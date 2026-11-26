/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"

void SDomiStringH_Finalize(SDomiStringH *h) {
    if (!SDomiStringData_Free(h->d)) {
        UDomiMemory_Free(h->d);
    }
    h->d = &gSDnull;
}

int SDomiStringH_Set(SDomiStringH *h, const SDomiString *s) {
    unsigned int len = s->len;
    SDomiStringData *d;

    d = UDomiMemory_Allocate(len * 2 + sizeof(SDomiStringData));
    if (d == NULL) {
        return 0;
    }
    UDomiString_Copy((DOMChar *)(d + 1), s->str, len);
    d->s.len = len;
    d->s.str = (DOMChar *)(d + 1);
    d->ref = 1;
    SDomiStringH_Finalize(h);
    h->d = d;
    return 1;
}

void SDomiStringH_Assign(SDomiStringH *h, const SDomiStringH *src) {
    SDomiStringData *d = &gSDnull;

    if (src != NULL) {
        d = src->d;
    }
    d->ref++;
    SDomiStringH_Finalize(h);
    h->d = d;
}
