#include "common.h"
#include <kernelutils.h>
#include <libgu.h>
#include <displaysvc.h>
#include <stdio.h>
#include <stdlib.h>
#include "pspBrowser.h"
#include "main.h"

extern PSPBROWSER_INI pbrowser_data;
extern char disp_list[2621440];
extern char _cTexMode;
extern char char_sjis0_12[9432];
extern char char_sjis1_12[53370];
extern char char_sjis2_12[61020];
extern char char_ascii_12[2502];
extern char char_sjis0_14[13100];
extern char char_sjis1_14[74125];
extern char char_sjis2_14[84750];
extern char char_ascii_14[2054];
extern char char_sjis0_16[16768];
extern char char_sjis1_16[94880];
extern char char_sjis2_16[108480];
extern char char_ascii_16[2528];
extern char *imageBuffer;

void menubarDraw();

void gCls()
{
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);
	sceGuDisable(4);
	sceGuTexFunc(0, 1);
	sceGuTexMapMode(0, 0, 0);
	sceGuTexWrap(0, 0);
	sceGuTexFilter(1, 1);
	sceGuBlendFunc(0, 2, 3, 0, 0);
}

void browserImageInit(void)
{
	imageBuffer = malloc(0x6e000);
	pbrowser_data.memBrowser = malloc(0x800000);
	pbrowser_data.memBrowserSize = 0x800000;
	pbrowser_data.memCashSize = 0x80000;
	pbrowser_data.memCookie = malloc(0x20000);
	pbrowser_data.memCookieSize = 0x20000;
}

void browserImageExit(void)
{
	free(pbrowser_data.memBrowser);
	free(pbrowser_data.memCookie);
	free(imageBuffer);
}

void browserDraw(void)
{
	int x;
	int y;

	gCls();
	sceGuTexMode(1, 0, 0, 0);
	switch (_cTexMode) {
	case 0:
		sceGuTexImage(0, 512, 256, 480, imageBuffer);
		sceGuSpriteMode(32, 32, 32, 32);
		for (y = 0; y < 256; y += 32)
			for (x = 0; x < 480; x += 32)
				sceGuDrawSprite(x, y + 16, 0, x, y, 0, 0);
		break;
	case 1:
		sceGuTexImage(0, 256, 512, 256, imageBuffer);
		sceGuSpriteMode(32, 32, 32, 32);
		for (y = 0; y < 256; y += 32)
			for (x = 0; x < 480; x += 32)
				sceGuDrawSprite(x, y + 16, 0, y, 448 - x, 0, 3);
		break;
	case 2:
		sceGuTexImage(0, 512, 512, 640, imageBuffer);
		sceGuSpriteMode(32, 32, 24, 24);
		for (y = 0; y < 256; y += 24)
			for (x = 0; x < 384; x += 24)
				sceGuDrawSprite(x, y + 16, 0, x * 32 / 24, y * 32 / 24, 0, 0);
		sceGuTexImage(0, 512, 512, 640, imageBuffer + 0x400);
		for (y = 0; y < 256; y += 24)
			for (x = 0; x < 96; x += 24)
				sceGuDrawSprite(x + 384, y + 16, 0, x * 32 / 24, y * 32 / 24, 0, 0);
		break;
	case 3:
		sceGuTexImage(0, 512, 512, 352, imageBuffer + 0x15500);
		sceGuSpriteMode(32, 32, 24, 24);
		for (y = 0; y < 256; y += 24)
			for (x = 0; x < 384; x += 24)
				sceGuDrawSprite(x, y + 16, 0, y * 32 / 24, 480 - x * 32 / 24, 0, 3);
		sceGuTexImage(0, 512, 512, 352, imageBuffer);
		for (y = 0; y < 256; y += 24)
			for (x = 0; x < 96; x += 24)
				sceGuDrawSprite(x + 384, y + 16, 0, y * 32 / 24, 96 - x * 32 / 24, 0, 3);
		break;
	}
	menubarDraw();
}

void imageCls(void)
{
	int i;

	for (i = 0; i < 0x6e000; i++)
		imageBuffer[i] = 0xff;
}

void onFocus(char *url, char *oaram)
{
	sePlay(0);
}

int browserStart(char *url_data, int cf)
{
	imageCls();
	pbrowser_data.image = imageBuffer;
	switch (_cTexMode) {
	case 0:
		pbrowser_data.imageWidth = 480;
		pbrowser_data.imageHeight = 256;
		pbrowser_data.browserWidth = 480;
		pbrowser_data.browserHeight = 256;
		break;
	case 1:
		pbrowser_data.imageWidth = 256;
		pbrowser_data.imageHeight = 480;
		pbrowser_data.browserWidth = 256;
		pbrowser_data.browserHeight = 480;
		break;
	case 2:
		pbrowser_data.imageWidth = 640;
		pbrowser_data.imageHeight = 341;
		pbrowser_data.browserWidth = 640;
		pbrowser_data.browserHeight = 341;
		break;
	case 3:
		pbrowser_data.imageWidth = 352;
		pbrowser_data.imageHeight = 640;
		pbrowser_data.browserWidth = 352;
		pbrowser_data.browserHeight = 640;
		break;
	}
	pbrowser_data.uid = "MY_UID";
	pbrowser_data.homeURL = pHome;
	pbrowser_data.backcolor = "#FFFFFF";
	pbrowser_data.mode = cf | 0x07000000;
	pbrowser_data.thread = 0x41;
	switch (_cFontSize) {
	case 0:
		pbrowser_data.fontSize = 12;
		pbrowser_data.character0 = char_ascii_12;
		pbrowser_data.character1 = char_sjis0_12;
		pbrowser_data.character2 = char_sjis1_12;
		pbrowser_data.character3 = char_sjis2_12;
		break;
	case 1:
		pbrowser_data.fontSize = 14;
		pbrowser_data.character0 = char_ascii_14;
		pbrowser_data.character1 = char_sjis0_14;
		pbrowser_data.character2 = char_sjis1_14;
		pbrowser_data.character3 = char_sjis2_14;
		break;
	case 2:
		pbrowser_data.fontSize = 16;
		pbrowser_data.character0 = char_ascii_16;
		pbrowser_data.character1 = char_sjis0_16;
		pbrowser_data.character2 = char_sjis1_16;
		pbrowser_data.character3 = char_sjis2_16;
		break;
	}
	pbrowser_data.userAgent = pUserAgent;
	pbrowser_data.mimetype0 = "application/x-psp";
	pbrowser_data.mimetype1 = NULL;
	pbrowser_data.mimetype2 = NULL;
	pbrowser_data.mimetype3 = NULL;
	puts("pspBrowserInit");
	if (pspBrowserInit(&pbrowser_data) != 0) {
		puts("[ ERROR  ] - pspBrowserInit");
		return 1;
	}
	pspBrowserSetFocusCallback(onFocus);
	addDownload();
	if (mepgAdd() != 0) {
		puts("[ ERROR  ] - mepgAdd");
		return 1;
	}
	if (mp3Add() != 0) {
		puts("[ ERROR  ] - mp3Add");
		return 1;
	}
	puts("PSPBROWSER_COMMAND_SET_URL");
	if (pspBrowserSetState(0x18, url_data) != 0) {
		puts("[ ERROR  ] - pspBrowserSetState");
		return 1;
	}
	return 5;
}

int browserInit(void)
{
	return browserStart(pHome, 0);
}

int browserExec(void)
{
	PSPBROWSER_INPUT keyData;
	int padOld;
	int padon;
	int padin;
	int rslt;

	pspBrowserSetState(0xc, imageBuffer);
	padOld = 0;
	while (iPspBrowserApMode == PSP_BROWSER_EXEC) {
		keyData.input = 0;
		padin = mainPadRead();
		padon = ~padOld & padin;
		padOld = padin;
		switch (_cTexMode) {
		case 0:
		case 2:
			if (padin & 0x10)
				keyData.input |= 1;
			if (padin & 0x40)
				keyData.input |= 2;
			if (padin & 0x80)
				keyData.input |= 4;
			if (padin & 0x20)
				keyData.input |= 8;
			break;
		case 1:
		case 3:
			if (padin & 0x10)
				keyData.input |= 4;
			if (padin & 0x40)
				keyData.input |= 8;
			if (padin & 0x80)
				keyData.input |= 2;
			if (padin & 0x20)
				keyData.input |= 1;
			break;
		}
		if (padin & 0x2000)
			keyData.input |= 0x10;
		if (padin & 0x4000)
			keyData.input |= 0x20;
		if (padon & 0x100) {
			sePlay(1);
			pspBrowserSetState(2, NULL);
		}
		if (padon & 0x200) {
			if (_cTexMode == 1) {
				keyData.input |= 0x10;
			} else {
				sePlay(1);
				pspBrowserSetState(3, NULL);
			}
		}
		if (padon & 0x8000) {
			PSPBROWSER_GET_URL pspGetUrl;
			char url_data[320];

			pspGetUrl.url = url_data;
			pspGetUrl.length = 320;
			pspBrowserGetState(0x18, &pspGetUrl);
			printf("URI %s \n", url_data);
		}
		if (padon & 0x1000) {
			sePlay(1);
			return PSP_BROWSER_MENU;
		}
		if (padon & 0x2000)
			sePlay(1);
		if (padon & 0x4000)
			sePlay(2);
		rslt = pspBrowserExec(&keyData);
		switch (rslt & 0xffff) {
		case 23:
			sceKernelDcacheWritebackInvalidateAll();
			pspBrowserSetState(0x17, NULL);
			break;
		case 16:
			return PSP_BROWSER_INPUT;
		case 17:
			return PSP_BROWSER_ALERT;
		case 18:
			return PSP_BROWSER_CONFIRM;
		case 20:
			return PSP_BROWSER_PASSWORD;
		case 21:
			return PSP_BROWSER_SSL_IN;
		case 22:
			return PSP_BROWSER_SSL_OUT;
		case 24:
			return PSP_BROWSER_READERROR;
		case 25:
			return PSP_BROWSER_FATALERROR;
		case 32:
			return PSP_BROWSER_DOWNLOAD;
		}
		browserDraw();
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		if (_cPspBrowserExit)
			return 4;
	}
	return iPspBrowserApMode;
}

void browserEnd()
{
	pspBrowserSetState(-1, NULL);
	while ((pspBrowserExec(NULL) & 0x08000000) == 0) {
		browserDraw();
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
	}
	pspBrowserExit();
}

int browserExit(void)
{
	browserEnd();
	return 1;
}

int browserFontEX(void)
{
	PSPBROWSER_GET_URL pspGetUrl;
	char url_data[320];
	int ret;
	int i;

	pspGetUrl.url = url_data;
	pspGetUrl.length = 320;
	pspBrowserGetState(0x18, &pspGetUrl);
	browserEnd();
	ret = browserStart(url_data, 1);
	for (i = 0; i < 4; i++) {
		gCls();
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
	}
	return ret;
}
