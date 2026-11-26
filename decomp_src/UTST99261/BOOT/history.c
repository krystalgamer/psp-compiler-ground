#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_initHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_attachHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_freeHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_createHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_deleteHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_registHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getHeadHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getHistoryLength);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getCurrentIndex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_addSiblingHistoryNode);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getSiblingHistoryNode(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xB0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getPrevSiblingHistoryNode(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xB4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_addChildHistoryNode);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getChildHistoryNode(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xAC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getParentHistoryNode(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xA8);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_moveFrontHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_moveBackHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getHistoryWithOffset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setCurURI);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getCurURI(int *arg0) {
    return *arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getCurURIlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setBaseURI);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getBaseURI(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getBaseURIlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xC);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setRefURI);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getRefURI(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getRefURIlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x14);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setTargetName);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getTargetName(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getTargetNamelen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x1C);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setDefaultTarget);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getDefaultTarget(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getDefaultTargetlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x24);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setTitle);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getTitle(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x28);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getTitlelen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x2C);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setJSURI);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getJSURIlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x78);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getJSURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_deleteJSURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setCSSURI);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getCSSURIlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x80);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getCSSURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_deleteCSSURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setStyleSheet);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getStyleSheet(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x70);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setSourceType);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getSourceType(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x30);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setMemoIndex);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getMemoIndex(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x34);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setMethodType);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getMethodType(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x38);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setRequestFlag);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getRequestFlag(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x3C);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setCharSet);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getCharSet(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x44);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setSessionID);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getSessionID(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x48);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setUnitId);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getUnitId(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x4C);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setAuthUsername);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getAuthUsername(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x50);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getAuthUsernamelen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x54);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setAuthPassword);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getAuthPassword(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x58);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getAuthPasswordlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x5C);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setHttpHeader);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getHttpHeader(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x60);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setPostData);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getPostData(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x64);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_freePostData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setDomObject);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getDomObject(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x68);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_createFragmentIDs);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setFragmentIDs);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_deleteFragmentIDs);

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *HST_getFragmentIDs(void *arg0, int arg1) {
    M2C_UNK *var_a2;
    int temp_a1;
    int var_v1;

    temp_a1 = arg1 + M2C_FIELD(arg0, int *, 0x88);
    var_a2 = arg0 + 0x8C;
    if ((temp_a1 < 0) || (M2C_FIELD(arg0, int *, 0x84) < temp_a1)) {
        return NULL;
    }
    var_v1 = 0;
    if (temp_a1 > 0) {
        do {
            var_v1 += 1;
            var_a2 = *var_a2;
        } while (var_v1 < temp_a1);
    }
    return var_a2;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getFragmentIDsPosition(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x88);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_moveFragmentIDs);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setTransStatus);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getTransStatus(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xA4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchSessionIDHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchRequestFlagHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchDocumentHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchTargetNameHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchUriHistoryNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getHistoryGarbageList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_flushHistoryGarbageList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", searchExtFileSessionID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", searchExtFileHistoryURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getParentExtSessionID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getParentExtHistoryURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_getExtHistoryURI);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *getReqFlagCSSHistURI(void *arg0, int arg1) {
    void *var_a0;
    void *var_v1;

    var_a0 = arg0;
    var_v1 = NULL;
    if (var_a0 != NULL) {
loop_1:
        var_v1 = var_a0;
        if (M2C_FIELD(var_a0, int *, 0x3C) != arg1) {
            var_a0 = M2C_FIELD(var_a0, void **, 0xB0);
            if (var_a0 == NULL) {
                var_v1 = NULL;
            } else {
                goto loop_1;
            }
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchCSSRequestFlag);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *HST_getReqFlagJSHistURI(void *arg0, int arg1) {
    void *var_a0;
    void *var_v1;

    var_a0 = arg0;
    var_v1 = NULL;
    if (var_a0 != NULL) {
loop_1:
        var_v1 = var_a0;
        if (M2C_FIELD(var_a0, int *, 0x3C) != arg1) {
            var_a0 = M2C_FIELD(var_a0, void **, 0xB0);
            if (var_a0 == NULL) {
                var_v1 = NULL;
            } else {
                goto loop_1;
            }
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_searchJSRequestFlag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_diffHistoryNodes);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_deleteCurrentHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", deleteHistory);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", searchHistoryNodeInner);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", addHistoryGarbage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", uricmp_5704C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", freeFragmentIDs);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_setRequestResult);

#ifndef NULL
#define NULL ((void *)0)
#endif
int HST_getRequestResult(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x40);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_httpHeaderDisassemble);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_httpHeaderDuplicate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/history", HST_httpHeaderFree);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/history", D_00134D78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/history", D_00134D7C);
