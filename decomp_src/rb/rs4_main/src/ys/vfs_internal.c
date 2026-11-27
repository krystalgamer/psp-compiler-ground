/* C++ source (.cc); still m2c drafts compiled as C under the mangled names */
/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK _AniFrameSet(int, int);                     /* extern */
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern unsigned char D_0010473C;
extern unsigned char D_00104758;
extern unsigned char D_00104774;
extern unsigned char _ZZN9MetaMagic9SemaphoreC1EPKciijE12__FUNCTION__;
M2C_UNK sceKernelTerminateDeleteThread(int);        /* extern */
extern unsigned char D_001047E4;
extern unsigned char D_00104800;
extern unsigned char D_00104828;
extern unsigned char D_00104868;
extern unsigned char _ZZN9MetaMagic6ThreadD1EvE12__FUNCTION__;
extern unsigned char D_00104840;
M2C_UNK sceKernelExitThread(M2C_UNK);               /* extern */
M2C_UNK sceKernelTerminateThread(int);              /* extern */
extern unsigned char _ZZN9MetaMagic6Thread4TermEvE12__FUNCTION__;

void *localeGetCntx();                              /* extern */
extern unsigned char D_00104798;
M2C_UNK _memFree(void *, M2C_UNK *, M2C_UNK);       /* extern */
extern unsigned char D_0010477C;
M2C_UNK sceKernelReferSemaStatus(int);              /* extern */
M2C_UNK sceKernelReferThreadStatus(int);            /* extern */
M2C_UNK _ZN3Vfs8Internal6SystemC1Ev(int);           /* extern */
int _memAllocMBL(M2C_UNK, M2C_UNK *, M2C_UNK);      /* extern */
extern unsigned char D_00104898;
M2C_UNK _ZN3Vfs4File5CloseEv();                     /* extern */
int _ZN3Vfs6System19Create_InternalFileERNS_4FileEPKci(); /* extern */
M2C_UNK _ZN3Vfs6System7DestroyEv();                 /* extern */
M2C_UNK _ZN3Vfs6System5MountEPKcPv();               /* extern */
M2C_UNK _ZN3Vfs6System7UnmountEPKc();               /* extern */
M2C_UNK _ZN3Vfs4File4SeekEii();                     /* extern */
M2C_UNK _ZN3Vfs4File4ReadEPvj();                    /* extern */
extern unsigned char D_001048E0;
extern unsigned char D_001048C8;



INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal6SystemC2Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal6SystemC1Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal6SystemD2Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal6SystemD1Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal6SystemD0Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal6System5MountERNS0_17FileSystemMounterEPKcPv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal6System7UnmountEPKc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal6System20Find_MountFileSystemEPKcPi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal6System19Create_InternalFileERNS_4FileEPKci);

void *_ZN3Vfs8Internal6System19Remove_InternalFileERNS0_4FileE(void *arg0, void *arg1) {
    int var_v1;
    void *temp_v1;
    void *var_a0;

    var_a0 = arg0;
    temp_v1 = M2C_FIELD(arg1, void **, 4);
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, int *, 4) = (int) (M2C_FIELD(temp_v1, int *, 4) + 1);
    }
    var_v1 = 0xF;
    do {
        var_v1 -= 1;
        if (M2C_FIELD(var_a0, int *, 0x24) == arg1) {
            M2C_FIELD(var_a0, int *, 0x24) = 0;
        }
        var_a0 += 4;
    } while (var_v1 >= 0);
    return arg1;
}

void _ZN3Vfs8Internal6System9Close_AllEv(void *arg0) {
    int var_s1;
    void **temp_v0;
    void *var_s0;

    var_s1 = 0xF;
    var_s0 = arg0;
    do {
        temp_v0 = M2C_FIELD(var_s0, void ***, 0x24);
        var_s1 -= 1;
        if (temp_v0 != NULL) {
            M2C_FIELD(var_s0, void ***, 0x24) = NULL;
            M2C_FIELD(*temp_v0, M2C_UNK (**)(void **), 4)(temp_v0);
        }
        var_s0 += 4;
    } while (var_s1 >= 0);
}

void _ZN3Vfs8Internal10FileSystemC2Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048E0;
}

void _ZN3Vfs8Internal10FileSystemC1Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048E0;
}

void _ZN3Vfs8Internal10FileSystemD2Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048E0;
}

void _ZN3Vfs8Internal10FileSystemD1Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048E0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal10FileSystemD0Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal10FileSystem13Set_MountNameEPKc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal10FileSystem11Create_FileERiPKci);

void _ZN3Vfs8Internal17FileSystemMounterD2Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048C8;
}

void _ZN3Vfs8Internal17FileSystemMounterD1Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048C8;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZN3Vfs8Internal17FileSystemMounterD0Ev);

int _ZN3Vfs8Internal17FileSystemMounter11Check_ImageEPv(void) {
    return 0;
}

int _ZN3Vfs8Internal17FileSystemMounter17Create_FileSystemEPKcPv(void) {
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", D_00104898);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", D_001048AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTVN3Vfs8Internal17FileSystemMounterE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", D_001048C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTVN3Vfs8Internal10FileSystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", D_001048E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTVN3Vfs8Internal6SystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", D_001048F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTIN3Vfs8Internal10FileSystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTIN3Vfs8Internal17FileSystemMounterE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTIN3Vfs8Internal6SystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTSN3Vfs8Internal6SystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTSN3Vfs8Internal17FileSystemMounterE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs_internal", _ZTSN3Vfs8Internal10FileSystemE);
