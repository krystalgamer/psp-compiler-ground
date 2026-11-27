/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int mq_ps_su;
extern int mq_ps;
extern int Security;
extern int buf_Message_Show_FLG;
PsLocation *ps_SetLocation();
extern int DOCUMENT_WRITE;
extern int LAYOUT_STOP;
extern int buf_Loding_Stop_FLG;
extern int SaveUnitId;
extern int RECIEVE_MSG;
int *ps_ExternalSearchSessionHistoryNode();
int *ps_ExternalSearchSessionParentHistoryNode();
int *HST_getJSURI();
int *HST_getCSSURI();
extern int CONTENT_SAVE;
extern int CONTENT_GETCNT;
extern int CONTENT_GETTMEP;
extern int GET_HEAD_STAT;
extern int GET_HEAD_STOP;
extern int GET_HEAD_SESSIONID;
extern int *ContntHeader;
extern int ContntType;
extern int SubmitExtn;
extern int UPDATE_TYPE;
extern int *SaveTRAGETURI;
extern int NOTARGET;
int *HST_httpHeaderDisassemble();
extern int SSLFlg;
extern int SSL_Next_STS;
extern int Accession;
extern int SaveURI;
extern int SaveREF;
extern int Layout_Cont;
extern int psCacheMode;
extern char D_00137C10[];
int ps_i241A(PsIpc *msg);
extern int buf_sessionUI;
extern int buf_localUI;
extern int SAVE_STOP;
extern int On_Save;
extern void *gPREF_UI;
extern int mq_js;
extern int mq_layout;
extern int LAYOUT_END[9];
extern int before_ps_sts;
extern int buf_Message_cnt;
extern int buf_ps_sts;
M2C_UNK ps_setExMsg(int, int);                      /* extern */
extern int D_00584FB8;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */

M2C_UNK ps_i2314();                                 /* extern */

int strlen(const char *s);
void *memset(void *s, int c, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
extern char D_00137B20[];
extern char D_00137B44[];
extern int AuthDialogCancel;
int *ps_PassWordChk();
int memcmp(const void *a, const void *b, unsigned int n);
extern char D_00137B18[];
extern char D_00137B1C[];
extern char D_00137BF4[];
int ps_i221A();
int *ps_searchRequestFlagHistoryNode();
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137B18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137B1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137B20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137B44);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", ps_i2406);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137BF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137C10);

int ps_i2412(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    if (msg->x14 != 2) {
        m.body = *msg;
        if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
            ps_halt(D_00137C10);
        }
    } else {
        buf_ps_sts = ps_i241A(msg);
    }
    return buf_ps_sts;
}

int ps_i2414(PsIpc *msg) {
    PsIpc m;
    int r;
    int *uri;
    int t;
    int a;
    int ty;

    ps_setExMsg(D_00584FB8, msg);
    if (GET_HEAD_STAT == 0) {
        GET_HEAD_STAT = 1;
        if (ContntHeader != NULL) {
            HST_httpHeaderFree(ContntHeader);
        }
        ContntHeader = HST_httpHeaderDisassemble(msg->x1C, msg->x18);
        ContntType = UTL_guessMIMEType(ContntHeader[3]);
        if (ContntType == -1) {
            ContntType = SubmitExtn;
        }
        SubmitExtn = -1;
        r = ps_i2414_auth(msg);
        if (r != -1) {
            return r;
        }
        if (ContntType != 5 && ContntType != 6 && ContntType != 2 && ContntType != 3 && ContntType != 4) {
            initMPI_SIG_REQUEST_ABORTED(&m);
            m.x04 = GET_HEAD_SESSIONID;
            m.x10 = 0;
            ps_sndmsg(&m, 5);
            return 0x14;
        }
        if (ContntType == 5 || ContntType == 6) {
            a = 0;
            if (GET_HEAD_STOP == 1) {
                ps_freeExMsgBox(D_00584FB8);
                GET_HEAD_STOP = 0;
                return 3;
            }
            ty = (UPDATE_TYPE != 0) ? 2 : 1;
            t = 0;
            uri = SaveTRAGETURI;
            if (uri[0] != 0 && NOTARGET == 0) {
                t = uri[1];
                a = uri[0];
            }
            ps_sendAbortPage(0, 0, ty, t, a);
        }
    }
    return 0x14;
}

int ps_i2414_auth(PsIpc *msg) {
    PsIpc m;
    int pm;
    char *t;
    char *s;
    int pt;
    int pp;
    int size;
    int *pw;
    int *buf;
    char *p;
    int ret;

    pp = 0;
    t = D_00137B20;
    s = D_00137B44;
    AuthDialogCancel = 0;
    if (msg->x10 != 0x191) {
        return -1;
    }
    {
        pt = 3 - ((strlen(t) + 3) & 3);
        pm = 3 - ((strlen(s) + 3) & 3);
        size = strlen(t) + strlen(s) + pt + pm + 0x1C;
        pw = ps_PassWordChk(((int *)SaveURI)[0], ((int *)SaveURI)[1]);
        if (pw != NULL) {
            pp = 3 - ((pw[0] + 3) % 4);
            size += pw[0] + pw[2] + pp;
        }
        buf = MEM_malloc(0, size);
        memset(buf, 0, size);
        buf[0] = 3;
        buf[1] = strlen(t);
        memcpy(&buf[2], t, strlen(t));
        p = (char *)buf + (strlen(t) + pt) + 8;
        *(int *)p = strlen(s);
        memcpy(p + 4, s, strlen(s));
        p = p + (strlen(s) + pm) + 4;
        if (pw != NULL) {
            *(int *)p = pw[0];
            memcpy(p + 4, (void *)pw[1], pw[0]);
            p = p + pw[0] + pp + 4;
            *(int *)p = pw[2];
            memcpy(p + 4, (void *)pw[3], pw[2]);
        } else {
            ((int *)p)[0] = 0;
            ((int *)p)[1] = 0;
        }
        m.type = 2;
        m.x04 = msg->x04;
        m.x08 = 0;
        m.cmd = 0xE;
        m.x10 = 0;
        m.x14 = 0x80000001;
        m.x18 = size;
        m.x1C = (int)buf;
        ps_sndmsg(&m, 1);
        before_ps_sts = 0x14;
        buf_Message_cnt++;
        if (pw != NULL) {
            MEM_free(0, pw);
        }
    }
    return 0x13;
}

int ps_i241A(PsIpc *msg) {
    PsIpc m;
    PsIpc m1;
    PsDomBuild b;
    char crlf2[4];
    char lf2[2];
    struct {
        int x00;
        PsIpc body;
    } q;
    int ret;
    int *ext;
    int *node;
    PsDomResult *r;
    PsDomResult *d;
    int len;
    int i;
    int mode;
    int *n;

    memcpy(crlf2, D_00137B18, 4);
    memcpy(lf2, D_00137B1C, 2);
    ret = 0;
    if (msg->x14 == 0) {
        q.body = *msg;
        if (OS_mq_send(mq_js, &q, sizeof(q), 0) < 0) {
            ps_halt(D_00137C10);
        }
        return buf_ps_sts;
    }
    if (msg->x10 != 200) {
        return ps_i221A(msg);
    }
    if (msg->x10 == 401) {
        return ps_JSMailBoxClean();
    }
    ext = ps_ExternalSearchSessionHistoryNode(msg->x04, msg->x14);
    if (ext == NULL) {
        ps_halt("ExternalHistory NULL\n");
    }
    HST_setRequestFlag(ext, 3);
    node = ps_ExternalSearchSessionParentHistoryNode(msg->x04, msg->x14);
    if (node == NULL) {
        ps_halt("sessrch_p NULL\n");
    }
    b.x[0] = node[1];
    b.x[1] = node[0];
    b.x[2] = node[5];
    b.x[3] = node[4];
    b.x[4] = node[7];
    b.x[5] = node[6];
    b.x[9] = node[0x48 / 4];
    b.x[11] = 1;
    b.x[13] = Accession;
    len = msg->x18;
    for (i = 0; i < msg->x18 - 3; i++) {
        if (memcmp((char *)msg->x1C + i, crlf2, 4) == 0) {
            len = i + 4;
            break;
        }
    }
    if (len != msg->x18) {
        goto found;
    }
    for (i = 0; i < msg->x18 - 1; i++) {
        if (memcmp((char *)msg->x1C + i, lf2, 2) == 0) {
            len = i + 2;
            break;
        }
    }
    if (len == msg->x18) {
        b.x[7] = 0;
        b.x[6] = 0;
    } else {
    found:
        b.x[7] = len + msg->x1C;
        b.x[6] = msg->x18 - len;
    }
    Encoding(node, 0, &b.x[10]);
    if (msg->x14 == 1) {
        b.x[12] = msg->x14;
    } else {
        b.x[12] = 7;
    }
    r = parseDomBuild(&b);
    initMPL_REQ_LOAD_PAGE(&m1);
    m1.x04 = node[0x48 / 4];
    ps_sndmsg(&m1, 4);
    switch (r->type) {
    case 0:
        ret = ps_JSMailBoxClean();
        break;
    case 1:
        d = MEM_malloc(0, r->len * 2 + 0xC);
        if (d == NULL) {
            ps_halt("(char*)E_malloc(ps_i241A) failed");
        }
        d->len = r->len;
        d->data = (char *)d + 0xC;
        memcpy(d->data, r->data, r->len * 2);
        d->type = node[0x68 / 4];
        MEM_free(0, r->data);
        m.type = 2;
        m.x04 = node[0x48 / 4];
        m.x08 = 1;
        m.cmd = 0x30B;
        m.x10 = 0;
        m.x14 = 0;
        m.x18 = r->len * 2 + 0xC;
        m.x1C = (int)d;
        ps_sndmsg(&m, 4);
        ret = 0x12;
        break;
    case 2:
        n = HST_getJSURI(node, HST_getJSURIlen(node));
        mode = 2;
        if (node[0x30 / 4] != 1) {
            mode = psCacheMode;
        }
        ps_getsend(n, mode, 3, r);
        ret = 0x1A;
        break;
    case 3:
        n = HST_getCSSURI(node, HST_getCSSURIlen(node));
        mode = 2;
        if (node[0x30 / 4] != 1) {
            mode = psCacheMode;
        }
        ps_getsend(n, mode, 1, NULL);
        ret = 0x1A;
        break;
    default:
        ps_halt("ps_i241A(parseDomBuild) failed.");
        break;
    }
    while ((n = ps_searchRequestFlagHistoryNode(node, 0)) != NULL) {
        if (ps_isGetRequest(n) == 0) {
            HST_setRequestFlag(n, 5);
            ps_errStringParseDomBuild(n, D_00137BF4);
        } else {
            mode = 2;
            if (n[0x30 / 4] != 1) {
                mode = psCacheMode;
            }
            if (HST_getMethodType(n) == 0) {
                ps_getsend(n, mode, 0, NULL);
            } else {
                ps_postsend_history(n, mode);
            }
        }
    }
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    if (r != NULL) {
        MEM_free(0, r);
    }
    return ret;
}
