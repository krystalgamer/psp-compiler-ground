/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

struct socket *
getsock(int fd)
{
	struct socket *so;
	int s;

	if (fd <= 0 || fd > 255)
		return NULL;
	s = _sce_pspnet_spllock();
	for (so = socklist.tqh_first; so; so = so->so_list.tqe_next)
		if (so->so_fd == fd)
			break;
	_sce_pspnet_splunlock(s);
	return so;
}

void
soisconnecting(struct socket *so)
{
	so->so_state &= ~(SS_ISCONNECTED|SS_ISDISCONNECTING);
	so->so_state |= SS_ISCONNECTING;
}

void
soisconnected(struct socket *so)
{
	struct socket *head = so->so_head;

	so->so_state &= ~(SS_ISCONNECTING|SS_ISDISCONNECTING|SS_ISCONFIRMING);
	so->so_state |= SS_ISCONNECTED;
	if (head && soqremque(so, 0)) {
		soqinsque(head, so, 1);
		sorwakeup(head);
		wakeup((caddr_t)&head->so_timeo);
	} else {
		wakeup((caddr_t)&so->so_timeo);
		sorwakeup(so);
		sowwakeup(so);
	}
}

void
soisdisconnecting(struct socket *so)
{
	so->so_state &= ~SS_ISCONNECTING;
	so->so_state |= (SS_ISDISCONNECTING|SS_CANTRCVMORE|SS_CANTSENDMORE);
	wakeup((caddr_t)&so->so_timeo);
	sowwakeup(so);
	sorwakeup(so);
}

void
soisdisconnected(struct socket *so)
{
	so->so_state &= ~(SS_ISCONNECTING|SS_ISCONNECTED|SS_ISDISCONNECTING);
	so->so_state |= (SS_CANTRCVMORE|SS_CANTSENDMORE|SS_ISDISCONNECTED);
	wakeup((caddr_t)&so->so_timeo);
	sowwakeup(so);
	sorwakeup(so);
}

struct socket *
sonewconn(struct socket *head, int connstatus)
{
	struct socket *so;
	int soqueue = connstatus ? 1 : 0;

	if (head->so_qlen + head->so_q0len > 3 * head->so_qlimit / 2)
		return ((struct socket *)0);
	so = sceNetMallocInternal(sizeof(*so));
	if (so == NULL)
		return ((struct socket *)0);
	memset((caddr_t)so, 0, sizeof(*so));
	so->so_type = head->so_type;
	so->so_options = head->so_options &~ SO_ACCEPTCONN;
	so->so_linger = head->so_linger;
	so->so_state = head->so_state | SS_NOFDREF;
	so->so_proto = head->so_proto;
	so->so_timeo = head->so_timeo;
	so->so_send = head->so_send;
	so->so_receive = head->so_receive;
	so->so_fd = -1;
	(void) soreserve(so, head->so_snd.sb_hiwat, head->so_rcv.sb_hiwat);
	soqinsque(head, so, soqueue);
	if ((*so->so_proto->pr_usrreq)(so, PRU_ATTACH,
	    (struct mbuf *)0, (struct mbuf *)0, (struct mbuf *)0)) {
		(void) soqremque(so, soqueue);
		sceNetFreeInternal(so);
		return ((struct socket *)0);
	}
	if (connstatus) {
		sorwakeup(head);
		wakeup((caddr_t)&head->so_timeo);
		so->so_state |= connstatus;
	}
	TAILQ_INSERT_TAIL(&socklist, so, so_list);
	return (so);
}

void
soqinsque(struct socket *head, struct socket *so, int q)
{
	so->so_head = head;
	if (q == 0) {
		head->so_q0len++;
		so->so_onq = &head->so_q0;
	} else {
		head->so_qlen++;
		so->so_onq = &head->so_q;
	}
	TAILQ_INSERT_TAIL(so->so_onq, so, so_qe);
}

int
soqremque(struct socket *so, int q)
{
	struct socket *head = so->so_head;

	if (q == 0) {
		if (so->so_onq != &head->so_q0)
			return (0);
		head->so_q0len--;
	} else {
		if (so->so_onq != &head->so_q)
			return (0);
		head->so_qlen--;
	}
	TAILQ_REMOVE(so->so_onq, so, so_qe);
	so->so_onq = NULL;
	so->so_head = NULL;
	return (1);
}

void
socantsendmore(struct socket *so)
{
	so->so_state |= SS_CANTSENDMORE;
	sowwakeup(so);
}

void
socantrcvmore(struct socket *so)
{
	so->so_state |= SS_CANTRCVMORE;
	sorwakeup(so);
}

int
sbwait(struct sockbuf *sb)
{
	sb->sb_flags |= SB_WAIT;
	return (tsleep((caddr_t)&sb->sb_cc, sb->sb_timeo));
}

int
sb_lock(struct sockbuf *sb)
{
	int error;

	while (sb->sb_flags & SB_LOCK) {
		sb->sb_flags |= SB_WANT;
		error = tsleep((caddr_t)&sb->sb_flags, 0);
		if (error)
			return (error);
	}
	sb->sb_flags |= SB_LOCK;
	return (0);
}

void
sowakeup(struct socket *so, struct sockbuf *sb)
{
	selwakeup(&sb->sb_sel);
	sb->sb_flags &= ~SB_SEL;
	if (sb->sb_flags & SB_WAIT) {
		sb->sb_flags &= ~SB_WAIT;
		wakeup((caddr_t)&sb->sb_cc);
	}
	if (sb->sb_flags & SB_UPCALL)
		(*so->so_upcall)(so, so->so_upcallarg, M_DONTWAIT);
}

int
soreserve(struct socket *so, u_long sndcc, u_long rcvcc)
{
	if (sbreserve(&so->so_snd, sndcc) == 0)
		goto bad;
	if (sbreserve(&so->so_rcv, rcvcc) == 0)
		goto bad2;
	if (so->so_rcv.sb_lowat == 0)
		so->so_rcv.sb_lowat = 1;
	if (so->so_snd.sb_lowat == 0)
		so->so_snd.sb_lowat = MCLBYTES;
	if (so->so_snd.sb_lowat > so->so_snd.sb_hiwat)
		so->so_snd.sb_lowat = so->so_snd.sb_hiwat;
	return (0);
bad2:
	sbrelease(&so->so_snd);
bad:
	return (ENOBUFS);
}

int
sbreserve(struct sockbuf *sb, u_long cc)
{
	if (cc == 0 || cc > SB_MAX * MCLBYTES / (MSIZE + MCLBYTES))
		return (0);
	sb->sb_hiwat = cc;
	sb->sb_mbmax = min(cc * 2, SB_MAX);
	if (sb->sb_lowat > sb->sb_hiwat)
		sb->sb_lowat = sb->sb_hiwat;
	return (1);
}

void
sbrelease(struct sockbuf *sb)
{
	sbflush(sb);
	sb->sb_hiwat = sb->sb_mbmax = 0;
}

void
sbappend(struct sockbuf *sb, struct mbuf *m)
{
	struct mbuf *n;

	if (m == 0)
		return;
	if ((n = sb->sb_mb) != NULL) {
		while (n->m_nextpkt)
			n = n->m_nextpkt;
		do {
			if (n->m_flags & M_EOR) {
				sbappendrecord(sb, m);
				return;
			}
		} while (n->m_next && (n = n->m_next));
	}
	sbcompress(sb, m, n);
}

void
sbappendrecord(struct sockbuf *sb, struct mbuf *m0)
{
	struct mbuf *m;

	if (m0 == 0)
		return;
	m = sb->sb_mb;
	if (m)
		while (m->m_nextpkt)
			m = m->m_nextpkt;
	sballoc(sb, m0);
	if (m)
		m->m_nextpkt = m0;
	else
		sb->sb_mb = m0;
	m = m0->m_next;
	m0->m_next = 0;
	if (m && (m0->m_flags & M_EOR)) {
		m0->m_flags &= ~M_EOR;
		m->m_flags |= M_EOR;
	}
	sbcompress(sb, m, m0);
}

void
sbinsertoob(struct sockbuf *sb, struct mbuf *m0)
{
	struct mbuf *m;
	struct mbuf **mp;

	if (m0 == 0)
		return;
	for (mp = &sb->sb_mb; (m = *mp) != NULL; mp = &(*mp)->m_nextpkt) {
	    again:
		switch (m->m_type) {

		case MT_OOBDATA:
			continue;

		case MT_CONTROL:
			if ((m = m->m_next) != NULL)
				goto again;
		}
		break;
	}
	sballoc(sb, m0);
	m0->m_nextpkt = *mp;
	*mp = m0;
	m = m0->m_next;
	m0->m_next = 0;
	if (m && (m0->m_flags & M_EOR)) {
		m0->m_flags &= ~M_EOR;
		m->m_flags |= M_EOR;
	}
	sbcompress(sb, m, m0);
}

int
sbappendaddr(struct sockbuf *sb, struct sockaddr *asa, struct mbuf *m0, struct mbuf *control)
{
	struct mbuf *m, *n;
	int space = asa->sa_len;

	if (m0)
		space += m0->m_pkthdr.len;
	for (n = control; n; n = n->m_next) {
		space += n->m_len;
		if (n->m_next == 0)
			break;
	}
	if (space > sbspace(sb))
		return (0);
	MGET(m, M_DONTWAIT, MT_SONAME);
	if (m == 0)
		return (0);
	if (asa->sa_len > MLEN) {
		MEXTMALLOC(m, asa->sa_len, M_NOWAIT);
		if ((m->m_flags & M_EXT) == 0) {
			m_free(m);
			return (0);
		}
	}
	m->m_len = asa->sa_len;
	memcpy(mtod(m, caddr_t), (caddr_t)asa, asa->sa_len);
	if (n)
		n->m_next = m0;
	else
		control = m0;
	m->m_next = control;
	for (n = m; n; n = n->m_next)
		sballoc(sb, n);
	if ((n = sb->sb_mb) != NULL) {
		while (n->m_nextpkt)
			n = n->m_nextpkt;
		n->m_nextpkt = m;
	} else
		sb->sb_mb = m;
	return (1);
}

int
sbappendcontrol(struct sockbuf *sb, struct mbuf *m0, struct mbuf *control)
{
	struct mbuf *m, *n;
	int space = 0;

	for (m = control; ; m = m->m_next) {
		space += m->m_len;
		if (m->m_next == 0)
			break;
	}
	n = m;
	for (m = m0; m; m = m->m_next)
		space += m->m_len;
	if (space > sbspace(sb))
		return (0);
	n->m_next = m0;
	for (m = control; m; m = m->m_next)
		sballoc(sb, m);
	if ((n = sb->sb_mb) != NULL) {
		while (n->m_nextpkt)
			n = n->m_nextpkt;
		n->m_nextpkt = control;
	} else
		sb->sb_mb = control;
	return (1);
}

void sbcompress(struct sockbuf *sb, struct mbuf *m, struct mbuf *n)
{
	int eor = 0;
	struct mbuf *o;

	while (m) {
		eor |= m->m_flags & M_EOR;
		if (m->m_len == 0 &&
		    (eor == 0 ||
		     (((o = m->m_next) || (o = n)) &&
		      o->m_type == m->m_type))) {
			m = m_free(m);
			continue;
		}
		if (n && (n->m_flags & M_EOR) == 0 && n->m_type == m->m_type &&
		    (((n->m_flags & M_EXT) == 0 &&
		      n->m_data + n->m_len + m->m_len <= &n->m_dat[MLEN]) ||
		     ((~n->m_flags & (M_EXT | M_CLUSTER)) == 0 &&
		      n->m_ext.ext_nextref == n &&
		      n->m_data + n->m_len + m->m_len <= n->m_ext.ext_buf + MCLBYTES))) {
			memcpy(mtod(n, caddr_t) + n->m_len, mtod(m, caddr_t),
			    (unsigned)m->m_len);
			n->m_len += m->m_len;
			sb->sb_cc += m->m_len;
			m = m_free(m);
			continue;
		}
		if (n)
			n->m_next = m;
		else
			sb->sb_mb = m;
		sballoc(sb, m);
		n = m;
		m->m_flags &= ~M_EOR;
		m = m->m_next;
		n->m_next = 0;
	}
	if (eor) {
		if (n)
			n->m_flags |= eor;
	}
}

void
sbflush(struct sockbuf *sb)
{
	while (sb->sb_mbcnt)
		sbdrop(sb, (int)sb->sb_cc);
}

void
sbdrop(struct sockbuf *sb, int len)
{
	struct mbuf *m, *mn;
	struct mbuf *next;

	next = (m = sb->sb_mb) ? m->m_nextpkt : 0;
	while (len > 0) {
		if (m == 0) {
			m = next;
			next = m->m_nextpkt;
			continue;
		}
		if (m->m_len > len) {
			m->m_len -= len;
			m->m_data += len;
			sb->sb_cc -= len;
			break;
		}
		len -= m->m_len;
		sbfree(sb, m);
		MFREE(m, mn);
		m = mn;
	}
	while (m && m->m_len == 0) {
		sbfree(sb, m);
		MFREE(m, mn);
		m = mn;
	}
	if (m) {
		sb->sb_mb = m;
		m->m_nextpkt = next;
	} else
		sb->sb_mb = next;
}

void
sbdroprecord(struct sockbuf *sb)
{
	struct mbuf *m, *mn;

	m = sb->sb_mb;
	if (m) {
		sb->sb_mb = m->m_nextpkt;
		do {
			sbfree(sb, m);
			MFREE(m, mn);
		} while ((m = mn) != NULL);
	}
}

struct mbuf *
sbcreatecontrol(caddr_t p, int size, int type, int level)
{
	struct cmsghdr *cp;
	struct mbuf *m;

	if (CMSG_SPACE(size) > MCLBYTES)
		return NULL;
	if ((m = m_get(M_DONTWAIT, MT_CONTROL)) == NULL)
		return ((struct mbuf *) NULL);
	if (CMSG_SPACE(size) > MLEN) {
		MCLGET(m, M_DONTWAIT);
		if ((m->m_flags & M_EXT) == 0) {
			m_free(m);
			return NULL;
		}
	}
	cp = mtod(m, struct cmsghdr *);
	memcpy(CMSG_DATA(cp), p, size);
	m->m_len = CMSG_SPACE(size);
	cp->cmsg_len = CMSG_LEN(size);
	cp->cmsg_level = level;
	cp->cmsg_type = type;
	return (m);
}

int
sofdalloc(void)
{
	int fd;

	for (fd = (lastfd == 255) ? 1 : lastfd + 1; fd != lastfd; fd = (fd == 255) ? 1 : fd + 1) {
		if (getsock(fd) == NULL) {
			lastfd = fd;
			return fd;
		}
	}
	return -1;
}
