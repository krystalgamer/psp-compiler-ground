/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern const SDomiNodeVt gDomiDocumentFragmentVt;

void SDomiDocumentFragment_Initialize(SDomiNode *n, SDomiDocument *doc) {
    SDomiInternalNode_Initialize(n, &gDomiDocumentFragmentVt, 0, 11, doc, AcsExterngSHnull());
}
