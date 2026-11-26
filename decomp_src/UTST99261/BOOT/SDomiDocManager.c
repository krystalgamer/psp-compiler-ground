/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
int UDomiString_CompareBinary(const DOMChar *a, unsigned int alen, const DOMChar *b, unsigned int blen);

typedef struct SDomiDocHolder {
    SDomiSLink link;
    SDomiDocument *doc;
    SDomiStringH id;
} SDomiDocHolder;

typedef struct SDomiDocManager {
    SDomiDocHolder *active;
    SDomiSLink trash;
} SDomiDocManager;

void SDomiDocHolder_Initialize(SDomiDocHolder *h);
void SDomiDocHolder_Finalize(SDomiDocHolder *h);
void SDomiDocManager_TrashActiveDocument(SDomiDocManager *m);
void SDomiDocManager_EmptyTrash(SDomiDocManager *m);

static SDomiDocHolder *RecoverPtr(SDomiSLink *l) {
    return (SDomiDocHolder *)l;
}

static void DeleteDocHolder(SDomiDocHolder *h) {
    h->doc->i.n.vt->Finalize(h->doc);
    UDomiMemory_Free(h->doc);
    SDomiDocHolder_Finalize(h);
    UDomiMemory_Free(h);
}

static int isDocID(SDomiDocHolder *h, const SDomiString *id) {
    int r = 0;

    if (h != NULL && UDomiString_CompareBinary(h->id.d->s.str, h->id.d->s.len, id->str, id->len) == 0) {
        r = 1;
    }
    return r;
}

static SDomiDocHolder *FindInTrash(SDomiDocManager *m, const SDomiString *id) {
    SDomiSLink *l;
    SDomiDocHolder *h;

    for (l = SDomiSLink_first(&m->trash); l != NULL; l = SDomiSLink_next(&m->trash, l)) {
        h = RecoverPtr(l);
        if (isDocID(h, id)) {
            return h;
        }
    }
    return NULL;
}

void SDomiDocHolder_Initialize(SDomiDocHolder *h) {
    h->link.next = NULL;
    SDomiStringH_Init(&h->id);
}

void SDomiDocHolder_Finalize(SDomiDocHolder *h) {
    SDomiStringH_Finalize(&h->id);
}

void SDomiDocManager_Initialize(SDomiDocManager *m) {
    m->active = NULL;
    m->trash.next = &m->trash;
}

void SDomiDocManager_Finalize(SDomiDocManager *m) {
    SDomiDocManager_TrashActiveDocument(m);
    SDomiDocManager_EmptyTrash(m);
}

int SDomiDocManager_Free(SDomiDocManager *m) {
    SDomiSLink *l = SDomiSLink_RemoveLast(&m->trash);

    if (l == NULL) {
        return 0;
    }
    DeleteDocHolder(RecoverPtr(l));
    return 1;
}

int SDomiDocManager_AddDocument(SDomiDocManager *m, const SDomiString *id, SDomiDocument *doc) {
    SDomiDocHolder *h = UDomiMemory_Allocate(sizeof(SDomiDocHolder));

    if (h != NULL) {
        SDomiDocHolder_Initialize(h);
        if (SDomiStringH_Set(&h->id, id)) {
            h->doc = doc;
            SDomiDocManager_TrashActiveDocument(m);
            m->active = h;
            return 1;
        }
        SDomiDocHolder_Finalize(h);
        UDomiMemory_Free(h);
    }
    doc->i.n.vt->Finalize(doc);
    UDomiMemory_Free(doc);
    return 0;
}

SDomiDocument *SDomiDocManager_ReuseDocument(SDomiDocManager *m, const SDomiString *id) {
    SDomiDocHolder *h;

    if (isDocID(m->active, id)) {
        return m->active->doc;
    }
    h = FindInTrash(m, id);
    if (h == NULL) {
        return NULL;
    }
    SDomiSLink_Remove(&m->trash, &h->link);
    SDomiDocManager_TrashActiveDocument(m);
    m->active = h;
    return h->doc;
}

void SDomiDocManager_TrashActiveDocument(SDomiDocManager *m) {
    if (m->active != NULL) {
        m->active->doc->i.n.vt->FreeTrash(m->active->doc);
        SDomiSLink_Insert(&m->trash, &m->active->link);
        m->active = NULL;
    }
}

void SDomiDocManager_TrashDocument(SDomiDocManager *m, const SDomiString *id) {
    if (isDocID(m->active, id)) {
        SDomiDocManager_TrashActiveDocument(m);
    }
}

void SDomiDocManager_DiscardDocument(SDomiDocManager *m, const SDomiString *id) {
    SDomiDocHolder *h = FindInTrash(m, id);

    if (h != NULL) {
        SDomiSLink_Remove(&m->trash, &h->link);
        DeleteDocHolder(h);
    }
}

void SDomiDocManager_EmptyTrash(SDomiDocManager *m) {
    SDomiSLink *l;

    for (;;) {
        l = SDomiSLink_RemoveFirst(&m->trash);
        if (l == NULL) {
            break;
        }
        DeleteDocHolder(RecoverPtr(l));
    }
}

void SDomiDocManager_DeleteDocuments(SDomiDocManager *m, SDomiImplementation *impl) {
    SDomiSLink *l, *next;
    SDomiDocHolder *h;

    if (m->active != NULL && m->active->doc->implementation == impl) {
        SDomiDocManager_TrashActiveDocument(m);
    }
    for (l = SDomiSLink_first(&m->trash); l != NULL; l = next) {
        next = SDomiSLink_next(&m->trash, l);
        h = RecoverPtr(l);
        if (h->doc->implementation == impl) {
            SDomiSLink_Remove(&m->trash, l);
            DeleteDocHolder(h);
        }
    }
}
