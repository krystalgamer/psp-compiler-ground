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

#ifndef NULL
#define NULL ((void *)0)
#endif

int _BarPutSet(void *arg0) {
    int temp_lo;

    if (M2C_FIELD(arg0, int *, 0x1C) != 0) {
        temp_lo = 0x3B8 / (int) (M2C_FIELD(arg0, int *, 0x10) - 1);
        M2C_FIELD(arg0, int *, 0x20) = temp_lo;
        if (temp_lo >= 0x88) {
            M2C_FIELD(arg0, int *, 0x20) = 0x88;
        }
        _AniFrameSet(M2C_FIELD(((M2C_FIELD(arg0, signed char *, 0x32) * 4) + arg0), int *, 0x8030), M2C_FIELD(arg0, int *, 0x20));
        _BarPutPosSet(arg0);
    }
    return 0;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif
int Sub_ShopUnLock(void *arg0) {
    int var_a1;

    var_a1 = 0;
    if (M2C_FIELD(arg0, int *, 0x40) == 5) {
        M2C_FIELD(arg0, int *, 0x40) = 0;
        var_a1 = 1;
    }
    return var_a1;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);

void _ZN9MetaMagic9SemaphoreC2EPKciij(void *arg0, signed char *arg1, int arg2, int arg3, unsigned int arg4) {
    int temp_v0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104798;
    temp_v0 = sceKernelCreateSema(arg1, arg4, arg2, arg3, NULL);
    M2C_FIELD(arg0, int *, 4) = temp_v0;
    if (temp_v0 < 0) {
        consPrintf(&D_0010473C, &D_00104758, 0x22, &_ZZN9MetaMagic9SemaphoreC1EPKciijE12__FUNCTION__, &D_00104774);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);

void _ZN9MetaMagic9SemaphoreC1EPKciij(void *arg0, signed char *arg1, int arg2, int arg3, unsigned int arg4) {
    int temp_v0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_00104798;
    temp_v0 = sceKernelCreateSema(arg1, arg4, arg2, arg3, NULL);
    M2C_FIELD(arg0, int *, 4) = temp_v0;
    if (temp_v0 < 0) {
        consPrintf(&D_0010473C, &D_00104758, 0x22, &_ZZN9MetaMagic9SemaphoreC1EPKciijE12__FUNCTION__, &D_00104774);
    }
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelExitDeleteThread(int status);
int sceKernelGetThreadId(void);

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

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelExitDeleteThread(int status);
int sceKernelGetThreadId(void);

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

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelExitDeleteThread(int status);
int sceKernelGetThreadId(void);

void _ZN9MetaMagic6ThreadD0Ev(void *arg0) {
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
    } else {
        sceKernelTerminateDeleteThread(temp_v0_2);
    }
    _memFree(arg0, &D_00104840, 0x19);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6Thread12Set_PriorityEi);

#ifndef NULL
#define NULL ((void *)0)
#endif

void _ZNK9MetaMagic6Thread10Get_StatusER19SceKernelThreadInfo(void *arg0, int *arg1) {
    *arg1 = 0x6C;
    sceKernelReferThreadStatus(M2C_FIELD(arg0, int *, 4));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ZN9MetaMagic6Thread5StartEiPKv);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelGetThreadId(void);

void _ZN9MetaMagic6Thread4TermEv(void *arg0) {
    int temp_v0;
    int temp_v0_2;

    temp_v0 = sceKernelGetThreadId();
    if (temp_v0 < 0) {
        consPrintf(&D_001047E4, &D_00104800, 0xA7, &_ZZN9MetaMagic6Thread4TermEvE12__FUNCTION__, &D_00104828);
    }
    temp_v0_2 = M2C_FIELD(arg0, int *, 4);
    if (temp_v0_2 == temp_v0) {
        sceKernelExitThread(0);
        return;
    }
    sceKernelTerminateThread(temp_v0_2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int _ZN9MetaMagic6Thread3RunEiPKv(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void _ZN9MetaMagic6Thread11_EntryPointEjPv(int arg0, int arg1) {
    void **temp_v1;
    void *temp_a0;

    temp_a0 = arg1 + arg0;
    temp_v1 = M2C_FIELD(temp_a0, void ***, -4);
    M2C_FIELD(*temp_v1, M2C_UNK (**)(void **, int, int), 8)(temp_v1, M2C_FIELD(temp_a0, int *, -8), arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void _ZN3Tgs12ResidentData5ResetEv(int *arg0) {
    *arg0 = __builtin_allegrex_ins(*arg0, 0, 0, 2);
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void vfsClose(int arg0) {
    if (arg0 != 0) {
        _ZN3Vfs4FileD1Ev();
        _memFree(arg0, &D_00104898, 0x19);
    }
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif
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

#ifndef NULL
#define NULL ((void *)0)
#endif
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
