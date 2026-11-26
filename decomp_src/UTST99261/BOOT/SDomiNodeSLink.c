/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"

SDomiNode *RecoverNodePtr(SDomiSLink *l) {
    return l != NULL ? (SDomiNode *)((char *)l - 8) : NULL;
}

SDomiNode *SDomiNodeSLink_RemoveFirst(SDomiSLink *head) {
    return RecoverNodePtr(SDomiSLink_RemoveFirst(head));
}

void SDomiNodeSLink_DeleteAll(SDomiSLink *head) {
    SDomiNode *n;

    while ((n = SDomiNodeSLink_RemoveFirst(head)) != NULL) {
        n->vt->Finalize(n);
        UDomiMemory_Free(n);
    }
}

void cmDomiNotation_Finalize(SDomiNode *n) {
    SDomiNotation *no = (SDomiNotation *)n;

    SDomiStringH_Finalize(&no->systemId);
    SDomiStringH_Finalize(&no->publicId);
    cmDomiNode_Finalize(n);
}
