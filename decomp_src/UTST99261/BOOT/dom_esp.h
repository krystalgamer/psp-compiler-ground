/* browser core interface (jsi / esp_*), recovered from the asm */
#ifndef DOM_ESP_H
#define DOM_ESP_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct EspConfig {
    int x00;
    int cookieEnabled;                /* 0x04 */
    char rest[0x68];
} EspConfig;

typedef struct EspContext {
    unsigned short state;             /* 0x00, 2 = terminating */
    char pad02[0x7A];
    EspConfig config;                 /* 0x7C */
    EspConfig *prefs;                 /* 0xEC, copy being edited */
    int xF0;
    int xF4;
    void *msg;                        /* 0xF8 */
    int xFC;
    int x100;
    unsigned short inputDevice;       /* 0x104 */
} EspContext;

extern EspContext *esp_context;

typedef struct JSTimer {
    int x00;
    int id;                           /* 0x04 */
    int status;                       /* 0x08 */
    void *x0C;
    void *cx;                         /* 0x10 */
    struct JSTimer *next;             /* 0x14 */
} JSTimer;

typedef struct JSPtr {
    void *cx;
    int x04;
    struct JSPtr *next;               /* 0x08 */
    int x0C;
} JSPtr;

extern JSTimer *g_JS_TIMER_;
extern JSPtr **g_JSPTRLIST_;

void *MEM_malloc(int pool, unsigned int size);
void MEM_free(int pool, void *p);

int esp_setBoolConfig(EspConfig *c, int key, int value);
int esp_getBoolConfig(EspConfig *c, int key, void *value);
int esp_setIntConfig(EspConfig *c, int key, int value);
int esp_getIntConfig(EspConfig *c, int key, void *value);
int esp_setStringConfig(EspConfig *c, int key, int value);
int esp_getStringConfig(EspConfig *c, int key, void *value);
void esp_freeConfig(EspConfig *c);
int esp_copyConfig(EspConfig *dst, EspConfig *src);

int ESP_beginConfig(void);
int ESP_endConfig(void);
int ESP_setBoolPreference(int key, int value);

void *HST_getHistoryWithOffset(int offset);
void *HST_getHeadHistoryNode(void);
int HST_getFragmentIDs(void *node, int dir);

#endif
