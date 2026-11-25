/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

int
__cmsg_alignbytes(void)
{
	return 3;
}
