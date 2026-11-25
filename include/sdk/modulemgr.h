#ifndef _MODULEMGR_H
#define _MODULEMGR_H
#include <kerneltypes.h>
struct SceKernelLMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};
typedef struct SceKernelLMOption SceKernelLMOption;
struct SceKernelSMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidstack;
    SceSize stacksize;
    int priority;
    unsigned int attribute;
};
typedef struct SceKernelSMOption SceKernelSMOption;
struct SceKernelModuleInfo { /* size 0x40 */
    SceSize size;
    char nsegment;
    char reserved[3];
    int segmentaddr[4];
    int segmentsize[4];
    unsigned int entry_addr;
    unsigned int gp_value;
    unsigned int text_addr;
    unsigned int text_size;
    unsigned int data_size;
    unsigned int bss_size;
};
typedef struct SceKernelModuleInfo SceKernelModuleInfo;
SceUID sceKernelLoadModule(const char *path, int flags, const SceKernelLMOption *option);
SceUID sceKernelLoadModuleByID(SceUID fd, int flags, const SceKernelLMOption *option);
int sceKernelStartModule(SceUID modid, SceSize args, void *argp, int *status, const SceKernelSMOption *option);
int sceKernelStopModule(SceUID modid, SceSize args, void *argp, int *status, const SceKernelSMOption *option);
int sceKernelUnloadModule(SceUID modid);
#endif
