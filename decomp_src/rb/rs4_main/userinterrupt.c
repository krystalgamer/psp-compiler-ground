/* SDK userinterrupt (1.9.2.internal), -O4 like the other SDK libraries */
/* cflags: -O3 */
#include "common.h"

int sceKernelRegisterSubIntrHandler(int intno, int no, void *handler, void *arg);
int sceKernelReleaseSubIntrHandler(int intno, int no);
int sceKernelEnableSubIntr(int intno, int no);
int sceDisplaySetVblankCallback(int no, void *cb, void *arg)
{
	int ret;
	if (cb != 0) {
		ret = sceKernelRegisterSubIntrHandler(30, no, cb, arg);
		if (ret >= 0) ret = sceKernelEnableSubIntr(30, no);
	} else {
		ret = sceKernelReleaseSubIntrHandler(30, no);
	}
	return ret;
}
