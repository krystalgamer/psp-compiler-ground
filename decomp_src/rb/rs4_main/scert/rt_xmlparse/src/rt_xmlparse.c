#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_xmlparse_create(void);
int rt_xmlparse_destroy(void);
int rt_xmlparse_is_document_complete(void);
int rt_xmlparse_parse_buf(void);
int rt_xmlparse_set_character_data_cb(void);
int rt_xmlparse_set_element_end_cb(void);
int rt_xmlparse_set_element_start_cb(void);
int rt_xmlparse_set_user_data(void);

int rt_xmlparse_create(void) {
    return 4;
}

int rt_xmlparse_destroy(void) {
    return 4;
}

int rt_xmlparse_parse_buf(void) {
    return 4;
}

int rt_xmlparse_set_user_data(void) {
    return 4;
}

int rt_xmlparse_set_element_start_cb(void) {
    return 4;
}

int rt_xmlparse_set_element_end_cb(void) {
    return 4;
}

int rt_xmlparse_set_character_data_cb(void) {
    return 4;
}

int rt_xmlparse_is_document_complete(void) {
    return 4;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_xmlparse/src/rt_xmlparse", rcsid_10CE18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_xmlparse/src/rt_xmlparse", header_rcsid_10CE7C);
