/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct CTYPE { char *ext; int type; } CTYPE;
extern CTYPE contentType[];
unsigned int strlen(const char *s);
int strncmp(const char *a, const char *b, unsigned int n);
int strcmp(const char *a, const char *b);
typedef struct FILEDATA { int type; int size; void *data; } FILEDATA;
void *MEM_malloc(int pool, unsigned int size);
int fileContentType(char *path);
int directoryCheck(char *path);
void *readCFData(char *path, int *size);
void MEM_free(M2C_UNK, void *);                  /* extern */
extern unsigned char search;


int sprintf(char *buf, const char *fmt, ...);
void deleteFileData(void *arg0);
char *URLencode(char *p, int c) {
    char *dst = p;

    if (c == ' ') {
        *p++ = '+';
    } else if (c == '-' || c == '_') {
        *p++ = c;
    } else if (c == '.' || c == '*') {
        *p++ = c;
    } else if (c < '0' || (c > '9' && c < 'A') || (c > 'z' || (c > 'Z' && c < 'a'))) {
        p += sprintf(p, "%%%02X", c);
    } else {
        *p++ = c;
    }
    *p = 0;
    return dst;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int newFormCollect(int arg0, int arg1, void *arg2) {
    M2C_FIELD(arg2, int *, 4) = arg0;
    M2C_FIELD(arg2, int *, 8) = arg1;
    M2C_FIELD(arg2, int *, 0xC) = 0;
    M2C_FIELD(arg2, int *, 0x10) = 0;
    M2C_FIELD(arg2, int *, 0x14) = 0;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void deleteFormCollect(void *arg0) {
    int temp_a0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_s1;
    void *var_s0;

    var_s0 = M2C_FIELD(arg0, void **, 0x10);
    if (var_s0 != NULL) {
        do {
            temp_a1 = M2C_FIELD(var_s0, void **, 0);
            temp_s1 = M2C_FIELD(var_s0, void **, 0xC);
            if (temp_a1 != NULL) {
                MEM_free(0, temp_a1);
            }
            temp_a1_2 = M2C_FIELD(var_s0, void **, 4);
            if (temp_a1_2 != NULL) {
                MEM_free(0, temp_a1_2);
            }
            temp_a0 = M2C_FIELD(var_s0, int *, 8);
            if (temp_a0 != 0) {
                deleteFileData(temp_a0);
            }
            MEM_free(0, var_s0);
            var_s0 = temp_s1;
        } while (temp_s1 != NULL);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", getFormCollectData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", addFormCollectSymbol);

int fileContentType(char *name) {
    char *ext;
    char *p;
    int i;

    p = name;
    ext = p;
    while (*p) {
        if (*p == '.')
            ext = p;
        p++;
    }
    for (i = 0; contentType[i].ext != NULL; i++) {
        if (strcmp(ext, contentType[i].ext) == 0)
            break;
    }
    return contentType[i].type;
}

FILEDATA *newFileData(char *path) {
    FILEDATA *fd = MEM_malloc(0, sizeof(FILEDATA));
    if (fd == NULL) {
        return NULL;
    }
    fd->type = fileContentType(path);
    if (!directoryCheck(path)) {
        return NULL;
    }
    fd->data = readCFData(path, &fd->size);
    if (fd->data == NULL) {
        fd->size = 0;
    }
    return fd;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void deleteFileData(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    if (temp_a1 != NULL) {
        MEM_free(0, temp_a1);
    }
    MEM_free(0, arg0);
}

char *memstr(char *s, int n, char *pat) {
    int len = strlen(pat);
    while (n > 0 && n >= len) {
        if (*s == *pat && strncmp(s, pat, len) == 0) {
            return s;
        }
        n--;
        s++;
    }
    return NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void clearSearchStrings(void) {
    M2C_FIELD(&search, int *, 0) = 0;
    M2C_FIELD(&search, int *, 4) = 0;
    M2C_FIELD(&search, int *, 0xC) = 0;
    M2C_FIELD(&search, int *, 8) = 0;
    M2C_FIELD(&search, int *, 0x10) = 0;
    if (M2C_FIELD(&search, int *, 0x14) != 0) {
        MEM_free(0, M2C_FIELD(&search, int *, 0x14));
        M2C_FIELD(&search, int *, 0x14) = 0;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", searchStrings);
