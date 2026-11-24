#include "common.h"
#include <stdio.h>
#include <libgu.h>
#include <displaysvc.h>
#include "pspBrowser.h"
#include "main.h"
#include "message.h"

int browserReaderror(void)
{
	int ret;

	puts("pspBrowser [ READ ERROR]");
	messStart();
	messObjCreate(7, 185, 60, NULL, 0, 0);
	messObjCreate(0x93, 185, 107, NULL, 0, 13);
	messObjCreate(0x90, 185, 127, NULL, 0, 11);
	messObjCreate(0x8f, 185, 147, NULL, 0, 10);
	do {
		browserDraw();
		ret = messExec(1);
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		if (ret == 13) {
			PSPBROWSER_GET_URL pspGetUrl;
			char url_data[320];

			pspGetUrl.url = url_data;
			pspGetUrl.length = 320;
			pspBrowserGetState(0x18, &pspGetUrl);
			pspNetworkExit();
			pspNetworkInit();
			pspBrowserSetState(0x18, url_data);
			break;
		}
		if (ret == 11) {
			pspBrowserSetState(2, NULL);
			messEnd();
		}
		if (ret == 10) {
			pspBrowserSetState(0x18, pHome);
			messEnd();
		}
		if (_cPspBrowserExit)
			return 4;
	} while (ret != 1);
	return 5;
}
