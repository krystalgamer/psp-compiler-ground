#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_strlen(signed char *arg0);

char *rt_string_strncpy(char *d, const char *s, int n)
{
    char *r = d;

    if (n != 0) {
        while (--n != -1 && (*d++ = *s++) != 0)
            ;
        d[-1] = 0;
    }
    return r;
}

int rt_strlen(signed char *arg0) {
    int var_v0;
    signed char *var_v1;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v1 = arg0;
        if (*arg0 != 0) {
            do {
                var_v1 += 1;
            } while (*var_v1 != 0);
        }
        var_v0 = var_v1 - arg0;
    }
    return var_v0;
}

unsigned int rt_strnlen(const char *s, unsigned int n)
{
    const char *e = s + n;
    const char *p;
    if (s == NULL) return 0;
    for (p = s; p < e && *p != 0; p++)
        ;
    return p - s;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_string", rcsid_10EEF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_string", rt_string_header_rcsid);
