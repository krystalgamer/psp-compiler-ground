#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_constraint_check_RT_1BYTE(signed char *arg0, void *arg1);
int rt_constraint_check_RT_2BYTE(short *arg0, void *arg1);
int rt_constraint_check_RT_4BYTE(int *arg0, void *arg1);
int rt_constraint_check_RT_4BYTE_FP(float *arg0, void *arg1);
int rt_constraint_check_RT_U1BYTE(unsigned char *arg0, void *arg1);
int rt_constraint_check_RT_U2BYTE(unsigned short *arg0, void *arg1);
int rt_constraint_check_RT_U4BYTE(unsigned int *arg0, void *arg1);

int rt_constraint_check_RT_1BYTE(signed char *arg0, void *arg1) {
    int var_a0;
    signed char temp_a1;

    temp_a1 = *arg0;
    var_a0 = 0;
    if (temp_a1 >= M2C_FIELD(arg1, signed char *, 0)) {
        var_a0 = 1;
        if (M2C_FIELD(arg1, signed char *, 1) < temp_a1) {
            var_a0 = 0;
        }
    }
    return var_a0;
}

int rt_constraint_check_RT_U1BYTE(unsigned char *arg0, void *arg1) {
    int var_a0;
    unsigned char temp_a1;

    temp_a1 = *arg0;
    var_a0 = 0;
    if (temp_a1 >= (unsigned char) M2C_FIELD(arg1, unsigned char *, 0)) {
        var_a0 = 1;
        if ((unsigned char) M2C_FIELD(arg1, unsigned char *, 1) < temp_a1) {
            var_a0 = 0;
        }
    }
    return var_a0;
}

int rt_constraint_check_RT_2BYTE(short *arg0, void *arg1) {
    short temp_a1;
    int var_a0;

    temp_a1 = *arg0;
    var_a0 = 0;
    if (temp_a1 >= M2C_FIELD(arg1, short *, 0)) {
        var_a0 = 1;
        if (M2C_FIELD(arg1, short *, 2) < temp_a1) {
            var_a0 = 0;
        }
    }
    return var_a0;
}

int rt_constraint_check_RT_U2BYTE(unsigned short *arg0, void *arg1) {
    int var_a0;
    unsigned short temp_a1;

    temp_a1 = *arg0;
    var_a0 = 0;
    if (temp_a1 >= (unsigned short) M2C_FIELD(arg1, unsigned short *, 0)) {
        var_a0 = 1;
        if ((unsigned short) M2C_FIELD(arg1, unsigned short *, 2) < temp_a1) {
            var_a0 = 0;
        }
    }
    return var_a0;
}

int rt_constraint_check_RT_4BYTE(int *arg0, void *arg1) {
    int temp_a0;
    int var_v1;

    temp_a0 = *arg0;
    var_v1 = 0;
    if (temp_a0 >= M2C_FIELD(arg1, int *, 0)) {
        var_v1 = 1;
        if (M2C_FIELD(arg1, int *, 4) < temp_a0) {
            var_v1 = 0;
        }
    }
    return var_v1;
}

int rt_constraint_check_RT_U4BYTE(unsigned int *arg0, void *arg1) {
    int var_v1;
    unsigned int temp_a0;

    temp_a0 = *arg0;
    var_v1 = 0;
    if (temp_a0 >= (unsigned int) M2C_FIELD(arg1, unsigned int *, 0)) {
        var_v1 = 1;
        if ((unsigned int) M2C_FIELD(arg1, unsigned int *, 4) < temp_a0) {
            var_v1 = 0;
        }
    }
    return var_v1;
}

int rt_constraint_check_RT_8BYTE(long long *v, long long *r)
{
    return *v >= r[0] && *v <= r[1];
}

int rt_constraint_check_RT_U8BYTE(unsigned long long *v, unsigned long long *r)
{
    return *v >= r[0] && *v <= r[1];
}

int rt_constraint_check_RT_4BYTE_FP(float *arg0, void *arg1) {
    float temp_f1;
    int var_v0;

    temp_f1 = *arg0;
    var_v0 = 0;
    if (!(temp_f1 < M2C_FIELD(arg1, float *, 0)) && !(M2C_FIELD(arg1, float *, 4) < temp_f1)) {
        var_v0 = 1;
    }
    return var_v0;
}

int rt_constraint_check_RT_8BYTE_FP(double *v, double *r)
{
    double t = *v;
    int ret = 0;

    if (!(t < r[0]) && !(t > r[1])) ret = 1;
    return ret;
}

unsigned int rt_strnlen();
int rt_constraint_check_RT_CSTRING(const char *s, unsigned int *c)
{
    unsigned int n = rt_strnlen(s, c[1]);
    if (n < c[0]) return 0;
    return n < c[1];
}
