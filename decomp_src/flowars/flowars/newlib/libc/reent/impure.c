/* newlib-1.12.0/newlib/libc/reent/impure.c: only its .rodata ("C", the
   initial _current_locale of impure_data) is here; impure_data itself is in
   the module's .data blob.  splat emits no rodata file for a unit without
   .text, so the string is written out directly. */
__asm__(".section .rodata\n"
	"\t.align 2\n"
	".globl D_0003194C\n"
	"D_0003194C:\n"
	"\t.asciz \"C\"\n"
	"\t.align 2\n"
	"\t.previous");
