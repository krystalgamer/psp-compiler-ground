/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern const SDomiNodeVt gDomiCharacterDataVt;

void SDomiCharacterData_Initialize(SDomiCharacterData *n, const SDomiNodeVt *vt, int type, struct SDomiDocument *doc, const SDomiStringH *name) {
    if (vt == NULL) {
        vt = &gDomiCharacterDataVt;
    }
    SDomiExternalNode_Initialize(&n->e.n, vt, 0, type, doc, name);
    SDomiStrAcu_Initialize(&n->data, 4);
}

int SDomiCharacterData_set_data(SDomiCharacterData *n, const SDomiString *s) {
    SDomiStrAcu_Reset(&n->data);
    SDomiStrAcu_Insert(&n->data, n->data.len, s);
    return 0;
}

int SDomiCharacterData_substringData(SDomiCharacterData *n, unsigned int off, unsigned int count, SDomiString *out) {
    unsigned int len = n->data.len;

    if (len < off) {
        return 1;
    }
    len -= off;
    if (len < count) {
        count = len;
    }
    out->len = count;
    out->str = n->data.buf + off;
    return 0;
}

int SDomiCharacterData_insertData(SDomiCharacterData *n, unsigned int off, const SDomiString *s) {
    if (n->data.len < off) {
        return 1;
    }
    return SDomiStrAcu_Insert(&n->data, off, s) ? 0 : -1;
}

int SDomiCharacterData_deleteData(SDomiCharacterData *n, unsigned int off, unsigned int count) {
    if (n->data.len < off) {
        return 1;
    }
    SDomiStrAcu_Delete(&n->data, off, count);
    SDomiStrAcu_Truncate(&n->data);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiCharacterData", SDomiCharacterData_replaceData);
