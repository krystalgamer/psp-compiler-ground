#include "common.h"
#include <stdio.h>
#include <string.h>
#include <libgu.h>
#include <displaysvc.h>
#include "pspBrowser.h"
#include "main.h"
#include "message.h"

extern char mp3Filename[320];

int mp3Callback(char *filename, char *data);

int mp3Init(void)
{
	return 0;
}

void mp3Exit(void)
{
}

int mp3Add()
{
	pspBrowserAddAnchor("mp3", mp3Callback);
	return 0;
}

int mp3Exec(void)
{
	int padin;
	int ret;
	int i;

	puts("mp3 Exec");
	soundExit();
	ret = mp3_init(mp3Filename);
	if (ret) {
		mp3_exit();
	} else {
		gInit();
		messStart();
		messObjCreate(10, 120, 66, NULL, 0, 0);
		messObjCreate(0x8d, 185, 190, NULL, 0, 6);
		messObjCreate(0x17, 140, 105, mp3Filename, strlen(mp3Filename), 200);
		for (i = 0; i < 10; i++) {
			browserDraw();
			messExec(1);
			sceGuFinish();
			sceGuSync(0, 0);
			sceDisplayWaitVblankStartCB();
			sceGuSwapBuffers();
		}
		padin = 0;
		do {
			if (mainPadRead() & 0x2000)
				padin = 1;
			mp3_exec(1);
			sceDisplayWaitVblankStartCB();
		} while (!padin);
		mp3_exit();
		messEnd();
		for (i = 0; i < 10; i++) {
			browserDraw();
			messExec(1);
			sceGuFinish();
			sceGuSync(0, 0);
			sceDisplayWaitVblankStartCB();
			sceGuSwapBuffers();
		}
	}
	soundInit();
	return 5;
}

int mp3End()
{
	return 0;
}

int mp3Callback(char *filename, char *data)
{
	strcpy(mp3Filename, filename);
	printf("mpeg file = { %s ][ %s\n", mp3Filename, data);
	iPspBrowserApMode = 0x13;
	return 0;
}
