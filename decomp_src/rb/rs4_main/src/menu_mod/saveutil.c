/* cflags: -Os -fno-strength-reduce */
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
void SetData_InitBase();
M2C_UNK sceUtilitySavedataInitStart(void *);        /* extern */
int FreeData_Normal(int, void *);char *strcpy(char *d, const char *s);

extern unsigned char D_00103954;
void *_memAllocZero();

extern int l_atSaveRes[];
typedef struct { void *buf; int bufSize; int size; int unk; } SaveFDIcon0;
typedef struct { char pad[0x584]; SaveFDIcon0 d; } SavePIcon0;
typedef struct { void *data; int size; } SaveDatIcon0;
SaveDatIcon0 *resGetDatLocal();

typedef struct { void *buf; int bufSize; int size; int unk; } SaveFDPic1;
typedef struct { char pad[0x5A4]; SaveFDPic1 d; } SavePPic1;

typedef struct { void *buf; int bufSize; int size; int unk; } SaveFDIcon1;
typedef struct { char pad[0x594]; SaveFDIcon1 d; } SavePIcon1;

typedef struct { void *buf; int bufSize; int size; int unk; } SaveFDSnd0;
typedef struct { char pad[0x5B4]; SaveFDSnd0 d; } SavePSnd0;

int UtilGetMessageLang();
int UtilGetAssign();
void *memset(void *s, int c, unsigned int n);

int UtilityUnlink();
void gameEnSoftReset(void);
void *localeGetRegionCntx();
unsigned int strlen(const char *);
void *memcpy(void *, const void *, unsigned long);
extern unsigned char D_00104098;
typedef struct { char pad[0x80]; int f80; int f84; int f88; int f8C; } SaveGameCntx;
SaveGameCntx *gameGetCntx();
char *saveGetAccountData(int);
int saveGetData(int, int, int, void *);
int saveSetData(int, int, int, void *);
typedef struct { int f0; int f4; int f8; } SaveShift;
extern SaveShift l_tSHIFT;
extern int D_0011B058;
int _memFree();
int memcmp(const void *, const void *, unsigned int);

void consPrintf(const char *fmt, ...);
int SetData_Normal(int mode, char *p);
void FreeData_Sizes(int a);
void SetData_Paramsfo_String(int arg0) {
    signed char *temp_s2;

    temp_s2 = arg0 + 0x80;
    strcpy(temp_s2, &D_0011AB50);
    strcpy(arg0 + 0x100, &D_0011AB50 + 0x80);
    strcpy(arg0 + 0x180, &D_0011AB50 + 0x100);
    M2C_FIELD(temp_s2, unsigned char *, 0x500) = (unsigned char) M2C_FIELD(localeGetRegionCntx(), unsigned char *, 4);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00103954);

void SetData_GameData(char *p)
{
	void *d = _memAllocZero(0x14B0, &D_00103954, 0x81);
	SaveGameCntx *g;
	if (d == NULL)
		consPrintf("cassert : %s %d : %s : %s\n", &D_00103954, 0x82, "SetData_GameData", "pSaveData");
	g = gameGetCntx();
	l_tSHIFT.f8 = (*(unsigned int *)(saveGetAccountData(g->f8C) + 0x14A0) >> 1) & 1;
	*(unsigned int *)(saveGetAccountData(g->f8C) + 0x14A0) |= 2;
	saveGetData(g->f88, g->f8C, 0x140962, d);
	*(void **)(p + 0x74) = d;
	*(int *)(p + 0x78) = 0x14B0;
	*(int *)(p + 0x7C) = 0x14B0;
}

typedef struct { unsigned b0:1; unsigned shift:1; unsigned rest:30; } SaveAccBits;
int FreeData_GameData(p)
	char *p;
{
	SaveGameCntx *g = gameGetCntx();
	if (*(int *)(p + 0x1C) == 0 || (*(int *)(p + 0x1C) == 2 && *(int *)(p + 0x5CC) == 0)) {
		consPrintf("save ok backup update\n");
		saveSetData(g->f88, 2, 0x140962, *(void **)(p + 0x74));
	} else {
		consPrintf("save ng result = %x\n", *(int *)(p + 0x1C));
		((SaveAccBits *)(saveGetAccountData(g->f8C) + 0x14A0))->shift = D_0011B058;
	}
	_memFree(*(void **)(p + 0x74), &D_00103954, 0x9F);
}

void SetData_GameBuf(char *p)
{
	*(void **)(p + 0x74) = _memAllocZero(0x80000, &D_00103954, 0xA6);
	*(int *)(p + 0x78) = 0x80000;
}

typedef struct { int d[0x14B0 / 4]; } SaveAccData;
void FreeData_GameBuf(char *p)
{
	SaveGameCntx *g, *g2;
	SaveAccData *buf, *acc;
	int r;
	if (*(int *)(p + 0x1C) == 0 || (*(int *)(p + 0x1C) == 2 && *(int *)(p + 0x5CC) == 0)) {
		if (l_tSHIFT.f0 != 0x1000000) {
			g = gameGetCntx();
			saveSetData(g->f88, g->f8C, 0x140962, *(void **)(p + 0x74));
			saveSetData(g->f88, 2, 0x140962, *(void **)(p + 0x74));
		} else {
			g2 = gameGetCntx();
			buf = _memAllocZero(0x14B0, &D_00103954, 0xBE);
			acc = (SaveAccData *)saveGetAccountData(2);
			*buf = *acc;
			saveSetData(g2->f88, 2, 0x140962, *(void **)(p + 0x74));
			r = memcmp(buf, acc, 0x14B0);
			*acc = *buf;
			_memFree(buf, &D_00103954, 0xCC);
			l_tSHIFT.f4 = r == 0 ? 1 : 2;
		}
		consPrintf("load ok result=%d/%d\n", *(int *)(p + 0x1C), D_0011B054);
	} else {
		consPrintf("load ng result = %x\n", *(int *)(p + 0x1C));
	}
	_memFree(*(void **)(p + 0x74), &D_00103954, 0xD8);
}

void SetData_Icon0Buf(void *p) {
}

void SetData_Icon1Buf(void *p) {
}

void SetData_Pic1Buf(void *p) {
}

void SetData_Snd0Buf(void *p) {
}

void SetData_Icon0(SavePIcon0 *p)
{
	SaveDatIcon0 *r;
	r = resGetDatLocal(l_atSaveRes[0], l_atSaveRes[1]);
	p->d.buf = r->data;
	p->d.bufSize = r->size;
	p->d.size = r->size;
}

void SetData_Pic1(SavePPic1 *p)
{
	SaveDatIcon0 *r;
	r = resGetDatLocal(l_atSaveRes[0], l_atSaveRes[3]);
	p->d.buf = r->data;
	p->d.bufSize = r->size;
	p->d.size = r->size;
}

void SetData_Icon1(SavePIcon1 *p)
{
	SaveDatIcon0 *r;
	if (l_atSaveRes[2] < 0)
		return;
	r = resGetDatLocal(l_atSaveRes[0], l_atSaveRes[2]);
	p->d.buf = r->data;
	p->d.bufSize = r->size;
	p->d.size = r->size;
}

void SetData_Snd0(SavePSnd0 *p)
{
	SaveDatIcon0 *r;
	r = resGetDatLocal(l_atSaveRes[0], l_atSaveRes[4]);
	p->d.buf = r->data;
	p->d.bufSize = r->size;
	p->d.size = r->size;
}

M2C_UNK *Get_Savedata(void) {
    return &savedata_param;
}

void SetUtilityType(unsigned int arg0) {
    if (arg0 < 3U) {
        g_utilityType = arg0;
    }
}

void UtilityNone(void) {
    SetUtilityType(2);
}

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

void SetData_InitBase(int *p, int a)
{
	p[0] = a;
	p[1] = UtilGetMessageLang();
	p[2] = UtilGetAssign();
	p[3] = 0x15;
	p[4] = 0x17;
	p[5] = 0x16;
	p[6] = 0x14;
}

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

void MakeMode(int m, char *s, int n)
{
	if (n >= 11) {
		s[0] = '-';
		s[1] = (m & 0x100) ? 'r' : '-';
		s[2] = (m & 0x80) ? 'w' : '-';
		s[3] = (m & 0x40) ? 'x' : '-';
		s[4] = (m & 0x20) ? 'r' : '-';
		s[5] = (m & 0x10) ? 'w' : '-';
		s[6] = (m & 0x8) ? 'x' : '-';
		s[7] = (m & 0x4) ? 'r' : '-';
		s[8] = (m & 0x2) ? 'w' : '-';
		s[9] = (m & 0x1) ? 'x' : '-';
		s[10] = 0;
	}
}

typedef struct { const char *name[23]; } SaveTypeNames;
extern const SaveTypeNames D_00103B98;
extern const char D_00103BF4[];
int snprintf(char *, unsigned int, const char *, ...);
void GetTypeName(int type, char *buf, unsigned int n)
{
	SaveTypeNames t = D_00103B98;
	snprintf(buf, n, D_00103BF4, t.name[type]);
}

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

extern unsigned char D_001040A0, D_001040AC;
/* STAND-IN: builtin memcpy for the variable-length copy, a real call for the 4-byte one (cf. SetData_Sizes) */
void SetData_Load(char *p, int mode)
{
	unsigned int len;

	len = strlen((char *)localeGetRegionCntx() + 5);
	__builtin_memcpy(p + 0x3C, (char *)localeGetRegionCntx() + 5, len);
	*(char *)(len + (int)p + 0x3C) = 0;
	memcpy(p + 0x4C, &D_00104098, 4);
	p[0x50] = 0;
	if (mode != 0)
		sprintf(p + 0x64, &D_00103BF4, &D_001040A0);
	else
		sprintf(p + 0x64, &D_00103BF4, &D_001040AC);
	SetData_GameBuf(p);
	memset(p + 0x80, 0, 0x504);
	SetData_Icon0Buf(p);
	SetData_Icon1Buf(p);
	SetData_Pic1Buf(p);
	SetData_Snd0Buf(p);
}

void FreeData_Load(int a, int b) {
    FreeData_GameBuf(a);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Save);

void FreeData_Save(int a, int b)
{
	FreeData_GameData(a, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", SetData_Delete);

void CB_SaveData_Normal(int arg0) {
    void *temp_s0;

    temp_s0 = Get_Savedata();
    SetUtilityType(0);
    memset(temp_s0, 0, 0x600U);
    SetData_InitBase(temp_s0, 0x600);
    SetData_Normal(arg0, temp_s0);
    sceUtilitySavedataInitStart(temp_s0);
}

void Free_SaveData_Normal(int arg0) {
    FreeData_Normal(arg0, Get_Savedata());
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104098);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001040A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001040AC);

int SetData_Normal(int mode, char *p)
{
	int ret;
	*(int *)(p + 0x30) = mode;
	*(int *)(p + 0x38) = 0;
	Copy_SecureFileId((int)(p + 0x5DC));
	switch (mode) {
	case 0:
	case 2:
		SetData_Load(p, 1);
		ret = 0;
		break;
	case 1:
	case 3:
		SetData_Save(p, 1);
		ret = 0;
		break;
	case 9:
	case 10:
		SetData_Delete(p);
		ret = 0;
		break;
	case 8:
		SetData_Sizes(p);
		ret = 0;
		break;
	case 4:
	case 5:
	case 6:
	default:
		ret = 1;
		break;
	case 7:
		ret = 0;
		break;
	}
	return ret;
}

int FreeData_Normal(int mode, void *p)
{
	int ret;
	switch (mode) {
	case 0:
	case 2:
		FreeData_Load(p, 1);
		ret = 0;
		break;
	case 1:
	case 3:
		FreeData_Save(p, 1);
		ret = 0;
		break;
	case 8:
		FreeData_Sizes(p);
		ret = 0;
		break;
	case 4:
	case 5:
	case 6:
	default:
		ret = 1;
		break;
	case 7:
	case 9:
	case 10:
		ret = 0;
		break;
	}
	return ret;
}

extern unsigned char _msDataSize, _msFreeSize, _utilityDataSize;
void SetData_Save();
/* STAND-IN: the variable-length copy only matches as the builtin memcpy (dst evaluated before
   the src call), the 4-byte copy only as a real call (the file's memcpy is not builtin-compatible) */
void SetData_Sizes(char *p)
{
	unsigned int len;

	memset(&_msFreeSize, 0, 0x14);
	memset(&_msDataSize, 0, 0x40);
	memset(&_utilityDataSize, 0, 0x1C);
	*(void **)(p + 0x5D0) = &_msFreeSize;
	*(void **)(p + 0x5D4) = &_msDataSize;
	len = strlen((char *)localeGetRegionCntx() + 5);
	__builtin_memcpy(*(char **)(p + 0x5D4), (char *)localeGetRegionCntx() + 5, len);
	(*(char **)(p + 0x5D4))[len] = 0;
	memcpy(*(char **)(p + 0x5D4) + 0x10, &D_00104098, 4);
	(*(char **)(p + 0x5D4))[0x14] = 0;
	*(void **)(p + 0x5D8) = &_utilityDataSize;
	SetData_Save(p, 1);
}

void FreeData_Sizes(int a)
{
	FreeData_Save(a, 1);
}

typedef struct { int d[0x514 / 4]; } SaveRes;
void gameDisSoftReset(void);
int UtilityLink();
int Savedata_Update();
void SaveStart(int mode, SaveRes *res)
{
	int m = mode & 0xFFFFFF;
	consPrintf("SaveStart : %d (shift:%d)\n", m, mode / 0x1000000);
	gameDisSoftReset();
	UtilityLink(Savedata_Update);
	if (res != NULL)
		*(SaveRes *)l_atSaveRes = *res;
	else
		memset(l_atSaveRes, 0, 0x514);
	l_tSHIFT.f4 = 0;
	l_tSHIFT.f0 = mode;
	CB_SaveData_Normal(m);
}

void SaveEnd(int x)
{
	int id = x & 0xFFFFFF;
	UtilityUnlink();
	Free_SaveData_Normal(id);
	gameEnSoftReset();
	consPrintf("SaveEnd : %d (shift:%d)\n", id, x / 0x1000000);
}

int SaveState(void) {
    return g_utilityType == 0;
}

int SaveGetResult(void) {
    return D_0011B078;
}

int SaveGetAbortedStatus(void) {
    return D_0011B628;
}

int SaveGetSHIFTResult(void) {
    return D_0011B054;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104148);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_00104170);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_0010418C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/saveutil", D_001041A0);

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
