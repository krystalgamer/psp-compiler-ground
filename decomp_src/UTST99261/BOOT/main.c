#include "common.h"
#include <kerneltypes.h>
#include <thread.h>
#include <iofilemgr.h>
#include <loadexec.h>
#include <umduser.h>
#include <ctrlsvc.h>
#include <libgu.h>
#include <stdio.h>
#include <string.h>
#include "load_modules.h"
#include "pspBrowser.h"
#include "main.h"
#include "message.h"

extern int iPspBrowserApMode;
extern char disp_list[2621440];
extern char *pSound;
extern char *pHome;
extern char *pPath;
extern char *pUserAgent;
extern char _cPspBrowserExit;

/* main's "static DISPATCH tblFrame[20];", kept in the asm .bss for now */
extern DISPATCH D_002190A4[20];


int mainPadRead(void)
{
	SceCtrlData buf[8];
	int ret;
	int cont;

	ret = sceCtrlReadBufferPositive(buf, 8);
	cont = 0;
	if (ret != 0)
		cont = buf[0].Buttons;
	return cont;
}

void gInit()
{
	int prevPri;

	prevPri = sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x40);
	sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x40);
	sceCtrlSetSamplingCycle(0);
	sceGuInit();
	sceGuDisplay(1);
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(1, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x44000, 512);
	sceGuDepthBuffer((void *)0x88000, 512);
	sceGuOffset(2048 - 480 / 2, 2048 - 272 / 2);
	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(50000, 10000);
	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);
	sceGuColor(0xffffffff);
	sceGuClearColor(0xffff4040);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuEnable(9);
	sceGuTexFunc(0, 1);
	sceGuTexMapMode(0, 0, 0);
	sceGuTexWrap(0, 0);
	sceGuTexFilter(1, 1);
	sceGuFinish();
	sceGuSync(0, 0);
}

int mainInit()
{
	if (LoadRequiredModules() != 0)
		return PSP_AP_EXIT;
	browserImageInit();
	gInit();
	if (fontInit() != 0)
		return PSP_AP_EXIT;
	if (soundInit() != 0)
		return PSP_AP_EXIT;
	if (messInit() != 0)
		return PSP_AP_EXIT;
	return PSP_BROWSER_INIT;
}

int mainExit()
{
	fontExit();
	messExit();
	soundExit();
	pspNetworkExit();
	sceGuTerm();
	browserImageExit();
	return PSP_AP_END;
}

static int ExitFunction(int count, int arg_impose, int arg_self)
{
	printf("sano exit start %s()\n", __FUNCTION__);
	_cPspBrowserExit = 1;
	sceKernelExitGame();
	return 0;
}

int dfileBoot()
{
	int size;
	char *pBuff;
	int nInFd;
	int ret;
	SceIoStat stat;
	char filepath[128];

	if (sceIoGetstat("ms0:init.dat", &stat) != 0)
		return -1;
	size = stat.st_size;
	nInFd = sceIoOpen("ms0:init.dat", SCE_O_RDONLY, 0644);
	if (nInFd < 0)
		return -1;
	pBuff = __builtin_alloca(size);
	ret = sceIoRead(nInFd, pBuff, size);
	if (ret < 0) {
		sceIoClose(nInFd);
		return -1;
	}
	if (strcmp(pBuff, "dfile103.dat") == 0 || strcmp(pBuff, "dfile105.dat") == 0) {
		sprintf(filepath, "%s%s", "disc0:/PSP_GAME/USRDIR/", pBuff);
		sceUmdActivate(1, "disc0:");
		sceUmdWaitDriveStat(0x20);
		sceKernelLoadExec(filepath, NULL);
	}
	sceIoClose(nInFd);
	return 0;
}

#define tblFrame D_002190A4
int main(int argc, char **argv)
{
	int i;
	SceUID homeCallBackId;
	char *pPrx;
	char *pHiki;

	pHome = "file://disc0:/PSP_GAME/USRDIR/index.html";
	pPath = "disc0:/PSP_GAME/USRDIR/module/";
	pSound = "disc0:/PSP_GAME/USRDIR/sound/";
	pUserAgent = "";
	pPrx = NULL;
	for (i = 1; i < argc - 1; i++) {
		if (strcmp(argv[i], "-h") == 0) {
			i++;
			pHome = argv[i];
		}
		if (strcmp(argv[i], "-x") == 0) {
			i++;
			pPrx = argv[i];
		}
		if (strcmp(argv[i], "-p") == 0) {
			i++;
			pPath = argv[i];
		}
		if (strcmp(argv[i], "-s") == 0) {
			i++;
			pSound = argv[i];
		}
		if (strcmp(argv[i], "-u") == 0) {
			i++;
			pUserAgent = argv[i];
		}
		if (strcmp(argv[i], "-z") == 0) {
			i++;
			pHiki = argv[i];
		}
	}
	dfileBoot();
	homeCallBackId = sceKernelCreateCallback("PSP_BROWSER", ExitFunction, NULL);
	sceKernelRegisterExitCallback(homeCallBackId);
	tblFrame[PSP_AP_INIT] = mainInit;
	tblFrame[PSP_AP_EXIT] = mainExit;
	tblFrame[PSP_BROWSER_INIT] = browserInit;
	tblFrame[PSP_BROWSER_EXEC] = browserExec;
	tblFrame[PSP_BROWSER_EXIT] = browserExit;
	tblFrame[PSP_BROWSER_FONTEX] = browserFontEX;
	tblFrame[PSP_BROWSER_ALERT] = browserAlert;
	tblFrame[PSP_BROWSER_CONFIRM] = browserConfirm;
	tblFrame[PSP_BROWSER_INPUT] = browserInput;
	tblFrame[PSP_BROWSER_SSL_IN] = browserSslIn;
	tblFrame[PSP_BROWSER_SSL_OUT] = browserSslOut;
	tblFrame[PSP_BROWSER_FATALERROR] = browserFatalerror;
	tblFrame[PSP_BROWSER_PASSWORD] = browserPassword;
	tblFrame[PSP_BROWSER_DOWNLOAD] = browserDownload;
	tblFrame[PSP_BROWSER_READERROR] = browserReaderror;
	tblFrame[PSP_CONTENT_DOWNLOAD] = contentDownload;
	tblFrame[PSP_BROWSER_MENU] = browserMenu;
	tblFrame[PSP_MPEG] = mpegExec;
	tblFrame[PSP_MP3] = mp3Exec;
	do {
		iPspBrowserApMode = tblFrame[iPspBrowserApMode]();
	} while (iPspBrowserApMode != PSP_AP_END);
	sceKernelDeleteCallback(homeCallBackId);
	if (_cPspBrowserExit) {
		sceKernelExitGame();
		return 1;
	}
	if (pPrx == NULL) {
		sceKernelExitGame();
		return 1;
	}
	sceKernelLoadExec(pPrx, NULL);
	return 1;
}
