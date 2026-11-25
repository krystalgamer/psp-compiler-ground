#include "common.h"

/* declarations recovered from DWARF */


extern char *boot_path;

static int LoadNetModules(void);
static int UnloadNetModules(void);


int sceUtilityLoadNetModule(int);
int sceUtilityUnloadNetModule(int);
int printf(const char *, ...);

static int LoadNetModules(void)
{
    int ret;

    ret = sceUtilityLoadNetModule(1);
    if (ret < 0) {
        printf("sceUtilityLoadNetModule(SCE_UTILITY_NET_MODULE_COMMON) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityLoadNetModule(2);
    if (ret < 0) {
        printf("sceUtilityLoadNetModule(SCE_UTILITY_NET_MODULE_ADHOC) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityLoadNetModule(3);
    if (ret < 0) {
        printf("sceUtilityLoadNetModule(SCE_UTILITY_NET_MODULE_INET) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityLoadNetModule(4);
    if (ret < 0) {
        printf("sceUtilityLoadNetModule(SCE_UTILITY_NET_MODULE_URI) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityLoadNetModule(5);
    if (ret < 0) {
        printf("sceUtilityLoadNetModule(SCE_UTILITY_NET_MODULE_PARSE_HTTP) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityLoadNetModule(6);
    if (ret < 0) {
        printf("sceUtilityLoadNetModule(SCE_UTILITY_NET_MODULE_HTTP) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityLoadNetModule(7);
    if (ret < 0) {
        printf("sceUtilityLoadNetModule(SCE_UTILITY_NET_MODULE_SSL) failed. ret = 0x%x\n", ret);
        return ret;
    }
    return 0;
}

static int UnloadNetModules(void)
{
    int ret;

    ret = sceUtilityUnloadNetModule(7);
    if (ret < 0) {
        printf("sceUtilityUnloadNetModule(SCE_UTILITY_NET_MODULE_SSL) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityUnloadNetModule(6);
    if (ret < 0) {
        printf("sceUtilityUnloadNetModule(SCE_UTILITY_NET_MODULE_HTTP) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityUnloadNetModule(5);
    if (ret < 0) {
        printf("sceUtilityUnloadNetModule(SCE_UTILITY_NET_MODULE_PARSE_HTTP) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityUnloadNetModule(4);
    if (ret < 0) {
        printf("sceUtilityUnloadNetModule(SCE_UTILITY_NET_MODULE_URI) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityUnloadNetModule(3);
    if (ret < 0) {
        printf("sceUtilityUnloadNetModule(SCE_UTILITY_NET_MODULE_INET) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityUnloadNetModule(2);
    if (ret < 0) {
        printf("sceUtilityUnloadNetModule(SCE_UTILITY_NET_MODULE_ADHOC) failed. ret = 0x%x\n", ret);
        return ret;
    }
    ret = sceUtilityUnloadNetModule(1);
    if (ret < 0) {
        printf("sceUtilityUnloadNetModule(SCE_UTILITY_NET_MODULE_COMMON) failed. ret = 0x%x\n", ret);
        return ret;
    }
    return 0;
}

int LoadRequiredModules(void) {
    return __builtin_allegrex_min(LoadNetModules(), 0);
}

void StopDeleteLoadedModules(void) {
    UnloadNetModules();
}
