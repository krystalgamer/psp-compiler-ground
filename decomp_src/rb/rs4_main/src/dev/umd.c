/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
int sceUmdUnRegisterUMDCallBack(int);               /* extern */
extern signed char D_000FA8A4;
extern int UmdUID;

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

int sceKernelDelayThreadCB(unsigned int delay);
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sprintf(char *buf, const char *fmt, ...);
void *memset(void *s, int c, unsigned int n);
int sceUmdRegisterUMDCallBack(int);                 /* extern */
int sceUmdWaitDriveStatCB(M2C_UNK, M2C_UNK);        /* extern */
extern signed char D_000FA7E8;
extern signed char D_000FA7F0;
extern unsigned char D_000FA828;
extern unsigned char D_000FA848;
extern signed char D_000FA85C;
extern unsigned char D_000FA864;
extern signed char D_000FA88C;
extern signed char D_000FA898;
extern unsigned char RdpStat;
extern int UmdName_PrefDir;
extern signed char UmdRdp;
int umdProc(int, int, void *);

int umdInit(int arg0) {
    M2C_UNK *temp_v0;
    int temp_v0_2;

    temp_v0 = "umdInit";
    consPrintf("%s {\n", temp_v0);
    memset(&UmdRdp, 0, 0x400U);
    sprintf(&UmdRdp, &D_000FA7E8, UmdName_Alias, UmdName_PrefDir, arg0);
    if (M2C_FIELD(&UmdRdp, signed char *, 0x3FF) != 0) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0x3F, temp_v0, &D_000FA828);
    }
    consPrintf(&D_000FA7F0, &UmdRdp);
    if (UmdStandby != 0) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0x45, temp_v0, &D_000FA848);
    }
    UmdStandby = 1;
    umdActive();
    temp_v0_2 = sceKernelCreateCallback(&D_000FA85C, &umdProc, NULL);
    UmdUID = temp_v0_2;
    if (temp_v0_2 <= 0) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0x4C, temp_v0, &D_000FA864);
    }
    if (sceUmdRegisterUMDCallBack(UmdUID) != 0) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0x51, temp_v0, &D_000FA870);
    }
    if (sceUmdWaitDriveStatCB(0x20, 0) != 0) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0x56, temp_v0, &D_000FA870);
    }
    memset(&RdpStat, 0, 0x58U);
loop_11:
    if (sceIoGetstat(&UmdRdp, &RdpStat) != 0) {
        sceKernelDelayThreadCB(0x3E8U);
        goto loop_11;
    }
    consPrintf(&D_000FA88C, M2C_FIELD(&RdpStat, int *, 0x40));
    umdReady();
    consPrintf(&D_000FA898);
    return 1;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

int umdTerm(void) {
    M2C_UNK *temp_v0;

    temp_v0 = "umdTerm";
    consPrintf(&D_000FA8A4, temp_v0);
    if (UmdStandby == 1) {
        if (sceUmdUnRegisterUMDCallBack(UmdUID) != 0) {
            consPrintf(&D_000FA7FC, &D_000FA818, 0x79, temp_v0, &D_000FA870);
        }
        UmdStandby = 0;
        UmdUID = -1;
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/umd", D_000FA8A4);

void umdActive(void) {
    if ((UmdStandby == 1) && (sceUmdActivate(1, UmdName_Alias) != 0)) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0x8C, "umdActive", &D_000FA870);
    }
}

int umdProc(int arg0, int stat, void *arg2) {
    consPrintf("%s : %x\n", &D_000FA85C, stat);
    if (stat & 1) consPrintf("SCE_UMD_MEDIA_OUT\n");
    if (stat & 2) consPrintf("SCE_UMD_MEDIA_IN\n");
    if (stat & 4) consPrintf("SCE_UMD_MEDIA_CHG\n");
    if (stat & 0x10) consPrintf("SCE_UMD_READY\n");
    if (stat & 8) consPrintf("SCE_UMD_NOT_READY\n");
    if (stat & 0x20) {
        consPrintf("SCE_UMD_READABLE\n");
        UmdState = 1;
        UmdReady &= 1;
    } else {
        UmdReady = 0;
        UmdState = 0;
    }
    return 0;
}

extern char UmdName[0x400];

char *umdPref(char *p) {
    memset(UmdName, 0, sizeof(UmdName));
    if (*p != '/') {
        sprintf(UmdName, (char *)&D_000FA7E8, UmdName_Alias, UmdName_PrefDir, p);
    } else {
        sprintf(UmdName, "%s%s%s", UmdName_Alias, UmdName_PrefDir, p);
    }
    if (UmdName[sizeof(UmdName) - 1] != 0) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0xCE, "umdPref", "UmdName[sizeof(UmdName)-1] == 0");
    }
    return UmdName;
}

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

int sceIoDopen(const char *);
int sceIoDread(int, void *);
int sceIoDclose(int);
int strcmp(const char *, const char *);
char *strcat(char *, const char *);

typedef struct {
    int st_mode;
    char pad[0x54];
    char d_name[256];
    void *d_private;
    int dummy;
} UmdDirent;

void umdDump(const char *dir) {
    UmdDirent ent;
    char path[0x400];
    char *p;
    int uid;
    int r;

    p = umdPref((char *)dir);
    uid = sceIoDopen(p);
    consPrintf("%x %s {\n\n", uid, p);
    if (uid < 0) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0x113, "umdDump", "UID >= 0");
    }
    for (;;) {
        r = sceIoDread(uid, &ent);
        if (r < 0) {
            consPrintf(&D_000FA7FC, &D_000FA818, 0x119, "umdDump", "Ret >= 0");
        }
        if (r == 0) break;
        sprintf(path, "%s%s", dir, ent.d_name);
        switch (ent.st_mode & 0xF000) {
        case 0x1000:
            if (strcmp(ent.d_name, ".") != 0 && strcmp(ent.d_name, "..") != 0) {
                strcat(path, "/");
                umdDump(path);
            }
            break;
        case 0x2000:
        case 0x4000:
            consPrintf((char *)&D_000FA8A4, path);
            break;
        }
    }
    if (sceIoDclose(uid) != 0) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0x16E, "umdDump", "Ret == 0");
    }
    consPrintf("}\n\n");
}
