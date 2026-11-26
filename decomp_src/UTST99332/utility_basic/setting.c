#include "common.h"

void Menu_WriteLine(const char *line, int color);

/* declarations recovered from DWARF */


extern int g_lang;
extern int g_assing;

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
static void OnPush_ChangeLang(int selection);
int GetMessageLang();
void OnPush_Circle(int selection);
void OnPush_Cross(int selection);
static void OnPush_ChangeAssign(int selection);
int GetAssign();


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

void OnPush_Japanese(int selection) {
    g_lang = selection;
    Menu_WriteLine("OnPush_Japanese", 0xFFFFFF);
}

void OnPush_English(int selection) {
    g_lang = selection;
    Menu_WriteLine("OnPush_English", 0xFFFFFF);
}

void OnPush_French(int selection) {
    g_lang = selection;
    Menu_WriteLine("OnPush_French", 0xFFFFFF);
}

void OnPush_Spanish(int selection) {
    g_lang = selection;
    Menu_WriteLine("OnPush_Spanish", 0xFFFFFF);
}

void OnPush_German(int selection) {
    g_lang = selection;
    Menu_WriteLine("OnPush_German", 0xFFFFFF);
}

void OnPush_Italian(int selection) {
    g_lang = selection;
    Menu_WriteLine("OnPush_Italian", 0xFFFFFF);
}

void OnPush_Dutch(int selection) {
    g_lang = selection;
    Menu_WriteLine("OnPush_Dutch", 0xFFFFFF);
}

void OnPush_Portuguese(int selection) {
    g_lang = selection;
    Menu_WriteLine("OnPush_Portuguese", 0xFFFFFF);
}

void OnPush_Russian(int selection) {
    g_lang = selection;
    Menu_WriteLine("OnPush_Russian", 0xFFFFFF);
}

void OnPush_ChangeLang(int selection) {
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
    Menu_SetCancelCallback(OnPush_ChangeSetting);
}

int GetMessageLang(void) {
    return g_lang;
}

void OnPush_Circle(int selection)
{
	g_assing = 0;
	Menu_WriteLine("OnPush_Circle", 0xFFFFFF);
}

void OnPush_Cross(int selection)
{
	g_assing = 1;
	Menu_WriteLine("OnPush_Cross", 0xFFFFFF);
}

static void OnPush_ChangeAssign(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("circle is enter", OnPush_Circle);
    Menu_AppendItem("cross  is enter", OnPush_Cross);
    Menu_SetCancelCallback(OnPush_ChangeSetting);
}

int GetAssign(void) {
    return g_assing;
}
