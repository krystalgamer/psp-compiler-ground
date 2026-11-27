/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int buf_sessionUI;
extern int buf_localUI;
extern int buf_ps_sts;



extern int Security;
extern int buf_Message_Show_FLG;
extern int before_ps_sts;
extern int buf_Message_cnt;
typedef struct PsAuthInfo { char *path; char *user; char *pass; } PsAuthInfo;
PsAuthInfo *HST_searchAuthorizationDB(char *url);
int strlen(const char *s);
void *memcpy(void *d, const void *s, unsigned int n);
extern int On_Save;
extern int SSLFlg;
extern int CONTENT_SAVE;
extern void *gPREF_UI;
void sendMPL_REQ_DATA_ATTR(PsIpc *msg) {
    PsIpc m;

    buf_sessionUI = msg->x04;
    buf_localUI = msg->x14;
    m.type = 2;
    m.x04 = ps_sessionGen();
    m.x08 = 0;
    m.cmd = 0x307;
    m.x10 = 0;
    m.x14 = 0;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    ps_sndmsg(&m, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0A03(PsIpc *msg) {
    sendMPL_REQ_DATA_ATTR(msg);
    return 0xF;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0A06(PsIpc *msg) {
    sendMPL_REQ_DATA_ATTR(msg);
    return buf_ps_sts;
}

int ps_u0B03(PsIpc *msg) {
    PsIpc m;
    int x;
    int plen;
    int ulen;
    int alen;
    int *r;
    char *url;
    int n;
    PsAuthInfo *a;
    int size;
    int *buf;
    char *p;
    char *user;
    char *pass;

    ulen = 0;
    plen = 0;
    On_Save = 1;
    SSLFlg = 0;
    CONTENT_SAVE = 0;
    alen = 0;
    if (gPREF_UI != NULL) {
        M2C_FIELD(gPREF_UI, int *, 0x68) = 0;
    }
    r = (int *)msg->x1C;
    url = (char *)r[1];
    n = strlen(url);
    x = r[2];
    a = HST_searchAuthorizationDB(url);
    if (a != NULL) {
        ulen = strlen(a->user);
        plen = strlen(a->pass);
        if (ulen + plen > 0) {
            alen = ulen + plen + 0x16;
        }
    }
    size = n + alen + 0x1A;
    buf = MEM_malloc(0, size);
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    p = (char *)&buf[6];
    buf[0] = r[0];
    buf[1] = n;
    buf[2] = (int)p;
    memcpy(p, url, n);
    p[n] = 0;
    p += n + 1;
    buf[3] = 0;
    buf[4] = 0;
    if (alen > 0) {
        buf[3] = alen;
        buf[4] = (int)p;
        user = a->user;
        pass = a->pass;
        memcpy(p, "Authorization: Basic ", strlen("Authorization: Basic "));
        p += strlen("Authorization: Basic ");
        if (ulen > 0 && user != NULL) {
            memcpy(p, user, ulen);
            p += ulen;
        }
        *p++ = ':';
        if (plen > 0 && pass != NULL) {
            memcpy(p, pass, plen);
            p += plen;
        }
        *p = 0;
    }
    buf[5] = x;
    m.type = 2;
    m.x04 = 0;
    m.x08 = 0;
    m.cmd = 6;
    m.x10 = 0;
    m.x14 = 0;
    m.x18 = size;
    m.x1C = (int)buf;
    ps_sndmsg(&m, 5);
    MEM_free(0, msg->x1C);
    return 9;
}

int ps_u0C03(PsIpc *msg) {
    PsIpc m;
    void *node;
    int len;
    int *buf;

    node = HST_getHeadHistoryNode();
    if (node != NULL) {
        len = HST_getTitlelen(node);
        buf = MEM_malloc(0, len + 4);
        if (buf == NULL) {
            ps_halt("(char*)E_malloc(ps_u0C03) failed");
        }
        memset(buf, 0, len + 4);
        buf[0] = len;
        if (len != 0) {
            memcpy(buf + 1, HST_getTitle(node), len);
        }
        m.type = 2;
        m.x04 = msg->x04;
        m.x08 = msg->x08;
        m.cmd = 0xD;
        m.x10 = msg->x10;
        m.x14 = msg->x14;
        m.x18 = len + 4;
        m.x1C = (int)buf;
        ps_sndmsg(&m, 1);
    }
    return buf_ps_sts;
}

int getBuffSize(int n) {
    int r;

    r = 0;
    if (n % 4 != 0) {
        if (n / 4 * 4 == n - 1) {
            r = 3;
        } else if (n % 4 == 2) {
            r = 2;
        } else {
            r = 1;
        }
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_u0E13);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_u3103(void) {
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_u3216);

int ps_u3517(PsIpc *msg) {
    PsIpc d;
    int *p;
    char *s;
    int sec;

    ps_saveCacheMode(1);
    ps_JSMailBoxfree();
    ps_FreeLocation();
    p = (int *)msg->x1C;
    s = MEM_malloc(0, p[3] + 1);
    memset(s, 0, p[3] + 1);
    memcpy(s, (void *)p[4], p[3]);
    sec = icmpstr(s, "https://", 8);
    MEM_free(0, s);
    if (((sec == 1 && Security == 0) || (sec == 0 && Security == 1)) && buf_Message_Show_FLG == 0) {
        if (Security == 0) {
            if (initMPU_REQ_SHOW_DIALOG(&d, 6) == 0) {
                ps_halt("initMPU_REQ_SHOW_DIALOG failed");
            }
            d.x14 = 0x80000002;
        } else {
            if (initMPU_REQ_SHOW_DIALOG(&d, 7) == 0) {
                ps_halt("initMPU_REQ_SHOW_DIALOG failed");
            }
            d.x14 = 0x80000003;
        }
        d.x04 = msg->x04;
        ps_sndmsg(&d, 1);
        ps_save(msg, 0);
        buf_Message_Show_FLG = 1;
        before_ps_sts = buf_ps_sts;
        buf_Message_cnt++;
        return 0x13;
    }
    return ps_submit(msg);
}

int ps_l1001(void) {
    PsIpc m;

    m.type = 2;
    m.x04 = ps_sessionGen();
    m.x08 = 0;
    m.cmd = 0;
    m.x10 = 0;
    m.x14 = 0;
    m.x18 = 0;
    m.x1C = 0;
    ps_sndmsg(&m, 5);
    return 2;
}

