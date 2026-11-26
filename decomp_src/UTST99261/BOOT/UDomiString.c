/* cflags: -O1 */
#include "common.h"
#include "parse_hist.h"
#include "parse_ps.h"
#include "dom_domi.h"
#include "m2c_macros.h"
extern int mq_layout;
extern int mq_iom;
extern int mq_ui;
typedef struct ExMsgNode {
    PsIpc *msg;
    struct ExMsgNode *prev;
    struct ExMsgNode *next;
} ExMsgNode;
typedef struct PsTbl {
    int cmd;
    int x04;
    int dest;
    int sts;
} PsTbl;
extern PsTbl D_00135260[];
extern int mq_ps;
extern int mq_ps_su;
extern int buf_sessionUI;
extern int buf_localUI;
extern char D_00135598[];
extern int mq_js;
extern char D_0013559C[];
extern const char _ctype_[];
extern int buf_ps_sts;
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
int ps_isMoveHistory(int, int, int);                /* extern */
extern int buf_sessionID;
extern int buf_sessionURL;
extern int buf_sessionstop;
int ps_createExMsgBox();                            /* extern */
extern int Accession;
extern int AuthDialogCancel;
extern int CHARSET_CODE;
extern int COMPULSION_END_FLG;
extern int CONTENT_GETCNT;
extern int CONTENT_GETTMEP;
extern int CONTENT_SAVE;
extern int ContntHeader;
extern int ContntType;
extern int DOCUMENT_WRITE;
extern int DOM_NODE_MAX_SIZE;
extern unsigned char EX_MSG_BOX_NO;
extern int GET_HEAD_SESSIONID;
extern int GET_HEAD_STAT;
extern int GET_HEAD_STOP;
extern int GetPlace;
extern int JS_Document;
extern int LAYOUT_STOP;
extern int Layout_Cont;
extern int NOTARGET;
extern int On_Save;
extern signed char PageGetType;
extern int RECIEVE_MSG;
extern int RELOAD_FLG;
extern int REQ_FAILD;
extern int SAVE_STOP;
extern int SSLFlg;
extern int SSL_Next_STS;
extern int SaveREF;
extern int SaveTRAGETURI;
extern int SaveURI;
extern int SaveUnitId;
extern int Security;
extern int SubmitExtn;
extern int UPDATE_TYPE;
extern int before_ps_sts;
extern int buf_Loding_Stop_FLG;
extern int buf_Message_Show_FLG;
extern int buf_Message_cnt;
extern int buf_lo_parcent;
extern unsigned char buf_ps_errinf;
extern int buf_ps_evt;
extern int buf_ps_parcent;
extern int gpsCntxtTable;
extern int psCacheMode;
extern int save_sessionURL;
extern int save_sessionstop;
int HST_getHeadHistoryNode();                       /* extern */
M2C_UNK HST_searchCSSRequestFlag(int, int);         /* extern */
M2C_UNK HST_searchJSRequestFlag(int, int);          /* extern */
int *MEM_malloc(M2C_UNK, M2C_UNK);                  /* extern */



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", UDomiString_ToLower);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", UDomiString_ToUpper);

int UDomiString_CompareNoCase(const DOMChar *s1, unsigned int n1, const DOMChar *s2, unsigned int n2) {
    int d;

    while (n1 != 0 && n2 != 0) {
        d = UDomiString_ToUpper(*s1++);
        d -= UDomiString_ToUpper(*s2++);
        if (d != 0) {
            return d > 0 ? 1 : -1;
        }
        n1--;
        n2--;
    }
    if (n1 != n2) {
        return n1 < n2 ? -1 : 1;
    }
    return 0;
}

int UDomiString_CompareBinary(const DOMChar *s1, unsigned int n1, const DOMChar *s2, unsigned int n2) {
    int d;

    while (n1 != 0 && n2 != 0) {
        d = *s1++ - *s2++;
        if (d != 0) {
            return d > 0 ? 1 : -1;
        }
        n1--;
        n2--;
    }
    if (n1 != n2) {
        return n1 < n2 ? -1 : 1;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

DOMChar *UDomiString_Allocate(unsigned int len) {
    return UDomiMemory_Allocate(len * 2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void UDomiString_Free(DOMChar *s) {
    UDomiMemory_Free(s);
}

void UDomiString_Copy(DOMChar *d, const DOMChar *s, unsigned int len) {
    UDomiMemory_Copy(d, s, len * 2);
}

void UDomiString_Move(DOMChar *d, const DOMChar *s, unsigned int len) {
    UDomiMemory_Move(d, s, len * 2);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", inverseDCT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", sortImage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", JPEG);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", PNG);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", esp_psThread);

int ps_sndmsg(PsIpc *msg, int dest) {
    struct {
        int x00;
        PsIpc body;
    } m;
    int q;

    q = 0;
    m.body = *msg;
    if (dest == 2) {
        q = mq_ps;
    } else if (dest == 4) {
        q = mq_layout;
    } else if (dest == 5) {
        q = mq_iom;
    } else if (dest == 1) {
        q = mq_ui;
    }
    if (OS_mq_send(q, &m, sizeof(m), 0) < 0) {
        ps_halt("Parser : OS_mq_send(ps_comm) failed");
    }
}

int setParseMassageToDestTask(int dest, int a, int b, int c, int d, int e, int f, int g) {
    PsMsg m;

    m.type = 2;
    m.arg[0] = a;
    m.arg[1] = b;
    m.arg[2] = c;
    m.arg[3] = d;
    m.arg[4] = e;
    m.arg[5] = f;
    m.arg[6] = g;
    return ps_sndmsg(&m, dest);
}

void ps_halt(char *msg) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_dmy(void) {
    ps_dmyskip();
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_dmyskip(void *arg0) {
    int temp_a1;

    temp_a1 = M2C_FIELD(arg0, int *, 0x1C);
    if (temp_a1 != 0) {
        MEM_free(0, temp_a1);
    }
    return buf_ps_sts;
}

int ps_dmy1(void *p) {
    ps_save(p, 0);
    return buf_ps_sts;
}

int ps_dmy2(void *p) {
    NOTARGET = 0;
    ps_save(p, 0);
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_dmy3(void *arg0) {
    int temp_a1;

    if (ps_isMoveHistory(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 4), M2C_FIELD(arg0, int *, 0x14)) == 0) {
        temp_a1 = M2C_FIELD(arg0, int *, 0x1C);
        if (temp_a1 != 0) {
            MEM_free(0, temp_a1);
        }
    } else {
        ps_save(arg0, 0);
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_transmit);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_sessionGen(void) {
    int temp_v1;

    temp_v1 = buf_sessionID + 1;
    buf_sessionID = temp_v1;
    if (temp_v1 > 0x08000000) {
        buf_sessionID = 1;
    }
    return buf_sessionID;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_sessionURL(void) {
    int temp_v1;

    temp_v1 = buf_sessionURL + 1;
    buf_sessionURL = temp_v1;
    if (temp_v1 > 0x07FFFFFF) {
        buf_sessionURL = 1;
    }
    return buf_sessionURL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_sessionstop(void) {
    int temp_v1;

    temp_v1 = buf_sessionstop + 1;
    buf_sessionstop = temp_v1;
    if (temp_v1 > 0x07FFFFFF) {
        buf_sessionstop = 1;
    }
    return buf_sessionstop;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void ps_idolinit(void) {
    buf_ps_parcent = 0;
    buf_lo_parcent = 0;
    JS_Document = 0;
    Layout_Cont = 0;
    ContntType = 5;
    rcvInfo = 0;
    SaveUnitId = 0;
    SaveURI = 0;
    SaveREF = 0;
    SaveTRAGETURI = 0;
    SubmitExtn = -1;
    GetPlace = 0;
    Accession = 0;
    Security = 0;
    SSLFlg = 0;
    On_Save = 0;
    SSL_Next_STS = 0;
    GET_HEAD_SESSIONID = 0;
    GET_HEAD_STOP = 0;
    LAYOUT_STOP = 0;
    UPDATE_TYPE = 0;
    buf_ps_evt = 0;
    buf_ps_sts = 0;
    memset(&buf_ps_errinf, 0, 0x80U);
    buf_sessionID = 0;
    buf_sessionURL = 0;
    save_sessionURL = 0;
    buf_sessionstop = 0;
    save_sessionstop = 0;
    before_ps_sts = 0;
    buf_Message_cnt = 0;
    buf_Loding_Stop_FLG = 0;
    buf_Message_Show_FLG = 0;
    COMPULSION_END_FLG = 0;
    SAVE_STOP = 0;
    RELOAD_FLG = 0;
    CHARSET_CODE = 0;
    RECIEVE_MSG = 0;
    DOCUMENT_WRITE = 0;
    PS_LOCATION_HEAD = 0;
    CONTENT_SAVE = 0;
    CONTENT_GETTMEP = 0;
    CONTENT_GETCNT = -1;
    NOTARGET = 0;
    REQ_FAILD = 0;
    GET_HEAD_STAT = 0;
    ContntHeader = 0;
    DOM_NODE_MAX_SIZE = 0;
    AuthDialogCancel = 0;
    PageGetType = 0;
    psCacheMode = 0;
    gpsCntxtTable = 0;
    ps_initExMsgBoxList();
    M2C_FIELD(&EX_MSG_BOX_NO, int *, 0) = 0;
    M2C_FIELD(&EX_MSG_BOX_NO, int *, 4) = 0;
    M2C_FIELD(&EX_MSG_BOX_NO, int *, 0) = ps_createExMsgBox();
    M2C_FIELD(&EX_MSG_BOX_NO, int *, 4) = ps_createExMsgBox();
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135260);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135380);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_getsend);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001353B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001353E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001353FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135408);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_LocationGetSend);

void ps_rflagclr(void) {
    int i;
    void *n;

    for (i = 1; i < 7; i++) {
        while ((n = HST_searchRequestFlagHistoryNode(i)) != NULL) {
            HST_setRequestFlag(n, 0);
        }
    }
}

void ps_save(PsIpc *msg, int sid) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (sid != 0) {
        m.body.x14 = sid;
    }
    if (OS_mq_send(mq_ps_su, &m, sizeof(m), 0) < 0) {
        ps_halt("Parser : cmk_mbox_send(ps_save) failed");
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_Security);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_SaveName);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001354B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001354E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001354F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_0013557C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ChkContentType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_searchRequestFlagHistoryNode);

void *ps_ExternalSearchSessionParentHistoryNode(void *a, int b) {
    void *head = HST_getHeadHistoryNode();

    if (b == 1) {
        return HST_getParentExtHistoryURI(head, a, D_00135598);
    }
    return HST_getParentExtHistoryURI(head, a, D_0013559C);
}

void *ps_ExternalSearchSessionHistoryNode(void *a, int b) {
    void *head = HST_getHeadHistoryNode();

    if (b == 1) {
        return HST_getExtHistoryURI(head, a, D_00135598);
    }
    return HST_getExtHistoryURI(head, a, D_0013559C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *ps_ExternalSearchRequestFlag(int arg0, int arg1) {
    int temp_a0;

    temp_a0 = HST_getHeadHistoryNode();
    if (arg1 == 1) {
        return HST_searchCSSRequestFlag(temp_a0, arg0);
    }
    return HST_searchJSRequestFlag(temp_a0, arg0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", parseSetAuthData);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135598);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_0013559C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001355A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001355BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001355D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001355F4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_HeadSend);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", cmpstr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", icmpstr);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_PassWordChk(void) {
    return 0;
}

void ps_PassWordSet(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_submit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_postsend);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_postsend_history);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_splitPostData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_UrlsrchNoteToSubmitNote);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135744);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_0013574C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_JSMailBoxClean);

void ps_JSMailBoxfree(void) {
    PsMqMsg m;

    while (GetMQUEUE(mq_js, &m)) {
        buf_ps_evt = m.evt;
        if (m.data != NULL) {
            MEM_free(0, m.data);
        }
    }
}

void ps_MailBoxClean(void) {
    PsMqMsg m;

    while (GetMQUEUE(mq_ps_su, &m)) {
        if (OS_mq_send(mq_ps, &m, sizeof(m), 0) < 0) {
            ps_halt("Parser : cmk_mbox_send(ps_MailBoxClean) failed");
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_ParseDomBuildCall);

void ps_FrontParseDomBuild(void) {
    PsDomBuild b;
    void *r;

    b.x[0] = 0;
    b.x[1] = 0;
    b.x[2] = 0;
    b.x[3] = 0;
    b.x[4] = 0;
    b.x[5] = 0;
    b.x[6] = 0;
    b.x[7] = 0;
    b.x[9] = 0;
    b.x[11] = 0;
    b.x[12] = 8;
    b.x[13] = 0;
    r = parseDomBuild(&b);
    if (r != NULL) {
        MEM_free(0, r);
    }
}

void ps_BackParseDomBuild(void) {
    PsDomBuild b;
    void *r;

    b.x[0] = 0;
    b.x[1] = 0;
    b.x[2] = 0;
    b.x[3] = 0;
    b.x[4] = 0;
    b.x[5] = 0;
    b.x[6] = 0;
    b.x[7] = 0;
    b.x[9] = 0;
    b.x[11] = 0;
    b.x[12] = 9;
    b.x[13] = 0;
    r = parseDomBuild(&b);
    if (r != NULL) {
        MEM_free(0, r);
    }
}

void ps_ParseDomBuildFree(void) {
    PsDomBuild b;
    void *r;

    b.x[0] = 0;
    b.x[1] = 0;
    b.x[2] = 0;
    b.x[3] = 0;
    b.x[4] = 0;
    b.x[5] = 0;
    b.x[6] = 0;
    b.x[7] = 0;
    b.x[9] = 0;
    b.x[11] = 0;
    b.x[12] = 12;
    b.x[13] = 0;
    r = parseDomBuild(&b);
    if (r != NULL) {
        MEM_free(0, r);
    }
}

int ps_SendIOMChk(int n, char *s) {
    int i;

    for (i = 0; i < n; i++) {
        if (icmpstr(s + i, "#", 1) == 1) {
            return i;
        }
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_Terminate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_SetLocation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_GetLocation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_FreeLocation);

void ps_DomTerm(int sid) {
    PsDomBuild b;
    PsIpc m;
    int *node;
    void *r;

    node = HST_searchSessionIDHistoryNode(sid);
    b.x[0] = node[1];
    b.x[1] = node[0];
    b.x[2] = node[5];
    b.x[3] = node[4];
    b.x[4] = node[7];
    b.x[5] = node[6];
    b.x[6] = 0;
    b.x[7] = 0;
    b.x[9] = sid;
    b.x[10] = 0;
    b.x[11] = 2;
    b.x[12] = 0;
    b.x[13] = Accession;
    r = parseDomBuild(&b);
    if (r != NULL) {
        MEM_free(0, r);
    }
    initMPL_REQ_LOAD_PAGE(&m);
    m.x04 = sid;
    ps_sndmsg(&m, 4);
}

int ps_isMoveHistory(int off, int sid, int local) {
    PsIpc m;

    if (off == 0) {
        return 1;
    }
    if (HST_getFragmentIDs(HST_getHeadHistoryNode(), off) != 0) {
        return 1;
    }
    if (off != 0 && HST_getHistoryWithOffset(off) != 0) {
        return 1;
    }
    m.type = 0;
    m.x04 = 0;
    m.x08 = 0;
    m.cmd = 0;
    m.x10 = 0;
    m.x14 = 0;
    m.x18 = 0;
    m.x1C = 0;
    initMPU_SIG_RECV_COMPLETE(&m);
    m.x04 = sid;
    m.x10 = -1;
    m.x14 = local;
    ps_sndmsg(&m, 1);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_fragmentJump);

int ps_isGetRequest(void *node) {
    char *uri, *u;

    if (node == NULL || (uri = HST_getCurURI(node)) == NULL) {
        return 0;
    }
    while ((node = HST_getParentHistoryNode(node)) != NULL) {
        u = HST_getCurURI(node);
        if (u != NULL && strcmp(uri, u) == 0) {
            return 0;
        }
    }
    return 1;
}

void ps_errStringParseDomBuild(int *node, char *str) {
    PsIpc m;
    PsDomBuild b;
    void *r;

    HST_setRequestFlag(node, 5);
    if (HST_getSessionID(node) == 0) {
        HST_setSessionID(node, ps_sessionGen());
    }
    memset(&b, 0, sizeof(b));
    b.x[0] = node[1];
    b.x[1] = node[0];
    b.x[2] = node[5];
    b.x[3] = node[4];
    b.x[4] = node[7];
    b.x[5] = node[6];
    b.x[6] = strlen(str);
    b.x[7] = (int)str;
    b.x[9] = HST_getSessionID(node);
    b.x[11] = 0;
    b.x[12] = 0;
    b.x[13] = Accession;
    r = parseDomBuild(&b);
    if (r != NULL) {
        MEM_free(0, r);
    }
    initMPL_REQ_LOAD_PAGE(&m);
    m.x04 = HST_getSessionID(node);
    ps_sndmsg(&m, 4);
    m.x10 = 1;
    ps_sndmsg(&m, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_initExMsgBoxList(void) {
    exMsgBoxList.count = 0;
    exMsgBoxList.first = NULL;
    exMsgBoxList.last = NULL;
    return 1;
}

int ps_deleteExMsgBoxList(void) {
    ExMsgBox *b, *next;

    for (b = exMsgBoxList.first; b != NULL; b = next) {
        next = b->next;
        ps_deleteExMsgBox(b->id);
    }
    ps_initExMsgBoxList();
    return 1;
}

int ps_createExMsgBox(void) {
    ExMsgBox *b = MEM_malloc(0, sizeof(ExMsgBox));

    if (b == NULL) {
        return -1;
    }
    b->id = 0;
    b->x04 = NULL;
    b->x08 = NULL;
    b->x0C = NULL;
    b->prev = NULL;
    b->next = NULL;
    b->id = ++exMsgBoxList.count;
    if (exMsgBoxList.last != NULL) {
        exMsgBoxList.last->next = b;
        b->prev = exMsgBoxList.last;
    }
    exMsgBoxList.last = b;
    if (exMsgBoxList.first == NULL) {
        exMsgBoxList.first = b;
    }
    return b->id;
}

int ps_deleteExMsgBox(int id) {
    ExMsgBox *b;
    ExMsgBox *n;

    b = ps_getExMsgBox(id);
    if (b == NULL) {
        return 0;
    }
    ps_freeExMsgBox(id);
    if (b->prev != NULL) {
        b->prev->next = b->next;
    } else {
        n = b->next;
        exMsgBoxList.first = n;
        if (n != NULL) {
            n->prev = NULL;
        }
    }
    if (b->next != NULL) {
        b->next->prev = b->prev;
    } else {
        exMsgBoxList.last = b->prev;
        if (exMsgBoxList.first != NULL) {
            exMsgBoxList.first->next = NULL;
        }
    }
    MEM_free(0, b);
    return 1;
}

ExMsgBox *ps_getExMsgBox(int id) {
    ExMsgBox *b;

    for (b = exMsgBoxList.first; b != NULL; b = b->next) {
        if (b->id == id) {
            return b;
        }
    }
    return NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_freeExMsgBox(int id) {
    int var_v0;
    void *temp_a1;
    void *temp_s1;
    void *temp_v0;
    void *var_s0;

    temp_v0 = ps_getExMsgBox(id);
    var_v0 = 0;
    if (temp_v0 != NULL) {
        var_s0 = M2C_FIELD(temp_v0, void **, 8);
        if (var_s0 != NULL) {
            do {
                temp_a1 = M2C_FIELD(M2C_FIELD(var_s0, void **, 0), void **, 0x1C);
                temp_s1 = M2C_FIELD(var_s0, void **, 8);
                if (temp_a1 != NULL) {
                    MEM_free(0, temp_a1);
                }
                MEM_free(0, M2C_FIELD(var_s0, void **, 0));
                MEM_free(0, var_s0);
                var_s0 = temp_s1;
            } while (temp_s1 != NULL);
        }
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, void **, 8) = NULL;
        M2C_FIELD(temp_v0, int *, 0xC) = 0;
        var_v0 = 1;
    }
    return var_v0;
}

int ps_setExMsg(int id, PsIpc *msg) {
    ExMsgBox *b;
    ExMsgNode *n;

    b = ps_getExMsgBox(id);
    if (b == NULL) {
        return 0;
    }
    n = MEM_malloc(0, sizeof(ExMsgNode));
    if (n == NULL) {
        return 0;
    }
    n->msg = NULL;
    n->prev = NULL;
    n->next = NULL;
    n->msg = MEM_malloc(0, sizeof(PsIpc));
    if (n->msg == NULL) {
        MEM_free(0, n);
        return 0;
    }
    *n->msg = *msg;
    if (b->x0C != NULL) {
        ((ExMsgNode *)b->x0C)->next = n;
        n->prev = b->x0C;
        b->x0C = n;
    } else {
        b->x0C = n;
    }
    if (b->x08 == NULL) {
        b->x08 = n;
    }
    b->x04 = (void *)((int)b->x04 + 1);
    return 1;
}

int ps_setTopExMsg(int id, PsIpc *msg) {
    ExMsgBox *b;
    ExMsgNode *n;

    b = ps_getExMsgBox(id);
    if (b == NULL) {
        return 0;
    }
    n = MEM_malloc(0, sizeof(ExMsgNode));
    if (n == NULL) {
        return 0;
    }
    n->msg = NULL;
    n->prev = NULL;
    n->next = NULL;
    n->msg = MEM_malloc(0, sizeof(PsIpc));
    if (n->msg == NULL) {
        MEM_free(0, n);
        return 0;
    }
    *n->msg = *msg;
    if (b->x08 != NULL) {
        ((ExMsgNode *)b->x08)->prev = n;
        n->next = b->x08;
        b->x08 = n;
    } else {
        b->x08 = n;
    }
    if (b->x0C == NULL) {
        b->x0C = n;
    }
    b->x04 = (void *)((int)b->x04 + 1);
    return 1;
}

int ps_getExMsg(int id, PsIpc *out) {
    ExMsgBox *b;
    ExMsgNode *n;
    ExMsgNode *x;

    out->type = 0;
    out->x04 = 0;
    out->x08 = 0;
    out->cmd = 0;
    out->x10 = 0;
    out->x14 = 0;
    out->x18 = 0;
    out->x1C = 0;
    b = ps_getExMsgBox(id);
    if (b == NULL) {
        return 0;
    }
    if (b->x08 == NULL) {
        return 0;
    }
    n = b->x08;
    x = n->next;
    b->x08 = x;
    if (x == NULL) {
        b->x0C = NULL;
    }
    b->x04 = (void *)((int)b->x04 - 1);
    *out = *n->msg;
    MEM_free(0, n->msg);
    MEM_free(0, n);
    return 1;
}

int ps_getBottomExMsg(int id, PsIpc *out) {
    ExMsgBox *b;
    ExMsgNode *n;
    ExMsgNode *x;

    out->type = 0;
    out->x04 = 0;
    out->x08 = 0;
    out->cmd = 0;
    out->x10 = 0;
    out->x14 = 0;
    out->x18 = 0;
    out->x1C = 0;
    b = ps_getExMsgBox(id);
    if (b == NULL) {
        return 0;
    }
    if (b->x0C == NULL) {
        return 0;
    }
    n = b->x0C;
    x = n->prev;
    b->x0C = x;
    if (x == NULL) {
        b->x08 = NULL;
    }
    b->x04 = (void *)((int)b->x04 - 1);
    *out = *n->msg;
    MEM_free(0, n->msg);
    MEM_free(0, n);
    return 1;
}

int ps_moveExMsgToExMsg(int from, int to, int sid) {
    PsIpc m;

    while (ps_getExMsg(from, &m) == 1) {
        if (sid != 0) {
            m.x04 = sid;
        }
        ps_setExMsg(to, &m);
    }
    return 1;
}

int ps_moveExMsgToTopExMsg(int from, int to, int sid) {
    PsIpc m;

    while (ps_getBottomExMsg(from, &m) == 1) {
        if (sid != 0) {
            m.x04 = sid;
        }
        ps_setTopExMsg(to, &m);
    }
    return 1;
}

int ps_sendAbortPageToDiffHistory(int sid, int local, void *node) {
    PsIpc m;
    int sent;
    int s;
    int *n;

    initMPL_REQ_ABORT_PAGE(&m);
    m.x10 = local;
    m.x14 = sid;
    sent = 0;
    s = 0;
    while ((s = HST_diffHistoryNodes(node, s)) != 0) {
        n = HST_searchSessionIDHistoryNode(s);
        if (n == NULL) {
            ps_halt("Parser : ps_sendAbortPageToDiffHistory\n");
            return 0;
        }
        if (n[27] == 0) {
            continue;
        }
        if (HST_getRequestFlag(n) < 0) {
            continue;
        }
        m.x04 = s;
        ps_sndmsg(&m, 4);
        HST_setRequestFlag(n, 8);
        sent = 1;
    }
    return sent != 0;
}

int ps_sendAbortPage(int sid, int a, int b, int name, int len) {
    void *node;

    if (len != 0 && (node = HST_searchTargetNameHistoryNode(name, len)) != NULL && HST_getHeadHistoryNode() != node) {
        sid = HST_getSessionID(node);
    }
    setParseMassageToDestTask(4, sid, 0, 0x304, b, a, 0, 0);
    return 1;
}

void ps_sendGetStop(PsIpc *m) {
    int i;
    int *n;

    for (i = 1; i < 7; i++) {
        HST_searchRequestFlagHistoryNode(i);
        while ((n = HST_searchRequestFlagHistoryNode(i)) != NULL) {
            m->x14 = 0;
            m->x04 = HST_getSessionID(n);
            if (m->x04 == 0) {
                ps_halt("HST_getSessionID failed");
            }
            ps_sndmsg(m, 5);
            n[15] = 8;
        }
        while ((n = ps_ExternalSearchRequestFlag(i, 1)) != NULL) {
            m->x14 = 1;
            m->x04 = HST_getSessionID(n);
            if (m->x04 == 0) {
                ps_halt("HST_getSessionID failed");
            }
            ps_sndmsg(m, 5);
            n[15] = 8;
        }
        while ((n = ps_ExternalSearchRequestFlag(i, 2)) != NULL) {
            m->x14 = 2;
            m->x04 = HST_getSessionID(n);
            if (m->x04 == 0) {
                ps_halt("HST_getSessionID failed");
            }
            ps_sndmsg(m, 5);
            n[15] = 8;
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPI_SIG_REQUEST_ABORTED(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 4;
    M2C_FIELD(arg0, int *, 0x10) = 1;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPL_REQ_ABORT_PAGE(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0x304;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPU_SIG_RECV_COMPLETE(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 5;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPU_SIG_LAYOUT_COMPLETE(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 6;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPU_SIG_RECV_STARTED(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 3;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPU_RPL_LOAD_PAGE(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 2;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initMPL_REQ_LOAD_PAGE(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 2;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0x303;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int initMPU_REQ_SHOW_DIALOG(void *arg0, int arg1) {
    int *temp_v0;
    int var_v0;

    temp_v0 = MEM_malloc(0, 4);
    var_v0 = 0;
    if (temp_v0 != NULL) {
        *temp_v0 = arg1;
        M2C_FIELD(arg0, int *, 0) = 2;
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0xE;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        M2C_FIELD(arg0, int *, 0x14) = 0;
        M2C_FIELD(arg0, int *, 0x18) = 4;
        M2C_FIELD(arg0, int **, 0x1C) = temp_v0;
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", initMPU_SIG_EXTDATA_SELECTED);

void sendStart(PsIpc *a, PsIpc *b, int *data) {
    initMPU_RPL_LOAD_PAGE(a);
    a->x04 = buf_sessionUI;
    a->x14 = buf_localUI;
    a->x18 = data[0] + 4;
    a->x1C = (int)data;
    ps_sndmsg(a, 1);
    initMPU_SIG_RECV_STARTED(b);
    b->x04 = buf_sessionUI;
    b->x14 = buf_localUI;
    ps_sndmsg(b, 1);
}

void sendComplete(PsIpc *m) {
    initMPU_SIG_LAYOUT_COMPLETE(m);
    m->x04 = buf_sessionUI;
    m->x14 = buf_localUI;
    ps_sndmsg(m, 1);
    initMPU_SIG_RECV_COMPLETE(m);
    m->x04 = buf_sessionUI;
    m->x14 = buf_localUI;
    ps_sndmsg(m, 1);
}

void sendMPL_REQ_LOAD_PAGE(PsIpc *m, int sid) {
    initMPL_REQ_LOAD_PAGE(m);
    m->x04 = sid;
    ps_sndmsg(m, 4);
    initMPL_REQ_LOAD_PAGE(m);
    m->x04 = sid;
    m->x10 = 1;
    ps_sndmsg(m, 4);
}

void initMSGQUEUE(int q) {
    PsMqMsg m;
    int attr[4];

    for (;;) {
        OS_mq_getattr(q, attr);
        attr[0] |= 0x4000;
        OS_mq_setattr(q, attr, 0);
        if (OS_mq_receive(q, &m, 0x24, 0) < 0) {
            attr[0] &= ~0x4000;
            OS_mq_setattr(q, attr, 0);
            return;
        }
        attr[0] &= ~0x4000;
        OS_mq_setattr(q, attr, 0);
    }
}

void *GetMQUEUE(int q, void *buf) {
    int attr[4];

    OS_mq_getattr(q, attr);
    attr[0] |= 0x4000;
    OS_mq_setattr(q, attr, 0);
    if (OS_mq_receive(q, buf, 0x24, 0) < 0) {
        attr[0] &= ~0x4000;
        OS_mq_setattr(q, attr, 0);
        return NULL;
    }
    attr[0] &= ~0x4000;
    OS_mq_setattr(q, attr, 0);
    return buf;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", CharEncode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", Encoding);

void ps_saveCacheMode(int m) {
    switch (m) {
    case 1:
        psCacheMode = 1;
        break;
    case 2:
        psCacheMode = 2;
        break;
    case 3:
        psCacheMode = 3;
        break;
    case 0:
        psCacheMode = 0;
        break;
    default:
        psCacheMode = 0;
        break;
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", tbl_psfunc);
