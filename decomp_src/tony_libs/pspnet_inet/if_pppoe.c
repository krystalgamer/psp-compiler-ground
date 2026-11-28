/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"
#include "if_spppvar.h"

/* NetBSD 1.6 net/if_pppoe.c, cut down by Sony to a single PPPoE interface */

#define pppoe_detach func_0002A850
#define pppoe_softintr func_0002A980
#define pppoe_disc_input func_0002AAA0
#define pppoe_data_input func_0002AABC
#define pppoe_ioctl func_0002AC08
#define pppoe_timeout func_0002ADA8
#define pppoe_disconnect func_0002AECC
#define pppoe_send_padr func_0002AF88
#define pppoe_send_padt func_0002B24C
#define pppoe_start func_0002B350
#define pppoe_ether_input func_0002B564
#define pppoe_attach func_0002B640
#define pppoe_dispatch_disc_pkt func_0002B79C
#define pppoe_tls func_0002BD24
#define pppoe_tlf func_0002BDB4
#define pppoe_send_padi func_0002BE00
#define pppoe_get_mbuf func_0002C0F4

#define pppoe_softc0 D_0002EC78

#define splnet _sce_pspnet_spllock
#define splx _sce_pspnet_splunlock
#define malloc(size, type, flags) sceNetMallocInternal(size)
#define free(p, type) sceNetFreeInternal(p)
#define hz 100

struct ifnet *_sce_pspnet_ifunit(const char *name);
void _sce_pspnet_if_detach(struct ifnet *ifp);
#define ifunit _sce_pspnet_ifunit
#define if_detach _sce_pspnet_if_detach

#define IFT_PPP 0x17
#define ETHERTYPE_PPPOEDISC 0x8863
#define ETHERTYPE_PPPOE 0x8864
#define NETISR_PPPOE 30

#define PPPOE_STATE_INITIAL 0
#define PPPOE_STATE_PADI_SENT 1
#define PPPOE_STATE_PADR_SENT 2
#define PPPOE_STATE_SESSION 3
#define PPPOE_STATE_CLOSING 4

#define PPPOE_HEADERLEN 6
#define PPPOE_VERTYPE 0x11

#define PPPOE_TAG_EOL		0x0000		/* end of list */
#define PPPOE_TAG_SNAME		0x0101		/* service name */
#define PPPOE_TAG_ACNAME	0x0102		/* access concentrator name */
#define PPPOE_TAG_HUNIQUE	0x0103		/* host unique */
#define PPPOE_TAG_ACCOOKIE	0x0104		/* AC cookie */
#define PPPOE_TAG_VENDOR	0x0105		/* vendor specific */
#define PPPOE_TAG_RELAYSID	0x0110		/* relay session id */
#define PPPOE_TAG_SNAME_ERR	0x0201		/* service name error */
#define PPPOE_TAG_ACSYS_ERR	0x0202		/* AC system error */
#define PPPOE_TAG_GENERIC_ERR	0x0203		/* gerneric error */

#define PPPOE_CODE_PADI		0x09		/* Active Discovery Initiation */
#define	PPPOE_CODE_PADO		0x07		/* Active Discovery Offer */
#define	PPPOE_CODE_PADR		0x19		/* Active Discovery Request */
#define	PPPOE_CODE_PADS		0x65		/* Active Discovery Session confirmation */
#define	PPPOE_CODE_PADT		0xA7		/* Active Discovery Terminate */

#define	PPPOE_MAXMTU	(ETHERMTU-PPPOE_HEADERLEN-2)
#ifndef ETHERMTU
#define ETHERMTU 1500
#endif

#define	PPPOE_ADD_16(PTR, VAL)			\
		*(PTR)++ = (VAL) / 256;		\
		*(PTR)++ = (VAL) % 256

#define PPPOE_ADD_HEADER(PTR, CODE, SESS, LEN)	\
		*(PTR)++ = PPPOE_VERTYPE;	\
		*(PTR)++ = (CODE);		\
		PPPOE_ADD_16(PTR, SESS);	\
		PPPOE_ADD_16(PTR, LEN)

#define PPPOE_READ_16(PTR) (((PTR)[0] << 8) | (PTR)[1])

#define	PPPOE_DISC_TIMEOUT	(hz*5)	/* base for quick timeout calculation */
#define PPPOE_DISC_MAXPADR	2	/* retry PADR twice */

#define PPPOESETSTATUS 0x80146971
#define PPPOEGETSTATUS 0x80146972
#define PPPOEGETSESSION 0xC0206970
#define PPPOEGETERROR 0xC1146974
#ifndef SIOCSIFFLAGS
#define SIOCSIFFLAGS 0x80206910
#endif
#ifndef SIOCSIFMTU
#define SIOCSIFMTU 0x8020697F
#endif

struct ether_addr {
	u_int8_t ether_addr_octet[6];
};

struct pppoe_softc {
	struct sppp sc_sppp;		/* contains a struct ifnet as first element */
	struct ifnet *sc_eth_if;	/* ethernet interface we are using */

	int sc_state;			/* discovery phase or session connected */
	struct ether_addr sc_dest;	/* hardware address of concentrator */
	u_int16_t sc_session;		/* PPPoE session id */

	char *sc_service_name;		/* if != NULL: requested name of service */
	char *sc_concentrator_name;	/* if != NULL: requested concentrator id */
	u_int8_t *sc_ac_cookie;		/* content of AC cookie we must echo back */
	size_t sc_ac_cookie_len;	/* length of cookie data */
	struct callout sc_timeout;	/* timeout while not in session state */
	int sc_padi_retried;		/* number of PADI retries already done */
	int sc_padr_retried;		/* number of PADR retries already done */
	int sc_status;
	int sc_error;
	char sc_errmsg[256];
	int sc_unk60C;
};

struct pppoeconnectionstate {
	char ifname[16];
	u_int state;
	u_int session_id;
	u_int padi_retry_no;
	u_int padr_retry_no;
};

struct pppoestatus {
	char ifname[16];
	int status;
};

struct pppoeerrmsg { char msg[256]; } __attribute__((aligned(4)));

struct pppoeerror {
	char ifname[16];
	int error;
	struct pppoeerrmsg msg;
};

extern struct ifqueue ppoediscinq;
extern struct ifqueue ppoeinq;
extern struct pppoe_softc pppoe_softc0;

void pppoe_softintr(void);
static void pppoe_disc_input(struct mbuf *);
static void pppoe_dispatch_disc_pkt(struct mbuf *, int);
static void pppoe_data_input(struct mbuf *);

static int pppoe_connect(struct pppoe_softc *);
static int pppoe_disconnect(struct pppoe_softc *);
static int pppoe_ioctl(struct ifnet *, unsigned long, caddr_t);
static void pppoe_tls(struct sppp *);
void pppoe_tlf(struct sppp *);
void pppoe_start(struct ifnet *);

static void pppoe_timeout(void *);

static int pppoe_send_padi(struct pppoe_softc *);
static int pppoe_send_padr(struct pppoe_softc *);
static int pppoe_send_padt(struct ifnet *, u_int, const u_int8_t *);

static int pppoe_output(struct pppoe_softc *, struct mbuf *);

static struct pppoe_softc * pppoe_find_softc_by_session(u_int, struct ifnet *);
static struct pppoe_softc * pppoe_find_softc_by_hunique(u_int8_t *, size_t, struct ifnet *);
static struct mbuf *pppoe_get_mbuf(size_t len);

#define IF_PURGE(ifq) do { \
	struct mbuf *__m0; \
	for (;;) { \
		IF_DEQUEUE((ifq), __m0); \
		if (__m0 == NULL) \
			break; \
		m_freem(__m0); \
	} \
} while (0)

void
pppoe_detach(void)
{
	struct pppoe_softc *sc = &pppoe_softc0;

	callout_stop(&sc->sc_timeout);
	IF_PURGE(&ppoediscinq);
	IF_PURGE(&ppoeinq);
	sppp_detach(&sc->sc_sppp.pp_if);
	if_detach(&sc->sc_sppp.pp_if);
	if (sc->sc_concentrator_name)
		free(sc->sc_concentrator_name, M_DEVBUF);
	if (sc->sc_service_name)
		free(sc->sc_service_name, M_DEVBUF);
	if (sc->sc_ac_cookie)
		free(sc->sc_ac_cookie, M_DEVBUF);
}

static struct pppoe_softc *
pppoe_find_softc_by_session(u_int session, struct ifnet *rcvif)
{
	struct pppoe_softc *sc = &pppoe_softc0;

	if (session == 0)
		return NULL;

	if (sc->sc_state == PPPOE_STATE_SESSION
	    && sc->sc_session == session) {
		if (sc->sc_eth_if == rcvif)
			return sc;
		else
			return NULL;
	}
	return NULL;
}

/* Check host unique token passed and return appropriate softc pointer,
 * or NULL if token is bogus. */
static struct pppoe_softc *
pppoe_find_softc_by_hunique(u_int8_t *token, size_t len, struct ifnet *rcvif)
{
	struct pppoe_softc *sc, *t;

	if (len != sizeof sc)
		return NULL;
	memcpy(&t, token, len);

	sc = &pppoe_softc0;
	if (sc != t)
		return NULL;

	/* should be safe to access *sc now */
	if (sc->sc_state < PPPOE_STATE_PADI_SENT || sc->sc_state >= PPPOE_STATE_SESSION)
		return NULL;
	if (sc->sc_eth_if != rcvif)
		return NULL;
	return sc;
}

/* called at appropriate protection level */
void
pppoe_softintr(void)
{
	struct mbuf *m;
	int s, disc_done, data_done;

	do {
		disc_done = 0;
		data_done = 0;
		for (;;) {
			s = splnet();
			IF_DEQUEUE(&ppoediscinq, m);
			splx(s);
			if (m == NULL) break;
			disc_done = 1;
			pppoe_disc_input(m);
		}

		for (;;) {
			s = splnet();
			IF_DEQUEUE(&ppoeinq, m);
			splx(s);
			if (m == NULL) break;
			data_done = 1;
			pppoe_data_input(m);
		}
	} while (disc_done || data_done);
}

static void
pppoe_disc_input(struct mbuf *m)
{
	pppoe_dispatch_disc_pkt(m, 0);
}

static void
pppoe_data_input(struct mbuf *m)
{
	u_int16_t session, plen;
	struct pppoe_softc *sc;
	u_int8_t *ph;
	u_int8_t vertype, code;

	m_adj(m, sizeof(struct ether_header));
	if (m->m_pkthdr.len <= PPPOE_HEADERLEN)
		goto drop;

	if (m->m_len < PPPOE_HEADERLEN) {
		m = m_pullup(m, PPPOE_HEADERLEN);
		if (!m)
			return;
	}
	ph = mtod(m, u_int8_t *);

	vertype = *ph++;
	if (vertype != PPPOE_VERTYPE)
		goto drop;
	code = *ph++;
	if (code != 0)
		goto drop;

	session = PPPOE_READ_16(ph);
	ph += 2;
	sc = pppoe_find_softc_by_session(session, m->m_pkthdr.rcvif);
	if (sc == NULL)
		goto drop;

	plen = PPPOE_READ_16(ph);

	m_adj(m, PPPOE_HEADERLEN);

	if (m->m_pkthdr.len < plen)
		goto drop;

	/* fix incoming interface pointer (not the raw ethernet interface anymore) */
	m->m_pkthdr.rcvif = &sc->sc_sppp.pp_if;

	/* pass packet up and account for it */
	sc->sc_sppp.pp_if.if_ipackets++;
	sppp_input(&sc->sc_sppp.pp_if, m);
	return;

drop:
	m_freem(m);
}

static int
pppoe_output(struct pppoe_softc *sc, struct mbuf *m)
{
	struct sockaddr dst;
	struct ether_header *eh;
	u_int16_t etype;

	if (sc->sc_eth_if == NULL) {
		m_freem(m);
		return EIO;
	}

	memset(&dst, 0, sizeof dst);
	dst.sa_family = AF_UNSPEC;
	eh = (struct ether_header*)&dst.sa_data;
	etype = sc->sc_state == PPPOE_STATE_SESSION ? ETHERTYPE_PPPOE : ETHERTYPE_PPPOEDISC;
	eh->ether_type = htons(etype);
	memcpy(&eh->ether_dhost, &sc->sc_dest, sizeof sc->sc_dest);

	m->m_flags &= ~(M_BCAST|M_MCAST);
	sc->sc_sppp.pp_if.if_opackets++;
	sc->sc_eth_if->if_output(sc->sc_eth_if, m, &dst, NULL);
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/if_pppoe", func_0002AC08);

/*
 * Allocate a mbuf/cluster with space to store the given data length
 * of payload, leaving space for prepending an ethernet header
 * in front.
 */
static void
pppoe_timeout(void *arg)
{
	int x;
	struct pppoe_softc *sc = (struct pppoe_softc*)arg;

	switch (sc->sc_state) {
	case PPPOE_STATE_PADI_SENT:
		x = splnet();
		sc->sc_padi_retried++;
		if (pppoe_send_padi(sc) != 0)
			sc->sc_padi_retried--;
		callout_reset(&sc->sc_timeout, PPPOE_DISC_TIMEOUT,
		    pppoe_timeout, sc);
		splx(x);
		break;

	case PPPOE_STATE_PADR_SENT:
		x = splnet();
		sc->sc_padr_retried++;
		if (sc->sc_padr_retried >= PPPOE_DISC_MAXPADR) {
			memset(&sc->sc_dest, 0xff, sizeof(sc->sc_dest));
			sc->sc_state = PPPOE_STATE_PADI_SENT;
			sc->sc_padr_retried = 0;
			pppoe_send_padi(sc);
			callout_reset(&sc->sc_timeout, PPPOE_DISC_TIMEOUT,
			    pppoe_timeout, sc);
			splx(x);
			return;
		}
		if (pppoe_send_padr(sc) != 0)
			sc->sc_padr_retried--;
		callout_reset(&sc->sc_timeout, PPPOE_DISC_TIMEOUT,
		    pppoe_timeout, sc);
		splx(x);
		break;
	case PPPOE_STATE_CLOSING:
		pppoe_disconnect(sc);
		break;
	default:
		return;	/* all done, work in peace */
	}
}

/* disconnect */
static int
pppoe_disconnect(struct pppoe_softc *sc)
{
	int err, x;

	x = splnet();

	if (sc->sc_state < PPPOE_STATE_SESSION)
		err = EBUSY;
	else
		err = pppoe_send_padt(sc->sc_eth_if, sc->sc_session, (const u_int8_t *)&sc->sc_dest);

	/* cleanup softc */
	sc->sc_state = PPPOE_STATE_INITIAL;
	memset(&sc->sc_dest, 0xff, sizeof(sc->sc_dest));
	if (sc->sc_ac_cookie) {
		free(sc->sc_ac_cookie, M_DEVBUF);
		sc->sc_ac_cookie = NULL;
	}
	sc->sc_ac_cookie_len = 0;
	sc->sc_session = 0;

	/* notify upper layer */
	sc->sc_sppp.pp_down(&sc->sc_sppp);

	splx(x);

	return err;
}

/* Send a PADR packet */
static int
pppoe_send_padr(struct pppoe_softc *sc)
{
	struct mbuf *m0;
	u_int8_t *p;
	size_t len, l1 = 0;

	if (sc->sc_state != PPPOE_STATE_PADR_SENT)
		return EIO;

	len = 2 + 2 + 2 + 2 + sizeof(sc);		/* service name, host unique */
	if (sc->sc_service_name != NULL) {		/* service name tag maybe empty */
		l1 = strlen(sc->sc_service_name);
		len += l1;
	}
	if (sc->sc_ac_cookie_len > 0)
		len += 2 + 2 + sc->sc_ac_cookie_len;	/* AC cookie */
	m0 = pppoe_get_mbuf(len + PPPOE_HEADERLEN);
	if (!m0)
		return ENOBUFS;
	p = mtod(m0, u_int8_t *);
	PPPOE_ADD_HEADER(p, PPPOE_CODE_PADR, 0, len);
	PPPOE_ADD_16(p, PPPOE_TAG_SNAME);
	if (sc->sc_service_name != NULL) {
		PPPOE_ADD_16(p, l1);
		memcpy(p, sc->sc_service_name, l1);
		p += l1;
	} else {
		PPPOE_ADD_16(p, 0);
	}
	if (sc->sc_ac_cookie_len > 0) {
		PPPOE_ADD_16(p, PPPOE_TAG_ACCOOKIE);
		PPPOE_ADD_16(p, sc->sc_ac_cookie_len);
		memcpy(p, sc->sc_ac_cookie, sc->sc_ac_cookie_len);
		p += sc->sc_ac_cookie_len;
	}
	PPPOE_ADD_16(p, PPPOE_TAG_HUNIQUE);
	PPPOE_ADD_16(p, sizeof(sc));
	memcpy(p, &sc, sizeof sc);

	return pppoe_output(sc, m0);
}

/* send a PADT packet */
static int
pppoe_send_padt(struct ifnet *outgoing_if, u_int session, const u_int8_t *dest)
{
	struct ether_header *eh;
	struct sockaddr dst;
	struct mbuf *m0;
	u_int8_t *p;

	m0 = pppoe_get_mbuf(PPPOE_HEADERLEN);
	if (!m0)
		return EIO;
	p = mtod(m0, u_int8_t *);
	PPPOE_ADD_HEADER(p, PPPOE_CODE_PADT, session, 0);

	memset(&dst, 0, sizeof dst);
	dst.sa_family = AF_UNSPEC;
	eh = (struct ether_header*)&dst.sa_data;
	eh->ether_type = htons(ETHERTYPE_PPPOEDISC);
	memcpy(&eh->ether_dhost, dest, ETHER_ADDR_LEN);

	m0->m_flags &= ~(M_BCAST|M_MCAST);
	return outgoing_if->if_output(outgoing_if, m0, &dst, NULL);
}

void
pppoe_start(struct ifnet *ifp)
{
	struct pppoe_softc *sc = (void *)ifp;
	struct mbuf *m;
	u_int8_t *p;
	size_t len;

	if (sppp_isempty(ifp))
		return;

	/* are we ready to proccess data yet? */
	if (sc->sc_state < PPPOE_STATE_SESSION) {
		sppp_flush(&sc->sc_sppp.pp_if);
		return;
	}

	while ((m = sppp_dequeue(ifp)) != NULL) {
		len = m->m_pkthdr.len;
		M_PREPEND(m, PPPOE_HEADERLEN, M_DONTWAIT);
		if (m == NULL) {
			ifp->if_oerrors++;
			continue;
		}
		p = mtod(m, u_int8_t *);
		PPPOE_ADD_HEADER(p, 0, sc->sc_session, len);

		pppoe_output(sc, m);
	}
}

void
pppoe_ether_input(struct mbuf *m, u_short etype, int *handled)
{
	struct ifqueue *inq;
	int s;

	switch (etype) {
	case ETHERTYPE_PPPOEDISC:
	case ETHERTYPE_PPPOE:
		if (etype == ETHERTYPE_PPPOEDISC)
			inq = &ppoediscinq;
		else
			inq = &ppoeinq;
		s = splnet();
		if (IF_QFULL(inq)) {
			IF_DROP(inq);
			m_freem(m);
		} else
			IF_ENQUEUE(inq, m);
		splx(s);
		schednetisr(NETISR_PPPOE);
		*handled = 1;
		break;
	}
}

__attribute__((noinline)) int
pppoe_attach(const char *ifname)
{
	struct pppoe_softc *sc = &pppoe_softc0;

	memset(&ppoediscinq, 0, sizeof(ppoediscinq));
	ppoediscinq.ifq_maxlen = IFQ_MAXLEN;
	memset(&ppoeinq, 0, sizeof(ppoeinq));
	ppoeinq.ifq_maxlen = IFQ_MAXLEN;
	memset(sc, 0, sizeof(struct pppoe_softc));

	sc->sc_eth_if = ifunit(ifname);
	if (sc->sc_eth_if == NULL)
		return -1;

	memcpy(sc->sc_sppp.pp_if.if_xname, "pppoe0", 6);
	sc->sc_sppp.pp_if.if_softc = sc;
	sc->sc_sppp.pp_if.if_mtu = PPPOE_MAXMTU;
	sc->sc_sppp.pp_if.if_flags = IFF_SIMPLEX|IFF_POINTOPOINT|IFF_MULTICAST;
	sc->sc_sppp.pp_if.if_type = IFT_PPP;
	sc->sc_sppp.pp_if.if_hdrlen = sizeof(struct ether_header) + PPPOE_HEADERLEN;
	sc->sc_sppp.pp_flags |= PP_KEEPALIVE |	/* use LCP keepalive */
				PP_NOFRAMING;	/* no serial encapsulation */
	sc->sc_sppp.pp_if.if_ioctl = pppoe_ioctl;
	sc->sc_sppp.pp_if.if_snd.ifq_maxlen = IFQ_MAXLEN;

	/* changed to real address later */
	memset(&sc->sc_dest, 0xff, sizeof(sc->sc_dest));

	callout_init(&sc->sc_timeout);

	sc->sc_sppp.pp_if.if_start = pppoe_start;
	sc->sc_sppp.pp_tls = pppoe_tls;
	sc->sc_sppp.pp_tlf = pppoe_tlf;
	sc->sc_sppp.pp_framebytes = PPPOE_HEADERLEN;	/* framing added to ppp packets */

	if_attach(&sc->sc_sppp.pp_if);
	sppp_attach(&sc->sc_sppp.pp_if);
	return 0;
}

/* analyze and handle a single received packet while not in session state */
INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/if_pppoe", func_0002B79C);

/* Start a connection (i.e. initiate discovery phase) */
static int
pppoe_connect(struct pppoe_softc *sc)
{
	int x;

	if (sc->sc_state != PPPOE_STATE_INITIAL)
		return EBUSY;

	x = splnet();
	sc->sc_state = PPPOE_STATE_PADI_SENT;
	if (sc->sc_status <= 0)
		sc->sc_status = 1;
	sc->sc_padr_retried = 0;
	pppoe_send_padi(sc);
	callout_reset(&sc->sc_timeout, PPPOE_DISC_TIMEOUT, pppoe_timeout, sc);
	splx(x);
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/if_pppoe", func_0002BD24);

__attribute__((noinline)) void
pppoe_tlf(struct sppp *sp)
{
	struct pppoe_softc *sc = (void *)sp;
	if (sc->sc_state < PPPOE_STATE_SESSION)
		return;
	/*
	 * Do not call pppoe_disconnect here, the upper layer state
	 * machine gets confused by this. We must return from this
	 * function and defer disconnecting to the timeout handler.
	 */
	sc->sc_state = PPPOE_STATE_CLOSING;
	callout_reset(&sc->sc_timeout, hz/50, pppoe_timeout, sc);
}

static int
pppoe_send_padi(struct pppoe_softc *sc)
{
	struct mbuf *m0;
	int len, l1 = 0, l2 = 0;
	u_int8_t *p;

	if (sc->sc_state > PPPOE_STATE_PADI_SENT)
		return 0;

	/* calculate length of frame (excluding ethernet header + pppoe header) */
	len = 2 + 2 + 2 + 2 + sizeof sc;	/* service name tag is required, host unique is send too */
	if (sc->sc_service_name != NULL) {
		l1 = strlen(sc->sc_service_name);
		len += l1;
	}
	if (sc->sc_concentrator_name != NULL) {
		l2 = strlen(sc->sc_concentrator_name);
		len += 2 + 2 + l2;
	}

	/* allocate a buffer */
	m0 = pppoe_get_mbuf(len + PPPOE_HEADERLEN);	/* header len + payload len */
	if (!m0)
		return ENOBUFS;

	/* fill in pkt */
	p = mtod(m0, u_int8_t *);
	PPPOE_ADD_HEADER(p, PPPOE_CODE_PADI, 0, len);
	PPPOE_ADD_16(p, PPPOE_TAG_SNAME);
	if (sc->sc_service_name != NULL) {
		PPPOE_ADD_16(p, l1);
		memcpy(p, sc->sc_service_name, l1);
		p += l1;
	} else {
		PPPOE_ADD_16(p, 0);
	}
	if (sc->sc_concentrator_name != NULL) {
		PPPOE_ADD_16(p, PPPOE_TAG_ACNAME);
		PPPOE_ADD_16(p, l2);
		memcpy(p, sc->sc_concentrator_name, l2);
		p += l2;
	}
	PPPOE_ADD_16(p, PPPOE_TAG_HUNIQUE);
	PPPOE_ADD_16(p, sizeof(sc));
	memcpy(p, &sc, sizeof sc);

	/* send pkt */
	return pppoe_output(sc, m0);
}

static struct mbuf *
pppoe_get_mbuf(size_t len)
{
	struct mbuf *m;

	MGETHDR(m, M_DONTWAIT, MT_DATA);
	if (m == NULL)
		return NULL;
	if (len + sizeof(struct ether_header) > MHLEN) {
		MCLGET(m, M_DONTWAIT);
		if ((m->m_flags & M_EXT) == 0) {
			struct mbuf *n;
			MFREE(m, n);
			return 0;
		}
	}
	m->m_data += sizeof(struct ether_header);
	m->m_len = len;
	m->m_pkthdr.len = len;
	m->m_pkthdr.rcvif = NULL;

	return m;
}

