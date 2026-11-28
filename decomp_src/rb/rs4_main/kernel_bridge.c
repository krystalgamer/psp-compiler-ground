/* SDK crt0 kernel_bridge.o: its Makefile builds with -O4 (= -O3) */
/* cflags: -O3 */
#include "common.h"

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
int isatty(int file);
int _rename(const char *oldpath, const char *newpath);
int _stat(const char *file_name, struct stat *buf);
int _fcntl(int fd, int cmd);
int _link(const char *oldpath, const char *newpath);
int _unlink(const char *pathname);
int _kill(pid_t pid, int sig);
pid_t _getpid(void);
pid_t _fork(void);
pid_t _wait(int *status);
int _execve(const char *filename, char *const *argv, char *const *envp);
void __free_heap(void);
clock_t clock(void);
time_t time(time_t *pTime);
int _gettimeofday(struct timeval *p, struct timezone *z);
clock_t _times(struct tms *buf);
int sigfillset(sigset_t *set);
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);


SceUID sceKernelStdin(void);
SceUID sceKernelStdout(void);
SceUID sceKernelStderr(void);
int sceIoClose(SceUID fd);
int sceIoRead(SceUID fd, void *data, unsigned int size);
int sceIoWrite(SceUID fd, const void *data, unsigned int size);
static inline int FileToUID(int fd)
{
	switch(fd) {
		case 0:
			return sceKernelStdin();
		case 1:
			return sceKernelStdout();
		case 2:
			return sceKernelStderr();
		default:
			return fd;
	}
}

SceUID sceIoOpen(const char *file, int flags, int mode);
static int _sys_open (const char *path, int flags)
{
	return sceIoOpen(path, flags, 0644);
}
int _open (const char *path, int flags, ...)
{
	int result;
	int newflags = 0;

	switch((unsigned int) flags & 0x00000003) {
		case 0:	newflags = 0x0001;	break;
		case 1:	newflags = 0x0002;	break;
		case 2:	newflags = 0x0003;	break;
		default:		break;
	}
	if (flags & 0x0008) {
		newflags |= 0x0100;
	}
	if (flags & 0x0200) {
		newflags |= 0x0200;
	}
	if (flags & 0x0400) {
		newflags |= 0x0400;
	}
	if (flags & 0x0800) {
		newflags |= 0x0800;
	}
	if (flags & 0x4000) {
		newflags |= 0x0004;
	}

	result = _sys_open(path, newflags);
	return result;
}

long long sceIoLseek(SceUID fd, long long offset, int whence);
static off_t _sys_lseek (int file, off_t offset, int dir)
{
	return sceIoLseek(FileToUID(file), (long long int) offset, dir);
}
/* not deferred in the original (-O4): kept in place */
off_t _lseek (int file, off_t offset, int dir) __attribute__((noinline));
off_t _lseek (int file, off_t offset, int dir)

{
	off_t result;
	int newdir;
	int fd = FileToUID(file);

	if (fd < 0) {
		return -9;
	}
	switch(dir) {
		case 0:	newdir = 0;	break;
		case 1:	newdir = 1;	break;
		case 2:	newdir = 2;	break;
		default:		newdir = dir;			break;
	}

	result = _sys_lseek(fd, offset, newdir);
	return result;
}

struct _reent;
struct _reent *__getreent(void);
void _reclaim_reent(struct _reent *);
int sceKernelPrintf(const char *fmt, ...);
int sceKernelExitThread(int status);
SceUID sceKernelGetModuleId(void);
int sceKernelStopModule(SceUID modid, unsigned int args, void *argp, int *status, void *option);
int sceKernelUnloadModule(SceUID modid);
int sceKernelStopUnloadSelfModuleWithStatus(int exitcode, unsigned int args, void *argp, int *status, void *option);
extern struct _reent *_getmodreent(void) __attribute__((weak));
extern int _clrmodreent(struct _reent *) __attribute__((weak));

/* process (this revision has no "something wrong" report and break after the final call) */
void _exit(int status) __attribute__((noinline));
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

	sceKernelStopUnloadSelfModuleWithStatus(1 /* NO_RESIDENT */, 0, NULL, NULL, NULL);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/kernel_bridge", sce_newlib_stop_func);

SceUID sceKernelAllocPartitionMemory(SceUID partitionid, const char *name, int type, unsigned int size, void *addr);
void *sceKernelGetBlockHeadAddr(SceUID blockid);
void *_sbrk (ptrdiff_t incr)
{
	void *result;
	unsigned int realsize;

	if ( minheap == NULL ) {
		if (&sce_newlib_heap_kb_size == NULL) {
			realsize = 64*1024;
		} else if (sce_newlib_heap_kb_size == 0) {
			return (void *)-1;
		} else {
			realsize = sce_newlib_heap_kb_size*1024;
		}
		if (realsize > 0) {
			mbid = sceKernelAllocPartitionMemory(2,
												"UserSbrk",
												3,
												realsize, (void *)4096);
			if ( mbid > 0 ) {
				minheap = currentheap = sceKernelGetBlockHeadAddr(mbid);
				maxheap = currentheap + realsize;
			}
		}
	}
	if ( minheap != NULL
		&& ((currentheap+incr) >= minheap)
		&& ((currentheap+incr) <= maxheap) ) {
		result = currentheap;
		currentheap += incr;
		return result;
	} else {
		return (void *)-1;
	}
}

int _read (int file, void *ptr, size_t len)
{
	int fd = FileToUID(file);

	if (fd < 0) {
		return -9;
	} else {
		return sceIoRead(fd, ptr, len);
	}
}

int _write (int file, const void *ptr, size_t len)
{
	int fd = FileToUID(file);

	if (fd < 0) {
		return -9;
	} else {
		return sceIoWrite(fd, ptr, len);
	}
}

int _close (int file)
{
	int fd = FileToUID(file);

	if (fd < 0) {
		return -9;
	} else {
		return sceIoClose(fd);
	}
}

int _fstat(int file, struct stat *st)
{
	st->st_mode = 0x2000;
	return 0;
}

int isatty(int file) {
    return 1;
}

int _rename(const char *oldpath, const char *newpath)
{
	return sceIoRename(oldpath, newpath);
}

int _stat(const char *file_name, struct stat *buf)
{
	return -1;
}

int _fcntl(int fd, int cmd) {
    return -1;
}

int _link(const char *oldpath, const char *newpath)
{
	return -1;
}

int _unlink(const char *pathname)
{
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

int _execve(const char *filename, char *const *argv, char *const *envp)
{
	return -1;
}

int sceKernelFreePartitionMemory(SceUID);
void __free_heap(void)
{
	if (mbid != 0) {
		sceKernelFreePartitionMemory(mbid);
		mbid = 0;
	}
}

clock_t clock(void)
{
	return sceKernelLibcClock();
}

time_t time(time_t *pTime)
{
	return sceKernelLibcTime(pTime);
}

int _gettimeofday(struct timeval *p, struct timezone *z) {
    return sceKernelLibcGettimeofday();
}

clock_t _times(struct tms *buf)
{
	return -1;
}

int sigfillset(sigset_t *set)
{
	*set = ~0;
	return 0;
}

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
	return -1;
}
