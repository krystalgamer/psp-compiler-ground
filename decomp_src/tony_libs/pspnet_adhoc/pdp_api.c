/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/pdp_api", sceNetAdhocPdpCreate);

int sceNetAdhocPdpSend(int id, struct SceNetEtherAddr *daddr, u_short dport, void *data, int len, unsigned int timeout, int flag)
{
	struct thread_info *ti;
	struct adhoc_socket *so, *q;
	struct thread_info *t;
	int s;
	int ret;

	if (daddr == NULL)
		return 0x80410711;
	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return 0x80410002;
	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	so = func_00000DFC(1, id);
	ret = 0x80410701;
	if (so == NULL)
		goto out;
	POLL_LINK(so, ti);
	ret = func_00001530(so, daddr, dport, data, len, timeout, flag);
	if ((struct adhoc_socket *)ti->polllist == so) {
		ti->polllist = so->pollnext;
	} else {
		for (q = ti->polllist; q->pollnext != so; q = q->pollnext)
			;
		q->pollnext = q->pollnext->pollnext;
	}
	if (so->pollq == ti) {
		so->pollq = ti->pollnext;
	} else {
		for (t = so->pollq; t->pollnext != ti; t = t->pollnext)
			;
		t->pollnext = t->pollnext->pollnext;
	}
	if (so->flags & 1) {
		if (so->pollq == NULL) {
			func_00002B38(so);
			func_00000F74(so);
		}
		ret = 0x80410707;
	}
out:
	_sce_pspnet_splunlock(s);
	_sce_pspnet_thread_leave(ti, 0);
	return ret;
}

int sceNetAdhocPdpDelete(int id, int flag)
{
	struct adhoc_socket *so;
	struct pdpcb *pcb;
	int s;
	int ret;

	ret = 0;
	s = _sce_pspnet_spllock();
	if (D_00007400 == 0) {
		ret = 0x80410712;
		goto out;
	}
	so = func_00000DFC(1, id);
	if (so == NULL) {
		ret = 0x80410701;
		goto out;
	}
	pcb = so->pcb;
	if (pcb->flags & 1) {
		pcb->flags &= ~1;
		_sce_pspnet_wakeup(&pcb->rcv_head);
	}
	if (pcb->flags & 2) {
		pcb->flags &= ~2;
		_sce_pspnet_wakeup(&D_00007448);
	}
	if (pcb->ifp->if_adhocflags & 1) {
		pcb->ifp->if_adhocflags &= ~1;
		_sce_pspnet_wakeup(&pcb->ifp->if_snd);
	}
	if (pcb->ifp->if_adhocflags & 2) {
		pcb->ifp->if_adhocflags &= ~2;
		_sce_pspnet_wakeup(&D_00007448);
	}
	func_00002304(pcb);
	so->flags |= 1;
	so->id = -1;
	if (so->pollq == NULL) {
		func_00002B38(so);
		func_00000F74(so);
	}
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/pdp_api", func_00001530);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/pdp_api", func_00001B90);

int sceNetAdhocPdpRecv(int id, struct SceNetEtherAddr *saddr, u_short *sport, void *buf, int *len, unsigned int timeout, int flag)
{
	if (buf == NULL || len == NULL)
		return 0x80410711;
	return func_00001F20(id, saddr, sport, buf, len, timeout, flag, NULL);
}

int sceNetAdhoc_lib_67346A2A(int id, struct SceNetEtherAddr *saddr, u_short *sport, void *buf, int *len, unsigned int timeout, int flag, int *x)
{
	if (buf == NULL || len == NULL || x == NULL)
		return 0x80410711;
	return func_00001F20(id, saddr, sport, buf, len, timeout, flag, x);
}

int func_00001F20(int id, struct SceNetEtherAddr *saddr, u_short *sport, void *buf, int *len, unsigned int timeout, int flag, int *x)
{
	struct thread_info *ti;
	struct adhoc_socket *so, *q;
	struct thread_info *t;
	int s;
	int ret;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return 0x80410002;
	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	so = func_00000DFC(1, id);
	ret = 0x80410701;
	if (so == NULL)
		goto out;
	POLL_LINK(so, ti);
	ret = func_00001B90(so, saddr, sport, buf, len, timeout, flag, x);
	if ((struct adhoc_socket *)ti->polllist == so) {
		ti->polllist = so->pollnext;
	} else {
		for (q = ti->polllist; q->pollnext != so; q = q->pollnext)
			;
		q->pollnext = q->pollnext->pollnext;
	}
	if (so->pollq == ti) {
		so->pollq = ti->pollnext;
	} else {
		for (t = so->pollq; t->pollnext != ti; t = t->pollnext)
			;
		t->pollnext = t->pollnext->pollnext;
	}
	if (so->flags & 1) {
		if (so->pollq == NULL) {
			func_00002B38(so);
			func_00000F74(so);
		}
		ret = 0x80410707;
	}
out:
	_sce_pspnet_splunlock(s);
	_sce_pspnet_thread_leave(ti, 0);
	return ret;
}
