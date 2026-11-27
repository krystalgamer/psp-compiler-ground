/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
int consPrintf();
extern unsigned char D_000FA7FC;
extern unsigned char D_000FA818;
extern int D_00119150;
extern int UmdName_Alias;
extern signed char UmdVirtual;
extern int LogIdx;
extern int pLogBuf;

extern int UmdReady;
extern int UmdState;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", umdProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", umdPref);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sprintf(char *buf, const char *fmt, ...);
void *memset(void *s, int c, unsigned int n);

signed char *umdParamToVirtual(int arg0, int arg1) {
    if (arg1 == 0) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0xD9, "umdParamToVirtual", "Size != 0");
    }
    memset(&UmdVirtual, 0, 0x400U);
    sprintf(&UmdVirtual, "%s/sce_lbn0x%x_size0x%lx", UmdName_Alias, D_00119150 + (arg0 * 0x10), arg1);
    if (M2C_FIELD(&UmdVirtual, signed char *, 0x3FF) != 0) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0xE6, "umdParamToVirtual", "UmdVirtual[sizeof(UmdVirtual)-1] == 0");
    }
    return &UmdVirtual;
}

typedef struct { int mode, attr; long long size; char t[48]; unsigned int priv[6]; } UmdStat;
int sceIoGetstat(const char *, UmdStat *);
char *umdPref();
int umdNameToVirtual(char *name)
{
	UmdStat st;
	if (sceIoGetstat(umdPref(name), &st) != 0)
		return 0;
	return (int)umdParamToVirtual(st.priv[0], (int)st.size);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int umdReady(void) {
    int temp_v0;

    temp_v0 = UmdReady;
    UmdReady = UmdState;
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", umdDump);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", calcNumBcd);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", calcBcdNum);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", consInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAA78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAA94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAAA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAAAC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAAC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAACC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", consTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", consPrintf);

#ifndef NULL
#define NULL ((void *)0)
#endif

int consLog(unsigned int arg0) {
    int var_v1;

    var_v1 = 0;
    if ((pLogBuf != 0) & (arg0 < 0x10U)) {
        var_v1 = pLogBuf + (((LogIdx + arg0) & 0xF) << 6);
    }
    return var_v1;
}

int dencEncode(int a, int b, int c)
{
	return c;
}

int dencDecode(int a, int b, int c)
{
	return c;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAB04);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAB20);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", elmInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAB54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAB5C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", elmTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", elmCall);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", elmFree);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FABEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAC08);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", hdlInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAC3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAC44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAC5C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", hdlTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", hdlMake);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAC88);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", hdlFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", hdlPtr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", listInit);

#ifndef NULL
#define NULL ((void *)0)
#endif
int listTerm(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", listAddHead);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", listAddTail);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", memInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FACEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FACF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FACF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAD14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAD24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAD30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAD3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAD44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAD4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAD64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FAD7C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", memTerm);
