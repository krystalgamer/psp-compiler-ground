/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/socket", func_00000D3C);

void func_00000D84(void)
{
	struct adhoc_socket *so;

	_sce_pspnet_stop_of_adhoc_module_in_sched();
	while ((so = D_00007418.tqh_first) != NULL) {
		if (so->pcb == NULL) {
			TAILQ_REMOVE(&D_00007418, so, link);
			sceNetFreeInternal(so);
		}
	}
}

struct adhoc_socket *func_00000DFC(int type, int id)
{
	struct adhoc_socket *so;

	type &= 0xFF;
	for (so = D_00007418.tqh_first; so != NULL; so = so->link.tqe_next) {
		if ((type == 0 || so->type == type) && so->id == id)
			break;
	}
	return so;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/socket", func_00000E44);

int func_00000ED0(u_char type, struct adhoc_socket **sop)
{
	struct adhoc_socket *so;
	int ret;

	so = sceNetMallocInternal(sizeof(*so));
	ret = 0x80410001;
	if (so != NULL) {
		memset(so, 0, sizeof(*so));
		so->type = type;
		so->id = -1;
		TAILQ_INSERT_TAIL(&D_00007418, so, link);
		ret = 0;
		*sop = so;
	}
	return ret;
}

void func_00000F74(struct adhoc_socket *so)
{
	if (so->pcb == NULL) {
		TAILQ_REMOVE(&D_00007418, so, link);
		sceNetFreeInternal(so);
	}
}

int func_00000FBC(void)
{
	struct adhoc_socket *so;

	for (so = D_00007418.tqh_first; so != NULL; so = so->link.tqe_next) {
		if (so->pollq != NULL)
			return 1;
	}
	return 0;
}

void func_00000FF0(struct adhoc_socket *so, int events)
{
	struct thread_info *ti;

	for (ti = so->pollq; ti != NULL; ti = ti->pollnext) {
		if (ti->wchan != NULL) {
			if (((events & 0x210) && ti->wchan == so->wchan_send) ||
			    ((events & 0x1A0) && ti->wchan == so->wchan_recv) ||
			    ((events & 0x40) && ti->wchan == so->wchan_poll)) {
				ti->wchan = NULL;
				sceKernelSignalSema(ti->sema, 1);
			}
		}
	}
}
