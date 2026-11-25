#include "common.h"

/* declarations recovered from DWARF */
struct SceNetAdhocctlAdhocId;
typedef char SceChar8;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlAdhocId { /* size 0x10 */
    int type;
    SceChar8 data[9];
    SceUChar8 padding[3];
};

extern struct SceNetAdhocctlAdhocId adhoc_id;

int init_net(void);
int term_net(void);
int init_apnet(void);
int init_adhoc(void);
int term_adhoc(void);
int init_http(void);
int term_http(void);


int init_net(void)
{
    int ret;

    ret = sceNetInit(0x20000, 42, 0x1000, 42, 0x1000);
    if (ret != 0) return ret;
    ret = sceNetInetInit();
    if (ret != 0) return ret;
    ret = sceNetResolverInit();
    if (ret < 0) {
        printf("sceNetResolverInit() failed. ret = 0x%x\n", ret);
        return ret;
    }
    return ret;
}

int term_net(void)
{
    int ret;

    ret = sceNetResolverTerm();
    if (ret < 0) {
        printf("sceNetResolverTerm() failed. ret = 0x%x\n", ret);
    }
    ret = sceNetInetTerm();
    if (ret != 0) return ret;
    ret = sceNetTerm();
    return ret;
}

int init_apnet(void)
{
    int ret;

    ret = sceNetApctlInit(0x8000, 48);
    if (ret != 0) return ret;
    ret = sceSslInit(0x28000);
    if (ret < 0) {
        printf("sceSslInit() failed. ret = 0x%x\n", ret);
        return ret;
    }
    return ret;
}

int term_apnet(void)
{
    int ret;

    sceSslEnd();
    ret = sceNetApctlTerm();
    return ret;
}

int init_adhoc(void)
{
    int ret;

    ret = sceNetAdhocInit();
    if (ret < 0) return ret;
    ret = sceNetAdhocctlInit(0x2000, 48, &adhoc_id);
    return ret;
}

int term_adhoc(void)
{
    int ret;

    ret = sceNetAdhocctlTerm();
    if (ret != 0) return ret;
    ret = sceNetAdhocTerm();
    return ret;
}

int init_http(void)
{
    int ret;

    ret = sceHttpInit(0x25800);
    if (ret != 0) return ret;
    ret = sceHttpsInit(0, 0, 0, 0);
    if (ret != 0) return ret;
    ret = sceHttpsLoadDefaultCert(0, 0);
    if (ret != 0) return ret;
    ret = sceHttpLoadSystemCookie();
    return ret;
}

int term_http(void)
{
    int ret;

    ret = sceHttpSaveSystemCookie();
    if (ret != 0) return ret;
    ret = sceHttpsEnd();
    if (ret != 0) return ret;
    ret = sceHttpEnd();
    return ret;
}
