/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
extern signed char D_0011AB50;
M2C_UNK ShowResult();                               /* extern */
unsigned int sceUtilitySavedataGetStatus();                  /* extern */
M2C_UNK sceUtilitySavedataShutdownStart();          /* extern */
M2C_UNK sceUtilitySavedataUpdate(int);              /* extern */
extern unsigned char _secure_file_id;
extern int D_0011B078;
extern int D_0011B628;
extern int D_0011B054;

extern unsigned char savedata_param;
extern unsigned int g_utilityType;
M2C_UNK FreeData_GameBuf();                         /* extern */
M2C_UNK SetData_InitBase(void *, M2C_UNK);          /* extern */
M2C_UNK SetData_Normal(int, void *);                /* extern */
M2C_UNK sceUtilitySavedataInitStart(void *);        /* extern */
M2C_UNK FreeData_Normal(int, int);                  /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
char *strcpy(char *d, const char *s);

void SetData_Paramsfo_String(int arg0) {
    signed char *temp_s2;

    temp_s2 = arg0 + 0x80;
    strcpy(temp_s2, &D_0011AB50);
    strcpy(arg0 + 0x100, &D_0011AB50 + 0x80);
    strcpy(arg0 + 0x180, &D_0011AB50 + 0x100);
    M2C_FIELD(temp_s2, unsigned char *, 0x500) = (unsigned char) M2C_FIELD(localeGetRegionCntx(), unsigned char *, 4);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103954);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_GameData);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", FreeData_GameData);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_GameBuf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", FreeData_GameBuf);

void SetData_Icon0Buf(void) {
}

void SetData_Icon1Buf(void) {
}

void SetData_Pic1Buf(void) {
}

void SetData_Snd0Buf(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Icon0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Pic1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Icon1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Snd0);

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *Get_Savedata(void) {
    return &savedata_param;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void SetUtilityType(unsigned int arg0) {
    if (arg0 < 3U) {
        g_utilityType = arg0;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void UtilityNone(void) {
    SetUtilityType(2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int Savedata_Update(void) {
    unsigned int temp_v0;

    temp_v0 = sceUtilitySavedataGetStatus();
    switch (temp_v0) {
    case 2:
        sceUtilitySavedataUpdate(M2C_FIELD(gameGetCntx(), int *, 0x80) + 1);
        break;
    case 3:
        sceUtilitySavedataShutdownStart();
        ShowResult();
        break;
    case 0:
        UtilityNone();
        /* fallthrough */
    case 1:
    case 4:
        break;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_InitBase);

#ifndef NULL
#define NULL ((void *)0)
#endif

void Copy_SecureFileId(int arg0) {
    int var_a1;
    unsigned char *temp_v1;
    unsigned char temp_a0;

    var_a1 = 0;
    do {
        temp_a0 = *(var_a1 + &_secure_file_id);
        temp_v1 = arg0 + var_a1;
        var_a1 += 1;
        *temp_v1 = temp_a0;
    } while (var_a1 < 0x10);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", MakeMode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", GetTypeName);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _secure_file_id);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A80);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103A94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103AA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103AB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103AC0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103ADC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103AF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103B0C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103B20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103B34);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103B48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103B60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103B78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103B88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103B98);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103BF4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", ShowResult);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Load);

#ifndef NULL
#define NULL ((void *)0)
#endif

void FreeData_Load(void) {
    FreeData_GameBuf();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Save);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", FreeData_Save);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Delete);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void CB_SaveData_Normal(int arg0) {
    void *temp_s0;

    temp_s0 = Get_Savedata();
    SetUtilityType(0);
    memset(temp_s0, 0, 0x600U);
    SetData_InitBase(temp_s0, 0x600);
    SetData_Normal(arg0, temp_s0);
    sceUtilitySavedataInitStart(temp_s0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void Free_SaveData_Normal(int arg0) {
    FreeData_Normal(arg0, Get_Savedata());
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104098);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001040A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001040AC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Normal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", FreeData_Normal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Sizes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", FreeData_Sizes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SaveStart);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SaveEnd);

#ifndef NULL
#define NULL ((void *)0)
#endif

int SaveState(void) {
    return g_utilityType == 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int SaveGetResult(void) {
    return D_0011B078;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int SaveGetAbortedStatus(void) {
    return D_0011B628;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int SaveGetSHIFTResult(void) {
    return D_0011B054;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104148);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104170);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010418C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", Sub_Shop);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001041AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001041B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001041CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001041D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001041E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104208);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104224);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104238);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104300);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104388);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104434);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104450);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010446C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104478);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104484);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104490);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010449C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001044AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001044BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001044C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001044D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001044E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001044EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001044F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104504);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104510);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010451C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104528);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104534);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104540);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010454C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104558);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104568);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104574);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001045B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001045E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001045FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104608);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104614);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104620);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010462C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104638);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104644);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010465C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104670);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104680);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104690);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001046A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001046B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001046CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001046D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001046EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010470C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104710);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104714);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104718);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010471C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104720);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104724);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104728);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010472C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZZN9MetaMagic9SemaphoreC1EPKciijE12__FUNCTION__);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010473C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104758);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104774);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010477C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTVN9MetaMagic9SemaphoreE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104798);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTIN9MetaMagic9SemaphoreE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTSN9MetaMagic9SemaphoreE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTIN2Ys6ObjectE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTSN2Ys6ObjectE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZZN9MetaMagic6ThreadC1EPKciijE12__FUNCTION__);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001047E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104800);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104818);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZZN9MetaMagic6ThreadD1EvE12__FUNCTION__);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104828);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104840);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZZN9MetaMagic6Thread4TermEvE12__FUNCTION__);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTVN9MetaMagic6ThreadE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104868);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTIN9MetaMagic6ThreadE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTSN9MetaMagic6ThreadE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104898);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001048AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTVN3Vfs8Internal17FileSystemMounterE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001048C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTVN3Vfs8Internal10FileSystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001048E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTVN3Vfs8Internal6SystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001048F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTIN3Vfs8Internal10FileSystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTIN3Vfs8Internal17FileSystemMounterE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTIN3Vfs8Internal6SystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTSN3Vfs8Internal6SystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTSN3Vfs8Internal17FileSystemMounterE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", _ZTSN3Vfs8Internal10FileSystemE);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010497C);
