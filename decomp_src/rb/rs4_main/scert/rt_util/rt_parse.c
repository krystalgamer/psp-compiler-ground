#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
extern unsigned char gbInitialized_135B94;
extern void **gapfParsers;
extern unsigned int *gaTypeCount;
extern unsigned int gMaxClasses;
extern unsigned int gMaxTypes;
extern unsigned int *gaExecutionCount;
typedef struct { int used; char pad[0x20]; int time; int x; int y; void *buf; } RtFragMsg;
extern RtFragMsg *gpaFragMsg;
void rt_parse_update(void);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_initialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_shutdown);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_register);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_reg_parser);

extern unsigned char gbInitialized_135B94;
extern void *gpfAppParser;
int rt_parse_reg_app_parser(void *f)
{
    if (gbInitialized_135B94 != 1) return 5;
    gpfAppParser = f;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_update_parser);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_execute);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_execute_ext);

int rt_parse_get_callback(unsigned int cls, unsigned int type, void **out)
{
    if (out == NULL) return 2;
    *out = NULL;
    if (gbInitialized_135B94 != 1) return 5;
    if (gapfParsers == NULL) return 5;
    if (gaTypeCount == NULL) return 5;
    if (cls >= gMaxClasses) return 2;
    if (type >= gMaxTypes) return 2;
    *out = gapfParsers[cls * gMaxTypes + type];
    if (*out == NULL) return 2;
    return 0;
}

int rt_parse_zero_execution_counts(unsigned int cls)
{
    if (gbInitialized_135B94 != 1) return 5;
    if (gapfParsers == 0) return 5;
    if (gaTypeCount == 0) return 5;
    if (gaExecutionCount == 0) return 5;
    if (cls >= gMaxClasses) return 2;
    memset((void *)((int)gaExecutionCount + (cls * gMaxTypes << 2)), 0, gMaxTypes * 4);
    return 0;
}

int rt_parse_get_execution_counts(unsigned int cls, unsigned int *out, unsigned int n)
{
    unsigned int i;

    if (gbInitialized_135B94 != 1) return 5;
    if (gapfParsers == NULL) return 5;
    if (gaTypeCount == NULL) return 5;
    if (gaExecutionCount == NULL) return 5;
    if (cls >= gMaxClasses) return 2;
    if (out == NULL) return 2;
    if (n < gMaxTypes) return 2;
    for (i = 0; i < gMaxTypes; i++)
        *out++ = gaExecutionCount[cls * gMaxTypes + i];
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_fragment_message);

int rt_time_elapsed();
int rt_memory_free();
int rt_parse_timeout_frag_msg(void)
{
    unsigned int i;
    unsigned int el;

    if (gpaFragMsg != NULL) {
        for (i = 0; i < 256; i++) {
            if (gpaFragMsg[i].used != 0) {
                rt_time_elapsed(&gpaFragMsg[i].time, &el);
                if (el >= 30001) {
                    rt_memory_free(&gpaFragMsg[i].buf);
                    gpaFragMsg[i].used = 0;
                }
            }
        }
    }
    return 0;
}

void rt_parse_update(void) {
    rt_parse_timeout_frag_msg();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_find_frag_msg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_fragment_handler);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rcsid_10EE44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", headerfile_rcsid_10EEA0);
