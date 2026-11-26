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
struct _anon1 { /* size 0x244 */
    SceUtilityParamBase base;
    int result;
    int type;
    unsigned int errorNum;
    char msgString[512];
    int optionType;
    int buttonResult;
};
typedef struct _anon1 SceUtilityMsgDialogParam;

extern char *sampleMsgDialogString;
extern SceUtilityMsgDialogParam msgdialog_param;
extern int sample_type;

int utility_update_msgdialog(void);
void OnPush_MsgDialog(int selection);
static void CreateMenu_MsgDialog();
static void OnCancel_MsgDialog(int selection);
static void OnPush_MsgDialogNumber(int selection);
static void OnPush_MsgDialogString(int selection);
static void OnPush_MsgDialogNormal(int selection);
static void OnPush_MsgDialogNormal_YesNo_Yes(int selection);
static void OnPush_MsgDialogNormal_YesNo_No(int selection);
static void OnPush_MsgDialogError(int selection);
static void OnPush_MsgDialogError_YesNo_Yes(int selection);
static void OnPush_MsgDialogError_YesNo_No(int selection);
void startMsgDialog(void);


INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/msgdialog", D_00016890);

void *memset(void *s, int c, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *, int, unsigned int);
void *memcpy(void *, const void *, unsigned int);
int GetMessageLang(void);
int GetAssign(void);
int sceUtilityMsgDialogInitStart(SceUtilityMsgDialogParam *);
int sceUtilityMsgDialogGetStatus(void);
int sceUtilityMsgDialogUpdate(int);
int sceUtilityMsgDialogShutdownStart(void);
void Menu_UnlockInput(void);
void Menu_LockInput(void);
void Menu_Show(void);
void Menu_Hide(void);
void Menu_ClearItems(void);
void Menu_AppendItem(const char *name, void (*callback)(int));
void Menu_SetCancelCallback(void (*callback)(int));
void Menu_WriteLine(const char *line, int color);
void CreateMenu_Root(void);
int utility_update_msgdialog(void)
{
    int ret = 0;
    int status;

    status = sceUtilityMsgDialogGetStatus();
    switch (status) {
    case 1:
        break;
    case 2:
        Menu_Hide();
        ret = sceUtilityMsgDialogUpdate(1);
        break;
    case 0:
        Menu_UnlockInput();
        Menu_Show();
        sample_type = 0;
        break;
    case 3:
        ret = sceUtilityMsgDialogShutdownStart();
        break;
    case 4:
        break;
    }
    return ret;
}

void OnPush_MsgDialog(int selection)
{
    Menu_WriteLine("OnPush_MsgDialog", 0x00ffffff);
    CreateMenu_MsgDialog();
}

static void CreateMenu_MsgDialog(void)
{
    Menu_ClearItems();
    Menu_AppendItem("0 : MsgDialog Number", OnPush_MsgDialogNumber);
    Menu_AppendItem("1 : MsgDialog String", OnPush_MsgDialogString);
    Menu_SetCancelCallback(OnCancel_MsgDialog);
}

static void OnCancel_MsgDialog(int selection)
{
    Menu_WriteLine("OnCancel_MsgDialog", 0x00ffffff);
    CreateMenu_Root();
}

static void OnPush_MsgDialogNumber(int selection)
{
    int ret;

    Menu_WriteLine("OnPush_MsgDialogNumber", 0x00ffffff);
    Menu_LockInput();
    sample_type = 4;
    memset(&msgdialog_param, 0, sizeof(msgdialog_param));
    msgdialog_param.base.size = sizeof(msgdialog_param);
    msgdialog_param.base.message_lang = GetMessageLang();
    msgdialog_param.base.ctrl_assign = GetAssign();
    msgdialog_param.base.main_thread_priority = 17;
    msgdialog_param.base.sub_thread_priority = 19;
    msgdialog_param.base.font_thread_priority = 18;
    msgdialog_param.base.sound_thread_priority = 16;
    msgdialog_param.type = 0;
    msgdialog_param.errorNum = 0x80110384;
    ret = sceUtilityMsgDialogInitStart(&msgdialog_param);
}

void OnPush_MsgDialogString(int selection) {
    Menu_ClearItems();
    Menu_AppendItem("0 : DialogType Normal", OnPush_MsgDialogNormal);
    Menu_AppendItem("1 : DialogType Normal_YesNo_Default_Yes", OnPush_MsgDialogNormal_YesNo_Yes);
    Menu_AppendItem("2 : DialogType Normal_YesNo_Default_No", OnPush_MsgDialogNormal_YesNo_No);
    Menu_AppendItem("3 : DialogType Error", OnPush_MsgDialogError);
    Menu_AppendItem("4 : DialogType Error_YesNo_Default_Yes", OnPush_MsgDialogError_YesNo_Yes);
    Menu_AppendItem("5 : DialogType Error_YesNo_Default_No", OnPush_MsgDialogError_YesNo_No);
    Menu_SetCancelCallback(OnCancel_MsgDialog);
}

static void OnPush_MsgDialogNormal(int selection)
{
    memset(&msgdialog_param, 0, sizeof(msgdialog_param));
    msgdialog_param.optionType = 0x001;
    startMsgDialog();
}

static void OnPush_MsgDialogNormal_YesNo_Yes(int selection)
{
    memset(&msgdialog_param, 0, sizeof(msgdialog_param));
    msgdialog_param.optionType = 0x011;
    startMsgDialog();
}

static void OnPush_MsgDialogNormal_YesNo_No(int selection)
{
    memset(&msgdialog_param, 0, sizeof(msgdialog_param));
    msgdialog_param.optionType = 0x111;
    startMsgDialog();
}

static void OnPush_MsgDialogError(int selection)
{
    memset(&msgdialog_param, 0, sizeof(msgdialog_param));
    msgdialog_param.optionType = 0x000;
    startMsgDialog();
}

static void OnPush_MsgDialogError_YesNo_Yes(int selection)
{
    memset(&msgdialog_param, 0, sizeof(msgdialog_param));
    msgdialog_param.optionType = 0x010;
    startMsgDialog();
}

static void OnPush_MsgDialogError_YesNo_No(int selection)
{
    memset(&msgdialog_param, 0, sizeof(msgdialog_param));
    msgdialog_param.optionType = 0x110;
    startMsgDialog();
}

void startMsgDialog(void)
{
    int ret;

    Menu_WriteLine("OnPush_MsgDialogString", 0x00ffffff);
    Menu_LockInput();
    sample_type = 4;
    msgdialog_param.base.size = sizeof(msgdialog_param);
    msgdialog_param.base.message_lang = GetMessageLang();
    msgdialog_param.base.ctrl_assign = GetAssign();
    msgdialog_param.base.main_thread_priority = 17;
    msgdialog_param.base.sub_thread_priority = 19;
    msgdialog_param.base.font_thread_priority = 18;
    msgdialog_param.base.sound_thread_priority = 16;
    msgdialog_param.type = 1;
    memcpy(msgdialog_param.msgString, sampleMsgDialogString, sizeof(msgdialog_param.msgString));
    ret = sceUtilityMsgDialogInitStart(&msgdialog_param);
}
