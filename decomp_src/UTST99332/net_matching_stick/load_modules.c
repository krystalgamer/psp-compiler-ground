#include "common.h"

/* declarations recovered from DWARF */
typedef int SceUID;
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

extern SceUID ifhandle_modid;
extern SceUID memab_modid;
extern SceUID pspnet_adhoc_auth_modid;
extern SceUID pspnet_modid;
extern SceUID pspnet_adhoc_modid;
extern SceUID pspnet_adhocctl_modid;
extern SceUID pspnet_adhoc_matching_modid;

static SceUID load_module(const char *path, SceUID mpid);
static int unload_module(SceUID modid);
int load_required_modules(void);
int unload_required_modules(void);


/* SDK prototypes (tools/sdk_protos.h) */
int printf(const char *fmt, ...);

SceUID sceKernelLoadModule(const char *path, int flags, SceKernelLMOption *option);
int sceKernelStartModule(SceUID modid, SceSize args, void *argp, int *status, void *option);
void *memset(void *s, int c, unsigned int n);

static SceUID load_module(const char *path, SceUID mpid)
{
	SceKernelLMOption option;
	SceUID modid;
	int ret, mresult;

	memset(&option, 0, sizeof(option));
	option.size = sizeof(option);
	option.mpidtext = mpid;
	option.mpiddata = mpid;
	option.position = 0;
	option.access = 1;

	do {
		ret = sceKernelLoadModule(path, 0, &option);
	} while (ret < 0);
	modid = ret;

	do {
		ret = sceKernelStartModule(modid, 0, NULL, &mresult, NULL);
	} while (ret < 0);

	return modid;
}

int sceKernelStopModule(SceUID modid, SceSize args, void *argp, int *status, void *option);
int sceKernelUnloadModule(SceUID modid);

static int unload_module(SceUID modid)
{
	int ret, mresult;

	ret = sceKernelStopModule(modid, 0, NULL, NULL, NULL);
	if (ret < 0) {
		printf("sceKernelStopModule() failed. ret = 0x%x\n", ret);
		return ret;
	}

	ret = sceKernelUnloadModule(modid);
	if (ret < 0) {
		printf("sceKernelUnloadModule() failed. ret = 0x%x\n", ret);
		return ret;
	}

	return ret;
}

int load_required_modules(void)
{
	int ret = 0;

	ret = load_module("disc0:/PSP_GAME/USRDIR/MODULE/ifhandle.prx", 1);
	if (ret < 0) {
		printf("load_module %s failed. ret = 0x%x\n", "disc0:/PSP_GAME/USRDIR/MODULE/ifhandle.prx", ret);
		goto error;
	}
	ifhandle_modid = ret;

	ret = load_module("disc0:/PSP_GAME/USRDIR/MODULE/memab.prx", 1);
	if (ret < 0) {
		printf("load_module %s failed. ret = 0x%x\n", "disc0:/PSP_GAME/USRDIR/MODULE/memab.prx", ret);
		goto error;
	}
	memab_modid = ret;

	ret = load_module("disc0:/PSP_GAME/USRDIR/MODULE/pspnet_adhoc_auth.prx", 1);
	if (ret < 0) {
		printf("load_module %s failed. ret = 0x%x\n", "disc0:/PSP_GAME/USRDIR/MODULE/pspnet_adhoc_auth.prx", ret);
		goto error;
	}
	pspnet_adhoc_auth_modid = ret;

	ret = load_module("disc0:/PSP_GAME/USRDIR/MODULE/pspnet.prx", 2);
	if (ret < 0) {
		printf("load_module %s failed. ret = 0x%x\n", "disc0:/PSP_GAME/USRDIR/MODULE/pspnet.prx", ret);
		goto error;
	}
	pspnet_modid = ret;

	ret = load_module("disc0:/PSP_GAME/USRDIR/MODULE/pspnet_adhoc.prx", 2);
	if (ret < 0) {
		printf("load_module %s failed. ret = 0x%x\n", "disc0:/PSP_GAME/USRDIR/MODULE/pspnet_adhoc.prx", ret);
		goto error;
	}
	pspnet_adhoc_modid = ret;

	ret = load_module("disc0:/PSP_GAME/USRDIR/MODULE/pspnet_adhocctl.prx", 2);
	if (ret < 0) {
		printf("load_module %s failed. ret = 0x%x\n", "disc0:/PSP_GAME/USRDIR/MODULE/pspnet_adhocctl.prx", ret);
		goto error;
	}
	pspnet_adhocctl_modid = ret;

	ret = load_module("disc0:/PSP_GAME/USRDIR/MODULE/pspnet_adhoc_matching.prx", 2);
	if (ret < 0) {
		printf("load_module %s failed. ret = 0x%x\n", "disc0:/PSP_GAME/USRDIR/MODULE/pspnet_adhoc_matching.prx", ret);
		goto error;
	}
	pspnet_adhoc_matching_modid = ret;

error:
	return ret;
}

int unload_required_modules(void)
{
	int ret = 0;

	ret = unload_module(pspnet_adhoc_matching_modid);
	if (ret < 0) {
		printf("unload_module() failed. ret = 0x%x\n", ret);
		goto error;
	}

	ret = unload_module(pspnet_adhocctl_modid);
	if (ret < 0) {
		printf("unload_module() failed. ret = 0x%x\n", ret);
		goto error;
	}

	ret = unload_module(pspnet_adhoc_modid);
	if (ret < 0) {
		printf("unload_module() failed. ret = 0x%x\n", ret);
		goto error;
	}

	ret = unload_module(pspnet_modid);
	if (ret < 0) {
		printf("unload_module() failed. ret = 0x%x\n", ret);
		goto error;
	}

	ret = unload_module(pspnet_adhoc_auth_modid);
	if (ret < 0) {
		printf("unload_module() failed. ret = 0x%x\n", ret);
		goto error;
	}

	ret = unload_module(memab_modid);
	if (ret < 0) {
		printf("unload_module() failed. ret = 0x%x\n", ret);
		goto error;
	}

	ret = unload_module(ifhandle_modid);
	if (ret < 0) {
		printf("unload_module() failed. ret = 0x%x\n", ret);
		goto error;
	}

error:
	return ret;
}
