/* cflags: -O1 */
#include "common.h"
#include <ctype.h>
#include "parse_hist.h"
#include "parse_ps.h"
#include "dom_domi.h"
#include "m2c_macros.h"
extern PsLocation *PS_LOCATION_HEAD;
extern PsLocation *D_0025B5CC;
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



typedef struct PSNAME { unsigned int len; char *name; } PSNAME;
int strncmp(const char *a, const char *b, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
typedef struct PSDATA { int pad[2]; unsigned int len; char *data; } PSDATA;
typedef struct PSREQ { int pad[4]; int hist; int pad2[2]; PSDATA *d; } PSREQ;
int HST_getHistoryWithOffset(int off);
unsigned int HST_getCurURIlen(int h);
char *HST_getCurURI(int h);
int icmpstr(char *a, char *b, int n);
typedef struct PREFUI { int pad[3]; int enc; } PREFUI;
extern PREFUI *gPREF_UI;
typedef struct ENCDOC { int pad[17]; int type; int pad2[6]; int charset; } ENCDOC;
int CharEncode();
typedef struct CEDOC { int pad[4]; char *cs; } CEDOC;
int cmpstr(char *a, char *b);
char *strcpy(char *d, const char *s);
typedef struct SIGEXT { char *a; char *b; char *c; int d; } SIGEXT;
typedef struct MPUSIG { int type; int x4; int x8; int xC; int x10; int x14; int size; SIGEXT *data; } MPUSIG;
typedef struct CTYPE { char name[20]; int len; int type; } CTYPE;
int ps_i2208(PsIpc *msg);
int ps_i2308(PsIpc *msg);
int ps_i2406(PsIpc *msg);
int ps_i2608(PsIpc *msg);
int ps_i2906(PsIpc *msg);
int ps_i2D06(PsIpc *msg);
PsLocation *ps_GetLocation(int id);
extern PsLocation *D_0025B5C8;
typedef struct UrlNote { char *p; char *q; int plen; int qlen; } UrlNote;
typedef struct UrlHist { int pad[25]; UrlNote *note; } UrlHist;
typedef struct PsNote { int pad[2]; int len1; char *p1; int len2; char *p2; int len3; char *p3; } PsNote;
typedef struct SubmitNote { unsigned short x0; int method; int x8; int len1; char *p1; int len2; char *p2; int len3; char *p3; int len4; char *p4; } SubmitNote;
extern char D_0013574C[];
void *MEM_calloc(int, unsigned int);
int HST_getMethodType(void *h);
typedef struct PsFatal { int code; char *msg; } PsFatal;
extern PsFatal *FATAL_ERR_MSG;
extern PsMqMsg COMPULSION_END;
extern int jsapi_lock;
int ps_u0103(PsIpc *msg);
int ps_l1105(PsIpc *msg);
int ps_i2104(PsIpc *msg);
typedef struct PsUri { int len; char *p; } PsUri;
extern PsUri *SaveTRAGETURI_p __asm__("SaveTRAGETURI");
extern SubmitNote *RECIEVE_MSG_p __asm__("RECIEVE_MSG");
void ps_freeRecvInfo(void);
int UTL_guessMIMETypeFromName(char *name);
void ps_HeadSend(int len1, char *p1, int len2, char *p2, int a, int b, int id);
void ps_postsend(int len1, char *p1, int len2, char *p2, int a, int hdrlen, char *hdr, int bodylen, char *body, int z, int id);
char *strcat(char *d, const char *s);
unsigned short UDomiString_ToLower(unsigned short c) {
    if (c < 0x80) {
        return tolower(c);
    }
    return c;
}

unsigned short UDomiString_ToUpper(unsigned short c) {
    if (c < 0x80) {
        return toupper(c);
    }
    return c;
}

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

const char GIF87[6] = "GIF87a";
const char GIF89[6] = "GIF89a";
const unsigned char JPEG[3] = { 0xFF, 0xD8, 0xFF };
const unsigned char PNG[8] = { 0x89, 'P', 'N', 'G', 0x0D, 0x0A, 0x1A, 0x0A };
int memcmp(const void *a, const void *b, unsigned int n);

int sortImage(unsigned char *p, int len) {
    int ret = -1;

    if (p != NULL & len > 0) {
        switch (*p) {
        case 0x47:
            if (len >= 6) {
                if (memcmp(p, GIF87, 6) == 0)
                    ret = 1;
                else if (memcmp(p, GIF89, 6) == 0)
                    ret = 1;
            }
            break;
        case 0xFF:
            if (len >= 3) {
                if (memcmp(p, JPEG, 3) == 0)
                    ret = 2;
            }
            break;
        case 0x89:
            if (len >= 8) {
                if (memcmp(p, PNG, 8) == 0)
                    ret = 4;
            }
            break;
        }
    }
    return ret;
}

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

int ps_transmit(int *m) {
    int ret = buf_ps_sts;
    int i;
    PsTbl *p;
    int dest;
    int x;
    if (m == NULL) {
        return ret;
    }
    for (i = 0;; i++) {
        if (D_00135260[i].cmd == -1) {
            return ps_dmyskip(m);
        }
        p = &D_00135260[i];
        if (p->cmd == m[3]) {
            dest = p->dest;
            x = p->x04;
            if (p->sts != -1) {
                ret = p->sts;
            }
            setParseMassageToDestTask(dest, m[1], m[2], x, m[4], m[5], m[6], m[7]);
            return ret;
        }
    }
}

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

int ps_Security(PSREQ *req) {
    unsigned int *buf;
    char *s;
    int h;
    unsigned int len;
    PSDATA *d;

    if (req->hist != 0) {
        h = HST_getHistoryWithOffset(req->hist);
        if (h == 0)
            return 2;
        len = HST_getCurURIlen(h);
        buf = (unsigned int *)MEM_malloc(0, len + 4);
        if (buf == NULL)
            ps_halt("Parser : (char*)E_malloc(ps_u0203) failed\n");
        buf[0] = len;
        memcpy(buf + 1, HST_getCurURI(h), buf[0]);
    } else {
        d = req->d;
        buf = (unsigned int *)MEM_malloc(0, d->len + 4);
        if (buf == NULL)
            ps_halt("Parser : (char*)E_malloc(ps_u0203) failed");
        buf[0] = d->len;
        memcpy(buf + 1, d->data, d->len);
    }
    s = (char *)MEM_malloc(0, 9);
    memset(s, 0, 9);
    memcpy(s, buf + 1, 8);
    if (icmpstr(s, "https://", 8) == 1) {
        MEM_free(0, buf);
        MEM_free(0, s);
        return 1;
    }
    MEM_free(0, buf);
    MEM_free(0, s);
    return 0;
}

void ps_SaveName(int len, char *path, PSNAME *n) {
    int i;
    int found = 0;

    n->len = 0;
    for (i = len; i > 0; i--) {
        if (strncmp(&path[i], "/", 1) == 0) {
            n->len = len - i - 1;
            found = 1;
            break;
        }
    }
    if (found == 1 && n->len != 0) {
        n->name = (char *)MEM_malloc(0, n->len + 1);
        memset(n->name, 0, n->len + 1);
        if (n == NULL)
            ps_halt("Parser : (char*)E_malloc(ps_u0203) failed");
        memcpy(n->name, path + i + 1, n->len);
    } else {
        n->len = 0;
        n->name = NULL;
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_001354F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_0013557C);

extern char D_0013557C[];
typedef struct CTYPETBL { CTYPE t[5]; } CTYPETBL;
/* D_001354F0 = the initializer of ChkContentType's local table: {"text/html",9,0}, {"text/plain",10,2},
   {"image/jpeg",10,3}, {"image/gif",9,3}, {"image/png",9,3}; it has to stay before "Content-Type:", which
   ps_splitPostData (asm) shares */
extern const CTYPETBL D_001354F0;
int ChkContentType(char *p, int len) {
    CTYPETBL tbl = D_001354F0;
    int i;
    int n;

    n = len;
    for (;;) {
        if (n < 13) {
            p = "text/html";
            break;
        }
        if (icmpstr(p, D_0013557C, 13) == 1) {
            p += 13;
            while (*p == ' ')
                p++;
            break;
        }
        p++;
        n--;
    }
    for (i = 0; i < 5; i++) {
        if (icmpstr(p, tbl.t[i].name, tbl.t[i].len) == 1)
            return tbl.t[i].type;
    }
    return 4;
}

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

int cmpstr(char *a, char *b) {
    while (*a != 0 && ((*b != '\r') & (*b != '\n'))) {
        if ((char)((u8)(*a - 'a') < 26 ? *a & ~0x20 : *a) != (char)((u8)(*b - 'a') < 26 ? *b & ~0x20 : *b)) {
            return 0;
        }
        a++;
        b++;
    }
    return 1;
}

int icmpstr(char *a, char *b, int n) {
    int i = 0;
    while (*a != 0 && ((*b != '\r') & (*b != '\n'))) {
        if ((char)((u8)(*a - 'a') < 26 ? *a & ~0x20 : *a) != (char)((u8)(*b - 'a') < 26 ? *b & ~0x20 : *b)) {
            return 0;
        }
        i++;
        if (i == n) {
            return 1;
        }
        a++;
        b++;
    }
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_PassWordChk(void) {
    return 0;
}

void ps_PassWordSet(void) {
}

int ps_submit(PsIpc *msg) {
    SubmitNote *n;
    char *ext;
    PsIpc sig;
    char *hdr;
    int hdrlen;
    char *body;
    int bodylen;

    buf_sessionUI = msg->x04;
    buf_localUI = msg->x14;
    ps_freeRecvInfo();
    n = (SubmitNote *)msg->x1C;
    SubmitExtn = -1;
    ext = MEM_malloc(0, n->len1 + 1);
    if (ext != NULL) {
        memcpy(ext, n->p1, n->len1);
        ext[n->len1] = 0;
        SubmitExtn = UTL_guessMIMETypeFromName(ext);
        MEM_free(0, ext);
    }
    switch (n->method) {
    case 0:
        ps_HeadSend(n->len1, n->p1, n->len2, n->p2, 0, 0, n->x8);
        break;
    case 1:
        bodylen = 0;
        hdrlen = 0;
        body = NULL;
        hdr = NULL;
        ps_splitPostData(n->p4, n->len4, &hdr, &hdrlen, &body, &bodylen);
        ps_postsend(n->len1, n->p1, n->len2, n->p2, 0, hdrlen, hdr, bodylen, body, 0, n->x8);
        if (hdr != NULL)
            MEM_free(0, hdr);
        if (body != NULL)
            MEM_free(0, body);
        break;
    default:
        ps_halt("ps_submit (PS_SUBMIT_NODE_type_ERROR) failed.");
        MEM_free(0, msg->x1C);
        return buf_ps_sts;
    }
    SaveUnitId = n->x8;
    PageGetType = 1;
    Accession = 0;
    GetPlace = 0;
    UPDATE_TYPE = n->x0;
    SaveTRAGETURI_p = MEM_malloc(0, n->len3 + 8);
    if (SaveTRAGETURI_p == NULL)
        ps_halt("Parser : (char*)E_malloc(ps_submit) failed");
    SaveTRAGETURI_p->len = n->len3;
    if (n->len3 != 0) {
        SaveTRAGETURI_p->p = (char *)SaveTRAGETURI_p + 8;
        memcpy(SaveTRAGETURI_p->p, n->p3, n->len3);
    }
    if (RECIEVE_MSG_p != NULL)
        MEM_free(0, RECIEVE_MSG_p);
    RECIEVE_MSG_p = n;
    initMPU_SIG_RECV_STARTED(&sig);
    sig.x14 = buf_localUI;
    sig.x04 = buf_sessionUI;
    ps_sndmsg(&sig, 1);
    return 20;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_postsend);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_postsend_history);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", ps_splitPostData);

SubmitNote *ps_UrlsrchNoteToSubmitNote(UrlHist *h, PsNote *n) {
    SubmitNote *s;
    char *p;
    int plen, qlen, total;
    char *pp, *qp;
    int m;

    if (h == NULL || n == NULL)
        return NULL;
    qlen = 0;
    plen = 0;
    total = 0;
    qp = NULL;
    pp = NULL;
    if (h->note != NULL) {
        plen = h->note->plen;
        qlen = h->note->qlen;
        pp = h->note->p;
        qp = h->note->q;
        if (plen > 0 && qlen > 0)
            total = plen + qlen + 4;
        else
            total = plen + qlen;
    }
    s = MEM_calloc(0, n->len1 + n->len2 + n->len3 + total + 0x30);
    if (s == NULL)
        return NULL;
    p = (char *)(s + 1);
    s->x0 = 0;
    s->method = 0;
    m = HST_getMethodType(h);
    if (m == 1)
        s->method = m;
    if (n->len1 > 0) {
        s->len1 = n->len1;
        s->p1 = p;
        memcpy(p, n->p1, n->len1);
        p += n->len1 + 1;
    }
    if (n->len2 > 0) {
        s->len2 = n->len2;
        s->p2 = p;
        memcpy(p, n->p2, n->len2);
        p += n->len2 + 1;
    }
    if (n->len3 > 0) {
        s->len3 = n->len3;
        s->p3 = p;
        memcpy(p, n->p3, n->len3);
        p += n->len3 + 1;
    }
    if (total > 0) {
        s->len4 = total;
        s->p4 = p;
        if (plen > 0) {
            memcpy(p, pp, plen);
            p += plen;
        }
        if (qlen > 0) {
            if (plen > 0) {
                memcpy(p, D_0013574C, 4);
                p += 4;
            }
            memcpy(p, qp, qlen);
        }
    }
    return s;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_00135744);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/UDomiString", D_0013574C);

int ps_JSMailBoxClean(void) {
    PsMqMsg m;
    int ret;
    int flag;

    flag = 0;
    buf_ps_sts = 200;
    ret = 200;
    while (GetMQUEUE(mq_js, &m)) {
        buf_ps_evt = m.evt;
        switch (m.evt) {
        case 0x24:
        case 0x25:
            ret = ps_i2406((PsIpc *)&m.x[1]);
            break;
        case 0x26:
            ret = ps_i2608((PsIpc *)&m.x[1]);
            break;
        case 0x23:
            ret = ps_i2308((PsIpc *)&m.x[1]);
            if (ret == 0x12 || ret == 0x1A)
                return ret;
            if (ret == 7)
                flag = 1;
            break;
        case 0x22:
            ret = ps_i2208((PsIpc *)&m.x[1]);
            flag = 1;
            break;
        case 0x29:
            ret = ps_i2906((PsIpc *)&m.x[1]);
            break;
        case 0x2D:
            ret = ps_i2D06((PsIpc *)&m.x[1]);
            break;
        default:
            if (m.data != NULL)
                MEM_free(0, m.data);
            ps_halt("ps_l1B12(illegal Message!) failed\n");
            break;
        }
        if (ret == 0x12) {
            buf_ps_sts = ret;
            return 0x12;
        }
        if (ret == 0x1A) {
            buf_ps_sts = ret;
            return 0x1A;
        }
    }
    if (flag == 1)
        buf_ps_sts = 7;
    else
        buf_ps_sts = 8;
    return buf_ps_sts;
}

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

int ps_ParseDomBuildCall(PsIpc *msg) {
    PsDomBuild b;
    PsIpc m;
    PsIpc m2;
    int *node;
    PsDomResult *r;
    int ret;
    PsDomResult *d;
    void *u;
    int mode;

    ret = 0;
    node = HST_searchSessionIDHistoryNode(msg->x04);
    if (node == NULL) {
        if (msg->x18 != 0) {
            MEM_free(0, (void *)msg->x1C);
        }
        return ret;
    }
    b.x[0] = node[1];
    b.x[1] = node[0];
    b.x[2] = node[5];
    b.x[3] = node[4];
    b.x[4] = node[7];
    b.x[5] = node[6];
    b.x[6] = 0;
    b.x[7] = 0;
    b.x[9] = msg->x04;
    b.x[10] = 0;
    Encoding(node, 0, &b.x[10]);
    b.x[11] = 1;
    b.x[12] = 0;
    b.x[13] = Accession;
    r = parseDomBuild(&b);
    initMPL_REQ_LOAD_PAGE(&m);
    m.x04 = msg->x04;
    ps_sndmsg(&m, 4);
    switch (r->type) {
    case 0:
        break;
    case 1:
        d = MEM_malloc(0, r->len * 2 + 0xC);
        if (d == NULL) {
            ps_halt("(char*)E_malloc(ps_i2406) failed");
        }
        d->len = r->len;
        d->data = (char *)d + 0xC;
        memcpy(d->data, r->data, r->len * 2);
        d->type = node[0x68 / 4];
        MEM_free(0, r->data);
        m2.type = 2;
        m2.x04 = msg->x04;
        m2.x08 = 1;
        m2.cmd = 0x30B;
        m2.x10 = 0;
        m2.x14 = 0;
        m2.x18 = r->len * 2 + 0xC;
        m2.x1C = (int)d;
        ps_sndmsg(&m2, 4);
        ret = 0x12;
        break;
    case 2:
        u = HST_getJSURI(node, HST_getJSURIlen(node));
        if (u == NULL) {
            ps_halt("ExternalHistory = NULL\n");
        }
        mode = 2;
        if (node[0x30 / 4] != 1) {
            mode = psCacheMode;
        }
        ps_getsend(u, mode, 3, r);
        ret = 0x1A;
        break;
    case 3:
        u = HST_getCSSURI(node, HST_getCSSURIlen(node));
        if (u == NULL) {
            ps_halt("ExternalHistory = NULL\n");
        }
        mode = 2;
        if (node[0x30 / 4] != 1) {
            mode = psCacheMode;
        }
        ps_getsend(u, mode, 1, NULL);
        ret = 0x1A;
        break;
    default:
        ps_halt("ps_i2406(parseDomBuild) failed.");
        break;
    }
    if (r != NULL) {
        MEM_free(0, r);
    }
    return ret;
}

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

void ps_Terminate(void) {
    PsMqMsg m;
    int attr[4];
    int done;
    PsFatal *e;

    COMPULSION_END.x[1] = 2;
    COMPULSION_END.x[2] = 0;
    COMPULSION_END.x[3] = 0;
    COMPULSION_END.evt = 0xFFFF;
    COMPULSION_END.x14[0] = 0;
    COMPULSION_END.x14[1] = 0;
    COMPULSION_END.x14[2] = 0;
    COMPULSION_END.data = NULL;
    e = FATAL_ERR_MSG;
    done = 0;
    if (e != NULL) {
        FATAL_ERR_MSG = NULL;
        e->code = -1;
        e->msg = "AllocationError(PS)";
        COMPULSION_END.x14[2] = 50;
        COMPULSION_END.data = e;
    }
    OS_mq_send(mq_ui, &COMPULSION_END, 0x24, 0);
    COMPULSION_END_FLG = 1;
    if (jsapi_lock != 0)
        OS_thread_mutex_unlock(jsapi_lock);
    OS_mq_getattr(mq_ps, attr);
    attr[0] &= ~0x4000;
    OS_mq_setattr(mq_ps, attr, 0);
    for (;;) {
        OS_mq_receive(mq_ps, &m, 0x24, 0);
        buf_ps_evt = m.evt;
        if (m.x[1] == 10) {
            m.x[1] = 5;
            OS_mq_send(mq_iom, &m, 0x24, 0);
            continue;
        }
        switch (buf_ps_evt) {
        case 1:
            if (done == 0)
                buf_ps_sts = ps_u0103((PsIpc *)&m.x[1]);
            done = 1;
            break;
        case 0x11:
            if (buf_ps_sts == 5) {
                buf_ps_sts = ps_l1105((PsIpc *)&m.x[1]);
                OS_mq_close(mq_ps);
                OS_mq_close(mq_ps_su);
                OS_mq_close(mq_ui);
                OS_mq_close(mq_layout);
                OS_mq_close(mq_iom);
                OS_mq_close(mq_js);
                OS_mq_unlink("/tmp/mq_ps");
                OS_mq_unlink("/tmp/mq_ps_su");
                OS_mq_unlink("/tmp/mq_lo");
                OS_mq_unlink("/tmp/mq_iom");
                OS_mq_unlink("/tmp/mq_ps_js");
                OS_thread_exit(NULL);
            }
            break;
        case 0x21:
            if (buf_ps_sts == 4)
                buf_ps_sts = ps_i2104((PsIpc *)&m.x[1]);
            break;
        default:
            if (m.data != NULL)
                MEM_free(0, m.data);
            break;
        }
    }
}

PsLocation *ps_SetLocation(int id, int b, int c, int len, char *url) {
    PsLocation *p;

    D_0025B5C8 = ps_GetLocation(id);
    if (D_0025B5C8 != NULL) {
        D_0025B5C8->id = id;
        D_0025B5C8->x04 = b;
        D_0025B5C8->x08 = c;
        D_0025B5C8->x0C++;
        MEM_free(0, D_0025B5C8->buf);
        D_0025B5C8->buf = MEM_malloc(0, len + 1);
        memset(D_0025B5C8->buf, 0, len + 1);
        memcpy(D_0025B5C8->buf, url, len);
        return D_0025B5C8;
    }
    D_0025B5C8 = PS_LOCATION_HEAD;
    if (PS_LOCATION_HEAD == NULL) {
        D_0025B5C8 = PS_LOCATION_HEAD = MEM_malloc(0, sizeof(PsLocation));
        D_0025B5C8->prev = NULL;
    } else {
        for (;;) {
            if (D_0025B5C8->next == NULL)
                break;
            D_0025B5C8 = D_0025B5C8->next;
        }
        D_0025B5C8->next = MEM_malloc(0, sizeof(PsLocation));
        p = D_0025B5C8;
        D_0025B5C8 = p->next;
        D_0025B5C8->prev = p;
    }
    D_0025B5C8->id = id;
    D_0025B5C8->x04 = b;
    D_0025B5C8->x08 = c;
    D_0025B5C8->x0C = 0;
    D_0025B5C8->next = NULL;
    D_0025B5C8->buf = MEM_malloc(0, len + 1);
    memset(D_0025B5C8->buf, 0, len + 1);
    memcpy(D_0025B5C8->buf, url, len);
    return D_0025B5C8;
}

PsLocation *ps_GetLocation(int id) {
    PsLocation *p;
    if (PS_LOCATION_HEAD == NULL)
        return NULL;
    D_0025B5CC = PS_LOCATION_HEAD;
    if (D_0025B5CC->id == id)
        return D_0025B5CC;
    while (1) {
        p = D_0025B5CC->next;
        if (p == NULL)
            break;
        D_0025B5CC = p;
        if (p->id != id)
            continue;
        return p;
    }
    return NULL;
}

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

int ps_fragmentJump(int off) {
    void *h;
    char **f;
    int len;
    int *buf;
    char *s;
    PsIpc m;
    h = (void *)HST_getHeadHistoryNode();
    if (off != 0 && h != NULL && (f = (char **)HST_getFragmentIDs(h, off)) != NULL) {
    ps_rflagclr();
    len = HST_getCurURIlen((int)h);
    if (f[5] != NULL) {
        len += strlen(f[5]);
    }
    buf = MEM_malloc(0, len + 5);
    buf[0] = len;
    s = (char *)(buf + 1);
    strcpy(s, HST_getCurURI((int)h));
    if (f[5] != NULL) {
        strcat(s, f[5]);
    }
    initMPU_RPL_LOAD_PAGE(&m);
    m.x04 = buf_sessionUI;
    m.x14 = buf_localUI;
    m.x18 = len + 5;
    m.x1C = (int)buf;
    ps_sndmsg(&m, 1);
    m.type = 2;
    m.x04 = HST_getSessionID(h);
    m.x08 = 0;
    m.cmd = 0x311;
    m.x10 = off;
    m.x14 = 0;
    m.x18 = 0;
    m.x1C = 0;
    ps_sndmsg(&m, 4);
    return 1;
    }
    return 0;
}

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

void initMPU_SIG_EXTDATA_SELECTED(MPUSIG *sig, char *a, int alen, char *b, int blen, char *c, int clen, int d) {
    int size;
    SIGEXT *e;
    char *p;

    size = alen + blen + clen + 3 + sizeof(SIGEXT);
    e = (SIGEXT *)MEM_malloc(0, size);
    e->a = NULL;
    e->b = NULL;
    e->c = NULL;
    e->d = 0;
    p = (char *)(e + 1);
    e->a = p;
    if (a != NULL) {
        memcpy(p, a, alen);
        p += alen;
    }
    *p++ = 0;
    e->b = p;
    if (b != NULL) {
        memcpy(p, b, blen);
        p += blen;
    }
    *p++ = 0;
    e->c = p;
    if (c != NULL) {
        memcpy(p, c, clen);
        p += clen;
    }
    *p = 0;
    e->d = d;
    sig->type = 2;
    sig->x4 = 0;
    sig->x8 = 0;
    sig->xC = 10;
    sig->x10 = 0;
    sig->x14 = 0;
    sig->size = size;
    sig->data = e;
}

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

int CharEncode(CEDOC *d) {
    int ret;
    char *s;

    if (d != NULL) {
        ret = 0;
        if (d->cs != NULL) {
            s = (char *)MEM_malloc(0, strlen(d->cs) + 1);
            if (s == NULL)
                return 0;
            strcpy(s, d->cs);
            if (cmpstr(s, "iso-2022-jp") == 1)
                ret = 3;
            else if (cmpstr(s, "euc-jp") == 1)
                ret = 2;
            else if (cmpstr(s, "Shift_JIS") == 1)
                ret = 1;
            else if (cmpstr(s, "UTF-8") == 1)
                ret = 4;
            else if (cmpstr(s, "ISO-8859-1") == 1)
                ret = 5;
            else if (cmpstr(s, "us-ascii") == 1)
                ret = 5;
            else
                ret = 0;
            MEM_free(0, s);
        }
    } else {
        ret = 0;
    }
    return ret;
}

void Encoding(ENCDOC *d, int *flag, int *enc) {
    int cs = d->charset;

    if (gPREF_UI != NULL) {
        if (gPREF_UI->enc != 0) {
            *enc = gPREF_UI->enc;
        } else if (Accession == 1 && RELOAD_FLG == 0) {
            if (d->type == 0)
                *enc = 5;
            else if (d->type == 1)
                *enc = 3;
            else if (d->type == 2)
                *enc = 1;
            else if (d->type == 3)
                *enc = 2;
            else if (d->type == 5)
                *enc = 4;
            else
                *enc = 0;
        } else {
            if (d->type == 100) {
                if (flag != NULL)
                    *flag = 1;
            }
            *enc = CharEncode(cs);
        }
    }
}

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

