/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "inetlib.h"
/* --- end declarations --- */

int sceNetInetInetPton(int af, const char *src, void *dst)
{
	struct thread_info *ti;
	int ret;

	if ((ti = _sce_pspnet_thread_enter()) == NULL)
		return -1;
	if (af != AF_INET) {
		_sce_pspnet_thread_leave(ti, EAFNOSUPPORT);
		return -1;
	}
	ret = func_0002C4CC(src, dst, 1);
	_sce_pspnet_thread_leave(ti, ti->error);
	return ret;
}

u_int sceNetInetInetAddr(const char *cp)
{
	struct in_addr val;

	if (func_0002C4CC(cp, &val, 0))
		return val.s_addr;
	return 0xffffffff;
}

int sceNetInetInetAton(const char *cp, struct in_addr *addr)
{
	return func_0002C4CC(cp, addr, 0);
}

int func_0002C4CC(const char *cp, void *addr, int strict)
{
	u_long val;
	int base, n;
	u_char c;
	u_int parts[4];
	u_int *pp = parts;
	u_int digit;

	c = *cp;
	for (;;) {
		if (!isdigit(c))
			return 0;
		val = 0;
		base = 10;
		if (c == '0') {
			c = *++cp;
			if (c == 'x' || c == 'X') {
				base = 16;
				c = *++cp;
			} else if (isdigit(c) && c != '9')
				base = 8;
		}
		if (strict && base != 10)
			return 0;
	again:
		if (isdigit(c)) {
			digit = c - '0';
			if (digit < base) {
				val = val * base + digit;
				c = *++cp;
				goto again;
			}
		} else if (base == 16 && isxdigit(c)) {
			digit = c - (islower(c) ? 'a' - 10 : 'A' - 10);
			if (digit < 16) {
				val = (val << 4) | digit;
				c = *++cp;
				goto again;
			}
		}
		if (c == '.') {
			if (pp >= parts + 3)
				return 0;
			*pp++ = val;
			c = *++cp;
		} else
			break;
	}
	if (c != '\0' && !isspace(c))
		return 0;
	n = pp - parts + 1;
	if (strict && n != 4)
		return 0;
	switch (n) {
	case 0:
		return 0;
	case 1:
		break;
	case 2:
		if (parts[0] > 0xff || val > 0xffffff)
			return 0;
		val |= parts[0] << 24;
		break;
	case 3:
		if ((parts[0] | parts[1]) > 0xff || val > 0xffff)
			return 0;
		val |= (parts[0] << 24) | (parts[1] << 16);
		break;
	case 4:
		if ((parts[0] | parts[1] | parts[2] | val) > 0xff)
			return 0;
		val |= (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8);
		break;
	}
	if (addr) {
		val = htonl(val);
		memcpy(addr, &val, sizeof(val));
	}
	return 1;
}
