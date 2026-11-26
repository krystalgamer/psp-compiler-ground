#include "common.h"

/* declarations recovered from DWARF */
typedef char SceChar8;
typedef struct SceKernelLMOption SceKernelLMOption;
struct SceKernelLMOption;
typedef unsigned int SceSize;
typedef int SceUID;
struct SceKernelLMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};
typedef struct SceKernelSMOption SceKernelSMOption;
struct SceKernelSMOption;
struct SceKernelSMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidstack;
    SceSize stacksize;
    int priority;
    unsigned int attribute;
};
typedef int SceInt32;
struct _anon1;
struct _anon1 { /* size 0x8 */
    const SceChar8 *name;
    SceInt32 partition;
};

extern SceUID moduleIDs[4];
extern const struct _anon1 moduleInfo[4];
extern char local_host[128];
extern char modulename[256];

static SceUID load_module(const SceChar8 *filename, SceKernelLMOption *lm_opt, SceKernelSMOption *sm_opt);
static SceInt32 unload_module(SceUID mid);
SceInt32 unloadModuleVideo(void);
SceInt32 loadModuleVideo(void);


INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/moduleload", D_0001275C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/moduleload", D_00012774);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/moduleload", D_0001278C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/moduleload", D_000127A4);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/moduleload", moduleInfo);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/moduleload", load_module);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/moduleload", unload_module);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/moduleload", unloadModuleVideo);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/moduleload", loadModuleVideo);
