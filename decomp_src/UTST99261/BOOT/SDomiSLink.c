/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"

SDomiSLink *SDomiSLink_first(SDomiSLink *head) {
    SDomiSLink *n = head->next;
    return n != head ? n : NULL;
}

SDomiSLink *SDomiSLink_next(SDomiSLink *head, SDomiSLink *cur) {
    SDomiSLink *n = cur->next;
    return n != head ? n : NULL;
}

void SDomiSLink_Insert(SDomiSLink *head, SDomiSLink *l) {
    if (l->next == NULL) {
        l->next = head->next;
        head->next = l;
    }
}

void SDomiSLink_Remove(SDomiSLink *head, SDomiSLink *l) {
    SDomiSLink *p;

    if (l->next == NULL) {
        return;
    }
    for (p = head; p->next != head; p = p->next) {
        if (p->next == l) {
            p->next = l->next;
            l->next = NULL;
            return;
        }
    }
}

SDomiSLink *SDomiSLink_RemoveFirst(SDomiSLink *head) {
    SDomiSLink *l = SDomiSLink_first(head);

    if (l != NULL) {
        head->next = l->next;
        l->next = NULL;
    }
    return l;
}

SDomiSLink *SDomiSLink_RemoveLast(SDomiSLink *head) {
    SDomiSLink *prev = head, *l, *n;

    l = SDomiSLink_first(head);
    for (n = l; n != NULL; n = SDomiSLink_next(head, n)) {
        prev = l;
        l = n;
    }
    prev->next = head;
    if (l != NULL) {
        l->next = NULL;
    }
    return l;
}
