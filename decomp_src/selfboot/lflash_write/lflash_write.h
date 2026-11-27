#ifndef LFLASH_WRITE_H
#define LFLASH_WRITE_H

#include "common.h"

typedef int SceUID;
typedef unsigned int SceSize;
typedef int SceMode;
typedef long long SceOff;

typedef struct ScePspDateTime {
	unsigned short year, month, day, hour, minute, second;
	unsigned int microsecond;
} ScePspDateTime;

typedef struct SceIoStat {
	SceMode st_mode;
	unsigned int st_attr;
	SceOff st_size;
	ScePspDateTime st_ctime;
	ScePspDateTime st_atime;
	ScePspDateTime st_mtime;
	unsigned int st_private[6];
} SceIoStat;

typedef struct SceIoDirent {
	SceIoStat d_stat;
	char d_name[256];
	void *d_private;
	int dummy;
} SceIoDirent;

int printf(const char *fmt, ...);
int putchar(int c);
int puts(const char *s);
char *strcat(char *d, const char *s);
char *strtok(char *s, const char *delim);
int strcmp(const char *a, const char *b);
char *strcpy(char *d, const char *s);
char *strncpy(char *d, const char *s, unsigned int n);
unsigned int strlen(const char *s);

SceUID sceIoOpen(const char *file, int flags, SceMode mode);
int sceIoClose(SceUID fd);
int sceIoRead(SceUID fd, void *data, SceSize size);
int sceIoWrite(SceUID fd, const void *data, SceSize size);
SceOff sceIoLseek(SceUID fd, SceOff offset, int whence);
SceUID sceIoDopen(const char *dirname);
int sceIoDread(SceUID fd, SceIoDirent *dir);
int sceIoDclose(SceUID fd);
int sceIoMkdir(const char *dir, SceMode mode);
int sceIoAssign(const char *dev1, const char *dev2, const char *dev3, int mode, void *unk1, long unk2);
int sceIoUnassign(const char *dev);
int ShellForKernel_9C3CFF4D(const char *name, const char *help, int (*func)(char *));
char *func_0000009C(char *buf, int size, SceUID fd);
int func_000001A8(const char *path);
char *func_000002FC(char *path);
int func_00000350(SceUID in, SceUID out);
int func_000003F0(SceUID fd1, SceUID fd2);
int func_00000000(char *str, char **argv, int max);
int func_000011A4(char *file);
int func_00001594(char *cmd);
int LflashFatfmt_B7A424A4(int argc, char **argv);

/* .rodata strings shared by functions that are still asm */
extern const char D_00005160[];	/* "sceIoRead 0x%08x\n" */
extern const char D_000051B4[];	/* "size1 0x%08x != 0x%08x size2\n" */
extern const char D_0000521C[];	/* "sceIoOpen 0x%08x\n" */
extern const char D_00005294[];	/* "argument error" */
extern const char D_000052A4[];	/* "%s " */
extern const char D_000052A8[];	/* "sceIoClose 0x%08x\n" */

/* .data */
extern char *D_000056E0[6];	/* "flash0".."flash5" */
extern char *D_000056F8[6];	/* "lflash0:0,0".. */
extern char *D_00005710[6];	/* "flash0:".. */
extern char *D_00005728[6];	/* "flashfat0:".. */
extern char *D_00005740[];	/* fatfmt argv: { "fatfmt", dev } */

#endif
