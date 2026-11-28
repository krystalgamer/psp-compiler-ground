/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK semaLock(int);                              /* extern */
extern int SemaMod;
typedef struct { const char *name; int a, b; int uid; } ModEnt;
extern ModEnt ModTbl[3];
extern int NetTbl[2];
extern unsigned char D_000FA3A4, D_000FA3C0, D_000FA398, D_000FA3DC, D_000FA404, D_000FA42C, D_000FA45C, D_000FA484;
M2C_UNK semaUnlock(int);

void consPrintf(const char *fmt, ...);
void fileLock(void);
void fileUnlock(void);
extern unsigned char D_000FA3A0, D_000FA3D0;
int sceUtilityLoadNetModule(int module);
int sceUtilityLoadAvModule(int module);
int semaInit(const void *name);
char *filePath(const char *path);
int modLoad(int path);
int modInit(void)
{
	int n;
	unsigned int i;
	ModEnt *p;

	consPrintf(&D_000FA398, "modInit");
	SemaMod = semaInit(&D_000FA3A0);
	if (SemaMod <= 0)
		consPrintf(&D_000FA3A4, &D_000FA3C0, 0x50, "modInit", &D_000FA3D0);
	consPrintf(&D_000FA3DC, sceUtilityLoadAvModule(0));
	consPrintf(&D_000FA404, sceUtilityLoadAvModule(1));
	consPrintf(&D_000FA42C, sceUtilityLoadAvModule(2));
	consPrintf(&D_000FA45C, sceUtilityLoadAvModule(3));
	p = ModTbl;
	for (n = 3; n != 0; n--) {
		p->uid = modLoad((int)filePath(p->name));
		p++;
	}
	for (i = 0; i < 2; i++)
		while (sceUtilityLoadNetModule(NetTbl[i]) != 0)
			sceKernelDelayThreadCB(1000);
	consPrintf(&D_000FA484);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA398);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA404);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA42C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA45C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA484);

int sceUtilityUnloadNetModule(int module);
int sceUtilityUnloadAvModule(int module);
int sceKernelDelayThreadCB(unsigned int usec);
int semaTerm(int sema);
int modUnload(int uid);
int modTerm(void)
{
	int i, n;
	ModEnt *p;

	consPrintf(&D_000FA398, "modTerm");
	for (i = 1; i >= 0; i--)
		while (sceUtilityUnloadNetModule(NetTbl[i]) != 0)
			sceKernelDelayThreadCB(1000);
	p = &ModTbl[2];
	for (n = 3; n != 0; n--) {
		modUnload(p->uid);
		p--;
	}
	consPrintf(&D_000FA45C, sceUtilityUnloadAvModule(3));
	consPrintf(&D_000FA42C, sceUtilityUnloadAvModule(2));
	consPrintf(&D_000FA404, sceUtilityUnloadAvModule(1));
	consPrintf(&D_000FA3DC, sceUtilityUnloadAvModule(0));
	if (semaTerm(SemaMod) != 1)
		consPrintf(&D_000FA3A4, &D_000FA3C0, 0xA4, "modTerm", "Ret == TRUE");
	SemaMod = -1;
	consPrintf(&D_000FA484);
	return 1;
}

void modLock(void) {
    if (SemaMod > 0) {
        semaLock(SemaMod);
    }
}

void modUnlock(void) {
    if (SemaMod > 0) {
        semaUnlock(SemaMod);
    }
}

int fileReady();                                    /* extern */
int sceKernelLoadModule(int, M2C_UNK, M2C_UNK);     /* extern */
int sceKernelStartModule(int, M2C_UNK, M2C_UNK, M2C_UNK *, void *); /* extern */
extern unsigned char D_000FA3A4;
extern unsigned char D_000FA3C0;
extern unsigned char D_000FA4C8;

int modLoad(int arg0) {
    int sp20;
    int opt[5];
    M2C_UNK *temp_v0;
    int var_s2;

    var_s2 = 0;
    if (arg0 == 0) {
        consPrintf(&D_000FA3A4, &D_000FA3C0, 0xC6, "modLoad", "pName");
    }
    while (var_s2 <= 0) {
        if (fileReady() == 1) {
            fileLock();
            var_s2 = sceKernelLoadModule(arg0, 0, 0);
            fileUnlock();
        }
        if (var_s2 > 0) break;
        sceKernelDelayThreadCB(0x3E8U);
    }
    temp_v0 = "modLoad";
    consPrintf("%s : 0x%08x : %s\n", temp_v0, var_s2, arg0);
    if (var_s2 <= 0) {
        consPrintf(&D_000FA3A4, &D_000FA3C0, 0xDE, temp_v0, "UID > 0");
    }
    modLock();
    memset(opt, 0, 0x14U);
    opt[0] = sizeof(opt);
    if (sceKernelStartModule(var_s2, 0, 0, &sp20, opt) < 0) {
        consPrintf(&D_000FA3A4, &D_000FA3C0, 0xEE, temp_v0, &D_000FA4C8);
    }
    modUnlock();
    return var_s2;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA4C8);

int sceKernelStopModule(int, M2C_UNK, M2C_UNK, M2C_UNK *, void *); /* extern */
int sceKernelUnloadModule(int);                     /* extern */
extern unsigned char D_000FA3A4;
extern unsigned char D_000FA3C0;
extern unsigned char D_000FA4C8;

int modUnload(int arg0) {
    int sp20;
    int opt[5];
    M2C_UNK *temp_v0;

    temp_v0 = "modUnload";
    consPrintf("%s : 0x%08x\n", temp_v0, arg0);
    modLock();
    memset(opt, 0, 0x14U);
    opt[0] = sizeof(opt);
    if (sceKernelStopModule(arg0, 0, 0, &sp20, opt) != 0) {
        consPrintf(&D_000FA3A4, &D_000FA3C0, 0x10B, temp_v0, "Ret == SCE_KERNEL_ERROR_OK");
    }
    if (sceKernelUnloadModule(arg0) < 0) {
        consPrintf(&D_000FA3A4, &D_000FA3C0, 0x110, temp_v0, &D_000FA4C8);
    }
    modUnlock();
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA50C);
