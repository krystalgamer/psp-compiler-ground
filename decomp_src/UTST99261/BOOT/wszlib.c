/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/wszlib.h"
#include "m2c_macros.h"
M2C_UNK rnd_gdrawGetTextlineExtents();              /* extern */
M2C_UNK rnd_gdrawGetTextboxExtents();               /* extern */
M2C_UNK rnd_gdrawGetCheckboxExtents();              /* extern */
M2C_UNK rnd_gdrawGetRadiobuttonExtents();           /* extern */
M2C_UNK rnd_gdrawGetButtonExtents();                /* extern */
M2C_UNK rnd_gdrawGetPulldownExtents();              /* extern */
M2C_UNK rnd_gdrawGetListExtents();                  /* extern */
M2C_UNK GUI_Graphics_getStringSize();               /* extern */
M2C_UNK rnd_gdrawGetStringsVisibleLength();         /* extern */
M2C_UNK colorValue();                               /* extern */

ZBUF *newZBuf(u8 *data, int size) {
    ZBUF *zb;

    zb = ESP_malloc(sizeof(ZBUF));
    if (zb == NULL) {
        return NULL;
    }
    zb->head = NULL;
    zb->pos = 0;
    zb->bit = 0;
    zb->out = NULL;
    zb->outLen = 0;
    zb->outSize = 0;
    zb->data = data;
    zb->size = size;
    zb->ptr = data;
    zb->total = size;
    zb->cur = (ZCHUNK *)zb;
    return zb;
}

int addData(ZBUF *zb, u8 *data, int size) {
    ZCHUNK *p;
    ZCHUNK *c;

    for (p = (ZCHUNK *)zb; p->next != NULL; p = p->next)
        ;
    c = ESP_malloc(sizeof(ZCHUNK));
    if (c == NULL) {
        return -2;
    }
    c->data = data;
    c->size = size;
    c->next = NULL;
    p->next = c;
    zb->total += size;
    return 0;
}

void freeZBuf(ZBUF *zb) {
    ZCHUNK *p;
    ZCHUNK *n;

    for (p = zb->head; p != NULL; p = n) {
        n = p->next;
        ESP_free(p);
    }
    if (zb->out != NULL) {
        ESP_free(zb->out);
    }
    ESP_free(zb);
}

int readBits(ZBUF *zb, int n, int msbFirst, unsigned int *out) {
    unsigned int v;
    int i;
    int avail;
    ZCHUNK *c;

    v = 0;
    if ((unsigned int)n > 32) {
        return -5;
    }
    if (zb->cur == NULL) {
        return -1;
    }
    c = zb->cur;
    avail = (c->size - zb->pos) * 8 - zb->bit;
    if (avail < n) {
        c = c->next;
        do {
            if (c == NULL) {
                return -1;
            }
            avail += c->size * 8;
            c = c->next;
        } while (avail < n);
    }
    if (msbFirst == 1) {
        for (i = 0; i < n; i++) {
            v <<= 1;
            if ((*zb->ptr >> zb->bit++) & 1) {
                v |= 1;
            }
            if (zb->bit & 8) {
                zb->bit = 0;
                zb->pos++;
                zb->ptr++;
                if (zb->pos == zb->cur->size) {
                    zb->cur = zb->cur->next;
                    zb->pos = 0;
                    if (zb->cur != NULL) {
                        zb->ptr = zb->cur->data;
                    } else if (i < n - 1) {
                        return -1;
                    }
                }
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            if ((*zb->ptr >> zb->bit++) & 1) {
                v |= 1 << i;
            }
            if (zb->bit & 8) {
                zb->bit = 0;
                zb->pos++;
                zb->ptr++;
                if (zb->pos == zb->cur->size) {
                    zb->cur = zb->cur->next;
                    zb->pos = 0;
                    if (zb->cur != NULL) {
                        zb->ptr = zb->cur->data;
                    } else if (i < n - 1) {
                        return -1;
                    }
                }
            }
        }
    }
    if (out != NULL) {
        *out = v;
    }
    return 0;
}

int peekBits(ZBUF *zb, int n, int msbFirst, unsigned int *out) {
    unsigned int v;
    int i;
    int avail;
    ZCHUNK *c;
    ZCHUNK *t;
    u8 *p;
    unsigned int bit;

    v = 0;
    if ((unsigned int)n > 32) {
        return -5;
    }
    if (zb->cur == NULL) {
        return -1;
    }
    t = zb->cur;
    avail = (t->size - zb->pos) * 8 - zb->bit;
    if (avail < n) {
        t = t->next;
        do {
            if (t == NULL) {
                return -1;
            }
            avail += t->size * 8;
            t = t->next;
        } while (avail < n);
    }
    c = zb->cur;
    p = zb->ptr;
    bit = zb->bit;
    if (msbFirst == 1) {
        for (i = 0; i < n; i++) {
            v = (v << 1) | ((*p >> bit) & 1);
            bit++;
            if (bit & 8) {
                p++;
                bit = 0;
                if (p == c->data + c->size) {
                    c = c->next;
                    if (c != NULL) {
                        p = c->data;
                    }
                }
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            if ((*p >> bit) & 1) {
                v |= 1 << i;
            }
            bit++;
            if (bit & 8) {
                p++;
                bit = 0;
                if (p == c->data + c->size) {
                    c = c->next;
                    if (c != NULL) {
                        p = c->data;
                    }
                }
            }
        }
    }
    if (out != NULL) {
        *out = v;
    }
    return 0;
}

void skipBits(ZBUF *zb, int n) {
    while (n > 8) {
        zb->pos++;
        zb->ptr++;
        n -= 8;
        if (zb->pos == zb->cur->size) {
            zb->cur = zb->cur->next;
            zb->pos = 0;
            if (zb->cur != NULL) {
                zb->ptr = zb->cur->data;
            } else {
                zb->ptr = NULL;
            }
        }
    }
    if (n > 0) {
        n += zb->bit;
        zb->bit = n;
        if ((unsigned int)n >= 8) {
            zb->pos++;
            zb->ptr++;
            zb->bit = n - 8;
            if (zb->pos == zb->cur->size) {
                zb->cur = zb->cur->next;
                zb->pos = 0;
                if (zb->cur != NULL) {
                    zb->ptr = zb->cur->data;
                } else {
                    zb->ptr = NULL;
                }
            }
        }
    }
}

int writeBytes(ZBUF *zb, u8 *src, int len) {
    u8 *old;
    u8 *nb;
    int sz;

    old = NULL;
    if (len <= 0) {
        return -5;
    }
    if (zb->out == NULL) {
        zb->outSize = (unsigned int)len < zb->total ? zb->total : len;
        zb->out = ESP_malloc(zb->outSize);
        if (zb->out == NULL) {
            return -2;
        }
    } else if (zb->outSize < len + zb->outLen) {
        sz = zb->outSize * 7 / 5;
        while (sz < len + zb->outLen) {
            sz = sz * 7 / 5;
        }
        old = zb->out;
        nb = ESP_malloc(sz);
        if (nb == NULL) {
            return -2;
        }
        memcpy(nb, old, zb->outLen);
        zb->out = nb;
        zb->outSize = sz;
    }
    memcpy(zb->out + zb->outLen, src, len);
    zb->outLen += len;
    if (old != NULL) {
        ESP_free(old);
    }
    return 0;
}

void skipCurByte(ZBUF *zb) {
    if (zb->bit != 0) {
        zb->bit = 0;
        zb->pos++;
        zb->ptr++;
    }
}

int do_nocomp(ZBUF *zb) {
    unsigned int len;
    unsigned int nlen;
    unsigned int n;
    unsigned int rest;
    int r;

    skipCurByte(zb);
    if ((r = readBits(zb, 16, 0, &len)) != 0) {
        return r;
    }
    if ((r = readBits(zb, 16, 0, &nlen)) != 0) {
        return r;
    }
    if (len != (~nlen & 0xFFFF)) {
        return -3;
    }
    while (len != 0) {
        rest = zb->cur->size - zb->pos;
        n = len;
        if (rest < n) {
            n = rest;
        }
        if ((r = writeBytes(zb, zb->ptr, n)) != 0) {
            return r;
        }
        zb->pos += n;
        zb->ptr += n;
        if (zb->pos == zb->cur->size) {
            zb->cur = zb->cur->next;
            zb->pos = 0;
            if (zb->cur != NULL) {
                zb->ptr = zb->cur->data;
            }
        }
        len -= n;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", do_fixed);

int calc_hc(HCODE *t, int maxlen, int n, int rev) {
    int *count;
    int *next;
    int i;
    int code;
    int len;

    count = ESP_malloc(maxlen * 4 + 4);
    if (count == NULL) {
        return -2;
    }
    next = ESP_malloc(maxlen * 4 + 4);
    if (next == NULL) {
        ESP_free(count);
        return -2;
    }
    memset(count, 0, maxlen * 4);
    memset(next, 0, maxlen * 4);
    for (i = 0; i < n; i++) {
        count[t[i].len]++;
    }
    code = 0;
    count[0] = 0;
    for (i = 1; i <= maxlen; i++) {
        code = (code + count[i - 1]) << 1;
        next[i] = code;
    }
    ESP_free(count);
    for (i = 0; i < n; i++) {
        len = t[i].len;
        if (len == 0) {
            continue;
        }
        if (rev) {
            t[i].code = next[len] << (maxlen - len);
        } else {
            t[i].code = next[len];
        }
        next[len]++;
    }
    ESP_free(next);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", read_code_length);

void quick_sort(HCODE *t, int lo, int hi) {
    unsigned int pivot;
    int i;
    int j;
    HCODE tmp;

    if (hi - lo <= 0) {
        return;
    }
    pivot = t[(lo + hi) / 2].code;
    i = lo;
    j = hi;
    for (;;) {
        while (t[i].code < pivot) {
            i++;
        }
        while (pivot < t[j].code && i <= j) {
            j--;
        }
        if (j < i) {
            break;
        }
        tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
        j--;
    }
    j = j < lo ? lo : j;
    quick_sort(t, lo, j);
    quick_sort(t, j + 1, hi);
}

int pack_tree(HCODE *t, int n) {
    int i;
    int j;

    j = 0;
    for (i = 0; i < n; i++) {
        if (t[i].len != 0) {
            if (j < i) {
                t[j] = t[i];
                t[j].sym = i;
                t[i].len = 0;
            } else {
                t[i].sym = i;
            }
            j++;
        }
    }
    quick_sort(t, 0, j - 1);
    return j;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", do_dynamic);

ZBUF *zlib_new(u8 *data, int size) {
    ZBUF *zb;

    zb = newZBuf(data, size);
    if (zb == NULL) {
        return NULL;
    }
    return zb;
}

int zlib_addData(void *handle, u8 *data, int size) {
    return addData(handle, data, size);
}

void zlib_free(void *handle) {
    freeZBuf(handle);
}

int zlib_inflate(void *handle, u8 **out, int *outLen) {
    ZBUF *zb = handle;
    unsigned int cmf;
    unsigned int flg;
    unsigned int hdr;
    int last;
    int r;

    hdr = 0;
    last = 0;
    if (out != NULL) {
        *out = zb->out;
    }
    if (outLen != NULL) {
        *outLen = zb->outLen;
    }
    if ((r = readBits(zb, 8, 0, &cmf)) != 0) {
        return r;
    }
    if ((cmf & 0xF) != 8) {
        return -3;
    }
    if ((r = readBits(zb, 8, 0, &flg)) != 0) {
        return r;
    }
    if (((cmf << 8) + flg) % 31 != 0) {
        return -3;
    }
    if (flg & 0x20) {
        skipBits(zb, 16);
    }
    do {
        if ((r = readBits(zb, 3, 0, &hdr)) != 0) {
            return r;
        }
        if (hdr & 1) {
            last = 1;
        }
        switch ((int)(hdr >> 1) & 3) {
        case 0:
            r = do_nocomp(zb);
            break;
        case 1:
            r = do_fixed(zb);
            break;
        case 2:
            r = do_dynamic(zb);
            break;
        default:
            return -3;
        }
        if (r != 0) {
            if (out != NULL) {
                *out = zb->out;
            }
            if (outLen != NULL) {
                *outLen = zb->outLen;
            }
            return r;
        }
    } while (!last);
    if (out != NULL) {
        *out = zb->out;
    }
    if (outLen != NULL) {
        *outLen = zb->outLen;
    }
    return 0;
}

int setTextStrings(FORMELEM *e, char *s) {
    if (e->widget == NULL) {
        return -100;
    }
    if (e->info->kind == 1) {
        GUI_TextArea_setText(e->widget, s);
    } else {
        GUI_TextField_setText(e->widget, s);
    }
    return 0;
}

char *getTextStrings(FORMELEM *e) {
    if (e->widget == NULL) {
        return (char *)-100;
    }
    if (e->info->kind == 1) {
        return rnd_gdrawGetTextboxString(e->widget);
    }
    return rnd_gdrawGetTextlineString(e->widget);
}

int replaceTextStrings(FORMELEM *e, char *s, int start, int end) {
    int t;

    if (e->widget == NULL) {
        return -100;
    }
    if (end < start) {
        t = start;
        start = end;
        end = t;
    }
    if (e->info->kind == 1) {
        return rnd_gdrawReplaceTextboxString(e->widget, s, start, end);
    }
    return GUI_TextField_insert(e->widget, s, start, end);
}

int getTextSelectionRange(FORMELEM *e, int *start, int *end) {
    if (e->widget == NULL) {
        return -100;
    }
    if (e->info->kind == 1) {
        return GUI_TextArea_getSelection(e->widget, start, end);
    }
    return GUI_TextField_getSelection(e->widget, start, end);
}

char *getTextSelectionString(FORMELEM *e) {
    if (e->widget == NULL) {
        return (char *)-100;
    }
    if (e->info->kind == 1) {
        return rnd_gdrawGetTextboxSelectionString(e->widget);
    }
    return rnd_gdrawGetTextlineSelectionString(e->widget);
}

int selectText(FORMELEM *e) {
    if (e->widget == NULL) {
        return -100;
    }
    if (e->info->kind == 1) {
        rnd_gdrawSelectTextbox(e->widget, 1);
    } else {
        GUI_TextField_selectAll(e->widget);
    }
    return 0;
}

void getTextlineExtents(void) {
    rnd_gdrawGetTextlineExtents();
}

void getTextboxExtents(void) {
    rnd_gdrawGetTextboxExtents();
}

void getCheckboxExtents(void) {
    rnd_gdrawGetCheckboxExtents();
}

int setCheckboxState(FORMELEM *e, int state) {
    if (e->widget == NULL) {
        return -100;
    }
    GUI_Checkbox_setState(e->widget, state);
    return 0;
}

int getCheckboxState(FORMELEM *e) {
    if (e->widget == NULL) {
        return -100;
    }
    return GUI_Checkbox_getState(e->widget);
}

void getRadiobuttonExtents(void) {
    rnd_gdrawGetRadiobuttonExtents();
}

int setRadiobuttonState(FORMELEM *e, int state) {
    if (e->widget == NULL) {
        return -100;
    }
    GUI_RadioButton_setState(e->widget, state);
    return 0;
}

int getRadiobuttonState(FORMELEM *e) {
    if (e->widget == NULL) {
        return -100;
    }
    return GUI_RadioButton_getState(e->widget);
}

void getButtonExtents(void) {
    rnd_gdrawGetButtonExtents();
}

void getPulldownExtents(void) {
    rnd_gdrawGetPulldownExtents();
}

int setPulldownState(FORMELEM *e, int index) {
    if (e->widget == NULL) {
        return -100;
    }
    GUI_Choice_select(e->widget, index);
    return 0;
}

int getPulldownState(FORMELEM *e) {
    if (e->widget == NULL) {
        return -100;
    }
    return GUI_Choice_getSelectedItem(e->widget);
}

void getListExtents(void) {
    rnd_gdrawGetListExtents();
}

int setListSelect(FORMELEM *e, int index, int state) {
    if (e->widget == NULL) {
        return -100;
    }
    rnd_gdrawSetListState(e->widget, index, state, 0);
    return 0;
}

int getListSelect(FORMELEM *e, int index) {
    if (e->widget == NULL) {
        return -100;
    }
    return GUI_List_isIndexSelected(e->widget, index);
}

void getStringsExtents(void) {
    GUI_Graphics_getStringSize();
}

void getStringsVisibleLength(void) {
    rnd_gdrawGetStringsVisibleLength();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", colorValue);

void esp_colorNameToValue(void) {
    colorValue();
}

int isSimilarColor(int c1, int c2) {
    int r1, g1, b1;
    int r2, g2, b2;

    r1 = c1 & 0xFF;
    g1 = (c1 >> 8) & 0xFF;
    b1 = (c1 >> 16) & 0xFF;
    r2 = c2 & 0xFF;
    g2 = (c2 >> 8) & 0xFF;
    b2 = (c2 >> 16) & 0xFF;
    if ((r1 - r2 > -48 && r1 - r2 < 48) && (g1 - g2 > -48 && g1 - g2 < 48) && (b1 - b2 > -48 && b1 - b2 < 48)) {
        return 0;
    }
    return -1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", distance_tab);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132990);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_001329A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_001329B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_001329C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_001329C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_001329D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_001329DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_001329E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_001329EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_001329F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A34);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132A9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132AA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132AAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132AB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132AC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132AD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132AE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132AEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132AF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132B98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132BA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132BB0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132BB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132BC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132BD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132BDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132BE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132BF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132BFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132C98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132CA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132CB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132CC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132CCC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132CD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132CF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132CFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132D98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132DAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132DB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132DC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132DD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132DE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132DF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132E98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132EA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132EAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132EBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132EC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132ED8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132EE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132EF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F68);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132F9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132FA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132FB0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132FBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132FC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132FD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132FDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132FE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132FE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132FF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132FF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00133004);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_0013300C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00133014);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_0013301C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00133028);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00133030);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_0013303C);
