/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern int attached;
M2C_UNK newDOMString_4B5FC();                       /* extern */
M2C_UNK esp_getMemoNum();                           /* extern */
M2C_UNK esp_loadMemoList();                         /* extern */
M2C_UNK HST_getHistoryLength();                     /* extern */
M2C_UNK HST_getCurrentIndex();                      /* extern */
M2C_UNK esp_setDialogReply();                       /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", newDOMString_4B5FC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", duplicateDOMString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_init);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentSelection);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getRadioState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setRadioState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getSelectedIndex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setSelectedIndex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getTextValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setTextValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getWindowRec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getWindowName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setWindowName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getBrowserHomeURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getAbsoluteURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_freeDOMString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_freeURLRec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setURLProtocol);

#ifndef NULL
#define NULL ((void *)0)
#endif
void JSI_setURLPort(short *arg0, short arg1) {
    *arg0 = arg1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setURLHost);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", SetIpcMember);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", SetIpcmsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", init_global_ptr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", delete_global_ptr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", get_global_ptr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", js_InitTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", js_getTimerStatus);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", getTimerNum);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", js_checkAddTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", js_DestroyTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", js_addTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", js_delTimerID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", searchTimerCx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", js_delTimerCx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListInit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListDestroy);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListFindCx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListFind);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListFindEmpty);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListAdd);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListDel);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSPtrListDelAll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSRunStart);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_reloadPage);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_freeSavedPageList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_downloadURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setFreeScrollEnabled);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_findString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getPositionAttribute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_getFocusAttribute);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_guiMemAlloc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_guiMemFree);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_malloc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_free);

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_setModelessDialogReply(void) {
    esp_setDialogReply();
}
