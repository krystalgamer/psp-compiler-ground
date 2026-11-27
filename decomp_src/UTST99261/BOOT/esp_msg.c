/* cflags: -O1 */
#include "common.h"
#include "dom_esp.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);

int OS_mq_open(const char *name, int flags, ...);
int OS_mq_receive(int q, void *buf, int len, void *prio);
int OS_mq_close(int q);
void OS_thread_exit(void *r);
int GUI_Toolkit_postEvent(void *w, int ev, void *p);
void *cnvExtSchemeSelected(void *arg0) {
    void *temp_s1;
    void *temp_v0;
    void *var_v0;

    temp_s1 = M2C_FIELD(arg0, void **, 0x1C);
    temp_v0 = MEM_malloc(0, M2C_FIELD(temp_s1, unsigned int *, 0) + 1);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        memset(temp_v0, 0, M2C_FIELD(temp_s1, unsigned int *, 0) + 1);
        memcpy(temp_v0, M2C_FIELD(temp_s1, void **, 4), M2C_FIELD(temp_s1, unsigned int *, 0));
        MEM_free(0, temp_s1);
        M2C_FIELD(arg0, void **, 0x1C) = temp_v0;
        var_v0 = arg0;
    }
    return var_v0;
}

int esp_msgThread(void *arg) {
    EspMsg m;
    int q;
    int *spare;
    int *err;
    int *p;
    void *w;
    int run;

    run = 1;
    q = OS_mq_open("/tmp/mq_ui", 2);
    if (q < 0) {
        return 0;
    }
    spare = MEM_malloc(0, 0x20);
    if (spare == NULL) {
        return 0;
    }
    err = MEM_malloc(0, 8);
    if (err == NULL) {
        if (spare != NULL) {
            MEM_free(0, spare);
        }
        return 0;
    }
    while (run == 1) {
        if (OS_mq_receive(q, &m, 0x24, NULL) < 0) {
            return 0;
        }
        p = MEM_malloc(0, 0x20);
        if (p == NULL) {
            if (m.cmd != 0xFFFF || spare == NULL) {
                return 0;
            }
            p = spare;
            spare = NULL;
        }
        p[0] = m.src;
        p[1] = m.x08;
        p[2] = m.x0C;
        p[3] = m.cmd;
        p[4] = m.arg;
        p[5] = m.x18;
        p[6] = m.len;
        p[7] = (int)m.data;
        w = M2C_FIELD(arg, void **, 0x78);
        switch (p[3]) {
        case 0:
            GUI_Toolkit_postEvent(w, 9, p);
            break;
        case 1:
            MEM_free(0, p);
            GUI_Toolkit_postEvent(w, 0xA, NULL);
            run = 0;
            break;
        case 2:
            GUI_Toolkit_postEvent(w, 0xB, p);
            break;
        case 4:
            GUI_Toolkit_postEvent(w, 0xC, p);
            break;
        case 5:
            GUI_Toolkit_postEvent(w, 0xD, p);
            break;
        case 6:
            GUI_Toolkit_postEvent(w, 0xE, p);
            break;
        case 9:
            p = cnvExtSchemeSelected(p);
            if (p == NULL) {
                goto nomem;
            }
            GUI_Toolkit_postEvent(w, 0xF, p);
            break;
        case 0xA:
            GUI_Toolkit_postEvent(w, 0x10, p);
            break;
        case 0xB:
            GUI_Toolkit_postEvent(w, 0x17, p);
            break;
        case 0xC:
            GUI_Toolkit_postEvent(w, 0x11, p);
            break;
        case 0xE:
            GUI_Toolkit_postEvent(w, 0x12, p);
            break;
        case 0x14:
            GUI_Toolkit_postEvent(w, 0x15, p);
            break;
        case 0x15:
            GUI_Toolkit_postEvent(w, 0x16, p);
            break;
        case 0x16:
            GUI_Toolkit_postEvent(w, 0x18, p);
            break;
        case 0x11:
            GUI_Toolkit_postEvent(w, 0x19, p);
            break;
        case 0xFFFF:
            GUI_Toolkit_postEvent(w, 0x20, p);
            break;
        case 0x17:
            GUI_Toolkit_postEvent(w, 0x1B, p);
            break;
        case 0x18:
            GUI_Toolkit_postEvent(w, 0x1C, p);
            break;
        case 0x19:
            GUI_Toolkit_postEvent(w, 0x1D, p);
            break;
        case 0x1A:
            GUI_Toolkit_postEvent(w, 0x1E, p);
            break;
        case 0x1B:
            GUI_Toolkit_postEvent(w, 0x1F, p);
            break;
        default:
            MEM_free(0, p);
            p = NULL;
            break;
        nomem:
            if (spare != NULL) {
                void *w2 = M2C_FIELD(arg, void **, 0x78);
                spare[0] = 0;
                spare[1] = 0;
                spare[2] = 0;
                spare[3] = 0;
                spare[4] = 0;
                spare[5] = 0;
                spare[6] = 0;
                spare[7] = 0;
                spare[0] = M2C_FIELD(esp_context, int *, 0x100);
                spare[3] = 0xFFFF;
                spare[7] = (int)err;
                if (err != NULL) {
                    err[0] = -1;
                    err[1] = (int)"AllocationError(API_MSG)";
                }
                GUI_Toolkit_postEvent(w2, 0x20, spare);
                spare = NULL;
                err = NULL;
            }
            break;
        }
    }
    if (spare != NULL) {
        MEM_free(0, spare);
    }
    if (err != NULL) {
        MEM_free(0, err);
    }
    OS_mq_close(q);
    OS_thread_exit(NULL);
    return 0;
}

int esp_setupPointerDeviceMessage(EspMsg *m, int type, int x, int y, int btn, int time) {
    EspDevEvent *e;

    e = MEM_malloc(0, 0x14);
    if (e == NULL) {
        m->data = NULL;
        return -1;
    }
    m->cmd = 4;
    m->arg = 0;
    m->len = 0x14;
    m->data = e;
    *(short *)e = type;
    ((int *)e)[1] = time;
    ((int *)e)[2] = x;
    ((int *)e)[3] = y;
    ((short *)e)[8] = btn;
    return 0;
}

int esp_setupKeyDeviceMessage(EspMsg *m, int type, int key, int mod, int time) {
    EspDevEvent *e;

    e = MEM_malloc(0, 0x14);
    if (e == NULL) {
        m->data = NULL;
        return -1;
    }
    m->cmd = 4;
    m->arg = 0;
    m->len = 0x14;
    m->data = e;
    *(short *)e = type;
    ((int *)e)[1] = time;
    ((short *)e)[4] = key;
    ((short *)e)[5] = mod;
    return 0;
}

int esp_postMessage(int q, EspMsg *m) {
    if (OS_mq_send(q, m, sizeof(EspMsg), 0) < 0) {
        return -1;
    }
    return 0;
}

int esp_postMsgInit(int q, void *a) {
    EspMsg m;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.len = 0;
    m.src = 1;
    m.cmd = 0;
    m.data = a;
    return esp_postMessage(q, &m);
}

int esp_postMsgQuit(int q) {
    EspMsg m;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.len = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 1;
    return esp_postMessage(q, &m);
}

int esp_postMsgLoadPage(int q, char *url, char *ref, int arg, int a, int b, int c) {
    EspMsg m;
    int ulen;
    int rlen;
    struct {
        short a;
        short b;
        short c;
        short d;
        int ulen;
        char *url;
        int rlen;
        char *ref;
        int pad[2];
        char buf[1];
    } *d;

    if (url != NULL) {
        ulen = strlen(url);
    } else {
        ulen = 0;
    }
    rlen = 0;
    if (ulen > 0 && ref != NULL) {
        rlen = strlen(ref);
    }
    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.x18 = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 2;
    m.arg = arg;
    m.len = ulen + rlen + 0x22;
    d = MEM_calloc(0, m.len);
    if (d == NULL) {
        return -1;
    }
    d->a = a;
    d->b = b;
    d->c = c;
    d->d = 0;
    if (ulen > 0) {
        d->ulen = ulen;
        d->url = d->buf;
        strcpy(d->url, url);
        if (rlen > 0) {
            d->rlen = rlen;
            d->ref = d->url + d->ulen + 1;
            strcpy(d->ref, ref);
        }
    }
    m.data = d;
    if (esp_postMessage(q, &m) != 0) {
        MEM_free(0, m.data);
        return -1;
    }
    return 0;
}

int esp_postMsgSubmitForm(int q, char *url, char *data, int dlen, char *ref, int x, char *hdr) {
    EspMsg m;
    int ulen;
    int rlen;
    int hlen;
    int *d;
    char *p;

    ulen = strlen(url) + 1;
    rlen = 0;
    if (ref != NULL) {
        rlen = strlen(ref) + 1;
    }
    hlen = 0;
    if (hdr != NULL) {
        hlen = strlen(hdr);
    }
    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.x18 = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 0x37;
    m.arg = 0;
    m.len = ulen + rlen + hlen + dlen + 0x14;
    d = MEM_calloc(0, m.len);
    if (d == NULL) {
        return -1;
    }
    d[0] = x;
    m.data = d;
    p = (char *)(d + 5);
    d[1] = (int)p;
    strcpy(p, url);
    p += ulen;
    if (rlen > 0) {
        d[2] = (int)p;
        strcpy(p, ref);
        p += rlen;
    }
    if (hlen + dlen > 0) {
        d[3] = hlen + dlen;
        d[4] = (int)p;
        memcpy(p, hdr, hlen);
        memcpy((char *)d[4] + hlen, data, dlen);
    }
    if (esp_postMessage(q, &m) != 0) {
        MEM_free(0, m.data);
        return -1;
    }
    return 0;
}

int esp_postMsgRepaint(int q) {
    EspMsg m;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.len = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 3;
    return esp_postMessage(q, &m);
}

int esp_postMsgDeviceEvent(int q, void *a) {
    EspMsg m;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.src = 1;
    m.cmd = 4;
    m.len = 0x14;
    m.data = a;
    return esp_postMessage(q, &m);
}

int esp_postMsgStop(int q) {
    EspMsg m;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.len = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 5;
    return esp_postMessage(q, &m);
}

int esp_postMsgFindString(int q, int dir, int flags, char *str) {
    EspMsg m;
    int size;
    short *d;

    size = strlen(str) + 0x11;
    d = MEM_malloc(0, size);
    if (d == NULL) {
        return -1;
    }
    d[0] = 0;
    d[1] = flags;
    d[2] = dir;
    ((int *)d)[2] = strlen(str);
    ((int *)d)[3] = (int)(d + 8);
    strcpy((char *)(d + 8), str);
    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.src = 1;
    m.cmd = 6;
    m.len = size;
    m.data = d;
    return esp_postMessage(q, &m);
}

int esp_postMsgDataAttr(int q, int a, int b, int c) {
    EspMsg m;
    int *d;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.len = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 0xA;
    d = MEM_malloc(0, 0xC);
    if (d == NULL) {
        return -1;
    }
    d[0] = a;
    d[1] = b;
    d[2] = c;
    m.len = 0xC;
    m.data = d;
    return esp_postMessage(q, &m);
}

int esp_postMsgSaveURL(int q, char *url, int x) {
    EspMsg m;
    int size;
    int *d;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.len = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 0xB;
    size = strlen(url) + 0xD;
    d = MEM_malloc(0, size);
    if (d == NULL) {
        return -1;
    }
    d[0] = 0;
    d[1] = (int)(d + 3);
    strcpy((char *)(d + 3), url);
    d[2] = x;
    m.len = size;
    m.data = d;
    return esp_postMessage(q, &m);
}

int esp_postMsgTitle(int q) {
    EspMsg m;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.len = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 12;
    return esp_postMessage(q, &m);
}

int esp_postMsgConfigChanged(int q) {
    EspMsg m;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.len = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 13;
    return esp_postMessage(q, &m);
}

int esp_postMsgFreeScroll(int q, int a) {
    EspMsg m;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.x18 = 0;
    m.len = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 15;
    m.arg = a;
    return esp_postMessage(q, &m);
}

int esp_postMsgEditMenu(int q, int op, char *str) {
    EspMsg m;
    int len;
    char *p;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.x18 = 0;
    m.len = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 0x30;
    m.arg = op;
    if (op == 0 && str != NULL) {
        len = strlen(str);
        p = MEM_malloc(0, len + 1);
        if (p == NULL) {
            return -1;
        }
        strcpy(p, str);
        m.len = len + 1;
        m.data = p;
    }
    return esp_postMessage(q, &m);
}

int esp_postMsgDeleteCookie(int q) {
    EspMsg m;

    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.len = 0;
    m.data = NULL;
    m.src = 1;
    m.cmd = 51;
    return esp_postMessage(q, &m);
}

int esp_postMsgInputData(int q, char *str) {
    EspMsg m;
    int size;
    int *d;

    size = 8;
    if (str != NULL) {
        size = strlen(str) + 9;
    }
    d = MEM_malloc(0, size);
    if (d == NULL) {
        return -1;
    }
    d[0] = str != NULL ? strlen(str) + 1 : 0;
    memcpy(d + 1, str, d[0]);
    m.x00 = 0;
    m.x08 = 0;
    m.x0C = 0;
    m.arg = 0;
    m.x18 = 0;
    m.src = 1;
    m.cmd = 0x36;
    m.len = size;
    m.data = d;
    return esp_postMessage(q, &m);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133C84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133C94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CA0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CCC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133D08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133D14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133D20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133D28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133D30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", cfg_names);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", cv_code);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133E24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133E2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133E34);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133E3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133E40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", cv_fsize);
