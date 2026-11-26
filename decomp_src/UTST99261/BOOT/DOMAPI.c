/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK SDomiDocManager_Initialize(M2C_UNK *);      /* extern */
extern int gDOMAPIUse;
extern unsigned char gDomiDocManager;
extern int gDomiError;
M2C_UNK SDomiDocManager_Finalize(M2C_UNK *);        /* extern */
M2C_UNK SDomiDocManager_EmptyTrash(M2C_UNK *);      /* extern */
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
unsigned char *MEM_malloc(M2C_UNK, int);                       /* extern */
M2C_UNK SDomiStrAcu_Finalize(int);                  /* extern */
M2C_UNK cmDomiNode_Finalize(int);                   /* extern */

M2C_UNK DOMAPI_NewDOMImplementation();              /* extern */
M2C_UNK DOMAPI_DeleteDOMImplementation();           /* extern */
M2C_UNK SDomiCharacterData_set_data();              /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

void DOMAPI_Initialize(void) {
    int temp_v1;

    temp_v1 = gDOMAPIUse + 1;
    gDOMAPIUse = temp_v1;
    if (temp_v1 == 1) {
        SDomiDocManager_Initialize(&gDomiDocManager);
    }
    gDomiError = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void DOMAPI_Finalize(void) {
    int temp_v0;

    if (gDOMAPIUse != 0) {
        temp_v0 = gDOMAPIUse - 1;
        gDOMAPIUse = temp_v0;
        if (temp_v0 == 0) {
            SDomiDocManager_Finalize(&gDomiDocManager);
        }
    }
    gDomiError = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_AddDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_ReuseDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_TrashDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_DiscardDocument);

#ifndef NULL
#define NULL ((void *)0)
#endif

void DOMAPI_EmptyTrash(void) {
    SDomiDocManager_EmptyTrash(&gDomiDocManager);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_NewDOMImplementation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMAPI_DeleteDOMImplementation);

#ifndef NULL
#define NULL ((void *)0)
#endif

int DOMAPI_Error(void) {
    return gDomiError;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void DOMStringfree(void *arg0) {
    int temp_a1;

    temp_a1 = M2C_FIELD(arg0, int *, 8);
    if (temp_a1 != 0) {
        MEM_free(0, temp_a1);
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 0) = 0;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", UTF8toDOMString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", ASCIItoDOMString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoJIS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoSJIS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoEUC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoUTF8);

#ifndef NULL
#define NULL ((void *)0)
#endif

unsigned char *DOMStringtoASCII(void *arg0) {
    unsigned char *temp_v0;
    unsigned char *var_v0;

    temp_v0 = MEM_malloc(0, (M2C_FIELD(arg0, int *, 4) * 2) + 1);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        temp_v0[ucs2ToAscii(temp_v0, M2C_FIELD(arg0, unsigned short **, 8), M2C_FIELD(arg0, int *, 4))] = 0;
        var_v0 = temp_v0;
    }
    return var_v0;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiCharacterData_Finalize(int arg0) {
    SDomiStrAcu_Finalize(arg0 + 0x2C);
    cmDomiNode_Finalize(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int cmDomiCharacterData_get_nodeValue(void *arg0, void *arg1) {
    M2C_FIELD(arg1, int *, 0) = (int) M2C_FIELD(arg0, int *, 0x34);
    M2C_FIELD(arg1, int *, 4) = (int) M2C_FIELD(arg0, int *, 0x38);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cmDomiCharacterData_set_nodeValue(void) {
    SDomiCharacterData_set_data();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", cmDomiCharacterData_cloneNode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", D_00134DB4);
