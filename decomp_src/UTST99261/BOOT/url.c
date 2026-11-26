/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

typedef struct QUEUE {
    struct QUEUE *next;
    struct QUEUE *prev;
} QUEUE;

extern const char _ctype_[];
int UTL_mfileread(void *f, void *buf, unsigned int n);
QUEUE *UTL_peekqueue(QUEUE *q, QUEUE *e);
int UTL_mfilewrite(void *f, void *buf, unsigned int n);

M2C_UNK createGifContext();                         /* extern */
M2C_UNK deleteGifContext();                         /* extern */
M2C_UNK initializeGifContext();                     /* extern */
M2C_UNK setGifBuffer();                             /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", trimspace);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001322F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001322F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001322FC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", toAbsoluteURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_free);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_setScheme);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_setHost);

#ifndef NULL
#define NULL ((void *)0)
#endif
void URL_setPort(void *arg0, int arg1) {
    if (M2C_FIELD(arg0, int *, 8) >= 0) {
        M2C_FIELD(arg0, int *, 8) = arg1;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_setPath);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_setQuery);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_setAnchor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_toString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_toAbsoluteURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_equals);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_splitURL);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132328);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_encode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_decode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_checkFileStrage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_toLocalFileName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_isSupportedMIMEType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_isSupportedFileType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_guessMIMETypeFromName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_guessMIMEType);

int UTL_isNumber(char *s, int len) {
    int i;

    if (s == NULL) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        if (!((_ctype_ + 1)[(int)*s] & 4)) {
            return 0;
        }
        s++;
    }
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void UTL_initqueue(void *arg0) {
    M2C_FIELD(arg0, void **, 0) = arg0;
    M2C_FIELD(arg0, void **, 4) = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void UTL_enqueue(M2C_UNK *arg0, M2C_UNK *arg1) {
    M2C_UNK *temp_v0;

    temp_v0 = M2C_FIELD(arg0, M2C_UNK **, 4);
    M2C_FIELD(arg0, M2C_UNK **, 4) = arg1;
    *temp_v0 = arg1;
    M2C_FIELD(arg1, M2C_UNK **, 0) = arg0;
    M2C_FIELD(arg1, M2C_UNK **, 4) = temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *UTL_dequeue(void **arg0) {
    void *temp_v0;
    void *temp_v1;
    void *var_v0;

    temp_v1 = *arg0;
    var_v0 = NULL;
    if (arg0 != temp_v1) {
        temp_v0 = M2C_FIELD(temp_v1, void **, 0);
        *arg0 = temp_v0;
        M2C_FIELD(temp_v0, void ***, 4) = arg0;
        M2C_FIELD(temp_v1, void **, 0) = NULL;
        M2C_FIELD(temp_v1, int *, 4) = 0;
        var_v0 = temp_v1;
    }
    return var_v0;
}

void UTL_relqueue(QUEUE *q, QUEUE *e) {
    QUEUE *next;
    QUEUE *prev;

    next = e->next;
    prev = e->prev;
    prev->next = next;
    next->prev = prev;
    e->next = NULL;
    e->prev = NULL;
}

void UTL_insqueue(QUEUE *q, QUEUE *pos, QUEUE *e) {
    QUEUE *prev;

    prev = pos->prev;
    e->next = pos;
    e->prev = prev;
    pos->prev = e;
    prev->next = e;
}

QUEUE *UTL_peekqueue(QUEUE *q, QUEUE *e) {
    QUEUE *n;

    if (e == NULL) {
        e = q;
    }
    n = e->next;
    if (q != n) {
        return n;
    }
    return NULL;
}

QUEUE *UTL_peekprevqueue(QUEUE *q, QUEUE *e) {
    QUEUE *n;

    if (e == NULL) {
        e = q;
    }
    n = e->prev;
    if (q != n) {
        return n;
    }
    return NULL;
}

int UTL_sizequeue(QUEUE *q) {
    QUEUE *e;
    int n;

    e = NULL;
    n = 0;
    while ((e = UTL_peekqueue(q, e)) != NULL) {
        n++;
    }
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfilecreate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfiledelete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfileread);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfilewrite);

int UTL_mfilegetc(void *f) {
    u8 c;

    if (UTL_mfileread(f, &c, 1) != 1) {
        return -1;
    }
    return c;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfileclean);

int UTL_mfileputc(void *f, int c) {
    u8 ch;

    ch = c;
    return UTL_mfilewrite(f, &ch, 1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);

void UTL_mfileputs(int arg0, signed char *arg1) {
    UTL_mfilewrite(arg0, arg1, strlen(arg1));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int UTL_mfilesize(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfilepos);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfileseek);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfileduplicate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_strword);

#ifndef NULL
#define NULL ((void *)0)
#endif
int directoryCheck(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", pathMake);

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_gifCreateContext(void) {
    createGifContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_gifDestroyContext(void) {
    deleteGifContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_gifFinalizeContext(void) {
    initializeGifContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_gifInputData(void) {
    setGifBuffer();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int IMG_gifStartDecompress(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", IMG_gifGetImageData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", IMG_gifReadHeader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", IMG_gifScanLines);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013234C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132350);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132354);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013235C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132360);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132364);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132368);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132370);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132374);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132378);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013237C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132384);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132388);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013238C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132390);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132394);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013239C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132404);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132410);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013241C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132428);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", cnt_tbl);
