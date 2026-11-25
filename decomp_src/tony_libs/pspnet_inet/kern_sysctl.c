/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "inetlib.h"
/* --- end declarations --- */

int func_000086F4(void *oldp, size_t *oldlenp, void *newp, size_t newlen, char *str, int maxlen)
{
	int len, error = 0, err2 = 0;

	if (newp && newlen >= maxlen)
		return EINVAL;
	if (oldlenp) {
		len = strlen(str) + 1;
		if (oldp) {
			if (*oldlenp < len) {
				len = *oldlenp;
				err2 = ENOMEM;
			} else
				*oldlenp = len;
			bcopy(str, oldp, len);
			error = err2;
		} else
			*oldlenp = len;
	}
	if (error == 0 && newp) {
		bcopy(newp, str, newlen);
		str[newlen] = 0;
	}
	return error;
}

int func_000087F0(void *oldp, size_t *oldlenp, void *newp, size_t newlen, int *valp)
{
	int error = 0;

	if (newp && newlen != sizeof(int))
		return EINVAL;
	if (oldlenp) {
		if (oldp == NULL)
			*oldlenp = sizeof(int);
		else {
			if (*oldlenp < sizeof(int))
				return ENOMEM;
			*oldlenp = sizeof(int);
			bcopy(valp, oldp, sizeof(int));
		}
	}
	if (error == 0 && newp)
		bcopy(newp, valp, sizeof(int));
	return 0;
}

int func_000088AC(void *oldp, size_t *oldlenp, void *newp, int val)
{
	if (newp)
		return EPERM;
	if (oldlenp) {
		if (oldp == NULL)
			*oldlenp = sizeof(int);
		else {
			if (*oldlenp < sizeof(int))
				return ENOMEM;
			*oldlenp = sizeof(int);
			bcopy(&val, oldp, sizeof(int));
		}
	}
	return 0;
}

int func_0000891C(void *oldp, size_t *oldlenp, void *newp, size_t newlen, quad_t *valp)
{
	int error = 0;

	if (newp && newlen != sizeof(quad_t))
		return EINVAL;
	if (oldlenp) {
		if (oldp == NULL)
			*oldlenp = sizeof(quad_t);
		else {
			if (*oldlenp < sizeof(quad_t))
				return ENOMEM;
			*oldlenp = sizeof(quad_t);
			bcopy(valp, oldp, sizeof(quad_t));
		}
	}
	if (error == 0 && newp)
		bcopy(newp, valp, sizeof(quad_t));
	return 0;
}

int func_000089D8(void *oldp, size_t *oldlenp, void *newp, quad_t val)
{
	if (newp)
		return EPERM;
	if (oldlenp) {
		if (oldp == NULL)
			*oldlenp = sizeof(quad_t);
		else {
			if (*oldlenp < sizeof(quad_t))
				return ENOMEM;
			*oldlenp = sizeof(quad_t);
			bcopy(&val, oldp, sizeof(quad_t));
		}
	}
	return 0;
}

int func_00008A4C(void *oldp, size_t *oldlenp, void *newp, const char *str)
{
	int len, error = 0, err2 = 0;

	if (newp)
		return EPERM;
	if (oldlenp) {
		len = strlen(str) + 1;
		if (oldp) {
			if (*oldlenp < len) {
				len = *oldlenp;
				err2 = ENOMEM;
			} else
				*oldlenp = len;
			bcopy(str, oldp, len);
			error = err2;
		} else
			*oldlenp = len;
	}
	return error;
}

int func_00008AF4(void *oldp, size_t *oldlenp, void *newp, size_t newlen, void *sp, int len)
{
	int error = 0;

	if (newp && newlen != len)
		return EINVAL;
	if (oldlenp) {
		if (oldp == NULL)
			*oldlenp = len;
		else {
			if (*oldlenp < len)
				return ENOMEM;
			*oldlenp = len;
			bcopy(sp, oldp, len);
		}
	}
	if (error == 0 && newp)
		bcopy(newp, sp, len);
	return 0;
}

int func_00008BB4(void *oldp, size_t *oldlenp, void *newp, const void *sp, int len)
{
	if (newp)
		return EPERM;
	if (oldlenp) {
		if (oldp == NULL)
			*oldlenp = len;
		else {
			if (*oldlenp < len)
				return ENOMEM;
			*oldlenp = len;
			bcopy(sp, oldp, len);
		}
	}
	return 0;
}
