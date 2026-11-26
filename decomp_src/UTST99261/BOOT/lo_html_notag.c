/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "nflayout.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_notag", normal_text);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_notag", normalizeText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_notag", pre_text);

BOX *getSpecialBehaviorParent(BOX *box) {
    s16 h;
    while (box != NULL) {
        h = box->html;
        if (h == 0x45 || h == 0x4D || h == 0x58) {
            return box;
        }
        box = box->parent;
    }
    return NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_notag", html_NOTAG);
