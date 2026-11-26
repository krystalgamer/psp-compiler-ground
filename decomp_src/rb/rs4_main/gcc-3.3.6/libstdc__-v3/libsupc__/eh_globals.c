/* lang: c++ */
/* the gcc-3.3.6 libstdc++ eh_globals.cc of the 1.9.2 tree, as built for psp-gcc 1.9.2;
   its variables stay in the module's asm .data/.bss (declared extern instead of
   defined static) */
#include <exception>
#include <cstdlib>
#include "../gcc1.9.2_src/libstdc++-v3/libsupc++/unwind-cxx.h"
#include "bits/c++config.h"
#include "bits/gthr.h"

using namespace __cxxabiv1;


// Single-threaded fallback buffer.
extern __cxa_eh_globals globals_static;

#if __GTHREADS
extern __gthread_key_t globals_key;
extern int use_thread_key;

static void
get_globals_dtor (void *ptr)
{
  __gthread_key_dtor (globals_key, ptr);
  if (ptr)
    std::free (ptr);
}

static void
get_globals_init ()
{
  use_thread_key =
    (__gthread_key_create (&globals_key, get_globals_dtor) == 0);
}

static void
get_globals_init_once ()
{
  extern __gthread_once_t once __asm__("_ZZ21get_globals_init_oncevE4once");
  if (__gthread_once (&once, get_globals_init) != 0
      || use_thread_key < 0)
    use_thread_key = 0;
}
#endif

extern "C" __cxa_eh_globals *
__cxa_get_globals_fast ()
{
#if __GTHREADS
  if (use_thread_key)
    return (__cxa_eh_globals *) __gthread_getspecific (globals_key);
  else
    return &globals_static;
#else
  return &globals_static;
#endif
}

extern "C" __cxa_eh_globals *
__cxa_get_globals ()
{
#if __GTHREADS
  __cxa_eh_globals *g;

  if (use_thread_key == 0)
    return &globals_static;

  if (use_thread_key < 0)
    {
      get_globals_init_once ();

      // Make sure use_thread_key got initialized.
      if (use_thread_key == 0)
	return &globals_static;
    }

  g = (__cxa_eh_globals *) __gthread_getspecific (globals_key);
  if (! g)
    {
      if ((g = (__cxa_eh_globals *)
	   std::malloc (sizeof (__cxa_eh_globals))) == 0
	  || __gthread_setspecific (globals_key, (void *) g) != 0)
        std::terminate ();
      g->caughtExceptions = 0;
      g->uncaughtExceptions = 0;
    }

  return g;
#else
  return &globals_static;
#endif
}
/* static in eh_globals.cc; the module's .eh_frame (asm) refers to it */
__asm__(".globl _Z21get_globals_init_oncev");
