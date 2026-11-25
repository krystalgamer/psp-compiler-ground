#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int SceSize;
struct _anon1;
struct _anon1 { /* size 0x10 */
    const char *url;
    const char *caption;
    int reserved1;
    int reserved2;
};
typedef struct _anon1 SceUtilityHtmlViewerBookmark;
struct _anon2;
struct _anon3;
struct _anon3 { /* size 0x30 */
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
typedef struct _anon3 SceUtilityParamBase;
struct _anon4;
struct _anon4 { /* size 0x8 */
    const char *dirname;
    const char *filename;
};
typedef struct _anon4 SceUtilityHtmlViewerFileParam;
struct _anon5;
struct _anon5 { /* size 0x14 */
    unsigned int cookie_mode;
    unsigned int cache_size;
    const char *home_url;
    unsigned int char_size;
    unsigned int disp_mode;
};
typedef struct _anon5 SceUtilityHtmlViewerConfig;
struct _anon2 { /* size 0x78 */
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
typedef struct _anon2 SceUtilityHtmlViewerParam;
typedef int SceUID;

extern int sample_type;
extern SceUtilityHtmlViewerBookmark favorites[1];
extern SceUtilityHtmlViewerParam htmlviewer_param_F4CB8;
#define htmlviewer_param htmlviewer_param_F4CB8
extern SceUID fpl_69F1A8;
#define fpl fpl_69F1A8
#define OnPush_LaunchHtmlViewer OnPush_LaunchHtmlViewer_3BB8

static void Cleanup(void);
int utility_update_htmlviewer(void);
static void OnPush_LaunchHtmlViewer(int selection);
static void OnPush_Select_HeapSize(int selection);
static void OnPush_Setup_HeapSize(int selection);
static void OnPush_Select_Bookmark(int selection);
static void OnPush_Setup_Bookmark(int selection);
static void OnPush_Select_InitialUrl(int selection);
static void OnPush_Setup_InitialUrl(int selection);
static void OnPush_Select_NumTab(int selection);
static void OnPush_Setup_NumTab(int selection);
static void OnPush_Select_UiLevel(int selection);
static void OnPush_Setup_UiLevel(int selection);
static void OnPush_Select_OpenNetstart(int selection);
static void OnPush_Setup_OpenNetstart(int selection);
static void OnPush_Select_StartCtrl(int selection);
static void OnPush_Setup_StartCtrl(int selection);
static void OnPush_Select_DownloadDir(int selection);
static void OnPush_Setup_DownloadDir(int selection);
static void OnPush_Select_DownloadFile(int selection);
static void OnPush_Setup_DownloadFile(int selection);
static void OnPush_Select_UploadDir(int selection);
static void OnPush_Setup_UploadDir(int selection);
static void OnPush_Select_UploadFile(int selection);
static void OnPush_Setup_UploadFile(int selection);
static void OnPush_Setup_UploadDownload(int selection);
static void OnPush_Select_CookieMode(int selection);
static void OnPush_Setup_CookieMode(int selection);
static void OnPush_Select_CacheSize(int selection);
static void OnPush_Setup_CacheSize(int selection);
static void OnPush_Select_HomeUrl(int selection);
static void OnPush_Setup_HomeUrl(int selection);
static void OnPush_Setup_TemporarySettings(int selection);
static void OnPush_Select_AutoDisconnect(int selection);
static void OnPush_Setup_AutoDisconnect(int selection);
static void OnCancel_HtmlViewer(int selection);
void OnPush_HtmlViewer(int selection);

int printf(const char *, ...);
int GetMessageLang(void);
int GetAssign(void);
int init_net(void);
int term_net(void);
int init_apnet(void);
int term_apnet(void);
int init_http(void);
int term_http(void);
SceUID sceKernelCreateFpl(const char *, int, unsigned int, unsigned int, unsigned int, void *);
int sceKernelAllocateFpl(SceUID, void **, unsigned int *);
int sceKernelFreeFpl(SceUID, void *);
int sceKernelDeleteFpl(SceUID);
int sceUtilityHtmlViewerInitStart(SceUtilityHtmlViewerParam *);
int sceUtilityHtmlViewerGetStatus(void);
int sceUtilityHtmlViewerUpdate(int);
int sceUtilityHtmlViewerShutdownStart(void);
void Menu_UnlockInput(void);
void Menu_LockInput(void);
void Menu_Show(void);
void Menu_Hide(void);
void Menu_ClearItems(void);
void Menu_AppendItem(const char *name, void (*callback)(int));
void Menu_SetCancelCallback(void (*callback)(int));
void Menu_WriteLine(const char *line, int color);
void Menu_PrintF(int color, const char *fmt, ...);
void CreateMenu_Root(void);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/htmlviewer", D_0001DBE8);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/htmlviewer", D_0001DC08);

static void Cleanup(void)
{
    Menu_UnlockInput();
    Menu_Show();
    sample_type = 0;
    if (htmlviewer_param.heap_addr != NULL) {
        sceKernelFreeFpl(fpl, htmlviewer_param.heap_addr);
        htmlviewer_param.heap_addr = NULL;
    }
    if (fpl > 0) {
        sceKernelDeleteFpl(fpl);
        fpl = 0;
    }
    term_http();
    term_apnet();
    term_net();
}

int utility_update_htmlviewer(void)
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
    case 0:
        Menu_PrintF(0x00ffffff, "HtmlViewer Result - 0x%08X\n", htmlviewer_param.base.result);
        Cleanup();
        break;
    case 3:
        ret = sceUtilityHtmlViewerShutdownStart();
        if (ret != 0) {
            printf("sceUtilityHtmlViewerShutdownStart failed - 0x%08X\n", ret);
        }
        break;
    case 4:
        break;
    }
    return ret;
}

static void OnPush_LaunchHtmlViewer_3BB8(int selection)
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
        Cleanup();
        return;
    }
    sample_type = 5;
    htmlviewer_param.base.message_lang = GetMessageLang();
    htmlviewer_param.base.ctrl_assign = GetAssign();
    ret = sceKernelAllocateFpl(fpl, &htmlviewer_param.heap_addr, 0);
    if (ret != 0) {
        Menu_PrintF(0x00ffffff, "sceKernelAllocateFpl failed - 0x%08X\n", ret);
        Cleanup();
        return;
    }
    ret = sceUtilityHtmlViewerInitStart(&htmlviewer_param);
    if (ret != 0) {
        Menu_PrintF(0x00ffffff, "sceUtilityHtmlViewerInitStart - 0x%08X\n", ret);
        Cleanup();
        return;
    }
}

static void OnPush_Select_HeapSize(int selection)
{
    htmlviewer_param.heap_size = (4 + selection * 2) * 1024 * 1024;
    OnPush_HtmlViewer(0);
}

static void OnPush_Setup_HeapSize(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("4MB", OnPush_Select_HeapSize);
    Menu_AppendItem("6MB", OnPush_Select_HeapSize);
    Menu_AppendItem("8MB", OnPush_Select_HeapSize);
    Menu_SetCancelCallback(OnPush_HtmlViewer);
}

static void OnPush_Select_Bookmark(int selection)
{
    htmlviewer_param.num_bookmark = selection;
    OnPush_HtmlViewer(0);
}

static void OnPush_Setup_Bookmark(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("none", OnPush_Select_Bookmark);
    Menu_AppendItem("PlayStation.jp/psp", OnPush_Select_Bookmark);
    Menu_SetCancelCallback(OnPush_HtmlViewer);
}

static void OnPush_Select_InitialUrl(int selection)
{
    switch (selection) {
    case 0:
        htmlviewer_param.initial_url = NULL;
        break;
    case 1:
        htmlviewer_param.initial_url = "http://www.jp.playstation.com/";
        break;
    }
    OnPush_HtmlViewer(0);
}

static void OnPush_Setup_InitialUrl(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("none", OnPush_Select_InitialUrl);
    Menu_AppendItem("Playstation.com", OnPush_Select_InitialUrl);
    Menu_SetCancelCallback(OnPush_HtmlViewer);
}

static void OnPush_Select_NumTab(int selection)
{
    htmlviewer_param.num_tab = selection + 1;
    OnPush_HtmlViewer(0);
}

static void OnPush_Setup_NumTab(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Num of Tab: 1", OnPush_Select_NumTab);
    Menu_AppendItem("Num of Tab: 2", OnPush_Select_NumTab);
    Menu_AppendItem("Num of Tab: 3", OnPush_Select_NumTab);
    Menu_SetCancelCallback(OnPush_HtmlViewer);
}

static void OnPush_Select_UiLevel(int selection)
{
    htmlviewer_param.ui_level = selection;
    OnPush_HtmlViewer(0);
}

static void OnPush_Setup_UiLevel(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("UI Level: Full", OnPush_Select_UiLevel);
    Menu_AppendItem("UI Level: Limited", OnPush_Select_UiLevel);
    Menu_AppendItem("UI Level: None", OnPush_Select_UiLevel);
    Menu_SetCancelCallback(OnPush_HtmlViewer);
}

static void OnPush_Select_OpenNetstart(int selection)
{
    switch (selection) {
    case 0:
        htmlviewer_param.flag &= ~1;
        break;
    case 1:
        htmlviewer_param.flag |= 1;
        break;
    }
    OnPush_HtmlViewer(0);
}

static void OnPush_Setup_OpenNetstart(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Open Netstart: No", OnPush_Select_OpenNetstart);
    Menu_AppendItem("Open Netstart: Yes", OnPush_Select_OpenNetstart);
    Menu_SetCancelCallback(OnPush_HtmlViewer);
}

static void OnPush_Select_StartCtrl(int selection)
{
    switch (selection) {
    case 0:
        htmlviewer_param.flag &= ~2;
        break;
    case 1:
        htmlviewer_param.flag |= 2;
        break;
    }
    OnPush_HtmlViewer(0);
}

static void OnPush_Setup_StartCtrl(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Start Control: Enable", OnPush_Select_StartCtrl);
    Menu_AppendItem("Start Control: Disable", OnPush_Select_StartCtrl);
    Menu_SetCancelCallback(OnPush_HtmlViewer);
}

static void OnPush_Select_DownloadDir(int selection)
{
    switch (selection) {
    case 0:
        htmlviewer_param.download.dirname = NULL;
        break;
    case 1:
        htmlviewer_param.download.dirname = "/PSP/COMMON";
        break;
    }
    OnPush_Setup_UploadDownload(0);
}

static void OnPush_Setup_DownloadDir(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Download Dir: None", OnPush_Select_DownloadDir);
    Menu_AppendItem("Download Dir: \"/PSP/COMMON\"", OnPush_Select_DownloadDir);
    Menu_SetCancelCallback(OnPush_Setup_UploadDownload);
}

static void OnPush_Select_DownloadFile(int selection)
{
    switch (selection) {
    case 0:
        htmlviewer_param.download.filename = NULL;
        break;
    case 1:
        htmlviewer_param.download.filename = "TEST.DAT";
        break;
    }
    OnPush_Setup_UploadDownload(0);
}

static void OnPush_Setup_DownloadFile(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Download File: None", OnPush_Select_DownloadFile);
    Menu_AppendItem("Download File: \"TEST.DAT\"", OnPush_Select_DownloadFile);
    Menu_SetCancelCallback(OnPush_Setup_UploadDownload);
}

static void OnPush_Select_UploadDir(int selection)
{
    switch (selection) {
    case 0:
        htmlviewer_param.upload.dirname = NULL;
        break;
    case 1:
        htmlviewer_param.upload.dirname = "/PSP/COMMON";
        break;
    }
    OnPush_Setup_UploadDownload(0);
}

static void OnPush_Setup_UploadDir(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Upload Dir: None", OnPush_Select_UploadDir);
    Menu_AppendItem("Upload Dir: \"/PSP/COMMON\"", OnPush_Select_UploadDir);
    Menu_SetCancelCallback(OnPush_Setup_UploadDownload);
}

static void OnPush_Select_UploadFile(int selection)
{
    switch (selection) {
    case 0:
        htmlviewer_param.upload.filename = NULL;
        break;
    case 1:
        htmlviewer_param.upload.filename = "TEST.DAT";
        break;
    }
    OnPush_Setup_UploadDownload(0);
}

static void OnPush_Setup_UploadFile(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Upload File: None", OnPush_Select_UploadFile);
    Menu_AppendItem("Upload File: \"TEST.DAT\"", OnPush_Select_UploadFile);
    Menu_SetCancelCallback(OnPush_Setup_UploadDownload);
}

static void OnPush_Setup_UploadDownload(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("setup: Download Dir", OnPush_Setup_DownloadDir);
    Menu_AppendItem("setup: Download File", OnPush_Setup_DownloadFile);
    Menu_AppendItem("setup: Upload   Dir", OnPush_Setup_UploadDir);
    Menu_AppendItem("setup: Upload   File", OnPush_Setup_UploadFile);
    Menu_SetCancelCallback(OnPush_HtmlViewer);
}

static void OnPush_Select_CookieMode(int selection)
{
    htmlviewer_param.temp_config.cookie_mode = selection;
    OnPush_Setup_TemporarySettings(0);
}

static void OnPush_Setup_CookieMode(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Cookie: Reject", OnPush_Select_CookieMode);
    Menu_AppendItem("Cookie: Accept", OnPush_Select_CookieMode);
    Menu_AppendItem("Cookie: Confirm", OnPush_Select_CookieMode);
    Menu_AppendItem("Cookie: Default", OnPush_Select_CookieMode);
    Menu_SetCancelCallback(OnPush_Setup_TemporarySettings);
}

static void OnPush_Select_CacheSize(int selection)
{
    htmlviewer_param.temp_config.cache_size = selection * 512;
    OnPush_Setup_TemporarySettings(0);
}

static void OnPush_Setup_CacheSize(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Cache Size: Default", OnPush_Select_CacheSize);
    Menu_AppendItem("Cache Size:   512KB", OnPush_Select_CacheSize);
    Menu_AppendItem("Cache Size:  1024KB", OnPush_Select_CacheSize);
    Menu_AppendItem("Cache Size:  1536KB", OnPush_Select_CacheSize);
    Menu_AppendItem("Cache Size:  2048KB", OnPush_Select_CacheSize);
    Menu_SetCancelCallback(OnPush_Setup_TemporarySettings);
}

static void OnPush_Select_HomeUrl(int selection)
{
    switch (selection) {
    case 0:
        htmlviewer_param.temp_config.home_url = NULL;
        break;
    case 1:
        htmlviewer_param.temp_config.home_url = "http://www.playstation-club.com/";
        break;
    }
    OnPush_Setup_TemporarySettings(0);
}

static void OnPush_Setup_HomeUrl(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Home URL: Default", OnPush_Select_HomeUrl);
    Menu_AppendItem("Home URL: Playstation Club", OnPush_Select_HomeUrl);
    Menu_SetCancelCallback(OnPush_Setup_TemporarySettings);
}

static void OnPush_Setup_TemporarySettings(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("setup: Cookie Mode", OnPush_Setup_CookieMode);
    Menu_AppendItem("setup: Cache Size", OnPush_Setup_CacheSize);
    Menu_AppendItem("setup: Home URL", OnPush_Setup_HomeUrl);
    Menu_SetCancelCallback(OnPush_HtmlViewer);
}

static void OnPush_Select_AutoDisconnect(int selection)
{
    htmlviewer_param.auto_disconnect = selection;
    OnPush_HtmlViewer(0);
}

static void OnPush_Setup_AutoDisconnect(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("Auto Disconnect: Enable", OnPush_Select_AutoDisconnect);
    Menu_AppendItem("Auto Disconnect: Disable", OnPush_Select_AutoDisconnect);
    Menu_AppendItem("Auto Disconnect: Confirm", OnPush_Select_AutoDisconnect);
    Menu_SetCancelCallback(OnPush_HtmlViewer);
}

static void OnCancel_HtmlViewer(int selection)
{
    CreateMenu_Root();
}

void OnPush_HtmlViewer(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("launch", OnPush_LaunchHtmlViewer);
    Menu_AppendItem("setup: Heap Size", OnPush_Setup_HeapSize);
    Menu_AppendItem("setup: Add Bookmark", OnPush_Setup_Bookmark);
    Menu_AppendItem("setup: Initial URL", OnPush_Setup_InitialUrl);
    Menu_AppendItem("setup: Num of Tab", OnPush_Setup_NumTab);
    Menu_AppendItem("setup: UI Level", OnPush_Setup_UiLevel);
    Menu_AppendItem("setup: Open Netstart", OnPush_Setup_OpenNetstart);
    Menu_AppendItem("setup: Start Control", OnPush_Setup_StartCtrl);
    Menu_AppendItem("setup: Upload/Download...", OnPush_Setup_UploadDownload);
    Menu_AppendItem("setup: Temp Settings...", OnPush_Setup_TemporarySettings);
    Menu_AppendItem("setup: Auto Disconnect", OnPush_Setup_AutoDisconnect);
    Menu_SetCancelCallback(OnCancel_HtmlViewer);
}
