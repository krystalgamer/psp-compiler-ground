/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
void getOskUtilityTextResult(void);
extern void *l_ptCntx;
extern int sample_type_11A910;

M2C_UNK gameCtrlLock();                             /* extern */
M2C_UNK gameDisSoftReset();                         /* extern */
M2C_UNK gameCtrlUnlock();
extern int osk_param;
int setOskUtilityParam();
int sceUtilityOskInitStart();

int UtilityLink();
int utility_update_osk();
extern unsigned char D_00103130, D_00103158, D_00103168, D_001031E4, D_001031F4, D_001031F8, D_00103228, D_00103258;
void *_memAlloc(int, void *, int);
int _memFree();
typedef struct { char pad[0x28]; unsigned short *text; unsigned int result; char pad2[0x34 - 0x30]; } OskData;

M2C_UNK *gameGetCntx(void);
void gameEnSoftReset(void);
void UtilityUnlink(void);
typedef unsigned short SceWChar16;
typedef struct {
	unsigned int size;
	int message_lang;
	int ctrl_assign;
	int main_thread_priority;
	int sub_thread_priority;
	int font_thread_priority;
	int sound_thread_priority;
	int result;
	int reserved1;
	int reserved2;
	int reserved3;
	int reserved4;
} SceUtilityParamBase;
typedef enum { SCE_UTILITY_OSK_BOOL_VALUE_FALSE = 0, SCE_UTILITY_OSK_BOOL_VALUE_TRUE = 1 } SceUtilityOskBoolValue;
typedef enum { SCE_UTILITY_OSK_INPUT_FIELD_RESULT_UNEDITED = 0 } SceUtilityOskInputFieldResult;
typedef struct {
	unsigned int input_method_type;
	unsigned int input_method_attributes;
	unsigned int writing_language_type;
	SceUtilityOskBoolValue hide_mode;
	int input_character_type;
	int num_lines;
	int kinsoku;
	SceWChar16 *message;
	SceWChar16 *init_text;
	unsigned int result_text_buffer_size;
	SceWChar16 *result_text_buffer;
	SceUtilityOskInputFieldResult result;
	unsigned int limit_length;
} SceUtilityOskInputFieldInfo;
typedef struct {
	SceUtilityParamBase base;
	unsigned int num_input_fields;
	SceUtilityOskInputFieldInfo *input_field_info;
	int _38, _3c;
} SceUtilityOskParam;
extern int aInputCharTypeList[];
unsigned char UtilGetMessageLang(void);
int UtilGetAssign(void);
void *memset(void *, int, unsigned int);
void setOskUtilityPraram(unsigned int numInputFields, SceWChar16 **messageString, SceWChar16 **initString,
	SceWChar16 **resultTextBuffer, unsigned int bufferSize, SceUtilityOskInputFieldInfo *inputField,
	SceUtilityOskParam *pParam)
{
	int i;

	memset(pParam, 0x00, sizeof(SceUtilityOskParam));
	pParam->base.size = sizeof(SceUtilityOskParam);
	pParam->base.message_lang = UtilGetMessageLang();
	pParam->base.ctrl_assign = UtilGetAssign();
	pParam->base.main_thread_priority = 0x14 + 1;
	pParam->base.sub_thread_priority = 0x14 + 3;
	pParam->base.font_thread_priority = 0x14 + 2;
	pParam->base.sound_thread_priority = 0x14;
	pParam->base.reserved1 = 0;
	pParam->base.reserved2 = 0;

	pParam->num_input_fields = numInputFields;
	pParam->input_field_info = inputField;

	memset(inputField, 0x00, sizeof(*inputField));

	for (i = 0; i < (int)numInputFields; i++) {
		inputField[i].input_method_type = 1;
		inputField[i].input_method_attributes = 0;
		inputField[i].writing_language_type = 0;
		inputField[i].input_character_type = aInputCharTypeList[i];
		inputField[i].num_lines = 4;
		inputField[i].kinsoku = 1;

		inputField[i].hide_mode = 0;
		inputField[i].message = messageString[i];
		inputField[i].init_text = initString[i];
		inputField[i].result_text_buffer_size = bufferSize;
		inputField[i].result_text_buffer = resultTextBuffer[i];
		inputField[i].result = 0;
		inputField[i].limit_length = 0;
	}

	return;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103130);

unsigned short *textUcs4toUcs2Alloc(int *src, unsigned int n)
{
	unsigned short *buf = _memAlloc(n * 2, &D_00103130, 0xD4);
	unsigned short *d = buf;
	consPrintf(&D_00103158, "textUcs4toUcs2Alloc", src, buf, n);
	while (*src != 0 && n > 1) {
		consPrintf(&D_00103168, "textUcs4toUcs2Alloc", n, *src);
		*d++ = *src++;
		n--;
	}
	*d = 0;
	return buf;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103158);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103168);

int textUcs2toUcs4Free(unsigned short *src, int *dst, unsigned int n)
{
	unsigned short *s = src;
	consPrintf(&D_00103158, "textUcs2toUcs4Free", src, dst, n);
	if (dst != NULL) {
		while (*src != 0 && n > 1) {
			consPrintf(&D_00103168, "textUcs2toUcs4Free", n, *src);
			*dst++ = *src++;
			n--;
		}
		*dst = 0;
	}
	_memFree(s, &D_00103130, 0xF0);
	return 0;
}

extern SceUtilityOskInputFieldInfo *l_pFieldInfo;
extern unsigned char D_001031A0, D_001031B8;
typedef struct { unsigned int *message; unsigned int *init_text; unsigned int *result_text; int method; int char_type; int lines; unsigned int size; int result; } OskReqIn;
typedef struct { int num; OskReqIn **req; } OskCntxIn;
void *_memAllocZero(int, void *, int);
void *localeGetCntx(void);
unsigned short *textUcs4toUcs2Alloc(int *src, unsigned int n);
#define FI(i) ((l_pFieldInfo)[i])
int setOskUtilityParam(OskCntxIn *c, SceUtilityOskParam *pParam)
{
	int i;

	l_ptCntx = c;
	memset(pParam, 0x00, sizeof(SceUtilityOskParam));
	pParam->base.size = sizeof(SceUtilityOskParam);
	pParam->base.message_lang = UtilGetMessageLang();
	pParam->base.ctrl_assign = UtilGetAssign();
	pParam->base.main_thread_priority = 0x14 + 1;
	pParam->base.sub_thread_priority = 0x14 + 3;
	pParam->base.font_thread_priority = 0x14 + 2;
	pParam->base.sound_thread_priority = 0x14;
	pParam->base.reserved1 = 0;
	pParam->base.reserved2 = 0;

	pParam->num_input_fields = c->num;
	pParam->input_field_info = (SceUtilityOskInputFieldInfo *)(l_pFieldInfo = _memAllocZero(c->num * sizeof(SceUtilityOskInputFieldInfo), &D_00103130, 0x110));

	for (i = 0; i < c->num; i++) {
		FI(i).input_method_type = c->req[i]->method;
		FI(i).input_method_attributes = 0;
		FI(i).writing_language_type = M2C_FIELD(localeGetCntx(), int *, 0x18);
		FI(i).hide_mode = 0;
		FI(i).input_character_type = c->req[i]->char_type;
		FI(i).num_lines = c->req[i]->lines;
		FI(i).kinsoku = 1;

		FI(i).message = textUcs4toUcs2Alloc(c->req[i]->message, 0x20);
		FI(i).init_text = textUcs4toUcs2Alloc(c->req[i]->init_text, 0x20);
		FI(i).result_text_buffer_size = c->req[i]->size;
		FI(i).result_text_buffer = textUcs4toUcs2Alloc(c->req[i]->result_text, 0x20);
		FI(i).result = 0;
		FI(i).limit_length = 0;
	}
	consPrintf(&D_001031A0, "setOskUtilityParam", l_pFieldInfo);
	consPrintf(&D_001031B8, "setOskUtilityParam", c);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031B8);

extern SceUtilityOskInputFieldInfo *l_pFieldInfo;
extern unsigned char D_001031A0, D_001031B8;
typedef struct { char pad[8]; int *dst; char pad2[0x1C - 0xC]; int result; } OskReq;
typedef struct { int num; OskReq **req; } OskCntx;
typedef struct { char pad[0x1C]; unsigned short *desc; unsigned short *intext; int pad24; unsigned short *outtext; int result; char pad30[4]; } OskField;
void getOskUtilityTextResult(void)
{
	OskCntx *c = l_ptCntx;
	int i;
	int r;

	consPrintf(&D_001031A0, "getOskUtilityTextResult", l_pFieldInfo);
	consPrintf(&D_001031B8, "getOskUtilityTextResult", c);
	for (i = 0; i < c->num; i++) {
		consPrintf(&D_001031E4, i);
		if (((OskField *)l_pFieldInfo)[i].result == 1)
			consPrintf(&D_001031F4, &D_001031F8);
		else if (((OskField *)l_pFieldInfo)[i].result == 0)
			consPrintf(&D_001031F4, &D_00103228);
		else if (((OskField *)l_pFieldInfo)[i].result == 2)
			consPrintf(&D_001031F4, &D_00103258);
		((OskField *)l_pFieldInfo)[i].desc = (unsigned short *)textUcs2toUcs4Free(((OskField *)l_pFieldInfo)[i].desc, NULL, 0x20);
		((OskField *)l_pFieldInfo)[i].intext = (unsigned short *)textUcs2toUcs4Free(((OskField *)l_pFieldInfo)[i].intext, NULL, 0x20);
		((OskField *)l_pFieldInfo)[i].outtext = (unsigned short *)textUcs2toUcs4Free(((OskField *)l_pFieldInfo)[i].outtext, c->req[i]->dst, 0x20);
		r = 1;
		if (*c->req[i]->dst != 0)
			r = ((OskField *)l_pFieldInfo)[i].result;
		c->req[i]->result = r;
	}
	_memFree(l_pFieldInfo, &D_00103130, 0x154);
	l_pFieldInfo = 0;
	l_ptCntx = NULL;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103228);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103258);

void dumpOskUtilityTextResult(int n, OskData *d)
{
	int i;
	OskData *e;
	unsigned short *p;
	for (i = 0; i < n; i++) {
		consPrintf(&D_001031E4, i);
		e = (OskData *)(i * 52 + (int)d);
		switch (e->result) {
		case 0:
			consPrintf(&D_001031F4, &D_00103228);
			break;
		case 1:
			consPrintf(&D_001031F4, &D_001031F8);
			break;
		case 2:
			consPrintf(&D_001031F4, &D_00103258);
			consPrintf(" [");
			for (p = e->text; *p; p++)
				consPrintf("0x%4.4x ", *p);
			consPrintf("]\n");
			break;
		}
	}
}

void drawPrintf(const char *, ...);
int sceUtilityOskGetStatus(void);
int sceUtilityOskUpdate(int);
int sceUtilityOskShutdownStart(void);
int utility_update_osk(void)
{
	int ret = 0;
	int st = sceUtilityOskGetStatus();
	drawPrintf("Osk : %d:%d\n", st, sample_type_11A910);
	switch (st) {
	case 2:
		ret = sceUtilityOskUpdate(((int *)gameGetCntx())[0x80 / 4] + 1);
		if (ret != 0)
			consPrintf("sceUtilityOskUpdate failed - %d\n", ret);
		break;
	case 3:
		ret = sceUtilityOskShutdownStart();
		if (ret == 0)
			consPrintf("sceUtilityOskShutdownStart ok\n");
		else
			consPrintf("sceUtilityOskShutdownStart failed - %d\n", ret);
		break;
	case 4:
		consPrintf("SCE_UTILITY_COMMON_STATUS_SHUTDOWN\n");
		break;
	case 0:
		consPrintf("SCE_UTILITY_COMMON_STATUS_NONE\n");
		sample_type_11A910 = 0;
		break;
	case 1:
		break;
	}
	return ret;
}

void OnPush_OSK(int a) {
    int temp_v0;

    sample_type_11A910 = 1;
    setOskUtilityParam(a, &osk_param);
    temp_v0 = sceUtilityOskInitStart(&osk_param);
    if (temp_v0 != 0) {
        consPrintf("sceUtilityOskInitStart failed - %d\n", temp_v0);
    }
}

void Lock(int arg0) {
    int *temp_v0;

    gameDisSoftReset();
    gameCtrlLock();
    temp_v0 = gameGetCntx();
    M2C_FIELD(temp_v0, int *, 4) = (int) (M2C_FIELD(temp_v0, int *, 4) | (arg0 != 0));
}

void Unlock(int arg0) {
    int *temp_v0;

    temp_v0 = gameGetCntx();
    M2C_FIELD(temp_v0, int *, 8) = (int) (M2C_FIELD(temp_v0, int *, 8) | (arg0 != 0));
    gameCtrlUnlock();
    gameEnSoftReset();
}

int OskStart(int *p)
{
	consPrintf("OskStart : \n");
	Lock(p[2] & 1);
	if (UtilityLink(utility_update_osk)) {
		OnPush_OSK(p);
		return 1;
	}
	Unlock(p[2] & 1);
	return 0;
}

void OskEnd(void) {
    int temp_s0;

    if (l_ptCntx != NULL) {
        temp_s0 = M2C_FIELD(l_ptCntx, int *, 8);
        getOskUtilityTextResult();
        UtilityUnlink();
        Unlock(temp_s0 & 1);
        consPrintf("OskEnd\n");
    }
}

int OskState(void) {
    return sample_type_11A910 == 1;
}
