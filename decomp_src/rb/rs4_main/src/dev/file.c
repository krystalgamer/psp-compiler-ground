/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK semaLock(int);                              /* extern */
extern int FileSema;
M2C_UNK semaUnlock(int);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9E44);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", fileTerm);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", filePath);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", D_000F9F64);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", fileReady);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", fileRead);

int fileReadPath(int a, int b)
{
	return fileRead(filePath(a), b);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/file", fileWrite);
