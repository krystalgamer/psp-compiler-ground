/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK DOMAPI_NewDOMImplementation();              /* extern */
M2C_UNK DOMAPI_DeleteDOMImplementation();           /* extern */
M2C_UNK SDomiCharacterData_set_data();              /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_Initialize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_Finalize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_AddDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_ReuseDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_TrashDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_DiscardDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_EmptyTrash);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_NewDOMImplementation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_DeleteDOMImplementation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_Error);

#ifndef NULL
#define NULL ((void *)0)
#endif

void Util_DOMAPI_NewHTMLDOMImplementation(void) {
    DOMAPI_NewDOMImplementation();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void Util_DOMAPI_DeleteHTMLDOMImplementation(void) {
    DOMAPI_DeleteDOMImplementation();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLDOMImplementation_createHTMLDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_Elament_getCharactorData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLDocument_getBody);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLFormElement_getLength);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLSelectElement_getLength);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLSelectElement_getType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLOptionElement_getIndex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_Node_TraceNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_getNodeByTagName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringfree);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", UTF8toDOMString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", ASCIItoDOMString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoJIS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoSJIS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoEUC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoUTF8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoASCII);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringEncode);

#ifndef NULL
#define NULL ((void *)0)
#endif
int DOMStringlen(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringcat);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringcasecmp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringcasecmpFast);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringcasecmpChar);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringcasecmpCharFast);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", cmDomiCharacterData_Finalize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", cmDomiCharacterData_get_nodeValue);

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiCharacterData_set_nodeValue(void) {
    SDomiCharacterData_set_data();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", cmDomiCharacterData_cloneNode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", D_00134DB4);
