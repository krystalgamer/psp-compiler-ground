#include "common.h"

/* declarations recovered from DWARF */


extern int g_lang;
extern int g_assign;

void DrawSetting(void);
void OnPush_ChangeSetting(int selection);
static void OnCancel_ChangeSetting(int selection);
static void OnPush_Japanese(int selection);
static void OnPush_English(int selection);
static void OnPush_French(int selection);
static void OnPush_Spanish(int selection);
static void OnPush_German(int selection);
static void OnPush_Italian(int selection);
static void OnPush_Dutch(int selection);
static void OnPush_Portuguese(int selection);
static void OnPush_Russian(int selection);
static void OnPush_Hangul(int selection);
static void OnPush_ChangeLang(int selection);
int GetMessageLang(void);
void OnPush_Circle(int selection);
void OnPush_Cross(int selection);
static void OnPush_ChangeAssign(int selection);
int GetAssign(void);

int sprintf(char *, const char *, ...);
int sceGuDebugPrint(int, int, unsigned int, const char *);
int sceImposeSetLanguageMode(int, int);
void Menu_ClearItems(void);
void Menu_AppendItem(const char *name, void (*callback)(int));
void Menu_SetCancelCallback(void (*callback)(int));
void Menu_WriteLine(const char *line, int color);
void CreateMenu_Root(void);

void DrawSetting(void)
{
    char msg[256];
    const char *p_lang;
    const char *p_assign;

    p_lang = "error";
    switch (g_lang) {
    case 0: p_lang = "Japan"; break;
    case 1: p_lang = "English"; break;
    case 2: p_lang = "French"; break;
    case 3: p_lang = "Spanish"; break;
    case 4: p_lang = "German"; break;
    case 5: p_lang = "Italian"; break;
    case 6: p_lang = "Dutch"; break;
    case 7: p_lang = "Portuguess"; break;
    case 8: p_lang = "Russian"; break;
    case 9: p_lang = "Hangul"; break;
    case 10: p_lang = "Chinese(T)"; break;
    case 11: p_lang = "Chinese(S)"; break;
    }
    p_assign = "circle";
    if (g_assign != 0) p_assign = "cross";
    sprintf(msg, "lang[%s] assign[%s]", p_lang, p_assign);
    sceGuDebugPrint(0, 259, 0x00ffffff, msg);
}

void OnPush_ChangeSetting(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("change lang >", OnPush_ChangeLang);
    Menu_AppendItem("change assing >", OnPush_ChangeAssign);
    Menu_SetCancelCallback(OnCancel_ChangeSetting);
}

static void OnCancel_ChangeSetting(int selection)
{
    Menu_WriteLine("OnCancel_SaveData", 0x00ffffff);
    CreateMenu_Root();
}

static void OnPush_Japanese(int selection)
{
    g_lang = selection;
    sceImposeSetLanguageMode(g_lang, g_assign);
    Menu_WriteLine("OnPush_Japanese", 0x00ffffff);
}

static void OnPush_English(int selection)
{
    g_lang = selection;
    sceImposeSetLanguageMode(g_lang, g_assign);
    Menu_WriteLine("OnPush_English", 0x00ffffff);
}

static void OnPush_French(int selection)
{
    g_lang = selection;
    sceImposeSetLanguageMode(g_lang, g_assign);
    Menu_WriteLine("OnPush_French", 0x00ffffff);
}

static void OnPush_Spanish(int selection)
{
    g_lang = selection;
    sceImposeSetLanguageMode(g_lang, g_assign);
    Menu_WriteLine("OnPush_Spanish", 0x00ffffff);
}

static void OnPush_German(int selection)
{
    g_lang = selection;
    sceImposeSetLanguageMode(g_lang, g_assign);
    Menu_WriteLine("OnPush_German", 0x00ffffff);
}

static void OnPush_Italian(int selection)
{
    g_lang = selection;
    sceImposeSetLanguageMode(g_lang, g_assign);
    Menu_WriteLine("OnPush_Italian", 0x00ffffff);
}

static void OnPush_Dutch(int selection)
{
    g_lang = selection;
    sceImposeSetLanguageMode(g_lang, g_assign);
    Menu_WriteLine("OnPush_Dutch", 0x00ffffff);
}

static void OnPush_Portuguese(int selection)
{
    g_lang = selection;
    sceImposeSetLanguageMode(g_lang, g_assign);
    Menu_WriteLine("OnPush_Portuguese", 0x00ffffff);
}

static void OnPush_Russian(int selection)
{
    g_lang = selection;
    sceImposeSetLanguageMode(g_lang, g_assign);
    Menu_WriteLine("OnPush_Russian", 0x00ffffff);
}

static void OnPush_Hangul(int selection)
{
    g_lang = selection;
    sceImposeSetLanguageMode(g_lang, g_assign);
    Menu_WriteLine("OnPush_Hangul", 0x00ffffff);
}

static void OnPush_ChangeLang(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("japanese", OnPush_Japanese);
    Menu_AppendItem("english", OnPush_English);
    Menu_AppendItem("french", OnPush_French);
    Menu_AppendItem("spanish", OnPush_Spanish);
    Menu_AppendItem("german", OnPush_German);
    Menu_AppendItem("italian", OnPush_Italian);
    Menu_AppendItem("dutch", OnPush_Dutch);
    Menu_AppendItem("portuguese", OnPush_Portuguese);
    Menu_AppendItem("russian", OnPush_Russian);
    Menu_AppendItem("hungul", OnPush_Hangul);
    Menu_SetCancelCallback(OnPush_ChangeSetting);
}

int GetMessageLang(void)
{
    return g_lang;
}

void OnPush_Circle(int selection)
{
    g_assign = 0;
    sceImposeSetLanguageMode(g_lang, g_assign);
}

void OnPush_Cross(int selection)
{
    g_assign = 1;
    sceImposeSetLanguageMode(g_lang, g_assign);
}

static void OnPush_ChangeAssign(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("circle is enter", OnPush_Circle);
    Menu_AppendItem("cross  is enter", OnPush_Cross);
    Menu_SetCancelCallback(OnPush_ChangeSetting);
}

int GetAssign(void)
{
    return g_assign;
}
