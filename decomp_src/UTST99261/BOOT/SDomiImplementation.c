/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern const SDomiImplementationVt gImplementationVt;

void SDomiImplementation_Initialize(SDomiImplementation *impl, const SDomiImplementationVt *vt) {
    if (vt == NULL) {
        vt = &gImplementationVt;
    }
    impl->vt = vt;
    impl->trash.next = &impl->trash;
}

void SDomiImplementation_TrashNode(SDomiImplementation *impl, SDomiNode *n) {
    SDomiSLink_Insert(&impl->trash, &n->trash);
}
