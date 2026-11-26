#include "common.h"

/* declarations recovered from DWARF */
typedef int SceUID;
typedef struct SceKernelLMOption SceKernelLMOption;
struct SceKernelLMOption;
typedef unsigned int SceSize;
struct SceKernelLMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};

extern SceUID ifhandle_modid;
extern SceUID memab_modid;
extern SceUID pspnet_adhoc_auth_modid;
extern SceUID pspnet_modid;
extern SceUID pspnet_adhoc_modid;
extern SceUID pspnet_adhocctl_modid;
extern SceUID pspnet_adhoc_matching_modid;

static SceUID load_module(const char *path, SceUID mpid);
static int unload_module(SceUID modid);
int load_required_modules(void);
int unload_required_modules(void);


/* SDK prototypes (tools/sdk_protos.h) */
int printf(const char *fmt, ...);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/load_modules", load_module);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/load_modules", unload_module);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/load_modules", load_required_modules);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/load_modules", unload_required_modules);
