/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc.h"
/* --- end declarations --- */

int sceNetAdhocInit(void)
{
	int s;
	int ret;

	s = _sce_pspnet_spllock();
	ret = 0x80410713;
	if (D_00007400 > 0)
		goto out;
	D_00007404.ifq_maxlen = 50;
	D_00007404.ifq_head = NULL;
	D_00007404.ifq_len = 0;
	D_00007404.ifq_drops = 0;
	D_00007404.ifq_tail = NULL;
	if ((ret = func_00000D3C()) < 0)
		goto out;
	if ((ret = func_000029AC()) < 0)
		goto err1;
	if ((ret = func_00005374()) < 0)
		goto err2;
	if ((ret = _sce_pspnet_start_of_adhoc_module_in_netintr(func_00000224, func_00000444)) < 0)
		goto err3;
	if ((ret = _sce_pspnet_start_of_adhoc_module_in_if_ethersubr_core(func_00000430)) < 0)
		goto err4;
	if (func_00006880() < 0)
		goto err5;
	D_00007400 = 1;
	_sce_pspnet_splunlock(s);
	return 0;
err5:
	_sce_pspnet_stop_of_adhoc_module_in_if_ethersubr_core();
err4:
	_sce_pspnet_stop_of_adhoc_module_in_netintr();
err3:
	func_0000483C();
err2:
	func_00002A18();
err1:
	func_00000D84();
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

int sceNetAdhocTerm(void)
{
	int s;
	int ret;
	struct mbuf *m;

	ret = 0;
	s = _sce_pspnet_spllock();
	if (D_00007400 == 0)
		goto out;
	if (func_00000FBC() != 0) {
		ret = 0x80410714;
		goto out;
	}
	func_00006898();
	_sce_pspnet_stop_of_adhoc_module_in_if_ethersubr_core();
	_sce_pspnet_stop_of_adhoc_module_in_netintr();
	func_0000483C();
	func_00002A18();
	func_00000D84();
	while (D_00007404.ifq_head != NULL) {
		IF_DEQUEUE(&D_00007404, m);
		sceNetMFreem(m);
	}
	D_00007400 = 0;
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

void func_00000224(void)
{
	struct mbuf *m;
	u_char type;

	for (;;) {
		IF_DEQUEUE(&D_00007404, m);
		if (m == NULL)
			return;
		if ((u_int)m->m_pkthdr.len <= 0x30)
			goto drop;
		if ((u_int)m->m_len > 0x30)
			type = mtod(m, u_char *)[0x30];
		else
			sceNetMCopydata(m, 0x30, 1, &type);
		if (type == 1)
			func_000023C4(m);
		else if (type == 2)
			func_0000578C(m);
		else
drop:
			sceNetMFreem(m);
	}
}

void func_00000320(struct ifnet *ifp, struct mbuf *m)
{
	if (memcmp(mtod(m, char *), LLADDR(ifp->if_sadl), 6) == 0) {
		if (D_00007404.ifq_len >= D_00007404.ifq_maxlen)
			goto drop;
		m->m_pkthdr.rcvif = ifp;
		IF_ENQUEUE(&D_00007404, m);
		_sce_pspnet_schednetintr_with_evf(0x1D);
		return;
	}
	m->m_flags |= 0x8000;
	IF_ENQUEUE(&ifp->if_snd, m);
	if (!(ifp->if_flags & IFF_OACTIVE))
		(*ifp->if_start)(ifp);
	return;
drop:
	IF_DROP(&D_00007404);
	sceNetMFreem(m);
}

int func_00000430(struct ifnet *ifp, struct mbuf *m, struct ifqueue **inq)
{
	*inq = &D_00007404;
	return 0;
}

void func_00000444(struct ifnet *ifp)
{
	func_00002B90(ifp);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/adhoc", sceNetAdhocPollSocket);

int func_0000092C(struct pollent *pe, int n)
{
	int count;
	int i;

	count = 0;
	for (i = 0; i < n; i++, pe++) {
		switch (pe->so->type) {
		case 1:
			pe->sd->revents = func_00002C00(pe->so, pe->sd->events);
			break;
		case 2:
			pe->sd->revents = func_000050F8(pe->so, pe->sd->events);
			break;
		}
		count += pe->sd->revents != 0;
	}
	return count;
}

int sceNetAdhocSetSocketAlert(int id, int flag)
{
	struct adhoc_socket *so;
	int s;
	int ret;
	int n;

	ret = 0;
	s = _sce_pspnet_spllock();
	n = 0;
	if (D_00007400 == 0) {
		ret = 0x80410712;
		goto out;
	}
	for (so = D_00007418.tqh_first; so != NULL; so = so->link.tqe_next) {
		if (so->id == id)
			break;
	}
	if (so == NULL) {
		ret = 0x80410701;
		goto out;
	}
	if (flag & 0x10) {
		if (!(so->flags & 0x10)) {
			so->flags |= 0x10;
			n++;
		}
	} else
		so->flags &= ~0x10;
	if (flag & 0x20) {
		if (!(so->flags & 0x20)) {
			so->flags |= 0x20;
			n++;
		}
	} else
		so->flags &= ~0x20;
	if (flag & 0x40) {
		if (!(so->flags & 0x40)) {
			so->flags |= 0x40;
			n++;
		}
	} else
		so->flags &= ~0x40;
	if (flag & 0x80) {
		if (!(so->flags & 0x80)) {
			so->flags |= 0x80;
			n++;
		}
	} else
		so->flags &= ~0x80;
	if (flag & 0x100) {
		if (!(so->flags & 0x100)) {
			so->flags |= 0x100;
			n++;
		}
	} else
		so->flags &= ~0x100;
	if (flag & 0x200) {
		if (!(so->flags & 0x200)) {
			so->flags |= 0x200;
			n++;
		}
	} else
		so->flags &= ~0x200;
	if (n != 0)
		_sce_pspnet_adhoc_sabort(so, flag);
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

int sceNetAdhocGetSocketAlert(int id, int *flag)
{
	struct adhoc_socket *so;
	int s;
	int ret;

	ret = 0;
	if (flag == NULL)
		return 0x80410711;
	s = _sce_pspnet_spllock();
	if (D_00007400 == 0) {
		ret = 0x80410712;
		goto out;
	}
	for (so = D_00007418.tqh_first; so != NULL; so = so->link.tqe_next) {
		if (so->id == id)
			break;
	}
	if (so == NULL) {
		ret = 0x80410701;
		goto out;
	}
	*flag = 0;
	if (so->flags & 0x10)
		*flag = 0x10;
	if (so->flags & 0x20)
		*flag |= 0x20;
	if (so->flags & 0x40)
		*flag |= 0x40;
	if (so->flags & 0x80)
		*flag |= 0x80;
	if (so->flags & 0x100)
		*flag |= 0x100;
	if (so->flags & 0x200)
		*flag |= 0x200;
out:
	_sce_pspnet_splunlock(s);
	return ret;
}
