/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc_auth.h"
/* --- end declarations --- */

int func_00001214(void)
{
	int ret;
	int i;

	if (sceMemab_driver_01FD1BA0() < 0)
		return 0x80410688;
	for (i = 0; i < 16; i++) {
		D_00003FD8[i].first = 0;
		D_00003FD8[i].last = &D_00003FD8[i].first;
	}
	ret = sceKernelCreateSema("SceNetAdhocAuth", 0, 1, 1, 0);
	if (ret < 0)
		return ret;
	D_00003FD4 = ret;
	return 0;
}

void func_00001290(void)
{
	sceKernelDeleteSema(D_00003FD4);
	D_00003FD4 = 0;
	sceMemab_driver_0C134D3F();
}

int func_000012C4(struct sa *sa)
{
	struct sahead *head;
	int ret = 0;

	if (sa_lookup(sa->mac.data) != 0)
		ret = 0x80410686;
	else {
		head = &D_00003FD8[sa->mac.data[5] & 0xF];
		if ((sa->next = head->first) != 0)
			head->first->prev = &sa->next;
		else
			head->last = &sa->next;
		head->first = sa;
		sa->prev = &head->first;
	}
	return ret;
}

int func_000013A4(struct sa *sa)
{
	struct sahead *head;
	int ret = 0;

	if (sa_lookup(sa->mac.data) == 0)
		ret = 0x80410685;
	else {
		head = &D_00003FD8[sa->mac.data[5] & 0xF];
		if (sa->next != 0)
			sa->next->prev = sa->prev;
		else
			head->last = sa->prev;
		*sa->prev = sa->next;
	}
	return ret;
}

struct sa *func_0000147C(const unsigned char *mac)
{
	struct sa *p;

	for (p = D_00003FD8[mac[5] & 0xF].first; p; p = p->next)
		if (memcmp(p->mac.data, mac, 6) == 0)
			break;
	return p;
}
