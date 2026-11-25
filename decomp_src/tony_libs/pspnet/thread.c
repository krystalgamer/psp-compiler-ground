/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"
/* --- end declarations --- */

struct thread_info *_sce_pspnet_thread_enter(void)
{
	SceUID thid = sceKernelGetThreadId();
	struct thread_info *ti;

	sceKernelWaitSema(D_0000A094, 1, 0);
	for (ti = D_0000AC00.tqh_first; ti != NULL; ti = ti->link.tqe_next) {
		if (ti->thid == thid)
			break;
	}
	if (ti == NULL) {
		ti = sceNetMallocInternal(sizeof(*ti));
		if (ti == NULL)
			goto fail;
		memset(ti, 0, sizeof(*ti));
		TAILQ_INSERT_TAIL(&D_0000AC00, ti, link);
		ti->thid = thid;
	}
	if (ti->semacnt == 0) {
		ti->sema = sceKernelCreateSema("SceNetThreadInfo", 0, 0, 1, 0);
		if (ti->sema < 0) {
			ti->error = 0x2E;
			goto fail;
		}
	}
	ti->semacnt++;
	ti->refcnt++;
	ti->error = 0;
	sceKernelSignalSema(D_0000A094, 1);
	return ti;
fail:
	sceKernelSignalSema(D_0000A094, 1);
	return NULL;
}

int sceNetFreeThreadinfo(SceUID thid)
{
	struct thread_info *ti;
	int ret = 0;

	sceKernelWaitSema(D_0000A094, 1, 0);
	for (ti = D_0000AC00.tqh_first; ti != NULL; ti = ti->link.tqe_next) {
		if (ti->thid == thid)
			break;
	}
	if (ti == NULL)
		ret = 0x80410104;
	else if (ti->refcnt > 0)
		ret = 0x80410105;
	else {
		TAILQ_REMOVE(&D_0000AC00, ti, link);
		_sce_pspnet_callout_cleanup(&ti->co);
		sceNetFreeInternal(ti);
	}
	sceKernelSignalSema(D_0000A094, 1);
	return ret;
}

int func_00001F0C(void)
{
	int ret;

	TAILQ_INIT(&D_0000AC00);
	ret = sceKernelCreateSema("SceNetThreadList", 0, 1, 1, 0);
	D_0000A094 = ret;
	return (ret < 0) ? ret : 0;
}

struct thread_info *_sce_pspnet_get_threadinfo(SceUID thid)
{
	struct thread_info *ti;

	sceKernelWaitSema(D_0000A094, 1, 0);
	for (ti = D_0000AC00.tqh_first; ti != NULL; ti = ti->link.tqe_next) {
		if (ti->thid == thid)
			break;
	}
	sceKernelSignalSema(D_0000A094, 1);
	return ti;
}

struct thread_info *_sce_pspnet_lock_threadinfo(SceUID thid)
{
	return threadinfo_lock(thid);
}

void _sce_pspnet_unlock_threadinfo(struct thread_info *ti)
{
	threadinfo_unlock(ti);
}

int _sce_pspnet_thread_leave(struct thread_info *ti, int error)
{
	return thread_leave(ti, error);
}

int _sce_pspnet_get_thread_errno(void)
{
	SceUID thid = sceKernelGetThreadId();
	struct thread_info *ti;

	sceKernelWaitSema(D_0000A094, 1, 0);
	for (ti = D_0000AC00.tqh_first; ti != NULL; ti = ti->link.tqe_next) {
		if (ti->thid == thid)
			break;
	}
	sceKernelSignalSema(D_0000A094, 1);
	if (ti == NULL)
		return 0x80410001;
	return ti->error;
}

int _sce_pspnet_set_thread_errno(int error)
{
	SceUID thid = sceKernelGetThreadId();
	struct thread_info *ti;

	sceKernelWaitSema(D_0000A094, 1, 0);
	for (ti = D_0000AC00.tqh_first; ti != NULL; ti = ti->link.tqe_next) {
		if (ti->thid == thid)
			break;
	}
	sceKernelSignalSema(D_0000A094, 1);
	if (ti == NULL)
		return 0x80410001;
	ti->error = error;
	return 0;
}

int _sce_pspnet_thread_busycount(void)
{
	struct thread_info *ti;
	int n = 0;

	sceKernelWaitSema(D_0000A094, 1, 0);
	for (ti = D_0000AC00.tqh_first; ti != NULL; ti = ti->link.tqe_next) {
		if (ti->refcnt > 0)
			n++;
	}
	sceKernelSignalSema(D_0000A094, 1);
	return n ? 0x80410105 : 0;
}

void func_00002300(void)
{
	if (D_0000A094 >= 0)
		sceKernelDeleteSema(D_0000A094);
	D_0000A094 = -1;
}

int sceNetThreadAbort(SceUID thid)
{
	struct thread_info *self;
	struct thread_info *ti;
	int ret = 0;
	int error = 0;

	self = _sce_pspnet_thread_enter();
	if (self == NULL)
		return 0x80410001;
	ti = threadinfo_lock(thid);
	if (ti == NULL) {
		error = 2;
		ret = 0x80410104;
	} else {
		_sce_pspnet_tabort(ti);
		threadinfo_unlock(ti);
	}
	thread_leave(self, error);
	return ret;
}
