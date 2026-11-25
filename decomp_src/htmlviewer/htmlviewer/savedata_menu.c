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

extern int sample_type;
extern SceUtilitySavedataParam savedata_param;

void ShowResult();
void OnPush_SaveData(int selection);
static void CreateMenu_SaveData(void);
static void SaveDataPushEventTmplate(const char *pFuncName, int type, SceUtilitySavedataParam *pParam);
static void OnPush_SaveData_Normal(int selection);
static void OnCancel_SaveData_Normal(int selection);

void *memset(void *, int, unsigned int);
unsigned int strlen(const char *);
char *strcat(char *, const char *);
int sprintf(char *, const char *, ...);
int GetMessageLang(void);
int GetAssign(void);
int set_savedata_param(const int type, SceUtilitySavedataParam *pParam);
int sceUtilitySavedataInitStart(SceUtilitySavedataParam *);
void Menu_LockInput(void);
void Menu_ClearItems(void);
void Menu_AppendItem(const char *name, void (*callback)(int));
void Menu_SetCancelCallback(void (*callback)(int));
void Menu_WriteLine(const char *line, int color);
void Menu_PrintF(int color, const char *fmt, ...);
void CreateMenu_Root(void);

void ShowResult()
{
    SceUtilitySavedataParam *pParam = &savedata_param;
    int result = pParam->base.result;
    char msg[256];

    Menu_WriteLine("---------- savedata result ----------", 0xC000);
    Menu_PrintF(0xC000, "result = 0x%08x", pParam->base.result);
    if (result < 0 && pParam->type != 8 && pParam->type != 22) return;
    if (result == 1) {
        Menu_WriteLine("user canceled.", 0xC000);
        return;
    }
    {
        int bind = pParam->bind & 3;
        if (bind == 1) {
            sprintf(msg, "bind : my psp data");
        } else if (bind == 2) {
            sprintf(msg, "bind : other psp data");
        } else if (bind == 3) {
            sprintf(msg, "bind : un supported");
        } else {
            sprintf(msg, "bind : un used");
        }
        {
            char msg2[16];
            sprintf(msg2, "(0x%x).\n", bind);
            strcat(msg, msg2);
        }
        Menu_WriteLine(msg, 0xC000);
    }
    if (pParam->titleId[0] && pParam->userId[0]) {
        Menu_WriteLine("-- dir name --", 0xC000);
        Menu_PrintF(0xC000, "title id : %s", pParam->titleId);
        Menu_PrintF(0xC000, "user  id : %s", pParam->userId);
    }
    if (pParam->type == 2) {
        Menu_WriteLine("-- loaded data --", 0xC000);
    } else if (pParam->type == 3) {
        Menu_WriteLine("-- saved data --", 0xC000);
    } else if (pParam->type == 7) {
        return;
    }
    Menu_PrintF(0xC000, "size : %d", pParam->dataFileSize);
    if (pParam->type == 2) {
        Menu_WriteLine("-- PARAM.SFO string size --", 0xC000);
        Menu_PrintF(0xC000, "tilte          : %d", strlen(pParam->systemFile.title));
        Menu_PrintF(0xC000, "savedata tilte : %d", strlen(pParam->systemFile.savedataTitle));
        Menu_PrintF(0xC000, "detail         : %d", strlen(pParam->systemFile.detail));
        Menu_PrintF(0xC000, "parental lock level : %d", pParam->systemFile.parentalLev);
        Menu_WriteLine("-- content files size --", 0xC000);
        Menu_PrintF(0xC000, "icon0 : %d", pParam->icon0.dataFileSize);
        Menu_PrintF(0xC000, "icon1 : %d", pParam->icon1.dataFileSize);
        Menu_PrintF(0xC000, "pic1  : %d", pParam->pic1.dataFileSize);
        Menu_PrintF(0xC000, "snd0  : %d", pParam->snd0.dataFileSize);
    }
}

void OnPush_SaveData(int selection)
{
    Menu_WriteLine("OnPush_SaveData", 0x00ffffff);
    CreateMenu_SaveData();
}

static void CreateMenu_SaveData(void)
{
    Menu_ClearItems();
    Menu_AppendItem("Load", OnPush_SaveData_Normal);
    Menu_AppendItem("Save", OnPush_SaveData_Normal);
    Menu_AppendItem("Delete", OnPush_SaveData_Normal);
    Menu_SetCancelCallback(OnCancel_SaveData_Normal);
}

static void SaveDataPushEventTmplate(const char *pFuncName, int type, SceUtilitySavedataParam *pParam)
{
    int ret;

    Menu_WriteLine(pFuncName, 0x00ffffff);
    Menu_LockInput();
    sample_type = 1;
    memset(pParam, 0, sizeof(SceUtilitySavedataParam));
    pParam->base.size = sizeof(SceUtilitySavedataParam);
    pParam->base.message_lang = GetMessageLang();
    pParam->base.ctrl_assign = GetAssign();
    pParam->base.main_thread_priority = 17;
    pParam->base.sub_thread_priority = 19;
    pParam->base.font_thread_priority = 18;
    pParam->base.sound_thread_priority = 16;
    set_savedata_param(type, pParam);
    ret = sceUtilitySavedataInitStart(pParam);
}

static void OnPush_SaveData_Normal(int selection)
{
    unsigned int type[3] = {2, 3, 7};

    SaveDataPushEventTmplate("OnPush_SaveData_Normal", type[selection], &savedata_param);
}

static void OnCancel_SaveData_Normal(int selection)
{
    Menu_WriteLine("OnCancel_SaveData", 0x00ffffff);
    CreateMenu_Root();
}
