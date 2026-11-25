/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

void func_000028D0(void)
{
	struct callout *c;
	int s;

	s = sceKernelCpuSuspendIntr();
	for (;;) {
		c = D_0000AC10.tqh_first;
		if (c == NULL)
			break;
		TAILQ_REMOVE(&D_0000AC10, c, c_pending);
		sceKernelCancelAlarm(c->c_alarm);
	}
	sceKernelCpuResumeIntr(s);
	if (D_0000A09C >= 0) {
		sceKernelTerminateThread(D_0000A09C);
		sceKernelDeleteThread(D_0000A09C);
	}
	D_0000A09C = -1;
	if (D_0000A098 >= 0)
		sceKernelDeleteSema(D_0000A098);
	D_0000A098 = -1;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/callout", _sce_pspnet_callout_reset_usec);

void _sce_pspnet_callout_stop(struct callout *c)
{
	int s;

	s = sceKernelCpuSuspendIntr();
	if (!(c->c_flags & 2)) {
		c->c_flags &= ~1;
	} else {
		if (sceKernelCancelAlarm(c->c_alarm) == 0)
			TAILQ_REMOVE(&D_0000AC10, c, c_pending);
		else
			TAILQ_REMOVE(&D_0000AC08, c, c_fired);
		c->c_func = NULL;
		c->c_fired.tqe_next = NULL;
		c->c_fired.tqe_prev = NULL;
		c->c_flags &= ~3;
	}
	sceKernelCpuResumeIntr(s);
}

int func_00002B34(int prio, int stack)
{
	int ret;

	TAILQ_INIT(&D_0000AC08);
	TAILQ_INIT(&D_0000AC10);
	D_0000A098 = sceKernelCreateSema("SceNetCalloutQueue", 0, 0, 1, 0);
	if (D_0000A098 < 0)
		return D_0000A098;
	D_0000A09C = sceKernelCreateThread("SceNetCallout", func_00002C74, prio, stack, 0, 0);
	if (D_0000A09C < 0)
		return D_0000A09C;
	ret = sceKernelStartThread(D_0000A09C, 0, 0);
	return (ret < 0) ? ret : 0;
}

void _sce_pspnet_callout_init(struct callout *c)
{
	c->c_fired.tqe_next = NULL;
	c->c_fired.tqe_prev = NULL;
	c->c_pending.tqe_next = NULL;
	c->c_pending.tqe_prev = NULL;
	c->c_func = NULL;
	c->c_arg = NULL;
	c->c_time = 0;
	c->c_flags = 0;
	c->c_alarm = 0;
}

void _sce_pspnet_callout_cleanup(struct callout *c)
{
}

void _sce_pspnet_callout_reset(struct callout *c, unsigned int ticks, void (*func)(void *), void *arg)
{
	if (ticks > 0x68DB8)
		return;
	if (ticks == 0)
		ticks = 1;
	_sce_pspnet_callout_reset_usec(c, ticks * 10000, func, arg);
}

int func_00002C74(SceSize args, void *argp)
{
	struct callout *c;
	void (*func)(void *);
	void *arg;
	int s, intr;

again:
	sceKernelWaitSema(D_0000A098, 1, 0);
	s = _sce_pspnet_spllock();
	for (;;) {
		intr = sceKernelCpuSuspendIntr();
		c = D_0000AC08.tqh_first;
		if (c == NULL)
			break;
		TAILQ_REMOVE(&D_0000AC08, c, c_fired);
		func = c->c_func;
		arg = c->c_arg;
		c->c_fired.tqe_next = NULL;
		c->c_fired.tqe_prev = NULL;
		c->c_func = NULL;
		c->c_flags &= ~2;
		sceKernelCpuResumeIntr(intr);
		func(arg);
	}
	sceKernelCpuResumeIntr(intr);
	_sce_pspnet_splunlock(s);
	goto again;
}

SceUInt func_00002D48(void *common)
{
	struct callout *c = common;

	TAILQ_INSERT_TAIL(&D_0000AC08, c, c_fired);
	TAILQ_REMOVE(&D_0000AC10, c, c_pending);
	sceKernelSignalSema(D_0000A098, 1);
	return 0;
}
