/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

int _sce_pspnet_tsleep_usec(void *wchan, unsigned int usec)
{
	struct thread_info *ti;
	struct slpque *q;
	int ret = 0;
	int relock = 0;

	ti = _sce_pspnet_get_threadinfo(sceKernelGetThreadId());
	sceKernelWaitSema(D_0000A0A0, 1, 0);
	if (D_0000AC28 > 0)
		D_0000AC18(ti);
	if (ti->slpflags & 2) {
		ti->slpflags &= ~2;
		ret = 4;
		goto out;
	}
	q = SLPQUE(wchan);
	TAILQ_INSERT_TAIL(q, ti, slpq);
	ti->wchan = wchan;
	sceKernelSignalSema(D_0000A0A0, 1);
	if (usec != 0)
		_sce_pspnet_callout_reset_usec(&ti->co, usec, func_000030A8, ti);
	if (sceNet_lib_6DC71518() == sceKernelGetThreadId()) {
		relock = 1;
		_sce_pspnet_splunlock(1);
	}
	sceKernelWaitSema(ti->sema, 1, 0);
	if (relock)
		_sce_pspnet_spllock();
	if (usec != 0)
		_sce_pspnet_callout_stop(&ti->co);
	sceKernelWaitSema(D_0000A0A0, 1, 0);
	TAILQ_REMOVE(q, ti, slpq);
	ti->slpq.tqe_prev = NULL;
	ti->slpq.tqe_next = NULL;
	if (ti->slpflags & 1) {
		ti->slpflags &= ~1;
		ret = 11;
		goto out;
	}
	if (ti->slpflags & 2) {
		ti->slpflags &= ~2;
		ret = 4;
	}
out:
	sceKernelSignalSema(D_0000A0A0, 1);
	return ret;
}

int func_00002FC4(void)
{
	int i;

	for (i = 0; i < 128; i++)
		TAILQ_INIT(&slpque[i]);
	D_0000A0A0 = sceKernelCreateSema("SceNetSlpque", 0, 1, 1, 0);
	return (D_0000A0A0 < 0) ? D_0000A0A0 : 0;
}

void func_00003028(void)
{
	if (D_0000A0A0 >= 0)
		sceKernelDeleteSema(D_0000A0A0);
	D_0000A0A0 = -1;
}

int _sce_pspnet_tsleep(void *wchan, unsigned int ticks)
{
	if (ticks > 0x68DB8)
		return 22;
	return _sce_pspnet_tsleep_usec(wchan, ticks * 10000);
}

void func_000030A8(void *arg)
{
	struct thread_info *ti = arg;

	sceKernelWaitSema(D_0000A0A0, 1, 0);
	if (ti->wchan != NULL) {
		ti->wchan = NULL;
		ti->slpflags |= 1;
		sceKernelSignalSema(ti->sema, 1);
	}
	sceKernelSignalSema(D_0000A0A0, 1);
}

void _sce_pspnet_wakeup(void *wchan)
{
	struct thread_info *ti;

	sceKernelWaitSema(D_0000A0A0, 1, 0);
	for (ti = SLPQUE(wchan)->tqh_first; ti != NULL; ti = ti->slpq.tqe_next) {
		if (ti->wchan == wchan) {
			ti->wchan = NULL;
			sceKernelSignalSema(ti->sema, 1);
		}
	}
	sceKernelSignalSema(D_0000A0A0, 1);
}

void _sce_pspnet_tiwakeup(SceUID thid, void *wchan)
{
	struct thread_info *ti;

	sceKernelWaitSema(D_0000A0A0, 1, 0);
	for (ti = SLPQUE(wchan)->tqh_first; ti != NULL; ti = ti->slpq.tqe_next) {
		if ((thid < 0 || thid == ti->thid) && ti->wchan == wchan) {
			ti->wchan = NULL;
			sceKernelSignalSema(ti->sema, 1);
		}
	}
	sceKernelSignalSema(D_0000A0A0, 1);
}

int _sce_pspnet_tabort(struct thread_info *ti)
{
	sceKernelWaitSema(D_0000A0A0, 1, 0);
	ti->slpflags |= 2;
	if (ti->wchan != NULL) {
		ti->wchan = NULL;
		sceKernelSignalSema(ti->sema, 1);
	}
	sceKernelSignalSema(D_0000A0A0, 1);
}

void _sce_pspnet_adhoc_sabort(void *a, void *b)
{
	sceKernelWaitSema(D_0000A0A0, 1, 0);
	if (D_0000AC24 > 0)
		D_0000AC1C(a, b);
	sceKernelSignalSema(D_0000A0A0, 1);
}

void _sce_pspnet_inet_sabort(void *a)
{
	sceKernelWaitSema(D_0000A0A0, 1, 0);
	if (D_0000AC28 > 0)
		D_0000AC20(a);
	sceKernelSignalSema(D_0000A0A0, 1);
}

int _sce_pspnet_start_of_adhoc_module_in_sched(void (*f)(void *, void *))
{
	D_0000AC1C = f;
	D_0000AC24 = 1;
	return 0;
}

int _sce_pspnet_stop_of_adhoc_module_in_sched(void)
{
	D_0000AC24 = 0;
	D_0000AC1C = NULL;
	return 0;
}

int _sce_pspnet_start_of_inet_module_in_sched(void (*f)(struct thread_info *), void (*g)(void *))
{
	D_0000AC18 = f;
	D_0000AC20 = g;
	D_0000AC28 = 1;
	return 0;
}

int _sce_pspnet_stop_of_inet_module_in_sched(void)
{
	D_0000AC28 = 0;
	D_0000AC18 = NULL;
	D_0000AC20 = NULL;
	return 0;
}
