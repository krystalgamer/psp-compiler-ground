/* INCLUDE_ASM for C++ units built with -finline-functions (-O3): cc1plus
   then defers every function to the end of the file, after the top-level
   asm, so the asm functions have to be deferred the same way.  Each one is
   included from a function of its own that is put in a discarded section
   (its label, prologue and epilogue go there); the asm itself goes to
   .text.  (The wrapper's .ent is closed around the included function's
   own .ent/.end and opened again for the .end cc1plus writes.)  Include before
   common.h / any header that includes it. */
#ifndef DEFER_ASM_H
#define DEFER_ASM_H

#define INCLUDE_ASM(FOLDER, NAME) \
    extern "C" void NAME##__asm(void) __attribute__((section(".discard.asm"))); \
    extern "C" void NAME##__asm(void) \
    { \
        __asm__( \
            ".end " #NAME "__asm\n" \
            ".text\n" \
            "    .set noat\n" \
            "    .set noreorder\n" \
            "    .include \"" FOLDER "/" #NAME ".s\"\n" \
            "    .set reorder\n" \
            "    .set at\n" \
            ".section .discard.asm\n" \
            ".ent " #NAME "__asm\n"); \
    }

#endif
