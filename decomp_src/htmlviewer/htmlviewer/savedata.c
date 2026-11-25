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
    unsigned char typeWriteRemoveUpdateParam;
    unsigned char reserved[2];
};
typedef struct _anon3 SceUtilitySDSystemFileParam;
struct _anon4;
struct _anon4 { /* size 0x10 */
    void *pDataBuf;
    unsigned int dataBufSize;
    unsigned int dataFileSize;
    char *reserved;
};
typedef struct _anon4 SceUtilitySDExtFile;
struct _anon5;
struct _anon5 { /* size 0x14 */
    SceUtilitySDExtFile icon0;
    const char *pTitle;
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
struct _anon9;
struct _anon10;
typedef int SceMode;
typedef struct ScePspDateTime ScePspDateTime;
struct ScePspDateTime;
struct ScePspDateTime { /* size 0x10 */
    short unsigned int year;
    short unsigned int month;
    short unsigned int day;
    short unsigned int hour;
    short unsigned int minute;
    short unsigned int second;
    unsigned int microsecond;
};
struct _anon10 { /* size 0x48 */
    SceMode st_mode;
    ScePspDateTime st_ctime;
    ScePspDateTime st_atime;
    ScePspDateTime st_mtime;
    char userId[20];
};
typedef struct _anon10 SceUtilitySDUserIdStat;
struct _anon9 { /* size 0xc */
    unsigned int userIdMax;
    unsigned int userIdNum;
    SceUtilitySDUserIdStat *pUserIds;
};
typedef struct _anon9 SceUtilitySavedataUserIdList;
struct _anon11;
struct _anon12;
typedef long long int SceOff;
struct _anon12 { /* size 0x50 */
    SceMode st_mode;
    unsigned int reserved;
    SceOff st_size;
    ScePspDateTime st_ctime;
    ScePspDateTime st_atime;
    ScePspDateTime st_mtime;
    char fileName[13];
    char reserved1[3];
};
typedef struct _anon12 SceUtilitySDFileStat;
struct _anon11 { /* size 0x24 */
    unsigned int secureFileMax;
    unsigned int normalFileMax;
    unsigned int systemFileMax;
    unsigned int secureFileNum;
    unsigned int normalFileNum;
    unsigned int systemFileNum;
    SceUtilitySDFileStat *pSecureFiles;
    SceUtilitySDFileStat *pNormalFiles;
    SceUtilitySDFileStat *pSystemFiles;
};
typedef struct _anon11 SceUtilitySavedataFileList;
struct _anon13;
struct _anon14;
struct _anon14 { /* size 0x18 */
    SceOff st_size;
    char fileName[13];
    char reserved[3];
};
typedef struct _anon14 SceUtilitySDFileStat2;
struct _anon13 { /* size 0x3c */
    unsigned int secureFileNum;
    unsigned int normalFileNum;
    SceUtilitySDFileStat2 *pSecureFiles;
    SceUtilitySDFileStat2 *pNormalFiles;
    unsigned int msClusterSizeByte;
    unsigned int msFreeCluster;
    unsigned int msFreeSizeKB;
    char msFreeSizeStr[8];
    unsigned int createNeedSizeKB;
    char createNeedSizeStr[8];
    unsigned int overwriteNeedSizeKB;
    char overwriteNeedSizeStr[8];
};
typedef struct _anon13 SceUtilitySavedataCheckSize;
struct _anon1 { /* size 0x600 */
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
    unsigned char secureFileId[16];
    unsigned int dataVersion;
    unsigned int mcStatus;
    SceUtilitySavedataUserIdList *pUserIdList;
    SceUtilitySavedataFileList *pFileList;
    SceUtilitySavedataCheckSize *pCheckSize;
};
typedef struct _anon1 SceUtilitySavedataParam;

extern const char *const _sd_strings[3];
extern const char *const _sd_strings2[3];
extern const char *_sd_emptyTitle;
extern char _dataBuf[1048576];
extern char _readIcon0[1048576];
extern char _readIcon1[1048576];
extern char _readPic1[1048576];
extern char _readSnd0[1048576];
extern SceUtilitySavedataListSaveNewData _newData;

int set_savedata_param(const int type, SceUtilitySavedataParam *pParam);
static void set_param_load(SceUtilitySavedataParam *pParam);
static void set_param_save(SceUtilitySavedataParam *pParam);
static void set_params(SceUtilitySavedataParam *pUtil);
static void set_icon0(SceUtilitySavedataParam *pParam);
static void set_pic1(SceUtilitySavedataParam *pParam);
static void set_icon1(SceUtilitySavedataParam *pParam);
static void set_snd0(SceUtilitySavedataParam *pParam);
static void set_newdata_item(SceUtilitySavedataParam *pParam);

#define SD_DIRNAME_MODELNUM "SLPS1000"
#define SD_DIRNAME_PARTNUM "DATA00"
#define SD_FILENAME "SECURE.BIN"
#define SD_SAVEDATA "ABCDEFGHIJKLMNOPQRSTUVWXYZ."
#define SD_BUFF_SIZE (1024 * 1024)

/* the *Size locals are absolute linker symbols (sizes of the linked-in binary files) */
extern char PRX_ZERO[];
#define _icon0Size ((int)(PRX_ZERO + 0x3C7B))
#define _icon_newSize ((int)(PRX_ZERO + 0x32FB))
#define _pic1Size ((int)(PRX_ZERO + 0x1DC9E))
#define _icon1Size ((int)(PRX_ZERO + 0x1B800))
#define _snd0Size ((int)(PRX_ZERO + 0x154AC))

void *memcpy(void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);
unsigned int strlen(const char *);
char *strcpy(char *, const char *);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/savedata", D_0001D4C8);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/savedata", D_0001D4DC);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/savedata", D_0001D4F8);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/savedata", _sd_strings);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/savedata", D_0001D598);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/savedata", D_0001D5AC);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/savedata", D_0001D5BC);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/savedata", _sd_strings2);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/savedata", D_0001D5F4);

const unsigned char _secure_file_id[16] = {
    0x01, 0xAF, 0x6F, 0x00, 0x02, 0x00, 0x70, 0xD5, 0x2E, 0x24, 0x12, 0xC7, 0xE1, 0xFF, 0x83, 0xBA
};

int set_savedata_param(const int type, SceUtilitySavedataParam *pParam)
{
    pParam->overWriteMode = 1;
    memcpy(pParam->secureFileId, _secure_file_id, sizeof(pParam->secureFileId));
    pParam->type = type;
    switch (type) {
    case 2:
        set_param_load(pParam);
        break;
    case 3:
        set_param_save(pParam);
        break;
    case 7:
        break;
    default:
        return 1;
        break;
    }
    return 0;
}

static void set_param_load(SceUtilitySavedataParam *pParam)
{
    unsigned int len;

    len = strlen(SD_DIRNAME_MODELNUM);
    memcpy(pParam->titleId, SD_DIRNAME_MODELNUM, len);
    pParam->titleId[len] = '\0';
    len = strlen(SD_DIRNAME_PARTNUM);
    memcpy(pParam->userId, SD_DIRNAME_PARTNUM, len);
    pParam->userId[len] = '\0';
    strcpy(pParam->fileName, SD_FILENAME);
    pParam->pDataBuf = _dataBuf;
    pParam->dataBufSize = SD_BUFF_SIZE;
    memset(&pParam->systemFile, 0x00, sizeof(SceUtilitySDSystemFileParam));
    pParam->icon0.pDataBuf = _readIcon0;
    pParam->icon0.dataBufSize = SD_BUFF_SIZE;
    pParam->icon1.pDataBuf = _readIcon1;
    pParam->icon1.dataBufSize = SD_BUFF_SIZE;
    pParam->pic1.pDataBuf = _readPic1;
    pParam->pic1.dataBufSize = SD_BUFF_SIZE;
    pParam->snd0.pDataBuf = _readSnd0;
    pParam->snd0.dataBufSize = SD_BUFF_SIZE;
}

static void set_param_save(SceUtilitySavedataParam *pParam)
{
    unsigned int len;

    len = strlen(SD_DIRNAME_MODELNUM);
    memcpy(pParam->titleId, SD_DIRNAME_MODELNUM, len);
    pParam->titleId[len] = '\0';
    len = strlen(SD_DIRNAME_PARTNUM);
    memcpy(pParam->userId, SD_DIRNAME_PARTNUM, len);
    pParam->userId[len] = '\0';
    strcpy(pParam->fileName, SD_FILENAME);
    len = strlen(SD_SAVEDATA);
    memcpy(_dataBuf, SD_SAVEDATA, len);
    pParam->pDataBuf = _dataBuf;
    pParam->dataBufSize = SD_BUFF_SIZE;
    pParam->dataFileSize = len;
    set_params(pParam);
    set_icon0(pParam);
    set_icon1(pParam);
    set_pic1(pParam);
    set_snd0(pParam);
    set_newdata_item(pParam);
}

static void set_params(SceUtilitySavedataParam *pUtil)
{
    SceUtilitySDSystemFileParam *pSysf = &pUtil->systemFile;
    const char *const *pStrings = _sd_strings;

    memcpy(pSysf->title, pStrings[0], strlen(pStrings[0]) + 1);
    memcpy(pSysf->savedataTitle, pStrings[1], strlen(pStrings[1]) + 1);
    memcpy(pSysf->detail, pStrings[2], strlen(pStrings[2]) + 1);
    pSysf->parentalLev = 1;
}

static void set_icon0(SceUtilitySavedataParam *pParam)
{
    extern const unsigned char _icon0[];

    pParam->icon0.pDataBuf = (void *)_icon0;
    pParam->icon0.dataBufSize = _icon0Size;
    pParam->icon0.dataFileSize = _icon0Size;
}

static void set_pic1(SceUtilitySavedataParam *pParam)
{
    extern const unsigned char _pic1[];

    pParam->pic1.pDataBuf = (void *)_pic1;
    pParam->pic1.dataBufSize = _pic1Size;
    pParam->pic1.dataFileSize = _pic1Size;
}

static void set_icon1(SceUtilitySavedataParam *pParam)
{
    extern const unsigned char _icon1[];

    pParam->icon1.pDataBuf = (void *)_icon1;
    pParam->icon1.dataBufSize = _icon1Size;
    pParam->icon1.dataFileSize = _icon1Size;
}

static void set_snd0(SceUtilitySavedataParam *pParam)
{
    extern const unsigned char _snd0[];

    pParam->snd0.pDataBuf = (void *)_snd0;
    pParam->snd0.dataBufSize = _snd0Size;
    pParam->snd0.dataFileSize = _snd0Size;
}

static void set_newdata_item(SceUtilitySavedataParam *pParam)
{
    extern const unsigned char _icon_new[];

    _newData.icon0.pDataBuf = (void *)_icon_new;
    _newData.icon0.dataBufSize = _icon_newSize;
    _newData.icon0.dataFileSize = _icon_newSize;
    _newData.pTitle = _sd_emptyTitle;
    pParam->pNewData = &_newData;
}
