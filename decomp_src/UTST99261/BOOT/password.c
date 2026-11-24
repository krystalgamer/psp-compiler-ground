#include "common.h"
#include <stdio.h>
#include <libgu.h>
#include <displaysvc.h>
#include "pspBrowser.h"
#include "main.h"
#include "message.h"

int browserPassword(void)
{
	int ret;
	int hId, hPass;
	char user_id[320];
	char user_pass[320];
	int id_size = 0;
	int pass_size = 0;
	PSPBROWSER_SET_PASSWORD pspSetPassword;

	puts("pspBrowser [ PASSWORD ]");
	user_id[0] = 0;
	user_pass[0] = 0;
	messStart();
	messObjCreate(3, 185, 60, NULL, 0, 0);
	hId = messObjCreate(0x55, 120, 120, user_id, 0, 7);
	hPass = messObjCreate(0x56, 120, 150, user_id, 0, 8);
	messObjCreate(0x8c, 130, 190, NULL, 0, 5);
	messObjCreate(0x8d, 240, 190, NULL, 0, 6);
	do {
		browserDraw();
		ret = messExec(1);
		sceGuFinish();
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		switch (ret) {
		case 5:
			pspSetPassword.id = user_id;
			pspSetPassword.password = user_pass;
			pspSetPassword.state = 0;
			pspBrowserSetState(0x14, &pspSetPassword);
			messEnd();
			break;
		case 6:
			pspSetPassword.state = -1;
			pspBrowserSetState(0x14, &pspSetPassword);
			messEnd();
			break;
		case 7:
			ret = inputExec(user_id, id_size, 0);
			if (ret) {
				messObjStrSet(hId, user_id, ret);
				id_size = ret;
			}
			break;
		case 8:
			ret = inputExec(user_pass, pass_size, 0);
			if (ret) {
				messObjStrSet(hPass, user_pass, ret);
				pass_size = ret;
			}
			break;
		}
		if (_cPspBrowserExit)
			return 4;
	} while (ret != 1);
	return 5;
}
