/* upstream: newlib-1.12.0/newlib/libc/time/tzset_r.c (unmodified) */
/* cflags: -O2 -fno-builtin */

/* The module's .data/.bss (asm) define the variables: declared first into
   .data.* sections, which the linker script discards, and weak in the
   assembler only.  The static ones are made global so that the module's
   labels are the ones used. */
#define DISCARD(n) __attribute__((section(".data." #n)))
struct __tzrule_struct;
extern char __tzname_std[11] DISCARD(__tzname_std);
extern char __tzname_dst[11] DISCARD(__tzname_dst);
extern char *prev_tzenv DISCARD(prev_tzenv);
extern char *_tzname[2] DISCARD(_tzname);
extern int _daylight DISCARD(_daylight);
extern long _timezone DISCARD(_timezone);
extern int __tzyear DISCARD(__tzyear);
extern int __tznorth DISCARD(__tznorth);
extern struct __tzrule_struct __tzrule[2] DISCARD(__tzrule);
#undef DISCARD
#define static
#include "libc/time/tzset_r.c"
#undef static
__asm__(".weak __tzname_std\n.weak __tzname_dst\n.weak prev_tzenv\n.weak _tzname\n.weak _daylight\n"
        ".weak _timezone\n.weak __tzyear\n.weak __tznorth\n.weak __tzrule");

/* labels the rest of the module's asm uses */
__asm__(".globl D_00178590\nD_00178590 = 0x00178590");
