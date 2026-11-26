/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
extern unsigned char _DOMhref;
BOX *getBodyBox(BOX *box);
char *getDOMAttributeValue(void *node, void *name);
void URL_splitURL(void **parts, char *url);
void *MEM_malloc(int pool, unsigned int size);
void MEM_free(int pool, void *p);
unsigned int strlen(const char *s);
char *strcpy(char *d, const char *s);


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_meta", unquote_str);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_meta", html_META);

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_NOSCRIPT(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_SCRIPT(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_STYLE(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_LINK(void) {
    return 0;
}

int html_BASE(void *node, BOX *box) {
    void *parts[12];
    BOX *body;
    char *url;
    body = getBodyBox(box);
    url = getDOMAttributeValue(node, &_DOMhref);
    if (url != NULL) {
        URL_splitURL(parts, url);
        if (parts[0] == NULL || parts[2] == NULL) {
            MEM_free(0, url);
            return 0;
        }
        if (M2C_FIELD(body->geom, void **, 0x28) != NULL) {
            MEM_free(0, M2C_FIELD(body->geom, void **, 0x28));
        }
        M2C_FIELD(body->geom, char **, 0x28) = url;
    }
    return 0;
}
