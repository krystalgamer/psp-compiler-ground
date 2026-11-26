/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern SDomiString gSnull;
extern SDomiStringH gSHnull;

static int ResizeAllocation(SDomiStrAcu *a, unsigned int size) {
    DOMChar *buf, *old;
    unsigned int len;

    if (a->alloc != size) {
        buf = NULL;
        if (size != 0) {
            buf = UDomiString_Allocate(size);
        }
        if (buf != NULL || size == 0) {
            len = a->len;
            old = a->buf;
            if (size < len) {
                len = size;
            }
            UDomiString_Copy(buf, old, len);
            a->len = len;
            a->buf = buf;
            UDomiString_Free(old);
            a->alloc = size;
        } else {
            return 0;
        }
    }
    return 1;
}

void SDomiStrAcu_Initialize(SDomiStrAcu *a, unsigned int grow) {
    a->grow = grow;
    a->alloc = 0;
    a->len = 0;
    a->buf = NULL;
}

void SDomiStrAcu_Finalize(SDomiStrAcu *a) {
    a->alloc = 0;
    UDomiString_Free(a->buf);
    a->len = 0;
    a->buf = NULL;
}

void SDomiStrAcu_Reset(SDomiStrAcu *a) {
    a->len = 0;
    SDomiStrAcu_Truncate(a);
}

int SDomiStrAcu_Truncate(SDomiStrAcu *a) {
    return ResizeAllocation(a, a->len);
}

int SDomiStrAcu_Allocate(SDomiStrAcu *a, unsigned int n) {
    if (a->alloc < n) {
        ResizeAllocation(a, n);
    }
}

int SDomiStrAcu_Insert(SDomiStrAcu *a, unsigned int pos, const SDomiString *s) {
    unsigned int n = s->len;
    unsigned int len = a->len;
    unsigned int newlen;
    unsigned int size;
    DOMChar *buf, *d, *p;

    newlen = len + n;
    if (len < pos) {
        pos = len;
    }
    if (a->alloc < newlen) {
        size = newlen + a->grow;
        buf = UDomiString_Allocate(size);
        if (buf == NULL) {
            return 0;
        }
        UDomiString_Copy(buf, a->buf, pos);
        d = buf + pos;
        UDomiString_Copy(d, s->str, n);
        d += n;
        p = a->buf + pos;
        UDomiString_Copy(d, p, len - pos);
        UDomiString_Free(a->buf);
        a->len = newlen;
        a->buf = buf;
        a->alloc = size;
    } else {
        DOMChar *q = a->buf + pos;
        UDomiString_Move(q + n, q, len - pos);
        UDomiString_Move(q, s->str, n);
        a->len = newlen;
    }
    return 1;
}

void SDomiStrAcu_Delete(SDomiStrAcu *a, unsigned int pos, unsigned int n) {
    unsigned int len = a->len;
    DOMChar *p;

    if (len < pos) {
        pos = len;
    }
    if (len < pos + n) {
        n = len - pos;
    }
    p = a->buf + pos;
    len -= n;
    UDomiString_Move(p, p + n, len - pos);
    a->len = len;
}

const SDomiString *AcsExterngSnull(void) {
    return &gSnull;
}

SDomiStringData *AcsExterngSDnull(void) {
    return &gSDnull;
}

SDomiStringH *AcsExterngSHnull(void) {
    return &gSHnull;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiStrAcu", gSnull);
