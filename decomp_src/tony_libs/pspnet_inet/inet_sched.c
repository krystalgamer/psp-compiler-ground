/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

int
func_00001D50(void)
{
	return _sce_pspnet_start_of_inet_module_in_sched(func_00001D94, func_00001DD8);
}

void
func_00001D78(void)
{
	_sce_pspnet_stop_of_inet_module_in_sched();
}

void
func_00001D94(struct thread_info *ti)
{
	struct socket *so;

	for (so = ti->socks; so; so = so->so_tnext) {
		if (so->so_state & SS_ISDISCONNECTED) {
			so->so_state &= ~SS_ISDISCONNECTED;
			ti->slpflags |= 2;
		}
	}
}

void
func_00001DD8(struct socket *so)
{
	struct thread_info *ti = so->so_thread;

	if (ti && ti->wchan) {
		ti->wchan = NULL;
		ti->slpflags |= 2;
		sceKernelSignalSema(ti->sema, 1);
	} else
		so->so_state |= SS_ISDISCONNECTED;
}
