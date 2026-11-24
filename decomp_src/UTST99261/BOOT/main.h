#ifndef MAIN_H
#define MAIN_H
/* types recovered from DWARF (tools/dwarfhdr.py) */
enum {
    PSP_AP_INIT = 0,
    PSP_AP_EXIT = 1,
    PSP_AP_RE_INIT = 2,
    PSP_BROWSER_INIT = 3,
    PSP_BROWSER_EXIT = 4,
    PSP_BROWSER_EXEC = 5,
    PSP_BROWSER_FONTEX = 6,
    PSP_BROWSER_INPUT = 7,
    PSP_BROWSER_ALERT = 8,
    PSP_BROWSER_CONFIRM = 9,
    PSP_BROWSER_PASSWORD = 10,
    PSP_BROWSER_SSL_IN = 11,
    PSP_BROWSER_SSL_OUT = 12,
    PSP_BROWSER_READERROR = 13,
    PSP_BROWSER_FATALERROR = 14,
    PSP_BROWSER_DOWNLOAD = 15,
    PSP_CONTENT_DOWNLOAD = 16,
    PSP_BROWSER_MENU = 17,
    PSP_MPEG = 18,
    PSP_MP3 = 19,
    PSP_AP_END = 20,
};
typedef int (*DISPATCH)(void);
extern int iPspBrowserApMode;
extern char disp_list[2621440];
extern char *pSound;
extern char *pHome;
extern char *pPath;
extern char *pUserAgent;
extern char _cPspBrowserExit;
extern char _cFontSize;
extern char _cTexMode;
extern char _cImageDez;

void gInit();
void browserDraw(void);
int inputExec(char *moji, int m_size, int mod);
int pspNetworkInit(void);
void pspNetworkExit(void);

#endif
