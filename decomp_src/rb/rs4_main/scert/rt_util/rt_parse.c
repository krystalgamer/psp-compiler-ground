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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_get_callback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_zero_execution_counts);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_get_execution_counts);

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
