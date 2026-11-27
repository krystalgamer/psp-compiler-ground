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

#if defined(M2CTX) || defined(PERMUTER)
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_ASM_LINKONCE(FOLDER, NAME)
#else
#define INCLUDE_ASM(FOLDER, NAME) DEFER_ASM_IN(".text", FOLDER, NAME)
/* A template instance / inline function kept as asm: in its own
   .gnu.linkonce.t section like cc1plus's copies, so the link keeps the
   first copy (the original holder object precedes every other user). */
#define INCLUDE_ASM_LINKONCE(FOLDER, NAME) \
    DEFER_ASM_IN(".section .gnu.linkonce.t." #NAME ",\"ax\",@progbits", FOLDER, NAME)
#define DEFER_ASM_IN(SECTION, FOLDER, NAME) \
    extern "C" void NAME##__asm(void) __attribute__((section(".discard.asm"))); \
    extern "C" void NAME##__asm(void) \
    { \
        __asm__( \
            ".end " #NAME "__asm\n" \
            SECTION "\n" \
            "    .set noat\n" \
            "    .set noreorder\n" \
            "    .include \"" FOLDER "/" #NAME ".s\"\n" \
            "    .set reorder\n" \
            "    .set at\n" \
            ".section .discard.asm\n" \
            ".ent " #NAME "__asm\n"); \
    }
#endif

#endif
