/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
int sceUmdActivate(M2C_UNK, int);                   /* extern */
extern unsigned char D_000FA7FC;
extern unsigned char D_000FA818;
extern unsigned char D_000FA870;
extern int UmdName_Alias;
extern int UmdStandby;
void consPrintf(const char *, ...);
extern unsigned char D_000FA7FC;
extern unsigned char D_000FA818;
extern int D_00119150;
extern int UmdName_Alias;
extern signed char UmdVirtual;

extern int UmdReady;
extern int UmdState;
int sprintf(char *buf, const char *fmt, ...);
void *memset(void *s, int c, unsigned int n);

typedef struct { int mode, attr; long long size; char t[48]; unsigned int priv[6]; } UmdStat;
int sceIoGetstat(const char *, UmdStat *);
char *umdPref();

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", umdInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA7E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA7F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA7FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA818);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA828);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA848);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA85C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA864);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA870);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA88C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA898);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", umdTerm);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA8A4);

void umdActive(void) {
    if ((UmdStandby == 1) && (sceUmdActivate(1, UmdName_Alias) != 0)) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0x8C, "umdActive", &D_000FA870);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", umdProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", umdPref);

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

int umdNameToVirtual(char *name)
{
	UmdStat st;
	if (sceIoGetstat(umdPref(name), &st) != 0)
		return 0;
	return (int)umdParamToVirtual(st.priv[0], (int)st.size);
}

int umdReady(void) {
    int temp_v0;

    temp_v0 = UmdReady;
    UmdReady = UmdState;
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", umdDump);
