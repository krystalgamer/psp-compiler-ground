#include "common.h"

/* declarations recovered from DWARF */
typedef int SceUID;
typedef int SceInt32;
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
struct _anon7;
struct _anon7 { /* size 0x244 */
    SceUtilityParamBase base;
    int result;
    int type;
    unsigned int errorNum;
    char msgString[512];
    int optionType;
    int buttonResult;
};
typedef struct _anon7 SceUtilityMsgDialogParam;
typedef unsigned int SceSize;
typedef struct SceKernelLoadExecParam SceKernelLoadExecParam;
struct SceKernelLoadExecParam;
struct SceKernelLoadExecParam { /* size 0x10 */
    SceSize size;
    SceSize args;
    const void *argp;
    const char *key;
};
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
struct _anon8;
struct _anon8 { /* size 0x10 */
    const char *url;
    const char *caption;
    int reserved1;
    int reserved2;
};
typedef struct _anon8 SceUtilityHtmlViewerBookmark;
struct _anon9;
struct _anon10;
struct _anon10 { /* size 0x8 */
    const char *dirname;
    const char *filename;
};
typedef struct _anon10 SceUtilityHtmlViewerFileParam;
struct _anon11;
struct _anon11 { /* size 0x14 */
    unsigned int cookie_mode;
    unsigned int cache_size;
    const char *home_url;
    unsigned int char_size;
    unsigned int disp_mode;
};
typedef struct _anon11 SceUtilityHtmlViewerConfig;
struct _anon9 { /* size 0x78 */
    SceUtilityParamBase base;
    void *heap_addr;
    unsigned int heap_size;
    unsigned int num_bookmark;
    SceUtilityHtmlViewerBookmark *bookmark;
    const char *initial_url;
    unsigned int num_tab;
    unsigned int ui_level;
    unsigned int flag;
    SceUtilityHtmlViewerFileParam download;
    SceUtilityHtmlViewerFileParam upload;
    SceUtilityHtmlViewerConfig temp_config;
    unsigned int auto_disconnect;
};
typedef struct _anon9 SceUtilityHtmlViewerParam;

extern int sample_type;
extern int _gp[];
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern SceUID thread_id;
extern SceUtilityOskParam osk_param;
extern int g_IsSuspending;
extern int g_MessageStart;
extern SceUtilityHtmlViewerBookmark favorites[1];
extern SceUtilityHtmlViewerParam htmlviewer_param;
extern SceUID fpl;
extern SceUtilityOskInputFieldInfo oskInputFieldInfo[4];
extern SceWChar16 aIinitString[4][30];
extern int aInputCharTypeList[4];
extern SceWChar16 *aInitStringList[4];
extern SceWChar16 aMessageString[4][17];
extern SceWChar16 *aMessageStringList[4];
extern SceWChar16 aResultString[4][32];
extern SceWChar16 *aResultStringList[4];
extern char loadExecDispBuff[557056];

static int fileRead(const char *fileName, void *readBuff, int size);
static SceInt32 setHoldDisplay(const void *p_disp);
static void setOskUtilityPraram(unsigned int numInputFields, SceWChar16 **messageString, SceWChar16 **initString, SceWChar16 **resultTextBuffer, unsigned int bufferSize, SceUtilityOskInputFieldInfo *inputField, SceUtilityOskParam *pParam);
void CreateMenu_Root(void);
static void DialogUpdate();
static void MessageDialog();
static void OnPush_LaunchHtmlViewer(int selection);
static int utility_update_htmlviewer2(void);
static int sub_thread(SceSize argSize, void *argBlock);
int main(int argc, char **argv);

/* SDK functions (tools/sdk_protos.h) */
void sceKernelExitGame(void);
int printf(const char *fmt, ...);
int puts(const char *s);


INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B398);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B3D4);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B3FC);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", fileRead);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", setHoldDisplay);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", setOskUtilityPraram);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B480);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", CreateMenu_Root);

void OnPush_OSK(int selection) {
    int temp_v0;

    Menu_WriteLine("OnPush_OSK", 0xFFFFFF);
    Menu_LockInput();
    sample_type = 2;
    setOskUtilityPraram(4U, aMessageStringList, aInitStringList, aResultStringList, 0x20U, oskInputFieldInfo, &osk_param);
    temp_v0 = sceUtilityOskInitStart(&osk_param);
    if (temp_v0 == 0) {

    } else {
        printf("sceUtilityOskInitStart failed - %d\n", temp_v0);
    }
}

int ExitFunction(int count, int arg_impose, void *arg_self) {
    sceKernelExitGame();
    return 0;
}

int PowerCallback(int count, int arg, void *common) {
    if (!(arg & 0x10000)) {

    } else {
        g_IsSuspending = 1;
        puts("suspending on");
    }
    if (g_IsSuspending != 0) {
        if (arg & 0x40000) {
            g_MessageStart = 1;
            g_IsSuspending = 0;
            puts("suspending off");
        }
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", DialogUpdate);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", MessageDialog);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B544);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", OnPush_LaunchHtmlViewer_B64);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", utility_update_htmlviewer2);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B7F4);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B800);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B810);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B844);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", sub_thread);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B874);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", main);
