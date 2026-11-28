#include "common.h"
#include "m2c_macros.h"
#include <modulemgr.h>
#include <iofilemgr.h>

typedef struct {
	const char *path;
	SceUID mpid;
} MODULE_PATH;

typedef struct {
	SceUID id;
	int type;
	const char *name;
} MODULE_ENT;

extern const MODULE_PATH s_modules_path[9];
extern SceUID s_loaded_modules_id[9];
extern MODULE_ENT module[2];

int printf(const char *, ...);
int puts(const char *);
void *memset(void *, int, unsigned int);
void wait_umd(void);
int LoadRequiredModules(void);
int loadModuleAt3plus(void);
int sceKernelExitDeleteThread(int);
SceUID load_module(const char *name, SceKernelLMOption *lmopt, SceKernelSMOption *smopt);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002F9B8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002F9D8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002F9F4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FA1C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FA38);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FA58);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FA78);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FA9C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FAC0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FAE4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FB04);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", s_modules_path);

SceUID LoadModule(const char *path, SceUID mpid)
{
	SceInt32 ret = 0;
	SceInt32 mresult = 0;
	SceKernelLMOption opt;
	SceUID modid;
	SceUID fd;

	memset(&opt, 0, sizeof(opt));
	opt.size = sizeof(opt);
	opt.mpidtext = mpid;
	opt.mpiddata = 0;
	opt.position = 0;
	modid = sceIoOpen(path, SCE_O_RDONLY, 0);
	if (modid < 0) {
		printf("sceIoOpen() returns 0x%x\n", ret);
		return ret;
	}
	fd = modid;
	ret = sceKernelLoadModuleByID(fd, 0, &opt);
	if (ret < 0) {
		printf("sceKerelLoadMoule() returns 0x%x\n", ret);
	} else {
		modid = ret;
		ret = sceKernelStartModule(modid, 0, NULL, &mresult, NULL);
		if (ret >= 0) {
			printf("%s start with 0x%x code\n", path, mresult);
			return modid;
		}
		printf("sceKernelStartModule() returns 0x%x", ret);
		if (modid > 0) {
			sceKernelStopModule(modid, 0, NULL, &mresult, NULL);
			printf("try to stop modules.. code = 0x%x\n", mresult);
			sceKernelUnloadModule(modid);
		}
	}
	if (fd > 0)
		sceIoClose(fd);
	return ret;
}

int LoadRequiredModules(void)
{
	unsigned int i;
	SceUID id;

	puts("MODULE LOAD START");
	memset(s_loaded_modules_id, 0, sizeof(s_loaded_modules_id));
	for (i = 0; i < 9; i++) {
		printf("MODULE LOAD %s\n", s_modules_path[i].path);
		id = LoadModule(s_modules_path[i].path, s_modules_path[i].mpid);
		if (id < 0) {
			printf("MODULE LOAD FAILED %s\n", s_modules_path[i].path);
			return id;
		}
		s_loaded_modules_id[i] = id;
	}
	return 0;
}

void StopDeleteLoadedModules(void)
{
	unsigned int i;

	for (i = 0; i < 9; i++) {
		if (s_loaded_modules_id[i] == 0)
			break;
		sceKernelStopModule(s_loaded_modules_id[i], 0, 0, 0, 0);
		sceKernelUnloadModule(s_loaded_modules_id[i]);
		s_loaded_modules_id[i] = 0;
	}
}

SceUID load_module(const char *name, SceKernelLMOption *lmopt, SceKernelSMOption *smopt)
{
	SceUID modid;
	int ret;

	modid = sceKernelLoadModule(name, 0, lmopt);
	if (modid < 0) {
		printf("fatal error : cannot load %s 0x%08x\n", name, modid);
		return modid;
	}
	ret = sceKernelStartModule(modid, 0, 0, 0, smopt);
	if (ret < 0) {
		printf("fatal error : cannot start %s 0x%08x\n", name, ret);
		return ret;
	}
	return modid;
}

int loadModuleAt3plus(void)
{
	SceKernelLMOption opt1;
	SceKernelLMOption opt2;
	SceKernelLMOption *opt;
	int i;

	wait_umd();
	opt1.size = sizeof(opt1);
	opt1.mpidtext = 1;
	opt1.mpiddata = 1;
	opt1.position = 0;
	opt1.access = 1;
	opt2.size = sizeof(opt2);
	opt2.mpidtext = 2;
	opt2.mpiddata = 2;
	opt2.position = 0;
	opt2.access = 1;
	for (i = 0; i < 2; i++) {
		if (module[i].type == 1)
			opt = &opt1;
		else
			opt = &opt2;
		module[i].id = load_module(module[i].name, opt, 0);
		if (module[i].id < 0) {
			printf("fatal error : cannot load Module (%s)", module[i].name);
			do {
				wait_umd();
				module[i].id = load_module(module[i].name, opt, 0);
			} while (module[i].id < 0);
		}
	}
	return 0;
}

int sub_thread(void) {
    puts("module load-----------");
    loadModuleAt3plus();
    LoadRequiredModules();
    sceKernelExitDeleteThread(0);
    return 0;
}
