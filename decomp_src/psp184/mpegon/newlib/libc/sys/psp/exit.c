/* upstream: newlib-1.12.0/newlib/libc/sys/psp/exit.c (Sony's psp-newlib; not in newlib 1.12.0: exit() without __cleanup, _atexit of _getmodreent()) */
/* cflags: -O2 -fno-builtin -falign-loops=64 */
#define __DYNAMIC_REENT__
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <reent.h>

void
exit(int code)
{
  struct _reent *ptr;
  register struct _atexit *p;
  register struct _on_exit_args * args;
  register int n;
  int i;

  ptr = (struct _reent *)_getmodreent();
  p = ptr->_atexit;
  while (p)
    {
      args = & p->_on_exit_args;

      for (n = p->_ind - 1, i = (n >= 0) ? (1 << n) : 0; n >= 0; --n, i >>= 1)
        if (args->_fntypes & i)
          (*((void (*)(int, void *)) p->_fns[n]))(code, args->_fnargs[n]);
        else
          p->_fns[n] ();

      p = p->_next;
    }
  _exit (code);
}
