#include "common.h"

/* declarations recovered from DWARF */
typedef char SceChar8;
typedef struct SceKernelLMOption SceKernelLMOption;
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
typedef struct SceKernelSMOption SceKernelSMOption;
struct SceKernelSMOption;
struct SceKernelSMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidstack;
    SceSize stacksize;
    int priority;
    unsigned int attribute;
};
typedef int SceInt32;

extern SceUID moduleIDs[4];
extern const char *const moduleNames[4];
extern SceUID libfont_modid;

static SceUID _load_module_video(const SceChar8 *filename, SceKernelLMOption *lm_opt, SceKernelSMOption *sm_opt);
static SceInt32 _unload_module_video(SceUID mid);
static SceInt32 unloadModuleVideo(void);
static SceInt32 loadModuleVideo(void);
static SceUID load_module(const char *path);
static int unload_module(SceUID modid);


INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/load_modules", _load_module_video);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/load_modules", _unload_module_video);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/load_modules", unloadModuleVideo);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/load_modules", loadModuleVideo);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/load_modules", load_module);

int sceKernelStopModule(SceUID modid, SceSize argsize, void *argp, int *status, void *option);
int sceKernelUnloadModule(SceUID modid);
static int unload_module(SceUID modid)
{
	int ret;

	ret = sceKernelStopModule(modid, 0, NULL, NULL, NULL);
	if (ret >= 0)
		ret = sceKernelUnloadModule(modid);
	return ret;
}

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/load_modules", D_0002DB0C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/load_modules", D_0002DB3C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/load_modules", D_0002DB6C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/load_modules", D_0002DB98);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/load_modules", moduleNames);

int load_required_modules(void) {
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int var_s0;
    int var_v0;

    temp_v0 = load_module("disc0:/PSP_GAME/USRDIR/module/libfont.prx");
    var_s0 = temp_v0;
    if ((temp_v0 >= 0) && (libfont_modid = var_s0, temp_v0_2 = sceUtilityLoadNetModule(1), var_s0 = temp_v0_2, (temp_v0_2 >= 0)) && (temp_v0_3 = sceUtilityLoadNetModule(2), var_s0 = temp_v0_3, (temp_v0_3 >= 0)) && (temp_v0_4 = loadModuleVideo(), var_s0 = temp_v0_4, (temp_v0_4 >= 0))) {
        var_v0 = var_s0;
    } else {
        unload_required_modules();
        var_v0 = var_s0;
    }
    return var_v0;
}

int unload_required_modules(void) {
    int temp_v0;
    int var_v1;

    sceUtilityUnloadNetModule(2);
    sceUtilityUnloadNetModule(1);
    var_v1 = unloadModuleVideo();
    if (libfont_modid >= 0) {
        temp_v0 = unload_module(libfont_modid);
        var_v1 = temp_v0;
        if (temp_v0 >= 0) {
            libfont_modid = -1;
        }
    }
    return var_v1;
}
