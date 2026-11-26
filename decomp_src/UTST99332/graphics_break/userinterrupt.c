/* cflags: -O2 -frename-registers */
#include "common.h"

int sceKernelRegisterSubIntrHandler(int intno, int no, void *handler, void *arg);
int sceKernelEnableSubIntr(int intno, int no);
int sceKernelReleaseSubIntrHandler(int intno, int no);

int sceDisplaySetVblankCallback(int no, void *handler, void *arg)
{
	int ret;

	if (handler != NULL) {
		ret = sceKernelRegisterSubIntrHandler(30, no, handler, arg);
		if (ret >= 0) {
			ret = sceKernelEnableSubIntr(30, no);
		}
	} else {
		ret = sceKernelReleaseSubIntrHandler(30, no);
	}

	return ret;
}
