/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
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
extern MesObject *D_00585338;
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
M2C_UNK mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_date_method;


MesDate *mes_date_new(MesContext *ctx)
{
    MesDate *d = mes_gc_alloc(ctx, 7);

    if (d != NULL) {
        mes_object_init(&d->obj, 2, D_00585338);
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_is_leap_year);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_now);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_from_value);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_to_value);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_constructor);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_utc);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_to_locale_time_string);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_get_year);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_get_timezone_offset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_set_time);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_set_hours);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_set_utc_hours);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_set_full_year);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_set_year);

MesValue mes_date_set_month(MesContext *ctx, int m, int v)
{
    return mes_date_set_full_year(ctx, 0, m, v);
}

MesValue mes_date_set_date(MesContext *ctx, int v)
{
    return mes_date_set_full_year(ctx, 0, 0, v);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_set_utc_full_year);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_date", mes_date_setup);

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
