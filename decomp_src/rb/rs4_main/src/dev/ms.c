/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK semaLock(int);                              /* extern */
extern int MsSema;
M2C_UNK semaUnlock(int);                            /* extern */

extern int MsReady;
extern int MsState;

extern unsigned char D_000FA51C;
extern unsigned char D_000FA524;
extern unsigned char D_000FA538;
extern unsigned char D_000FA548;
extern unsigned char D_000FA5E8;
char *msPref(char *);
extern unsigned char D_000FA564;
extern unsigned char D_000FA568;
extern unsigned char D_000FA574;
extern unsigned char D_000FA57C;
extern unsigned char D_000FA588;
extern unsigned char D_000FA590;
extern unsigned char D_000FA5AC;
extern int MsStandby;
extern int MsUID;
int msProc(int, int, void *);

int msInit(void) {
    M2C_UNK *temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int uid;

    temp_v0 = "msInit";
    consPrintf(&D_000FA51C, temp_v0);
    if (MsStandby != 0) {
        consPrintf(&D_000FA548, &D_000FA538, 0x2E, temp_v0, &D_000FA524);
    }
    MsStandby = 1;
    temp_v0_2 = semaInit(&D_000FA564);
    MsSema = temp_v0_2;
    if (temp_v0_2 <= 0) {
        consPrintf(&D_000FA548, &D_000FA538, 0x33, temp_v0, &D_000FA568);
    }
    temp_v0_3 = sceKernelCreateCallback(&D_000FA574, &msProc, NULL);
    MsUID = temp_v0_3;
    if (temp_v0_3 <= 0) {
        consPrintf(&D_000FA548, &D_000FA538, 0x3A, temp_v0, &D_000FA57C);
    }
    uid = MsUID;
    if (sceIoDevctl(&D_000FA588, 0x02415821, &uid, 4, 0, 0) != 0) {
        consPrintf(&D_000FA548, &D_000FA538, 0x3D, temp_v0, &D_000FA590);
    }
    msReady();
    consPrintf(&D_000FA5AC);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA51C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA524);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA538);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA548);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA564);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA568);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA574);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA57C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA588);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA590);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA5AC);

int msTerm(void) {
    M2C_UNK *temp_v0;
    int temp_s1;
    int uid;

    temp_v0 = "msTerm";
    consPrintf(&D_000FA51C, temp_v0);
    temp_s1 = MsStandby;
    if (temp_s1 == 1) {
        uid = MsUID;
        if (sceIoDevctl(&D_000FA588, 0x02415822, &uid, 4, 0, 0) != 0) {
            consPrintf(&D_000FA548, &D_000FA538, 0x50, temp_v0, &D_000FA590);
        }
        MsUID = -1;
        if (semaTerm(MsSema) != temp_s1) {
            consPrintf(&D_000FA548, &D_000FA538, 0x56, temp_v0, "Ret == TRUE");
        }
        MsSema = -1;
        MsStandby = 0;
    }
    consPrintf(&D_000FA5AC);
    return 1;
}

int msProc(int arg0, int arg1, void *arg2) {

    if (arg1 == 1) {
        consPrintf("%s : Ready\n", &D_000FA574);
        if (arg0 >= 2) {
            MsReady = 0;
            msUnlock();
        }
        MsState = arg1;
        MsReady &= 1;
    } else {
        consPrintf("%s : Not Ready\n", &D_000FA574);
        MsReady = 0;
        MsState = 0;
        msUnlock();
    }
    return 0;
}

void msLock(void) {
    if (MsSema > 0) {
        semaLock(MsSema);
    }
}

void msUnlock(void) {
    if (MsSema > 0) {
        semaUnlock(MsSema);
    }
}

extern char MsName[0x400];
extern int MsName_Alias;
extern unsigned char D_000FA5F0, D_000FA5F8;


char *msPref(char *p) {
    memset(MsName, 0, sizeof(MsName));
    if (*p != '/') {
        sprintf(MsName, "%s/%s", MsName_Alias, p);
    } else {
        sprintf(MsName, (char *)&D_000FA5E8, MsName_Alias, p);
    }
    if (MsName[sizeof(MsName) - 1] != 0) {
        consPrintf(&D_000FA548, &D_000FA538, 0xA7, &D_000FA5F0, &D_000FA5F8);
    }
    return MsName;
}

int msReady(void) {
    int temp_v0;

    temp_v0 = MsReady;
    MsReady = MsState;
    return temp_v0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA5E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA5F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ms", D_000FA5F8);

int sceIoDopen(const char *);
int sceIoDread(int, void *);
int sceIoDclose(int);
int strcmp(const char *, const char *);
char *strcat(char *, const char *);
int sprintf(char *, const char *, ...);
void *memset(void *, int, unsigned int);

typedef struct {
    int st_mode;
    char pad[0x54];
    char d_name[256];
    void *d_private;
    int dummy;
} MsDirent;

void msDump(const char *dir) {
    char path[0x400];
    MsDirent ent;
    char priv[0x110];
    char *p;
    int uid;
    int r;

    p = msPref((char *)dir);
    uid = sceIoDopen(p);
    consPrintf("%x %s {\n\n", uid, p);
    if (uid < 0) {
        consPrintf(&D_000FA548, &D_000FA538, 0xBF, "msDump", "UID >= 0");
    }
    for (;;) {
        memset(&ent, 0, sizeof(ent));
        ent.d_private = priv;
        r = sceIoDread(uid, &ent);
        if (r < 0) {
            consPrintf(&D_000FA548, &D_000FA538, 0xCB, "msDump", "Ret >= 0");
        }
        if (r == 0) break;
        sprintf(path, (char *)&D_000FA5E8, dir, ent.d_name);
        switch (ent.st_mode & 0xF000) {
        case 0x1000:
            if (strcmp(ent.d_name, ".") != 0 && strcmp(ent.d_name, "..") != 0) {
                strcat(path, "/");
                msDump(path);
            }
            break;
        case 0x2000:
        case 0x4000:
            consPrintf("%s\n", path);
            break;
        }
    }
    if (sceIoDclose(uid) != 0) {
        consPrintf(&D_000FA548, &D_000FA538, 0x120, "msDump", "Ret == 0");
    }
    consPrintf("}\n\n");
}
