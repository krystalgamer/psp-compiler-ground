#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoBaseConstruct);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoBaseDestruct);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoBaseCopy);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoBaseAttachObserver);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoBaseDetachObserver);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoBaseSetParent);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoObserverConstruct);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoObserverDestruct);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoObserverCopy);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoObserverSetSubject);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoSubjectConstruct);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoSubjectDestruct);

void sceGmoSubjectCopy(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoSubjectAttachObserver);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_base", sceGmoSubjectDetachObserver);
