/* cflags: -O1 */
#include "common.h"
#include "parse_hist.h"
#include "m2c_macros.h"
HstNode *HST_searchTargetNameHistoryNode();
HstNode *HST_createHistoryNode();
HstNode *parseCopyHistoryNode();
int HST_getHeadHistoryNode();                       /* extern */
int HST_getHistoryWithOffset(M2C_UNK);              /* extern */
int parseDeleteMultiBuffer();                       /* extern */
M2C_UNK parseRoundHistoryNode(int, int);            /* extern */

M2C_UNK HST_moveBackHistory();                      /* extern */
M2C_UNK HST_moveFrontHistory();                     /* extern */


void parseFreeItem(HstNode *n) {
    void **css;
    void **nx;

    if (n == NULL) {
        return;
    }
    MEM_free(0, n->s08.p);
    n->s08.p = NULL;
    n->s08.len = 0;
    MEM_free(0, n->s20.p);
    n->s20.p = NULL;
    n->s20.len = 0;
    MEM_free(0, n->s28.p);
    n->s28.p = NULL;
    n->s28.len = 0;
    n->xA4 = 0;
    for (css = n->css; css != NULL; css = nx) {
        nx = css[8];
        CSS2_freeCSSStyleSheet(css);
    }
    n->css = NULL;
    if (n->doc != NULL) {
        Util_DOMAPI_DeleteHTMLDOMImplementation(Document_getImplementation(n->doc));
        DOMAPI_Finalize();
        n->doc = NULL;
    }
    if (HST_deleteJSURI(n) == 0) {
        n->x74 = 0;
        n->x78 = 0;
    }
    if (HST_deleteCSSURI(n) == 0) {
        n->x7C = 0;
        n->x80 = 0;
    }
    n->x6C = 0;
}

void parseDeleteHistoryItem(HstNode *top) {
    HstNode *node;
    HstNode *parent;
    HstNode *next;

    if (top == NULL) {
        return;
    }
    parent = top->parent;
    next = top->next;
    node = top;
    if (node->flag >= 0) {
        parseFreeItem(node);
    }
    while (node != NULL) {
        if (node->child != NULL) {
            node = node->child;
        } else if (node->next != NULL) {
            node = node->next;
            if (node == next) {
                return;
            }
        } else {
            node = node->parent;
            if (node == parent || node == top) {
                return;
            }
            if (node == NULL) {
                return;
            }
        climb:
            if (node->next == NULL) {
                goto up;
            }
            node = node->next;
        }
        if (node->flag >= 0) {
            parseFreeItem(node);
        }
        continue;
    up:
        node = node->parent;
        if (node == parent || node == top) {
            return;
        }
        if (node != NULL) {
            goto climb;
        }
        return;
    }
}

void parseHST_deleteHistoryNode(int name, int len) {
    HstNode *node;

    if (name == 0) {
        node = (HstNode *)HST_getHeadHistoryNode();
    } else {
        node = HST_searchTargetNameHistoryNode(name, len);
    }
    parseDeleteHistoryItem(node);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseRegistURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseReplaceURI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseReloadURI);

#ifndef NULL
#define NULL ((void *)0)
#endif

int parseMoveFrontURI(int arg0) {
    int temp_s0;
    int var_s1;

    var_s1 = arg0;
    if (arg0 != 0) {
        var_s1 = parseDeleteMultiBuffer();
    }
    temp_s0 = HST_getHistoryWithOffset(1);
    parseRoundHistoryNode(temp_s0, HST_getHeadHistoryNode());
    HST_moveFrontHistory();
    return var_s1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int parseMoveBackURI(int arg0) {
    int temp_s0;
    int var_s1;

    var_s1 = arg0;
    if (arg0 != 0) {
        var_s1 = parseDeleteMultiBuffer();
    }
    temp_s0 = HST_getHistoryWithOffset(-1);
    parseRoundHistoryNode(temp_s0, HST_getHeadHistoryNode());
    HST_moveBackHistory();
    return var_s1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void parseSavedContents(void) {
    HST_moveBackHistory();
    parseHST_deleteHistoryNode(0, 0);
    HST_moveFrontHistory();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseCopyHistoryEntities);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseCopyHistoryNode);

int uricmp_722F8(HstStr *a, HstStr *b) {
    int i;

    if (a->len != b->len) {
        return 0;
    }
    for (i = 0; i < a->len; i++) {
        if (a->p[i] != b->p[i]) {
            return 0;
        }
    }
    return 1;
}

void flushRequestFlag(HstNode *node) {
    fillRequestFlag(node, 0);
}

void fillRequestFlag(HstNode *top, int flag) {
    HstNode *node;

    node = top;
    if (node->flag >= 0) {
        HST_setRequestFlag(node, flag);
    }
    while (node != NULL) {
        if (node->child != NULL) {
            node = node->child;
        } else if (node->next != NULL) {
            node = node->next;
        } else {
            node = node->parent;
            if (node == NULL) {
                return;
            }
        climb:
            if (node->next == NULL) {
                goto up;
            }
            node = node->next;
        }
        if (node->flag >= 0) {
            HST_setRequestFlag(node, flag);
        }
        continue;
    up:
        node = node->parent;
        if (node != NULL) {
            goto climb;
        }
        return;
    }
}

int copyEntities(HstNode *a, HstNode *b) {
    if (uricmp_722F8(a, b) == 0 || a->x48 != b->x48) {
        a->x6C = 0;
        flushRequestFlag(a);
        return 0;
    }
    if (b->flag >= 0) {
        HST_setRequestFlag(a, 5);
    }
    HST_setDomObject(a, HST_getDomObject(b));
    HST_setSourceType(a, HST_getSourceType(b));
    HST_setMethodType(a, HST_getMethodType(b));
    a->x6C = b->x6C;
    HST_setDomObject(b, 0);
    b->x6C = 0;
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseHistory", parseRoundHistoryNode);
