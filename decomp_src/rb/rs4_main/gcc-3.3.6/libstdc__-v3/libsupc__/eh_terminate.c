/* lang: c++ */
/* the gcc-3.3.6 libstdc++ eh_terminate.cc of the 1.9.2 tree, as built for psp-gcc 1.9.2;
   the handler variables stay in the module's asm .data (only their definitions are left out) */
#include "../gcc1.9.2_src/libstdc++-v3/libsupc++/typeinfo"
#include "../gcc1.9.2_src/libstdc++-v3/libsupc++/exception"
#include <cstdlib>
#include "../gcc1.9.2_src/libstdc++-v3/libsupc++/unwind-cxx.h"
#include "../gcc1.9.2_src/libstdc++-v3/libsupc++/exception_defines.h"

using namespace __cxxabiv1;

/* The current installed user handlers.  */
/* std::terminate_handler __cxxabiv1::__terminate_handler = std::abort; */
/* std::unexpected_handler __cxxabiv1::__unexpected_handler = std::terminate; */

void
__cxxabiv1::__terminate (std::terminate_handler handler)
{
  try {
    handler ();
    std::abort ();
  } catch (...) {
    std::abort ();
  }
}

void
std::terminate ()
{
  __terminate (__terminate_handler);
}

void
__cxxabiv1::__unexpected (std::unexpected_handler handler)
{
  handler();
  std::terminate ();
}

void
std::unexpected ()
{
  __unexpected (__unexpected_handler);
}

std::terminate_handler
std::set_terminate (std::terminate_handler func) throw()
{
  std::terminate_handler old = __terminate_handler;
  __terminate_handler = func;
  return old;
}

std::unexpected_handler
std::set_unexpected (std::unexpected_handler func) throw()
{
  std::unexpected_handler old = __unexpected_handler;
  __unexpected_handler = func;
  return old;
}
