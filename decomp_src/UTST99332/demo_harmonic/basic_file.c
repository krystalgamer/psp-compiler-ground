#include "common.h"

/* declarations recovered from DWARF */
enum _Ios_Openmode {
    _M_ios_openmode_end = 65536,
};



static const char *fopen_mode(enum _Ios_Openmode mode);


INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZN14__gnu_internal10fopen_modeESt13_Ios_Openmode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcEC2EP15__gthread_mutex);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcEC1EP15__gthread_mutex);

void _ZNSt12__basic_fileIcED2Ev(void) {
    _ZNSt12__basic_fileIcE5closeEv();
}

void _ZNSt12__basic_fileIcED1Ev(void) {
    _ZNSt12__basic_fileIcE5closeEv();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcE12_M_open_modeESt13_Ios_OpenmodeRiS2_Pc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcE8sys_openEP7__sFILESt13_Ios_Openmode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcE8sys_openEiSt13_Ios_Openmodeb);

void _ZNSt12__basic_fileIcE8sys_getcEv(int *arg0) {
    getc(*arg0);
}

void _ZNSt12__basic_fileIcE10sys_ungetcEi(int *arg0, int arg1) {
    ungetc(arg1, *arg0);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcE4openEPKcSt13_Ios_Openmodei);

int _ZNKSt12__basic_fileIcE7is_openEv(int *arg0) {
    return *arg0 != 0;
}

void _ZNSt12__basic_fileIcE2fdEv(int *arg0) {
    fileno(*arg0);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcE5closeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcE6xsgetnEPci);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcE6xsputnEPKci);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcE7seekoffElSt12_Ios_SeekdirSt13_Ios_Openmode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/basic_file", _ZNSt12__basic_fileIcE7seekposElSt13_Ios_Openmode);

void _ZNSt12__basic_fileIcE4syncEv(int *arg0) {
    fflush(*arg0);
}

int _ZNSt12__basic_fileIcE16showmanyc_helperEv(void) {
    return 0;
}
