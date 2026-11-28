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

extern void *gpfPreExecuteCallback; extern int gMaxMessageSize; extern unsigned char gFragmentID; extern void *gpTempBuf;
int rt_memory_allocate_init_zero(); int rt_parse_fragment_handler();
int rt_parse_initialize(int maxmsg, unsigned int types, unsigned int classes, void *precb)
{
    int r;

    if (gbInitialized_135B94 != 0) return 0x3E8;
    if (types > 256) return 2;
    if (classes > 256) return 2;
    gpfPreExecuteCallback = precb;
    gMaxTypes = types;
    gMaxClasses = classes;
    gMaxMessageSize = maxmsg;
    r = rt_memory_allocate_init_zero(&gaTypeCount, classes * 4);
    if (r != 0) return r;
    r = rt_memory_allocate_init_zero(&gapfParsers, classes * types * 4);
    if (r != 0) return r;
    r = rt_memory_allocate_init_zero(&gpTempBuf, maxmsg * 3);
    if (r != 0) return r;
    r = rt_memory_allocate_init_zero(&gaExecutionCount, classes * types * 4);
    if (r != 0) return r;
    gbInitialized_135B94 = 1;
    r = rt_parse_reg_parser(2, 0, rt_parse_fragment_handler);
    if (r != 0) return r;
    gFragmentID = 0;
    return 0;
}

extern void *gpTempBuf;
int rt_memory_free();
int rt_parse_shutdown(void)
{
    unsigned int i;

    if (gpaFragMsg != NULL) {
        for (i = 0; i < 256; i++)
            if (gpaFragMsg[i].buf != NULL)
                rt_memory_free(&gpaFragMsg[i].buf);
        rt_memory_free(&gpaFragMsg);
    }
    if (gaTypeCount != NULL) rt_memory_free(&gaTypeCount);
    if (gapfParsers != NULL) rt_memory_free(&gapfParsers);
    if (gpTempBuf != NULL) rt_memory_free(&gpTempBuf);
    if (gaExecutionCount != NULL) rt_memory_free(&gaExecutionCount);
    gbInitialized_135B94 = 0;
    return 0;
}

int rt_parse_register(unsigned int *type_out, unsigned int cls, void *fn)
{
    unsigned int n;
    void **slot;

    if (gbInitialized_135B94 != 1) return 5;
    if (gapfParsers == NULL) return 5;
    if (gaTypeCount == NULL) return 5;
    if (type_out == NULL) return 2;
    if (cls >= gMaxClasses) return 2;
    n = gaTypeCount[cls];
    if (n > gMaxTypes) return 0x3EB;
    gaTypeCount[cls] = n + 1;
    slot = (void **)(((cls * gMaxTypes + n) << 2) + (int)gapfParsers);
    *type_out = n;
    *slot = fn;
    return 0;
}

int rt_parse_reg_parser(unsigned int type, unsigned int cls, void *fn)
{
    unsigned int n;
    void **slot;

    if (gbInitialized_135B94 != 1) return 5;
    if (gapfParsers == NULL) return 5;
    if (gaTypeCount == NULL) return 5;
    if (type >= 256) return 2;
    if (cls >= gMaxClasses) return 2;
    n = gaTypeCount[cls];
    if (n > gMaxTypes) return 0x3EB;
    if (type >= n) gaTypeCount[cls] = type + 1;
    slot = (void **)(((cls * gMaxTypes + type) << 2) + (int)gapfParsers);
    if (*slot != NULL) return 0x3EA;
    *slot = fn;
    return 0;
}

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
