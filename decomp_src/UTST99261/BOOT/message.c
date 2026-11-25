#include "common.h"
#include <psptypes.h>
#include <kernelutils.h>
#include <libgu.h>
#include <pspnet_apctl.h>
#include <power.h>
#include <rtc.h>
#include <stdio.h>
#include <math.h>
#include "pspBrowser.h"
#include "main.h"
#include "message.h"

extern short int messTex[65536];
extern short int barTex[16384];
extern short int messBoxImage[32768];
extern short int messBoxBr[64];
extern int _iMessMode;
extern int _iMessCount;
extern MESS_OBJ _sMessObj[40];
extern int _iMessObjCont;
extern char _cMessLcount;
extern int _iMessPadOld;
extern int _iMessObjSelect;
extern char _iBrAnim;

void messObjDraw(void);
void number22(int x, int a);
void number02(int x, int a);
int fontCls(int in_start, int in_size);
int fontPrint(int x, int y, char *str, int s_size, int ww, int hh);
int fontPassword(int x, int y, char *str, int s_size, int ww, int hh);
int fontDraw(short int *im, int in_start, int in_size);

int messInit(void)
{
	int i;

	for (i = 0; i < 32768; i++)
		messBoxImage[i] = 0;
	for (i = 0; i < 64; i++)
		messBoxBr[i] = 0;
	_iMessMode = 1;
	_iMessObjSelect = -1;
	_iMessObjCont = 0;
	_cMessLcount = 0;
	_iMessPadOld = 0;
	return 0;
}

int messExit(void)
{
	_iMessMode = 0;
	return 0;
}

int messStart(void)
{
	int i;

	if (_iMessMode == 0)
		return -1;
	_iMessMode = 2;
	_iMessObjSelect = -1;
	_iMessCount = 0;
	_iMessObjCont = 0;
	_iMessPadOld = 0;
	for (i = 0; i < 40; i++)
		_sMessObj[i].type = 0;
	return 0;
}

void messBlack(int cc)
{
	int col;

	sceGuEnable(4);
	col = cc * 200 / 255;
	col = (col << 16) | (col << 8) | col;
	sceGuBlendFunc(0, 10, 10, col, ~col);
	sceGuTexMode(1, 0, 0, 0);
	sceGuTexImage(0, 8, 8, 8, messBoxBr);
	sceGuSpriteMode(8, 8, 480, 272);
	sceGuDrawSprite(0, 0, 0, 0, 0, 0, 0);
}

int messExec(int ti)
{
	int col;
	int padin;
	int padon;
	int i;
	int obj_no;

	switch (_iMessMode) {
	case 0:
	case 1:
		return -1;
	case 2:
		_iMessCount += ti * 32;
		if (_iMessCount > 250) {
			_iMessCount = 255;
			_iMessMode = 3;
		}
		break;
	case 4:
		_iMessCount -= ti * 32;
		if (_iMessCount < 0) {
			_iMessMode = 1;
			_iMessCount = 0;
			puts("mess end en");
		}
		break;
	}
	sceGuEnable(4);
	col = _iMessCount * 200 / 255;
	col = (col << 16) | (col << 8) | col;
	sceGuBlendFunc(0, 10, 10, col, ~col);
	sceGuTexMode(1, 0, 0, 0);
	sceGuTexImage(0, 8, 8, 8, messBoxBr);
	sceGuSpriteMode(8, 8, 480, 272);
	sceGuDrawSprite(0, 0, 0, 0, 0, 0, 0);
	sceGuTexImage(0, 256, 256, 256, messTex);
	if (_iMessObjSelect != -1) {
		col = sin(_cMessLcount * 3.14159 / 128.0) * 127.0 + 128.0;
		col = (col << 16) | (col << 8) | col;
		sceGuBlendFunc(0, 10, 10, col, 0xffffff);
		switch (_sMessObj[_iMessObjSelect].type & 0xc0) {
		case 0x40:
			sceGuSpriteMode(168, 20, 168, 20);
			sceGuDrawSprite(_sMessObj[_iMessObjSelect].x + 64, _sMessObj[_iMessObjSelect].y, 0, 88, 52, 0, 0);
			break;
		case 0x80:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[_iMessObjSelect].x, _sMessObj[_iMessObjSelect].y, 0, 156, 236, 0, 0);
			break;
		}
	}
	col = _iMessCount;
	col = (col << 16) | (col << 8) | col;
	sceGuBlendFunc(0, 10, 10, col, 0xffffff);
	sceGuSpriteMode(256, 16, 256, 16);
	sceGuDrawSprite(107, 80, 0, 0, 0, 0, 0);
	sceGuSpriteMode(256, 16, 256, 16);
	sceGuDrawSprite(107, 176, 0, 0, 16, 0, 0);
	messObjDraw();
	_cMessLcount += ti * 6;
	if (_iMessMode != 3)
		return _iMessMode;
	if (_iMessObjSelect == -1)
		return 3;
	padin = mainPadRead();
	padon = _iMessPadOld & ~padin;
	if (padon & 0x2000) {
		_iMessPadOld = padin;
		sePlay(1);
		return _sMessObj[_iMessObjSelect].tData;
	}
	padon = ~_iMessPadOld & padin;
	_iMessPadOld = padin;
	if (padon & 0x90) {
		sePlay(0);
		obj_no = _iMessObjSelect - 1;
		if (obj_no == -1)
			obj_no = 39;
		for (i = 0; i < 40; i++) {
			if (_sMessObj[obj_no].type & 0xc0) {
				_iMessObjSelect = obj_no;
				_cMessLcount = 0;
				return _iMessMode;
			}
			obj_no--;
			if (obj_no == -1)
				obj_no = 39;
		}
	}
	if (padon & 0x60) {
		sePlay(0);
		obj_no = _iMessObjSelect + 1;
		if (obj_no == 40)
			obj_no = 0;
		for (i = 0; i < 40; i++) {
			if (_sMessObj[obj_no].type & 0xc0) {
				_iMessObjSelect = obj_no;
				_cMessLcount = 0;
				return _iMessMode;
			}
			obj_no++;
			if (obj_no == 40)
				obj_no = 0;
		}
	}
	return _iMessMode;
}

int messEnd(void)
{
	if (_iMessMode < 2)
		return -1;
	if (_iMessMode == 4)
		return -1;
	_iMessMode = 4;
	return 0;
}

int messObjCreate(char type, int x, int y, char *str, int strLen, int tData)
{
	int obj_no;

	if (_iMessObjCont >= 40)
		return -1;
	for (obj_no = 0; _sMessObj[obj_no].type != 0; obj_no++)
		;
	_sMessObj[obj_no].x = x;
	_sMessObj[obj_no].y = y;
	_sMessObj[obj_no].tData = tData;
	_sMessObj[obj_no].messData = str;
	_sMessObj[obj_no].messSize = strLen;
	_sMessObj[obj_no].type = type;
	_sMessObj[obj_no].mode = 0;
	if ((type & 0xc0) && _iMessObjSelect == -1)
		_iMessObjSelect = obj_no;
	_iMessObjCont++;
	return obj_no;
}

int messObjDel(int obj_no)
{
	if (obj_no < 0)
		return 0;
	if (obj_no >= 40)
		return 0;
	if (_sMessObj[obj_no].type != 0) {
		_sMessObj[obj_no].type = 0;
		_iMessObjCont--;
	}
	if (obj_no == _iMessObjSelect) {
		_iMessObjSelect = -1;
		for (obj_no = 0; obj_no < 40; obj_no++) {
			if (_sMessObj[obj_no].type & 0xc0) {
				_iMessObjSelect = obj_no;
				return 0;
			}
		}
	}
	return 0;
}

int messObjStateSet(int obj_no, int a)
{
	_sMessObj[obj_no].tData = a;
	return 0;
}

int messObjStrSet(int obj_no, char *st, int len)
{
	_sMessObj[obj_no].messData = st;
	_sMessObj[obj_no].messSize = len;
	_sMessObj[obj_no].mode = 0;
	return 0;
}

void messObjDraw(void)
{
	int type;
	int obj_no;
	int i;

	if (_iMessObjCont == 0)
		return;
	for (i = 0; i < 40; i++) {
		switch (_sMessObj[i].type & 0xdf) {
		case 1:
			sceGuSpriteMode(100, 17, 100, 17);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 56, 93, 0, 0);
			break;
		case 2:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 56, 110, 0, 0);
			break;
		case 3:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 56, 128, 0, 0);
			break;
		case 4:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 56, 146, 0, 0);
			break;
		case 5:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 56, 164, 0, 0);
			break;
		case 7:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 56, 200, 0, 0);
			break;
		case 8:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 56, 218, 0, 0);
			break;
		case 9:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 56, 236, 0, 0);
			break;
		case 10:
			sceGuSpriteMode(40, 20, 40, 20);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 16, 74, 0, 0);
			break;
		case 23:
			if (_sMessObj[i].mode == 0) {
				fontCls(0, 0x4000);
				fontPrint(0, 0, _sMessObj[i].messData, _sMessObj[i].messSize, _sMessObj[i].tData, 64);
				fontDraw(messBoxImage, 0, 0x4000);
				_sMessObj[i].mode = 1;
				sceKernelDcacheWritebackInvalidateAll();
			} else if (_sMessObj[i].mode != 1) {
				break;
			}
			sceGuTexImage(0, 256, 128, 256, messBoxImage);
			sceGuSpriteMode(_sMessObj[i].tData, 64, _sMessObj[i].tData, 64);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 0, 0, 0, 0);
			sceGuTexImage(0, 256, 256, 256, messTex);
			break;
		case 24:
			sceGuSpriteMode(16, 16, 16, 16);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 24, 58, 0, 0);
			break;
		case 25:
			sceGuSpriteMode(16, 16, 16, 16);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 40, 58, 0, 0);
			break;
		case 26:
			type = _sMessObj[i].tData * 2;
			sceGuSpriteMode(8, 20, 200, 20);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 16, 52, 0, 0);
			if (type != 0) {
				sceGuSpriteMode(8, 20, type, 20);
				sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 16, 32, 0, 0);
			}
			sceGuSpriteMode(200, 20, 200, 20);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 56, 72, 0, 0);
			break;
		case 85:
			if (_sMessObj[i].mode == 0) {
				fontCls(0x4000, 0x1000);
				fontPrint(0, 64, _sMessObj[i].messData, _sMessObj[i].messSize, 256, 16);
				fontDraw(messBoxImage, 0x4000, 0x1000);
				_sMessObj[i].mode = 1;
				sceKernelDcacheWritebackInvalidateAll();
			} else if (_sMessObj[i].mode != 1) {
				break;
			}
			sceGuTexImage(0, 256, 128, 256, messBoxImage);
			sceGuSpriteMode(256, 16, 256, 16);
			sceGuDrawSprite(_sMessObj[i].x + 68, _sMessObj[i].y + 2, 0, 0, 64, 0, 0);
			sceGuTexImage(0, 256, 256, 256, messTex);
			sceGuSpriteMode(64, 13, 64, 13);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y + 3, 0, 24, 32, 0, 0);
			sceGuSpriteMode(168, 20, 168, 20);
			sceGuDrawSprite(_sMessObj[i].x + 64, _sMessObj[i].y, 0, 88, 32, 0, 0);
			break;
		case 86:
			if (_sMessObj[i].mode == 0) {
				fontCls(0x5000, 0x1000);
				fontPassword(0, 83, _sMessObj[i].messData, _sMessObj[i].messSize, 256, 16);
				fontDraw(messBoxImage, 0x5000, 0x1000);
				_sMessObj[i].mode = 1;
				sceKernelDcacheWritebackInvalidateAll();
			} else if (_sMessObj[i].mode != 1) {
				break;
			}
			sceGuTexImage(0, 256, 128, 256, messBoxImage);
			sceGuSpriteMode(256, 16, 256, 16);
			sceGuDrawSprite(_sMessObj[i].x + 68, _sMessObj[i].y + 2, 0, 0, 80, 0, 0);
			sceGuTexImage(0, 256, 256, 256, messTex);
			sceGuSpriteMode(64, 13, 64, 13);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y + 3, 0, 24, 45, 0, 0);
			sceGuSpriteMode(168, 20, 168, 20);
			sceGuDrawSprite(_sMessObj[i].x + 64, _sMessObj[i].y, 0, 88, 32, 0, 0);
			break;
		case 140:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 156, 92, 0, 0);
			break;
		case 141:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 156, 110, 0, 0);
			break;
		case 142:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 156, 128, 0, 0);
			break;
		case 143:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 156, 146, 0, 0);
			break;
		case 144:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 156, 164, 0, 0);
			break;
		case 146:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 156, 218, 0, 0);
			break;
		case 147:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 156, 200, 0, 0);
			break;
		case 148:
			sceGuSpriteMode(100, 18, 100, 18);
			sceGuDrawSprite(_sMessObj[i].x, _sMessObj[i].y, 0, 156, 182, 0, 0);
			break;
		}
	}
}

void number22(int x, int a)
{
	int a1;
	int a2;

	a1 = a / 10;
	a2 = a % 10;
	if (a1 > 9)
		a1 = 0;
	sceGuDrawSprite(x, 0, 0, a1 * 10 + 288, 16, 0, 0);
	sceGuDrawSprite(x + 10, 0, 0, a2 * 10 + 288, 16, 0, 0);
}

void number02(int x, int a)
{
	int a1;
	int a2;

	a1 = a / 10;
	a2 = a % 10;
	if (a1 > 9)
		a1 = 0;
	if (a1 != 0)
		sceGuDrawSprite(x, 0, 0, a1 * 10 + 288, 16, 0, 0);
	sceGuDrawSprite(x + 10, 0, 0, a2 * 10 + 288, 16, 0, 0);
}

void menubarDraw()
{
	union SceNetApctlInfo netInfo;
	PSPBROWSER_GET_STATE pspGetState;
	ScePspDateTime getTime;
	int rr;

	pspBrowserGetState(8, &pspGetState);
	sceGuTexImage(0, 512, 32, 512, barTex);
	sceGuSpriteMode(480, 16, 480, 16);
	sceGuDrawSprite(0, 0, 0, 0, 0, 0, 0);
	sceGuSpriteMode(17, 16, 17, 16);
	if (pspGetState.state & 0x40000000) {
		_iBrAnim++;
		if (_iBrAnim == 32)
			_iBrAnim = 0;
	}
	sceGuDrawSprite(24, 0, 0, (_iBrAnim / 4) * 17 + 152, 16, 0, 0);
	if (_iSslOn == 1)
		sceGuDrawSprite(43, 0, 0, 404, 16, 0, 0);
	sceGuSpriteMode(19, 16, 19, 16);
	sceNetApctlGetInfo(5, &netInfo);
	rr = (netInfo.rssi + 20) / 4;
	if (rr < 0)
		rr = 0;
	if (rr > 3)
		rr = 3;
	sceGuDrawSprite(3, 0, 0, rr * 19, 16, 0, 0);
	rr = (scePowerGetBatteryLifePercent() + 20) / 4;
	if (rr < 0)
		rr = 0;
	if (rr > 3)
		rr = 3;
	sceGuBlendFunc(4, 10, 10, 0x808080, 0xffffff);
	sceGuDrawSprite(460, 0, 0, rr * 19 + 76, 16, 0, 0);
	sceGuSpriteMode(8, 16, 8, 16);
	sceGuDrawSprite(370, 0, 0, 396, 16, 0, 0);
	sceGuDrawSprite(425, 0, 0, 388, 16, 0, 0);
	sceGuSpriteMode(10, 16, 10, 16);
	sceRtcGetCurrentClockLocalTime(&getTime);
	number02(350, getTime.month);
	number22(378, getTime.day);
	number02(405, getTime.hour);
	number22(433, getTime.minute);
}
