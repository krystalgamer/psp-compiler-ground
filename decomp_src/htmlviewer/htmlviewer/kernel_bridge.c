#include "common.h"
/* cflags: -O2 -frename-registers */

/* declarations recovered from DWARF */
typedef long int off_t;
typedef int ptrdiff_t;
typedef unsigned int size_t;
struct stat;
typedef short int dev_t;
typedef short unsigned int ino_t;
typedef unsigned int mode_t;
typedef short unsigned int nlink_t;
typedef short unsigned int uid_t;
typedef short unsigned int gid_t;
typedef long int time_t;
struct stat { /* size 0x3c */
    dev_t st_dev;
    ino_t st_ino;
    mode_t st_mode;
    nlink_t st_nlink;
    uid_t st_uid;
    gid_t st_gid;
    dev_t st_rdev;
    off_t st_size;
    time_t st_atime;
    long int st_spare1;
    time_t st_mtime;
    long int st_spare2;
    time_t st_ctime;
    long int st_spare3;
    long int st_blksize;
    long int st_blocks;
    long int st_spare4[2];
};
typedef int pid_t;
typedef long unsigned int clock_t;
struct timeval;
struct timeval { /* size 0x8 */
    long int tv_sec;
    long int tv_usec;
};
struct timezone;
struct timezone { /* size 0x8 */
    int tz_minuteswest;
    int tz_dsttime;
};
struct tms;
typedef int sigset_t;
typedef int SceUID;

extern char *currentheap;
extern char *minheap;
extern char *maxheap;
extern int sce_newlib_heap_kb_size __attribute__((weak));
extern SceUID mbid;
extern void (*const sce_newlib_stop_func)(void);

int _open(const char *path, int flags, ...);
static int _sys_open(const char *path, int flags);
off_t _lseek(int file, off_t offset, int dir);
static int FileToUID(int fd);
static off_t _sys_lseek(int file, off_t offset, int dir);
void _exit(int status);
void *_sbrk(ptrdiff_t incr);
int _read(int file, void *ptr, size_t len);
int _write(int file, const void *ptr, size_t len);
int _close(int file);
int _fstat(int file, struct stat *st);
void __free_heap(void);
int sigfillset(sigset_t *set);


static __inline__ int _sys_open(const char *path, int flags)
{
	return sceIoOpen(path, flags, 0644);
}
static __inline__ int FileToUID(int fd)
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
long long sceIoLseek(SceUID fd, long long offset, int whence);
static __inline__ off_t _sys_lseek(int file, off_t offset, int dir)
{
	return sceIoLseek(FileToUID(file), offset, dir);
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

off_t _lseek(int file, off_t offset, int dir)
{
	off_t result;
	int newdir;
	int fd = FileToUID(file);

	if (fd < 0) {
		return -9;
	}
	switch (dir) {
	case 0: newdir = 0; break;
	case 1: newdir = 1; break;
	case 2: newdir = 2; break;
	default: newdir = dir; break;
	}

	result = _sys_lseek(fd, offset, newdir);
	return result;
}

struct _reent;
extern struct _reent *_getmodreent(void) __attribute__((weak));
extern int _clrmodreent(struct _reent *) __attribute__((weak));
struct _reent *__getreent(void);
void _reclaim_reent(struct _reent *);
int sceKernelPrintf(const char *fmt, ...);
int sceKernelExitThread(int status);
int sceKernelGetModuleId(void);
int sceKernelStopModule(SceUID modid, unsigned int argsize, void *argp, int *status, void *option);
int sceKernelUnloadModule(SceUID modid);
int sceKernelSelfStopUnloadModule(int exitcode, unsigned int argsize, void *argp);
void _exit(int status)
{
	int rtn;
	struct _reent *ptr;
	int mid;

	if (_getmodreent) {
		ptr = _getmodreent();

		if (ptr != __getreent()) {
			sceKernelPrintf("libc:%s: should be called from main thread\n",
					__FUNCTION__);
			sceKernelExitThread(status);
		}

		_reclaim_reent(ptr);
		mid = _clrmodreent(ptr);

		if (sceKernelGetModuleId() != mid) {
			sceKernelStopModule(mid, 0, NULL, &rtn, NULL);
			sceKernelUnloadModule(mid);
			sceKernelExitThread(status);
		}
	}

	sceKernelSelfStopUnloadModule(1, 0, NULL);
}

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/kernel_bridge", sce_newlib_stop_func);

void *_sbrk(ptrdiff_t incr)
{
	char *newheap;
	char *oldheap;

	if (minheap == 0) {
		int size;

		if (&sce_newlib_heap_kb_size == 0 || sce_newlib_heap_kb_size == 0)
			size = 0x10000;
		else
			size = sce_newlib_heap_kb_size << 10;
		if (size != 0) {
			mbid = sceKernelAllocPartitionMemory(2, "UserSbrk", 3, size, (void *)0x1000);
			if (mbid > 0) {
				char *head = sceKernelGetBlockHeadAddr(mbid);
				maxheap = head + size;
				currentheap = head;
				minheap = head;
			}
		}
	}
	if (minheap != 0) {
		newheap = currentheap + incr;
		if (newheap >= minheap && newheap <= maxheap) {
			oldheap = currentheap;
			currentheap = newheap;
			return oldheap;
		}
	}
	return (void *)-1;
}

int sceIoRead(int fd, void *buf, unsigned int nbyte);
int _read(int file, void *ptr, size_t len)
{
	int fd = FileToUID(file);
	if (fd < 0)
		return -9;
	return sceIoRead(fd, ptr, len);
}

int sceIoWrite(int fd, const void *buf, unsigned int nbyte);
int _write(int file, const void *ptr, size_t len)
{
	int fd = FileToUID(file);
	if (fd < 0)
		return -9;
	return sceIoWrite(fd, ptr, len);
}

int sceIoClose(int fd);
int _close(int file)
{
	int fd = FileToUID(file);
	if (fd < 0)
		return -9;
	return sceIoClose(fd);
}

int _fstat(int file, struct stat *st) {
    st->st_mode = 0x2000;
    return 0;
}

int isatty(int file) {
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

int _kill(int pid, int sig) {
    return -1;
}

int _getpid(void) {
    return -1;
}

int _fork(void) {
    return -1;
}

int _wait(int *status) {
    return -1;
}

int _execve(signed char *filename, signed char **argv, signed char **envp) {
    return -1;
}

void __free_heap(void) {
    if (mbid != 0) {
        sceKernelFreePartitionMemory(mbid);
        mbid = 0;
    }
}

unsigned int clock(void) {
    return sceKernelLibcClock();
}

int time(int *pTime) {
    return sceKernelLibcTime();
}

int _gettimeofday(struct timeval *p, struct timezone *z) {
    return sceKernelLibcGettimeofday();
}

unsigned int _times(struct tms *buf) {
    return -1U;
}
/* Warning: struct tms is not defined (only forward-declared) */

int sigfillset(sigset_t *set) {
    *set = -1;
    return 0;
}

int sigprocmask(int how, int *set, int *oldset) {
    return -1;
}
