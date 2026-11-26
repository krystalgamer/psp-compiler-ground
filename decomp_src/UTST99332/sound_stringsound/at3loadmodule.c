#include "common.h"

/* declarations recovered from DWARF */
struct SceKernelLMOption;
typedef unsigned int SceSize;
typedef int SceUID;
struct SceKernelLMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};
typedef struct SceKernelLMOption SceKernelLMOption;
struct SceKernelSMOption;
struct SceKernelSMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidstack;
    SceSize stacksize;
    int priority;
    unsigned int attribute;
};
typedef struct SceKernelSMOption SceKernelSMOption;
typedef int SceInt32;
struct _anon1;
typedef unsigned char SceUChar8;
struct _anon1 { /* size 0xc */
    SceUID moduleID;
    SceInt32 kModeFlag;
    SceUChar8 *modulename;
};
typedef struct _anon1 ModuleArg;

extern ModuleArg module[2];

static int unload_module(SceUID mid);
int unloadModuleAt3plus(void);
int loadModuleAt3plus(void);


int load_module(signed char *modulename, SceKernelLMOption *lm_opt, SceKernelSMOption *sm_opt) {
    int temp_v0;

    do {
        temp_v0 = sceKernelLoadModule(modulename, 0, lm_opt);
    } while (temp_v0 < 0);
    do {

    } while (sceKernelStartModule(temp_v0, 0, 0, 0, sm_opt) < 0);
    return temp_v0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3loadmodule", D_0001F9BC);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3loadmodule", D_0001F9EC);

int printf(const char *fmt, ...);
int sceKernelStopModule(SceUID modid, SceSize argsize, void *argp, int *status, SceKernelSMOption *option);
int sceKernelUnloadModule(SceUID modid);
static SceInt32 unload_module(SceUID mid)
{
	SceInt32 ret;

	ret = sceKernelStopModule(mid, 0, NULL, NULL, NULL);
	if (ret < 0) {
		printf("fatal error : cannot stop module 0x%08x\n", ret);
		return ret;
	}
	ret = sceKernelUnloadModule(mid);
	if (ret < 0) {
		printf("fatal error : cannot unload module 0x%08x\n", ret);
		return ret;
	}
	return 0;
}

int unloadModuleAt3plus(void)
{
	int i;

	for (i = 1; i >= 0; i--) {
		if (module[i].moduleID >= 0) {
			if (unload_module(module[i].moduleID) < 0) {
				printf("fatal error : cannot unload module %s\n", module[i].modulename);
				return -1;
			}
		}
	}

	return 0;
}

int loadModuleAt3plus(void)
{
	SceKernelLMOption kMode;
	SceKernelLMOption uMode;
	SceKernelLMOption *pMode;
	SceInt32 i;

	kMode.size = sizeof(kMode);
	kMode.mpidtext = 1;
	kMode.mpiddata = 1;
	kMode.position = 0;
	kMode.access = 1;

	uMode.size = sizeof(uMode);
	uMode.mpidtext = 2;
	uMode.mpiddata = 2;
	uMode.position = 0;
	uMode.access = 1;

	for (i = 0; i < 2; i++) {
		if (module[i].kModeFlag)
			pMode = &kMode;
		else
			pMode = &uMode;
		module[i].moduleID = load_module((signed char *)module[i].modulename, pMode, NULL);
		if (module[i].moduleID < 0) {
			printf("fatal error : cannot load Module (%s)", module[i].modulename);
			unloadModuleAt3plus();
			return -1;
		}
	}
	return 0;
}
