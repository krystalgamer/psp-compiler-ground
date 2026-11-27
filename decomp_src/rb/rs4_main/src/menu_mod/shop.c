/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
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

extern const float D_00104710;
void bxAnmSetFrame(int, float);
void bxAnmSetSpeed(int, float);
void bxAnmSetLoop(int, int);
void bxAnmSetPause(int, int);
void _AniInfoSet_3CB84(int anm)
{
	bxAnmSetFrame(anm, 0.0f);
	bxAnmSetSpeed(anm, D_00104710);
	bxAnmSetLoop(anm, 1);
	bxAnmSetPause(anm, 0);
}

void bxAnmSetFrame(int, float);
void bxAnmSetSpeed(int, float);
void bxAnmExec(int);
void _AniFrameSet(int anm, int frame)
{
	bxAnmSetFrame(anm, (float)frame);
	bxAnmSetSpeed(anm, 0.0f);
	bxAnmExec(anm);
}

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

typedef struct { unsigned char b[4]; } CardWork4;
void _SwapCardWorkSet(CardWork4 *a, CardWork4 *b)
{
	CardWork4 t;
	t = *a;
	*a = *b;
	*b = t;
}

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

typedef struct { unsigned char kind; char pad; unsigned short id; } SortCard;
int _SortCardListGet(SortCard *t, int n, SortCard *k)
{
	int r = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (t[i].id == k->id && t[i].kind == k->kind) {
			r = i;
			break;
		}
	}
	return r;
}

int _CardListDel(SortCard *t, int n, SortCard *k)
{
	int i = _SortCardListGet(t, n, k);
	n--;
	for (; i < n; i++) {
		t[i].id = t[i + 1].id;
		t[i].kind = t[i + 1].kind;
	}
	return n;
}

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



#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);



#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelDeleteSema(int semid);



#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelDeleteSema(int semid);



#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelDeleteSema(int semid);



#ifndef NULL
#define NULL ((void *)0)
#endif





#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelExitDeleteThread(int status);
int sceKernelGetThreadId(void);



#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelExitDeleteThread(int status);
int sceKernelGetThreadId(void);



#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelExitDeleteThread(int status);
int sceKernelGetThreadId(void);




#ifndef NULL
#define NULL ((void *)0)
#endif




#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelGetThreadId(void);



#ifndef NULL
#define NULL ((void *)0)
#endif


#ifndef NULL
#define NULL ((void *)0)
#endif


#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif







#ifndef NULL
#define NULL ((void *)0)
#endif


#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif






#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif




#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif












#ifndef NULL
#define NULL ((void *)0)
#endif


#ifndef NULL
#define NULL ((void *)0)
#endif


#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif






#ifndef NULL
#define NULL ((void *)0)
#endif



#ifndef NULL
#define NULL ((void *)0)
#endif




#ifndef NULL
#define NULL ((void *)0)
#endif


#ifndef NULL
#define NULL ((void *)0)
#endif






#ifndef NULL
#define NULL ((void *)0)
#endif


#ifndef NULL
#define NULL ((void *)0)
#endif

