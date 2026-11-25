/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "inetlib.h"
/* --- end declarations --- */

char *sceNetInet_lib_2595064C(struct in_addr in)
{
	memcpy(D_0002F288, "[inet_ntoa error]", sizeof(D_0002F288));
	sceNetInetInetNtop(AF_INET, &in, D_0002F288, sizeof(D_0002F288));
	return D_0002F288;
}

const char *sceNetInetInetNtop(int af, const void *src, char *dst, socklen_t size)
{
	struct thread_info *ti;
	char tmp[sizeof "255.255.255.255"];
	const u_char *p = src;
	const char *ret;
	int l;

	if ((ti = _sce_pspnet_thread_enter()) == NULL)
		return NULL;
	if (af != AF_INET) {
		_sce_pspnet_thread_leave(ti, EAFNOSUPPORT);
		return NULL;
	}
	l = sprintf(tmp, "%u.%u.%u.%u", p[0], p[1], p[2], p[3]);
	ret = NULL;
	if (l == 0 || l >= size)
		_sce_pspnet_set_thread_errno(ENOSPC);
	else {
		strcpy(dst, tmp);
		ret = dst;
	}
	_sce_pspnet_thread_leave(ti, ti->error);
	return ret;
}
