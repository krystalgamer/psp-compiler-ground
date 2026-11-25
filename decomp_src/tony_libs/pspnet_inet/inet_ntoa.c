/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "inetlib.h"
/* --- end declarations --- */

char *func_00008C18(u_int addr)
{
	char *p = D_0002EB69;
	u_int n, q;
	int i;

	*--p = '\0';
	addr = ntohl(addr);
	for (i = 4; i > 0; i--) {
		n = addr & 0xff;
		addr >>= 8;
		*--p = n % 10 + '0';
		n /= 10;
		if (n) {
			*--p = n % 10 + '0';
			n /= 10;
			if (n)
				*--p = n + '0';
		}
		*--p = '.';
	}
	return p + 1;
}
