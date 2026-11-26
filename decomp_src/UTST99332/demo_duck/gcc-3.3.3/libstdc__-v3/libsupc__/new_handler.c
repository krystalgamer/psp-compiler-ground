/* lang: c++ */
/* the gcc-3.3.3 libstdc++ new_handler.cc of the 1.6.1 tree, as built for psp-gcc 1.6.1.internal;
   std::nothrow and __new_handler stay in the module's asm data (only their definitions are left out) */
#include "../gcc1.6.1_src/libstdc++-v3/libsupc++/new"

/* const std::nothrow_t std::nothrow = { }; */

using std::new_handler;
extern new_handler __new_handler;

new_handler
std::set_new_handler (new_handler handler) throw()
{
  new_handler prev_handler = __new_handler;
  __new_handler = handler;
  return prev_handler;
}

std::bad_alloc::~bad_alloc() throw() { }
