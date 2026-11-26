#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/kernel_bridge", _read);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/kernel_bridge", _write);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/kernel_bridge", _sys_open);

int _open(const char *path, int flags, ...)
{
	int sflags = 0;

	switch ((unsigned int)flags & 3) {
	case 0:
		sflags = 1;
		break;
	case 1:
		sflags = 2;
		break;
	case 2:
		sflags = 3;
		break;
	default:
		break;
	}
	if (flags & 0x0008) sflags |= 0x0100;
	if (flags & 0x0200) sflags |= 0x0200;
	if (flags & 0x0400) sflags |= 0x0400;
	if (flags & 0x0800) sflags |= 0x0800;
	if (flags & 0x4000) sflags |= 0x0004;
	return _sys_open(path, sflags);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/kernel_bridge", _close);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/kernel_bridge", _sys_lseek);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/kernel_bridge", _lseek);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/kernel_bridge", _fstat);

int isatty(int file)
{
	return 1;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/kernel_bridge", _exit);

int _kill(int pid, int sig) {
    return -1;
}

int _getpid(void) {
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/kernel_bridge", free_heap);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/kernel_bridge", _sbrk);

int _fork(void) {
    return -1;
}

int _wait(int *status) {
    return -1;
}

unsigned int clock(void) {
    return sceKernelLibcClock();
}

int time(int *pTime) {
    return sceKernelLibcTime();
}

int _gettimeofday(struct timeval *p, struct timezone *z)
{
	return sceKernelLibcGettimeofday(p, z);
}
