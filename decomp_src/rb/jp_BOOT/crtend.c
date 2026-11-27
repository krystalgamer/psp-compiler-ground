/* gcc 3.3.3 crtstuff.c with CRT_END (the psp-gcc 1.5.1 toolchain's crtend.o); __CTOR_END__ and
   the .init call stay in the module's asm (__do_global_ctors_aux is func_000159A8 there). */
/* cflags: -O2 -finhibit-size-directive -fno-inline-functions -fno-exceptions -fno-zero-initialized-in-bss */
typedef void (*func_ptr) (void);

extern func_ptr __CTOR_END__[];

#define __do_global_ctors_aux func_000159A8

void __attribute__((used))
__do_global_ctors_aux (void)
{
  func_ptr *p;
  for (p = __CTOR_END__ - 1; *p != (func_ptr) -1; p--)
    (*p) ();
}
