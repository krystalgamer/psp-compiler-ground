#include "common.h"
/* cflags: -O2 -frename-registers */

int sceKernelRegisterSubIntrHandler(int intno, int no, void *handler, void *arg);
int sceKernelReleaseSubIntrHandler(int intno, int no);
int sceKernelEnableSubIntr(int intno, int no);

typedef void (*VblankFunc)(int, void *);
int sceDisplaySetVblankCallback(int idx, VblankFunc pFunc, void *cookie)
{
	int ret;
	if (pFunc != NULL) {
		ret = sceKernelRegisterSubIntrHandler(30, idx, pFunc, cookie);
		if (ret >= 0)
			ret = sceKernelEnableSubIntr(30, idx);
	} else {
		ret = sceKernelReleaseSubIntrHandler(30, idx);
	}
	return ret;
}
