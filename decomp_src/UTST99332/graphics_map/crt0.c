#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread.h>

extern int sce_newlib_nocreate_thread_in_start __attribute__((weak));
extern int sce_newlib_stack_kb_size __attribute__((weak));
extern int sce_newlib_priority __attribute__((weak));
extern unsigned int sce_newlib_attribute __attribute__((weak));

extern void _init(void);
extern void _fini(void);
int main(int argc, char *argv[]);
int atexit(void (*func)(void));
void exit(int status);

int _main(int args, char *argp)
{
	int rtn;
	char *argv[20];
	char *ap;
	int argc;
	struct _reent reent;
	struct _reent *reentp;

	reentp = &reent;
	argc = 0;
	ap = argp;
	while (argc < 20 && (ap - argp) < args) {
		argv[argc++] = ap;
		ap += strlen(ap) + 1;
	}
	argv[argc] = NULL;
	_REENT_INIT_PTR(reentp);
	__asm__ volatile ("sw %0, 4($26)" : : "r"(reentp));
	atexit(_fini);
	_init();
	rtn = main(argc, argv);
	exit(rtn);
}

#ifdef NON_MATCHING
/* the original swaps the registers holding &sce_newlib_priority and
 * &sce_newlib_attribute */
int _start(int args, char *argp)
{
	SceUID thid;
	int res;

	if (&sce_newlib_nocreate_thread_in_start != NULL) {
		_main(args, argp);
		return 1;
	}
	{
		unsigned int realsize;
		int priority;
		unsigned int attribute;

		realsize = (&sce_newlib_stack_kb_size != NULL) ? sce_newlib_stack_kb_size << 10 : 0x40000;
		priority = (&sce_newlib_priority != NULL) ? sce_newlib_priority : 0x20;
		attribute = (&sce_newlib_attribute != NULL) ? (sce_newlib_attribute | 0x80000000) : 0x80000000;
		thid = sceKernelCreateThread("user_main", (SceKernelThreadEntry)_main, priority, realsize, attribute, NULL);
		res = sceKernelStartThread(thid, args, argp);
	}
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/UTST99332/graphics_map/nonmatchings/crt0", _start);
#endif
