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
extern int sce_newlib_heap_kb_size;
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


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/kernel_bridge", _open);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/kernel_bridge", _lseek);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/kernel_bridge", _exit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/kernel_bridge", sce_newlib_stop_func);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/kernel_bridge", _sbrk);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/kernel_bridge", _read);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/kernel_bridge", _write);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/kernel_bridge", _close);

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
