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

#define OnPush_LaunchHtmlViewer OnPush_LaunchHtmlViewer_B64
extern SceUID fpl_F5528;
#define fpl fpl_F5528
extern SceUtilityHtmlViewerParam htmlviewer_param_F4958;
#define htmlviewer_param htmlviewer_param_F4958
#define SCE_KERNEL_USER_HIGHEST_PRIORITY 0x11

int sceIoOpen(const char *, int, int);
int sceIoRead(int, void *, unsigned int);
int sceIoClose(int);
void *sceGeEdramGetAddr(void);
int sceDisplaySetFrameBuf(void *, int, int, int);
int sceKernelDcacheWritebackRange(const void *, unsigned int);
int sceDisplayWaitVblankStart(void);
int sceDisplaySetHoldMode(int);
void *memset(void *, int, unsigned int);
void *memcpy(void *, const void *, unsigned int);
static void OnPush_OSK(int selection);
static int ExitFunction(int count, int arg_impose, void *arg_self);
static int PowerCallback(int count, int arg, void *common);
char *strcpy(char *, const char *);
unsigned int strlen(const char *);
int GetMessageLang(void);
int GetAssign(void);
void Menu_ClearItems(void);
void Menu_AppendItem(const char *name, void (*callback)(int));
void Menu_WriteLine(const char *line, int color);
void Menu_PrintF(int color, const char *fmt, ...);
void Menu_LockInput(void);
void Menu_Hide(void);
void Menu_Init(void);
void Menu_Shutdown(void);
void OnPush_SaveData(int);
void OnPush_Netconf_Apnet(int);
void OnPush_Netconf_Adhoc(int);
void OnPush_MsgDialog(int);
void OnPush_HtmlViewer(int);
void OnPush_ChangeSetting(int);
int sceUtilityOskInitStart(SceUtilityOskParam *);
int sceUtilityMsgDialogGetStatus(void);
int sceUtilityMsgDialogUpdate(int);
int sceUtilityMsgDialogShutdownStart(void);
int sceUtilityMsgDialogInitStart(SceUtilityMsgDialogParam *);
int sceKernelCheckCallback(void);
void draw_frame(void);
void vsync_frame(void);
void init_all(void);
void term_all(void);
int init_net(void);
int init_apnet(void);
int init_http(void);
SceUID sceKernelCreateFpl(const char *, int, unsigned int, unsigned int, unsigned int, void *);
int sceKernelAllocateFpl(SceUID, void **, unsigned int *);
int sceUtilityHtmlViewerInitStart(SceUtilityHtmlViewerParam *);
int sceUtilityHtmlViewerGetStatus(void);
int sceUtilityHtmlViewerUpdate(int);
int sceUtilityHtmlViewerShutdownStart(void);
int LoadRequiredModules(void);
int sceKernelExitDeleteThread(int);
SceUID sceKernelCreateCallback(const char *, int (*)(int, int, void *), void *);
int scePowerRegisterCallback(int, SceUID);
int sceKernelRegisterExitCallback(SceUID);
int sceKernelDeleteCallback(SceUID);
void at3end(void);
SceUID sceKernelCreateThread(const char *, int (*)(SceSize, void *), int, int, unsigned int, void *);
int sceKernelStartThread(SceUID, SceSize, void *);
int sceKernelWaitThreadEnd(SceUID, unsigned int *);
int sceKernelDeleteThread(SceUID);
int sceKernelLoadExec(const char *, SceKernelLoadExecParam *);

/* SDK functions (tools/sdk_protos.h) */
void sceKernelExitGame(void);
int printf(const char *fmt, ...);
int puts(const char *s);


INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B398);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B3D4);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/main", D_0001B3FC);

static int fileRead(const char *fileName, void *readBuff, int size)
{
    SceUID fd;
    int ret;

    fd = sceIoOpen(fileName, 1, 0);
    if (fd < 0) {
        printf("*** ERROR: sceIoOpen(0x%08X)\n", fd);
        return -1;
    }
    ret = sceIoRead(fd, readBuff, size);
    if (ret < 0) {
        printf("*** ERROR: sceIoRead(0x%08X)\n", ret);
        return -1;
    }
    sceIoClose(fd);
    return 0;
}

static SceInt32 setHoldDisplay(const void *p_disp)
{
    void *vram_top;

    vram_top = sceGeEdramGetAddr();
    sceDisplaySetFrameBuf(vram_top, 512, 3, 1);
    memcpy(vram_top, p_disp, 512 * 272 * 4);
    sceKernelDcacheWritebackRange(vram_top, 512 * 272 * 4);
    sceDisplayWaitVblankStart();
    sceDisplaySetHoldMode(1);
    return 0;
}

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

void CreateMenu_Root(void)
{
    Menu_ClearItems();
    Menu_AppendItem("osk", OnPush_OSK);
    Menu_AppendItem("savedata >", OnPush_SaveData);
    Menu_AppendItem("netconf apnet >", OnPush_Netconf_Apnet);
    Menu_AppendItem("netconf adhoc >", OnPush_Netconf_Adhoc);
    Menu_AppendItem("msgdialog >", OnPush_MsgDialog);
    Menu_AppendItem("htmlviewer >", OnPush_HtmlViewer);
    Menu_AppendItem("change setting >", OnPush_ChangeSetting);
}

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

static void DialogUpdate()
{
    int ret;
    int status;

    status = sceUtilityMsgDialogGetStatus();
    switch (status) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        sceUtilityMsgDialogUpdate(2);
        break;
    case 3:
        ret = sceUtilityMsgDialogShutdownStart();
        break;
    case 4:
        break;
    }
}

static void MessageDialog()
{
    int i;
    char message[512] = "アクセスポイントから切断されました\xe3\x80";
    SceUtilityMsgDialogParam param;

    memset(&param, 0, sizeof(param));
    param.base.size = sizeof(param);
    param.base.ctrl_assign = 0;
    param.base.main_thread_priority = 17;
    param.base.sub_thread_priority = 19;
    param.base.font_thread_priority = 18;
    param.base.sound_thread_priority = 16;
    param.type = 1;
    param.optionType = 1;
    memcpy(param.msgString, message, sizeof(message));
    sceUtilityMsgDialogInitStart(&param);
    for (i = 0; i < 180; i++) {
        int status;
        draw_frame();
        DialogUpdate();
        sceKernelCheckCallback();
        vsync_frame();
        status = sceUtilityMsgDialogGetStatus();
        if (status == 0) break;
    }
}

static void OnPush_LaunchHtmlViewer_B64(int selection)
{
    SceSize size;
    int ret;

    Menu_LockInput();
    init_net();
    init_apnet();
    init_http();
    fpl = sceKernelCreateFpl("HtmlViewer_Heap", 2, 0, htmlviewer_param.heap_size, 1, 0);
    if (fpl <= 0) {
        Menu_PrintF(0x00ffffff, "sceKernelCreateFpl failed - 0x%08X\n", fpl);
        return;
    }
    sample_type = 5;
    htmlviewer_param.base.message_lang = GetMessageLang();
    htmlviewer_param.base.ctrl_assign = GetAssign();
    ret = sceKernelAllocateFpl(fpl, &htmlviewer_param.heap_addr, 0);
    if (ret != 0) {
        Menu_PrintF(0x00ffffff, "sceKernelAllocateFpl failed - 0x%08X\n", ret);
        return;
    }
    ret = sceUtilityHtmlViewerInitStart(&htmlviewer_param);
    if (ret != 0) {
        Menu_PrintF(0x00ffffff, "sceUtilityHtmlViewerInitStart - 0x%08X\n", ret);
        return;
    }
}

static int utility_update_htmlviewer2(void)
{
    int ret = 0;
    int status;

    status = sceUtilityHtmlViewerGetStatus();
    switch (status) {
    case 1:
        break;
    case 2:
        Menu_Hide();
        ret = sceUtilityHtmlViewerUpdate(1);
        if (ret != 0) {
            printf("sceUtilityHtmlViewerUpdate failed - 0x%08X\n", ret);
        }
        break;
    case 3:
        ret = sceUtilityHtmlViewerShutdownStart();
        if (ret != 0) {
            printf("sceUtilityHtmlViewerShutdownStart failed - 0x%08X\n", ret);
        }
        break;
    case 0:
        Menu_PrintF(0x00ffffff, "HtmlViewer Result - 0x%08X\n", htmlviewer_param.base.result);
        break;
    case 4:
        break;
    }
    return ret;
}

static int sub_thread(SceSize argSize, void *argBlock)
{
    int ret;
    SceUID cbidPower;
    int stat;
    SceUID uid;

    ret = LoadRequiredModules();
    if (ret < 0) {
        sceKernelExitDeleteThread(1);
    }
    cbidPower = sceKernelCreateCallback("OnPower", PowerCallback, NULL);
    scePowerRegisterCallback(-1, cbidPower);
    init_all();
    Menu_Init();
    CreateMenu_Root();
    uid = sceKernelCreateCallback("exit", ExitFunction, NULL);
    sceKernelRegisterExitCallback(uid);
    OnPush_LaunchHtmlViewer(0);
    do {
        if (g_MessageStart == 1) {
            g_MessageStart = 0;
        }
        draw_frame();
        utility_update_htmlviewer2();
        sceKernelCheckCallback();
        vsync_frame();
        stat = sceUtilityHtmlViewerGetStatus();
    } while (stat != 0);
    sceKernelDeleteCallback(cbidPower);
    printf("result:%d\n", htmlviewer_param.base.result);
    at3end();
    term_all();
    Menu_Shutdown();
    sceKernelExitDeleteThread(0);
    return 0;
}

int main(int argc, char **argv)
{
    int ret;
    int i;
    char back_prx_path[128] = "";

    puts("argument !!!");
    for (i = 0; i < argc; i++) {
        puts(argv[i]);
    }
    strcpy(back_prx_path, argv[0]);

    thread_id = sceKernelCreateThread("Utility Test", sub_thread, SCE_KERNEL_USER_HIGHEST_PRIORITY, 64 * 1024, 0, NULL);
    if (thread_id <= 0) {
        printf("can't create thread 0x%x\n", thread_id);
        return 1;
    }
    printf("thread created 0x%x\n", thread_id);
    ret = sceKernelStartThread(thread_id, 0, 0);
    if (ret) {
        printf("can't start thread 0x%x\n", ret);
        sceKernelDeleteThread(thread_id);
        return 1;
    }
    puts("sub_thread started");
    sceKernelWaitThreadEnd(thread_id, 0);
    {
        SceKernelLoadExecParam param;
        char v[128] = "RETURN\0\0";
        SceSize size;

        size = strlen(v) + 1;
        printf("loadExec (%s)\n", back_prx_path);
        ret = fileRead("disc0:/PSP_GAME/USRDIR/basic/nowloading.dat", loadExecDispBuff, 512 * 272 * 4);
        if (ret < 0) {
            printf("*** ERROR: fileRead(0x%08x)\n", ret);
        }
        setHoldDisplay(loadExecDispBuff);
        param.size = sizeof(param);
        param.args = size;
        param.argp = v;
        param.key = NULL;
        sceKernelLoadExec(back_prx_path, &param);
    }
    return 0;
}
