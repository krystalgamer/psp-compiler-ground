/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern const SDomiNodeVt gDomiProcessingInstructionVt;

void SDomiProcessingInstruction_Initialize(SDomiNode *n, struct SDomiDocument *doc, const SDomiStringH *target) {
    SDomiExternalNode_Initialize(n, &gDomiProcessingInstructionVt, 0, 7, doc, target);
    SDomiStringH_Init(&((SDomiProcessingInstruction *)n)->data);
}
