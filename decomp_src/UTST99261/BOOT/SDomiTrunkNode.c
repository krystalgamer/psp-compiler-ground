/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"

void SDomiTrunkNode_Initialize(SDomiTrunkNode *n, const SDomiNodeVt *vt, int flags, int type,
                               SDomiDocument *doc, const SDomiStringH *name) {
    SDomiInternalNode_Initialize(&n->i.n, vt, flags, type, doc, name);
    n->parentNode = NULL;
    n->previousSibling = NULL;
    n->nextSibling = NULL;
}
