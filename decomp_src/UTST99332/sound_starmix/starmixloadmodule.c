#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned char SceUChar;
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

extern SceUID sasMid;
extern SceUID audioMid;
extern SceUID atrac3Mid;

static int unload_module(SceUID mid);
int starmix_loadModule(void);
int starmix_unloadModule(void);


/* SDK prototypes (tools/sdk_protos.h) */
int puts(const char *s);

int load_module(unsigned char *filename, SceKernelLMOption *lm_opt, SceKernelSMOption *sm_opt) {
    int temp_v0;

    do {
        temp_v0 = sceKernelLoadModule(filename, 0, lm_opt);
    } while (temp_v0 < 0);
    do {

    } while (sceKernelStartModule(temp_v0, 0, 0, 0, sm_opt) < 0);
    return temp_v0;
}

int printf(const char *fmt, ...);
int sceKernelStopModule(SceUID modid, SceSize argsize, void *argp, int *status, SceKernelSMOption *option);
int sceKernelUnloadModule(SceUID modid);
static int unload_module(SceUID mid)
{
	int ret;

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

int starmix_loadModule(void)
{
	SceKernelLMOption kMode;
	SceKernelLMOption uMode;

	sasMid = 0;
	audioMid = 0;
	atrac3Mid = 0;

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

	sasMid = load_module("disc0:/PSP_GAME/USRDIR/MODULE/sc_sascore.prx", &kMode, NULL);
	if (sasMid < 0) {
		printf("fatal error : load SAS module\n");
		return -1;
	}
	audioMid = load_module("disc0:/PSP_GAME/USRDIR/MODULE/audiocodec.prx", &kMode, NULL);
	if (audioMid < 0) {
		printf("fatal error : load audiocodec Module\n");
		unload_module(sasMid);
		return -1;
	}
	atrac3Mid = load_module("disc0:/PSP_GAME/USRDIR/MODULE/libatrac3plus.prx", &uMode, NULL);
	if (atrac3Mid < 0) {
		printf("fatal error : load atrac3plus Module\n");
		unload_module(sasMid);
		unload_module(audioMid);
		return -1;
	}
	return 0;
}

int starmix_unloadModule(void)
{
	if (unload_module(atrac3Mid) < 0) {
		printf("fatal error : cannot unload atrac3plus module\n");
		return -1;
	}

	if (unload_module(audioMid) < 0) {
		printf("fatal error : cannot unload audiocodec module\n");
		return -1;
	}

	if (unload_module(sasMid) < 0) {
		printf("fatal error : cannot unload SAS module\n");
		return -1;
	}

	return 0;
}
