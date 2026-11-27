#include "common.h"

typedef int SceUID;
typedef unsigned int SceSize;
typedef long long SceOff;

int sceKernelStdin(void);
int sceKernelStdout(void);
int sceKernelStderr(void);
int sceIoRead(SceUID fd, void *data, SceSize size);
int sceIoWrite(SceUID fd, const void *data, SceSize size);
SceUID sceIoOpen(const char *file, int flags, int mode);
int sceIoClose(SceUID fd);
SceOff sceIoLseek(SceUID fd, SceOff offset, int whence);
int sceKernelExitThread(int status);
int sceKernelSelfStopUnloadModule(int exitcode, SceSize argsize, void *argp);
SceUID sceKernelAllocPartitionMemory(SceUID partitionid, const char *name, int type, SceSize size, void *addr);
int sceKernelFreePartitionMemory(SceUID blockid);
void *sceKernelGetBlockHeadAddr(SceUID blockid);
int sceKernelLibcClock(void);
int sceKernelLibcTime(int *t);
int sceKernelLibcGettimeofday(void *tp, void *tzp);

extern int sce_newlib_nocreate_thread_in_start __attribute__((weak));
extern int sce_newlib_heap_kb_size __attribute__((weak));

struct stat_ {
	short st_dev;
	unsigned short st_ino;
	unsigned int st_mode;
};

extern SceUID mbid;
extern unsigned int minheap;
extern unsigned int maxheap;
extern unsigned int currentheap;

void free_heap(void);

static __inline__ int conv_fd(int fd)
{
	switch (fd) {
	case 0:
		return sceKernelStdin();
	case 1:
		return sceKernelStdout();
	case 2:
		return sceKernelStderr();
	}
	return fd;
}

int _read(int fd, void *buf, unsigned int nbytes)
{
	fd = conv_fd(fd);
	if (fd < 0)
		return -9;
	return sceIoRead(fd, buf, nbytes);
}

int _write(int fd, const void *buf, unsigned int nbytes)
{
	fd = conv_fd(fd);
	if (fd < 0)
		return -9;
	return sceIoWrite(fd, buf, nbytes);
}

int _sys_open(name, flags, mode)
	const char *name;
	int flags;
	int mode;
{
	return sceIoOpen(name, flags, mode);
}

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

int _close(int fd)
{
	fd = conv_fd(fd);
	if (fd < 0)
		return -9;
	return sceIoClose(fd);
}

int _sys_lseek(int fd, int offset, int whence)
{
	return sceIoLseek(conv_fd(fd), offset, whence);
}

int _lseek(int fd, int offset, int whence)
{
	int pspwhence;

	fd = conv_fd(fd);
	if (fd < 0)
		return -9;
	switch (whence) {
	case 0:
		pspwhence = 0;
		break;
	case 1:
		pspwhence = 1;
		break;
	case 2:
		pspwhence = 2;
		break;
	default:
		pspwhence = whence;
		break;
	}
	return _sys_lseek(fd, offset, pspwhence);
}

int _fstat(int fd, struct stat_ *st)
{
	st->st_mode = 0x2000;
	return 0;
}

int isatty(int fd)
{
	return 1;
}

void _exit(int status)
{
	if (&sce_newlib_nocreate_thread_in_start != NULL) {
		if (status == 0)
			free_heap();
		sceKernelExitThread(status);
	} else {
		free_heap();
		sceKernelSelfStopUnloadModule(1, 0, NULL);
	}
}

int _kill(int pid, int sig)
{
	return -1;
}

int _getpid(void)
{
	return -1;
}

void free_heap(void)
{
	sceKernelFreePartitionMemory(mbid);
}

void *_sbrk(int incr)
{
	unsigned int result;
	unsigned int realsize;

	if (minheap == 0) {
		realsize = 64 * 1024;
		if (&sce_newlib_heap_kb_size != NULL)
			realsize = sce_newlib_heap_kb_size * 1024;
		mbid = sceKernelAllocPartitionMemory(2, "block", 0, realsize, NULL);
		if (mbid > 0) {
			minheap = currentheap = (unsigned int)sceKernelGetBlockHeadAddr(mbid);
			maxheap = currentheap + realsize;
		}
	}
	if (minheap != 0 && currentheap + incr >= minheap && currentheap + incr <= maxheap) {
		result = currentheap;
		currentheap += incr;
		return (void *)result;
	}
	return (void *)-1;
}

int _fork(void)
{
	return -1;
}

int _wait(int *status)
{
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
