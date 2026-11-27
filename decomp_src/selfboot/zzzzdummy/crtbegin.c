/* gcc 3.3.3 crtstuff.c with CRT_BEGIN (the psp-gcc 1.5.1.internal toolchain's crtbegin.o, built with
   CRTSTUFFT_O's -finhibit-size-directive -fno-inline-functions -fno-exceptions
   -fno-zero-initialized-in-bss; any cc1 reproduces it).  The module's asm keeps the data:
   __DTOR_LIST__/__EH_FRAME_BEGIN__/__JCR_LIST__ sections, the static p (.data),
   completed and object (.bss), and the .init/.fini calls of frame_dummy and
   __do_global_dtors_aux (named func_00000040 there, hence not static here). */
/* cflags: -O2 -finhibit-size-directive -fno-inline-functions -fno-exceptions -fno-zero-initialized-in-bss */
typedef void (*func_ptr) (void);
struct object;

extern func_ptr __DTOR_LIST__[];
extern const char __EH_FRAME_BEGIN__[];
extern void *__JCR_LIST__[];

extern void __deregister_frame_info (const void *) __attribute__ ((weak));
extern void __register_frame_info (const void *, struct object *) __attribute__ ((weak));
extern void _Jv_RegisterClasses (void *) __attribute__ ((weak));

#define __do_global_dtors_aux func_00000040

void __attribute__((used))
__do_global_dtors_aux (void)
{
  extern func_ptr *p __asm__("D_0000AAD4");	/* static func_ptr *p = __DTOR_LIST__ + 1; */
  extern _Bool completed __asm__("edata");	/* static _Bool completed; */
  func_ptr f;

  if (__builtin_expect (completed, 0))
    return;

  while ((f = *p))
    {
      p++;
      f ();
    }

  if (__deregister_frame_info)
    __deregister_frame_info (__EH_FRAME_BEGIN__);

  completed = 1;
}

void __attribute__((used))
frame_dummy (void)
{
  extern struct object object __asm__("D_0000B294");	/* static struct object object; */

  if (__register_frame_info)
    __register_frame_info (__EH_FRAME_BEGIN__, &object);
  if (__JCR_LIST__[0] && _Jv_RegisterClasses)
    _Jv_RegisterClasses (__JCR_LIST__);
}
