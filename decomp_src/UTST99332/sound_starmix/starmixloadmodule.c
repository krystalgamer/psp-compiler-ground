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

INCLUDE_ASM("tmp/asm/UTST99332/sound_starmix/nonmatchings/starmixloadmodule", starmix_loadModule);

INCLUDE_ASM("tmp/asm/UTST99332/sound_starmix/nonmatchings/starmixloadmodule", starmix_unloadModule);
