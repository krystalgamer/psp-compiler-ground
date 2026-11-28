/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"
#include <stdarg.h>

void
raw_init(void)
{
	LIST_INIT(&rawcb);
}

void
raw_input(struct mbuf *m0, ...)
{
	struct rawcb *rp;
	struct mbuf *m = m0;
	int sockets = 0;
	struct socket *last;
	va_list ap;
	struct sockproto *proto;
	struct sockaddr *src, *dst;

	va_start(ap, m0);
	proto = va_arg(ap, struct sockproto *);
	src = va_arg(ap, struct sockaddr *);
	dst = va_arg(ap, struct sockaddr *);
	va_end(ap);

	last = 0;
	for (rp = rawcb.lh_first; rp != 0; rp = rp->rcb_list.le_next) {
		if (rp->rcb_proto.sp_family != proto->sp_family)
			continue;
		if (rp->rcb_proto.sp_protocol &&
		    rp->rcb_proto.sp_protocol != proto->sp_protocol)
			continue;
#define equal(a1, a2) \
  (bcmp((caddr_t)(a1), (caddr_t)(a2), a1->sa_len) == 0)
		if (rp->rcb_laddr && !equal(rp->rcb_laddr, dst))
			continue;
		if (rp->rcb_faddr && !equal(rp->rcb_faddr, src))
			continue;
		if (last) {
			struct mbuf *n;
			if ((n = m_copy(m, 0, (int)M_COPYALL)) != NULL) {
				if (sbappendaddr(&last->so_rcv, src,
				    n, (struct mbuf *)0) == 0)
					m_freem(n);
				else {
					sorwakeup(last);
					sockets++;
				}
			}
		}
		last = rp->rcb_socket;
	}
	if (last) {
		if (sbappendaddr(&last->so_rcv, src,
		    m, (struct mbuf *)0) == 0)
			m_freem(m);
		else {
			sorwakeup(last);
			sockets++;
		}
	} else
		m_freem(m);
}

void *
raw_ctlinput(int cmd, struct sockaddr *arg, void *d)
{
	return NULL;
}

void
raw_setsockaddr(struct rawcb *rp, struct mbuf *nam)
{
	nam->m_len = rp->rcb_laddr->sa_len;
	bcopy(rp->rcb_laddr, mtod(nam, caddr_t), (unsigned)nam->m_len);
}

void
raw_setpeeraddr(struct rawcb *rp, struct mbuf *nam)
{
	nam->m_len = rp->rcb_faddr->sa_len;
	bcopy(rp->rcb_faddr, mtod(nam, caddr_t), (unsigned)nam->m_len);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/raw_usrreq", func_0000EFD0);
