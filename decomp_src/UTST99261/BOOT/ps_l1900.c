/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int buf_sessionURL;
extern int save_sessionURL;
extern int buf_sessionUI;
extern int buf_localUI;
extern int buf_ps_sts;



extern int Accession;
extern int DOCUMENT_WRITE;
extern int psCacheMode;
extern int buf_ps_evt;
extern int mq_js;
int ps_i2406(PsIpc *msg);
int ps_i2608(PsIpc *msg);
int ps_i2308(PsIpc *msg);
int ps_i2208(PsIpc *msg);
int ps_i2906(PsIpc *msg);
int ps_i2D06(PsIpc *msg);
void *memcpy(void *d, const void *s, unsigned int n);
void sendMPU_RPL_DATA_ATTR(PsIpc *msg) {
    PsIpc m;

    m.type = 2;
    m.x04 = buf_sessionUI;
    m.x08 = 0;
    m.cmd = 0xB;
    m.x10 = msg->x10;
    m.x14 = buf_localUI;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    ps_sndmsg(&m, 1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l1903(PsIpc *msg) {
    sendMPU_RPL_DATA_ATTR(msg);
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l190F(PsIpc *msg) {
    sendMPU_RPL_DATA_ATTR(msg);
    return 3;
}

int ps_l1913(PsIpc *msg) {
    ps_save(msg, 0);
    return buf_ps_sts;
}

int ps_l1A03(PsIpc *msg) {
    PsIpc m;

    buf_sessionUI = msg->x04;
    buf_localUI = msg->x14;
    m.x04 = msg->x04;
    m.x08 = msg->x08;
    m.x10 = msg->x10;
    m.x14 = msg->x14;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    m.type = 2;
    m.cmd = 0x15;
    m.x14 = ps_sessionURL();
    ps_sndmsg(&m, 1);
    save_sessionURL = buf_sessionURL;
    return 0x17;
}

int ps_l1A06(PsIpc *msg) {
    PsIpc m;

    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    ps_save(msg, 0);
    return 10;
}

int ps_l1A07(PsIpc *msg) {
    PsIpc m;

    initMPL_REQ_ABORT_PAGE(&m);
    ps_sndmsg(&m, 4);
    ps_save(msg, 0);
    return 11;
}

int ps_l1A08(PsIpc *msg) {
    PsIpc m;

    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    m.cmd = 0x304;
    m.x04 = 0;
    m.x10 = 0;
    ps_sndmsg(&m, 4);
    ps_save(msg, 0);
    return 12;
}

int ps_l1B12(PsIpc *msg) {
    PsDomBuild b;
    PsIpc m;
    PsMqMsg mm;
    PsIpc m2;
    int *node;
    int *t;
    PsDomResult *r;
    PsDomResult *d;
    int ret;
    int flag;
    void *u;
    int mode;
    int *n;

    ret = 0;
    flag = 0;
    node = HST_searchSessionIDHistoryNode(msg->x04);
    if (node == NULL) {
        ps_halt("ps_l1B12(session ERR) failed");
    }
    t = (int *)msg->x1C;
    b.x[0] = node[1];
    b.x[1] = node[0];
    b.x[2] = node[5];
    b.x[3] = node[4];
    b.x[4] = node[7];
    b.x[5] = node[6];
    b.x[6] = 0;
    b.x[7] = 0;
    b.x[9] = msg->x04;
    b.x[11] = 1;
    b.x[12] = 0;
    b.x[13] = Accession;
    if (DOCUMENT_WRITE == 1) {
        b.x[12] = 6;
        b.x[14] = DOCUMENT_WRITE;
        DOCUMENT_WRITE = 0;
    } else {
        b.x[14] = 0;
    }
    r = parseDomBuild(&b);
    if (t[2] != 0) {
        MEM_free(0, (void *)t[2]);
    }
    MEM_free(0, t);
    initMPL_REQ_LOAD_PAGE(&m);
    m.x04 = msg->x04;
    ps_sndmsg(&m, 4);
    switch (r->type) {
    case 0:
        break;
    case 1:
        d = MEM_malloc(0, r->len * 2 + 0xC);
        if (d == NULL) {
            ps_halt("(char*)E_malloc(ps_l1B12) failed");
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
        if (r != NULL) {
            MEM_free(0, r);
        }
        return 0x1A;
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
        if (r != NULL) {
            MEM_free(0, r);
        }
        return 0x1A;
    default:
        ps_halt("ps_i2406(parseDomBuild) failed.");
        break;
    }
    while ((n = HST_searchRequestFlagHistoryNode(0)) != NULL) {
        if (ps_isGetRequest(n) == 0) {
            HST_setRequestFlag(n, 5);
            ps_errStringParseDomBuild(n, "<html><body></body></html>");
        } else {
            mode = 2;
            if (n[0x30 / 4] != 1) {
                mode = psCacheMode;
            }
            ps_getsend(n, mode, 0, NULL);
        }
    }
    if (r->type == 1) {
        if (r != NULL) {
            MEM_free(0, r);
        }
        return ret;
    }
    if (r != NULL) {
        MEM_free(0, r);
    }
    buf_ps_sts = 200;
    ret = 200;
    while (GetMQUEUE(mq_js, &mm)) {
        buf_ps_evt = mm.evt;
        switch (mm.evt) {
        case 0x24:
        case 0x25:
            ret = ps_i2406((PsIpc *)&mm.x[1]);
            break;
        case 0x26:
            ret = ps_i2608((PsIpc *)&mm.x[1]);
            break;
        case 0x23:
            ret = ps_i2308((PsIpc *)&mm.x[1]);
            if (ret == 7)
                flag = 1;
            break;
        case 0x22:
            ret = ps_i2208((PsIpc *)&mm.x[1]);
            flag = 1;
            break;
        case 0x29:
            ret = ps_i2906((PsIpc *)&mm.x[1]);
            break;
        case 0x2D:
            ret = ps_i2D06((PsIpc *)&mm.x[1]);
            break;
        default:
            if (mm.data != NULL)
                MEM_free(0, mm.data);
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

