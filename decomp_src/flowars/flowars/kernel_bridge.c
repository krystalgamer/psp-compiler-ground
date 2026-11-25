#include "common.h"

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/kernel_bridge", _open);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/kernel_bridge", _lseek);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/kernel_bridge", _sbrk);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/kernel_bridge", _read);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/kernel_bridge", _write);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/kernel_bridge", _close);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/kernel_bridge", _fstat);

int isatty(int fd)
{
	return 1;
}

int _rename(signed char *oldpath, signed char *newpath) {
    return sceIoRename();
}

int _stat(signed char *file_name, struct stat *buf) {
    return -1;
}

int _fcntl(int fd, int cmd) {
    return -1;
}

int _link(signed char *oldpath, signed char *newpath) {
    return -1;
}

int _unlink(signed char *pathname) {
    return -1;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/kernel_bridge", _exit);

int _kill(int pid, int sig)
{
	return -1;
}

int _getpid(void)
{
	return -1;
}

int _fork(void)
{
	return -1;
}

int _wait(int *status)
{
	return -1;
}

int _execve(signed char *filename, signed char **argv, signed char **envp) {
    return -1;
}

int clock(void)
{
	return sceKernelLibcClock();
}

int time(int *t)
{
	return sceKernelLibcTime(t);
}

int _gettimeofday(void *tp, void *tzp)
{
	return sceKernelLibcGettimeofday(tp, tzp);
}
