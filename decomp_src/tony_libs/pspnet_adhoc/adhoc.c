/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/adhoc", sceNetAdhocInit);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/adhoc", sceNetAdhocTerm);

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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/adhoc", func_00000320);

int func_00000430(struct ifnet *ifp, struct mbuf *m, struct ifqueue **inq)
{
	*inq = &D_00007404;
	return 0;
}

void func_00000444(void *arg)
{
	func_00002B90(arg);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/adhoc", sceNetAdhocPollSocket);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/adhoc", func_0000092C);

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
