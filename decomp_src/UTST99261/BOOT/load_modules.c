#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <modulemgr.h>
#include <stdio.h>
#include <string.h>
#include "load_modules.h"
#include "pspBrowser.h"
#include "main.h"

extern SceUID s_loaded_modules_id[18];

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CEBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CECC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CED8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CEE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CEFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CF18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CF2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CF3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CF50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CF64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CF70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CF7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CF8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CF98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CFA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CFB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CFC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", D_0010CFD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", s_modules_path);

#ifdef NON_MATCHING
/* Close: LoadModule keeps the load result in one register where the
   original has a copy for modid (4 bytes shorter); LoadRequiredModules
   sets the 0 it returns after the loop instead of inside it. */
static const SampleLoadModule s_modules_path[] = {
	{ "ifhandle.prx", 1 },
	{ "pspnet.prx", 2 },
	{ "pspnet_inet.prx", 2 },
	{ "pspnet_apctl.prx", 2 },
	{ "pspnet_ap_dialog_dummy.prx", 2 },
	{ "pspnet_resolver.prx", 2 },
	{ "libbase64.prx", 2 },
	{ "libparse_uri.prx", 2 },
	{ "libparse_http.prx", 2 },
	{ "libhttp.prx", 2 },
	{ "libssl.prx", 2 },
	{ "cert_loader.prx", 1 },
	{ "libfont.prx", 2 },
	{ "videocodec.prx", 1 },
	{ "audiocodec.prx", 1 },
	{ "mpegbase.prx", 1 },
	{ "mpeg.prx", 2 },
	{ "libatrac3plus.prx", 2 },
};

static SceUID LoadModule(const SceUChar8 *path, SceUID mpid, const SceKernelSMOption *sm_opt)
{
	SceInt32 ret;
	SceInt32 mresult = 0;
	SceKernelLMOption opt;
	SceUID modid;

	memset(&opt, 0, sizeof(opt));
	opt.size = sizeof(opt);
	opt.mpidtext = mpid;
	opt.position = 0;
	ret = sceKernelLoadModule(path, 0, &opt);
	modid = ret;
	if (modid < 0) {
		printf("sceKerelLoadMoule() returns 0x%x\n", modid);
		return ret;
	}
	ret = sceKernelStartModule(modid, 0, NULL, &mresult, sm_opt);
	if (ret < 0) {
		printf("sceKernelStartModule() returns 0x%x", ret);
		if (modid > 0) {
			sceKernelStopModule(modid, 0, NULL, &mresult, sm_opt);
			printf("try to stop modules.. code = 0x%x\n", mresult);
			sceKernelUnloadModule(modid);
		}
		return ret;
	}
	printf("%s start with 0x%x code\n", path, mresult);
	return modid;
}

int LoadRequiredModules(void)
{
	char module_file[320];
	SceInt32 ret;
	SceUInt counter;

	memset(s_loaded_modules_id, 0, sizeof(s_loaded_modules_id));
	for (counter = 0; counter < sizeof(s_modules_path) / sizeof(s_modules_path[0]); counter++) {
		strcpy(module_file, pPath);
		strcat(module_file, s_modules_path[counter].path);
		ret = LoadModule(module_file, s_modules_path[counter].mpid, NULL);
		if (ret < 0)
			return ret;
		s_loaded_modules_id[counter] = ret;
	}
	return 0;
}

#endif

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", LoadModule_AFC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", LoadRequiredModules);

void StopDeleteLoadedModules(void)
{
	SceInt32 counter;

	for (counter = 18 - 1; counter >= 0; counter--) {
		if (s_loaded_modules_id[counter] == 0)
			break;
		sceKernelStopModule(s_loaded_modules_id[counter], 0, NULL, NULL, NULL);
		sceKernelUnloadModule(s_loaded_modules_id[counter]);
		s_loaded_modules_id[counter] = 0;
	}
}
