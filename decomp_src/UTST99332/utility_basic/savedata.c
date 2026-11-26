#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon2;
struct _anon2 { /* size 0x30 */
    unsigned int size;
    int message_lang;
    int ctrl_assign;
    int main_thread_priority;
    int sub_thread_priority;
    int font_thread_priority;
    int sound_thread_priority;
    int result;
    int reserved1;
    int reserved2;
    int reserved3;
    int reserved4;
};
typedef struct _anon2 SceUtilityParamBase;
struct _anon3;
struct _anon3 { /* size 0x504 */
    char title[128];
    char savedataTitle[128];
    char detail[1024];
    unsigned char parentalLev;
    unsigned char reserved[3];
};
typedef struct _anon3 SceUtilitySDSystemFileParam;
struct _anon4;
struct _anon4 { /* size 0x10 */
    void *pDataBuf;
    unsigned int dataBufSize;
    unsigned int dataFileSize;
    char *pFilePath;
};
typedef struct _anon4 SceUtilitySDExtFile;
struct _anon5;
struct _anon5 { /* size 0x14 */
    SceUtilitySDExtFile icon0;
    char *pTitle;
};
typedef struct _anon5 SceUtilitySavedataListSaveNewData;
struct _anon6;
struct _anon6 { /* size 0x14 */
    unsigned int msClusterSizeByte;
    unsigned int msFreeCluster;
    unsigned int msFreeSizeKB;
    char msFreeSizeStr[8];
};
typedef struct _anon6 SceUtilitySavedataMsFreeSize;
struct _anon7;
struct _anon7 { /* size 0x40 */
    char titleId[13];
    char reserved[3];
    char userId[20];
    unsigned int cluster;
    unsigned int sizeKB;
    char sizeStr[8];
    unsigned int size32KB;
    char size32Str[8];
};
typedef struct _anon7 SceUtilitySavedataMsDataSize;
struct _anon8;
struct _anon8 { /* size 0x1c */
    unsigned int cluster;
    unsigned int sizeKB;
    char sizeStr[8];
    unsigned int size32KB;
    char size32Str[8];
};
typedef struct _anon8 SceUtilitySavedataUtilityDataSize;
struct _anon1 { /* size 0x5dc */
    SceUtilityParamBase base;
    int type;
    unsigned int bind;
    unsigned int overWriteMode;
    char titleId[13];
    char reserved[3];
    char userId[20];
    char (*pUserIds)[20];
    char fileName[13];
    char reserved1[3];
    void *pDataBuf;
    unsigned int dataBufSize;
    unsigned int dataFileSize;
    SceUtilitySDSystemFileParam systemFile;
    SceUtilitySDExtFile icon0;
    SceUtilitySDExtFile icon1;
    SceUtilitySDExtFile pic1;
    SceUtilitySDExtFile snd0;
    SceUtilitySavedataListSaveNewData *pNewData;
    unsigned int initFocus;
    int abortedStatus;
    SceUtilitySavedataMsFreeSize *pMs;
    SceUtilitySavedataMsDataSize *pMsData;
    SceUtilitySavedataUtilityDataSize *pUtilityData;
};
typedef struct _anon1 SceUtilitySavedataParam;

extern char *_sd_strings[3];
extern char *_sd_emptyTitle;
extern char _emptyIconData[14157];
extern char _iconData[21438];
extern char _bgData[75906];
extern char _dataBuf[1048576];
extern char _listUserDirName[1024][20];
extern char _readIcon0[1048576];
extern char _readIcon1[1048576];
extern char _readPic1[1048576];
extern SceUtilitySavedataListSaveNewData _newData;
extern SceUtilitySavedataMsFreeSize _msFreeSize;
extern SceUtilitySavedataMsDataSize _msDataSize;
extern SceUtilitySavedataUtilityDataSize _utilityDataSize;

int set_savedata_param(const int type, SceUtilitySavedataParam *pParam);
void show_results(SceUtilitySavedataParam *pParam);
static void set_param_load(SceUtilitySavedataParam *pParam);
static void set_param_save(SceUtilitySavedataParam *pParam);
static void set_param_listload(SceUtilitySavedataParam *pParam);
static void set_param_listsave(SceUtilitySavedataParam *pParam);
static void set_param_listdelete(SceUtilitySavedataParam *pParam);
static void set_params(SceUtilitySavedataParam *pUtil);
static void set_icon0(SceUtilitySavedataParam *pParam);
static void set_pic1(SceUtilitySavedataParam *pParam);
static void set_icon1(SceUtilitySavedataParam *pParam);
static void set_snd0(SceUtilitySavedataParam *pParam);
static void set_newdata_item(SceUtilitySavedataParam *pParam);
static void set_param_sizes(SceUtilitySavedataParam *pParam);


void Menu_WriteLine(const char *line, int color);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", D_00016548);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", D_00016558);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", D_00016578);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", D_000166D8);

int set_savedata_param(const int type, SceUtilitySavedataParam *pParam)
{
	pParam->overWriteMode = 1;
	pParam->type = type;

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
		set_param_listdelete(pParam);
		break;
	case 7:
		break;
	case 8:
		set_param_sizes(pParam);
		break;
	default:
		return 1;
	}

	return 0;
}

void show_results(SceUtilitySavedataParam *pParam) {
}

extern const char D_00016714[]; /* "SLPS10000" (shared rodata) */
extern const char D_00016720[]; /* "0000" */
extern const char D_00016728[]; /* "%s" */
extern const char D_0001672C[]; /* "DATA.BIN" */
void *memcpy(void *dst, const void *src, unsigned long n); /* SDK size_t is unsigned long: not the builtin */
void *memset(void *s, int c, unsigned int n);
int sprintf(char *buf, const char *fmt, ...);

void set_param_load(SceUtilitySavedataParam *pParam)
{
	int len;

	memcpy(pParam->titleId, D_00016714, 9);
	pParam->titleId[9] = 0;

	memcpy(pParam->userId, D_00016720, 4);
	pParam->userId[4] = 0;

	sprintf(pParam->fileName, D_00016728, D_0001672C);

	pParam->pDataBuf = _dataBuf;
	pParam->dataBufSize = 0x100000;

	memset(&pParam->systemFile, 0, sizeof(pParam->systemFile));

	pParam->icon0.pDataBuf = _readIcon0;
	pParam->icon0.dataBufSize = 0x100000;

	pParam->icon1.pDataBuf = _readIcon1;
	pParam->icon1.dataBufSize = 0x100000;

	pParam->pic1.pDataBuf = _readPic1;
	pParam->pic1.dataBufSize = 0x100000;
}

extern const char D_00016738[]; /* save data text (shared rodata) */

void set_param_save(SceUtilitySavedataParam *pParam)
{
	int len;

	memcpy(pParam->titleId, D_00016714, 9);
	pParam->titleId[9] = 0;

	memcpy(pParam->userId, D_00016720, 4);
	pParam->userId[4] = 0;

	sprintf(pParam->fileName, D_00016728, D_0001672C);

	len = 27;
	memcpy(_dataBuf, D_00016738, len);
	pParam->pDataBuf = _dataBuf;
	pParam->dataBufSize = 0x100000;
	pParam->dataFileSize = len;

	set_params(pParam);

	set_icon0(pParam);
	set_icon1(pParam);
	set_pic1(pParam);
	set_snd0(pParam);
}

extern const char D_00016754[]; /* "%04d" (shared rodata) */

void set_param_listload(SceUtilitySavedataParam *pParam)
{
	int i, len, dirNum;

	memcpy(pParam->titleId, D_00016714, 9);
	pParam->titleId[9] = 0;

	for (i = 0; i < 20; i++) {
		sprintf(_listUserDirName[i], D_00016754, i);
	}
	_listUserDirName[20][0] = 0;

	pParam->pUserIds = _listUserDirName;

	sprintf(pParam->fileName, D_00016728, D_0001672C);

	pParam->pDataBuf = _dataBuf;
	pParam->dataBufSize = 0x100000;

	memset(&pParam->systemFile, 0, sizeof(pParam->systemFile));

	pParam->icon0.pDataBuf = _readIcon0;
	pParam->icon0.dataBufSize = 0x100000;

	pParam->icon1.pDataBuf = _readIcon1;
	pParam->icon1.dataBufSize = 0x100000;

	pParam->pic1.pDataBuf = _readPic1;
	pParam->pic1.dataBufSize = 0x100000;
}

void set_param_listsave(SceUtilitySavedataParam *pParam)
{
	int len, dirNum;

	memcpy(pParam->titleId, D_00016714, 9);
	pParam->titleId[9] = 0;

	for (dirNum = 0; dirNum < 20; dirNum++) {
		sprintf(_listUserDirName[dirNum], D_00016754, dirNum);
	}
	_listUserDirName[20][0] = 0;

	pParam->pUserIds = _listUserDirName;

	sprintf(pParam->fileName, D_00016728, D_0001672C);

	len = 27;
	memcpy(_dataBuf, D_00016738, len);
	pParam->pDataBuf = _dataBuf;
	pParam->dataBufSize = 0x100000;
	pParam->dataFileSize = len;

	set_params(pParam);

	set_icon0(pParam);
	set_icon1(pParam);
	set_pic1(pParam);
	set_snd0(pParam);

	set_newdata_item(pParam);
}

void set_param_listdelete(SceUtilitySavedataParam *pParam)
{
	int i, len;

	memcpy(pParam->titleId, D_00016714, 9);
	pParam->titleId[9] = 0;

	for (i = 0; i < 20; i++) {
		sprintf(_listUserDirName[i], D_00016754, i);
	}
	_listUserDirName[20][0] = 10;

	pParam->pUserIds = _listUserDirName;
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", set_params);

void set_icon0(SceUtilitySavedataParam *pParam)
{
	pParam->icon0.pDataBuf = _iconData;
	pParam->icon0.dataBufSize = 0x53BE;
	pParam->icon0.dataFileSize = 0x53BE;
}

void set_pic1(SceUtilitySavedataParam *pParam)
{
	pParam->pic1.pDataBuf = _bgData;
	pParam->pic1.dataBufSize = 0x12882;
	pParam->pic1.dataFileSize = 0x12882;
}

void set_icon1(SceUtilitySavedataParam *pParam)
{
	pParam->icon1.pDataBuf = NULL;
	pParam->icon1.dataBufSize = 0;
	pParam->icon1.dataFileSize = 0;
}

void set_snd0(SceUtilitySavedataParam *pParam)
{
	pParam->snd0.pDataBuf = NULL;
	pParam->snd0.dataBufSize = 0;
	pParam->snd0.dataFileSize = 0;
}

void set_newdata_item(SceUtilitySavedataParam *pParam)
{
	_newData.icon0.pDataBuf = _emptyIconData;
	_newData.icon0.dataBufSize = 0x374D;
	_newData.icon0.dataFileSize = 0x374D;

	_newData.pTitle = _sd_emptyTitle;

	pParam->pNewData = &_newData;
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", set_param_sizes);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", D_00016714);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", D_00016720);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", D_00016728);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", D_0001672C);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", D_00016738);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/savedata", D_00016754);
