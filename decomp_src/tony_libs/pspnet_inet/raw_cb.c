/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

int
raw_attach(struct socket *so, int proto)
{
	struct rawcb *rp = sotorawcb(so);
	int error;

	if (rp == 0)
		return (ENOBUFS);
	if ((error = soreserve(so, raw_sendspace, raw_recvspace)) != 0)
		return (error);
	rp->rcb_socket = so;
	rp->rcb_proto.sp_family = so->so_proto->pr_domain->dom_family;
	rp->rcb_proto.sp_protocol = proto;
	LIST_INSERT_HEAD(&rawcb, rp, rcb_list);
	return (0);
}

void
raw_detach(struct rawcb *rp)
{
	struct socket *so = rp->rcb_socket;

	so->so_pcb = 0;
	sofree(so);
	LIST_REMOVE(rp, rcb_list);
	sceNetFreeInternal(rp);
}

void
raw_disconnect(struct rawcb *rp)
{
	if (rp->rcb_socket->so_state & SS_NOFDREF)
		raw_detach(rp);
}
