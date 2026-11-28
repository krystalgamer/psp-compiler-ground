/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc.h"
/* --- end declarations --- */

void func_0000483C(void)
{
	struct ptpcb *pcb, *c;

	while ((pcb = D_00007430.tqh_first) != NULL) {
		TAILQ_REMOVE(&D_00007430, pcb, link);
		while ((c = pcb->children.tqh_first) != NULL) {
			TAILQ_REMOVE(&pcb->children, c, clink);
			_sce_pspnet_callout_stop(&c->co);
			func_00004B64(c);
			func_00004B18(c->so);
		}
		_sce_pspnet_callout_stop(&pcb->co);
		func_00004B64(pcb);
		func_00004B18(pcb->so);
	}
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/ptp", func_00004918);

void func_00004B18(struct adhoc_socket *so)
{
	struct ptpcb *pcb;

	pcb = so->pcb;
	so->pcb = NULL;
	TAILQ_REMOVE(&D_00007430, pcb, link);
	sceNetFreeInternal(pcb);
}

void func_00004B64(struct ptpcb *pcb)
{
	struct mbuf *m;

	while (pcb->snd.sb_head != NULL) {
		m = pcb->snd.sb_head;
		if ((pcb->snd.sb_head = m->m_nextpkt) == NULL)
			pcb->snd.sb_tail = NULL;
		pcb->snd.sb_cc -= m->m_pkthdr.len;
		m->m_nextpkt = NULL;
		sceNetMFreem(m);
	}
	pcb->snd.sb_hiwat = 0;
	while (pcb->rcv.sb_head != NULL) {
		m = pcb->rcv.sb_head;
		if ((pcb->rcv.sb_head = m->m_nextpkt) == NULL)
			pcb->rcv.sb_tail = NULL;
		pcb->rcv.sb_cc -= m->m_pkthdr.len;
		m->m_nextpkt = NULL;
		sceNetMFreem(m);
	}
	pcb->rcv.sb_hiwat = 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/ptp", func_00004C0C);

void func_00004E60(struct ptpcb *pcb)
{
	_sce_pspnet_callout_stop(&pcb->co);
	pcb->state = 4;
	pcb->so->flags = (pcb->so->flags & ~0x2000) | 0x4000;
	if (pcb->parent != NULL)
		SBWAKEUP(pcb->parent->rcv);
	else
		SBWAKEUP(pcb->rcv);
}

void func_00004F50(struct ptpcb *pcb)
{
	_sce_pspnet_callout_stop(&pcb->co);
	if (pcb->so->flags & 0x6000)
		func_00006340(pcb, 7);
	pcb->so->flags = (pcb->so->flags & ~0x3000) | 0x8000;
	pcb->state = 0;
	if (pcb->parent != NULL) {
		SBWAKEUP(pcb->parent->rcv);
		SBWAKEUP(pcb->parent->snd);
	} else {
		SBWAKEUP(pcb->rcv);
		SBWAKEUP(pcb->snd);
	}
}

int func_000050F8(struct adhoc_socket *so, int events)
{
	struct ptpcb *pcb, *c;
	int revents;

	revents = 0;
	pcb = so->pcb;
	if ((events & 2) && pcb->rcv.sb_cc >= pcb->rcv.sb_lowat)
		revents = 2;
	if ((events & 1) && pcb->snd.sb_hiwat - pcb->snd.sb_cc >= pcb->snd.sb_lowat)
		revents |= 1;
	if ((events & 4) && (so->flags & 0x4000))
		revents |= 4;
	if ((events & 8) && (so->flags & 0x1000)) {
		for (c = pcb->children.tqh_first; c != NULL; c = c->clink.tqe_next) {
			if (c->so->flags & 0x4000) {
				revents |= 8;
				break;
			}
		}
	}
	if ((events & 0x10) && pcb->snd.sb_cc == 0)
		revents |= 0x10;
	if (revents == 0) {
		if (events & 2)
			pcb->rcv.sb_flags |= 2;
		if (events & 1)
			pcb->snd.sb_flags |= 2;
		if (events & 4)
			pcb->rcv.sb_flags |= 2;
		if (events & 8)
			pcb->rcv.sb_flags |= 2;
		if (events & 0x10)
			pcb->snd.sb_flags |= 2;
	}
	return revents;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/ptp", sceNetAdhocGetPtpStat);

int func_00005374(void)
{
	TAILQ_INIT(&D_00007430);
	D_00007438 = sceNetRand() / 0x20009 + 0x4000;
	D_0000743C = sceNetRand();
	return 0;
}

struct ptpcb *func_000053CC(struct SceNetEtherAddr *laddr, u_short lport, struct SceNetEtherAddr *faddr, u_short fport)
{
	struct ptpcb *pcb;

	for (pcb = D_00007430.tqh_first; pcb != NULL; pcb = pcb->link.tqe_next) {
		if (memcmp(&pcb->laddr, laddr, 6) == 0 && pcb->lport == lport) {
			if (faddr == NULL)
				break;
			if (memcmp(&pcb->faddr, faddr, 6) == 0 && pcb->fport == fport)
				break;
		}
	}
	return pcb;
}

int func_0000548C(struct adhoc_socket *so)
{
	struct ptpcb *pcb;
	int ret;

	pcb = sceNetMallocInternal(sizeof(*pcb));
	ret = 0x80410001;
	if (pcb != NULL) {
		memset(pcb, 0, sizeof(*pcb));
		TAILQ_INIT(&pcb->children);
		_sce_pspnet_callout_init(&pcb->co);
		TAILQ_INSERT_TAIL(&D_00007430, pcb, link);
		pcb->state = 0;
		pcb->so = so;
		so->pcb = pcb;
		ret = 0;
	}
	return ret;
}

void func_00005528(struct ptpcb *pcb)
{
	memset(&pcb->laddr, 0, sizeof(pcb->laddr));
	memset(&pcb->faddr, 0, sizeof(pcb->faddr));
	pcb->lport = 0;
}

int func_00005544(struct ptpcb *pcb, u_int sndbuf, u_int rcvbuf)
{
	pcb->snd.sb_lowat = 1;
	pcb->snd.sb_hiwat = sndbuf;
	pcb->rcv.sb_hiwat = rcvbuf;
	pcb->rcv.sb_lowat = 1;
	return 0;
}

void func_00005560(struct ptpcb *pcb, u_int rexmt_int, int rexmt_cnt)
{
	pcb->rexmt_int = rexmt_int;
	pcb->rexmt_cnt = rexmt_cnt;
}

int func_0000556C(struct ptpcb *pcb, struct SceNetEtherAddr *faddr, u_short fport)
{
	if (memcmp(faddr, &D_0000734C, 6) == 0)
		return 0x80410702;
	if ((faddr->data[0] & 1) && memcmp(faddr, &D_00007344, 6) != 0)
		return 0x80410702;
	if (fport == 0 || fport == 0xFFFF)
		return 0x80410703;
	memcpy(&pcb->faddr, faddr, 6);
	pcb->state = 2;
	pcb->iss = D_0000743C++;
	pcb->fport = fport;
	pcb->so->flags |= 0x2000;
	func_00006340(pcb, 1);
	pcb->rexmt_left = pcb->rexmt_cnt;
	_sce_pspnet_callout_reset_usec(&pcb->co, pcb->rexmt_int, func_00006624, pcb);
	return 0;
}

int func_000056B0(struct ptpcb *pcb, int backlog)
{
	pcb->state = 1;
	pcb->backlog = backlog;
	pcb->so->flags |= 0x1000;
	return 0;
}

void func_000056D4(struct ptpcb *pcb)
{
	struct ptpcb *c;
	struct adhoc_socket *so;

	while ((c = pcb->children.tqh_first) != NULL) {
		so = c->so;
		TAILQ_REMOVE(&pcb->children, c, clink);
		pcb->nchildren--;
		func_00004F50(c);
		func_000056D4(c);
		func_00004B18(so);
		func_00000F74(so);
	}
	memset(&pcb->laddr, 0, sizeof(pcb->laddr));
	memset(&pcb->faddr, 0, sizeof(pcb->faddr));
	pcb->lport = 0;
	func_00004B64(pcb);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/ptp", func_0000578C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/ptp", func_00005FF8);

void func_00006340(struct ptpcb *pcb, u_char type)
{
	struct mbuf *m;
	u_int seq;
	u_int win;

	switch (type) {
	case 1:
	case 2:
	case 3:
	case 7:
		seq = pcb->iss;
		break;
	case 5:
		seq = pcb->rcv_nxt - 1;
		break;
	case 6:
		seq = pcb->rcv_nxt;
		break;
	default:
		seq = 0;
		break;
	}
	switch (type) {
	case 1:
	case 2:
	case 5:
		MGETHDR(m, M_DONTWAIT, 1);
		if (m == NULL)
			return;
		win = htonl(pcb->rcv.sb_hiwat - pcb->rcv.sb_cc);
		__builtin_memcpy(mtod(m, char *), &win, 4);
		m->m_len = 4;
		m->m_pkthdr.len = 4;
		m->m_pkthdr.rcvif = NULL;
		break;
	default:
		m = NULL;
		break;
	}
	func_00005FF8(pcb->ifp, &pcb->laddr, pcb->lport, &pcb->faddr, pcb->fport, type, seq, m);
	if (m != NULL)
		sceNetMFreem(m);
}

void func_0000648C(struct ptpcb *pcb, int flag)
{
	struct mbuf *m;
	u_int seq;
	int n;

	n = 0;
	m = pcb->snd.sb_head;
	for (seq = pcb->snd_una; m != NULL && seq != pcb->snd_nxt; seq++)
		m = m->m_nextpkt;
	while (m != NULL) {
		if (pcb->snd_wnd - pcb->snd_inflight < m->m_pkthdr.len) {
			if (n != 0)
				break;
			if (flag != 0) {
				func_00005FF8(pcb->ifp, &pcb->laddr, pcb->lport, &pcb->faddr, pcb->fport, 4, pcb->snd_una - 1, NULL);
				D_00007450.unk28++;
			} else if (!(pcb->co.c_flags & 1)) {
				D_00007450.unk2C++;
				pcb->rexmt_left = pcb->rexmt_cnt;
				_sce_pspnet_callout_reset_usec(&pcb->co, pcb->rexmt_int, func_00006624, pcb);
			}
			break;
		}
		func_00005FF8(pcb->ifp, &pcb->laddr, pcb->lport, &pcb->faddr, pcb->fport, 4, pcb->snd_nxt, m);
		n++;
		pcb->snd_nxt++;
		pcb->snd_inflight += m->m_pkthdr.len;
		m = m->m_next;
	}
	if (flag == 0 && n > 0) {
		pcb->rexmt_left = pcb->rexmt_cnt;
		_sce_pspnet_callout_reset_usec(&pcb->co, pcb->rexmt_int, func_00006624, pcb);
	}
}

void func_00006624(void *arg)
{
	struct ptpcb *pcb = arg;

	if ((u_int)pcb->state < 2)
		return;
	if (pcb->rexmt_left-- <= 0) {
		_sce_pspnet_callout_stop(&pcb->co);
		func_00004F50(pcb);
		return;
	}
	switch (pcb->state) {
	case 2:
		func_00006340(pcb, 1);
		break;
	case 3:
		func_00006340(pcb, 2);
		break;
	case 4:
		pcb->snd_inflight = 0;
		pcb->snd_nxt = pcb->snd_una;
		func_0000648C(pcb, 1);
		D_00007450.unk24++;
		break;
	}
	_sce_pspnet_callout_reset_usec(&pcb->co, pcb->rexmt_int, func_00006624, pcb);
}
