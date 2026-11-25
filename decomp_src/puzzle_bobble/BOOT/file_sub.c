#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <psptypes.h>
#include <kerneltypes.h>
#include <iofilemgr.h>
#include <thread.h>
#include <umduser.h>
#include <libgu.h>
#define SCE_UTILITY_SAVEDATA_OLD
#include <utility/utility_savedata.h>
#include "savedata.h"
#include "game.h"

#define UMD_WAIT 200000

extern char PakBuf[0x87D000];
extern int PakFileMax;
extern int *PakFileSize;
extern char *PakData;
extern SceUtilitySavedataParam savedata_param;
extern int D_00153A38;	/* disp_ms_dialog's static counter */

void wait_umd(void)
{
	int stat;

	for (;;) {
		sceKernelDelayThreadCB(UMD_WAIT);
		stat = sceUmdGetDriveStat();
		if (stat & 0x32)
			break;
		printf("UMD STATUS %08x\n", stat);
		while (sceUmdActivate(1, "disc0:") < 0)
			sceKernelDelayThreadCB(UMD_WAIT);
	}
	printf("UMD WAIT END\n");
}

int file_sub_init(void)
{
	NowSaveFlag = 0;
	do {
		if (sceUmdActivate(1, "disc0:") >= 0)
			break;
		sceKernelDelayThreadCB(UMD_WAIT);
	} while (1);
	save_data_init();
	return 0;
}

void load_pak(void)
{
	if (LoadPak() == 0) {
		do {
			wait_umd();
		} while (LoadPak() == 0);
	}
}

int load_file(const char *name, void **buf, int *size)
{
	char path[256];
	SceUID fd;
	int ret;

	sprintf(path, "disc0:/PSP_GAME/USRDIR/%s", name);
	fd = sceIoOpen(path, SCE_O_RDONLY, 0777);
	if (fd < 0)
		return 0;
	*size = sceIoLseek(fd, 0, SCE_SEEK_END);
	if (*size <= 0) {
		sceIoClose(fd);
		return 0;
	}
	if (sceIoLseek(fd, 0, SCE_SEEK_SET) < 0)
		return 0;
	*buf = malloc(*size);
	ret = sceIoRead(fd, *buf, *size);
	sceIoClose(fd);
	return ret >= 0;
}

const unsigned char last_bin[16] = "n v0.9.0";

#ifdef NON_MATCHING
/* Close: the original keeps &PakBuf in a register across both loops. */
int LoadPak(void)
{
	SceUID fd;
	unsigned int size;
	unsigned int i, j;
	unsigned int start;
	int ret;

	fd = sceIoOpen("disc0:/PSP_GAME/USRDIR/data.pak", SCE_O_RDONLY, 0644);
	if (fd < 0)
		return 0;
	size = sceIoLseek(fd, 0, SCE_SEEK_END);
	if (size == 0)
		return 0;
	if (sceIoLseek(fd, 0, SCE_SEEK_SET) < 0)
		return 0;
	start = size - 16;
	for (i = start; i < size; i++)
		PakBuf[i] = 0;
	ret = sceIoRead(fd, PakBuf, size);
	if (ret != size || ret < 0) {
		sceIoClose(fd);
		return 0;
	}
	for (i = start, j = 0; i < size; i++, j++) {
		if (last_bin[j] != PakBuf[i]) {
			sceIoClose(fd);
			return 0;
		}
	}
	sceIoClose(fd);
	PakFileMax = *(int *)PakBuf;
	PakFileSize = (int *)PakBuf + 1;
	PakData = (char *)((int *)PakBuf + PakFileMax + 1);
	return 1;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", LoadPak);
#endif

void GetPakInfo(int no, char **addr, int *size)
{
	int i;

	*addr = PakData;
	for (i = 0; i < no; i++)
		*addr += PakFileSize[i];
	*size = PakFileSize[no];
}

int MsLoad(void)
{
	int ret;

	if (MsAccessFlag != 0)
		return -1;
	printf("AUTO LOAD START\n");
	memset(&savedata_param, 0, sizeof(savedata_param));
	savedata_param.base.size = sizeof(savedata_param);
	savedata_param.base.main_thread_priority = 0x11;
	savedata_param.base.sub_thread_priority = 0x13;
	savedata_param.base.font_thread_priority = 0x12;
	savedata_param.base.sound_thread_priority = 0x10;
	savedata_param.base.ctrl_assign = 0;
	set_savedata_param(0, &savedata_param);
	ret = sceUtilitySavedataInitStart(&savedata_param);
	if (ret != 0) {
		printf("sceUtilitySavedataInitStart failed - %08x\n", ret);
		return -1;
	}
	NowSaveFlag = 1;
	MsAccessFlag = 1;
	UtilityFlag = 1;
	set_ms_dialog(0x98);
	return 0;
}

int MsLoad2(void)
{
	int ret;

	if (MsAccessFlag != 0)
		return -1;
	printf("LOAD START\n");
	memset(&savedata_param, 0, sizeof(savedata_param));
	savedata_param.base.size = sizeof(savedata_param);
	savedata_param.base.main_thread_priority = 0x11;
	savedata_param.base.sub_thread_priority = 0x13;
	savedata_param.base.font_thread_priority = 0x12;
	savedata_param.base.sound_thread_priority = 0x10;
	savedata_param.base.ctrl_assign = 0;
	set_savedata_param(2, &savedata_param);
	ret = sceUtilitySavedataInitStart(&savedata_param);
	if (ret != 0) {
		printf("sceUtilitySavedataInitStart failed - %08x\n", ret);
		return -1;
	}
	NowSaveFlag = 1;
	MsAccessFlag = 1;
	UtilityFlag = 1;
	return 0;
}

int save_confirm(void)
{
	MsAccessFlag = 1;
	set_ms_dialog(0xA4);
	MsType = 1;
	return 0;
}

#ifdef NON_MATCHING
/* Close: the original does not move the sceIoDevctl arguments above the
   MsAccessFlag test. */
int MsSave(void)
{
	int ret = -1;
	int err;
	int status;

	if (MsAccessFlag == 0) {
		err = sceIoDevctl("mscmhc0:", 0x02025806, NULL, 0, &status, sizeof(status));
		if (err >= 0)
			err = status == 1;
		if (err != 0 || OldError != 0x80110381) {
			printf("PUZZLE AUTO SAVE\n");
			memset(&savedata_param, 0, sizeof(savedata_param));
			savedata_param.base.size = sizeof(savedata_param);
			savedata_param.base.main_thread_priority = 0x11;
			savedata_param.base.sub_thread_priority = 0x13;
			savedata_param.base.font_thread_priority = 0x12;
			savedata_param.base.sound_thread_priority = 0x10;
			savedata_param.base.message_lang = 0;
			savedata_param.base.ctrl_assign = 0;
			savedata_param.type = 1;
			savedata_param.overWriteMode = 1;
			set_param_save(&savedata_param);
			err = sceUtilitySavedataInitStart(&savedata_param);
			if (err == 0) {
				NowSaveFlag = 1;
				MsAccessFlag = 1;
				UtilityFlag = 1;
				set_ms_dialog(ret_GameStat() == 2 ? 0xA5 : 0xA1);
				ret = 0;
			} else {
				printf("sceUtilitySavedataInitStart failed - %08x\n", err);
				ret = -1;
				NowSaveFlag = 0;
			}
		}
	}
	return ret;
}
#else
INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", D_0002F068);
/* strings it shares with the C around it */
__asm__("D_0002F030 = 0x2F030\nD_0002F074 = 0x2F074");
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", MsSave);
#endif

int MsSave2(void)
{
	int ret;

	if (MsAccessFlag != 0)
		return -1;
	printf("PUZZLE AUTO SAVE\n");
	memset(&savedata_param, 0, sizeof(savedata_param));
	savedata_param.base.size = sizeof(savedata_param);
	savedata_param.base.main_thread_priority = 0x11;
	savedata_param.base.sub_thread_priority = 0x13;
	savedata_param.base.font_thread_priority = 0x12;
	savedata_param.base.sound_thread_priority = 0x10;
	savedata_param.type = 3;
	savedata_param.base.message_lang = 0;
	savedata_param.base.ctrl_assign = 0;
	savedata_param.overWriteMode = 1;
	set_param_save(&savedata_param);
	ret = sceUtilitySavedataInitStart(&savedata_param);
	if (ret != 0) {
		printf("sceUtilitySavedataInitStart failed - %08x\n", ret);
		NowSaveFlag = 0;
		return -1;
	}
	NowSaveFlag = 1;
	MsAccessFlag = 1;
	UtilityFlag = 1;
	return 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", utility_update_savedata);

void set_ms_dialog(int no)
{
	if (MsGim >= 0)
		release_gims(MsGim);
	MsGim = 127;
	for (;;) {
		if (get_gims(MsGim) == 0)
			break;
		if (--MsGim <= 0)
			break;
	}
	printf("MS GIM=%d\n", MsGim);
	LoadGimFile(MsGim, no);
	MsSkip = 1;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", disp_ms_dialog);

void save_data_init(void)
{
	SaveDataBuf.unk00 = 0;
	SaveDataBuf.unk04 = 0;
	SaveDataBuf.unk08 = 0;
	SaveDataBuf.unk0C = 0;
	SaveDataBuf.unk14 = 0;
	SaveDataBuf.unk18 = 0;
	SaveDataBuf.unk1C = 0;
	SaveDataBuf.unk24 = 0;
	SaveDataBuf.unk10 = 1;
	SaveDataBuf.unk20 = 1;
}

typedef struct {
	unsigned int maxClusters;
	unsigned int freeClusters;
	unsigned int maxSectors;
	unsigned int sectorSize;
	unsigned int sectorCount;
} MsInfo;

unsigned int get_free_ms(void)
{
	MsInfo info;
	MsInfo *pinfo = &info;
	int ret;

	ret = sceIoDevctl("ms0:", 0x02425818, &pinfo, sizeof(pinfo), NULL, 0);
	if (ret < 0) {
		printf("MS INFO GET ERROR! %08x\n", ret);
		return 0;
	}
	printf("bps = %d\n", info.sectorSize);
	printf("spc = %d\n", info.sectorCount);
	printf("cls = %d\n", info.maxClusters);
	printf("ecl = %d\n", info.freeClusters);
	printf("ebc = %d\n", info.maxSectors);
	printf("Free area = %d Kbytes\n", info.sectorSize * info.sectorCount * info.freeClusters / 1024);
	return info.sectorSize * info.sectorCount * info.freeClusters / 1024;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", D_0002F254);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", D_0002F258);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", D_0002F25C);
