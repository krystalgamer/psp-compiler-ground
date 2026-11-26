/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void commonProc_html_text_inline(void *a0, void *a1, void *a2, int tag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_inline", commonProc_html_text_inline);

void html_ABBR(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x2);
}

void html_ACRONYM(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x3);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_inline", html_BR);

void html_CITE(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x14);
}

void html_CODE(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x15);
}

void html_DFN(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x1A);
}

void html_EM(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x1F);
}

void html_KBD(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x35);
}

void html_Q(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x49);
}

void html_SAMP(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x4B);
}

void html_SPAN(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x4F);
}

void html_STRONG(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x51);
}

void html_VAR(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x61);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_inline", html_A);
