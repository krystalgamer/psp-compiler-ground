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



INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZN9MetaMagic6ThreadC2EPKciij);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZN9MetaMagic6ThreadC1EPKciij);

void _ZN9MetaMagic6ThreadD2Ev(void *arg0) {
    int temp_v0;
    int temp_v0_2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104868;
    temp_v0 = sceKernelGetThreadId();
    if (temp_v0 < 0) {
        consPrintf(&D_001047E4, &D_00104800, 0x44, &_ZZN9MetaMagic6ThreadD1EvE12__FUNCTION__, &D_00104828);
    }
    temp_v0_2 = M2C_FIELD(arg0, int *, 4);
    if (temp_v0_2 == temp_v0) {
        sceKernelExitDeleteThread(0);
        return;
    }
    sceKernelTerminateDeleteThread(temp_v0_2);
}

void _ZN9MetaMagic6ThreadD1Ev(void *arg0) {
    int temp_v0;
    int temp_v0_2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104868;
    temp_v0 = sceKernelGetThreadId();
    if (temp_v0 < 0) {
        consPrintf(&D_001047E4, &D_00104800, 0x44, &_ZZN9MetaMagic6ThreadD1EvE12__FUNCTION__, &D_00104828);
    }
    temp_v0_2 = M2C_FIELD(arg0, int *, 4);
    if (temp_v0_2 == temp_v0) {
        sceKernelExitDeleteThread(0);
        return;
    }
    sceKernelTerminateDeleteThread(temp_v0_2);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZZN9MetaMagic6ThreadC1EPKciijE12__FUNCTION__);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", D_001047E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", D_00104800);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", D_00104818);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZZN9MetaMagic6ThreadD1EvE12__FUNCTION__);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", D_00104828);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZN9MetaMagic6ThreadD0Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZN9MetaMagic6Thread12Set_PriorityEi);

void _ZNK9MetaMagic6Thread10Get_StatusER19SceKernelThreadInfo(void *arg0, int *arg1) {
    *arg1 = 0x6C;
    sceKernelReferThreadStatus(M2C_FIELD(arg0, int *, 4));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZN9MetaMagic6Thread5StartEiPKv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZN9MetaMagic6Thread4TermEv);

int _ZN9MetaMagic6Thread3RunEiPKv(void) {
    return 0;
}

void _ZN9MetaMagic6Thread11_EntryPointEjPv(int arg0, int arg1) {
    void **temp_v1;
    void *temp_a0;

    temp_a0 = arg1 + arg0;
    temp_v1 = M2C_FIELD(temp_a0, void ***, -4);
    M2C_FIELD(*temp_v1, M2C_UNK (**)(void **, int, int), 8)(temp_v1, M2C_FIELD(temp_a0, int *, -8), arg1);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZTVN9MetaMagic6ThreadE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", D_00104868);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZTIN9MetaMagic6ThreadE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZTSN9MetaMagic6ThreadE);

