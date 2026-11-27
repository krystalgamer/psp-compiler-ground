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



void _ZN9MetaMagic9SemaphoreC2EPKciij(void *arg0, signed char *arg1, int arg2, int arg3, unsigned int arg4) {
    int temp_v0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104798;
    temp_v0 = sceKernelCreateSema(arg1, arg4, arg2, arg3, NULL);
    M2C_FIELD(arg0, int *, 4) = temp_v0;
    if (temp_v0 < 0) {
        consPrintf(&D_0010473C, &D_00104758, 0x22, &_ZZN9MetaMagic9SemaphoreC1EPKciijE12__FUNCTION__, &D_00104774);
    }
}

void _ZN9MetaMagic9SemaphoreC1EPKciij(void *arg0, signed char *arg1, int arg2, int arg3, unsigned int arg4) {
    int temp_v0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104798;
    temp_v0 = sceKernelCreateSema(arg1, arg4, arg2, arg3, NULL);
    M2C_FIELD(arg0, int *, 4) = temp_v0;
    if (temp_v0 < 0) {
        consPrintf(&D_0010473C, &D_00104758, 0x22, &_ZZN9MetaMagic9SemaphoreC1EPKciijE12__FUNCTION__, &D_00104774);
    }
}

void _ZN9MetaMagic9SemaphoreD2Ev(void *arg0) {
    int temp_a1;

    temp_a1 = M2C_FIELD(arg0, int *, 4);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104798;
    if (temp_a1 >= 0) {
        sceKernelDeleteSema(temp_a1);
    }
}

void _ZN9MetaMagic9SemaphoreD1Ev(void *arg0) {
    int temp_a1;

    temp_a1 = M2C_FIELD(arg0, int *, 4);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104798;
    if (temp_a1 >= 0) {
        sceKernelDeleteSema(temp_a1);
    }
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZZN9MetaMagic9SemaphoreC1EPKciijE12__FUNCTION__);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", D_0010473C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", D_00104758);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", D_00104774);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZN9MetaMagic9SemaphoreD0Ev);

void _ZNK9MetaMagic9Semaphore10Get_StatusER17SceKernelSemaInfo(void *arg0, int *arg1) {
    *arg1 = 0x38;
    sceKernelReferSemaStatus(M2C_FIELD(arg0, int *, 4));
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZTVN9MetaMagic9SemaphoreE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", D_00104798);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZTIN9MetaMagic9SemaphoreE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZTSN9MetaMagic9SemaphoreE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZTIN2Ys6ObjectE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZTSN2Ys6ObjectE);

