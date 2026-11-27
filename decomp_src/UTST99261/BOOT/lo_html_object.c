/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
BOX *createBox(void *ctx, int type);
BOX *getBodyBox(void *box);
void linkBox(BOX *box, BOX *parent, BOX *prev);
void initNoneContent(BOX *box, void *ctx);
void initBoxProperty(BOX *box);
void applyCSSExtStyleSheetToBox(void *node, BOX *box);
void applyCSSInlinePropertyToBox(void *node, BOX *box);
void delLinkBox(void *box);
void freeBox(void *box, int a1);

extern int D_00584D08;


#ifndef NULL
#define NULL ((void *)0)
#endif
int isImageMimeType(signed char *arg0) {
    return (unsigned int) (UTL_guessMIMEType(arg0) - 1) < 4U;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int isImageFileType(signed char *arg0) {
    return (unsigned int) (UTL_guessMIMETypeFromName(arg0) - 1) < 4U;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_object", html_OBJECT);

#ifndef NULL
#define NULL ((void *)0)
#endif

void html_OBJECT_after(void) {
    D_00584D08 = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_PARAM(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_object", html_FRAME);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_object", D_0013F13C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_object", html_FRAMESET);

BOX *html_NOFRAMES(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 0;
    box->html = 0x40;
    initNoneContent(box, node);
    initBoxProperty(box);
    M2C_FIELD(getBodyBox(parent)->geom, int *, 0x88) = 1;
    return box;
}

void html_NOFRAMES_after(void *a0, void *box) {
    if (box != NULL) {
        M2C_FIELD(getBodyBox(box)->geom, int *, 0x88) = 0;
        delLinkBox(box);
        freeBox(box, 0);
    }
}

BOX *html_IFRAME(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x30;
    initNoneContent(box, node);
    initBoxProperty(box);
    return box;
}
