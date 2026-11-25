#include "common.h"
#include <libgu.h>
#include <displaysvc.h>
#include "pspBrowser.h"
#include "main.h"
#include "message.h"

int browserMenu(void)
{
	PSPBROWSER_GET_URL pspGetUrl2;
	int ret;
	char url_data[320];

	messStart();
	messObjCreate(9, 185, 60, NULL, 0, 0);
	messObjCreate(0x8e, 130, 97, NULL, 0, 9);
	messObjCreate(0x8f, 130, 117, NULL, 0, 10);
	messObjCreate(0x90, 130, 137, NULL, 0, 11);
	messObjCreate(0x92, 130, 157, NULL, 0, 17);
	messObjCreate(0x94, 240, 97, NULL, 0, 14);
	messObjCreate(0x94, 240, 117, NULL, 0, 15);
	messObjCreate(0x94, 240, 137, NULL, 0, 16);
	do {
		browserDraw();
		ret = messExec(1);
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		switch (ret) {
		case 6:
			messEnd();
			break;
		case 9:
			pspBrowserSetState(4, NULL);
			messEnd();
			break;
		case 10:
			pspBrowserSetState(0x18, pHome);
			messEnd();
			break;
		case 11:
			pspBrowserSetState(2, NULL);
			messEnd();
			break;
		case 12:
			pspGetUrl2.url = url_data;
			pspGetUrl2.length = 320;
			ret = 2;
			pspBrowserGetState(0x18, &pspGetUrl2);
			if (inputExec(url_data, pspGetUrl2.getLength, 0)) {
				pspBrowserSetState(0x18, url_data);
				return 5;
			}
			break;
		case 14:
			switch (_cFontSize) {
			case 0:
				_cFontSize = 2;
				break;
			case 1:
				_cFontSize = 0;
				break;
			case 2:
				_cFontSize = 1;
				break;
			}
			imageCls();
			return 6;
		case 15:
			switch (_cTexMode) {
			case 0:
				_cTexMode = 1;
				break;
			case 1:
				_cTexMode = 2;
				break;
			case 2:
				_cTexMode = 3;
				break;
			case 3:
				_cTexMode = 0;
				break;
			}
			imageCls();
			return 6;
		case 16:
			if (_cImageDez == 0)
				_cImageDez = 1;
			else
				_cImageDez = 0;
			imageCls();
			pspBrowserSetState(4, NULL);
			messEnd();
			break;
		case 17:
			messEnd();
			return 4;
		}
		if (_cPspBrowserExit)
			return 4;
	} while (ret != 1);
	return 5;
}
