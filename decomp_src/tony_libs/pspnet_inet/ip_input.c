/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

struct ip_srcrt_s {
	struct	in_addr dst;			/* final destination */
	char	nop;				/* one NOP to align */
	char	srcopt[IPOPT_OFFSET + 1];	/* OPTVAL, OLEN and OFFSET */
	struct	in_addr route[MAX_IPOPTLEN/sizeof(struct in_addr)];
};
extern int ip_nhops;
extern struct ip_srcrt_s ip_srcrt;
extern int ipforwarding, ipsendredirects, ip_forwsrcrt, ip_allowsrcrt, ip_directedbcast;
extern int ipqmaxlen, ip_maxfragpackets, ip_nfragpackets;
extern u_int ip_mtudisc_timeout;
extern struct rttimer_queue *ip_mtudisc_timeout_q;
extern struct ipqhead ipq;
extern int ipq_locked;
extern struct sockaddr_in ipaddr __attribute__((aligned(4)));
extern struct route ipforward_rt __attribute__((aligned(4)));
extern u_long in_ifaddrhash;
extern int anonportmin, anonportmax, lowportmin, lowportmax;

static __inline int ipq_lock_try (void);
static __inline void ipq_unlock (void);

static __inline int
ipq_lock_try()
{
	int s;

	s = _sce_pspnet_spllock();
	if (ipq_locked) {
		_sce_pspnet_splunlock(s);
		return (0);
	}
	ipq_locked = 1;
	_sce_pspnet_splunlock(s);
	return (1);
}

static __inline void
ipq_unlock()
{
	int s;

	s = _sce_pspnet_spllock();
	ipq_locked = 0;
	_sce_pspnet_splunlock(s);
}

#define	IPQ_LOCK()		(void) ipq_lock_try()
#define	IPQ_LOCK_CHECK()	/* nothing */

#define	IPQ_UNLOCK()		ipq_unlock()


/*
 * We need to save the IP options in case a protocol wants to respond
 * to an incoming packet over the same route if the packet got here
 * using IP source routing.  This allows connection establishment and
 * maintenance when the remote end is on a network that is not known
 * to us.
 */

static void save_rte (u_char *, struct in_addr);

/*
 * IP initialization: fill in IP protocol switch table.
 * All protocols not implemented in kernel go to raw IP protocol handler.
 */
INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/ip_input", func_00014890);


/*
 * IP software interrupt routine
 */
void
ipintr(void)
{
	int s;
	struct mbuf *m;

	while (1) {
		s = _sce_pspnet_spllock();
		IF_DEQUEUE(&ipintrq, m);
		_sce_pspnet_splunlock(s);
		if (m == 0)
			return;
		ip_input(m);
	}
}

/*
 * Ip input routine.  Checksum and byte swap header.  If fragmented
 * try to reassemble.  Process options.  Pass to next level.
 */
void
ip_input(struct mbuf *m)
{
	struct ip *ip = NULL;
	struct ipq *fp;
	struct in_ifaddr *ia;
	struct ifaddr *ifa;
	struct ipqent *ipqe;
	int hlen = 0, mff, len;
	int downmatch;

	/*
	 * If no IP addresses have been set yet but the interfaces
	 * are receiving, can't do anything with incoming packets yet.
	 */
	if (in_ifaddrhead.tqh_first == 0)
		goto bad;
	ipstat.ips_total++;
	if (m->m_len < sizeof (struct ip) &&
	    (m = m_pullup(m, sizeof (struct ip))) == 0) {
		ipstat.ips_toosmall++;
		return;
	}
	ip = mtod(m, struct ip *);
	if (ip->ip_v != IPVERSION) {
		ipstat.ips_badvers++;
		goto bad;
	}
	hlen = ip->ip_hl << 2;
	if (hlen < sizeof(struct ip)) {	/* minimum header length */
		ipstat.ips_badhlen++;
		goto bad;
	}
	if (hlen > m->m_len) {
		if ((m = m_pullup(m, hlen)) == 0) {
			ipstat.ips_badhlen++;
			return;
		}
		ip = mtod(m, struct ip *);
	}

	/*
	 * RFC1122: packets with a multicast source address are
	 * not allowed.
	 */
	if (IN_MULTICAST(ip->ip_src.s_addr)) {
		/* XXX stat */
		goto bad;
	}

	if (in_cksum(m, hlen) != 0) {
		ipstat.ips_badsum++;
		goto bad;
	}

	/*
	 * Convert fields to host representation.
	 */
	NTOHS(ip->ip_len);
	NTOHS(ip->ip_off);
	len = ip->ip_len;

	/*
	 * Check for additional length bogosity
	 */
	if (len < hlen) {
	 	ipstat.ips_badlen++;
		goto bad;
	}

	/*
	 * Check that the amount of data in the buffers
	 * is as at least much as the IP header would have us expect.
	 * Trim mbufs if longer than we expect.
	 * Drop packet if shorter than we expect.
	 */
	if (m->m_pkthdr.len < len) {
		ipstat.ips_tooshort++;
		goto bad;
	}
	if (m->m_pkthdr.len > len) {
		if (m->m_len == m->m_pkthdr.len) {
			m->m_len = len;
			m->m_pkthdr.len = len;
		} else
			m_adj(m, len - m->m_pkthdr.len);
	}

	/*
	 * Assume that we can create a fast-forward IP flow entry
	 * based on this packet.
	 */
	m->m_flags |= M_CANFASTFWD;


	/*
	 * Process options and, if not destined for us,
	 * ship it on.  ip_dooptions returns 1 when an
	 * error was detected (causing an icmp message
	 * to be sent and the original packet to be freed).
	 */
	ip_nhops = 0;		/* for source routed packets */
	if (hlen > sizeof (struct ip) && ip_dooptions(m))
		return;

	/*
	 * Check our list of addresses, to see if the packet is for us.
	 *
	 * Traditional 4.4BSD did not consult IFF_UP at all.
	 * The behavior here is to treat addresses on !IFF_UP interface
	 * as not mine.
	 */
	downmatch = 0;
	for (ia = IN_IFADDR_HASH(ip->ip_dst.s_addr).lh_first;
	     ia != NULL;
	     ia = ia->ia_hash.le_next) {
		if (in_hosteq(ia->ia_addr.sin_addr, ip->ip_dst)) {
			if ((ia->ia_ifp->if_flags & IFF_UP) != 0)
				break;
			else
				downmatch++;
		}
	}
	if (ia != NULL)
		goto ours;
	if (m->m_pkthdr.rcvif->if_flags & IFF_BROADCAST) {
		for (ifa = m->m_pkthdr.rcvif->if_addrlist.tqh_first;
		    ifa != NULL; ifa = ifa->ifa_list.tqe_next) {
			if (ifa->ifa_addr->sa_family != AF_INET) continue;
			ia = ifatoia(ifa);
			if (in_hosteq(ip->ip_dst, ia->ia_broadaddr.sin_addr) ||
			    in_hosteq(ip->ip_dst, ia->ia_netbroadcast) ||
			    /*
			     * Look for all-0's host part (old broadcast addr),
			     * either for subnet or net.
			     */
			    ip->ip_dst.s_addr == ia->ia_subnet ||
			    ip->ip_dst.s_addr == ia->ia_net)
				goto ours;
			/*
			 * An interface with IP address zero accepts
			 * all packets that arrive on that interface.
			 */
			if (in_nullhost(ia->ia_addr.sin_addr))
				goto ours;
		}
	}
	if (IN_MULTICAST(ip->ip_dst.s_addr)) {
		struct in_multi *inm;
		/*
		 * See if we belong to the destination multicast group on the
		 * arrival interface.
		 */
		IN_LOOKUP_MULTI(ip->ip_dst, m->m_pkthdr.rcvif, inm);
		if (inm == NULL) {
			ipstat.ips_cantforward++;
			m_freem(m);
			return;
		}
		goto ours;
	}
	if (ip->ip_dst.s_addr == INADDR_BROADCAST ||
	    in_nullhost(ip->ip_dst))
		goto ours;

	/*
	 * Not for us; forward if possible and desirable.
	 */
	if (ipforwarding == 0) {
		ipstat.ips_cantforward++;
		m_freem(m);
	} else {
		/*
		 * If ip_dst matched any of my address on !IFF_UP interface,
		 * and there's no IFF_UP interface that matches ip_dst,
		 * send icmp unreach.  Forwarding it will result in in-kernel
		 * forwarding loop till TTL goes to 0.
		 */
		if (downmatch) {
			icmp_error(m, ICMP_UNREACH, ICMP_UNREACH_HOST, 0, 0);
			ipstat.ips_cantforward++;
			return;
		}

		ip_forward(m, 0);
	}
	return;

ours:
	/*
	 * If offset or IP_MF are set, must reassemble.
	 * Otherwise, nothing need be done.
	 * (We could look in the reassembly queue to see
	 * if the packet was previously fragmented,
	 * but it's not worth the time; just let them time out.)
	 */
	if (ip->ip_off & ~(IP_DF|IP_RF)) {
		/*
		 * Look for queue of fragments
		 * of this datagram.
		 */
		IPQ_LOCK();
		for (fp = ipq.lh_first; fp != NULL; fp = fp->ipq_q.le_next)
			if (ip->ip_id == fp->ipq_id &&
			    in_hosteq(ip->ip_src, fp->ipq_src) &&
			    in_hosteq(ip->ip_dst, fp->ipq_dst) &&
			    ip->ip_p == fp->ipq_p)
				goto found;
		fp = 0;
found:

		/*
		 * Adjust ip_len to not reflect header,
		 * set ipqe_mff if more fragments are expected,
		 * convert offset of this to bytes.
		 */
		ip->ip_len -= hlen;
		mff = (ip->ip_off & IP_MF) != 0;
		if (mff) {
		        /*
		         * Make sure that fragments have a data length
			 * that's a non-zero multiple of 8 bytes.
		         */
			if (ip->ip_len == 0 || (ip->ip_len & 0x7) != 0) {
				ipstat.ips_badfrags++;
				IPQ_UNLOCK();
				goto bad;
			}
		}
		ip->ip_off <<= 3;

		/*
		 * If datagram marked as having more fragments
		 * or if this is not the first fragment,
		 * attempt reassembly; if it succeeds, proceed.
		 */
		if (mff || ip->ip_off) {
			ipstat.ips_fragments++;
			ipqe = sceNetMallocInternal(sizeof(struct ipqent));
			if (ipqe == NULL) {
				ipstat.ips_rcvmemdrop++;
				IPQ_UNLOCK();
				goto bad;
			}
			ipqe->ipqe_mff = mff;
			ipqe->ipqe_m = m;
			ipqe->ipqe_ip = ip;
			m = ip_reass(ipqe, fp);
			if (m == 0) {
				IPQ_UNLOCK();
				return;
			}
			ipstat.ips_reassembled++;
			ip = mtod(m, struct ip *);
			hlen = ip->ip_hl << 2;
			ip->ip_len += hlen;
		} else
			if (fp)
				ip_freef(fp);
		IPQ_UNLOCK();
	}


	/*
	 * Switch out to protocol's input routine.
	 */
	ipstat.ips_delivered++;
    {
	int off = hlen, nh = ip->ip_p;

	(*inetsw[ip_protox[nh]].pr_input)(m, off, nh);
	return;
    }
bad:
	m_freem(m);
}

/*
 * Take incoming datagram fragment and try to
 * reassemble it into whole datagram.  If a chain for
 * reassembly of this datagram already exists, then it
 * is given as fp; otherwise have to make a chain.
 */
struct mbuf *
ip_reass(struct ipqent *ipqe, struct ipq *fp)
{
	struct mbuf *m = ipqe->ipqe_m;
	struct ipqent *nq, *p, *q;
	struct ip *ip;
	struct mbuf *t;
	int hlen = ipqe->ipqe_ip->ip_hl << 2;
	int i, next;

	IPQ_LOCK_CHECK();

	/*
	 * Presence of header sizes in mbufs
	 * would confuse code below.
	 */
	m->m_data += hlen;
	m->m_len -= hlen;

	/*
	 * If first fragment to arrive, create a reassembly queue.
	 */
	if (fp == 0) {
		/*
		 * Enforce upper bound on number of fragmented packets
		 * for which we attempt reassembly;
		 * If maxfrag is 0, never accept fragments.
		 * If maxfrag is -1, accept all fragments without limitation.
		 */
		if (ip_maxfragpackets < 0)
			;
		else if (ip_nfragpackets >= ip_maxfragpackets)
			goto dropfrag;
		ip_nfragpackets++;
		fp = (struct ipq *)sceNetMallocInternal(sizeof (struct ipq));
		if (fp == NULL)
			goto dropfrag;
		LIST_INSERT_HEAD(&ipq, fp, ipq_q);
		fp->ipq_ttl = IPFRAGTTL;
		fp->ipq_p = ipqe->ipqe_ip->ip_p;
		fp->ipq_id = ipqe->ipqe_ip->ip_id;
		LIST_INIT(&fp->ipq_fragq);
		fp->ipq_src = ipqe->ipqe_ip->ip_src;
		fp->ipq_dst = ipqe->ipqe_ip->ip_dst;
		p = NULL;
		goto insert;
	}

	/*
	 * Find a segment which begins after this one does.
	 */
	for (p = NULL, q = fp->ipq_fragq.lh_first; q != NULL;
	    p = q, q = q->ipqe_q.le_next)
		if (q->ipqe_ip->ip_off > ipqe->ipqe_ip->ip_off)
			break;

	/*
	 * If there is a preceding segment, it may provide some of
	 * our data already.  If so, drop the data from the incoming
	 * segment.  If it provides all of our data, drop us.
	 */
	if (p != NULL) {
		i = p->ipqe_ip->ip_off + p->ipqe_ip->ip_len -
		    ipqe->ipqe_ip->ip_off;
		if (i > 0) {
			if (i >= ipqe->ipqe_ip->ip_len)
				goto dropfrag;
			m_adj(ipqe->ipqe_m, i);
			ipqe->ipqe_ip->ip_off += i;
			ipqe->ipqe_ip->ip_len -= i;
		}
	}

	/*
	 * While we overlap succeeding segments trim them or,
	 * if they are completely covered, dequeue them.
	 */
	for (; q != NULL && ipqe->ipqe_ip->ip_off + ipqe->ipqe_ip->ip_len >
	    q->ipqe_ip->ip_off; q = nq) {
		i = (ipqe->ipqe_ip->ip_off + ipqe->ipqe_ip->ip_len) -
		    q->ipqe_ip->ip_off;
		if (i < q->ipqe_ip->ip_len) {
			q->ipqe_ip->ip_len -= i;
			q->ipqe_ip->ip_off += i;
			m_adj(q->ipqe_m, i);
			break;
		}
		nq = q->ipqe_q.le_next;
		m_freem(q->ipqe_m);
		LIST_REMOVE(q, ipqe_q);
		sceNetFreeInternal(q);
	}

insert:
	/*
	 * Stick new segment in its place;
	 * check for complete reassembly.
	 */
	if (p == NULL) {
		LIST_INSERT_HEAD(&fp->ipq_fragq, ipqe, ipqe_q);
	} else {
		LIST_INSERT_AFTER(p, ipqe, ipqe_q);
	}
	next = 0;
	for (p = NULL, q = fp->ipq_fragq.lh_first; q != NULL;
	    p = q, q = q->ipqe_q.le_next) {
		if (q->ipqe_ip->ip_off != next)
			return (0);
		next += q->ipqe_ip->ip_len;
	}
	if (p->ipqe_mff)
		return (0);

	/*
	 * Reassembly is complete.  Check for a bogus message size and
	 * concatenate fragments.
	 */
	q = fp->ipq_fragq.lh_first;
	ip = q->ipqe_ip;
	if ((next + (ip->ip_hl << 2)) > IP_MAXPACKET) {
		ipstat.ips_toolong++;
		ip_freef(fp);
		return (0);
	}
	m = q->ipqe_m;
	t = m->m_next;
	m->m_next = 0;
	m_cat(m, t);
	nq = q->ipqe_q.le_next;
	sceNetFreeInternal(q);
	for (q = nq; q != NULL; q = nq) {
		t = q->ipqe_m;
		nq = q->ipqe_q.le_next;
		sceNetFreeInternal(q);
		m_cat(m, t);
	}

	/*
	 * Create header for new ip packet by
	 * modifying header of first packet;
	 * dequeue and discard fragment reassembly header.
	 * Make header visible.
	 */
	ip->ip_len = next;
	ip->ip_src = fp->ipq_src;
	ip->ip_dst = fp->ipq_dst;
	LIST_REMOVE(fp, ipq_q);
	sceNetFreeInternal(fp);
	ip_nfragpackets--;
	m->m_len += (ip->ip_hl << 2);
	m->m_data -= (ip->ip_hl << 2);
	/* some debugging cruft by sklower, below, will go away soon */
	if (m->m_flags & M_PKTHDR) { /* XXX this should be done elsewhere */
		int plen = 0;
		for (t = m; t; t = t->m_next)
			plen += t->m_len;
		m->m_pkthdr.len = plen;
	}
	return (m);

dropfrag:
	ipstat.ips_fragdropped++;
	m_freem(m);
	sceNetFreeInternal(ipqe);
	return (0);
}

/*
 * Free a fragment reassembly header and all
 * associated datagrams.
 */
void
ip_freef(struct ipq *fp)
{
	struct ipqent *q, *p;

	IPQ_LOCK_CHECK();

	for (q = fp->ipq_fragq.lh_first; q != NULL; q = p) {
		p = q->ipqe_q.le_next;
		m_freem(q->ipqe_m);
		LIST_REMOVE(q, ipqe_q);
		sceNetFreeInternal(q);
	}
	LIST_REMOVE(fp, ipq_q);
	sceNetFreeInternal(fp);
	ip_nfragpackets--;
}

/*
 * IP timer processing;
 * if a timer expires on a reassembly
 * queue, discard it.
 */
void
ip_slowtimo(void)
{
	struct ipq *fp, *nfp;
	int s = _sce_pspnet_spllock();

	IPQ_LOCK();
	for (fp = ipq.lh_first; fp != NULL; fp = nfp) {
		nfp = fp->ipq_q.le_next;
		if (--fp->ipq_ttl == 0) {
			ipstat.ips_fragtimeout++;
			ip_freef(fp);
		}
	}
	/*
	 * If we are over the maximum number of fragments
	 * (due to the limit being lowered), drain off
	 * enough to get down to the new limit.
	 */
	if (ip_maxfragpackets < 0)
		;
	else {
		while (ip_nfragpackets > ip_maxfragpackets && ipq.lh_first)
			ip_freef(ipq.lh_first);
	}
	IPQ_UNLOCK();
	_sce_pspnet_splunlock(s);
}

/*
 * Drain off all datagram fragments.
 */
void
ip_drain(void)
{

	/*
	 * We may be called from a device's interrupt context.  If
	 * the ipq is already busy, just bail out now.
	 */
	if (ipq_lock_try() == 0)
		return;

	while (ipq.lh_first != NULL) {
		ipstat.ips_fragdropped++;
		ip_freef(ipq.lh_first);
	}

	IPQ_UNLOCK();
}

/*
 * Do option processing on a datagram,
 * possibly discarding it if bad options are encountered,
 * or forwarding it if source-routed.
 * Returns 1 if packet has been forwarded/freed,
 * 0 if the packet should be processed further.
 */
int
ip_dooptions(struct mbuf *m)
{
	struct ip *ip = mtod(m, struct ip *);
	u_char *cp, *cp0;
	struct ip_timestamp *ipt;
	struct in_ifaddr *ia;
	int opt, optlen, cnt, off, code, type = ICMP_PARAMPROB, forward = 0;
	struct in_addr dst;
	n_time ntime;

	dst = ip->ip_dst;
	cp = (u_char *)(ip + 1);
	cnt = (ip->ip_hl << 2) - sizeof (struct ip);
	for (; cnt > 0; cnt -= optlen, cp += optlen) {
		opt = cp[IPOPT_OPTVAL];
		if (opt == IPOPT_EOL)
			break;
		if (opt == IPOPT_NOP)
			optlen = 1;
		else {
			if (cnt < IPOPT_OLEN + sizeof(*cp)) {
				code = &cp[IPOPT_OLEN] - (u_char *)ip;
				goto bad;
			}
			optlen = cp[IPOPT_OLEN];
			if (optlen < IPOPT_OLEN + sizeof(*cp) || optlen > cnt) {
				code = &cp[IPOPT_OLEN] - (u_char *)ip;
				goto bad;
			}
		}
		switch (opt) {

		default:
			break;

		/*
		 * Source routing with record.
		 * Find interface with current destination address.
		 * If none on this machine then drop if strictly routed,
		 * or do nothing if loosely routed.
		 * Record interface address and bring up next address
		 * component.  If strictly routed make sure next
		 * address is on directly accessible net.
		 */
		case IPOPT_LSRR:
		case IPOPT_SSRR:
			if (ip_allowsrcrt == 0) {
				type = ICMP_UNREACH;
				code = ICMP_UNREACH_NET_PROHIB;
				goto bad;
			}
			if (optlen < IPOPT_OFFSET + sizeof(*cp)) {
				code = &cp[IPOPT_OLEN] - (u_char *)ip;
				goto bad;
			}
			if ((off = cp[IPOPT_OFFSET]) < IPOPT_MINOFF) {
				code = &cp[IPOPT_OFFSET] - (u_char *)ip;
				goto bad;
			}
			ipaddr.sin_addr = ip->ip_dst;
			ia = ifatoia(ifa_ifwithaddr(sintosa(&ipaddr)));
			if (ia == 0) {
				if (opt == IPOPT_SSRR) {
					type = ICMP_UNREACH;
					code = ICMP_UNREACH_SRCFAIL;
					goto bad;
				}
				/*
				 * Loose routing, and not at next destination
				 * yet; nothing to do except forward.
				 */
				break;
			}
			off--;			/* 0 origin */
			if ((off + sizeof(struct in_addr)) > optlen) {
				/*
				 * End of source route.  Should be for us.
				 */
				save_rte(cp, ip->ip_src);
				break;
			}
			/*
			 * locate outgoing interface
			 */
			bcopy((caddr_t)(cp + off), (caddr_t)&ipaddr.sin_addr,
			    sizeof(ipaddr.sin_addr));
			if (opt == IPOPT_SSRR)
				ia = ifatoia(ifa_ifwithaddr(sintosa(&ipaddr)));
			else
				ia = ip_rtaddr(ipaddr.sin_addr);
			if (ia == 0) {
				type = ICMP_UNREACH;
				code = ICMP_UNREACH_SRCFAIL;
				goto bad;
			}
			ip->ip_dst = ipaddr.sin_addr;
			bcopy((caddr_t)&ia->ia_addr.sin_addr,
			    (caddr_t)(cp + off), sizeof(struct in_addr));
			cp[IPOPT_OFFSET] += sizeof(struct in_addr);
			/*
			 * Let ip_intr's mcast routing check handle mcast pkts
			 */
			forward = !IN_MULTICAST(ip->ip_dst.s_addr);
			break;

		case IPOPT_RR:
			if (optlen < IPOPT_OFFSET + sizeof(*cp)) {
				code = &cp[IPOPT_OLEN] - (u_char *)ip;
				goto bad;
			}
			if ((off = cp[IPOPT_OFFSET]) < IPOPT_MINOFF) {
				code = &cp[IPOPT_OFFSET] - (u_char *)ip;
				goto bad;
			}
			/*
			 * If no space remains, ignore.
			 */
			off--;			/* 0 origin */
			if ((off + sizeof(struct in_addr)) > optlen)
				break;
			bcopy((caddr_t)(&ip->ip_dst), (caddr_t)&ipaddr.sin_addr,
			    sizeof(ipaddr.sin_addr));
			/*
			 * locate outgoing interface; if we're the destination,
			 * use the incoming interface (should be same).
			 */
			if ((ia = ifatoia(ifa_ifwithaddr(sintosa(&ipaddr))))
			    == NULL &&
			    (ia = ip_rtaddr(ipaddr.sin_addr)) == NULL) {
				type = ICMP_UNREACH;
				code = ICMP_UNREACH_HOST;
				goto bad;
			}
			bcopy((caddr_t)&ia->ia_addr.sin_addr,
			    (caddr_t)(cp + off), sizeof(struct in_addr));
			cp[IPOPT_OFFSET] += sizeof(struct in_addr);
			break;

		case IPOPT_TS:
			code = cp - (u_char *)ip;
			ipt = (struct ip_timestamp *)cp;
			if (ipt->ipt_len < 4 || ipt->ipt_len > 40) {
				code = (u_char *)&ipt->ipt_len - (u_char *)ip;
				goto bad;
			}
			if (ipt->ipt_ptr < 5) {
				code = (u_char *)&ipt->ipt_ptr - (u_char *)ip;
				goto bad;
			}
			if (ipt->ipt_ptr > ipt->ipt_len - sizeof (int32_t)) {
				if (++ipt->ipt_oflw == 0) {
					code = (u_char *)&ipt->ipt_ptr -
					    (u_char *)ip;
					goto bad;
				}
				break;
			}
			cp0 = (cp + ipt->ipt_ptr - 1);
			switch (ipt->ipt_flg) {

			case IPOPT_TS_TSONLY:
				break;

			case IPOPT_TS_TSANDADDR:
				if (ipt->ipt_ptr - 1 + sizeof(n_time) +
				    sizeof(struct in_addr) > ipt->ipt_len) {
					code = (u_char *)&ipt->ipt_ptr -
					    (u_char *)ip;
					goto bad;
				}
				ipaddr.sin_addr = dst;
				ia = ifatoia(ifaof_ifpforaddr(sintosa(&ipaddr),
				    m->m_pkthdr.rcvif));
				if (ia == 0)
					continue;
				bcopy(&ia->ia_addr.sin_addr,
				    cp0, sizeof(struct in_addr));
				ipt->ipt_ptr += sizeof(struct in_addr);
				break;

			case IPOPT_TS_PRESPEC:
				if (ipt->ipt_ptr - 1 + sizeof(n_time) +
				    sizeof(struct in_addr) > ipt->ipt_len) {
					code = (u_char *)&ipt->ipt_ptr -
					    (u_char *)ip;
					goto bad;
				}
				bcopy(cp0, &ipaddr.sin_addr,
				    sizeof(struct in_addr));
				if (ifatoia(ifa_ifwithaddr(sintosa(&ipaddr)))
				    == NULL)
					continue;
				ipt->ipt_ptr += sizeof(struct in_addr);
				break;

			default:
				/* XXX can't take &ipt->ipt_flg */
				code = (u_char *)&ipt->ipt_ptr -
				    (u_char *)ip + 1;
				goto bad;
			}
			ntime = iptime();
			cp0 = (u_char *) &ntime; /* XXX grumble, GCC... */
			bcopy(cp0, (caddr_t)cp + ipt->ipt_ptr - 1,
			    sizeof(n_time));
			ipt->ipt_ptr += sizeof(n_time);
		}
	}
	if (forward) {
		if (ip_forwsrcrt == 0) {
			type = ICMP_UNREACH;
			code = ICMP_UNREACH_SRCFAIL;
			goto bad;
		}
		ip_forward(m, 1);
		return (1);
	}
	return (0);
bad:
	icmp_error(m, type, code, 0, 0);
	ipstat.ips_badoptions++;
	return (1);
}

/*
 * Given address of next destination (final or next hop),
 * return internet address info of interface to be used to get there.
 */
struct in_ifaddr *
ip_rtaddr(struct in_addr dst)
{
	struct sockaddr_in *sin;

	sin = satosin(&ipforward_rt.ro_dst);

	if (ipforward_rt.ro_rt == 0 || !in_hosteq(dst, sin->sin_addr)) {
		if (ipforward_rt.ro_rt) {
			RTFREE(ipforward_rt.ro_rt);
			ipforward_rt.ro_rt = 0;
		}
		sin->sin_family = AF_INET;
		sin->sin_len = sizeof(*sin);
		sin->sin_addr = dst;

		rtalloc(&ipforward_rt);
	}
	if (ipforward_rt.ro_rt == 0)
		return ((struct in_ifaddr *)0);
	return (ifatoia(ipforward_rt.ro_rt->rt_ifa));
}

/*
 * Save incoming source route for use in replies,
 * to be picked up later by ip_srcroute if the receiver is interested.
 */
void
save_rte(u_char *option, struct in_addr dst)
{
	unsigned olen;

	olen = option[IPOPT_OLEN];
	if (olen > sizeof(ip_srcrt) - (1 + sizeof(dst)))
		return;
	bcopy((caddr_t)option, (caddr_t)ip_srcrt.srcopt, olen);
	ip_nhops = (olen - IPOPT_OFFSET - 1) / sizeof(struct in_addr);
	ip_srcrt.dst = dst;
}

/*
 * Retrieve incoming source route for use in replies,
 * in the same form used by setsockopt.
 * The first hop is placed before the options, will be removed later.
 */
struct mbuf *
ip_srcroute(void)
{
	struct in_addr *p, *q;
	struct mbuf *m;

	if (ip_nhops == 0)
		return ((struct mbuf *)0);
	m = m_get(M_DONTWAIT, MT_SOOPTS);
	if (m == 0)
		return ((struct mbuf *)0);

#define OPTSIZ	(sizeof(ip_srcrt.nop) + sizeof(ip_srcrt.srcopt))

	/* length is (nhops+1)*sizeof(addr) + sizeof(nop + srcrt header) */
	m->m_len = ip_nhops * sizeof(struct in_addr) + sizeof(struct in_addr) +
	    OPTSIZ;

	/*
	 * First save first hop for return route
	 */
	p = &ip_srcrt.route[ip_nhops - 1];
	*(mtod(m, struct in_addr *)) = *p--;

	/*
	 * Copy option fields and padding (nop) to mbuf.
	 */
	ip_srcrt.nop = IPOPT_NOP;
	ip_srcrt.srcopt[IPOPT_OFFSET] = IPOPT_MINOFF;
	bcopy((caddr_t)&ip_srcrt.nop,
	    mtod(m, caddr_t) + sizeof(struct in_addr), OPTSIZ);
	q = (struct in_addr *)(mtod(m, caddr_t) +
	    sizeof(struct in_addr) + OPTSIZ);
#undef OPTSIZ
	/*
	 * Record return path as an IP source route,
	 * reversing the path (pointers are now aligned).
	 */
	while (p >= ip_srcrt.route) {
		*q++ = *p--;
	}
	/*
	 * Last hop goes to final destination.
	 */
	*q = ip_srcrt.dst;
	return (m);
}

/*
 * Strip out IP options, at higher
 * level protocol in the kernel.
 * Second argument is buffer to which options
 * will be moved, and return value is their length.
 * XXX should be deleted; last arg currently ignored.
 */
void
ip_stripoptions(struct mbuf *m, struct mbuf *mopt)
{
	int i;
	struct ip *ip = mtod(m, struct ip *);
	caddr_t opts;
	int olen;

	olen = (ip->ip_hl << 2) - sizeof (struct ip);
	opts = (caddr_t)(ip + 1);
	i = m->m_len - (sizeof (struct ip) + olen);
	bcopy(opts  + olen, opts, (unsigned)i);
	m->m_len -= olen;
	if (m->m_flags & M_PKTHDR)
		m->m_pkthdr.len -= olen;
	ip->ip_len -= olen;
	ip->ip_hl = sizeof (struct ip) >> 2;
}


/*
 * Forward a packet.  If some error occurs return the sender
 * an icmp packet.  Note we can't always generate a meaningful
 * icmp message because icmp doesn't have a large enough repertoire
 * of codes and types.
 *
 * If not forwarding, just drop the packet.  This could be confusing
 * if ipforwarding was zero but some routing protocol was advancing
 * us as a gateway to somewhere.  However, we must let the routing
 * protocol deal with that.
 *
 * The srcrt parameter indicates whether the packet is being forwarded
 * via a source route.
 */
void
ip_forward(struct mbuf *m, int srcrt)
{
	struct ip *ip = mtod(m, struct ip *);
	struct sockaddr_in *sin;
	struct rtentry *rt;
	int error, type = 0, code = 0;
	struct mbuf *mcopy;
	n_long dest;
	struct ifnet *destifp;

	dest = 0;
	if (m->m_flags & (M_BCAST|M_MCAST) || in_canforward(ip->ip_dst) == 0) {
		ipstat.ips_cantforward++;
		m_freem(m);
		return;
	}
	if (ip->ip_ttl <= IPTTLDEC) {
		icmp_error(m, ICMP_TIMXCEED, ICMP_TIMXCEED_INTRANS, dest, 0);
		return;
	}
	ip->ip_ttl -= IPTTLDEC;

	sin = satosin(&ipforward_rt.ro_dst);
	if ((rt = ipforward_rt.ro_rt) == 0 ||
	    !in_hosteq(ip->ip_dst, sin->sin_addr)) {
		if (ipforward_rt.ro_rt) {
			RTFREE(ipforward_rt.ro_rt);
			ipforward_rt.ro_rt = 0;
		}
		sin->sin_family = AF_INET;
		sin->sin_len = sizeof(struct sockaddr_in);
		sin->sin_addr = ip->ip_dst;

		rtalloc(&ipforward_rt);
		if (ipforward_rt.ro_rt == 0) {
			icmp_error(m, ICMP_UNREACH, ICMP_UNREACH_HOST, dest, 0);
			return;
		}
		rt = ipforward_rt.ro_rt;
	}

	/*
	 * Save at most 68 bytes of the packet in case
	 * we need to generate an ICMP message to the src.
	 * Pullup to avoid sharing mbuf cluster between m and mcopy.
	 */
	mcopy = m_copym(m, 0, imin((int)ip->ip_len, 68), M_DONTWAIT);
	if (mcopy)
		mcopy = m_pullup(mcopy, ip->ip_hl << 2);

	/*
	 * If forwarding packet using same interface that it came in on,
	 * perhaps should send a redirect to sender to shortcut a hop.
	 * Only send redirect if source is sending directly to us,
	 * and if packet was not source routed (or has any options).
	 * Also, don't send redirect if forwarding using a default route
	 * or a route modified by a redirect.
	 */
	if (rt->rt_ifp == m->m_pkthdr.rcvif &&
	    (rt->rt_flags & (RTF_DYNAMIC|RTF_MODIFIED)) == 0 &&
	    !in_nullhost(satosin(rt_key(rt))->sin_addr) &&
	    ipsendredirects && !srcrt) {
		if (rt->rt_ifa &&
		    (ip->ip_src.s_addr & ifatoia(rt->rt_ifa)->ia_subnetmask) ==
		    ifatoia(rt->rt_ifa)->ia_subnet) {
			if (rt->rt_flags & RTF_GATEWAY)
				dest = satosin(rt->rt_gateway)->sin_addr.s_addr;
			else
				dest = ip->ip_dst.s_addr;
			/*
			 * Router requirements says to only send host
			 * redirects.
			 */
			type = ICMP_REDIRECT;
			code = ICMP_REDIRECT_HOST;
		}
	}

	error = ip_output(m, (struct mbuf *)0, &ipforward_rt,
	    (IP_FORWARDING | (ip_directedbcast ? IP_ALLOWBROADCAST : 0)), 0);
	if (error)
		ipstat.ips_cantforward++;
	else {
		ipstat.ips_forward++;
		if (type)
			ipstat.ips_redirectsent++;
		else {
			if (mcopy) {
				m_freem(mcopy);
			}
			return;
		}
	}
	if (mcopy == NULL)
		return;
	destifp = NULL;

	switch (error) {

	case 0:				/* forwarded, but need redirect */
		/* type, code set above */
		break;

	case ENETUNREACH:		/* shouldn't happen, checked above */
	case EHOSTUNREACH:
	case ENETDOWN:
	case EHOSTDOWN:
	default:
		type = ICMP_UNREACH;
		code = ICMP_UNREACH_HOST;
		break;

	case EMSGSIZE:
		type = ICMP_UNREACH;
		code = ICMP_UNREACH_NEEDFRAG;
		if (ipforward_rt.ro_rt)
			destifp = ipforward_rt.ro_rt->rt_ifp;
		ipstat.ips_cantfrag++;
		break;

	case ENOBUFS:
		type = ICMP_SOURCEQUENCH;
		code = 0;
		break;
	}
	icmp_error(mcopy, type, code, dest, destifp);
}

void
ip_savecontrol(struct inpcb *inp, struct mbuf **mp, struct ip *ip, struct mbuf *m)
{

	if (inp->inp_socket->so_options & SO_TIMESTAMP) {
		struct timeval tv;

		microtime(&tv);
		*mp = sbcreatecontrol((caddr_t) &tv, sizeof(tv),
		    SCM_TIMESTAMP, SOL_SOCKET);
		if (*mp)
			mp = &(*mp)->m_next;
	}
	if (inp->inp_flags & INP_RECVDSTADDR) {
		*mp = sbcreatecontrol((caddr_t) &ip->ip_dst,
		    sizeof(struct in_addr), IP_RECVDSTADDR, IPPROTO_IP);
		if (*mp)
			mp = &(*mp)->m_next;
	}
	if (inp->inp_flags & INP_RECVIF) {
		struct sockaddr_dl sdl;

		sdl.sdl_len = offsetof(struct sockaddr_dl, sdl_data[0]);
		sdl.sdl_family = AF_LINK;
		sdl.sdl_index = m->m_pkthdr.rcvif ?
		    m->m_pkthdr.rcvif->if_index : 0;
		sdl.sdl_nlen = sdl.sdl_alen = sdl.sdl_slen = 0;
		*mp = sbcreatecontrol((caddr_t) &sdl, sdl.sdl_len,
		    IP_RECVIF, IPPROTO_IP);
		if (*mp)
			mp = &(*mp)->m_next;
	}
}

int
ip_sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen)
{
	extern int subnetsarelocal, hostzeroisbroadcast;

	int error, old;

	/* All sysctl names at this level are terminal. */
	if (namelen != 1)
		return (ENOTDIR);

	switch (name[0]) {
	case IPCTL_FORWARDING:
		return (sysctl_int(oldp, oldlenp, newp, newlen, &ipforwarding));
	case IPCTL_SENDREDIRECTS:
		return (sysctl_int(oldp, oldlenp, newp, newlen,
			&ipsendredirects));
	case IPCTL_DEFTTL:
		return (sysctl_int(oldp, oldlenp, newp, newlen, &ip_defttl));
	case IPCTL_FORWSRCRT:
		return (sysctl_int(oldp, oldlenp, newp, newlen,
		    &ip_forwsrcrt));
	case IPCTL_DIRECTEDBCAST:
		return (sysctl_int(oldp, oldlenp, newp, newlen,
		    &ip_directedbcast));
	case IPCTL_ALLOWSRCRT:
		return (sysctl_int(oldp, oldlenp, newp, newlen,
		    &ip_allowsrcrt));
	case IPCTL_SUBNETSARELOCAL:
		return (sysctl_int(oldp, oldlenp, newp, newlen,
		    &subnetsarelocal));
	case IPCTL_MTUDISC:
		error = sysctl_int(oldp, oldlenp, newp, newlen,
		    &ip_mtudisc);
		if (ip_mtudisc != 0 && ip_mtudisc_timeout_q == NULL) {
			ip_mtudisc_timeout_q =
			    rt_timer_queue_create(ip_mtudisc_timeout);
		} else if (ip_mtudisc == 0 && ip_mtudisc_timeout_q != NULL) {
			rt_timer_queue_destroy(ip_mtudisc_timeout_q, TRUE);
			ip_mtudisc_timeout_q = NULL;
		}
		return error;
	case IPCTL_ANONPORTMIN:
		old = anonportmin;
		error = sysctl_int(oldp, oldlenp, newp, newlen, &anonportmin);
		if (anonportmin >= anonportmax || anonportmin < 0
		    || anonportmin > 65535
#ifndef IPNOPRIVPORTS
		    || anonportmin < IPPORT_RESERVED
#endif
		    ) {
			anonportmin = old;
			return (EINVAL);
		}
		return (error);
	case IPCTL_ANONPORTMAX:
		old = anonportmax;
		error = sysctl_int(oldp, oldlenp, newp, newlen, &anonportmax);
		if (anonportmin >= anonportmax || anonportmax < 0
		    || anonportmax > 65535
#ifndef IPNOPRIVPORTS
		    || anonportmax < IPPORT_RESERVED
#endif
		    ) {
			anonportmax = old;
			return (EINVAL);
		}
		return (error);
	case IPCTL_MTUDISCTIMEOUT:
		error = sysctl_int(oldp, oldlenp, newp, newlen,
		   &ip_mtudisc_timeout);
		if (ip_mtudisc_timeout_q != NULL)
			rt_timer_queue_change(ip_mtudisc_timeout_q,
					      ip_mtudisc_timeout);
		return (error);
	case IPCTL_HOSTZEROBROADCAST:
		return (sysctl_int(oldp, oldlenp, newp, newlen,
		    &hostzeroisbroadcast));


#ifndef IPNOPRIVPORTS
	case IPCTL_LOWPORTMIN:
		old = lowportmin;
		error = sysctl_int(oldp, oldlenp, newp, newlen, &lowportmin);
		if (lowportmin >= lowportmax
		    || lowportmin > IPPORT_RESERVEDMAX
		    || lowportmin < IPPORT_RESERVEDMIN
		    ) {
			lowportmin = old;
			return (EINVAL);
		}
		return (error);
	case IPCTL_LOWPORTMAX:
		old = lowportmax;
		error = sysctl_int(oldp, oldlenp, newp, newlen, &lowportmax);
		if (lowportmin >= lowportmax
		    || lowportmax > IPPORT_RESERVEDMAX
		    || lowportmax < IPPORT_RESERVEDMIN
		    ) {
			lowportmax = old;
			return (EINVAL);
		}
		return (error);
#endif

	case IPCTL_MAXFRAGPACKETS:
		return (sysctl_int(oldp, oldlenp, newp, newlen,
		    &ip_maxfragpackets));
	case IPCTL_STATS:
		return (sysctl_rdstruct(oldp, oldlenp, newp, &ipstat,
		    sizeof(ipstat)));

	default:
		return (EOPNOTSUPP);
	}
	/* NOTREACHED */
}
