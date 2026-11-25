#include "common.h"

typedef int SceBool;
typedef int SceUID;
typedef struct SceGimPicture SceGimPicture;
struct SceGimPicture;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef unsigned int size_t;
typedef long long int long64;
typedef long long unsigned int u_long64;
typedef struct SceRtcTick SceRtcTick;
struct SceRtcTick;
struct SceRtcTick { /* size 0x8 */
    u_long64 tick;
};
struct _anon1;
typedef char SceChar8;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;

extern StrFile strFile;
extern char ttybuf[1024];

int count_array(int *a, int a_size);
int find_array(int seed, int *a, int a_size);
int get_file_pointer(void);
SceBool load_file(const char *filename, int **buf, int *size);
SceGimPicture *load_image(const char *filename, ...);
void delete_image(SceGimPicture *picture);
int compact_array(int *a, int size);
void quick_sort(int *arr, int ilo, int ihi);
void *malloc16(size_t size);
void free16(void *addr);
void shuffle(int *buf, int size);
void ttyprintf2(char *tty, const char *str, ...);
void make_num_format(char *strOut, long64 num);
void activateUmd();
int evaluated_rand(int range, ...);
u_long64 get_tick();
void print_nothing();
void check_callback(SceUID callback);

#define va_start(v, l)	__builtin_stdarg_start((v), l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v, l)	__builtin_va_arg(v, l)
int sprintf(char *buf, const char *fmt, ...);
int vsprintf(char *buf, const char *fmt, va_list ap);
unsigned int strlen(const char *s);
char *strcpy(char *dst, const char *src);
void *memset(void *s, int c, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);
void free(void *p);
int rand(void);
int sceKernelGetGPI(void);
SceUID sceIoOpen(const char *name, int flag, int mode);
int sceIoClose(SceUID fd);
int sceIoWrite(SceUID fd, const void *buf, unsigned int nbyte);
int sceUmdActivate(int mode, const char *aliasname);
int sceUmdGetDriveStat(void);
int sceUmdWaitDriveStat(int stat);
int sceRtcGetCurrentTick(SceRtcTick *tick);
SceGimPicture *sceGimPictureCreate(void *option);
int sceGimPictureDelete(SceGimPicture *picture);
int sceGimPictureLoadFile(SceGimPicture *picture, void *data, int size, int flag);
int strFileAssign(const SceChar8 *filename);
int strFileUnassign(void);
int strFileOpen(StrFile *file, const SceChar8 *filename, int flags);
int strFileClose(StrFile *file);
int strFileRead(StrFile *file, void *buff, int size);
long long strFileLseek(StrFile *file, long long offset, int whence);

int count_array(int *a, int a_size)
{
	int i;

	for (i = 0; i < a_size && a[i] != 0; i++)
		;
	return i;
}

int find_array(int seed, int *a, int a_size)
{
	int i;

	for (i = 0; i < a_size; i++)
		if (a[i] == seed)
			return i;
	return -1;
}

int get_file_pointer(void)
{
	return 0;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", load_file);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/utils", D_0002F57C);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", load_image);

void delete_image(SceGimPicture *picture)
{
	if (picture)
		sceGimPictureDelete(picture);
}

int compact_array(int *a, int size)
{
	int index;
	int c;
	int pos;
	int buff[52];

	memset(buff, 0, sizeof(buff));
	pos = 0;
	for (index = 0; index < size; index++) {
		c = a[index];
		if (c != 0)
			buff[pos++] = c;
	}
	memset(a, 0, size);
	memcpy(a, buff, size * 4);
	return pos;
}

void quick_sort(int *arr, int ilo, int ihi)
{
	int pivot;
	int ulo;
	int uhi;
	int ieq;
	int tempEntry;

	if (ilo >= ihi)
		return;
	pivot = arr[(ilo + ihi) / 2];
	ieq = ulo = ilo;
	uhi = ihi;
	while (ulo <= uhi) {
		if (arr[uhi] > pivot) {
			uhi--;
		} else {
			tempEntry = arr[ulo];
			arr[ulo] = arr[uhi];
			arr[uhi] = tempEntry;
			if (arr[ulo] < pivot) {
				tempEntry = arr[ieq];
				arr[ieq] = arr[ulo];
				arr[ulo] = tempEntry;
				ieq++;
			}
			ulo++;
		}
	}
	quick_sort(arr, ilo, ieq - 1);
	quick_sort(arr, uhi + 1, ihi);
}

void *malloc16(unsigned int size) {
    return memalign(0x10, size);
}

void free16(void *addr) {
    free(addr);
}

void shuffle(int *buf, int size)
{
	int index;
	int pos;
	int temp;

	for (index = 0; index < size; index++) {
		pos = rand() % size;
		temp = buf[index];
		buf[index] = buf[pos];
		buf[pos] = temp;
	}
}

void ttyprintf2(char *tty, const char *str, ...)
{
	int fd;
	va_list argptr;

	fd = sceIoOpen(tty, 0x102, 0x777);
	if (fd < 0) {
		print_nothing("fd open failed:%x\n", fd);
		return;
	}
	va_start(argptr, str);
	vsprintf(ttybuf, str, argptr);
	va_end(argptr);
	sceIoWrite(fd, ttybuf, strlen(ttybuf));
	sceIoClose(fd);
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", make_num_format);

void activateUmd()
{
	sceUmdActivate(1, "disc0:");
	while (!(sceUmdGetDriveStat() & 0x20)) {
		print_nothing("*** umd unreadable wait\n");
		sceUmdWaitDriveStat(0x20);
	}
	print_nothing("*** umd readable\n");
}

int evaluated_rand(int range, ...)
{
	int arg;
	int cnt;
	int sum;
	int rate[20];
	int randVal;
	int i;
	va_list argptr;

	va_start(argptr, range);
	sum = 0;
	for (i = 0; i < 20; i++) {
		if (i < range) {
			arg = va_arg(argptr, int);
			rate[i] = arg;
			sum += arg;
		} else {
			rate[i] = 0;
		}
	}
	va_end(argptr);
	randVal = rand() % sum;
	sum = 0;
	for (cnt = 0; cnt < range; cnt++) {
		sum += rate[cnt];
		if (randVal < sum)
			return cnt;
	}
	return -1;
}

u_long64 get_tick()
{
	SceRtcTick newTime;

	sceRtcGetCurrentTick(&newTime);
	return newTime.tick;
}

void print_nothing()
{
}

void check_callback(SceUID callback)
{
}
