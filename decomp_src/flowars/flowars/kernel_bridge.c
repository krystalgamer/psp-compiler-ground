/* cflags: -O2 -frename-registers */
#include "common.h"

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
typedef int SceUID;

extern char *currentheap;
extern char *minheap;
extern char *maxheap;
extern int sce_newlib_heap_kb_size __attribute__((weak));
extern SceUID mbid;

int _open(const char *path, int flags, ...);
static __inline__ int _sys_open(const char *path, int flags);
off_t _lseek(int file, off_t offset, int dir);
static __inline__ int FileToUID(int fd);
static off_t _sys_lseek(int file, off_t offset, int dir);
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
void _exit(int status);
static void free_heap(void);
int _kill(pid_t pid, int sig);
pid_t _getpid(void);
pid_t _fork(void);
pid_t _wait(int *status);
int _execve(const char *filename, char *const *argv, char *const *envp);
clock_t clock(void);
time_t time(time_t *pTime);
int _gettimeofday(struct timeval *p, struct timezone *z);

int sceIoOpen(const char *file, int flags, int mode);
long long sceIoLseek(SceUID fd, long long offset, int whence);
int sceIoRead(SceUID fd, void *data, size_t size);
int sceIoWrite(SceUID fd, const void *data, size_t size);
int sceIoClose(SceUID fd);
int sceIoRename(const char *oldname, const char *newname);
int sceKernelStdin(void);
int sceKernelStdout(void);
int sceKernelStderr(void);
SceUID sceKernelAllocPartitionMemory(SceUID partitionid, const char *name, int type, size_t size, void *addr);
int sceKernelFreePartitionMemory(SceUID blockid);
void *sceKernelGetBlockHeadAddr(SceUID blockid);
int sceKernelSelfStopUnloadModule(int exitcode, size_t argsize, void *argp);
clock_t sceKernelLibcClock(void);
time_t sceKernelLibcTime(time_t *t);
int sceKernelLibcGettimeofday(struct timeval *tp, struct timezone *tzp);

static __inline__ int _sys_open(const char *path, int flags)
{
	return sceIoOpen(path, flags, 0644);
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

static __inline__ off_t _sys_lseek(int file, off_t offset, int dir)
{
	return sceIoLseek(FileToUID(file), offset, dir);
}

off_t _lseek(int file, off_t offset, int dir)
{
	int fd;
	int sdir;

	fd = FileToUID(file);
	if (fd < 0)
		return -9;
	switch (dir) {
	case 0:
		sdir = 0;
		break;
	case 1:
		sdir = 1;
		break;
	case 2:
		sdir = 2;
		break;
	default:
		sdir = dir;
		break;
	}
	return _sys_lseek(fd, offset, sdir);
}

void *_sbrk(ptrdiff_t incr)
{
	char *newheap;
	char *oldheap;

	if (minheap == 0) {
		int size = 0x10000;

		if (&sce_newlib_heap_kb_size != 0)
			size = sce_newlib_heap_kb_size << 10;
		if (size != 0) {
			mbid = sceKernelAllocPartitionMemory(2, "UserSbrk", 0, size, 0);
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

int _read(int file, void *ptr, size_t len)
{
	int fd = FileToUID(file);
	if (fd < 0)
		return -9;
	return sceIoRead(fd, ptr, len);
}

int _write(int file, const void *ptr, size_t len)
{
	int fd = FileToUID(file);
	if (fd < 0)
		return -9;
	return sceIoWrite(fd, ptr, len);
}

int _close(int file)
{
	int fd = FileToUID(file);
	if (fd < 0)
		return -9;
	return sceIoClose(fd);
}

int _fstat(int file, struct stat *st)
{
	st->st_mode = 0x2000;
	return 0;
}

int isatty(int file)
{
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

int _fcntl(int fd, int cmd)
{
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

static __inline__ void free_heap(void)
{
	if (mbid != 0) {
		sceKernelFreePartitionMemory(mbid);
		mbid = 0;
	}
}

void _exit(int status)
{
	free_heap();
	sceKernelSelfStopUnloadModule(1, 0, 0);
}

int _kill(pid_t pid, int sig)
{
	return -1;
}

pid_t _getpid(void)
{
	return -1;
}

pid_t _fork(void)
{
	return -1;
}

pid_t _wait(int *status)
{
	return -1;
}

int _execve(const char *filename, char *const *argv, char *const *envp)
{
	return -1;
}

clock_t clock(void)
{
	return sceKernelLibcClock();
}

time_t time(time_t *pTime)
{
	return sceKernelLibcTime(pTime);
}

int _gettimeofday(struct timeval *p, struct timezone *z)
{
	return sceKernelLibcGettimeofday(p, z);
}
