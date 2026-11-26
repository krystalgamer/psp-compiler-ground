#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned char SceUChar8;
typedef int SceUID;
typedef int SceInt32;
typedef struct SceKernelLMOption SceKernelLMOption;
struct SceKernelLMOption;
typedef unsigned int SceSize;
struct SceKernelLMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};
typedef unsigned int SceUInt;
typedef unsigned int SceUInt32;
typedef struct SampleLoadModule SampleLoadModule;
struct SampleLoadModule;
struct SampleLoadModule { /* size 0x8 */
    const SceUChar8 *path;
    const SceUID mpid;
};

extern const SampleLoadModule s_modules_path[10];
extern SceUID s_loaded_modules_id[10];

static SceUID LoadModule(const SceUChar8 *path, SceUID mpid);
int LoadRequiredModules(void);
void StopDeleteLoadedModules(void);
int sceKernelStopModule(SceUID modid, SceSize argsize, void *argp, int *status, void *option);
int sceKernelUnloadModule(SceUID modid);

/* SDK prototypes (tools/sdk_protos.h) */
int sceIoClose(int fd);
int sceIoOpen(const char *name, int flag, int mode);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", LoadModule);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", LoadRequiredModules);

void StopDeleteLoadedModules(void)
{
	SceUInt32 counter;

	for (counter = 0; counter < 10; counter++) {
		if (s_loaded_modules_id[counter] == 0) {
			break;
		}

		sceKernelStopModule(s_loaded_modules_id[counter], 0, NULL, NULL, NULL);
		sceKernelUnloadModule(s_loaded_modules_id[counter]);
		s_loaded_modules_id[counter] = 0;
	}
}

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", D_00016A18);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", D_00016A44);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", D_00016A6C);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", D_00016AA0);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", D_00016ACC);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", D_00016AFC);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", D_00016B2C);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", D_00016B5C);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", D_00016B90);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", D_00016BC8);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", s_modules_path);
