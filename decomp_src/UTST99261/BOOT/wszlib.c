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

int read_code_length(ZBUF *zb, HCODE *out, HCODE *cl, int bits, int maxBits, int n, int *minLen, int *maxLen) {
    int i;
    int prev;
    int maxl;
    unsigned int code;
    unsigned int bit;
    int len;
    int found;
    int k;
    int r;
    unsigned int j;

    i = 0;
    prev = -1;
    *minLen = 15;
    maxl = 0;
    while (i < n) {
        code = 0;
        len = bits;
        found = 0;
        if ((r = readBits(zb, len, 1, &code)) != 0) {
            return r;
        }
        for (k = 0; k < 19; k++) {
            if (cl[k].len == len && code == cl[k].code) {
                found = 1;
                break;
            }
        }
        if (!found) {
            while (len <= maxBits) {
                if ((r = readBits(zb, 1, 1, &bit)) != 0) {
                    return r;
                }
                len++;
                code = (code << 1) | bit;
                for (k = 0; k < 19; k++) {
                    if (cl[k].len == len && code == cl[k].code) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (!found) {
                return -3;
            }
        }
        if (k < 16) {
            out[i].len = k;
            i++;
            prev = k;
            if (k > 0 && k < *minLen) {
                *minLen = k;
            }
            if (maxl < k) {
                maxl = k;
            }
        } else if (k == 16) {
            if (prev == -1) {
                return -3;
            }
            if ((r = readBits(zb, 2, 0, &bit)) != 0) {
                return r;
            }
            for (j = 0; j < bit + 3; j++) {
                out[i].len = prev;
                i++;
            }
        } else if (k == 17) {
            if ((r = readBits(zb, 3, 0, &bit)) != 0) {
                return r;
            }
            i += bit + 3;
        } else if (k == 18) {
            if ((r = readBits(zb, 7, 0, &bit)) != 0) {
                return r;
            }
            i += bit + 11;
        } else {
            return -3;
        }
    }
    *maxLen = maxl;
    return 0;
}

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

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", length_tab);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", distance_tab);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wszlib", D_00132990);

