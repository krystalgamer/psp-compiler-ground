/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
int UDomiString_CompareBinary(const DOMChar *a, unsigned int alen, const DOMChar *b, unsigned int blen);
void SDomiNodeSet_Initialize(SDomiNodeSet *s, const SDomiStringH *name, SDomiNode *root, int (*build)(SDomiNodeSet *));
void SDomiNodeSet_Finalize(SDomiNodeSet *s);
void SDomiNodeSet_Free(SDomiNodeSet *s);

void SDomiNodeSetSet_DeleteAll(SDomiSLink *head) {
    SDomiNodeSet *s;

    while ((s = (SDomiNodeSet *)SDomiSLink_RemoveFirst(head)) != NULL) {
        SDomiNodeSet_Finalize(s);
        UDomiMemory_Free(s);
    }
}

void SDomiNodeSetSet_Free(SDomiSLink *head) {
    SDomiNodeSet *s;

    for (s = (SDomiNodeSet *)SDomiSLink_first(head); s != NULL; s = (SDomiNodeSet *)SDomiSLink_next(head, &s->link)) {
        SDomiNodeSet_Free(s);
    }
}

SDomiNodeSet *SDomiNodeSetSet_Prepare(SDomiSLink *head, const SDomiString *name, SDomiNode *root, int (*build)(SDomiNodeSet *)) {
    SDomiNodeSet *s;
    SDomiNodeSet *r;
    SDomiStringH h;

    for (s = (SDomiNodeSet *)SDomiSLink_first(head); s != NULL; s = (SDomiNodeSet *)SDomiSLink_next(head, &s->link)) {
        r = s;
        if (s->root == root && s->build == build &&
            UDomiString_CompareBinary(s->name.d->s.str, s->name.d->s.len, name->str, name->len) == 0) {
            goto found;
        }
    }
    r = NULL;
    SDomiStringH_Init(&h);
    if (SDomiStringH_Set(&h, name)) {
        r = UDomiMemory_Allocate(sizeof(SDomiNodeSet));
        if (r != NULL) {
            SDomiNodeSet_Initialize(r, &h, root, build);
            SDomiSLink_Insert(head, &r->link);
        }
    }
    goto end;
found:
    SDomiSLink_Remove(head, &s->link);
    SDomiSLink_Insert(head, &s->link);
    return r;
end:
    SDomiStringH_Finalize(&h);
    return r;
}
