/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void *getBodyBox(void *box);
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_object", html_FRAMESET);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_object", html_NOFRAMES);

void html_NOFRAMES_after(void *a0, void *box) {
    if (box != NULL) {
        M2C_FIELD(M2C_FIELD(getBodyBox(box), void **, 0x20), int *, 0x88) = 0;
        delLinkBox(box);
        freeBox(box, 0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_object", html_IFRAME);
