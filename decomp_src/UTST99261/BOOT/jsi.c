/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK HST_attachHistory();                        /* extern */
int GUI_RadioButton_getState(int);                  /* extern */
void *Node_getBox();                                /* extern */
extern void *gPREF_UI;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
void *duplicateDOMString(int);                      /* extern */
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
extern void *gNDA_NAME_JS_GLOBAL;
extern void *g_JS_TIMER_;
M2C_UNK js_delTimerID(int, M2C_UNK, M2C_UNK);       /* extern */
int OS_thread_self();                               /* extern */
int *HST_getHeadHistoryNode();                      /* extern */
int esp_postMsgLoadPage(int, int, int, M2C_UNK, M2C_UNK, int, M2C_UNK); /* extern */
extern void *esp_context;
M2C_UNK esp_postMsgSaveURL(int, int, int);          /* extern */
M2C_UNK esp_postMsgDataAttr(int, M2C_UNK, int, int); /* extern */
int MEM_addHaltCallback(M2C_UNK, int);              /* extern */

extern int attached;
M2C_UNK newDOMString_4B5FC();                       /* extern */
M2C_UNK esp_getMemoNum();                           /* extern */
M2C_UNK esp_loadMemoList();                         /* extern */
M2C_UNK HST_getHistoryLength();                     /* extern */
M2C_UNK HST_getCurrentIndex();                      /* extern */
M2C_UNK esp_setDialogReply();                       /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", newDOMString_4B5FC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", duplicateDOMString);

#ifndef NULL
#define NULL ((void *)0)
#endif

int JSI_init(void) {
    HST_attachHistory();
    attached = 1;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_free(void) {
    attached = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getElementPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setButtonValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getCheckboxState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setCheckboxState);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133A2C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setDocumentCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentLastModified);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentReferrer);

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_getDocumentSelection(void) {
    newDOMString_4B5FC(0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getFileUploadValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getImageComplete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getLinkURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setLinkURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getOptionState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setOptionState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getOptionText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setOptionText);

#ifndef NULL
#define NULL ((void *)0)
#endif

int JSI_getRadioState(int arg0) {
    void *temp_v0;

    if ((arg0 == 0) || (temp_v0 = Node_getBox(), (temp_v0 == NULL)) || (M2C_FIELD(temp_v0, short *, 0x38) != 0xF)) {
        return -1;
    }
    return GUI_RadioButton_getState(M2C_FIELD(temp_v0, int *, 0x2C)) != 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setRadioState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getSelectedIndex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setSelectedIndex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getTextValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setTextValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getWindowRec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getWindowName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setWindowName);

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);

void JSI_getBrowserHomeURL(void) {
    void *temp_s0;

    temp_s0 = gPREF_UI;
    newDOMString_4B5FC(M2C_FIELD(temp_s0, int *, 0x40), strlen(M2C_FIELD(temp_s0, signed char **, 0x40)));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getAbsoluteURL);

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_freeDOMString(void *arg0) {
    void *temp_a1;

    if (arg0 != NULL) {
        temp_a1 = M2C_FIELD(arg0, void **, 8);
        if (temp_a1 != NULL) {
            MEM_free(0, temp_a1);
        }
        MEM_free(0, arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_freeURLRec(void *arg0) {
    if (arg0 != NULL) {
        JSI_freeDOMString(M2C_FIELD(arg0, int *, 4));
        JSI_freeDOMString(M2C_FIELD(arg0, int *, 8));
        JSI_freeDOMString(M2C_FIELD(arg0, int *, 0xC));
        JSI_freeDOMString(M2C_FIELD(arg0, int *, 0x10));
        JSI_freeDOMString(M2C_FIELD(arg0, int *, 0x14));
        MEM_free(0, arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_setURLProtocol(void *arg0, int arg1) {
    int temp_a0;
    void *temp_v0;

    temp_v0 = duplicateDOMString(arg1);
    temp_a0 = M2C_FIELD(temp_v0, int *, 4);
    if ((temp_a0 != 0) && (M2C_FIELD(((temp_a0 * 2) + M2C_FIELD(temp_v0, int *, 8)), unsigned short *, -2) == 0x3A)) {
        M2C_FIELD(temp_v0, int *, 0) = (int) (M2C_FIELD(temp_v0, int *, 0) - 1);
        M2C_FIELD(temp_v0, int *, 4) = (int) (temp_a0 - 1);
    }
    JSI_freeDOMString(M2C_FIELD(arg0, void **, 4));
    M2C_FIELD(arg0, void **, 4) = temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void JSI_setURLPort(short *arg0, short arg1) {
    *arg0 = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_setURLHost(void *arg0, int arg1) {
    int temp_s1;

    temp_s1 = duplicateDOMString(arg1);
    JSI_freeDOMString(M2C_FIELD(arg0, int *, 8));
    M2C_FIELD(arg0, int *, 8) = temp_s1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setURLPathname);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setURLHash);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setURLSearch);

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_newDOMString(void) {
    newDOMString_4B5FC();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSSendMail);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSWaitMail);

#ifndef NULL
#define NULL ((void *)0)
#endif
void SetIpcMember(void *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    M2C_FIELD(arg0, int *, 0) = arg1;
    M2C_FIELD(arg0, int *, 4) = arg2;
    M2C_FIELD(arg0, int *, 8) = arg3;
    M2C_FIELD(arg0, int *, 0xC) = arg4;
    M2C_FIELD(arg0, int *, 0x10) = arg5;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = arg6;
    M2C_FIELD(arg0, int *, 0x1C) = arg7;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", SetIpcmsg);

#ifndef NULL
#define NULL ((void *)0)
#endif

void *init_global_ptr(void) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = MEM_malloc(0, 0x24);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0) = 0;
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, int *, 8) = 0;
        M2C_FIELD(temp_v0, int *, 0xC) = 0;
        M2C_FIELD(temp_v0, int *, 0x10) = 0;
        M2C_FIELD(temp_v0, int *, 0x14) = 0;
        M2C_FIELD(temp_v0, int *, 0x18) = 0;
        M2C_FIELD(temp_v0, int *, 0x1C) = 0;
        M2C_FIELD(temp_v0, int *, 0x20) = 0;
        gNDA_NAME_JS_GLOBAL = temp_v0;
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void delete_global_ptr(void) {
    int temp_v0;

    temp_v0 = get_global_ptr();
    gNDA_NAME_JS_GLOBAL = 0;
    MEM_free(0, temp_v0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int get_global_ptr(void) {
    return gNDA_NAME_JS_GLOBAL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_InitTimer(void) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x18);
    M2C_FIELD(temp_v0, int *, 4) = -1;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    g_JS_TIMER_ = temp_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", js_getTimerStatus);

#ifndef NULL
#define NULL ((void *)0)
#endif

int getTimerNum(void) {
    int var_v1;
    void *var_v0;

    var_v1 = 0;
    if (g_JS_TIMER_ != NULL) {
        var_v0 = M2C_FIELD(g_JS_TIMER_, void **, 0x14);
        if (var_v0 != NULL) {
            do {
                var_v0 = M2C_FIELD(var_v0, void **, 0x14);
                var_v1 += 1;
            } while (var_v0 != NULL);
        }
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int js_checkAddTimer(void) {
    return (getTimerNum() < 0xB) - 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_DestroyTimer(void) {
    void *temp_s0;

    temp_s0 = g_JS_TIMER_;
    if (M2C_FIELD(temp_s0, void **, 0x14) != NULL) {
        do {
            js_delTimerID(M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x14), int *, 4), 3, 0);
        } while (M2C_FIELD(temp_s0, void **, 0x14) != NULL);
    }
    MEM_free(0, temp_s0);
    g_JS_TIMER_ = NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_addTimer(int arg0, int arg1, int arg2, int arg3) {
    void *temp_v0;
    void *var_s4;

    var_s4 = g_JS_TIMER_;
    temp_v0 = MEM_malloc(0, 0x18);
    M2C_FIELD(temp_v0, int *, 0) = arg1;
    M2C_FIELD(temp_v0, int *, 4) = arg0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = arg2;
    M2C_FIELD(temp_v0, int *, 0x10) = arg3;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    if (M2C_FIELD(var_s4, int *, 0x14) != 0) {
        do {
            var_s4 = M2C_FIELD(var_s4, void **, 0x14);
        } while (M2C_FIELD(var_s4, int *, 0x14) != 0);
    }
    M2C_FIELD(var_s4, void **, 0x14) = temp_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", js_delTimerID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", searchTimerCx);

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_delTimerCx(int arg0) {
    void *var_s0;

    var_s0 = g_JS_TIMER_;
    if (var_s0 != NULL) {
        do {
            if (M2C_FIELD(var_s0, int *, 0x10) == arg0) {
                js_delTimerID(M2C_FIELD(var_s0, int *, 4), 3, 1);
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0x14);
        } while (var_s0 != NULL);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListInit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListDestroy);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListFindCx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListFind);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListFindEmpty);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListAdd);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListDel);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListDelAll);

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSRunStart(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0xC) = OS_thread_self();
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void JSRunFinish(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0xC) = 0;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListDumpAll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListDumpOne);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSFreeJSPtr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSCreate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSRun);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSDestroy);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133A50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133A54);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSHandleEvent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_initCore);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_initCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_startCore);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_terminateCore);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_destroyCore);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_loadPage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133BB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133BC4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_submitForm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_moveHistory);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ESP_reloadPage(int arg0) {
    int *temp_v0;
    int temp_s0;
    int var_v0;

    temp_v0 = HST_getHeadHistoryNode();
    var_v0 = -1;
    if (temp_v0 != NULL) {
        temp_s0 = HST_getCurURI(temp_v0);
        var_v0 = esp_postMsgLoadPage(M2C_FIELD(esp_context, int *, 0xF8), temp_s0, HST_getRefURI(temp_v0), 0, 1, arg0 != 1, 0);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_abortLoading);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_handleDeviceEvent);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ESP_saveCurrentPage(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int ESP_deleteSavedPage(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int ESP_deleteAllSavedPage(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_getSavedPageNum(void) {
    esp_getMemoNum();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_loadSavedPageList(void) {
    esp_loadMemoList();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void ESP_freeSavedPageList(int arg0) {
    if (arg0 != 0) {
        esp_freeMemoList();
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_downloadURL(int arg0, int arg1) {
    esp_postMsgSaveURL(M2C_FIELD(esp_context, int *, 0xF8), arg0, arg1);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setFreeScrollEnabled);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_findString);

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_getPositionAttribute(int arg0, int arg1) {
    esp_postMsgDataAttr(M2C_FIELD(esp_context, int *, 0xF8), 0, arg0, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_getFocusAttribute(void) {
    esp_postMsgDataAttr(M2C_FIELD(esp_context, int *, 0xF8), 1, 0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setTextField);

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_getHistoryLength(void) {
    HST_getHistoryLength();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_currentHistoryIndex(void) {
    HST_getCurrentIndex();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getHistoryURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getHistoryTitle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_hasNextHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_hasPreviousHistory);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ESP_deleteCache(void) {
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setCookieEnabled);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_deleteAllCookies);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setMouseTracking);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_beginConfig);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_endConfig);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setBoolPreference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getBoolPreference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setIntPreference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getIntPreference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setStringPreference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getStringPreference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setEncoding);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getEncoding);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setOnlineEnabled);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setFontSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getFontSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setInputData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setEnabledInputDevice);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setUnitId);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getUnitId);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setBgColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getBgColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setThreadPriority);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getThreadPriority);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setHomePageURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getHomePageURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setUserAgent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getUserAgent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setCacheSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getCacheSize);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ESP_guiMemAlloc(int arg0) {
    int temp_s0;
    int var_s1;

    var_s1 = 0;
    if (esp_context != 0) {
        temp_s0 = MEM_addHaltCallback(0, 0);
        var_s1 = MEM_malloc(0, arg0);
        MEM_addHaltCallback(0, temp_s0);
    }
    return var_s1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_guiMemFree(int arg0) {
    if (esp_context != 0) {
        MEM_free(0, arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ESP_malloc(int arg0) {
    int temp_s0;
    int var_s1;

    var_s1 = 0;
    if (esp_context != 0) {
        temp_s0 = MEM_addHaltCallback(0, 0);
        var_s1 = MEM_malloc(0, arg0);
        MEM_addHaltCallback(0, temp_s0);
    }
    return var_s1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_free(int arg0) {
    if (esp_context != 0) {
        MEM_free(0, arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_setModelessDialogReply(void) {
    esp_setDialogReply();
}
