#include "common.h"
#include "m2c_macros.h"
int Node_getBox(int);                               /* extern */
M2C_UNK resetFormData(int, M2C_UNK);                /* extern */
M2C_UNK clearSaveFormData();                        /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", getRadioListByName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", addSaveFormData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", clearSaveFormData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", getAncestorForm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", getPreviousForm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", getInputType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", addFormList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", addFormElementList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", freeFormList);

#ifndef NULL
#define NULL ((void *)0)
#endif

void clearAllFormData(void *arg0) {
    void *var_s0;

    if (arg0 != NULL) {
        var_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x7C);
        if (var_s0 != NULL) {
            do {
                resetFormData(Node_getBox(M2C_FIELD(var_s0, int *, 0)), 0);
                var_s0 = M2C_FIELD(var_s0, void **, 8);
            } while (var_s0 != NULL);
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", freeCurPageFormList);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *getFormList(void *arg0, int arg1) {
    void *var_a0;
    void *var_a2;
    void *var_v1;

    var_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x7C);
    var_a2 = NULL;
    if (var_a0 != NULL) {
loop_1:
        var_a2 = var_a0;
        if (M2C_FIELD(var_a0, int *, 0) != arg1) {
            var_v1 = M2C_FIELD(var_a0, void **, 4);
            if (var_v1 != NULL) {
loop_3:
                var_a2 = var_a0;
                if (M2C_FIELD(var_v1, int *, 0) != arg1) {
                    var_v1 = M2C_FIELD(var_v1, void **, 4);
                    if (var_v1 == NULL) {
                        goto block_5;
                    }
                    goto loop_3;
                }
            } else {
block_5:
                var_a0 = M2C_FIELD(var_a0, void **, 8);
                if (var_a0 == NULL) {
                    var_a2 = NULL;
                } else {
                    goto loop_1;
                }
            }
        }
    }
    return var_a2;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", confirmFepInfo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", actFormInput);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", actSubmitForm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", actResetForm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", actSaveForm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", actRestoreForm);

#ifndef NULL
#define NULL ((void *)0)
#endif

void actClearForm(void) {
    clearSaveFormData();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", addRadioList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", freeRadioList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_form", layoutWaitMail);
