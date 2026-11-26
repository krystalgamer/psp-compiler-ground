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
struct _anon1;
struct _anon1 { /* size 0x8 */
    char *name;
    int partition;
};

extern SceUID moduleIDs[2];
extern const struct _anon1 moduleInfo[2];

static int unload_module(SceUID mid);
int unloadModuleAt3plus(void);
int loadModuleAt3plus(void);


int load_module(signed char *filename, SceKernelLMOption *lm_opt, SceKernelSMOption *sm_opt) {
    int temp_v0;

    do {
        temp_v0 = sceKernelLoadModule(filename, 0, lm_opt);
    } while (temp_v0 < 0);
    do {

    } while (sceKernelStartModule(temp_v0, 0, 0, 0, sm_opt) < 0);
    return temp_v0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/at3loadmodule", D_0001F0F4);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/at3loadmodule", D_0001F124);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/at3loadmodule", moduleInfo);

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

int unloadModuleAt3plus(void)
{
	int i;

	for (i = 1; i >= 0; i--) {
		if (moduleIDs[i] >= 0) {
			if (unload_module(moduleIDs[i]) < 0) {
				printf("fatal error : cannot unload module %s\n", moduleInfo[i].name);
				return -1;
			}
		}
	}

	return 0;
}

int loadModuleAt3plus(void)
{
	SceKernelLMOption mode;
	int i;

	mode.size = sizeof(mode);
	mode.position = 0;
	mode.access = 1;
	for (i = 0; i < 2; i++) {
		mode.mpiddata = moduleInfo[i].partition;
		mode.mpidtext = moduleInfo[i].partition;
		moduleIDs[i] = load_module((signed char *)moduleInfo[i].name, &mode, NULL);
		if (moduleIDs[i] < 0) {
			printf("fatal error : cannot load Module %s\n", moduleInfo[i].name);
			unloadModuleAt3plus();
			return -1;
		}
	}
	return 0;
}
