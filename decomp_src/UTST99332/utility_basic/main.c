#include "common.h"

/* declarations recovered from DWARF */
typedef short unsigned int SceWChar16;
struct _anon1;
enum _anon2 {
    SCE_UTILITY_OSK_BOOL_VALUE_FALSE = 0,
    SCE_UTILITY_OSK_BOOL_VALUE_TRUE = 1,
};
typedef enum _anon2 SceUtilityOskBoolValue;
enum _anon3 {
    SCE_UTILITY_OSK_INPUT_FIELD_RESULT_UNEDITED = 0,
    SCE_UTILITY_OSK_INPUT_FIELD_RESULT_CANCELED = 1,
    SCE_UTILITY_OSK_INPUT_FIELD_RESULT_EDITED = 2,
};
typedef enum _anon3 SceUtilityOskInputFieldResult;
struct _anon1 { /* size 0x34 */
    unsigned int input_method_type;
    unsigned int input_method_attributes;
    unsigned int writing_language_type;
    SceUtilityOskBoolValue hide_mode;
    int input_character_type;
    int num_lines;
    int kinsoku;
    SceWChar16 *message;
    SceWChar16 *init_text;
    int result_text_buffer_size;
    SceWChar16 *result_text_buffer;
    SceUtilityOskInputFieldResult result;
    int limit_length;
};
typedef struct _anon1 SceUtilityOskInputFieldInfo;
struct _anon4;
struct _anon5;
struct _anon5 { /* size 0x30 */
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
typedef struct _anon5 SceUtilityParamBase;
enum _anon6 {
    SCE_UTILITY_OSK_LOCAL_STATUS_NONE = 0,
    SCE_UTILITY_OSK_LOCAL_STATUS_INITIALIZING = 1,
    SCE_UTILITY_OSK_LOCAL_STATUS_INITIALIZED = 2,
    SCE_UTILITY_OSK_LOCAL_STATUS_OPENED = 3,
    SCE_UTILITY_OSK_LOCAL_STATUS_CLOSING = 4,
    SCE_UTILITY_OSK_LOCAL_STATUS_CLOSED = 5,
};
typedef enum _anon6 SceUtilityOskLocalStatus;
struct _anon4 { /* size 0x40 */
    SceUtilityParamBase base;
    unsigned int num_input_fields;
    SceUtilityOskInputFieldInfo *input_field_info;
    SceUtilityOskLocalStatus local_status;
    int error_code;
};
typedef struct _anon4 SceUtilityOskParam;
typedef unsigned int size_t;
typedef int SceUID;
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
};
struct _anon7;
struct _anon8;
struct _anon8 { /* size 0x504 */
    char title[128];
    char savedataTitle[128];
    char detail[1024];
    unsigned char parentalLev;
    unsigned char reserved[3];
};
typedef struct _anon8 SceUtilitySDSystemFileParam;
struct _anon9;
struct _anon9 { /* size 0x10 */
    void *pDataBuf;
    unsigned int dataBufSize;
    unsigned int dataFileSize;
    char *pFilePath;
};
typedef struct _anon9 SceUtilitySDExtFile;
struct _anon10;
struct _anon10 { /* size 0x14 */
    SceUtilitySDExtFile icon0;
    char *pTitle;
};
typedef struct _anon10 SceUtilitySavedataListSaveNewData;
struct _anon11;
struct _anon11 { /* size 0x14 */
    unsigned int msClusterSizeByte;
    unsigned int msFreeCluster;
    unsigned int msFreeSizeKB;
    char msFreeSizeStr[8];
};
typedef struct _anon11 SceUtilitySavedataMsFreeSize;
struct _anon12;
struct _anon12 { /* size 0x40 */
    char titleId[13];
    char reserved[3];
    char userId[20];
    unsigned int cluster;
    unsigned int sizeKB;
    char sizeStr[8];
    unsigned int size32KB;
    char size32Str[8];
};
typedef struct _anon12 SceUtilitySavedataMsDataSize;
struct _anon13;
struct _anon13 { /* size 0x1c */
    unsigned int cluster;
    unsigned int sizeKB;
    char sizeStr[8];
    unsigned int size32KB;
    char size32Str[8];
};
typedef struct _anon13 SceUtilitySavedataUtilityDataSize;
struct _anon7 { /* size 0x5dc */
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
typedef struct _anon7 SceUtilitySavedataParam;

extern int _gp[];
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern SceUID thread_id;
extern int loop;
extern int sample_type;
extern SceUtilitySavedataParam savedata_param;
extern SceUtilityOskParam osk_param;
extern SceUtilityOskInputFieldInfo oskInputFieldInfo[4];
extern SceWChar16 aIinitString[4][30];
extern int aInputCharTypeList[4];
extern SceWChar16 *aInitStringList[4];
extern SceWChar16 aMessageString[4][17];
extern SceWChar16 *aMessageStringList[4];
extern SceWChar16 aResultString[4][32];
extern SceWChar16 *aResultStringList[4];

static void setOskUtilityPraram(unsigned int numInputFields, SceWChar16 **messageString, SceWChar16 **initString, SceWChar16 **resultTextBuffer, unsigned int bufferSize, SceUtilityOskInputFieldInfo *inputField, SceUtilityOskParam *pParam);
static void dumpOskUtilityTextResult(unsigned int numInputFields, SceUtilityOskInputFieldInfo *inputField);
static int utility_update_osk(void);
static int utility_update_savedata(void);
static int utility_update(void);
void CreateMenu_Root();
static void CreateMenu_SaveData();
static void OnPush_OSK(int selection);
static void OnPush_SaveData(int selection);
static void OnPush_SaveData_0(int selection);
static void OnPush_SaveData_1(int selection);
static void OnPush_SaveData_2(int selection);
static void OnPush_SaveData_3(int selection);
static void OnPush_SaveData_4(int selection);
static void OnPush_SaveData_5(int selection);
static void OnPush_SaveData_6(int selection);
static void OnPush_SaveData_7(int selection);
static void OnPush_SaveData_8(int selection);
static void OnCancel_SaveData(int selection);
static void OnPush_Exit(int selection);
static int ExitFunction(int count, int arg_impose, void *arg_self);
static int sub_thread(size_t argSize, void *argBlock);
int main(int argc, char **argv);


void *memset(void *s, int c, unsigned int n);
static void setOskUtilityPraram(unsigned int numInputFields, SceWChar16 **messageString, SceWChar16 **initString, SceWChar16 **resultTextBuffer, unsigned int bufferSize, SceUtilityOskInputFieldInfo *inputField, SceUtilityOskParam *pParam)
{
    int i;

    memset(pParam, 0x00, sizeof(SceUtilityOskParam));
    pParam->base.size = sizeof(SceUtilityOskParam);
    pParam->base.message_lang = GetMessageLang();
    pParam->base.ctrl_assign = GetAssign();
    pParam->base.main_thread_priority = 17;
    pParam->base.sub_thread_priority = 19;
    pParam->base.font_thread_priority = 18;
    pParam->base.sound_thread_priority = 16;
    pParam->base.reserved1 = 0;
    pParam->base.reserved2 = 0;

    pParam->num_input_fields = numInputFields;
    pParam->input_field_info = inputField;

    memset(inputField, 0x00, sizeof(*inputField));

    for (i = 0; i < (int)numInputFields; i++) {
        inputField[i].input_method_type = 1;
        inputField[i].input_method_attributes = 0;
        inputField[i].writing_language_type = 0;
        inputField[i].hide_mode = SCE_UTILITY_OSK_BOOL_VALUE_FALSE;
        inputField[i].input_character_type = aInputCharTypeList[i];
        inputField[i].num_lines = 4;
        inputField[i].kinsoku = SCE_UTILITY_OSK_BOOL_VALUE_TRUE;

        inputField[i].message = messageString[i];
        inputField[i].init_text = initString[i];
        inputField[i].result_text_buffer_size = bufferSize;
        inputField[i].result_text_buffer = resultTextBuffer[i];
        inputField[i].result = SCE_UTILITY_OSK_INPUT_FIELD_RESULT_UNEDITED;
        inputField[i].limit_length = 0;
    }

    return;
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", dumpOskUtilityTextResult);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", utility_update_osk);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", utility_update_savedata);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", utility_update);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", CreateMenu_Root);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/main", D_000149B8);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", CreateMenu_SaveData);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_OSK);

void OnPush_SaveData(int selection)
{
    Menu_WriteLine("OnPush_SaveData", 0x00ffffff);
    CreateMenu_SaveData();
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_SaveData_0);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_SaveData_1);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_SaveData_2);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_SaveData_3);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_SaveData_4);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_SaveData_5);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_SaveData_6);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_SaveData_7);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_SaveData_8);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnCancel_SaveData);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", OnPush_Exit);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", ExitFunction_1068);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", sub_thread);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/main", main);
