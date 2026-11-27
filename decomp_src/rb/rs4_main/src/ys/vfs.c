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



int _ZN3Vfs6System6CreateEv(void) {
    _ZN3Vfs8Internal6SystemC1Ev(_memAllocMBL(0x64, &D_00104898, 0x17));
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs", _ZN3Vfs6System7DestroyEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs", _ZN3Vfs6System5MountEPKcPv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs", _ZN3Vfs6System7UnmountEPKc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs", _ZN3Vfs6System19Create_InternalFileERNS_4FileEPKci);

void _ZN3Vfs4File4InitEv(int *arg0) {
    *arg0 = 0;
}

void _ZN3Vfs4FileD2Ev(void) {
    _ZN3Vfs4File5CloseEv();
}

void _ZN3Vfs4FileD1Ev(void) {
    _ZN3Vfs4File5CloseEv();
}

int _ZN3Vfs4File4OpenEPKci(int arg0) {
    return (_ZN3Vfs6System19Create_InternalFileERNS_4FileEPKci() < 0) ? 0 : arg0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs", _ZN3Vfs4File5CloseEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs", _ZN3Vfs4File4SeekEii);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs", _ZN3Vfs4File4ReadEPvj);

void vfsInit(void) {
    _ZN3Vfs6System6CreateEv();
}

void vfsTerm(void) {
    _ZN3Vfs6System7DestroyEv();
}

void vfsMount(void) {
    _ZN3Vfs6System5MountEPKcPv();
}

void vfsUnmount(void) {
    _ZN3Vfs6System7UnmountEPKc();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/vfs", vfsOpen);

void vfsClose(int arg0) {
    if (arg0 != 0) {
        _ZN3Vfs4FileD1Ev();
        _memFree(arg0, &D_00104898, 0x19);
    }
}

void vfsSeek(void) {
    _ZN3Vfs4File4SeekEii();
}

void vfsRead(void) {
    _ZN3Vfs4File4ReadEPvj();
}

