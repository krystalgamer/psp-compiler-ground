#include "common.h"

/* declarations recovered from DWARF */


extern int _sce_module_startthpara[4];
extern int _sce_module_stopthpara[4];
extern int sce_newlib_stack_kb_size;
extern int sce_newlib_priority;
extern unsigned int sce_newlib_attribute;
extern void (*sce_newlib_stop_func)(void);

int _start(int args, char *argp);
int _main(int args, char *argp);
int _stop(void);


INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/crt0", _start);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/crt0", _main);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/crt0", _stop);
