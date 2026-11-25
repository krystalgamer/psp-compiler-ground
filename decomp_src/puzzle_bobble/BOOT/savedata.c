#include "common.h"
#include <stdio.h>
#include <string.h>
#include <utility/utility_savedata.h>
#include "savedata.h"

#define SAVEDATA_TITLEID "ULKS46002"
#define SAVEDATA_USERID "0000"
#define SAVEDATA_FILENAME "DATA.BIN"
#define DATABUF_SIZE (1024 * 1024)
#define USERDIR_COUNT 20

extern char *_sd_strings[3];
extern char *_sd_emptyTitle;
extern char _emptyIconData[22043];
extern char _iconData[22043];
extern char _bgData[38199];
extern char _dataBuf[DATABUF_SIZE];
extern char _listUserDirName[1024][20];
extern char _readIcon0[DATABUF_SIZE];
extern char _readIcon1[DATABUF_SIZE];
extern char _readPic1[DATABUF_SIZE];
extern SceUtilitySavedataListSaveNewData _newData;

static void set_param_load(SceUtilitySavedataParam *pParam);
static void set_param_listload(SceUtilitySavedataParam *pParam);
static void set_param_listsave(SceUtilitySavedataParam *pParam);
static void set_params(SceUtilitySavedataParam *pUtil);
static void set_icon0(SceUtilitySavedataParam *pParam);
static void set_icon1(SceUtilitySavedataParam *pParam);
static void set_pic1(SceUtilitySavedataParam *pParam);
static void set_snd0(SceUtilitySavedataParam *pParam);
static void set_newdata_item(SceUtilitySavedataParam *pParam);

int set_savedata_param(const int type, SceUtilitySavedataParam *pParam)
{
	pParam->type = type;
	pParam->overWriteMode = 1;
	switch (type) {
	case 0:
	case 2:
		set_param_load(pParam);
		break;
	case 1:
	case 3:
		set_param_save(pParam);
		break;
	case 4:
		set_param_listload(pParam);
		break;
	case 5:
		set_param_listsave(pParam);
		break;
	case 6:
	case 7:
		break;
	default:
		return 1;
	}
	return 0;
}

void show_results(SceUtilitySavedataParam *pParam)
{
	int result = pParam->base.result;
	int bind;

	puts("---------- savedata result ----------");
	printf("result = 0x%08x\n", pParam->base.result);
	if (result >= 0) {
		if (result == 1) {
			puts("user canceled.");
		} else {
			bind = pParam->bind & 3;
			if (bind == 1)
				printf("bind : my psp data");
			else if (bind == 2)
				printf("bind : other psp data");
			else if (bind == 3)
				printf("bind : un supported");
			else
				printf("bind : un used");
			printf("(0x%x).\n", bind);
			printf("\n");
			printf("-- %s --\n", (pParam->type & 1) ? "saved data" : "loaded data");
			printf("size : %d\n", pParam->dataFileSize);
			printf("\n");
			if (!(pParam->type & 1)) {
				puts("-- system file --");
				puts("size >");
				printf("\ttilte          : %d\n", strlen(pParam->systemFile.title));
				printf("\tsavedata tilte : %d\n", strlen(pParam->systemFile.savedataTitle));
				printf("\tdetail         : %d\n", strlen(pParam->systemFile.detail));
				puts("parental lock level >");
				printf("\t%d\n", pParam->systemFile.parentalLev);
				printf("\n");
				puts("-- external file --");
				printf("icon0 : %d\n", pParam->icon0.dataFileSize);
				printf("icon1 : %d\n", pParam->icon1.dataFileSize);
				printf("pic1  : %d\n", pParam->pic1.dataFileSize);
				printf("\n");
			}
			puts("-- dir name --");
			printf("title id : %s\n", pParam->titleId);
			printf("user  id : %s\n", pParam->userId);
			printf("\n");
		}
	}
	puts("-------------------------------------");
}

static void set_param_load(SceUtilitySavedataParam *pParam)
{
	int len;

	len = strlen(SAVEDATA_TITLEID);
	memcpy(pParam->titleId, SAVEDATA_TITLEID, len);
	pParam->titleId[len] = 0;
	len = strlen(SAVEDATA_USERID);
	memcpy(pParam->userId, SAVEDATA_USERID, len);
	pParam->userId[len] = 0;
	sprintf(pParam->fileName, "%s", SAVEDATA_FILENAME);
	pParam->pDataBuf = _dataBuf;
	pParam->dataBufSize = DATABUF_SIZE;
	memset(&pParam->systemFile, 0, sizeof(SceUtilitySDSystemFileParam));
	pParam->icon0.pDataBuf = _readIcon0;
	pParam->icon0.dataBufSize = DATABUF_SIZE;
	pParam->icon1.pDataBuf = _readIcon1;
	pParam->icon1.dataBufSize = DATABUF_SIZE;
	pParam->pic1.pDataBuf = _readPic1;
	pParam->pic1.dataBufSize = DATABUF_SIZE;
}

void set_param_save(SceUtilitySavedataParam *pParam)
{
	int len;

	len = strlen(SAVEDATA_TITLEID);
	memcpy(pParam->titleId, SAVEDATA_TITLEID, len);
	pParam->titleId[len] = 0;
	len = strlen(SAVEDATA_USERID);
	memcpy(pParam->userId, SAVEDATA_USERID, len);
	pParam->userId[len] = 0;
	printf("SAVE NAME = %s\n", pParam->titleId);
	sprintf(pParam->fileName, "%s", SAVEDATA_FILENAME);
	if (SaveDataBuf.unk20 > 500)
		SaveDataBuf.unk20 = 500;
	if (SaveDataBuf.unk18 > 999)
		SaveDataBuf.unk18 = 999;
	if (SaveDataBuf.unk1C > 999)
		SaveDataBuf.unk1C = 999;
	if (SaveDataBuf.unk14 > 9999)
		SaveDataBuf.unk14 = 9999;
	memcpy(_dataBuf, &SaveDataBuf, sizeof(SaveDataBuf));
	pParam->pDataBuf = _dataBuf;
	pParam->dataBufSize = DATABUF_SIZE;
	pParam->dataFileSize = sizeof(SaveDataBuf);
	set_params(pParam);
	set_icon0(pParam);
	set_icon1(pParam);
	set_pic1(pParam);
	set_snd0(pParam);
}

void load_buf(void)
{
	memcpy(&SaveDataBuf, _dataBuf, sizeof(SaveDataBuf));
}

static void set_param_listload(SceUtilitySavedataParam *pParam)
{
	int i;
	int len;

	len = strlen(SAVEDATA_TITLEID);
	memcpy(pParam->titleId, SAVEDATA_TITLEID, len);
	pParam->titleId[len] = 0;
	for (i = 0; i < USERDIR_COUNT; i++)
		sprintf(_listUserDirName[i], "%04d", i);
	_listUserDirName[USERDIR_COUNT][0] = 0;
	pParam->pUserIds = _listUserDirName;
	sprintf(pParam->fileName, "%s", SAVEDATA_FILENAME);
	pParam->pDataBuf = _dataBuf;
	pParam->dataBufSize = DATABUF_SIZE;
	memset(&pParam->systemFile, 0, sizeof(SceUtilitySDSystemFileParam));
	pParam->icon0.pDataBuf = _readIcon0;
	pParam->icon0.dataBufSize = DATABUF_SIZE;
	pParam->icon1.pDataBuf = _readIcon1;
	pParam->icon1.dataBufSize = DATABUF_SIZE;
	pParam->pic1.pDataBuf = _readPic1;
	pParam->pic1.dataBufSize = DATABUF_SIZE;
}

#ifdef NON_MATCHING
/* Close: the original computes the address of entry 21 (the terminator)
   from a register holding 21, and keeps %hi(_listUserDirName) apart. */
static void set_param_listsave(SceUtilitySavedataParam *pParam)
{
	int i;
	int len;

	len = strlen(SAVEDATA_TITLEID);
	memcpy(pParam->titleId, SAVEDATA_TITLEID, len);
	pParam->titleId[len] = 0;
	for (i = 0; i < USERDIR_COUNT; i++)
		sprintf(_listUserDirName[i], "%03d", i);
	len = strlen(SAVEDATA_TITLEID);
	memcpy(pParam->titleId, SAVEDATA_TITLEID, len);
	pParam->titleId[len] = 0;
	sprintf(_listUserDirName[i], "%s", "NEW");
	_listUserDirName[i + 1][0] = 0;
	pParam->pUserIds = _listUserDirName;
	sprintf(pParam->fileName, "%s", SAVEDATA_FILENAME);
	len = strlen("ABCDEFGHIJKLMNOPQRSTUVWXYZ.");
	memcpy(_dataBuf, "ABCDEFGHIJKLMNOPQRSTUVWXYZ.", len);
	pParam->pDataBuf = _dataBuf;
	pParam->dataBufSize = DATABUF_SIZE;
	pParam->dataFileSize = len;
	set_params(pParam);
	set_icon0(pParam);
	set_icon1(pParam);
	set_pic1(pParam);
	set_newdata_item(pParam);
}
#else
/* the strings it shares with the C above */
__asm__("D_0002F8F4 = 0x2F8F4\nD_0002F908 = 0x2F908\nD_0002F90C = 0x2F90C");
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/savedata", set_param_listsave);
#endif

static void set_params(SceUtilitySavedataParam *pUtil)
{
	SceUtilitySDSystemFileParam *pSysf = &pUtil->systemFile;

	memcpy(pSysf->title, _sd_strings[0], strlen(_sd_strings[0]) + 1);
	memcpy(pSysf->savedataTitle, _sd_strings[1], strlen(_sd_strings[1]) + 1);
	memcpy(pSysf->detail, _sd_strings[2], strlen(_sd_strings[2]) + 1);
	pSysf->parentalLev = 1;
}

static void set_icon0(SceUtilitySavedataParam *pParam)
{
	pParam->icon0.pDataBuf = _iconData;
	pParam->icon0.dataBufSize = sizeof(_iconData);
	pParam->icon0.dataFileSize = sizeof(_iconData);
}

static void set_icon1(SceUtilitySavedataParam *pParam)
{
	pParam->icon1.pDataBuf = NULL;
	pParam->icon1.dataBufSize = 0;
	pParam->icon1.dataFileSize = 0;
}

static void set_pic1(SceUtilitySavedataParam *pParam)
{
	pParam->pic1.pDataBuf = _bgData;
	pParam->pic1.dataBufSize = sizeof(_bgData);
	pParam->pic1.dataFileSize = sizeof(_bgData);
}

static void set_snd0(SceUtilitySavedataParam *pParam)
{
	pParam->snd0.pDataBuf = NULL;
	pParam->snd0.dataBufSize = 0;
	pParam->snd0.dataFileSize = 0;
}

static void set_newdata_item(SceUtilitySavedataParam *pParam)
{
	_newData.icon0.pDataBuf = _emptyIconData;
	_newData.icon0.dataBufSize = sizeof(_emptyIconData);
	_newData.icon0.dataFileSize = sizeof(_emptyIconData);
	_newData.pTitle = _sd_emptyTitle;
	pParam->pNewData = &_newData;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/savedata", D_0002F958);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/savedata", D_0002F988);
