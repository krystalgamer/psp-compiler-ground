/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern SDomiString gSCore;
extern SDomiString gSv1;
extern SDomiString gSv2;
int UDomiString_CompareNoCase(const DOMChar *a, unsigned int alen, const DOMChar *b, unsigned int blen);
void SDomiDocument_Initialize(SDomiDocument *doc, const SDomiNodeVt *vt, SDomiImplementation *impl, const SDomiStringH *name);

void SDomiExternalNode_Initialize(SDomiNode *n, const SDomiNodeVt *vt, int flags, int type,
                                  SDomiDocument *doc, const SDomiStringH *name) {
    SDomiNode_Initialize(n, vt, flags, type, doc, name);
    ((SDomiExternalNode *)n)->parentNode = NULL;
    ((SDomiExternalNode *)n)->previousSibling = NULL;
    ((SDomiExternalNode *)n)->nextSibling = NULL;
}

SDomiString *AcsExterngSv2(void) {
    return &gSv2;
}

SDomiString *AcsExterngSv1(void) {
    return &gSv1;
}

void cmDomiImplementation_Finalize(SDomiImplementation *impl) {
    SDomiNodeSLink_DeleteAll(&impl->trash);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", cmDomiImplementation_hasFeature);

int cmDomiImplementation_createDocumentType(SDomiImplementation *impl, const SDomiString *name, const SDomiString *publicId,
                                            const SDomiString *systemId, SDomiNode **out) {
    *out = NULL;
    return 9;
}

int cmDomiImplementation_createDocument(SDomiImplementation *impl, const SDomiString *ns, const SDomiString *name,
                                        SDomiNode *doctype, SDomiDocument **out) {
    SDomiDocument *doc = UDomiMemory_Allocate(sizeof(SDomiDocument));

    if (doc != NULL) {
        SDomiDocument_Initialize(doc, NULL, impl, AcsExterngSHnull());
        *out = doc;
        return 0;
    }
    *out = NULL;
    return -1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gCACore);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gCAv1);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gCAv2);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gSCore);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gSv1);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gSv2);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gImplementationVt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gDomiNotationVt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiExternalNode", gDomiProcessingInstructionVt);
