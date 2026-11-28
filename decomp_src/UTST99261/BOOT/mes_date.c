/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
extern MesObject *mes_classes[];
extern const double D_0013BD88;       /* 86400000.0 */
extern const double D_0013BD90;       /* 86400000.0 */
int mes_date_month_days(int year, int month);
extern const double D_0013BDA8;       /* 1000.0 */
double mes_num(MesValue v);
typedef struct MesDNum {
    int f0;
    int f4;
    double d;                         /* 0x8 */
} MesDNum;
extern const double D_0013BD98;       /* 86400000.0 */
extern const double D_0013BDA0;       /* 1000.0 */
double mes_number_fdiv(double a, double b);
double mes_number_floor(double d);
MesValue mes_eval_to_integer(MesContext *ctx, MesValue v);
typedef struct MesTimeval {
    int sec;
    int usec;
} MesTimeval;
int CLIB_gettimeofday(MesTimeval *tv, void *tz);
int mes_eval_to_int32(MesContext *ctx, MesValue v);
extern unsigned int mes_ids[];
extern void *mes_date_table;
extern void *mes_date_table1;
MesValue mes_date_constructor(MesContext *ctx, MesValue y, MesValue mo, MesValue da, MesValue h, MesValue mi, MesValue s, MesValue ms);
void *mes_native_new(MesContext *ctx, int a, void *fn, int nargs, int flags);
void mes_native_setup(MesContext *ctx, MesObject *o, void *table, int n);
typedef struct MesDate {
    struct MesObject obj;
    unsigned char valid;              /* 0x14 */
    int year;                         /* 0x18 */
    int month;                        /* 0x1C: 1..12 */
    int mday;                         /* 0x20 */
    int hours;                        /* 0x24 */
    int minutes;                      /* 0x28 */
    int seconds;                      /* 0x2C */
    int ms;                           /* 0x30 */
    int gmtoff;                       /* 0x34 */
    int zone;                         /* 0x38 */
} MesDate;
#define MES_DATE_BAD(d) (((int)(d) & 3) != 0 || (unsigned int)(d) <= 0x20 || (d)->obj.gc->kind != 7)
extern int mes_date_local_gmtoff;
extern int mes_date_local_zone;
MesValue mes_eval_type_error(MesContext *ctx, void *v);
void mes_date_set_gmtoff(MesDate *d, int gmtoff);
int mes_date_week(int year, int month, int mday);
MesValue mes_number_alloc_int32(MesContext *ctx, int n);
MesValue mes_date_string(MesContext *ctx, MesDate *d, int date, int time, int utc);
MesValue mes_date_to_value(MesContext *ctx, MesDate *d);
int mes_date_is_leap_year(int year);
MesValue mes_date_set_full_year(MesContext *ctx, int y, int m, int d);
MesValue mes_date_set_utc_full_year(MesContext *ctx, int y, int m, int d);
MesValue mes_date_set_hours(MesContext *ctx, int h, int mi, int s, int ms);
MesValue mes_date_set_utc_hours(MesContext *ctx, int h, int mi, int s, int ms);
void mes_date_normalize(MesDate *d);
void *mes_gc_alloc(MesContext *ctx, int kind);
void mes_object_init(MesObject *obj, int cls, MesObject *proto);
void mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_date_method;


MesDate *mes_date_from_string(MesContext *ctx, MesValue s);
MesValue mes_number_alloc(MesContext *ctx, double d);
int mes_eval_to_primitive(void *, int v, int hint);
int mes_eval_to_number(void *, int v);
void mes_object_set(MesObject *obj, unsigned int id, int value, int flags);
MesDate *mes_date_new(MesContext *ctx)
{
    MesDate *d = mes_gc_alloc(ctx, 7);

    if (d != NULL) {
        mes_object_init(&d->obj, 2, (*(MesObject * *)((char *)mes_classes + 0x8)));
        d->valid = 0;
        d->year = -1;
        d->month = -1;
        d->mday = -1;
        d->hours = -1;
        d->minutes = -1;
        d->seconds = -1;
        d->ms = 0;
        d->gmtoff = 0;
        d->zone = 0;
    }
    return d;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_date_initialize(void) {
    mes_gc_register(&mes_date_method, 0x3C, 0x10, 0x10);
}

int mes_date_is_leap_year(int y)
{
    int r = 0;
    int m;

    if (!(y & 3)) {
        if (y % 100 == 0) {
            m = y - y / 400 * 400;
            r = m == 0;
        } else
            r = 1;
    }
    return r;
}

int mes_date_year_days(int year)
{
    return mes_date_is_leap_year(year) ? 366 : 365;
}

int mes_date_month_days(int year, int month)
{
    int ret;

    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        ret = 31;
        break;
    case 2:
        ret = mes_date_is_leap_year(year) ? 29 : 28;
        break;
    default:
        ret = 30;
        break;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_normalize);

MesDate *mes_date_now(MesContext *ctx)
{
    MesDate *d = mes_date_new(ctx);
    MesTimeval tv;

    if (d != NULL) {
        CLIB_gettimeofday(&tv, NULL);
        d->valid = 1;
        d->year = 1970;
        d->month = 1;
        d->mday = tv.sec / 86400 + 1;
        d->hours = 0;
        d->minutes = 0;
        d->seconds = tv.sec % 86400;
        d->ms = tv.usec / 1000;
        d->gmtoff = 0;
        d->zone = 0;
        mes_date_normalize(d);
    }
    return d;
}

void mes_date_set_gmtoff(MesDate *d, int gmtoff)
{
    if (d != NULL) {
        d->seconds += gmtoff - d->gmtoff;
        d->gmtoff = gmtoff;
        if (gmtoff == mes_date_local_gmtoff)
            d->zone = mes_date_local_zone;
        else
            d->zone = 0;
        mes_date_normalize(d);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_date_week(int arg0, int arg1, int arg2) {
    int var_a1;
    int var_a3;
    int var_a4;

    var_a1 = arg1;
    var_a4 = arg0;
    if (var_a1 < 3) {
        var_a4 = -2;
        if (arg0 != 0) {
            var_a4 = arg0 - 1;
        }
        var_a1 += 0xC;
    }
    var_a3 = (((var_a4 + ((int) (var_a4 + ((unsigned int) (var_a4 >> 0x1F) >> 0x1E)) >> 2)) - (var_a4 / 100)) + (var_a4 / 400) + (((var_a1 * 0xD) + 8) / 5) + arg2) % 7;
    if (var_a3 < 0) {
        var_a3 += 7;
    }
    return var_a3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_from_string);

MesDate *mes_date_from_value(MesContext *ctx, MesValue v)
{
    MesDate *d = mes_date_new(ctx);
    double x;
    double c;
    int n;

    if (d != NULL && v != 0x1C && v != 0x14 && v != 0x18) {
        x = mes_number_floor(mes_num(v));
        c = D_0013BD88;
        n = mes_number_fdiv(x, c);
        d->valid = 1;
        d->year = 1970;
        d->month = 1;
        d->mday = n + 1;
        d->hours = 0;
        d->minutes = 0;
        d->seconds = 0;
        d->ms = x - n * c;
        mes_date_normalize(d);
    }
    return d;
}

MesValue mes_date_to_value(MesContext *ctx, MesDate *d)
{
    int y;
    int days;
    int ms;

    if (!d->valid)
        return 0x1C;
    y = d->year - 1;
    days = y * 365 + y / 4 - y / 100 + y / 400 - 719162;
    if (y < 0)
        days--;
    for (y = 1; y < d->month; y++)
        days += mes_date_month_days(d->year, y);
    days += d->mday - 1;
    ms = ((d->hours * 60 + d->minutes) * 60 + d->seconds - d->gmtoff) * 1000 + d->ms;
    return mes_number_alloc(ctx, days * D_0013BD90 + ms);
}

MesValue mes_date_constructor(MesContext *ctx, MesValue y, MesValue mo, MesValue da, MesValue h, MesValue mi, MesValue s, MesValue ms)
{
    MesDate *d;
    MesValue n;
    int argc;

    if (ctx->frame->construct) {
        switch (ctx->frame->args != NULL ? ctx->frame->args->argc : 0) {
        case 0:
            return (MesValue)mes_date_now(ctx);
        case 1:
            y = mes_eval_to_primitive(ctx, y, 0);
            *--ctx->sp = y;
            if ((y & 3) == 3) {
                d = mes_date_from_string(ctx, y);
            } else {
                y = mes_eval_to_number(ctx, y);
                *ctx->sp = y;
                d = mes_date_from_value(ctx, y);
            }
            ctx->sp++;
            break;
        default:
            d = mes_date_new(ctx);
            *--ctx->sp = (MesValue)d;
            d->valid = 1;
            n = mes_eval_to_number(ctx, y);
            if ((n & 3) == 1)
                d->year = n >> 2;
            else
                d->valid = 0;
            n = mes_eval_to_number(ctx, mo);
            if ((n & 3) == 1)
                d->month = (n >> 2) + 1;
            else
                d->valid = 0;
            if (da == 0) {
                d->mday = 1;
            } else {
                n = mes_eval_to_number(ctx, da);
                if ((n & 3) == 1)
                    d->mday = n >> 2;
                else
                    d->valid = 0;
            }
            if (h != 0) {
                n = mes_eval_to_number(ctx, h);
                if ((n & 3) == 1)
                    d->hours = n >> 2;
                else
                    d->valid = 0;
            } else {
                d->hours = 0;
            }
            if (mi != 0) {
                n = mes_eval_to_number(ctx, mi);
                if ((n & 3) == 1)
                    d->minutes = n >> 2;
                else
                    d->valid = 0;
            } else {
                d->minutes = 0;
            }
            if (s != 0) {
                n = mes_eval_to_number(ctx, s);
                if ((n & 3) == 1)
                    d->seconds = n >> 2;
                else
                    d->valid = 0;
            } else {
                d->seconds = 0;
            }
            if (ms != 0) {
                n = mes_eval_to_number(ctx, ms);
                if ((n & 3) == 1)
                    d->ms = n >> 2;
                else
                    d->valid = 0;
            } else {
                d->ms = 0;
            }
            d->gmtoff = mes_date_local_gmtoff;
            d->zone = mes_date_local_zone;
            ctx->sp++;
            if (d->valid)
                mes_date_normalize(d);
            break;
        }
        return (MesValue)d;
    }
    d = mes_date_now(ctx);
    *--ctx->sp = (MesValue)d;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    n = mes_date_string(ctx, d, 1, 1, 0);
    ctx->sp++;
    return n;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

MesValue mes_date_parse(MesContext *ctx, MesValue v)
{
    MesValue s = mes_eval_to_string(ctx, v);
    MesDate *d;

    *--ctx->sp = s;
    d = mes_date_from_string(ctx, s);
    ctx->sp++;
    return mes_date_to_value(ctx, d);
}

MesValue mes_date_utc(MesContext *ctx, MesValue y, MesValue mo, MesValue da, MesValue h, MesValue mi, MesValue s, MesValue ms)
{
    MesDate *d = mes_date_new(ctx);
    MesValue r;
    MesValue n;

    *--ctx->sp = (MesValue)d;
    d->valid = 1;
    if (y == 0) {
        d->year = 1970;
    } else {
        n = mes_eval_to_number(ctx, y);
        if ((n & 3) == 1)
            d->year = n >> 2;
        else
            d->valid = 0;
    }
    if (mo == 0) {
        d->month = 1;
    } else {
        n = mes_eval_to_number(ctx, mo);
        if ((n & 3) == 1)
            d->month = (n >> 2) + 1;
        else
            d->valid = 0;
    }
    if (da == 0) {
        d->mday = 1;
    } else {
        n = mes_eval_to_number(ctx, da);
        if ((n & 3) == 1)
            d->mday = n >> 2;
        else
            d->valid = 0;
    }
    if (h != 0) {
        n = mes_eval_to_number(ctx, h);
        if ((n & 3) == 1)
            d->hours = n >> 2;
        else
            d->valid = 0;
    } else {
        d->hours = 0;
    }
    if (mi != 0) {
        n = mes_eval_to_number(ctx, mi);
        if ((n & 3) == 1)
            d->minutes = n >> 2;
        else
            d->valid = 0;
    } else {
        d->minutes = 0;
    }
    if (s != 0) {
        n = mes_eval_to_number(ctx, s);
        if ((n & 3) == 1)
            d->seconds = n >> 2;
        else
            d->valid = 0;
    } else {
        d->seconds = 0;
    }
    if (ms != 0) {
        n = mes_eval_to_number(ctx, ms);
        if ((n & 3) == 1)
            d->ms = n >> 2;
        else
            d->valid = 0;
    } else {
        d->ms = 0;
    }
    if (d->valid)
        mes_date_normalize(d);
    r = mes_date_to_value(ctx, d);
    ctx->sp++;
    return r;
}

MesValue mes_date_to_string(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return mes_date_string(ctx, d, 1, 1, 0);
}

MesValue mes_date_to_date_string(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return mes_date_string(ctx, d, 1, 0, 0);
}

MesValue mes_date_to_time_string(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return mes_date_string(ctx, d, 0, 1, 0);
}

MesValue mes_date_to_locale_string(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return mes_date_string(ctx, d, 1, 1, 1);
}

MesValue mes_date_to_locale_date_string(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return mes_date_string(ctx, d, 1, 0, 1);
}

MesValue mes_date_to_locale_time_string(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return mes_date_string(ctx, d, 0, 1, 1);
}

MesValue mes_date_value_of(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    return mes_date_to_value(ctx, d);
}

MesValue mes_date_get_full_year(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return mes_number_alloc_int32(ctx, d->year);
}

MesValue mes_date_get_year(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return mes_number_alloc_int32(ctx, d->year - 1900);
}

MesValue mes_date_get_utc_full_year(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, 0);
    return mes_number_alloc_int32(ctx, d->year);
}

MesValue mes_date_get_month(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return MES_INT(d->month - 1);
}

MesValue mes_date_get_utc_month(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, 0);
    return MES_INT(d->month - 1);
}

MesValue mes_date_get_date(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return MES_INT(d->mday);
}

MesValue mes_date_get_utc_date(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, 0);
    return MES_INT(d->mday);
}

MesValue mes_date_get_day(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return MES_INT(mes_date_week(d->year, d->month, d->mday));
}

MesValue mes_date_get_utc_day(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, 0);
    return MES_INT(mes_date_week(d->year, d->month, d->mday));
}

MesValue mes_date_get_hours(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return MES_INT(d->hours);
}

MesValue mes_date_get_utc_hours(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, 0);
    return MES_INT(d->hours);
}

MesValue mes_date_get_minutes(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return MES_INT(d->minutes);
}

MesValue mes_date_get_utc_minutes(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, 0);
    return MES_INT(d->minutes);
}

MesValue mes_date_get_seconds(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return MES_INT(d->seconds);
}

MesValue mes_date_get_utc_seconds(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, 0);
    return MES_INT(d->seconds);
}

MesValue mes_date_get_ms(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    return MES_INT(d->ms);
}

MesValue mes_date_get_utc_ms(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    mes_date_set_gmtoff(d, 0);
    return MES_INT(d->ms);
}

MesValue mes_date_get_timezone_offset(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (!d->valid)
        return 0x1C;
    return MES_INT(-mes_date_local_gmtoff / 60);
}

MesValue mes_date_set_time(MesContext *ctx, MesValue t)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;
    double x;
    double c;
    int n;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    if (t != 0) {
        t = mes_eval_to_integer(ctx, t);
        if (t != 0x14 && t != 0x18) {
            x = mes_num(t);
            c = D_0013BD98;
            n = mes_number_fdiv(x, c);
            d->year = 1970;
            d->month = 1;
            d->mday = n + 1;
            d->hours = 0;
            d->minutes = 0;
            d->seconds = 0;
            d->ms = x - n * c;
            mes_date_normalize(d);
            return t;
        }
        d->valid = 0;
        return t;
    }
    if (!d->valid)
        return 0x1C;
    return mes_date_to_value(ctx, d);
}

MesValue mes_date_set_hours(MesContext *ctx, MesValue h, MesValue m, MesValue s, MesValue ms)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;
    double f;
    double c;
    int n;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    if (h != 0)
        d->hours = mes_eval_to_int32(ctx, h);
    if (m != 0)
        d->minutes = mes_eval_to_int32(ctx, m);
    if (s != 0)
        d->seconds = mes_eval_to_int32(ctx, s);
    if (ms != 0) {
        ms = mes_eval_to_number(ctx, ms);
        if (ms == 0x10)
            d->ms = 1;
        else if ((ms & 3) == 1)
            d->ms = ms >> 2;
        else if ((ms & 3) == 2) {
            f = mes_number_floor(((MesDNum *)(ms & ~3))->d);
            c = D_0013BDA0;
            n = mes_number_fdiv(f, c);
            d->mday += n;
            d->ms = f - n * c;
        } else
            d->valid = 0;
    }
    mes_date_normalize(d);
    return mes_date_to_value(ctx, d);
}

MesValue mes_date_set_minutes(MesContext *ctx, int mi, int s, int ms)
{
    return mes_date_set_hours(ctx, 0, mi, s, ms);
}

MesValue mes_date_set_seconds(MesContext *ctx, int s, int ms)
{
    return mes_date_set_hours(ctx, 0, 0, s, ms);
}

MesValue mes_date_set_ms(MesContext *ctx, int ms)
{
    return mes_date_set_hours(ctx, 0, 0, 0, ms);
}

MesValue mes_date_set_utc_hours(MesContext *ctx, MesValue h, MesValue m, MesValue s, MesValue ms)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;
    double f;
    double c;
    int n;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, 0);
    if (h != 0)
        d->hours = mes_eval_to_int32(ctx, h);
    if (m != 0)
        d->minutes = mes_eval_to_int32(ctx, m);
    if (s != 0)
        d->seconds = mes_eval_to_int32(ctx, s);
    if (ms != 0) {
        ms = mes_eval_to_number(ctx, ms);
        if (ms == 0x10)
            d->ms = 1;
        else if ((ms & 3) == 1)
            d->ms = ms >> 2;
        else if ((ms & 3) == 2) {
            f = mes_number_floor(((MesDNum *)(ms & ~3))->d);
            c = D_0013BDA8;
            n = mes_number_fdiv(f, c);
            d->mday += n;
            d->ms = f - n * c;
        } else
            d->valid = 0;
    }
    mes_date_normalize(d);
    return mes_date_to_value(ctx, d);
}

MesValue mes_date_set_utc_minutes(MesContext *ctx, int mi, int s, int ms)
{
    return mes_date_set_utc_hours(ctx, 0, mi, s, ms);
}

MesValue mes_date_set_utc_seconds(MesContext *ctx, int s, int ms)
{
    return mes_date_set_utc_hours(ctx, 0, 0, s, ms);
}

MesValue mes_date_set_utc_ms(MesContext *ctx, int ms)
{
    return mes_date_set_utc_hours(ctx, 0, 0, 0, ms);
}

MesValue mes_date_set_full_year(MesContext *ctx, MesValue y, MesValue m, MesValue v)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    if (y != 0)
        d->year = mes_eval_to_int32(ctx, y);
    if (m != 0)
        d->month = mes_eval_to_int32(ctx, m) + 1;
    if (v != 0)
        d->mday = mes_eval_to_int32(ctx, v);
    return mes_date_to_value(ctx, d);
}

MesValue mes_date_set_year(MesContext *ctx, MesValue v)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;
    int y;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, mes_date_local_gmtoff);
    if (v != 0) {
        y = mes_eval_to_int32(ctx, v);
        if ((unsigned int)y < 100)
            d->year = y + 1900;
        else
            d->year = y;
    }
    return mes_date_to_value(ctx, d);
}

MesValue mes_date_set_month(MesContext *ctx, int m, int v)
{
    return mes_date_set_full_year(ctx, 0, m, v);
}

MesValue mes_date_set_date(MesContext *ctx, int v)
{
    return mes_date_set_full_year(ctx, 0, 0, v);
}

MesValue mes_date_set_utc_full_year(MesContext *ctx, MesValue y, MesValue m, MesValue v)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, 0);
    if (y != 0)
        d->year = mes_eval_to_int32(ctx, y);
    if (m != 0)
        d->month = mes_eval_to_int32(ctx, m) + 1;
    if (v != 0)
        d->mday = mes_eval_to_int32(ctx, v);
    return mes_date_to_value(ctx, d);
}

MesValue mes_date_set_utc_month(MesContext *ctx, int m, int v)
{
    return mes_date_set_utc_full_year(ctx, 0, m, v);
}

MesValue mes_date_set_utc_date(MesContext *ctx, int v)
{
    return mes_date_set_utc_full_year(ctx, 0, 0, v);
}

MesValue mes_date_to_utc_string(MesContext *ctx)
{
    MesDate *d = (MesDate *)ctx->frame->thisobj;

    if (MES_DATE_BAD(d))
        return mes_eval_type_error(ctx, d);
    mes_date_set_gmtoff(d, 0);
    return mes_date_string(ctx, d, 1, 1, 0);
}

void mes_date_setup(MesContext *ctx)
{
    MesObject *proto;
    MesObject *ctor;

    proto = (MesObject *)mes_date_new(ctx);
    if (proto != NULL)
        proto->proto = (*(MesObject * *)((char *)mes_classes + 0x24));
    (*(MesObject * *)((char *)mes_classes + 0x8)) = proto;
    ctor = mes_native_new(ctx, mes_ids[2], mes_date_constructor, 7, 1);
    mes_object_set(ctx->global, mes_ids[2], (MesValue)ctor, 7);
    mes_object_set(ctor, mes_ids[59], (MesValue)proto, 7);
    mes_object_set(proto, mes_ids[40], (MesValue)ctor, 2);
    mes_native_setup(ctx, ctor, &mes_date_table1, 2);
    mes_native_setup(ctx, proto, &mes_date_table, 44);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BB38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BB40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BB44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BB50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BB60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BB70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BB80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BB94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BBA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BBB0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BBB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BBC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BBD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BBE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BBEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BBF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BC9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BCA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BCB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BCC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BCD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BCE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BCF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD68);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BD9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BDA0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BDA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BDA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", D_0013BDAC);
