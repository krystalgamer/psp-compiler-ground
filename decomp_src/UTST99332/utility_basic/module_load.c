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

void *memset(void *s, int c, unsigned int n);
SceUID sceKernelLoadModuleByID(SceUID fid, int flag, SceKernelLMOption *option);
int sceKernelStartModule(SceUID modid, SceSize argsize, void *argp, int *status, void *option);
static SceUID LoadModule(const SceUChar8 *path, SceUID mpid)
{
	SceInt32 ret, mresult;
	SceKernelLMOption opt;
	SceUID fd, modid;

	memset(&opt, 0, sizeof(opt));
	mresult = 0;
	opt.size = sizeof(opt);
	opt.mpidtext = mpid;
	opt.flags = 0;
	opt.mpiddata = 0;
	opt.position = 0;
	ret = sceIoOpen((const char *)path, 1, 0);
	if (ret < 0)
		goto error;
	fd = ret;
	do {
		ret = sceKernelLoadModuleByID(fd, 0, &opt);
	} while (ret < 0);
	modid = ret;
	do {
		ret = sceKernelStartModule(modid, 0, NULL, &mresult, NULL);
	} while (ret < 0);
	sceIoClose(fd);
	return modid;
error:
	return ret;
}

int LoadRequiredModules(void)
{
	SceInt32 ret;
	SceUInt counter;

	memset(s_loaded_modules_id, 0, sizeof(s_loaded_modules_id));
	for (counter = 0; counter < 10; counter++) {
		ret = LoadModule(s_modules_path[counter].path, s_modules_path[counter].mpid);
		if (ret < 0)
			goto error;
		s_loaded_modules_id[counter] = ret;
	}
	return 0;
error:
	return ret;
}

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
