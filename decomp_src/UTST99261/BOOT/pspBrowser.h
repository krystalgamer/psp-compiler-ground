#ifndef PSPBROWSER_H
#define PSPBROWSER_H
/* types recovered from DWARF (tools/dwarfhdr.py) */
typedef struct { /* size 0x64 */
    void *image;
    int imageWidth;
    int imageHeight;
    int browserWidth;
    int browserHeight;
    void *memCookie;
    int memCookieSize;
    void *memBrowser;
    int memBrowserSize;
    int memCashSize;
    char *uid;
    char *homeURL;
    char *backcolor;
    int mode;
    int thread;
    int fontSize;
    void *character0;
    void *character1;
    void *character2;
    void *character3;
    void *mimetype0;
    void *mimetype1;
    void *mimetype2;
    void *mimetype3;
    char *userAgent;
} PSPBROWSER_INI;
typedef struct { /* size 0x10 */
    int x;
    int y;
    int width;
    int height;
} PSPBROWSER_IMAGE_POSITION;
typedef int (*PSPBROWSER_ANCHOR_CALLBACK)(char *, char *);
typedef int (*PSPBROWSER_IMAGE_CALLBACK)(char *, char *, PSPBROWSER_IMAGE_POSITION *);
typedef int (*PSPBROWSER_DOWNLOAD_CALLBACK)(void *, int);
typedef void (*PSPBROWSER_FOCUS_CALLBACK)(char *, char *);
typedef void (*PSPBROWSER_UNLOAD_CALLBACK)(void);
typedef struct { /* size 0xc */
    int x;
    int y;
    int input;
} PSPBROWSER_INPUT;
typedef struct { /* size 0x4 */
    int state;
} PSPBROWSER_GET_STATE;
typedef struct { /* size 0x10 */
    int x;
    int y;
    int width;
    int height;
} PSPBROWSER_GET_CONTENTSSIZE;
typedef struct { /* size 0xc */
    char *uid;
    int length;
    int getLength;
} PSPBROWSER_GET_UID;
typedef struct { /* size 0x14 */
    char *input;
    int length;
    int getLength;
    int inputLength;
    int state;
} PSPBROWSER_GET_INPUT;
typedef struct { /* size 0xc */
    char *alert;
    int length;
    int getLength;
} PSPBROWSER_GET_ALERT;
typedef struct { /* size 0xc */
    char *confirm;
    int length;
    int getLength;
} PSPBROWSER_GET_CONFIRM;
typedef struct { /* size 0xc */
    char *file;
    int length;
    int getLength;
} PSPBROWSER_GET_FILE;
typedef struct { /* size 0xc */
    char *url;
    int length;
    int getLength;
} PSPBROWSER_GET_URL;
typedef struct { /* size 0x1c */
    char *url;
    int length;
    int getLength;
    char *mime;
    int mimeLength;
    int getMimeLength;
    int contentSize;
} PSPBROWSER_GET_DOWNLOAD;
typedef struct { /* size 0x4 */
    int readSize;
} PSPBROWSER_GET_DOWNLOAD_STATE;
typedef struct { /* size 0x8 */
    int x;
    int y;
} PSPBROWSER_SET_CONTENTSSIZE;
typedef struct { /* size 0x4 */
    int state;
} PSPBROWSER_SET_CONFIRM;
typedef struct { /* size 0x8 */
    char *file;
    int state;
} PSPBROWSER_SET_FILE;
typedef struct { /* size 0xc */
    char *id;
    char *password;
    int state;
} PSPBROWSER_SET_PASSWORD;
typedef struct { /* size 0x4 */
    int state;
} PSPBROWSER_SET_SSL_OUT;
typedef struct { /* size 0xc */
    char *url;
    char *postData;
    int postSize;
} PSPBROWSER_SET_POST;
typedef struct { /* size 0x8 */
    char *url;
    PSPBROWSER_DOWNLOAD_CALLBACK callback;
} PSPBROWSER_SET_DOWNLOAD_START;

/* library functions */
int pspBrowserSetState(int state, void *param);
int pspBrowserGetState(int state, void *param);

int pspBrowserAddAnchor(char *ext, PSPBROWSER_ANCHOR_CALLBACK callback);

int pspBrowserExec(PSPBROWSER_INPUT *input);

int pspBrowserInit(PSPBROWSER_INI *ini);
int pspBrowserExit(void);
int pspBrowserSetFocusCallback(PSPBROWSER_FOCUS_CALLBACK callback);

#endif
