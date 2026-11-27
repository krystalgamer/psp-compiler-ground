/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/iconv.h"

u16 unicodeToJisx0201(u16 c) {
    if (c < 0xFF) {
        return c;
    }
    if (c >= 0xFF61 && c <= 0xFF9F) {
        return c - 0xFEC0;
    }
    return 0;
}

u16 unicodeToJisx0208(u16 c) {
    unsigned int hi;
    unsigned int lo;
    const u16 *t;

    hi = c >> 8;
    lo = c & 0xFF;
    t = unicodeToJisx0208_map[hi];
    if (t == NULL) {
        return 0;
    }
    return t[lo];
}

u16 unicodeToJisx0212(u16 c) {
    unsigned int hi;
    unsigned int lo;
    const u16 *t;

    hi = c >> 8;
    lo = c & 0xFF;
    t = unicodeToJisx0212_map[hi];
    if (t == NULL) {
        return 0;
    }
    return t[lo];
}

u16 jisx0201ToUnicode(u16 c) {
    if (c < 0x7F) {
        if (c == 0x5C) {
            return 0x5C;
        }
        if (c == 0x7E) {
            return 0x7E;
        }
        return c;
    }
    if (c >= 0xA1 && c <= 0xDF) {
        return c + 0xFEC0;
    }
    return 0x3F;
}

u16 jisx0208ToUnicode(u16 c) {
    unsigned int hi;
    unsigned int lo;
    u16 u;

    hi = c >> 8;
    lo = c & 0xFF;
    if (hi >= 0x21 && hi <= 0x7E && lo >= 0x21 && lo <= 0x7E) {
        u = jisx0208ToUnicodeTable[(hi - 0x21) * 0x5E + (lo - 0x21)];
        if (u == 0) {
            return 0x3F;
        }
        return u;
    }
    return 0x3F;
}

u16 jisx0212ToUnicode(u16 c) {
    unsigned int hi;
    unsigned int lo;
    u16 u;

    hi = c >> 8;
    lo = c & 0xFF;
    if (hi >= 0x21 && hi <= 0x7E && lo >= 0x21 && lo <= 0x7E) {
        u = jisx0212ToUnicodeTable[(hi - 0x21) * 0x5E + (lo - 0x21)];
        if (u == 0) {
            return 0x3F;
        }
        return u;
    }
    return 0x3F;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", ucs2ToUtf8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", utf8ToUcs2);

int utf8nlen(const u8 *s, int max) {
    int n;
    int k;

    if (s == NULL || max == 0) {
        return 0;
    }
    n = 0;
    while (*s != 0) {
        if (!(*s & 0x80)) {
            k = 1;
        } else if ((*s & 0x80) && (*s & 0x60) == 0x40) {
            k = 2;
        } else if ((*s & 0x80) && (*s & 0x70) == 0x60) {
            k = 3;
        } else {
            k = 1;
        }
        if (n + k > max) {
            break;
        }
        s += k;
        n += k;
    }
    return n;
}
extern const char B64[];
unsigned int strlen(const char *s);
char *strcpy(char *d, const char *s);
void *memset(void *p, int c, unsigned int n);
void *MEM_malloc(void *pool, unsigned int n);
void MEM_free(void *pool, void *p);

#define ENC(c) ((c) ? B64[c] : 'A')
char *tobase64(char *s) {
    int len;
    char *out;
    char *buf;
    int i;
    int j;
    int pad;

    j = 0;
    pad = 0;
    len = strlen(s);
    out = MEM_malloc(0, len * 2);
    buf = MEM_malloc(0, len * 2);
    memset(buf, 0, len * 2);
    strcpy(buf, s);
    if (len / 3 * 3 == len - 1) {
        pad = 1;
    } else if (len / 3 * 3 == len - 2) {
        pad = 2;
    }
    for (i = 0; i < len; i += 3) {
        out[j] = ENC(buf[i] >> 2);
        out[j + 1] = ENC(((buf[i] & 3) << 4) | (buf[i + 1] >> 4));
        out[j + 2] = ENC(((buf[i + 1] & 0xF) << 2) | (buf[i + 2] >> 6));
        out[j + 3] = ENC(buf[i + 2] & 0x3F);
        j += 4;
    }
    out[j] = 0;
    if (pad == 1) {
        out[j - 1] = '=';
        out[j - 2] = '=';
    } else if (pad == 2) {
        out[j - 1] = '=';
    }
    MEM_free(0, buf);
    return out;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", ucs2ToJis);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", ucs2ToSjis);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", ucs2ToEuc);

int ucs2ToAscii(u8 *dst, const u16 *src, int len) {
    int i;
    int n;

    n = 0;
    for (i = 0; i < len; i++) {
        if (dst != NULL) {
            *dst++ = *src;
        }
        n++;
        src++;
    }
    return n;
}

int glanceEncode(const u8 *s, int len) {
    int state;
    int i;
    int ret;
    u8 c;

    state = 0;
    i = 0;
    ret = 0;
    for (; i < len; i++) {
        c = s[i];
        if (state == 0) {
            if (c >= 0x20 && c <= 0x7E) {
                continue;
            }
            if (c < 7 || c == 0x7F) {
                continue;
            }
            if (c == 0xFF) {
                continue;
            }
            if (c == 0x1B) {
                state = 1;
            } else {
                if (c >= 7 && c <= 13) {
                    continue;
                }
                if (c >= 0xE && c <= 0x1F) {
                    continue;
                }
                if ((c >= 0x80 && c <= 0x8D) || (c >= 0x90 && c <= 0xA0)) {
                    ret = 2;
                    break;
                }
                if (c == 0xFE) {
                    ret = 3;
                    break;
                }
            }
            ret = 4;
        } else if (state == 1) {
            if (c == '$') {
                state = 2;
            } else if (c == '(') {
                state = 3;
            } else {
                state = 0;
            }
        } else if (state == 2) {
            state = 0;
            if (c == '@' || c == 'B') {
                ret = 1;
                break;
            }
        } else {
            state = 0;
            if (c == 'B' || c == 'I' || c == 'J') {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int checkASCII(const u8 *s, int len) {
    int i;
    int r;
    u8 c;

    r = 0;
    for (i = 0; i < len; i++) {
        c = s[i];
        if (c >= 7 && c <= 13) {
            continue;
        }
        if (c >= 0x20 && c <= 0x7E) {
            continue;
        }
        r = -1;
        break;
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", checkJIS);

int checkShiftJIS(const u8 *s, int len) {
    int state;
    u8 lead;
    int ret;
    int i;
    u8 c;

    lead = 0;
    state = 0;
    i = 0;
    ret = 0;
    for (; i < len; i++) {
        c = s[i];
        if (state == 0) {
            if (c >= 7 && c <= 13) {
                continue;
            }
            if (c >= 0x20 && c <= 0x7E) {
                continue;
            }
            if (c >= 0xA1 && c <= 0xDF) {
                ret |= 2;
            } else if (c >= 0x81 && c <= 0x9F) {
                state = 1;
                lead = c;
                ret |= 1;
            } else if (c >= 0xE0 && c <= 0xEF) {
                state = 2;
                lead = c;
                ret |= 1;
            } else {
                ret = -1;
                break;
            }
        } else if (state == 1) {
            if ((c >= 0x40 && c <= 0x7E) || (c >= 0x80 && c <= 0xFC)) {
                state = 0;
                if (lead == 0x87 && c < 0x9E) {
                    ret |= 4;
                } else if (lead >= 0x85 && lead <= 0x87) {
                    ret |= 8;
                } else if (lead == 0x88 && c < 0x9E) {
                    ret |= 8;
                }
            } else {
                ret = -1;
                break;
            }
        } else {
            if ((c >= 0x40 && c <= 0x7E) || (c >= 0x80 && c <= 0xFC)) {
                state = 0;
                if (lead >= 0xED && lead <= 0xEE) {
                    ret |= 4;
                } else if (lead >= 0xEB && lead <= 0xEF) {
                    ret |= 8;
                }
            } else {
                ret = -1;
                break;
            }
        }
    }
    return ret;
}

int checkEUC(const u8 *s, int len) {
    int state;
    int i;
    int ret;
    u8 c;

    state = 0;
    i = 0;
    ret = 0;
    for (; i < len; i++) {
        c = s[i];
        if (state == 0) {
            if (c >= 7 && c <= 13) {
                continue;
            }
            if (c >= 0x20 && c <= 0x7E) {
                continue;
            }
            if (c == 0x8E) {
                state = 1;
                ret |= 2;
            } else if (c >= 0xA1 && c <= 0xFE) {
                state = 2;
                ret |= 1;
                if (c == 0xAD || (c >= 0xF9 && c <= 0xFC)) {
                    ret |= 4;
                } else if (c >= 0xA9 && c <= 0xAF) {
                    ret |= 8;
                } else if (c >= 0xF5 && c <= 0xFE) {
                    ret |= 8;
                }
            } else {
                ret = -1;
                break;
            }
        } else if (state == 1) {
            if (c >= 0xA1 && c <= 0xFE) {
                state = 0;
            } else {
                ret = -1;
                break;
            }
        } else {
            if (c >= 0xA1 && c <= 0xFE) {
                state = 0;
            } else {
                ret = -1;
                break;
            }
        }
    }
    return ret;
}

int checkUTF8(const u8 *s, int len) {
    int state;
    int count;
    int i;
    int ok;
    u8 c;

    state = 0;
    count = 0;
    for (i = 0; i < len; i++) {
        c = s[i];
        switch (state) {
        case 0:
            if (c >= 0xE0 && c <= 0xEF) {
                state = 3;
            } else if (c >= 0xC0 && c <= 0xDF) {
                state = 2;
            } else if ((s8)c < 0) {
                return 4;
            }
            break;
        case 3:
            ok = c >= 0x80 && c <= 0xBF;
            state = 4;
            if (!ok) {
                return 4;
            }
            break;
        case 2:
        case 4:
            ok = c >= 0x80 && c <= 0xBF;
            count++;
            state = 0;
            if (!ok) {
                return 4;
            }
            break;
        }
        if (count >= 5) {
            return 5;
        }
    }
    return 4;
}

int checkEncode(unsigned char *s, int n)
{
    int r;
    int sj;
    int euc;

    r = checkUTF8(s, n);
    if (r != 5) {
        r = glanceEncode(s, n);
        if (r == 4) {
            sj = checkShiftJIS(s, n);
            euc = checkEUC(s, n);
            if (sj >= 0) {
                if (euc >= 0) {
                    if (!(sj & 1))
                        r = 3;
                } else
                    r = 2;
            } else {
                r = (euc >= 0) + 2;
            }
        }
    }
    return r;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", B64);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", jisToUcs2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", sjisToUcs2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", eucToUcs2);

int asciiToUcs2(u16 *dst, const u8 *src, int len) {
    int i;
    int n;

    n = 0;
    for (i = 0; i < len; i++) {
        if (dst != NULL) {
            *dst++ = *src;
        }
        n++;
        src++;
    }
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", utf8ToSjis);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", sjisToUtf8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", utf8ToEuc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", eucToUtf8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_03);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_21);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_22);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_23);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_25);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_26);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_32);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_33);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_4e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_4f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_51);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_52);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_53);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_55);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_56);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_57);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_59);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_5a);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_5b);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_5c);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_5d);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_5e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_5f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_61);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_62);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_63);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_65);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_66);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_67);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_68);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_69);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_6a);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_6b);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_6c);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_6d);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_6e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_6f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_71);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_72);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_73);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_75);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_76);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_77);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_79);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_7a);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_7b);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_7c);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_7d);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_7e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_7f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_81);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_82);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_83);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_85);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_86);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_87);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_89);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_8a);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_8b);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_8c);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_8d);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_8e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_8f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_91);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_92);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_93);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_95);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_96);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_97);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_99);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_9a);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_9b);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_9c);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_9d);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_9e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_9f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0208_ff);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_01);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_02);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_03);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_21);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_32);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_4e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_4f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_51);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_52);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_53);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_55);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_56);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_57);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_59);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_5a);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_5b);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_5c);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_5d);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_5e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_5f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_61);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_62);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_63);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_65);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_66);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_67);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_68);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_69);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_6a);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_6b);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_6c);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_6d);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_6e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_6f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_71);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_72);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_73);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_75);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_76);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_77);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_79);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_7a);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_7b);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_7c);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_7d);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_7e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_7f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_81);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_82);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_83);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_85);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_86);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_87);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_89);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_8a);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_8b);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_8c);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_8d);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_8e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_8f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_91);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_92);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_93);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_95);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_96);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_97);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_99);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_9a);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_9b);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_9c);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_9d);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_9e);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_9f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_f9);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_fa);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", unicodeToJisx0212_ff);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", jisx0208ToUnicodeTable);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iconv", jisx0212ToUnicodeTable);
