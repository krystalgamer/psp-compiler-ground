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

int _start(int args, char *argp)
{
	SceUID thid;
	int res;

	if (&sce_newlib_nocreate_thread_in_start == NULL) {
		unsigned int realsize;
		int priority;
		unsigned int attribute;

		if (&sce_newlib_stack_kb_size != NULL)
			realsize = sce_newlib_stack_kb_size << 10;
		else
			realsize = 0x40000;
		if (&sce_newlib_priority != NULL)
			priority = sce_newlib_priority;
		else
			priority = 0x20;
		if (&sce_newlib_attribute != NULL)
			attribute = sce_newlib_attribute | 0x80000000;
		else
			attribute = 0x80000000;
		thid = sceKernelCreateThread("user_main", (SceKernelThreadEntry)_main, priority, realsize, attribute, NULL);
		res = sceKernelStartThread(thid, args, argp);
		return 0;
	}
	_main(args, argp);
	return 1;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DA40);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DA54);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DA64);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DA78);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DA88);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DA98);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DAA8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DAB8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DAC8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DAD8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DAE8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DAF8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DB08);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DB18);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/crt0", D_0002DB28);

