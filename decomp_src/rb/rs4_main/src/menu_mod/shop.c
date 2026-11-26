#include "common.h"
#include "m2c_macros.h"
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


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopAniSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _AniInfoSet_3CB84);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _AniFrameSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopCursorInitSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopCursorSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopNowCardSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopSaruCardCheck);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopSaruCardCheck2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopDeckCheck);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopDeckCheckSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopDeck2SaveSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopDeck2OmakaseSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopPutSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _CardListPutDel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _CardListPutSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _CardNowPutSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _DeckNowPutSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _BarPutSet);

#ifndef NULL
#define NULL ((void *)0)
#endif
int _BarPutPosSet(void *arg0) {
    if (M2C_FIELD(arg0, int *, 0x1C) != 0) {
        M2C_FIELD(arg0, int *, 0x24) = (int) ((int) ((0x88 - M2C_FIELD(arg0, int *, 0x20)) * M2C_FIELD(arg0, int *, 0x14)) / (int) (M2C_FIELD(arg0, int *, 0x10) - 7));
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int _WinPutSet(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _WinPutSet2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _WinPutSetWork);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _WinPutSetWorkCardPack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _TtrFontPutSet_3F420);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _Salbum2CardListSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _SwapCardWorkSet);

#ifndef NULL
#define NULL ((void *)0)
#endif
void _SwapIntWorkSet(int *arg0, int *arg1) {
    int temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _SortCardListSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _SortCardListSetInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _SortCardListGet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _CardListDel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", Sub_ShopUnLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _FontNumSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", Sub_Shop_WindowPut);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _GetCardPackID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _DeckCheck);

#ifndef NULL
#define NULL ((void *)0)
#endif

unsigned char UtilGetMessageLang(void) {
    return M2C_FIELD(localeGetCntx(), unsigned char *, 2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int UtilGetAssign(void) {
    return M2C_FIELD(localeGetCntx(), int *, 0xC) & 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic9SemaphoreC2EPKciij);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic9SemaphoreC1EPKciij);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelDeleteSema(int semid);

void _ZN9MetaMagic9SemaphoreD2Ev(void *arg0) {
    int temp_a1;

    temp_a1 = M2C_FIELD(arg0, int *, 4);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104798;
    if (temp_a1 >= 0) {
        sceKernelDeleteSema(temp_a1);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelDeleteSema(int semid);

void _ZN9MetaMagic9SemaphoreD1Ev(void *arg0) {
    int temp_a1;

    temp_a1 = M2C_FIELD(arg0, int *, 4);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104798;
    if (temp_a1 >= 0) {
        sceKernelDeleteSema(temp_a1);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelDeleteSema(int semid);

void _ZN9MetaMagic9SemaphoreD0Ev(void *arg0) {
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 4);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104798;
    if (temp_v1 >= 0) {
        sceKernelDeleteSema(temp_v1);
    }
    _memFree(arg0, &D_0010477C, 0x19);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZNK9MetaMagic9Semaphore10Get_StatusER17SceKernelSemaInfo(void *arg0, int *arg1) {
    *arg1 = 0x38;
    sceKernelReferSemaStatus(M2C_FIELD(arg0, int *, 4));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6ThreadC2EPKciij);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6ThreadC1EPKciij);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6ThreadD2Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6ThreadD1Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6ThreadD0Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6Thread12Set_PriorityEi);

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZNK9MetaMagic6Thread10Get_StatusER19SceKernelThreadInfo(void *arg0, int *arg1) {
    *arg1 = 0x6C;
    sceKernelReferThreadStatus(M2C_FIELD(arg0, int *, 4));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6Thread5StartEiPKv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6Thread4TermEv);

#ifndef NULL
#define NULL ((void *)0)
#endif
int _ZN9MetaMagic6Thread3RunEiPKv(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6Thread11_EntryPointEjPv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Tgs12ResidentData5ResetEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", TgsResidentData__Set_FinishPetitGame);

#ifndef NULL
#define NULL ((void *)0)
#endif

int _ZN3Vfs6System6CreateEv(void) {
    _ZN3Vfs8Internal6SystemC1Ev(_memAllocMBL(0x64, &D_00104898, 0x17));
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs6System7DestroyEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs6System5MountEPKcPv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs6System7UnmountEPKc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs6System19Create_InternalFileERNS_4FileEPKci);

#ifndef NULL
#define NULL ((void *)0)
#endif
void _ZN3Vfs4File4InitEv(int *arg0) {
    *arg0 = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZN3Vfs4FileD2Ev(void) {
    _ZN3Vfs4File5CloseEv();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZN3Vfs4FileD1Ev(void) {
    _ZN3Vfs4File5CloseEv();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int _ZN3Vfs4File4OpenEPKci(int arg0) {
    return (_ZN3Vfs6System19Create_InternalFileERNS_4FileEPKci() < 0) ? 0 : arg0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs4File5CloseEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs4File4SeekEii);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs4File4ReadEPvj);

#ifndef NULL
#define NULL ((void *)0)
#endif

void vfsInit(void) {
    _ZN3Vfs6System6CreateEv();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void vfsTerm(void) {
    _ZN3Vfs6System7DestroyEv();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void vfsMount(void) {
    _ZN3Vfs6System5MountEPKcPv();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void vfsUnmount(void) {
    _ZN3Vfs6System7UnmountEPKc();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", vfsOpen);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", vfsClose);

#ifndef NULL
#define NULL ((void *)0)
#endif

void vfsSeek(void) {
    _ZN3Vfs4File4SeekEii();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void vfsRead(void) {
    _ZN3Vfs4File4ReadEPvj();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6SystemC2Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6SystemC1Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6SystemD2Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6SystemD1Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6SystemD0Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6System5MountERNS0_17FileSystemMounterEPKcPv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6System7UnmountEPKc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6System20Find_MountFileSystemEPKcPi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6System19Create_InternalFileERNS_4FileEPKci);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6System19Remove_InternalFileERNS0_4FileE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal6System9Close_AllEv);

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZN3Vfs8Internal10FileSystemC2Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048E0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZN3Vfs8Internal10FileSystemC1Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048E0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZN3Vfs8Internal10FileSystemD2Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048E0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZN3Vfs8Internal10FileSystemD1Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048E0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal10FileSystemD0Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal10FileSystem13Set_MountNameEPKc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal10FileSystem11Create_FileERiPKci);

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZN3Vfs8Internal17FileSystemMounterD2Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048C8;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZN3Vfs8Internal17FileSystemMounterD1Ev(M2C_UNK **arg0) {
    *arg0 = &D_001048C8;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal17FileSystemMounterD0Ev);

#ifndef NULL
#define NULL ((void *)0)
#endif
int _ZN3Vfs8Internal17FileSystemMounter11Check_ImageEPv(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int _ZN3Vfs8Internal17FileSystemMounter17Create_FileSystemEPKcPv(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal4File4InitEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal4FileD2Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal4FileD1Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN3Vfs8Internal4FileD0Ev);

#ifndef NULL
#define NULL ((void *)0)
#endif
int _ZN3Vfs8Internal4File4SeekEii(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int _ZN3Vfs8Internal4File4ReadEPvj(void) {
    return 0;
}
