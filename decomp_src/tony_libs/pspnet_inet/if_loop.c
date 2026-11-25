/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define LOMTU (32768 + MHLEN + MLEN)

void
loopattach(int n)
{
	struct ifnet *ifp = &loif;

	sprintf(ifp->if_xname, "lo%d", 0);
	ifp->if_softc = NULL;
	ifp->if_mtu = LOMTU;
	ifp->if_flags = IFF_LOOPBACK | IFF_MULTICAST;
	ifp->if_ioctl = loioctl;
	ifp->if_output = looutput;
	ifp->if_type = IFT_LOOP;
	ifp->if_hdrlen = 0;
	ifp->if_addrlen = 0;
	if_attach(ifp);
}

int
looutput(struct ifnet *ifp, struct mbuf *m, struct sockaddr *dst, struct rtentry *rt)
{
	int s, isr;
	struct ifqueue *ifq = 0;

	m->m_pkthdr.rcvif = ifp;

	if (rt && rt->rt_flags & (RTF_REJECT | RTF_BLACKHOLE)) {
		m_freem(m);
		return (rt->rt_flags & RTF_BLACKHOLE ? 0 :
		    rt->rt_flags & RTF_HOST ? EHOSTUNREACH : ENETUNREACH);
	}
	if (m->m_len != m->m_pkthdr.len) {
		struct mbuf *n;
		int len;

		MGETHDR(n, M_DONTWAIT, MT_HEADER);
		len = MHLEN;
		if (n == NULL)
			goto nobufs;
		M_COPY_PKTHDR(n, m);
		if (m->m_pkthdr.len > len) {
			MCLGET(n, M_DONTWAIT);
			len = MCLBYTES;
			if ((n->m_flags & M_EXT) == 0) {
				m_free(n);
				n = NULL;
			}
		}
		if (n == NULL) {
		nobufs:
			m_freem(m);
			return (ENOBUFS);
		}
		if (m->m_pkthdr.len <= len) {
			m_copydata(m, 0, m->m_pkthdr.len, mtod(n, caddr_t));
			n->m_next = NULL;
			n->m_len = m->m_pkthdr.len;
			m_freem(m);
		} else {
			m_copydata(m, 0, len, mtod(n, caddr_t));
			m_adj(m, len);
			n->m_len = len;
			m->m_flags &= ~M_PKTHDR;
			n->m_next = m;
		}
		m = n;
	}
	ifp->if_opackets++;
	ifp->if_obytes += m->m_pkthdr.len;
	switch (dst->sa_family) {
	case AF_INET:
		ifq = &ipintrq;
		isr = NETISR_IP;
		break;
	default:
		m_freem(m);
		return (EAFNOSUPPORT);
	}
	s = _sce_pspnet_spllock();
	if (IF_QFULL(ifq)) {
		IF_DROP(ifq);
		m_freem(m);
		_sce_pspnet_splunlock(s);
		return (ENOBUFS);
	}
	IF_ENQUEUE(ifq, m);
	schednetisr(isr);
	ifp->if_ipackets++;
	ifp->if_ibytes += m->m_pkthdr.len;
	_sce_pspnet_splunlock(s);
	return (0);
}

void
lortrequest(int cmd, struct rtentry *rt, struct sockaddr *sa)
{
	if (rt)
		rt->rt_rmx.rmx_mtu = LOMTU;
}

int
loioctl(struct ifnet *ifp, u_long cmd, caddr_t data)
{
	struct ifaddr *ifa;
	struct ifreq *ifr;
	int error = 0;

	switch (cmd) {
	case SIOCSIFADDR:
		ifp->if_flags |= IFF_UP;
		ifa = (struct ifaddr *)data;
		if (ifa != 0)
			ifa->ifa_rtrequest = lortrequest;
		break;

	case SIOCADDMULTI:
	case SIOCDELMULTI:
		ifr = (struct ifreq *)data;
		if (ifr == 0) {
			error = EAFNOSUPPORT;
			break;
		}
		switch (ifr->ifr_addr.sa_family) {
		case AF_INET:
			break;
		default:
			error = EAFNOSUPPORT;
			break;
		}
		break;

	default:
		error = EINVAL;
	}
	return (error);
}
