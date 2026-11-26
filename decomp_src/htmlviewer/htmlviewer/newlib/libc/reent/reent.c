/* upstream: newlib-1.12.0/newlib/libc/reent/reent.c (Sony's 1.8.x psp-newlib: _reclaim_reent also frees the mprec result and p5s list and the stdio buffers) */
/* cflags: -O2 -fno-builtin */
#define __DYNAMIC_REENT__
#include <stdlib.h>
#include <stdio.h>
#include <reent.h>
#include "local.h"

extern void _Bfree (struct _reent *, struct _Bigint *);

/* Interim cleanup code */

void
_DEFUN (cleanup_glue, (ptr, glue),
     struct _reent *ptr _AND
     struct _glue *glue)
{
  /* Have to reclaim these in reverse order: */
  if (glue->_next)
    cleanup_glue (ptr, glue->_next);

  _free_r (ptr, glue);
}

static void
reclaim_smbf (struct _reent *ptr)
{
  FILE *fp;
  int n;
  struct _glue *g;

  for (g = &ptr->__sglue; g != NULL; g = g->_next)
    for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
      if ((fp->_flags & __SMBF) && fp->_bf._base != NULL)
	{
	  _free_r (ptr, fp->_bf._base);
	  fp->_bf._base = NULL;
	}
}

void
_DEFUN (_reclaim_reent, (ptr),
     struct _reent *ptr)
{
  if (ptr != _impure_ptr)
    {
      /* used by mprec routines. */
      if (ptr->_result)
	{
	  ptr->_result->_k = ptr->_result_k;
	  ptr->_result->_maxwds = 1 << ptr->_result_k;
	  _Bfree (ptr, ptr->_result);
	}
      {
	struct _Bigint *p5, *next;
	for (p5 = ptr->_p5s; p5; p5 = next)
	  {
	    next = p5->_next;
	    _Bfree (ptr, p5);
	  }
      }
      if (_REENT_MP_FREELIST(ptr))
	{
	  int i;
	  for (i = 0; i < 15 /* _Kmax */; i++) 
	    {
	      struct _Bigint *thisone, *nextone;
	
	      nextone = _REENT_MP_FREELIST(ptr)[i];
	      while (nextone)
		{
		  thisone = nextone;
		  nextone = nextone->_next;
		  _free_r (ptr, thisone);
		}
	    }    

	  _free_r (ptr, _REENT_MP_FREELIST(ptr));
	}

      /* atexit stuff */
      if ((ptr->_atexit) && (ptr->_atexit != &ptr->_atexit0))
	{
	  struct _atexit *p, *q;
	  for (p = ptr->_atexit; p != &ptr->_atexit0;)
	    {
	      q = p;
	      p = p->_next;
	      _free_r (ptr, q);
	    }
	}

      if (ptr->_cvtbuf)
	_free_r (ptr, ptr->_cvtbuf);

      if (ptr->__sdidinit)
	{
	  /* cleanup won't reclaim memory 'coz usually it's run
	     before the program exits, and who wants to wait for that? */
	  ptr->__cleanup (ptr);

	  reclaim_smbf (ptr);

	  if (ptr->__sglue._next)
	    cleanup_glue (ptr, ptr->__sglue._next);
	}

      /* Malloc memory not reclaimed; no good way to return memory anyway. */

    }
}

/*
 *  Do atexit() processing and cleanup
 *
 *  NOTE:  This is to be executed at task exit.  It does not tear anything
 *         down which is used on a global basis.
 */

void
_DEFUN (_wrapup_reent, (ptr), struct _reent *ptr)
{
  register struct _atexit *p;
  register int n;

  if (ptr == 0)
      ptr = _REENT;

  for (p = ptr->_atexit; p; p = p->_next)
    for (n = p->_ind; --n >= 0;)
      (*p->_fns[n]) ();
  if (ptr->__cleanup)
    (*ptr->__cleanup) (ptr);
}
