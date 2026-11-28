/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

/* NetBSD 1.6 net/if_spppsubr.c, cut down by Sony (PPPoE: LCP, IPCP, PAP, CHAP) */

#define sppp_input func_00026A4C
#define sppp_flush func_00026D5C
#define sppp_dequeue func_00026DEC
#define sppp_ioctl func_00026E9C
#define sppp_attach func_000291A4
#define sppp_detach func_000292E0
#define sppp_isempty func_00029330
#define sppp_cp_send func_000270D8
#define sppp_cp_input func_00027304
#define sppp_cp_change_state func_000279D4
#define sppp_lcp_RCR func_00027A88
#define sppp_lcp_RCN_nak func_00027E80
#define sppp_lcp_tlu func_00027FB0
#define sppp_ncp_check func_00028194
#define sppp_lcp_check_and_close func_000281E4
#define sppp_ipcp_RCR func_00028238
#define sppp_ipcp_RCN_nak func_00028544
#define sppp_ipcp_scr func_000286B4
#define sppp_chap_input func_0002882C
#define sppp_pap_input func_00028A0C
#define sppp_auth_send func_00028AAC
#define sppp_keepalive func_00028D14
#define sppp_params func_00028E70
#define sppp_phase_network func_0002907C
#define sppp_strnlen func_0002916C
#define sppp_output func_00029384
#define sppp_null func_00029760
#define sppp_lcp_up func_00029768
#define sppp_lcp_down func_00029818
#define sppp_lcp_open func_000298F4
#define sppp_lcp_close func_000299D0
#define sppp_lcp_TO func_00029AE4
#define sppp_lcp_RCN_rej func_00029B08
#define sppp_lcp_tld func_00029BCC
#define sppp_lcp_tls func_00029C70
#define sppp_lcp_tlf func_00029CB0
#define sppp_lcp_scr func_00029CE0
#define sppp_ipcp_up func_00029DDC
#define sppp_ipcp_down func_00029E64
#define sppp_ipcp_open func_00029F04
#define sppp_ipcp_close func_0002A000
#define sppp_ipcp_TO func_0002A144
#define sppp_ipcp_RCN_rej func_0002A168
#define sppp_ipcp_tlu func_0002A214
#define sppp_ipcp_tld func_0002A2A4
#define sppp_ipcp_tls func_0002A2B8
#define sppp_ipcp_tlf func_0002A2C8
#define sppp_pap_open func_0002A2DC
#define sppp_pap_close func_0002A33C
#define sppp_pap_TO func_0002A374
#define sppp_pap_my_TO func_0002A37C
#define sppp_pap_tlu func_0002A40C
#define sppp_pap_tld func_0002A414
#define sppp_pap_scr func_0002A45C
#define sppp_chap_open func_0002A4DC
#define sppp_chap_close func_0002A4E4
#define sppp_chap_TO func_0002A51C
#define sppp_chap_my_TO func_0002A524
#define sppp_chap_tlu func_0002A62C
#define sppp_chap_tld func_0002A634
#define sppp_chap_scr func_0002A67C
#define sppp_to_event func_0002A684


#include "if_spppvar.h"

#define splnet _sce_pspnet_spllock
#define splimp _sce_pspnet_spllock
#define splx _sce_pspnet_splunlock

void _sce_pspnet_schednetintr(int isr);
struct ifqueue *sceNetInet_lib_D7928A6D(void);
void _sce_pspnet_if_up(struct ifnet *ifp);
void _sce_pspnet_if_down(struct ifnet *ifp);
#define if_up _sce_pspnet_if_up
#define if_down _sce_pspnet_if_down
int sceKernelUtilsMd5BlockInit(void *ctx);
int sceKernelUtilsMd5BlockUpdate(void *ctx, const void *data, u_int size);
int sceKernelUtilsMd5BlockResult(void *ctx, u_char *digest);
#define MD5Init sceKernelUtilsMd5BlockInit
#define MD5Update sceKernelUtilsMd5BlockUpdate
#define MD5Final(d, c) sceKernelUtilsMd5BlockResult(c, d)
typedef struct { u_int buf[0x60 / 4]; } MD5_CTX;
#define malloc(size, type, flags) sceNetMallocInternal(size)
#define free(p, type) sceNetFreeInternal(p)
#define random sceNetRand
#define hz 100

#define IFT_PPP 0x17
#define PPP_ALLSTATIONS 0xff
#define PPP_UI 0x03
#define PPP_IP 0x0021
#define PPP_LCP 0xc021
#define PPP_PAP 0xc023
#define PPP_CHAP 0xc223
#define PPP_IPCP 0x8021

#define CONF_REQ 1
#define CONF_ACK 2
#define CONF_NAK 3
#define CONF_REJ 4
#define TERM_REQ 5
#define TERM_ACK 6
#define CODE_REJ 7
#define PROTO_REJ 8
#define ECHO_REQ 9
#define ECHO_REPLY 10
#define DISC_REQ 11

#define LCP_OPT_MRU 1
#define LCP_OPT_ASYNC_MAP 2
#define LCP_OPT_AUTH_PROTO 3
#define LCP_OPT_MAGIC 5

#define IPCP_OPT_ADDRESS 3
#define IPCP_OPT_PRIMDNS 129
#define IPCP_OPT_SECDNS 131

#define PAP_REQ 1
#define PAP_ACK 2
#define PAP_NAK 3
#define CHAP_CHALLENGE 1
#define CHAP_RESPONSE 2
#define CHAP_SUCCESS 3
#define CHAP_FAILURE 4
#define CHAP_MD5 5

#define STATE_INITIAL 0
#define STATE_STARTING 1
#define STATE_CLOSED 2
#define STATE_STOPPED 3
#define STATE_CLOSING 4
#define STATE_STOPPING 5
#define STATE_REQ_SENT 6
#define STATE_ACK_RCVD 7
#define STATE_ACK_SENT 8
#define STATE_OPENED 9

#define SPPP_PHASE_DEAD 0
#define SPPP_PHASE_ESTABLISH 1
#define SPPP_PHASE_TERMINATE 2
#define SPPP_PHASE_AUTHENTICATE 3
#define SPPP_PHASE_NETWORK 4

#define MAXALIVECNT 3
#define PPP_HEADER_LEN 4
#define LCP_HEADER_LEN 4

#define CP_LCP 0x01
#define CP_AUTH 0x02
#define CP_NCP 0x04
#define CP_QUAL 0x08



#define IPCP_HISADDR_SEEN 1
#define IPCP_MYADDR_SEEN 2
#define IPCP_PRIMDNS_SEEN 4
#define IPCP_SECDNS_SEEN 8
#define IPCP_UP 0x10

#define SPPPRESET 0x8014697C
#define SPPPSETLCPCFG 0x8020697A
#define SPPPGETPHASE 0xC014697B
#define SPPPGETSTATUS 0xC014697D
#define SPPPSETAUTHCFG 0x81186979
#define SPPPGETIPCP 0xC0246978
#ifndef SIOCSIFADDR
#define SIOCSIFADDR 0x8020690C
#endif
#ifndef SIOCSIFDSTADDR
#define SIOCSIFDSTADDR 0x8020690E
#endif
#ifndef SIOCSIFFLAGS
#define SIOCSIFFLAGS 0x80206910
#endif
#ifndef SIOCAIFADDR
#define SIOCAIFADDR 0x8040691A
#endif
#ifndef SIOCADDMULTI
#define SIOCADDMULTI 0x80206931
#endif
#ifndef SIOCDELMULTI
#define SIOCDELMULTI 0x80206932
#endif
#ifndef SIOCSIFMTU
#define SIOCSIFMTU 0x8020697F
#endif
#ifndef SIOCGIFMTU
#define SIOCGIFMTU 0xC020697E
#endif

struct ppp_header {
	u_char address;
	u_char control;
	u_short protocol;
} __attribute__((__packed__));

struct lcp_header {
	u_char type;
	u_char ident;
	u_short len;
} __attribute__((__packed__));

struct spppauthcfg {
	char ifname[16];
	char name[AUTHNAMELEN];
	char secret[AUTHKEYLEN];
	int timeout;
	int max_configure;
};

struct sppplcpcfg {
	char ifname[16];
	int timeout;
	int max_terminate;
	int max_configure;
	int max_failure;
};

struct spppstatus {
	char ifname[16];
	int value;
};

struct spppipcp {
	char ifname[16];
	u_int flags;
	u_int32_t myaddr;
	u_int32_t hisaddr;
	u_int32_t dns_addrs[2];
};

struct cp {
	u_short proto;
	u_char protoidx;
	u_char flags;
	const char *name;
	void (*Up)(struct sppp *sp);
	void (*Down)(struct sppp *sp);
	void (*Open)(struct sppp *sp);
	void (*Close)(struct sppp *sp);
	void (*TO)(void *sp);
	int (*RCR)(struct sppp *sp, struct lcp_header *h, int len);
	void (*RCN_rej)(struct sppp *sp, struct lcp_header *h, int len);
	void (*RCN_nak)(struct sppp *sp, struct lcp_header *h, int len);
	void (*tlu)(struct sppp *sp);
	void (*tld)(struct sppp *sp);
	void (*tls)(struct sppp *sp);
	void (*tlf)(struct sppp *sp);
	void (*scr)(struct sppp *sp);
};

extern struct callout keepalive_ch;


static int sppp_output(struct ifnet *ifp, struct mbuf *m,
		       struct sockaddr *dst, struct rtentry *rt);

static void sppp_cp_input(const struct cp *cp, struct sppp *sp,
			  struct mbuf *m);
static void sppp_cp_send(struct sppp *sp, u_short proto, u_char type,
			 u_char ident, u_short len, void *data);
static void sppp_cp_change_state(const struct cp *cp, struct sppp *sp,
				 int newstate);
static void sppp_auth_send(const struct cp *cp,
			   struct sppp *sp, unsigned int type, unsigned int id,
			   ...);

static void sppp_up_event(const struct cp *cp, struct sppp *sp);
static void sppp_down_event(const struct cp *cp, struct sppp *sp);
static void sppp_open_event(const struct cp *cp, struct sppp *sp);
static void sppp_close_event(const struct cp *cp, struct sppp *sp);
static void sppp_to_event(const struct cp *cp, struct sppp *sp);

static void sppp_null(struct sppp *sp);

static void sppp_lcp_init(struct sppp *sp);
static void sppp_lcp_up(struct sppp *sp);
static void sppp_lcp_down(struct sppp *sp);
static void sppp_lcp_open(struct sppp *sp);
static void sppp_lcp_close(struct sppp *sp);
static void sppp_lcp_TO(void *sp);
static int sppp_lcp_RCR(struct sppp *sp, struct lcp_header *h, int len);
static void sppp_lcp_RCN_rej(struct sppp *sp, struct lcp_header *h, int len);
static void sppp_lcp_RCN_nak(struct sppp *sp, struct lcp_header *h, int len);
static void sppp_lcp_tlu(struct sppp *sp);
static void sppp_lcp_tld(struct sppp *sp);
static void sppp_lcp_tls(struct sppp *sp);
static void sppp_lcp_tlf(struct sppp *sp);
static void sppp_lcp_scr(struct sppp *sp);
static void sppp_lcp_check_and_close(struct sppp *sp);
static int sppp_ncp_check(struct sppp *sp);

static void sppp_ipcp_init(struct sppp *sp);
static void sppp_ipcp_up(struct sppp *sp);
static void sppp_ipcp_down(struct sppp *sp);
static void sppp_ipcp_open(struct sppp *sp);
static void sppp_ipcp_close(struct sppp *sp);
static void sppp_ipcp_TO(void *sp);
static int sppp_ipcp_RCR(struct sppp *sp, struct lcp_header *h, int len);
static void sppp_ipcp_RCN_rej(struct sppp *sp, struct lcp_header *h, int len);
static void sppp_ipcp_RCN_nak(struct sppp *sp, struct lcp_header *h, int len);
static void sppp_ipcp_tlu(struct sppp *sp);
static void sppp_ipcp_tld(struct sppp *sp);
static void sppp_ipcp_tls(struct sppp *sp);
static void sppp_ipcp_tlf(struct sppp *sp);
static void sppp_ipcp_scr(struct sppp *sp);

static void sppp_pap_input(struct sppp *sp, struct mbuf *m);
static void sppp_pap_init(struct sppp *sp);
static void sppp_pap_open(struct sppp *sp);
static void sppp_pap_close(struct sppp *sp);
static void sppp_pap_TO(void *sp);
static void sppp_pap_my_TO(void *sp);
static void sppp_pap_tlu(struct sppp *sp);
static void sppp_pap_tld(struct sppp *sp);
static void sppp_pap_scr(struct sppp *sp);

static void sppp_chap_input(struct sppp *sp, struct mbuf *m);
static void sppp_chap_init(struct sppp *sp);
static void sppp_chap_open(struct sppp *sp);
static void sppp_chap_close(struct sppp *sp);
static void sppp_chap_TO(void *sp);
static void sppp_chap_my_TO(void *sp);
static void sppp_chap_tlu(struct sppp *sp);
static void sppp_chap_tld(struct sppp *sp);
static void sppp_chap_scr(struct sppp *sp);

static int sppp_params(struct sppp *sp, int cmd, void *data);
static void sppp_keepalive(void *dummy);
static void sppp_phase_network(struct sppp *sp);
static int sppp_strnlen(u_char *p, int max);

/* our control protocol descriptors */
const struct cp lcp = {
	PPP_LCP, IDX_LCP, CP_LCP, "lcp",
	sppp_lcp_up, sppp_lcp_down, sppp_lcp_open, sppp_lcp_close,
	sppp_lcp_TO, sppp_lcp_RCR, sppp_lcp_RCN_rej, sppp_lcp_RCN_nak,
	sppp_lcp_tlu, sppp_lcp_tld, sppp_lcp_tls, sppp_lcp_tlf,
	sppp_lcp_scr
};

const struct cp ipcp = {
	PPP_IPCP, IDX_IPCP, CP_NCP, "ipcp",
	sppp_ipcp_up, sppp_ipcp_down, sppp_ipcp_open, sppp_ipcp_close,
	sppp_ipcp_TO, sppp_ipcp_RCR, sppp_ipcp_RCN_rej, sppp_ipcp_RCN_nak,
	sppp_ipcp_tlu, sppp_ipcp_tld, sppp_ipcp_tls, sppp_ipcp_tlf,
	sppp_ipcp_scr
};

const struct cp pap = {
	PPP_PAP, IDX_PAP, CP_AUTH, "pap",
	sppp_null, sppp_null, sppp_pap_open, sppp_pap_close,
	sppp_pap_TO, 0, 0, 0,
	sppp_pap_tlu, sppp_pap_tld, sppp_null, sppp_null,
	sppp_pap_scr
};

const struct cp chap = {
	PPP_CHAP, IDX_CHAP, CP_AUTH, "chap",
	sppp_null, sppp_null, sppp_chap_open, sppp_chap_close,
	sppp_chap_TO, 0, 0, 0,
	sppp_chap_tlu, sppp_chap_tld, sppp_null, sppp_null,
	sppp_chap_scr
};

extern const struct cp *cps[IDX_COUNT];

#define IF_PURGE(ifq) do { \
	struct mbuf *__m0; \
	for (;;) { \
		IF_DEQUEUE((ifq), __m0); \
		if (__m0 == NULL) \
			break; \
		m_freem(__m0); \
	} \
} while (0)

#define PPP_SHORT(p) ((u_short)(((p)[0] << 8) + (p)[1]))

/*
 * Process the received packet.
 */
void
sppp_input(struct ifnet *ifp, struct mbuf *m)
{
	struct ppp_header *h = NULL;
	struct ifqueue *inq = 0;
	u_int16_t protocol;
	int s;
	struct sppp *sp = (struct sppp *)ifp;

	if (ifp->if_flags & IFF_UP)
		/* Count received bytes, add hardware framing */
		ifp->if_ibytes += m->m_pkthdr.len + sp->pp_framebytes;

	if (m->m_pkthdr.len <= PPP_HEADER_LEN) {
		/* Too small packet, drop it. */
	  drop:
		++ifp->if_ierrors;
		++ifp->if_iqdrops;
		m_freem(m);
		return;
	}

	if (sp->pp_flags & PP_NOFRAMING) {
		memcpy(&protocol, mtod(m, void *), 2);
		protocol = ntohs(protocol);
		m_adj(m, 2);
	} else {

		/* Get PPP header. */
		h = mtod(m, struct ppp_header *);
		m_adj(m, PPP_HEADER_LEN);

		switch (h->address) {
		case PPP_ALLSTATIONS:
			if (h->control != PPP_UI)
				goto drop;
			break;
		default:
			goto drop;
		}
		protocol = h->control;
	}

	switch (protocol) {
	default:
		if (sp->state[IDX_LCP] == STATE_OPENED) {
			u_int16_t prot = htons(protocol);
			sppp_cp_send(sp, PPP_LCP, PROTO_REJ,
			    ++sp->pp_seq[IDX_LCP], m->m_pkthdr.len + 2,
			    &prot);
		}
		++ifp->if_noproto;
		goto drop;
	case PPP_LCP:
		sppp_cp_input(&lcp, sp, m);
		m_freem(m);
		return;
	case PPP_PAP:
		if (sp->pp_phase >= SPPP_PHASE_AUTHENTICATE)
			sppp_pap_input(sp, m);
		m_freem(m);
		return;
	case PPP_CHAP:
		if (sp->pp_phase >= SPPP_PHASE_AUTHENTICATE)
			sppp_chap_input(sp, m);
		m_freem(m);
		return;
	case PPP_IPCP:
		if (sp->pp_phase == SPPP_PHASE_NETWORK)
			sppp_cp_input(&ipcp, sp, m);
		m_freem(m);
		return;
	case PPP_IP:
		if (sp->state[IDX_IPCP] == STATE_OPENED) {
			_sce_pspnet_schednetintr(NETISR_IP);
			inq = sceNetInet_lib_D7928A6D();
		}
		break;
	}

	if (! (ifp->if_flags & IFF_UP) || ! inq)
		goto drop;

	/* Check queue. */
	s = splnet();
	if (IF_QFULL(inq)) {
		/* Queue overflow. */
		IF_DROP(inq);
		splx(s);
		goto drop;
	}
	IF_ENQUEUE(inq, m);
	splx(s);
}

void
sppp_flush(struct ifnet *ifp)
{
	struct sppp *sp = (struct sppp *) ifp;

	IF_PURGE(&sp->pp_if.if_snd);
	IF_PURGE(&sp->pp_cpq);
}

/*
 * Get next packet to send.
 */
struct mbuf *
sppp_dequeue(struct ifnet *ifp)
{
	struct sppp *sp = (struct sppp *) ifp;
	struct mbuf *m;
	int s;

	s = splnet();
	/*
	 * Process only the control protocol queue until we have at
	 * least one NCP open.
	 */
	IF_DEQUEUE(&sp->pp_cpq, m);
	if (m == NULL && sppp_ncp_check(sp))
		IF_DEQUEUE(&sp->pp_if.if_snd, m);
	splx(s);
	return m;
}

/*
 * Process an ioctl request.  Called on low priority level.
 */
int
sppp_ioctl(struct ifnet *ifp, u_long cmd, void *data)
{
	struct ifreq *ifr = (struct ifreq *) data;
	struct sppp *sp = (struct sppp *) ifp;
	int s, error=0, going_up, going_down;

	s = splnet();
	switch (cmd) {
	case SIOCAIFADDR:
	case SIOCSIFDSTADDR:
		break;

	case SIOCSIFADDR:
		if_up(ifp);
		/* fall through... */

	case SIOCSIFFLAGS:
		going_up = (ifp->if_flags & (IFF_UP|IFF_RUNNING)) == IFF_UP;
		going_down = (ifp->if_flags & (IFF_UP|IFF_RUNNING)) == IFF_RUNNING;
		if (going_up || going_down)
			lcp.Close(sp);
		if (going_up) {
			ifp->if_flags |= IFF_RUNNING;
			lcp.Open(sp);
		} else if (going_down) {
			sppp_flush(ifp);
			ifp->if_flags &= ~IFF_RUNNING;
		}
		break;

	case SIOCSIFMTU:
		if (ifr->ifr_mtu < 128 || ifr->ifr_mtu > sp->lcp.their_mru) {
			error = EINVAL;
			break;
		}
		ifp->if_mtu = ifr->ifr_mtu;
		break;

	case SIOCGIFMTU:
		ifr->ifr_mtu = ifp->if_mtu;
		break;

	case SIOCADDMULTI:
	case SIOCDELMULTI:
		break;

	case SPPPSETAUTHCFG:
	case SPPPSETLCPCFG:
	case SPPPRESET:
	case SPPPGETPHASE:
	case SPPPGETSTATUS:
	case SPPPGETIPCP:
		error = sppp_params(sp, cmd, data);
		break;

	default:
		error = ENOTTY;
	}
	splx(s);
	return (error);
}

/*
 * Send PPP control protocol packet.
 */
INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/if_spppsubr", func_000270D8);

/*
 * Handle incoming PPP control protocol packets.
 */
static void
sppp_cp_input(const struct cp *cp, struct sppp *sp, struct mbuf *m)
{
	struct ifnet *ifp = &sp->pp_if;
	struct lcp_header *h;
	int len = m->m_pkthdr.len;
	int rv;
	u_char *p;
	u_int32_t u32;
	u_char ident;
	u_char type;

	if (len < 4)
		return;
	h = mtod(m, struct lcp_header *);
	if (len > PPP_SHORT((u_char *)&h->len))
		len = PPP_SHORT((u_char *)&h->len);
	ident = h->ident;
	type = h->type;
	p = (u_char *)(h + 1);
	switch (type) {
	case CONF_REQ:
		if (len < 4) {
			++ifp->if_ierrors;
			break;
		}
		/* handle states where RCR doesn't get a SCA/SCN */
		switch (sp->state[cp->protoidx]) {
		case STATE_CLOSING:
		case STATE_STOPPING:
			return;
		case STATE_CLOSED:
			sppp_cp_send(sp, cp->proto, TERM_ACK, ident,
				     0, 0);
			return;
		}
		rv = (cp->RCR)(sp, h, len);
		switch (sp->state[cp->protoidx]) {
		case STATE_OPENED:
			(cp->tld)(sp);
			(cp->scr)(sp);
			/* fall through... */
		case STATE_ACK_SENT:
		case STATE_REQ_SENT:
			sppp_cp_change_state(cp, sp, rv?
					     STATE_ACK_SENT: STATE_REQ_SENT);
			break;
		case STATE_STOPPED:
			sp->rst_counter[cp->protoidx] = sp->lcp.max_configure;
			(cp->scr)(sp);
			sppp_cp_change_state(cp, sp, rv?
					     STATE_ACK_SENT: STATE_REQ_SENT);
			break;
		case STATE_ACK_RCVD:
			if (rv) {
				sppp_cp_change_state(cp, sp, STATE_OPENED);
				(cp->tlu)(sp);
			} else
				sppp_cp_change_state(cp, sp, STATE_ACK_RCVD);
			break;
		default:
			++ifp->if_ierrors;
		}
		break;
	case CONF_ACK:
		if (ident != sp->confid[cp->protoidx]) {
			++ifp->if_ierrors;
			break;
		}
		switch (sp->state[cp->protoidx]) {
		case STATE_CLOSED:
		case STATE_STOPPED:
			sppp_cp_send(sp, cp->proto, TERM_ACK, ident, 0, 0);
			break;
		case STATE_CLOSING:
		case STATE_STOPPING:
			break;
		case STATE_REQ_SENT:
			sp->rst_counter[cp->protoidx] = sp->lcp.max_configure;
			sppp_cp_change_state(cp, sp, STATE_ACK_RCVD);
			break;
		case STATE_OPENED:
			(cp->tld)(sp);
			/* fall through */
		case STATE_ACK_RCVD:
			(cp->scr)(sp);
			sppp_cp_change_state(cp, sp, STATE_REQ_SENT);
			break;
		case STATE_ACK_SENT:
			sp->rst_counter[cp->protoidx] = sp->lcp.max_configure;
			sppp_cp_change_state(cp, sp, STATE_OPENED);
			(cp->tlu)(sp);
			break;
		default:
			++ifp->if_ierrors;
		}
		break;
	case CONF_NAK:
	case CONF_REJ:
		if (ident != sp->confid[cp->protoidx]) {
			++ifp->if_ierrors;
			break;
		}
		if (type == CONF_NAK)
			(cp->RCN_nak)(sp, h, len);
		else /* CONF_REJ */
			(cp->RCN_rej)(sp, h, len);

		switch (sp->state[cp->protoidx]) {
		case STATE_CLOSED:
		case STATE_STOPPED:
			sppp_cp_send(sp, cp->proto, TERM_ACK, ident, 0, 0);
			break;
		case STATE_REQ_SENT:
		case STATE_ACK_SENT:
			sp->rst_counter[cp->protoidx] = sp->lcp.max_configure;
			(cp->scr)(sp);
			break;
		case STATE_OPENED:
			(cp->tld)(sp);
			/* fall through */
		case STATE_ACK_RCVD:
			sppp_cp_change_state(cp, sp, STATE_ACK_SENT);
			(cp->scr)(sp);
			break;
		case STATE_CLOSING:
		case STATE_STOPPING:
			break;
		default:
			++ifp->if_ierrors;
		}
		break;

	case TERM_REQ:
		switch (sp->state[cp->protoidx]) {
		case STATE_ACK_RCVD:
		case STATE_ACK_SENT:
			sppp_cp_change_state(cp, sp, STATE_REQ_SENT);
			/* fall through */
		case STATE_CLOSED:
		case STATE_STOPPED:
		case STATE_CLOSING:
		case STATE_STOPPING:
		case STATE_REQ_SENT:
		  sta:
			/* Send Terminate-Ack packet. */
			sppp_cp_send(sp, cp->proto, TERM_ACK, ident, 0, 0);
			break;
		case STATE_OPENED:
			(cp->tld)(sp);
			sp->rst_counter[cp->protoidx] = 0;
			sppp_cp_change_state(cp, sp, STATE_STOPPING);
			goto sta;
		default:
			++ifp->if_ierrors;
		}
		break;
	case TERM_ACK:
		switch (sp->state[cp->protoidx]) {
		case STATE_CLOSED:
		case STATE_STOPPED:
		case STATE_REQ_SENT:
		case STATE_ACK_SENT:
			break;
		case STATE_CLOSING:
			(cp->tlf)(sp);
			sppp_cp_change_state(cp, sp, STATE_CLOSED);
			sppp_lcp_check_and_close(sp);
			break;
		case STATE_STOPPING:
			(cp->tlf)(sp);
			sppp_cp_change_state(cp, sp, STATE_STOPPED);
			sppp_lcp_check_and_close(sp);
			break;
		case STATE_ACK_RCVD:
			sppp_cp_change_state(cp, sp, STATE_REQ_SENT);
			break;
		case STATE_OPENED:
			(cp->tld)(sp);
			(cp->scr)(sp);
			sppp_cp_change_state(cp, sp, STATE_ACK_RCVD);
			break;
		default:
			++ifp->if_ierrors;
		}
		break;
	case CODE_REJ:
		/* XXX catastrophic rejects (RXJ-) aren't handled yet. */
		switch (sp->state[cp->protoidx]) {
		case STATE_CLOSED:
		case STATE_STOPPED:
		case STATE_REQ_SENT:
		case STATE_ACK_SENT:
		case STATE_CLOSING:
		case STATE_STOPPING:
		case STATE_OPENED:
			break;
		case STATE_ACK_RCVD:
			sppp_cp_change_state(cp, sp, STATE_REQ_SENT);
			break;
		default:
			++ifp->if_ierrors;
		}
		break;
	case PROTO_REJ:
	    {
		int catastrophic;
		const struct cp *upper;
		int i;
		u_int16_t proto;

		catastrophic = 0;
		upper = NULL;
		proto = p[0] << 8 | p[1];
		for (i = 0; i < IDX_COUNT; i++) {
			if (cps[i]->proto == proto) {
				upper = cps[i];
				break;
			}
		}
		if (upper == NULL)
			catastrophic++;

		/*
		 * if we got RXJ+ against conf-req, the peer does not implement
		 * this particular protocol type.  terminate the protocol.
		 */
		if (upper && !catastrophic) {
			if (sp->state[upper->protoidx] == STATE_REQ_SENT) {
				upper->Close(sp);
				break;
			}
		}

		/* XXX catastrophic rejects (RXJ-) aren't handled yet. */
		switch (sp->state[cp->protoidx]) {
		case STATE_CLOSED:
		case STATE_STOPPED:
		case STATE_REQ_SENT:
		case STATE_ACK_SENT:
		case STATE_CLOSING:
		case STATE_STOPPING:
		case STATE_OPENED:
			break;
		case STATE_ACK_RCVD:
			sppp_cp_change_state(cp, sp, STATE_REQ_SENT);
			break;
		default:
			++ifp->if_ierrors;
		}
		break;
	    }
	case DISC_REQ:
		if (cp->proto != PPP_LCP)
			goto illegal;
		/* Discard the packet. */
		break;
	case ECHO_REQ:
		if (cp->proto != PPP_LCP)
			goto illegal;
		if (sp->state[cp->protoidx] != STATE_OPENED) {
			++ifp->if_ierrors;
			break;
		}
		if (len < 8)
			break;
		memcpy(&u32, h + 1, sizeof u32);
		if (ntohl(u32) == sp->lcp.magic)
			break;
		u32 = htonl(sp->lcp.magic);
		memcpy(h + 1, &u32, sizeof u32);
		sppp_cp_send(sp, PPP_LCP, ECHO_REPLY, ident, len - 4,
		    h + 1);
		break;
	case ECHO_REPLY:
		if (cp->proto != PPP_LCP)
			goto illegal;
		if (ident != sp->lcp.echoid) {
			++ifp->if_ierrors;
			break;
		}
		if (len < 8)
			break;
		memcpy(&u32, h + 1, sizeof u32);
		if (ntohl(u32) != sp->lcp.magic)
			sp->pp_alivecnt = 0;
		break;
	default:
		/* Unknown packet type -- send Code-Reject packet. */
	  illegal:
		sppp_cp_send(sp, cp->proto, CODE_REJ,
		    ++sp->pp_seq[cp->protoidx], m->m_pkthdr.len, h);
		++ifp->if_ierrors;
	}
}


/*
 * The generic part of all Up/Down/Open/Close/TO event handlers.
 * Basically, the state transition handling in the automaton.
 */
static void
sppp_up_event(const struct cp *cp, struct sppp *sp)
{
	switch (sp->state[cp->protoidx]) {
	case STATE_INITIAL:
		sppp_cp_change_state(cp, sp, STATE_CLOSED);
		break;
	case STATE_STARTING:
		sp->rst_counter[cp->protoidx] = sp->lcp.max_configure;
		(cp->scr)(sp);
		sppp_cp_change_state(cp, sp, STATE_REQ_SENT);
		break;
	}
}

static void
sppp_down_event(const struct cp *cp, struct sppp *sp)
{
	switch (sp->state[cp->protoidx]) {
	case STATE_CLOSED:
	case STATE_CLOSING:
		sppp_cp_change_state(cp, sp, STATE_INITIAL);
		break;
	case STATE_STOPPED:
		(cp->tls)(sp);
		/* fall through */
	case STATE_STOPPING:
	case STATE_REQ_SENT:
	case STATE_ACK_RCVD:
	case STATE_ACK_SENT:
		sppp_cp_change_state(cp, sp, STATE_STARTING);
		break;
	case STATE_OPENED:
		(cp->tld)(sp);
		sppp_cp_change_state(cp, sp, STATE_STARTING);
		break;
	}
}


static void
sppp_open_event(const struct cp *cp, struct sppp *sp)
{
	switch (sp->state[cp->protoidx]) {
	case STATE_INITIAL:
		(cp->tls)(sp);
		sppp_cp_change_state(cp, sp, STATE_STARTING);
		break;
	case STATE_STARTING:
		break;
	case STATE_CLOSED:
		sp->rst_counter[cp->protoidx] = sp->lcp.max_configure;
		(cp->scr)(sp);
		sppp_cp_change_state(cp, sp, STATE_REQ_SENT);
		break;
	case STATE_STOPPED:
	case STATE_STOPPING:
	case STATE_REQ_SENT:
	case STATE_ACK_RCVD:
	case STATE_ACK_SENT:
	case STATE_OPENED:
		break;
	case STATE_CLOSING:
		sppp_cp_change_state(cp, sp, STATE_STOPPING);
		break;
	}
}


static void
sppp_close_event(const struct cp *cp, struct sppp *sp)
{
	switch (sp->state[cp->protoidx]) {
	case STATE_INITIAL:
	case STATE_CLOSED:
	case STATE_CLOSING:
		break;
	case STATE_STARTING:
		(cp->tlf)(sp);
		sppp_cp_change_state(cp, sp, STATE_INITIAL);
		break;
	case STATE_STOPPED:
		sppp_cp_change_state(cp, sp, STATE_CLOSED);
		break;
	case STATE_STOPPING:
		sppp_cp_change_state(cp, sp, STATE_CLOSING);
		break;
	case STATE_OPENED:
		(cp->tld)(sp);
		/* fall through */
	case STATE_REQ_SENT:
	case STATE_ACK_RCVD:
	case STATE_ACK_SENT:
		sp->rst_counter[cp->protoidx] = sp->lcp.max_terminate;
		sppp_cp_send(sp, cp->proto, TERM_REQ,
			     ++sp->pp_seq[cp->protoidx], 0, 0);
		sppp_cp_change_state(cp, sp, STATE_CLOSING);
		break;
	}
}

static void
sppp_to_event(const struct cp *cp, struct sppp *sp)
{
	int s;

	s = splnet();
	if (--sp->rst_counter[cp->protoidx] < 0)
		/* TO- event */
		switch (sp->state[cp->protoidx]) {
		case STATE_CLOSING:
			(cp->tlf)(sp);
			sppp_cp_change_state(cp, sp, STATE_CLOSED);
			sppp_lcp_check_and_close(sp);
			break;
		case STATE_STOPPING:
			(cp->tlf)(sp);
			sppp_cp_change_state(cp, sp, STATE_STOPPED);
			sppp_lcp_check_and_close(sp);
			break;
		case STATE_REQ_SENT:
		case STATE_ACK_RCVD:
		case STATE_ACK_SENT:
			(cp->tlf)(sp);
			sppp_cp_change_state(cp, sp, STATE_STOPPED);
			sppp_lcp_check_and_close(sp);
			break;
		}
	else
		/* TO+ event */
		switch (sp->state[cp->protoidx]) {
		case STATE_CLOSING:
		case STATE_STOPPING:
			sppp_cp_send(sp, cp->proto, TERM_REQ,
			    ++sp->pp_seq[cp->protoidx], 0, 0);
			callout_reset(&sp->ch[cp->protoidx], sp->lcp.timeout,
			    cp->TO, sp);
			break;
		case STATE_REQ_SENT:
		case STATE_ACK_RCVD:
			(cp->scr)(sp);
			/* sppp_cp_change_state() will restart the timer */
			sppp_cp_change_state(cp, sp, STATE_REQ_SENT);
			break;
		case STATE_ACK_SENT:
			(cp->scr)(sp);
			callout_reset(&sp->ch[cp->protoidx], sp->lcp.timeout,
			    cp->TO, sp);
			break;
		}

	splx(s);
}

/*
 * Change the state of a control protocol in the state automaton.
 * Takes care of starting/stopping the restart timer.
 */
static void
sppp_cp_change_state(const struct cp *cp, struct sppp *sp, int newstate)
{
	sp->state[cp->protoidx] = newstate;
	callout_stop(&sp->ch[cp->protoidx]);
	switch (newstate) {
	case STATE_INITIAL:
	case STATE_STARTING:
	case STATE_CLOSED:
	case STATE_STOPPED:
	case STATE_OPENED:
		break;
	case STATE_CLOSING:
	case STATE_STOPPING:
	case STATE_REQ_SENT:
	case STATE_ACK_RCVD:
	case STATE_ACK_SENT:
		callout_reset(&sp->ch[cp->protoidx], sp->lcp.timeout,
		    cp->TO, sp);
		break;
	}
}

/*
 *--------------------------------------------------------------------------*
 *                                                                          *
 *                         The LCP implementation.                          *
 *                                                                          *
 *--------------------------------------------------------------------------*
 */
static void
sppp_lcp_init(struct sppp *sp)
{
	sp->lcp.opts = (1 << LCP_OPT_MAGIC);
	sp->lcp.magic = 0;
	sp->state[IDX_LCP] = STATE_INITIAL;
	sp->fail_counter[IDX_LCP] = 0;
	sp->pp_seq[IDX_LCP] = 0;
	sp->pp_rseq[IDX_LCP] = 0;
	sp->lcp.protos = 0;
}

static void
sppp_lcp_up(struct sppp *sp)
{
	struct ifnet *ifp = &sp->pp_if;

	if (sp->state[IDX_LCP] == STATE_INITIAL) {
		ifp->if_flags |= IFF_RUNNING;
		lcp.Open(sp);
	}
	sppp_up_event(&lcp, sp);
}

static void
sppp_lcp_down(struct sppp *sp)
{
	struct ifnet *ifp = &sp->pp_if;

	sppp_down_event(&lcp, sp);

	if_down(ifp);
	if (sp->state[IDX_LCP] != STATE_INITIAL)
		lcp.Close(sp);
	else
		lcp.tlf(sp);
	ifp->if_flags &= ~IFF_RUNNING;
}

static void
sppp_lcp_open(struct sppp *sp)
{
	sp->pp_flags &= ~PP_NEEDAUTH;
	sppp_open_event(&lcp, sp);
}

static void
sppp_lcp_close(struct sppp *sp)
{
	sppp_close_event(&lcp, sp);
}

static void
sppp_lcp_TO(void *cookie)
{
	sppp_to_event(&lcp, (struct sppp *)cookie);
}

/*
 * Analyze a configure request.  Return true if it was agreeable, and
 * caused action sca, false if it has been rejected or nak'ed, and
 * caused action scn.  (The return value is used to make the state
 * transition decision in the state automaton.)
 */
static int
sppp_lcp_RCR(struct sppp *sp, struct lcp_header *h, int len)
{
	u_char *buf, *r, *p;
	int origlen, rlen, optlen = 0;
	u_int32_t nmagic;
	u_short authproto;

	len -= 4;
	origlen = len;
	buf = r = malloc (len, M_TEMP, M_NOWAIT);
	if (! buf)
		return (0);

	/* pass 1: check for things that need to be rejected */
	p = (void *)(h + 1);
	for (rlen=0; len>1 && p[1]; len-=p[1], p+=p[1]) {
		switch (*p) {
		case LCP_OPT_MAGIC:
			/* Magic number. */
			/* fall through, both are same length */
		case LCP_OPT_ASYNC_MAP:
			/* Async control character map. */
			if (len >= 6 && p[1] == 6)
				continue;
			break;
		case LCP_OPT_MRU:
			/* Maximum receive unit. */
			if (len >= 4 && p[1] == 4)
				continue;
			break;
		case LCP_OPT_AUTH_PROTO:
			if (len < 4)
				break;
			authproto = (p[2] << 8) + p[3];
			if (authproto == PPP_PAP && p[1] != 4)
				break;
			if (authproto == PPP_CHAP && p[1] != 5)
				break;
			sp->pp_flags |= PP_NEEDAUTH;
			continue;
		default:
			/* Others not supported. */
			break;
		}
		/* Add the option to rejected list. */
		bcopy (p, r, p[1]);
		r += p[1];
		rlen += p[1];
	}
	if (rlen) {
		sppp_cp_send(sp, PPP_LCP, CONF_REJ, h->ident, rlen, buf);
		goto end;
	}

	/*
	 * pass 2: check for option values that are unacceptable and
	 * thus require to be nak'ed.
	 */
	p = (void *)(h + 1);
	len = origlen;
	for (rlen=0; len>1 && p[1]; len-=p[1], p+=p[1]) {
		switch (*p) {
		case LCP_OPT_MAGIC:
			/* Magic number -- extract. */
			nmagic = (u_int32_t)p[2] << 24 |
				(u_int32_t)p[3] << 16 | p[4] << 8 | p[5];
			if (nmagic != sp->lcp.magic)
				continue;
			nmagic = ~sp->lcp.magic;
			/* Gonna NAK it. */
			r[2] = nmagic >> 24;
			r[3] = nmagic >> 16;
			r[4] = nmagic >> 8;
			r[5] = nmagic;
			optlen = 4;
			break;

		case LCP_OPT_ASYNC_MAP:
			continue;

		case LCP_OPT_MRU:
			sp->lcp.their_mru = p[2] * 256 + p[3];
			continue;

		case LCP_OPT_AUTH_PROTO:
			authproto = (p[2] << 8) + p[3];
			if (authproto != PPP_PAP && authproto != PPP_CHAP) {
				sp->myauth.proto = PPP_PAP;
				r[2] = sp->myauth.proto >> 8;
				r[3] = sp->myauth.proto;
				optlen = 4;
				break;
			}
			if (authproto == PPP_CHAP && p[4] != CHAP_MD5) {
				sp->myauth.proto = PPP_CHAP;
				r[2] = sp->myauth.proto >> 8;
				r[3] = sp->myauth.proto;
				r[4] = CHAP_MD5;
				optlen = 5;
				break;
			}
			sp->myauth.proto = authproto;
			continue;
		}
		/* Add the option to nak'ed list. */
		r[0] = p[0];
		r[1] = optlen;
		r += optlen;
		rlen += optlen;
	}
	if (rlen) {
		if (++sp->fail_counter[IDX_LCP] >= sp->lcp.max_failure) {
			sppp_cp_send(sp, PPP_LCP, CONF_REJ, h->ident, rlen, buf);
		} else {
			sppp_cp_send(sp, PPP_LCP, CONF_NAK, h->ident, rlen, buf);
		}
		goto end;
	} else {
		sp->fail_counter[IDX_LCP] = 0;
		sppp_cp_send(sp, PPP_LCP, CONF_ACK, h->ident, origlen, h + 1);
	}

 end:
	free(buf, M_TEMP);
	return (rlen == 0);
}

/*
 * Analyze the LCP Configure-Reject option list, and adjust our
 * negotiation.
 */
static void
sppp_lcp_RCN_rej(struct sppp *sp, struct lcp_header *h, int len)
{
	u_char *buf, *p;

	len -= 4;
	buf = malloc (len, M_TEMP, M_NOWAIT);
	if (!buf)
		return;

	p = (void *)(h + 1);
	for (; len > 1 && p[1]; len -= p[1], p += p[1]) {
		switch (*p) {
		case LCP_OPT_MAGIC:
			/* Magic number -- can't use it, use 0 */
			sp->lcp.opts &= ~(1 << LCP_OPT_MAGIC);
			sp->lcp.magic = 0;
			break;
		case LCP_OPT_MRU:
			sp->lcp.opts &= ~(1 << LCP_OPT_MRU);
			break;
		}
	}
	free(buf, M_TEMP);
	return;
}

/*
 * Analyze the LCP Configure-NAK option list, and adjust our
 * negotiation.
 */
static void
sppp_lcp_RCN_nak(struct sppp *sp, struct lcp_header *h, int len)
{
	u_char *buf, *p;

	len -= 4;
	buf = malloc (len, M_TEMP, M_NOWAIT);
	if (!buf)
		return;

	p = (void *)(h + 1);
	for (; len > 1 && p[1]; len -= p[1], p += p[1]) {
		switch (*p) {
		case LCP_OPT_MAGIC:
			if (len >= 6 && p[1] == 6) {
				sp->lcp.magic = (u_int32_t)p[2] << 24 |
					(u_int32_t)p[3] << 16 | p[4] << 8 | p[5];
				sp->lcp.opts |= (1 << LCP_OPT_MAGIC);
			}
			break;
		case LCP_OPT_MRU:
			if (len >= 4 && p[1] == 4) {
				sp->lcp.mru = p[2] * 256 + p[3];
				sp->lcp.opts |= (1 << LCP_OPT_MRU);
			}
			break;
		}
	}
	free(buf, M_TEMP);
	return;
}

#define SET_PHASE_STATUS(sp) \
	((sp)->pp_status = (sp)->pp_status < (sp)->pp_phase ? (sp)->pp_phase : (sp)->pp_status)

static void
sppp_lcp_tlu(struct sppp *sp)
{
	int i;
	u_int32_t mask;

	for (i = 0; i < IDX_COUNT; i++)
		if ((cps[i])->flags & CP_QUAL)
			(cps[i])->Open(sp);

	if ((sp->lcp.opts & (1 << LCP_OPT_AUTH_PROTO)) != 0 ||
	    (sp->pp_flags & PP_NEEDAUTH) != 0)
		sp->pp_phase = SPPP_PHASE_AUTHENTICATE;
	else
		sp->pp_phase = SPPP_PHASE_NETWORK;
	SET_PHASE_STATUS(sp);

	/*
	 * Open all authentication protocols.
	 */
	for (i = 0; i < IDX_COUNT; i++)
		if ((cps[i])->flags & CP_AUTH)
			(cps[i])->Open(sp);

	if (sp->pp_phase == SPPP_PHASE_NETWORK) {
		/* Notify all NCPs. */
		for (i = 0; i < IDX_COUNT; i++)
			if ((cps[i])->flags & CP_NCP)
				(cps[i])->Open(sp);
	}

	/* Send Up events to all started protos. */
	for (i = 0, mask = 1; i < IDX_COUNT; i++, mask <<= 1)
		if ((sp->lcp.protos & mask) && ((cps[i])->flags & CP_LCP) == 0)
			(cps[i])->Up(sp);

	/* notify low-level driver of state change */
	if (sp->pp_chg)
		sp->pp_chg(sp, (int)sp->pp_phase);

	if (sp->pp_phase == SPPP_PHASE_NETWORK)
		/* if no NCP is starting, close down */
		sppp_lcp_check_and_close(sp);
}

static void
sppp_lcp_tld(struct sppp *sp)
{
	int i;
	u_int32_t mask;

	sp->pp_phase = SPPP_PHASE_TERMINATE;

	/*
	 * Take upper layers down.  We send the Down event first and
	 * the Close second to prevent the upper layers from sending
	 * ``a flurry of terminate-request packets'', as the RFC
	 * describes it.
	 */
	for (i = 0, mask = 1; i < IDX_COUNT; i++, mask <<= 1)
		if ((sp->lcp.protos & mask) && ((cps[i])->flags & CP_LCP) == 0) {
			(cps[i])->Down(sp);
			(cps[i])->Close(sp);
		}
}

static void
sppp_lcp_tls(struct sppp *sp)
{
	sp->pp_phase = SPPP_PHASE_ESTABLISH;
	SET_PHASE_STATUS(sp);

	/* Notify lower layer if desired. */
	if (sp->pp_tls)
		(sp->pp_tls)(sp);
}

static void
sppp_lcp_tlf(struct sppp *sp)
{
	sp->pp_phase = SPPP_PHASE_DEAD;

	/* Notify lower layer if desired. */
	if (sp->pp_tlf)
		(sp->pp_tlf)(sp);
}

static void
sppp_lcp_scr(struct sppp *sp)
{
	char opt[6 /* magicnum */ + 4 /* mru */ + 5 /* chap */];
	int i = 0;

	if (sp->lcp.opts & (1 << LCP_OPT_MAGIC)) {
		if (! sp->lcp.magic)
			sp->lcp.magic = random();
		opt[i++] = LCP_OPT_MAGIC;
		opt[i++] = 6;
		opt[i++] = sp->lcp.magic >> 24;
		opt[i++] = sp->lcp.magic >> 16;
		opt[i++] = sp->lcp.magic >> 8;
		opt[i++] = sp->lcp.magic;
	}

	if (sp->lcp.opts & (1 << LCP_OPT_MRU)) {
		opt[i++] = LCP_OPT_MRU;
		opt[i++] = 4;
		opt[i++] = sp->lcp.mru >> 8;
		opt[i++] = sp->lcp.mru;
	}

	sp->confid[IDX_LCP] = ++sp->pp_seq[IDX_LCP];
	sppp_cp_send(sp, PPP_LCP, CONF_REQ, sp->confid[IDX_LCP], i, &opt);
}

/*
 * Check the open NCPs, return true if at least one NCP is open.
 */
static int
sppp_ncp_check(struct sppp *sp)
{
	int i, mask;

	for (i = 0, mask = 1; i < IDX_COUNT; i++, mask <<= 1)
		if ((sp->lcp.protos & mask) && (cps[i])->flags & CP_NCP)
			return 1;
	return 0;
}

/*
 * Re-check the open NCPs and see if we should terminate the link.
 * Called by the NCPs during their tlf action handling.
 */
static void
sppp_lcp_check_and_close(struct sppp *sp)
{

	if (sp->pp_phase < SPPP_PHASE_NETWORK)
		/* don't bother, we are already going down */
		return;

	if (sppp_ncp_check(sp))
		return;

	lcp.Close(sp);
}


/*
 *--------------------------------------------------------------------------*
 *                                                                          *
 *                        The IPCP implementation.                          *
 *                                                                          *
 *--------------------------------------------------------------------------*
 */

static void
sppp_ipcp_init(struct sppp *sp)
{
	sp->ipcp.opts = 0;
	sp->ipcp.flags = 0;
	sp->state[IDX_IPCP] = STATE_INITIAL;
	sp->fail_counter[IDX_IPCP] = 0;
	sp->pp_seq[IDX_IPCP] = 0;
	sp->pp_rseq[IDX_IPCP] = 0;
}

static void
sppp_ipcp_up(struct sppp *sp)
{
	sppp_up_event(&ipcp, sp);
}

static void
sppp_ipcp_down(struct sppp *sp)
{
	sppp_down_event(&ipcp, sp);
}

static void
sppp_ipcp_open(struct sppp *sp)
{
	sp->ipcp.flags = 0;
	sp->ipcp.opts |= (1 << IPCP_OPT_ADDRESS) | (1 << (IPCP_OPT_PRIMDNS - 100));
	sp->ipcp.opts |= (1 << (IPCP_OPT_SECDNS - 100));
	sp->ipcp.myaddr = 0;
	sp->ipcp.hisaddr = 0;
	sp->dns_addrs[0] = 0;
	sp->dns_addrs[1] = 0;
	sppp_open_event(&ipcp, sp);
}

static void
sppp_ipcp_close(struct sppp *sp)
{
	sppp_close_event(&ipcp, sp);

	if (sp->pp_saved_mtu > 0) {
		sp->pp_if.if_mtu = sp->pp_saved_mtu;
		sp->pp_saved_mtu = 0;
	}
}

static void
sppp_ipcp_TO(void *cookie)
{
	sppp_to_event(&ipcp, (struct sppp *)cookie);
}

/*
 * Analyze a configure request.  Return true if it was agreeable, and
 * caused action sca, false if it has been rejected or nak'ed, and
 * caused action scn.  (The return value is used to make the state
 * transition decision in the state automaton.)
 */
static int
sppp_ipcp_RCR(struct sppp *sp, struct lcp_header *h, int len)
{
	u_char *buf, *r, *p;
	int rlen, origlen;

	len -= 4;
	origlen = len;
	buf = r = malloc ((len < 6 ? 6 : len), M_TEMP, M_NOWAIT);
	if (! buf)
		return (0);

	/* pass 1: see if we can recognize them */
	p = (void *)(h + 1);
	for (rlen=0; len>1 && p[1]; len-=p[1], p+=p[1]) {
		switch (*p) {
		case IPCP_OPT_ADDRESS:
		case IPCP_OPT_PRIMDNS:
		case IPCP_OPT_SECDNS:
			if (len >= 6 && p[1] == 6) {
				/* correctly formed address option */
				continue;
			}
			break;
		default:
			/* Others not supported. */
			break;
		}
		/* Add the option to rejected list. */
		bcopy (p, r, p[1]);
		r += p[1];
		rlen += p[1];
	}
	if (rlen) {
		sppp_cp_send(sp, PPP_IPCP, CONF_REJ, h->ident, rlen, buf);
		goto end;
	}

	/* pass 2: parse option values */
	p = (void *)(h + 1);
	len = origlen;
	for (rlen=0; len>1 && p[1]; len-=p[1], p+=p[1]) {
		switch (*p) {
		case IPCP_OPT_ADDRESS:
			sp->ipcp.hisaddr = (u_int32_t)p[2] << 24 |
				(u_int32_t)p[3] << 16 | p[4] << 8 | p[5];
			sp->ipcp.flags |= IPCP_HISADDR_SEEN;
			continue;
		case IPCP_OPT_PRIMDNS:
			sp->dns_addrs[0] = (u_int32_t)p[2] << 24 |
				(u_int32_t)p[3] << 16 | p[4] << 8 | p[5];
			sp->ipcp.flags |= IPCP_PRIMDNS_SEEN;
			continue;
		case IPCP_OPT_SECDNS:
			sp->dns_addrs[1] = (u_int32_t)p[2] << 24 |
				(u_int32_t)p[3] << 16 | p[4] << 8 | p[5];
			sp->ipcp.flags |= IPCP_SECDNS_SEEN;
			continue;
		}
		/* Add the option to nak'ed list. */
		bcopy (p, r, p[1]);
		r += p[1];
		rlen += p[1];
	}

	if (rlen) {
		if (++sp->fail_counter[IDX_IPCP] >= sp->lcp.max_failure) {
			sppp_cp_send(sp, PPP_IPCP, CONF_REJ, h->ident, rlen, buf);
		} else {
			sppp_cp_send(sp, PPP_IPCP, CONF_NAK, h->ident, rlen, buf);
		}
	} else {
		sppp_cp_send(sp, PPP_IPCP, CONF_ACK, h->ident, origlen, h + 1);
	}

 end:
	free(buf, M_TEMP);
	return (rlen == 0);
}

/*
 * Analyze the IPCP Configure-Reject option list, and adjust our
 * negotiation.
 */
static void
sppp_ipcp_RCN_rej(struct sppp *sp, struct lcp_header *h, int len)
{
	u_char *p;

	len -= 4;

	p = (void *)(h + 1);
	for (; len > 1 && p[1]; len -= p[1], p += p[1]) {
		switch (*p) {
		case IPCP_OPT_ADDRESS:
			sp->ipcp.opts &= ~(1 << IPCP_OPT_ADDRESS);
			break;
		case IPCP_OPT_PRIMDNS:
			sp->ipcp.opts &= ~(1 << (IPCP_OPT_PRIMDNS - 100));
			break;
		case IPCP_OPT_SECDNS:
			sp->ipcp.opts &= ~(1 << (IPCP_OPT_SECDNS - 100));
			break;
		}
	}
}

/*
 * Analyze the IPCP Configure-NAK option list, and adjust our
 * negotiation.
 */
static void
sppp_ipcp_RCN_nak(struct sppp *sp, struct lcp_header *h, int len)
{
	u_char *p;

	len -= 4;

	p = (void *)(h + 1);
	for (; len > 1 && p[1]; len -= p[1], p += p[1]) {
		switch (*p) {
		case IPCP_OPT_ADDRESS:
			if (len >= 6 && p[1] == 6) {
				sp->ipcp.myaddr = (u_int32_t)p[2] << 24 |
					(u_int32_t)p[3] << 16 | p[4] << 8 | p[5];
				sp->ipcp.flags |= IPCP_MYADDR_SEEN;
			}
			break;
		case IPCP_OPT_PRIMDNS:
			if (len >= 6 && p[1] == 6) {
				sp->dns_addrs[0] = (u_int32_t)p[2] << 24 |
					(u_int32_t)p[3] << 16 | p[4] << 8 | p[5];
				sp->ipcp.flags |= IPCP_PRIMDNS_SEEN;
			}
			break;
		case IPCP_OPT_SECDNS:
			if (len >= 6 && p[1] == 6) {
				sp->dns_addrs[1] = (u_int32_t)p[2] << 24 |
					(u_int32_t)p[3] << 16 | p[4] << 8 | p[5];
				sp->ipcp.flags |= IPCP_SECDNS_SEEN;
			}
			break;
		}
	}
}

static void
sppp_ipcp_tlu(struct sppp *sp)
{
	struct ifnet *ifp = &sp->pp_if;

	sp->pp_status = 2;
	sp->ipcp.flags |= IPCP_UP;

	if (ifp->if_mtu > sp->lcp.their_mru) {
		sp->pp_saved_mtu = ifp->if_mtu;
		ifp->if_mtu = sp->lcp.their_mru;
	}

	if (sp->pp_con)
		sp->pp_con(sp);
}

static void
sppp_ipcp_tld(struct sppp *sp)
{
	sp->ipcp.flags &= ~IPCP_UP;
}

static void
sppp_ipcp_tls(struct sppp *sp)
{
	/* indicate to LCP that it must stay alive */
	sp->lcp.protos |= (1 << IDX_IPCP);
}

static void
sppp_ipcp_tlf(struct sppp *sp)
{
	/* we no longer need LCP */
	sp->lcp.protos &= ~(1 << IDX_IPCP);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/if_spppsubr", func_000286B4);


/*
 *--------------------------------------------------------------------------*
 *                                                                          *
 *                        The CHAP implementation.                          *
 *                                                                          *
 *--------------------------------------------------------------------------*
 */

/*
 * Handle incoming CHAP packets.
 */
static void
sppp_chap_input(struct sppp *sp, struct mbuf *m)
{
	struct lcp_header *h;
	int len, s;
	u_char *value, value_len, ident;
	u_char digest[16];
	u_char dsize;
	MD5_CTX ctx;
	u_char type;

	len = m->m_pkthdr.len;
	if (len < 4)
		return;
	h = mtod(m, struct lcp_header *);
	type = h->type;
	ident = h->ident;
	if (len > PPP_SHORT((u_char *)&h->len))
		len = PPP_SHORT((u_char *)&h->len);

	switch (type) {
	/* challenge, failure and success are his authproto */
	case CHAP_CHALLENGE:
		value = 1 + (u_char *)(h + 1);
		value_len = value[-1];

		if (len - value_len - 5 < 0)
			break;

		MD5Init(&ctx);
		MD5Update(&ctx, &ident, 1);
		MD5Update(&ctx, sp->myauth.secret, sp->myauth.secret_len);
		MD5Update(&ctx, value, value_len);
		MD5Final(digest, &ctx);
		dsize = sizeof digest;

		sppp_auth_send(&chap, sp, CHAP_RESPONSE, ident,
			       sizeof dsize, (const char *)&dsize,
			       sizeof digest, digest,
			       (size_t)sp->myauth.name_len,
			       sp->myauth.name,
			       0);
		callout_reset(&sp->ch[IDX_CHAP], sp->myauth.timeout,
		    sppp_chap_my_TO, sp);
		sp->rst_counter[IDX_CHAP] = sp->myauth.max_configure;
		sp->chap_ident = ident;
		memcpy(sp->chap_value, value, value_len);
		sp->chap_value_len = value_len;
		break;

	case CHAP_RESPONSE:
		break;

	case CHAP_SUCCESS:
		callout_stop(&sp->ch[IDX_CHAP]);
		s = splimp();
		sp->pp_flags &= ~PP_NEEDAUTH;
		splx(s);
		sppp_phase_network(sp);
		break;

	case CHAP_FAILURE:
		callout_stop(&sp->ch[IDX_CHAP]);
		s = splimp();
		splx(s);
		break;
	}
}


/*
 *--------------------------------------------------------------------------*
 *                                                                          *
 *                        The PAP implementation.                           *
 *                                                                          *
 *--------------------------------------------------------------------------*
 */

/*
 * Handle incoming PAP packets.  */
static void
sppp_pap_input(struct sppp *sp, struct mbuf *m)
{
	struct lcp_header *h;
	int len, s;

	len = m->m_pkthdr.len;
	if (len < 5)
		return;
	h = mtod(m, struct lcp_header *);
	switch (h->type) {
	case PAP_REQ:
		break;
	/* ack and nak are his authproto */
	case PAP_ACK:
		callout_stop(&sp->ch[IDX_PAP]);
		s = splimp();
		sp->pp_flags &= ~PP_NEEDAUTH;
		splx(s);
		sppp_phase_network(sp);
		break;

	case PAP_NAK:
		callout_stop(&sp->ch[IDX_PAP]);
		break;
	}
}

static void
sppp_pap_init(struct sppp *sp)
{
	/* PAP doesn't have STATE_INITIAL at all. */
	sp->state[IDX_PAP] = STATE_CLOSED;
	sp->fail_counter[IDX_PAP] = 0;
	sp->pp_seq[IDX_PAP] = 0;
	sp->pp_rseq[IDX_PAP] = 0;
}

static void
sppp_pap_open(struct sppp *sp)
{
	if (sp->myauth.proto == PPP_PAP) {
		/* we are peer, send a request, and start a timer */
		pap.scr(sp);
		callout_reset(&sp->ch[IDX_PAP], sp->myauth.timeout,
		    sppp_pap_my_TO, sp);
		sp->rst_counter[IDX_PAP] = sp->myauth.max_configure;
	}
}

static void
sppp_pap_close(struct sppp *sp)
{
	if (sp->state[IDX_PAP] != STATE_CLOSED)
		sppp_cp_change_state(&pap, sp, STATE_CLOSED);
}

/*
 * That's the timeout routine if we are authenticator.  Since the
 * authenticator is basically passive in PAP, we can't do much here.
 */
static void
sppp_pap_TO(void *cookie)
{
}

/*
 * That's the timeout handler if we are peer.  Since the peer is active,
 * we need to retransmit our PAP request since it is apparently lost.
 * XXX We should impose a max counter.
 */
static void
sppp_pap_my_TO(void *cookie)
{
	struct sppp *sp = (struct sppp *)cookie;

	if (--sp->rst_counter[IDX_PAP] < 0) {
		pap.tld(sp);
		sppp_cp_change_state(&pap, sp, STATE_CLOSED);
	} else {
		callout_reset(&sp->ch[IDX_PAP], sp->myauth.timeout,
		    sppp_pap_my_TO, sp);
		pap.scr(sp);
	}
}

static void
sppp_pap_tlu(struct sppp *sp)
{
}

static void
sppp_pap_tld(struct sppp *sp)
{
	callout_stop(&sp->ch[IDX_PAP]);
	sp->lcp.protos &= ~(1 << IDX_PAP);

	lcp.Close(sp);
}

static void
sppp_pap_scr(struct sppp *sp)
{
	u_char idlen, pwdlen;

	sp->confid[IDX_PAP] = ++sp->pp_seq[IDX_PAP];
	pwdlen = sp->myauth.secret_len;
	idlen = sp->myauth.name_len;

	sppp_auth_send(&pap, sp, PAP_REQ, sp->confid[IDX_PAP],
		       sizeof idlen, (const char *)&idlen,
		       (size_t)idlen, sp->myauth.name,
		       sizeof pwdlen, (const char *)&pwdlen,
		       (size_t)pwdlen, sp->myauth.secret,
		       0);
}

static void
sppp_chap_init(struct sppp *sp)
{
	/* Chap doesn't have STATE_INITIAL at all. */
	sp->state[IDX_CHAP] = STATE_CLOSED;
	sp->fail_counter[IDX_CHAP] = 0;
	sp->pp_seq[IDX_CHAP] = 0;
	sp->pp_rseq[IDX_CHAP] = 0;
}

static void
sppp_chap_open(struct sppp *sp)
{
}

static void
sppp_chap_close(struct sppp *sp)
{
	if (sp->state[IDX_CHAP] != STATE_CLOSED)
		sppp_cp_change_state(&chap, sp, STATE_CLOSED);
}

static void
sppp_chap_TO(void *cookie)
{
}

static void
sppp_chap_my_TO(void *cookie)
{
	struct sppp *sp = (struct sppp *)cookie;
	MD5_CTX ctx;
	u_char digest[16];
	u_char dsize;

	if (--sp->rst_counter[IDX_CHAP] < 0) {
		chap.tld(sp);
		sppp_cp_change_state(&pap, sp, STATE_CLOSED);
	} else {
		MD5Init(&ctx);
		MD5Update(&ctx, &sp->chap_ident, 1);
		MD5Update(&ctx, sp->myauth.secret, sp->myauth.secret_len);
		MD5Update(&ctx, sp->chap_value, sp->chap_value_len);
		MD5Final(digest, &ctx);
		dsize = sizeof digest;

		sppp_auth_send(&chap, sp, CHAP_RESPONSE, sp->chap_ident,
			       sizeof dsize, (const char *)&dsize,
			       sizeof digest, digest,
			       (size_t)sp->myauth.name_len,
			       sp->myauth.name,
			       0);
		callout_reset(&sp->ch[IDX_CHAP], sp->myauth.timeout,
		    sppp_chap_my_TO, sp);
	}
}

static void
sppp_chap_tlu(struct sppp *sp)
{
}

static void
sppp_chap_tld(struct sppp *sp)
{
	callout_stop(&sp->ch[IDX_CHAP]);
	sp->lcp.protos &= ~(1 << IDX_CHAP);

	lcp.Close(sp);
}

static void
sppp_chap_scr(struct sppp *sp)
{
}

/*
 * Random miscellaneous functions.
 */

/*
 * Send a PAP or CHAP proto packet.
 *
 * Varadic function, each of the elements for the ellipsis is of type
 * ``size_t mlen, const u_char *msg''.  Processing will stop iff
 * mlen == 0.
 * NOTE: never declare variadic functions with types subject to type
 * promotion (i.e. u_char). This is asking for big trouble depending
 * on the architecture you are on...
 */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/if_spppsubr", func_00028AAC);

/*
 * Send keepalive packets, every 10 seconds.
 */
static void
sppp_keepalive(void *arg)
{
	struct sppp *sp = (struct sppp *)arg;
	struct ifnet *ifp = &sp->pp_if;
	int s;

	s = splnet();
	if ((sp->pp_flags & PP_KEEPALIVE) && (ifp->if_flags & IFF_RUNNING) &&
	    sp->pp_phase >= SPPP_PHASE_AUTHENTICATE) {
		if (sp->pp_alivecnt == MAXALIVECNT) {
			/* No keepalive packets got.  Stop the interface. */
			if_down (ifp);
			IF_PURGE(&sp->pp_cpq);
			sp->pp_alivecnt = 0;

			/* we are down, close all open protocols */
			lcp.Close(sp);

			/* And now prepare LCP to reestablish the link, if configured to do so. */
			sppp_cp_change_state(&lcp, sp, STATE_STOPPED);

			/* Close connection imediatly, completition of this
			 * will summon the magic needed to reestablish it. */
			sp->pp_tlf(sp);
		} else {
			int32_t nmagic;

			if (sp->pp_alivecnt <= MAXALIVECNT)
				++sp->pp_alivecnt;
			nmagic = htonl(sp->lcp.magic);
			sp->lcp.echoid = ++sp->pp_seq[IDX_LCP];
			sppp_cp_send(sp, PPP_LCP, ECHO_REQ,
				sp->lcp.echoid, 4, &nmagic);
		}
	}
	splx(s);
	callout_reset(&keepalive_ch, hz * 10, sppp_keepalive, sp);
}

static int
sppp_params(struct sppp *sp, int cmd, void *data)
{
	switch (cmd) {
	case SPPPGETPHASE:
		((struct spppstatus *)data)->value = sp->pp_phase;
		break;
	case SPPPGETSTATUS:
		((struct spppstatus *)data)->value = sp->pp_status;
		break;
	case SPPPGETIPCP:
	    {
		struct spppipcp *ip = (struct spppipcp *)data;

		ip->flags = sp->ipcp.flags;
		ip->myaddr = sp->ipcp.myaddr;
		ip->hisaddr = sp->ipcp.hisaddr;
		ip->dns_addrs[0] = sp->dns_addrs[0];
		ip->dns_addrs[1] = sp->dns_addrs[1];
	    }
		break;
	case SPPPSETAUTHCFG:
	    {
		struct spppauthcfg *cfg = (struct spppauthcfg *)data;

		memcpy(sp->myauth.name, cfg->name, AUTHNAMELEN);
		sp->myauth.name_len = sppp_strnlen(cfg->name, AUTHNAMELEN);
		memcpy(sp->myauth.secret, cfg->secret, AUTHKEYLEN);
		sp->myauth.secret_len = sppp_strnlen(cfg->secret, AUTHKEYLEN);
		sp->myauth.timeout = cfg->timeout;
		sp->myauth.max_configure = cfg->max_configure;
	    }
		break;
	case SPPPSETLCPCFG:
	    {
		struct sppplcpcfg *lcpp = (struct sppplcpcfg *)data;

		sp->lcp.timeout = lcpp->timeout;
		sp->lcp.max_terminate = lcpp->max_terminate;
		sp->lcp.max_configure = lcpp->max_configure;
		sp->lcp.max_failure = lcpp->max_failure;
	    }
		break;
	case SPPPRESET:
		sppp_lcp_init(sp);
		sppp_ipcp_init(sp);
		sppp_pap_init(sp);
		sppp_chap_init(sp);
		sp->pp_status = 0;
		break;
	default:
		return (EINVAL);
	}

	return (0);
}

static void
sppp_phase_network(struct sppp *sp)
{
	int i;
	u_int32_t mask;

	sp->pp_phase = SPPP_PHASE_NETWORK;
	SET_PHASE_STATUS(sp);

	/* Notify NCPs now. */
	for (i = 0; i < IDX_COUNT; i++)
		if ((cps[i])->flags & CP_NCP)
			(cps[i])->Open(sp);

	/* Send Up events to all NCPs. */
	for (i = 0, mask = 1; i < IDX_COUNT; i++, mask <<= 1)
		if ((sp->lcp.protos & mask) && ((cps[i])->flags & CP_NCP))
			(cps[i])->Up(sp);

	/* if no NCP is starting, all this was in vain, close down */
	sppp_lcp_check_and_close(sp);
}

static int
sppp_strnlen(u_char *p, int max)
{
	int len;

	for (len = 0; len < max && *p; ++p)
		++len;
	return len;
}

__attribute__((noinline)) void
sppp_attach(struct ifnet *ifp)
{
	struct sppp *sp = (struct sppp *) ifp;
	int i;

	callout_init(&keepalive_ch);
	callout_reset(&keepalive_ch, hz * 10, sppp_keepalive, sp);

	sp->pp_if.if_type = IFT_PPP;
	sp->pp_if.if_output = sppp_output;
	sp->pp_cpq.ifq_maxlen = 20;
	sp->pp_alivecnt = 0;
	memset(&sp->pp_seq[0], 0, sizeof(sp->pp_seq));
	memset(&sp->pp_rseq[0], 0, sizeof(sp->pp_rseq));
	sp->pp_phase = SPPP_PHASE_DEAD;
	sp->pp_up = lcp.Up;
	sp->pp_down = lcp.Down;

	memset(&sp->myauth, 0, sizeof sp->myauth);
	sppp_lcp_init(sp);
	sppp_ipcp_init(sp);
	sppp_pap_init(sp);
	sppp_chap_init(sp);
	for (i = 0; i < IDX_COUNT; i++)
		callout_init(&sp->ch[i]);
}

__attribute__((noinline)) void
sppp_detach(struct ifnet *ifp)
{
	struct sppp *sp = (struct sppp *) ifp;
	int i;

	callout_stop(&keepalive_ch);
	for (i = 0; i < IDX_COUNT; i++)
		callout_stop(&sp->ch[i]);
}

/*
 * Return true if the interface has packets to send.
 */
__attribute__((noinline)) int
sppp_isempty(struct ifnet *ifp)
{
	struct sppp *sp = (struct sppp *) ifp;
	int empty, s;

	s = splnet();
	empty = !sp->pp_cpq.ifq_len && !sp->pp_if.if_snd.ifq_len;
	splx(s);
	return (empty);
}

/*
 * Enqueue transmit packet.
 */
INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/if_spppsubr", func_00029384);

static void
sppp_null(struct sppp *unused)
{
	/* do just nothing */
}
