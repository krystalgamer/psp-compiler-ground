/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

void
soinit(void)
{
	somaxconn = 128;
	lastfd = 0;
	TAILQ_INIT(&socklist);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/uipc_socket", func_000023C4);

int
sobind(struct socket *so, struct mbuf *nam)
{
	int s = _sce_pspnet_spllock();
	int error;

	error = (*so->so_proto->pr_usrreq)(so, PRU_BIND, (struct mbuf *)0,
	    nam, (struct mbuf *)0);
	_sce_pspnet_splunlock(s);
	return (error);
}

int
solisten(struct socket *so, int backlog)
{
	int s = _sce_pspnet_spllock(), error;

	error = (*so->so_proto->pr_usrreq)(so, PRU_LISTEN, (struct mbuf *)0,
	    (struct mbuf *)0, (struct mbuf *)0);
	if (error) {
		_sce_pspnet_splunlock(s);
		return (error);
	}
	if (so->so_q.tqh_first == NULL)
		so->so_options |= SO_ACCEPTCONN;
	if (backlog < 0)
		backlog = 0;
	so->so_qlimit = min(backlog, somaxconn);
	_sce_pspnet_splunlock(s);
	return (0);
}

void
sofree(struct socket *so)
{
	if (so->so_pcb || (so->so_state & SS_NOFDREF) == 0)
		return;
	if (so->so_head) {
		if (!soqremque(so, 0))
			return;
	}
	sbrelease(&so->so_snd);
	sorflush(so);
	TAILQ_REMOVE(&socklist, so, so_list);
	sceNetFreeInternal(so);
}

int
soclose(struct socket *so)
{
	struct socket *so2;
	int s = _sce_pspnet_spllock();
	int error = 0;

	if (so->so_options & SO_ACCEPTCONN) {
		while ((so2 = so->so_q0.tqh_first) != 0) {
			(void) soqremque(so2, 0);
			(void) soabort(so2);
		}
		while ((so2 = so->so_q.tqh_first) != 0) {
			(void) soqremque(so2, 1);
			(void) soabort(so2);
		}
	}
	if (so->so_pcb == 0)
		goto discard;
	if (so->so_state & SS_ISCONNECTED) {
		if ((so->so_state & SS_ISDISCONNECTING) == 0) {
			error = sodisconnect(so);
			if (error)
				goto drop;
		}
		if (so->so_options & SO_LINGER) {
			if ((so->so_state & SS_ISDISCONNECTING) &&
			    (so->so_state & SS_NBIO))
				goto drop;
			while (so->so_state & SS_ISCONNECTED) {
				error = tsleep((caddr_t)&so->so_timeo,
				    so->so_linger);
				if (error)
					break;
			}
		}
	}
drop:
	if (so->so_pcb) {
		int error2 = (*so->so_proto->pr_usrreq)(so, PRU_DETACH,
		    (struct mbuf *)0, (struct mbuf *)0, (struct mbuf *)0);
		if (error == 0)
			error = error2;
	}
discard:
	so->so_fd = -1;
	so->so_state |= SS_NOFDREF;
	sofree(so);
	_sce_pspnet_splunlock(s);
	return (error);
}

int
soabort(struct socket *so)
{
	return (*so->so_proto->pr_usrreq)(so, PRU_ABORT, (struct mbuf *)0,
	    (struct mbuf *)0, (struct mbuf *)0);
}

int
soaccept(struct socket *so, struct mbuf *nam)
{
	int s = _sce_pspnet_spllock();
	int error;

	so->so_state &= ~SS_NOFDREF;
	if ((so->so_state & SS_ISDISCONNECTED) == 0)
		error = (*so->so_proto->pr_usrreq)(so, PRU_ACCEPT,
		    (struct mbuf *)0, nam, (struct mbuf *)0);
	else
		error = ECONNABORTED;
	_sce_pspnet_splunlock(s);
	return (error);
}

int
soconnect(struct socket *so, struct mbuf *nam)
{
	int s;
	int error;

	if (so->so_options & SO_ACCEPTCONN)
		return (EOPNOTSUPP);
	s = _sce_pspnet_spllock();
	if (so->so_state & (SS_ISCONNECTED|SS_ISCONNECTING) &&
	    ((so->so_proto->pr_flags & PR_CONNREQUIRED) ||
	    (error = sodisconnect(so))))
		error = EISCONN;
	else
		error = (*so->so_proto->pr_usrreq)(so, PRU_CONNECT,
		    (struct mbuf *)0, nam, (struct mbuf *)0);
	_sce_pspnet_splunlock(s);
	return (error);
}

int
soconnect2(struct socket *so1, struct socket *so2)
{
	int s = _sce_pspnet_spllock();
	int error;

	error = (*so1->so_proto->pr_usrreq)(so1, PRU_CONNECT2,
	    (struct mbuf *)0, (struct mbuf *)so2, (struct mbuf *)0);
	_sce_pspnet_splunlock(s);
	return (error);
}

int
sodisconnect(struct socket *so)
{
	int s = _sce_pspnet_spllock();
	int error;

	if ((so->so_state & SS_ISCONNECTED) == 0) {
		error = ENOTCONN;
		goto bad;
	}
	if (so->so_state & SS_ISDISCONNECTING) {
		error = EALREADY;
		goto bad;
	}
	error = (*so->so_proto->pr_usrreq)(so, PRU_DISCONNECT,
	    (struct mbuf *)0, (struct mbuf *)0, (struct mbuf *)0);
bad:
	_sce_pspnet_splunlock(s);
	return (error);
}

#define	snderr(errno)	{ error = errno; _sce_pspnet_splunlock(s); goto release; }

int
sosend(struct socket *so, struct mbuf *addr, struct uio *uio, struct mbuf *top, struct mbuf *control, int flags)
{
	struct mbuf **mp;
	struct mbuf *m;
	long space, len, resid;
	int clen = 0, error, s, dontroute, mlen;
	int atomic = sosendallatonce(so) || top;
	int max_hdr;

	if (uio)
		resid = uio->uio_resid;
	else
		resid = top->m_pkthdr.len;
	if (resid < 0) {
		error = EINVAL;
		goto out;
	}
	dontroute =
	    (flags & MSG_DONTROUTE) && (so->so_options & SO_DONTROUTE) == 0 &&
	    (so->so_proto->pr_flags & PR_ATOMIC);
	if (control)
		clen = control->m_len;
restart:
	if ((error = sblock(&so->so_snd, SBLOCKWAIT(flags))) != 0)
		goto out;
	do {
		s = _sce_pspnet_spllock();
		if (so->so_state & SS_CANTSENDMORE)
			snderr(EPIPE);
		if (so->so_error) {
			error = so->so_error;
			so->so_error = 0;
			_sce_pspnet_splunlock(s);
			goto release;
		}
		if ((so->so_state & SS_ISCONNECTED) == 0) {
			if (so->so_proto->pr_flags & PR_CONNREQUIRED) {
				if ((so->so_state & SS_ISCONFIRMING) == 0 &&
				    !(resid == 0 && clen != 0))
					snderr(ENOTCONN);
			} else if (addr == 0)
				snderr(EDESTADDRREQ);
		}
		space = sbspace(&so->so_snd);
		if (flags & MSG_OOB)
			space += 1024;
		if ((atomic && resid > so->so_snd.sb_hiwat) ||
		    clen > so->so_snd.sb_hiwat)
			snderr(EMSGSIZE);
		if (space < resid + clen && uio &&
		    (atomic || space < so->so_snd.sb_lowat || space < clen)) {
			if (so->so_state & SS_NBIO)
				snderr(EWOULDBLOCK);
			sbunlock(&so->so_snd);
			error = sbwait(&so->so_snd);
			_sce_pspnet_splunlock(s);
			if (error)
				goto out;
			goto restart;
		}
		_sce_pspnet_splunlock(s);
		mp = &top;
		space -= clen;
		do {
		    if (uio == NULL) {
			resid = 0;
			if (flags & MSG_EOR)
				top->m_flags |= M_EOR;
		    } else do {
			if (top == 0) {
				MGETHDR(m, M_WAIT, MT_DATA);
				if (m == NULL) {
					error = ENOBUFS;
					goto release;
				}
				mlen = MHLEN;
				m->m_pkthdr.len = 0;
				m->m_pkthdr.rcvif = (struct ifnet *)0;
			} else {
				MGET(m, M_WAIT, MT_DATA);
				if (m == NULL) {
					error = ENOBUFS;
					goto release;
				}
				mlen = MLEN;
			}
			if (resid >= MINCLSIZE && space >= MCLBYTES) {
				MCLGET(m, M_WAIT);
				if ((m->m_flags & M_EXT) == 0)
					goto nopages;
				mlen = MCLBYTES;
				if (atomic && top == 0) {
					sceNetIfhandle_lib_5FB31C72(NULL, NULL, &max_hdr, NULL);
					len = min(MCLBYTES - max_hdr, resid);
					m->m_data += max_hdr;
				} else
					len = min(MCLBYTES, resid);
				space -= len;
			} else {
nopages:
				len = min(min(mlen, resid), space);
				space -= len;
				if (atomic && top == 0 && len < mlen)
					MH_ALIGN(m, len);
			}
			error = uiomove(mtod(m, caddr_t), (int)len, uio);
			resid = uio->uio_resid;
			m->m_len = len;
			*mp = m;
			top->m_pkthdr.len += len;
			if (error)
				goto release;
			mp = &m->m_next;
			if (resid <= 0) {
				if (flags & MSG_EOR)
					top->m_flags |= M_EOR;
				break;
			}
		    } while (space > 0 && atomic);
		    s = _sce_pspnet_spllock();
		    if (so->so_state & SS_CANTSENDMORE)
			snderr(EPIPE);
		    if (dontroute)
			    so->so_options |= SO_DONTROUTE;
		    if (resid > 0)
			    so->so_state |= SS_MORETOCOME;
		    error = (*so->so_proto->pr_usrreq)(so,
			(flags & MSG_OOB) ? PRU_SENDOOB : PRU_SEND,
			top, addr, control);
		    if (dontroute)
			    so->so_options &= ~SO_DONTROUTE;
		    if (resid > 0)
			    so->so_state &= ~SS_MORETOCOME;
		    _sce_pspnet_splunlock(s);
		    clen = 0;
		    control = 0;
		    top = 0;
		    mp = &top;
		    if (error)
			goto release;
		} while (resid && space > 0);
	} while (resid);

release:
	sbunlock(&so->so_snd);
out:
	if (top)
		m_freem(top);
	if (control)
		m_freem(control);
	return (error);
}

int
soreceive(struct socket *so, struct mbuf **paddr, struct uio *uio, struct mbuf **mp0, struct mbuf **controlp, int *flagsp)
{
	struct mbuf *m, **mp;
	int flags, len, error, s, offset;
	struct protosw *pr = so->so_proto;
	struct mbuf *nextrecord;
	int moff, type = 0;
	int orig_resid = uio->uio_resid;
	int freed = 0;

	mp = mp0;
	if (paddr)
		*paddr = 0;
	if (controlp)
		*controlp = 0;
	if (flagsp)
		flags = *flagsp &~ MSG_EOR;
	else
		flags = 0;
	if (flags & MSG_OOB) {
		m = m_get(M_WAIT, MT_DATA);
		if (m == NULL)
			return (ENOBUFS);
		error = (*pr->pr_usrreq)(so, PRU_RCVOOB, m,
		    (struct mbuf *)(long)(flags & MSG_PEEK), (struct mbuf *)0);
		if (error)
			goto bad;
		do {
			error = uiomove(mtod(m, caddr_t),
			    (int) min(uio->uio_resid, m->m_len), uio);
			m = m_free(m);
		} while (uio->uio_resid && error == 0 && m);
bad:
		if (m)
			m_freem(m);
		return (error);
	}
	if (mp)
		*mp = (struct mbuf *)0;
	if (so->so_state & SS_ISCONFIRMING && uio->uio_resid)
		(*pr->pr_usrreq)(so, PRU_RCVD, (struct mbuf *)0,
		    (struct mbuf *)0, (struct mbuf *)0);

restart:
	if ((error = sblock(&so->so_rcv, SBLOCKWAIT(flags))) != 0)
		return (error);
	s = _sce_pspnet_spllock();

	m = so->so_rcv.sb_mb;
	if (m == 0 || (((flags & MSG_DONTWAIT) == 0 &&
	    so->so_rcv.sb_cc < uio->uio_resid) &&
	    (so->so_rcv.sb_cc < so->so_rcv.sb_lowat ||
	    ((flags & MSG_WAITALL) && uio->uio_resid <= so->so_rcv.sb_hiwat)) &&
	    m->m_nextpkt == 0 && (pr->pr_flags & PR_ATOMIC) == 0)) {
		if (so->so_error) {
			if (m)
				goto dontblock;
			error = so->so_error;
			if ((flags & MSG_PEEK) == 0)
				so->so_error = 0;
			goto release;
		}
		if (so->so_state & SS_CANTRCVMORE) {
			if (m)
				goto dontblock;
			else
				goto release;
		}
		for (; m; m = m->m_next)
			if (m->m_type == MT_OOBDATA  || (m->m_flags & M_EOR)) {
				m = so->so_rcv.sb_mb;
				goto dontblock;
			}
		if ((so->so_state & (SS_ISCONNECTED|SS_ISCONNECTING)) == 0 &&
		    (so->so_proto->pr_flags & PR_CONNREQUIRED)) {
			error = ENOTCONN;
			goto release;
		}
		if (uio->uio_resid == 0)
			goto release;
		if ((so->so_state & SS_NBIO) || (flags & MSG_DONTWAIT)) {
			error = EWOULDBLOCK;
			goto release;
		}
		sbunlock(&so->so_rcv);
		error = sbwait(&so->so_rcv);
		_sce_pspnet_splunlock(s);
		if (error)
			return (error);
		goto restart;
	}
dontblock:
	nextrecord = m->m_nextpkt;
	if (pr->pr_flags & PR_ADDR) {
		orig_resid = 0;
		if (flags & MSG_PEEK) {
			if (paddr)
				*paddr = m_copy(m, 0, m->m_len);
			m = m->m_next;
		} else {
			sbfree(&so->so_rcv, m);
			freed = 1;
			if (paddr) {
				*paddr = m;
				so->so_rcv.sb_mb = m->m_next;
				m->m_next = 0;
				m = so->so_rcv.sb_mb;
			} else {
				MFREE(m, so->so_rcv.sb_mb);
				m = so->so_rcv.sb_mb;
			}
		}
	}
	while (m && m->m_type == MT_CONTROL && error == 0) {
		if (flags & MSG_PEEK) {
			if (controlp)
				*controlp = m_copy(m, 0, m->m_len);
			m = m->m_next;
		} else {
			sbfree(&so->so_rcv, m);
			freed = 1;
			if (controlp) {
				if (pr->pr_domain->dom_externalize &&
				    mtod(m, struct cmsghdr *)->cmsg_type ==
				    SCM_RIGHTS)
					error = (*pr->pr_domain->dom_externalize)(m);
				*controlp = m;
				so->so_rcv.sb_mb = m->m_next;
				m->m_next = 0;
				m = so->so_rcv.sb_mb;
			} else {
				MFREE(m, so->so_rcv.sb_mb);
				m = so->so_rcv.sb_mb;
			}
		}
		if (controlp) {
			orig_resid = 0;
			controlp = &(*controlp)->m_next;
		}
	}
	if (m) {
		if ((flags & MSG_PEEK) == 0)
			m->m_nextpkt = nextrecord;
		type = m->m_type;
		if (type == MT_OOBDATA)
			flags |= MSG_OOB;
	}
	moff = 0;
	offset = 0;
	while (m && uio->uio_resid > 0 && error == 0) {
		if (m->m_type == MT_OOBDATA) {
			if (type != MT_OOBDATA)
				break;
		} else if (type == MT_OOBDATA)
			break;
		so->so_state &= ~SS_RCVATMARK;
		len = uio->uio_resid;
		if (so->so_oobmark && len > so->so_oobmark - offset)
			len = so->so_oobmark - offset;
		if (len > m->m_len - moff)
			len = m->m_len - moff;
		if (mp == 0) {
			_sce_pspnet_splunlock(s);
			error = uiomove(mtod(m, caddr_t) + moff, (int)len, uio);
			s = _sce_pspnet_spllock();
			if (error) {
				if (m && freed && (pr->pr_flags & PR_ATOMIC))
					(void) sbdroprecord(&so->so_rcv);
				goto release;
			}
		} else
			uio->uio_resid -= len;
		if (len == m->m_len - moff) {
			if (m->m_flags & M_EOR)
				flags |= MSG_EOR;
			if (flags & MSG_PEEK) {
				m = m->m_next;
				moff = 0;
			} else {
				nextrecord = m->m_nextpkt;
				sbfree(&so->so_rcv, m);
				if (mp) {
					*mp = m;
					mp = &m->m_next;
					so->so_rcv.sb_mb = m = m->m_next;
					*mp = (struct mbuf *)0;
				} else {
					MFREE(m, so->so_rcv.sb_mb);
					m = so->so_rcv.sb_mb;
				}
				if (m)
					m->m_nextpkt = nextrecord;
			}
		} else {
			if (flags & MSG_PEEK)
				moff += len;
			else {
				if (mp)
					*mp = m_copym(m, 0, len, M_WAIT);
				m->m_data += len;
				m->m_len -= len;
				so->so_rcv.sb_cc -= len;
			}
		}
		if (so->so_oobmark) {
			if ((flags & MSG_PEEK) == 0) {
				so->so_oobmark -= len;
				if (so->so_oobmark == 0) {
					so->so_state |= SS_RCVATMARK;
					break;
				}
			} else {
				offset += len;
				if (offset == so->so_oobmark)
					break;
			}
		}
		if (flags & MSG_EOR)
			break;
		while (flags & MSG_WAITALL && m == 0 && uio->uio_resid > 0 &&
		    !sosendallatonce(so) && !nextrecord) {
			if (so->so_error || so->so_state & SS_CANTRCVMORE)
				break;
			error = sbwait(&so->so_rcv);
			if (error) {
				sbunlock(&so->so_rcv);
				_sce_pspnet_splunlock(s);
				return (0);
			}
			if ((m = so->so_rcv.sb_mb) != NULL)
				nextrecord = m->m_nextpkt;
		}
	}

	if (m && pr->pr_flags & PR_ATOMIC) {
		flags |= MSG_TRUNC;
		if ((flags & MSG_PEEK) == 0)
			(void) sbdroprecord(&so->so_rcv);
	}
	if ((flags & MSG_PEEK) == 0) {
		if (m == 0)
			so->so_rcv.sb_mb = nextrecord;
		if (pr->pr_flags & PR_WANTRCVD && so->so_pcb)
			(*pr->pr_usrreq)(so, PRU_RCVD, (struct mbuf *)0,
			    (struct mbuf *)(long)flags, (struct mbuf *)0);
	}
	if (orig_resid == uio->uio_resid && orig_resid &&
	    (flags & MSG_EOR) == 0 && (so->so_state & SS_CANTRCVMORE) == 0) {
		sbunlock(&so->so_rcv);
		_sce_pspnet_splunlock(s);
		goto restart;
	}

	if (flagsp)
		*flagsp |= flags;
release:
	sbunlock(&so->so_rcv);
	_sce_pspnet_splunlock(s);
	return (error);
}

int
soshutdown(struct socket *so, int how)
{
	struct protosw *pr = so->so_proto;

	if (!(how == SHUT_RD || how == SHUT_WR || how == SHUT_RDWR))
		return (EINVAL);
	if (how == SHUT_RD || how == SHUT_RDWR)
		sorflush(so);
	if (how == SHUT_WR || how == SHUT_RDWR)
		return (*pr->pr_usrreq)(so, PRU_SHUTDOWN, (struct mbuf *)0,
		    (struct mbuf *)0, (struct mbuf *)0);
	return (0);
}

void
sorflush(struct socket *so)
{
	struct sockbuf *sb = &so->so_rcv;
	struct protosw *pr = so->so_proto;
	int s;
	struct sockbuf asb;

	sb->sb_flags |= SB_NOINTR;
	(void) sblock(sb, M_WAIT);
	s = _sce_pspnet_spllock();
	socantrcvmore(so);
	sbunlock(sb);
	asb = *sb;
	memset((caddr_t)sb, 0, sizeof (*sb));
	_sce_pspnet_splunlock(s);
	if (pr->pr_flags & PR_RIGHTS && pr->pr_domain->dom_dispose)
		(*pr->pr_domain->dom_dispose)(asb.sb_mb);
	sbrelease(&asb);
}

int
sosetopt(struct socket *so, int level, int optname, struct mbuf *m0)
{
	int error = 0;
	struct mbuf *m = m0;

	if (level != SOL_SOCKET) {
		if (so->so_proto && so->so_proto->pr_ctloutput)
			return ((*so->so_proto->pr_ctloutput)
				  (PRCO_SETOPT, so, level, optname, &m0));
		error = ENOPROTOOPT;
	} else {
		switch (optname) {

		case SO_LINGER:
			if (m == NULL || m->m_len != sizeof (struct linger)) {
				error = EINVAL;
				goto bad;
			}
			so->so_linger = mtod(m, struct linger *)->l_linger;
			/* fall thru... */

		case SO_DEBUG:
		case SO_KEEPALIVE:
		case SO_DONTROUTE:
		case SO_USELOOPBACK:
		case SO_BROADCAST:
		case SO_REUSEADDR:
		case SO_REUSEPORT:
		case SO_OOBINLINE:
		case SO_TIMESTAMP:
			if (m == NULL || m->m_len < sizeof (int)) {
				error = EINVAL;
				goto bad;
			}
			if (*mtod(m, int *))
				so->so_options |= optname;
			else
				so->so_options &= ~optname;
			break;

		case SO_SNDBUF:
		case SO_RCVBUF:
		case SO_SNDLOWAT:
		case SO_RCVLOWAT:
		    {
			int optval;

			if (m == NULL || m->m_len < sizeof (int)) {
				error = EINVAL;
				goto bad;
			}
			optval = *mtod(m, int *);
			if (optval < 1) {
				error = EINVAL;
				goto bad;
			}
			switch (optname) {

			case SO_SNDBUF:
			case SO_RCVBUF:
				if (sbreserve(optname == SO_SNDBUF ?
				    &so->so_snd : &so->so_rcv,
				    (u_long) optval) == 0) {
					error = ENOBUFS;
					goto bad;
				}
				break;

			case SO_SNDLOWAT:
				so->so_snd.sb_lowat =
				    (optval > so->so_snd.sb_hiwat) ?
				    so->so_snd.sb_hiwat : optval;
				break;
			case SO_RCVLOWAT:
				so->so_rcv.sb_lowat =
				    (optval > so->so_rcv.sb_hiwat) ?
				    so->so_rcv.sb_hiwat : optval;
				break;
			}
			break;
		    }

		case SO_SNDTIMEO:
		case SO_RCVTIMEO:
		    {
			u_int val;

			if (m == NULL || m->m_len < sizeof (int)) {
				error = EINVAL;
				goto bad;
			}
			val = *mtod(m, u_int *);
			switch (optname) {

			case SO_SNDTIMEO:
				so->so_snd.sb_timeo = val / 10000;
				break;
			case SO_RCVTIMEO:
				so->so_rcv.sb_timeo = val / 10000;
				break;
			}
			break;
		    }

		case SO_NBIO:
			if (m == NULL || m->m_len < sizeof (int)) {
				error = EINVAL;
				goto bad;
			}
			if (*mtod(m, int *))
				so->so_state |= SS_NBIO;
			else
				so->so_state &= ~SS_NBIO;
			break;

		default:
			error = ENOPROTOOPT;
			break;
		}
		if (error == 0 && so->so_proto && so->so_proto->pr_ctloutput) {
			(void) ((*so->so_proto->pr_ctloutput)
				  (PRCO_SETOPT, so, level, optname, &m0));
			m = NULL;
		}
	}
bad:
	if (m)
		(void) m_free(m);
	return (error);
}

int
sogetopt(struct socket *so, int level, int optname, struct mbuf **mp)
{
	struct mbuf *m;

	if (level != SOL_SOCKET) {
		if (so->so_proto && so->so_proto->pr_ctloutput) {
			return ((*so->so_proto->pr_ctloutput)
				  (PRCO_GETOPT, so, level, optname, mp));
		} else
			return (ENOPROTOOPT);
	} else {
		m = m_get(M_WAIT, MT_SOOPTS);
		if (m == NULL)
			return (ENOBUFS);
		m->m_len = sizeof (int);

		switch (optname) {

		case SO_LINGER:
			m->m_len = sizeof (struct linger);
			mtod(m, struct linger *)->l_onoff =
				so->so_options & SO_LINGER;
			mtod(m, struct linger *)->l_linger = so->so_linger;
			break;

		case SO_USELOOPBACK:
		case SO_DONTROUTE:
		case SO_DEBUG:
		case SO_KEEPALIVE:
		case SO_REUSEADDR:
		case SO_REUSEPORT:
		case SO_BROADCAST:
		case SO_OOBINLINE:
		case SO_TIMESTAMP:
			*mtod(m, int *) = so->so_options & optname;
			break;

		case SO_TYPE:
			*mtod(m, int *) = so->so_type;
			break;

		case SO_ERROR:
			*mtod(m, int *) = so->so_error;
			so->so_error = 0;
			break;

		case SO_SNDBUF:
			*mtod(m, int *) = so->so_snd.sb_hiwat;
			break;

		case SO_RCVBUF:
			*mtod(m, int *) = so->so_rcv.sb_hiwat;
			break;

		case SO_SNDLOWAT:
			*mtod(m, int *) = so->so_snd.sb_lowat;
			break;

		case SO_RCVLOWAT:
			*mtod(m, int *) = so->so_rcv.sb_lowat;
			break;

		case SO_SNDTIMEO:
			*mtod(m, int *) = so->so_snd.sb_timeo;
			break;

		case SO_RCVTIMEO:
			*mtod(m, int *) = so->so_rcv.sb_timeo;
			break;

		case SO_NBIO:
			*mtod(m, int *) = so->so_state & SS_NBIO;
			break;

		default:
			(void)m_free(m);
			return (ENOPROTOOPT);
		}
		*mp = m;
		return (0);
	}
}

void
sohasoutofband(struct socket *so)
{
	selwakeup(&so->so_rcv.sb_sel);
}

int
sopoll(struct socket *so, int events, struct thread_info *p)
{
	int revents = 0;
	int s = _sce_pspnet_spllock();

	if (events & (POLLIN | POLLRDNORM))
		if (soreadable(so))
			revents |= events & (POLLIN | POLLRDNORM);

	if (events & (POLLOUT | POLLWRNORM))
		if (sowriteable(so))
			revents |= events & (POLLOUT | POLLWRNORM);

	if (events & (POLLPRI | POLLRDBAND))
		if (so->so_oobmark || (so->so_state & SS_RCVATMARK))
			revents |= events & (POLLPRI | POLLRDBAND);

	if (revents == 0) {
		if (events & (POLLIN | POLLPRI | POLLRDNORM | POLLRDBAND)) {
			selrecord(p, &so->so_rcv.sb_sel);
			so->so_rcv.sb_flags |= SB_SEL;
		}

		if (events & (POLLOUT | POLLWRNORM)) {
			selrecord(p, &so->so_snd.sb_sel);
			so->so_snd.sb_flags |= SB_SEL;
		}
	}

	_sce_pspnet_splunlock(s);
	return (revents);
}

int
soioctl(struct socket *so, u_long cmd, caddr_t data)
{
	if (IOCGROUP(cmd) == 'i')
		return (ifioctl(so, cmd, data, 1));
	if (IOCGROUP(cmd) == 'r')
		return (rtioctl(cmd, data));
	return ((*so->so_proto->pr_usrreq)(so, PRU_CONTROL,
	    (struct mbuf *)cmd, (struct mbuf *)data, (struct mbuf *)0));
}
