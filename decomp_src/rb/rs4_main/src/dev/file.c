/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
signed char *filePref(int);                                  /* extern */
extern signed char D_000F9E68;
extern unsigned char D_000F9E84;

M2C_UNK semaLock(int);                              /* extern */
extern int FileSema;
M2C_UNK semaUnlock(int);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E44);

void consPrintf(const char *fmt, ...);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", fileInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E84);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9EB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9ED8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9EE8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9EEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9EF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9F04);

extern unsigned char D_000F9E54, D_000F9F04;
int semaTerm(int);
int fileTerm(void)
{
	int ret, s = -1;
	consPrintf(&D_000F9E54, "fileTerm");
	ret = semaTerm(FileSema);
	if (ret != 1)
		consPrintf(&D_000F9E68, &D_000F9E84, 0xAC, "fileTerm", "Ret == TRUE");
	FileSema = s;
	consPrintf(&D_000F9F04);
	return 1;
}

void fileLock(void) {
    if (FileSema > 0) {
        semaLock(FileSema);
    }
}

void fileUnlock(void) {
    if (FileSema > 0) {
        semaUnlock(FileSema);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", filePref);

extern unsigned char D_000F9F64;
extern int FileHost;
signed char *umdPref(int);
signed char *msPref(int);
signed char *filePath(int path)
{
	switch (FileHost) {
	case 0:
		return filePref(path);
	case 1:
		return umdPref(path);
	case 2:
		return msPref(path);
	}
	consPrintf(&D_000F9E68, &D_000F9E84, 0xE9, "filePath", &D_000F9F64);
	return NULL;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9F64);

int sceKernelCheckCallback(void);
int umdReady(void);
int msReady(void);
extern unsigned char D_000F9F64;
int fileReady(void)
{
	if (sceKernelCheckCallback() == 0x80020064)
		consPrintf(&D_000F9E68, &D_000F9E84, 0x100, "fileReady", "Ret != SCE_KERNEL_ERROR_ILLEGAL_CONTEXT");
	switch (FileHost) {
	case 0:
		return 1;
	case 1:
		return umdReady();
	case 2:
		return msReady();
	default:
		consPrintf(&D_000F9E68, &D_000F9E84, 0x104, "fileReady", &D_000F9F64);
		return 0;
	}
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", fileRead);

int fileReadPath(int a, int b)
{
	return fileRead(filePath(a), b);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceKernelDcacheWritebackAll(void);
int sceIoOpen(const char *name, int flag, int mode);
int sceIoClose(int fd);
int sceIoWrite(int fd, const void *buf, unsigned int nbyte);

int fileWrite(int arg0, void *arg1, unsigned int arg2) {
    int temp_v0_2;
    int temp_v0_3;
    signed char *temp_v0;

    fileLock();
    temp_v0 = filePref(arg0);
    temp_v0_2 = sceIoOpen(temp_v0, 0x202, 0);
    if (temp_v0_2 < 0) {
        consPrintf("fd : %x %s\n", temp_v0_2, temp_v0);
        consPrintf(&D_000F9E68, &D_000F9E84, 0x1FB, "fileWrite", "fd >= 0");
    }
    sceKernelDcacheWritebackAll();
    temp_v0_3 = sceIoWrite(temp_v0_2, arg1, arg2);
    if (temp_v0_3 != arg2) {
        consPrintf(&D_000F9E68, &D_000F9E84, 0x204, "fileWrite", "Size == Len");
    }
    if (sceIoClose(temp_v0_2) != 0) {
        consPrintf(&D_000F9E68, &D_000F9E84, 0x208, "fileWrite", "ret == SCE_KERNEL_ERROR_OK");
    }
    consPrintf("%p : 0x%08x : %s\n", arg1, temp_v0_3, temp_v0);
    fileUnlock();
    return 1;
}
