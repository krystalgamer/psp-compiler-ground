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

typedef struct COLORNAME { int value; char *name; } COLORNAME;
extern COLORNAME D_0013303C[];
void *MEM_malloc(int, int);
void MEM_free(int, void *);
int strcasecmp(const char *, const char *);
unsigned int strlen(const char *);
int colorValue(name)
    char *name;
{
    int lo;
    int hi;
    int mid;
    int r;
    int g;
    int b;
    int len;
    int n;
    int pad;
    int cmp;
    int i;
    char c;
    char *rs;
    char *gs;
    char *bs;

    if (name == NULL) {
        return -100;
    }
    if (*name != '#') {
        lo = 0;
        hi = 0x92;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            cmp = strcasecmp(D_0013303C[mid].name, name);
            if (cmp == 0) {
                return D_0013303C[mid].value;
            }
            if (cmp < 0) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    } else {
        name++;
    }
    b = 0;
    g = 0;
    r = 0;
    bs = NULL;
    gs = NULL;
    len = strlen(name);
    n = (len + 2) / 3;
    pad = 3 - len % 3;
    if (pad == 3) {
        pad = 0;
    }
    rs = MEM_malloc(0, n + 1);
    memset(rs, 0, n + 1);
    if (len >= 2) {
        gs = MEM_malloc(0, n + 1);
        memset(gs, 0, n + 1);
    }
    if (len >= 3) {
        bs = MEM_malloc(0, n + 1);
        memset(bs, 0, n + 1);
    }
    if (rs != NULL) {
        memcpy(rs, name, n);
    }
    if (gs != NULL) {
        memcpy(gs, name + n, n);
    }
    if (bs != NULL) {
        memcpy(bs, name + n * 2, n - pad);
        memset(bs + (n - pad), '0', pad);
    }
    if (rs != NULL) {
        r = 0;
        for (i = 0; i < n && (c = rs[i]) != 0; i++) {
            if ((unsigned)(c - '0') < 10) {
                r = (r << 4) | (c & 0xF);
            } else if ((unsigned)(c - 'A') < 6 || (unsigned)(c - 'a') < 6) {
                r = (r << 4) | ((c & 0xF) + 9);
            } else if (c == 'O' || c == 'o') {
                r <<= 4;
            } else {
                MEM_free(0, rs);
                if (gs != NULL) {
                    MEM_free(0, gs);
                }
                if (bs != NULL) {
                    MEM_free(0, bs);
                }
                goto done;
            }
        }
        MEM_free(0, rs);
    }
    if (gs != NULL) {
        g = 0;
        for (i = 0; i < n && (c = gs[i]) != 0; i++) {
            if ((unsigned)(c - '0') < 10) {
                g = (g << 4) | (c & 0xF);
            } else if ((unsigned)(c - 'A') < 6 || (unsigned)(c - 'a') < 6) {
                g = (g << 4) | ((c & 0xF) + 9);
            } else if (c == 'O' || c == 'o') {
                g <<= 4;
            } else {
                MEM_free(0, gs);
                if (bs != NULL) {
                    MEM_free(0, bs);
                }
                goto done;
            }
        }
        MEM_free(0, gs);
    }
    if (bs != NULL) {
        b = 0;
        for (i = 0; i < n && (c = bs[i]) != 0; i++) {
            if ((unsigned)(c - '0') < 10) {
                b = (b << 4) | (c & 0xF);
            } else if ((unsigned)(c - 'A') < 6 || (unsigned)(c - 'a') < 6) {
                b = (b << 4) | ((c & 0xF) + 9);
            } else if (c == 'O' || c == 'o') {
                b <<= 4;
            } else {
                break;
            }
        }
        MEM_free(0, bs);
    }
done:
    return (r << 16) | (g << 8) | b;
}

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

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_001329A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_001329B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_001329C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_001329C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_001329D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_001329DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_001329E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_001329EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_001329F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A34);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132A9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132AA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132AAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132AB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132AC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132AD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132AE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132AEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132AF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132B98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132BA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132BB0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132BB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132BC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132BD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132BDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132BE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132BF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132BFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132C98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132CA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132CB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132CC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132CCC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132CD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132CF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132CFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132D98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132DAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132DB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132DC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132DD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132DE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132DF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132E98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132EA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132EAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132EBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132EC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132ED8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132EE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132EF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F68);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132F9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132FA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132FB0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132FBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132FC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132FD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132FDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132FE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132FE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132FF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00132FF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00133004);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_0013300C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00133014);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_0013301C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00133028);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_00133030);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/wscolor", D_0013303C);
