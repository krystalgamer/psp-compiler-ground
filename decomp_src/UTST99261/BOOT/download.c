#include "common.h"
#include <kerneltypes.h>
#include <iofilemgr.h>
#include <libgu.h>
#include <displaysvc.h>
#include <stdio.h>
#include <string.h>
#include "pspBrowser.h"
#include "main.h"
#include "message.h"

extern char save_buff[65536];
extern char DOWNLOADSAVEFILENAME[320];
extern int iDownloadSize;
extern int save_size;
extern SceUID DOWNLOADSAVEFD;

int downloadCallback(void *readBuff, int readSize);
int downloadCallbackF(char *filename, char *data);

int browserDownload(void)
{
	PSPBROWSER_GET_DOWNLOAD pspGetDownload;
	char filename[320];
	char mimetype[320];

	puts("pspBrowser [ DOWNLAOD ]");
	pspGetDownload.url = filename;
	pspGetDownload.length = 320;
	pspGetDownload.mime = mimetype;
	pspGetDownload.mimeLength = 320;
	pspBrowserGetState(0x20, &pspGetDownload);
	return 0x10;
}

int addDownload(void)
{
	pspBrowserAddAnchor("download", downloadCallbackF);
	strcpy(DOWNLOADSAVEFILENAME, "ms0:/download.txt");
	return 0;
}

int contentDownload(void)
{
	PSPBROWSER_GET_DOWNLOAD pspGetDownload;
	PSPBROWSER_SET_DOWNLOAD_START pspSetDownloadStart;
	char filename[320];
	char mimetype[320];
	int ret;
	int d_mode;
	int bh;

	pspGetDownload.url = filename;
	pspGetDownload.length = 320;
	pspGetDownload.mime = mimetype;
	pspGetDownload.mimeLength = 320;
	pspBrowserGetState(0x20, &pspGetDownload);
	d_mode = 0;
	messStart();
	messObjCreate(8, 185, 60, NULL, 0, 0);
	bh = messObjCreate(0x8c, 130, 190, NULL, 0, 5);
	messObjCreate(0x8d, 240, 190, NULL, 0, 6);
	iDownloadSize = 0;
	do {
		pspBrowserExec(0);
		browserDraw();
		ret = messExec(1);
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		switch (ret) {
		case 1:
			d_mode = 1;
			break;
		case 5:
			pspBrowserSetState(0x20, NULL);
			d_mode = 2;
			break;
		case 6:
			pspBrowserSetState(0x22, NULL);
			messEnd();
			break;
		}
		if (_cPspBrowserExit)
			return 4;
	} while (d_mode == 0);
	if (d_mode == 1)
		return 5;

	save_size = 0;
	messObjDel(bh);
	bh = messObjCreate(0x1a, 135, 150, NULL, 0, 0);
	DOWNLOADSAVEFD = sceIoOpen(DOWNLOADSAVEFILENAME, 0x602, 0x1ff);
	pspSetDownloadStart.url = filename;
	pspSetDownloadStart.callback = downloadCallback;
	pspBrowserSetState(0x21, &pspSetDownloadStart);
	while (d_mode == 2) {
		messObjStateSet(bh, iDownloadSize * 100 / pspGetDownload.contentSize);
		ret = pspBrowserExec(0);
		switch (ret & 0xffff) {
		case 0:
		case 34:
			break;
		case 35:
			printf("ddownload err 001 [ %d ]\n", ret);
			d_mode = 10;
			break;
		case 25:
			printf("ddownload err 003 [ %d ]\n", ret);
			d_mode = 12;
			break;
		default:
			printf("ddownload err 004 [ %d ]\n", ret);
			break;
		case 36:
			printf("ddownload err 002 [ %d ]\n", ret);
			d_mode = 11;
			break;
		}
		browserDraw();
		ret = messExec(1);
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		if (ret == 1) {
			printf("ddownload end", 1);
			d_mode = 1;
		} else if (ret == 6) {
			pspBrowserSetState(0x22, NULL);
			messEnd();
		}
		if (_cPspBrowserExit)
			return 4;
	}
	if (iDownloadSize == pspGetDownload.contentSize) {
		if (save_size != 0) {
			sceIoWrite(DOWNLOADSAVEFD, save_buff, save_size);
			save_size = 0;
		}
		sceIoClose(DOWNLOADSAVEFD);
	} else {
		puts("download error");
		sceIoClose(DOWNLOADSAVEFD);
		d_mode = 1;
		sceIoRemove(DOWNLOADSAVEFILENAME);
	}
	strcpy(DOWNLOADSAVEFILENAME, "ms0:/download.txt");
	if (d_mode == 1)
		return 5;
	pspBrowserSetState(0x23, NULL);
	messEnd();
	while (ret != 1) {
		browserDraw();
		ret = messExec(1);
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		if (_cPspBrowserExit)
			return 4;
	}
	return 5;
}

int downloadCallback(void *readBuff, int readSize)
{
	int aa;

	iDownloadSize += readSize;
	if (save_size + readSize > 0x10000) {
		aa = sceIoWrite(DOWNLOADSAVEFD, save_buff, save_size);
		if (aa != save_size)
			return -1;
		save_size = 0;
	}
	save_size += readSize;
	return readSize;
}

int downloadCallbackF(char *filename, char *data)
{
	pspBrowserSetState(1, NULL);
	strcpy(DOWNLOADSAVEFILENAME, data);
	pspBrowserSetState(0x18, filename);
	return 0;
}
