/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/pdp", func_00002108);

void func_00002304(struct pdpcb *pcb)
{
	struct mbuf *m;
	struct pdp_frag *f;

	while (pcb->rcv_head != NULL) {
		m = pcb->rcv_head;
		if ((pcb->rcv_head = m->m_nextpkt) == NULL)
			pcb->rcv_tail = NULL;
		pcb->rcv_cc -= m->m_pkthdr.len - 0x3C;
		m->m_nextpkt = NULL;
		sceNetMFreem(m);
	}
	pcb->rcv_hiwat = 0;
	while ((f = pcb->fragq.tqh_first) != NULL) {
		_sce_pspnet_callout_stop(&f->co);
		sceNetMFreem(f->m);
		TAILQ_REMOVE(&pcb->fragq, f, link);
		sceNetFreeInternal(f);
	}
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/pdp", func_000023C4);

int sceNetAdhocGetPdpStat(int *buflen, void *buf)
{
	struct pdpcb *pcb;
	struct SceNetAdhocPdpStat *st, *prev;
	int s;
	int ret;
	int len;

	ret = 0;
	prev = NULL;
	len = 0;
	if (buflen == NULL)
		return 0x80410711;
	s = _sce_pspnet_spllock();
	if (D_00007400 == 0) {
		ret = 0x80410712;
		goto out;
	}
	for (pcb = D_00007424.tqh_first; pcb != NULL; pcb = pcb->link.tqe_next) {
		if (buf != NULL) {
			if (*buflen < len + sizeof(*st))
				break;
			st = (struct SceNetAdhocPdpStat *)((char *)buf + len);
			st->next = NULL;
			st->id = pcb->so->id;
			st->laddr = pcb->laddr;
			st->lport = pcb->lport;
			st->rcv_sb_cc = pcb->rcv_cc;
			if (prev != NULL)
				prev->next = st;
			prev = st;
		}
		len += sizeof(*st);
	}
out:
	_sce_pspnet_splunlock(s);
	*buflen = len;
	return ret;
}

int func_000029AC(void)
{
	TAILQ_INIT(&D_00007424);
	D_0000742C = sceNetRand() / 0x20009 + 0x4000;
	D_0000744C = sceNetRand() / 0x8001;
	return 0;
}

void func_00002A18(void)
{
	struct pdpcb *pcb, *p;
	struct adhoc_socket *so;

	while ((pcb = D_00007424.tqh_first) != NULL) {
		func_00002304(pcb);
		so = pcb->so;
		p = so->pcb;
		so->pcb = NULL;
		TAILQ_REMOVE(&D_00007424, p, link);
		sceNetFreeInternal(p);
	}
}

int func_00002A9C(struct adhoc_socket *so)
{
	struct pdpcb *pcb;
	int ret;

	pcb = sceNetMallocInternal(sizeof(*pcb));
	ret = 0x80410001;
	if (pcb != NULL) {
		memset(pcb, 0, sizeof(*pcb));
		TAILQ_INIT(&pcb->fragq);
		pcb->so = so;
		so->pcb = pcb;
		TAILQ_INSERT_TAIL(&D_00007424, pcb, link);
		ret = 0;
	}
	return ret;
}

void func_00002B38(struct adhoc_socket *so)
{
	struct pdpcb *pcb;

	pcb = so->pcb;
	so->pcb = NULL;
	TAILQ_REMOVE(&D_00007424, pcb, link);
	sceNetFreeInternal(pcb);
}

int func_00002B84(struct pdpcb *pcb, u_int size)
{
	pcb->rcv_hiwat = size;
	return 0;
}

void func_00002B90(struct ifnet *ifp)
{
	if (ifp->if_adhocflags & 1) {
		ifp->if_adhocflags &= ~1;
		_sce_pspnet_wakeup(&ifp->if_snd);
	}
	if (ifp->if_adhocflags & 2) {
		ifp->if_adhocflags &= ~2;
		_sce_pspnet_wakeup(&D_00007448);
	}
}

int func_00002C00(struct adhoc_socket *so, int events)
{
	struct pdpcb *pcb;
	int revents;

	pcb = so->pcb;
	revents = 0;
	if ((events & 2) && pcb->rcv_head != NULL)
		revents = 2;
	if ((events & 1) && pcb->ifp->if_snd.ifq_len < pcb->ifp->if_snd.ifq_maxlen)
		revents |= 1;
	if (revents == 0) {
		if (events & 2)
			pcb->flags |= 2;
		if (events & 1)
			pcb->ifp->if_adhocflags |= 2;
	}
	return revents;
}

void func_00002C7C(void *arg)
{
	struct pdp_frag *f = arg;

	_sce_pspnet_callout_stop(&f->co);
	sceNetMFreem(f->m);
	TAILQ_REMOVE(&f->pcb->fragq, f, link);
	sceNetFreeInternal(f);
}
