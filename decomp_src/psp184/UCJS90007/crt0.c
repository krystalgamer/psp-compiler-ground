#include "common.h"

/* declarations recovered from DWARF */


extern const unsigned char __psp_libinfo__[24];
extern const int _sce_module_startthpara[4];
extern const int _sce_module_stopthpara[4];
extern int sce_newlib_stack_kb_size;
extern int sce_newlib_priority;
extern unsigned int sce_newlib_attribute;
extern void (*sce_newlib_stop_func)(void);

int _start(int args, char *argp);
int _main(int args, char *argp);
int _stop(void);


INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/crt0", __psp_libinfo___2D620);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/crt0", _sce_module_startthpara);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/crt0", _sce_module_stopthpara);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/crt0", _start);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/crt0", _main);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/crt0", _stop);
