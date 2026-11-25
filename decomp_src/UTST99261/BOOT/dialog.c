#include "common.h"
#include <psptypes.h>
#include <utility/utility_osk.h>
#include <libgu.h>
#include <displaysvc.h>
#include <stdio.h>
#include <string.h>
#include "pspBrowser.h"
#include "main.h"
#include "message.h"

typedef unsigned short SceFont_t_u16;
typedef SceFont_t_u16 SceFont_t_charCode;

int utf8ToUcs2(SceFont_t_charCode *ucs2, char *utf8, int len);
int ucs2ToUtf8(char *utf8, SceFont_t_charCode *ucs2, int len);

/* inputExec's static locals, kept in the asm .bss for now */
extern SceUtilityOskParam D_00219368;
extern SceUtilityOskInputFieldInfo D_002193A8;
extern SceFont_t_charCode D_002193DC[320];
extern SceFont_t_charCode D_0021965C[320];

int browserAlert(void)
{
	PSPBROWSER_GET_ALERT pspGetAlert;
	char alert_data[320];
	int ret;

	puts("pspBrowser [ ALERT ]");
	pspGetAlert.alert = alert_data;
	pspGetAlert.length = 320;
	pspBrowserGetState(0x11, &pspGetAlert);
	messStart();
	messObjCreate(1, 185, 60, NULL, 0, 0);
	messObjCreate(0x8c, 185, 190, NULL, 0, 5);
	messObjCreate(0x18, 96, 128, NULL, 0, 0);
	messObjCreate(0x17, 112, 105, alert_data, pspGetAlert.getLength, 256);
	do {
		browserDraw();
		ret = messExec(1);
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		if (ret == 5)
			messEnd();
		if (_cPspBrowserExit)
			return 4;
	} while (ret != 1);
	pspBrowserSetState(0x11, NULL);
	puts("alert end");
	return 5;
}

int browserConfirm(void)
{
	PSPBROWSER_GET_CONFIRM pspGetConfirm;
	PSPBROWSER_SET_CONFIRM pspSetConfirm;
	char confirm_data[320];
	int ret;

	puts("pspBrowser [ CONFIRM ]");
	pspGetConfirm.confirm = confirm_data;
	pspGetConfirm.length = 320;
	pspBrowserGetState(0x12, &pspGetConfirm);
	messStart();
	messObjCreate(2, 185, 60, NULL, 0, 0);
	messObjCreate(0x8c, 130, 190, NULL, 0, 5);
	messObjCreate(0x8d, 240, 190, NULL, 0, 6);
	messObjCreate(0x19, 96, 128, NULL, 0, 0);
	messObjCreate(0x17, 112, 105, confirm_data, pspGetConfirm.getLength, 256);
	do {
		browserDraw();
		ret = messExec(1);
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		if (ret == 5) {
			messEnd();
			pspSetConfirm.state = 0;
			pspBrowserSetState(0x12, &pspSetConfirm);
		}
		if (ret == 6) {
			messEnd();
			pspSetConfirm.state = -1;
			pspBrowserSetState(0x12, &pspSetConfirm);
		}
		if (_cPspBrowserExit)
			return 4;
	} while (ret != 1);
	puts("confirm end");
	return 5;
}

int browserSslIn(void)
{
	int ret;

	puts("pspBrowser [ SSL IN ]");
	messStart();
	messObjCreate(4, 185, 60, NULL, 0, 0);
	messObjCreate(0x8c, 185, 190, NULL, 0, 5);
	do {
		browserDraw();
		ret = messExec(1);
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		if (ret == 5) {
			_iSslOn = 1;
			messEnd();
		}
		if (_cPspBrowserExit)
			return 4;
	} while (ret != 1);
	pspBrowserSetState(0x15, NULL);
	puts("ssl in end");
	return 5;
}

int browserSslOut(void)
{
	PSPBROWSER_SET_SSL_OUT pspSetSslout;
	int ret;

	puts("pspBrowser [ SSL OUT ]");
	messStart();
	messObjCreate(5, 185, 60, NULL, 0, 0);
	messObjCreate(0x8c, 130, 190, NULL, 0, 5);
	messObjCreate(0x8d, 240, 190, NULL, 0, 6);
	do {
		browserDraw();
		ret = messExec(1);
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		if (ret == 5) {
			_iSslOn = 0;
			messEnd();
			pspSetSslout.state = 0;
			pspBrowserSetState(0x16, &pspSetSslout);
		}
		if (ret == 6) {
			messEnd();
			pspSetSslout.state = -1;
			pspBrowserSetState(0x16, &pspSetSslout);
		}
		if (_cPspBrowserExit)
			return 4;
	} while (ret != 1);
	puts("aal out end");
	return 5;
}

int browserFatalerror(void)
{
	pspBrowserSetState(0x19, NULL);
	return 5;
}

int browserInput(void)
{
	PSPBROWSER_GET_INPUT pspGetInput;
	unsigned char szBrwInput[321];
	int aa;

	puts("pspBrowser [ input ]");
	pspGetInput.input = (char *)szBrwInput;
	pspGetInput.length = 321;
	pspBrowserGetState(0x10, &pspGetInput);
	aa = inputExec((char *)szBrwInput, pspGetInput.getLength, 1);
	if (aa)
		pspBrowserSetState(0x10, szBrwInput);
	else
		pspBrowserSetState(0x10, NULL);
	return 5;
}

#define osk_param D_00219368
#define oskInputFieldInfo D_002193A8
#define ucs2_in D_002193DC
#define ucs2_out D_0021965C

#ifdef NON_MATCHING
/* Close: register choice for co and the block layout of the switch's
   returns differ. */
int inputExec(char *moji, int m_size, int mod)
{
	int ret;
	int aa;
	int i;
	int e;
	int status;
	int co;

	memset(ucs2_in, 0, sizeof(ucs2_in));
	memset(ucs2_out, 0, sizeof(ucs2_out));
	aa = utf8ToUcs2(ucs2_in, moji, m_size);
	ucs2_in[aa] = 0;
	memset(&osk_param, 0, sizeof(osk_param));
	osk_param.base.size = sizeof(osk_param);
	osk_param.base.message_lang = 0;
	osk_param.base.ctrl_assign = 0;
	osk_param.base.main_thread_priority = 0x11;
	osk_param.base.sub_thread_priority = 0x13;
	osk_param.base.font_thread_priority = 0x12;
	osk_param.base.sound_thread_priority = 0x10;
	osk_param.base.reserved1 = 0;
	osk_param.base.reserved2 = 0;
	osk_param.num_input_fields = 1;
	osk_param.input_field_info = &oskInputFieldInfo;
	oskInputFieldInfo.input_method_type = 1;
	oskInputFieldInfo.input_method_attributes = 0;
	oskInputFieldInfo.writing_language_type = 0;
	oskInputFieldInfo.hide_mode = 0;
	oskInputFieldInfo.input_character_type = 0;
	oskInputFieldInfo.num_lines = 4;
	oskInputFieldInfo.kinsoku = 1;
	oskInputFieldInfo.message = NULL;
	oskInputFieldInfo.init_text = ucs2_in;
	oskInputFieldInfo.result_text_buffer_size = 320;
	oskInputFieldInfo.result_text_buffer = ucs2_out;
	oskInputFieldInfo.result = 0;
	oskInputFieldInfo.limit_length = 0;
	ret = sceUtilityOskInitStart(&osk_param);
	if (ret != 0)
		return 0;
	if (mod == 1)
		co = 0;
	else
		co = 255;
	e = 0;
	do {
		browserDraw();
		if (co < 255) {
			co += 24;
			if (co > 250)
				co = 255;
		}
		messBlack(co);
		sceGuFinish();
		sceGuSync(0, 0);
		status = sceUtilityOskGetStatus();
		switch (status) {
		case 1:
			break;
		case 2:
			if (sceUtilityOskUpdate(1))
				e = -1;
			break;
		case 0:
		case 4:
			return aa;
		case 3:
			if (sceUtilityOskShutdownStart())
				e = -1;
			for (i = 0; ucs2_out[i] != 0; i++)
				;
			aa = ucs2ToUtf8(moji, ucs2_out, i);
			moji[aa] = 0;
			break;
		}
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
	} while (e == 0);
	return ~e & aa;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/dialog", inputExec);
#endif
