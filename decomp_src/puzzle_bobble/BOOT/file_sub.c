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
/* The unit's .bss (config `bss 0x153A28 file_sub`): these four, disp_ms_dialog's
 * DebugX.0, then PakData and savedata_param (tentative). */
int MsType = 0;
int MsSkip = 0;
int UtilityFlag = 0;
int OldError = 0;
static char *PakData;
static SceUtilitySavedataParam savedata_param;

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

/* ms_check() returns err early (`if (err < 0) return err;`): with `err = status == 1`
 * in an if the err < 0 path is jump-threaded past the caller's test.  The three flag
 * stores are written NowSaveFlag, MsAccessFlag, UtilityFlag. */
/* STAND-IN: "mscmhc0:" stays asm data (disp_ms_dialog, still asm, uses it too). */
extern const char D_0002F068[];
INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", D_0002F068);

static __inline__ int ms_check(void)
{
	int status;
	int err = sceIoDevctl(D_0002F068, 0x02025806, NULL, 0, &status, sizeof(status));

	if (err < 0)
		return err;
	return status == 1;
}
int MsSave(void)
{
	int err;

	if (MsAccessFlag != 0)
		return -1;
	if (ms_check() == 0 && OldError == 0x80110381)
		return -1;
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
	if (err != 0) {
		printf("sceUtilitySavedataInitStart failed - %08x\n", err);
		NowSaveFlag = 0;
		return -1;
	}
	NowSaveFlag = 1;
	MsAccessFlag = 1;
	UtilityFlag = 1;
	if (ret_GameStat() != 2)
		set_ms_dialog(0xA1);
	else
		set_ms_dialog(0xA5);
	return 0;
}

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

#ifdef NON_MATCHING
/* Two instructions short: logic and case layout complete (case order 2, 0, 1, 3, 4 and
 * type order 2, 0, 1 reproduce the original block order); the status dispatch and the
 * type register (v1 in the original, s1 here) differ. */
extern int D_0101C3B8;
int ret_GameStat(void);
unsigned int get_free_ms(void);
int utility_update_savedata(void)
{
	int ret = 0;
	int status;

	if (NowSaveFlag == 0)
		return ret;
	status = sceUtilitySavedataGetStatus();
	switch (status) {
	case 2:
		sceGuSync(0, 0);
		ret = sceUtilitySavedataUpdate(1);
		if (ret != 0)
			printf("sceUtilitySavedataUpdate failed - %08x\n", ret);
		break;
	case 0:
		UtilityFlag = 0;
		puts("SCE_UTILITY_COMMON_STATUS_NONE");
		if (MsGim >= 0) {
			release_gims(MsGim);
			MsGim = -1;
		}
		NowSaveFlag = 0;
		MsAccessFlag = 0;
		switch (savedata_param.type) {
		case 2:
			MsAccessFlag = 1;
			if (savedata_param.base.result == 0) {
				load_buf();
				printf("STAGE = %d\n", D_0101C3B8);
			}
			MsAccessFlag = 0;
			break;
		case 0:
			puts("AUTO LOAD END");
			MsAccessFlag = 1;
			switch (savedata_param.base.result) {
			case 0x80110306:
				set_ms_dialog(0x9B);
				MsType = 2;
				MsWait = 180;
				break;
			case 0x80110301:
			case 0x80110302:
				if (ret_GameStat() == 8) {
					set_ms_dialog(0x9F);
					MsType = 3;
				} else {
					set_ms_dialog(0x94);
					MsType = 4;
					MsWait = 180;
				}
				break;
			case 0x80110307:
				if (ret_GameStat() == 8) {
					set_ms_dialog(0x97);
					MsType = 4;
				} else if ((int)get_free_ms() < 0x100)
					set_ms_dialog(0x96);
				else
					set_ms_dialog(0x95);
				break;
			case 0:
				load_buf();
				printf("STAGE = %d\n", D_0101C3B8);
				MsAccessFlag = 0;
				break;
			case 0x8011030B:
			default:
				set_ms_dialog(0x8F);
				break;
			}
			break;
		case 1:
			puts("AUTO SAVE END");
			MsAccessFlag = 1;
			printf("SAVE FINISH %08x\n", savedata_param.base.result);
			switch (savedata_param.base.result) {
			case 0x80110384:
				if (OldError != savedata_param.base.result) {
					set_ms_dialog(0xA7);
					MsType = 6;
				} else
					MsAccessFlag = 0;
				break;
			case 0x80110381:
			case 0x80110382:
				if (OldError == savedata_param.base.result)
					MsAccessFlag = 0;
				else {
					set_ms_dialog(0x9C);
					MsType = 5;
					puts("MsType = 5");
				}
				break;
			case 0x80110383:
				if (OldError == savedata_param.base.result)
					MsAccessFlag = 0;
				else {
					set_ms_dialog(0xA0);
					MsType = 6;
					puts("MsType = 6");
				}
				break;
			case 0:
				MsAccessFlag = 0;
				break;
			case 0x8011038B:
			default:
				if (OldError == savedata_param.base.result)
					MsAccessFlag = 0;
				else {
					set_ms_dialog(0xA2);
					MsType = 6;
				}
				break;
			}
			OldError = savedata_param.base.result;
			break;
		}
		break;
	case 1:
		break;
	case 3:
		ret = sceUtilitySavedataShutdownStart();
		if (ret != 0)
			printf("sceUtilitySavedataShutdownStart failed - %08x\n", ret);
		show_results(&savedata_param);
		break;
	case 4:
		puts("SCE_UTILITY_COMMON_STATUS_SHUTDOWN");
		break;
	default:
		if (status != 0)
			printf("SAVE UTILITY STATUS = %08x\n", status);
		break;
	}
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", utility_update_savedata);
#endif

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

#ifdef NON_MATCHING
/* Rough (7 instructions short): the logic of all seven MsType cases, with ms_check()
 * (from the MsSave draft) inlined four times as in the original; the original shares more
 * tails between the cases (crossjumping) and keeps the two sprite floats in $f20-$f22. */
void disp_ms_dialog(void)
{
	static int DebugX;
	if (MsGim < 0)
		return;
	if (MsSkip) {
		MsSkip = 0;
	} else {
		SetSpriteColorRGBA(255, 255, 255, 255);
		DrawSpriteEz(0.0f, 0.0f, 84.0f, 240.0f, 104.0f, 0.0f, 0.0f, MsGim);
		DrawSpriteEz(0.0f, 240.0f, 84.0f, 240.0f, 104.0f, 240.0f, 0.0f, MsGim);
		DebugX = (DebugX + 1) & 0xFF;
	}
	if (UtilityFlag > 0)
		return;
	switch (MsType) {
	case 1:
		if (GetKeyHit() & 0x2000) {
			MsType = 0;
			MsSave();
		}
		if (GetKeyHit() & 0x4000) {
			MsType = 0;
			release_gims(MsGim);
			MsGim = -1;
			se_play(3);
			MsAccessFlag = 0;
		}
		break;
	case 2:
		if (--MsWait < 0) {
			MsType = 0;
			release_gims(MsGim);
			MsGim = -1;
			NowSaveFlag = 0;
			MsAccessFlag = 0;
		}
		break;
	case 3:
		if (ms_check() > 0) {
			NowSaveFlag = 0;
			MsAccessFlag = 0;
			MsType = 0;
			OldError = 0;
			MsLoad();
		}
		if (GetKeyHit() & 0x4000) {
			MsType = 0;
			release_gims(MsGim);
			MsGim = -1;
			NowSaveFlag = 0;
			MsAccessFlag = 0;
		}
		break;
	case 4:
		if (ms_check() > 0) {
			NowSaveFlag = 0;
			MsAccessFlag = 0;
			OldError = 0;
			MsType = 0;
			MsLoad();
		}
		if (GetKeyHit() & 0x4000) {
			MsType = 0;
			release_gims(MsGim);
			MsGim = -1;
			NowSaveFlag = 0;
			MsAccessFlag = 0;
			OldError = 0;
		}
		break;
	case 5:
		if (ms_check() > 0) {
			MsType = 0;
			puts("MsSave");
			NowSaveFlag = 0;
			MsAccessFlag = 0;
			OldError = 0;
			MsSave();
		}
		if (GetKeyHit() & 0x4000) {
			MsType = 0;
			release_gims(MsGim);
			MsGim = -1;
			NowSaveFlag = 0;
			MsAccessFlag = 0;
		}
		break;
	case 6:
		if (ms_check() == 0) {
			MsType = 0;
			puts("MsSave");
			NowSaveFlag = 0;
			MsAccessFlag = 0;
			OldError = 0;
			MsSave();
		}
		if (GetKeyHit() & 0x4000) {
			MsType = 0;
			release_gims(MsGim);
			MsGim = -1;
			NowSaveFlag = 0;
			MsAccessFlag = 0;
		}
		break;
	default:
		if (GetKeyHit() & 0x4008) {
			MsType = 0;
			release_gims(MsGim);
			MsGim = -1;
			NowSaveFlag = 0;
			MsAccessFlag = 0;
		}
		break;
	}
}
#else
/* STAND-IN: disp_ms_dialog is still asm.  Its statics, in its place and numbered as in
 * the original (DebugX.0); initialized ones only keep the numbering (their .data stays asm). */
static void __attribute__((section(".pbskip"), unused)) disp_ms_dialog_statics(void)
{
	static int DebugX;
}
__asm__("D_00153A38 = DebugX.0");
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/file_sub", disp_ms_dialog);
#endif

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
