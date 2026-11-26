#include "common.h"

void Menu_WriteLine(const char *line, int color);

/* declarations recovered from DWARF */
struct SceNetAdhocctlAdhocId;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlAdhocId { /* size 0x10 */
    int type;
    SceUChar8 data[9];
    SceUChar8 padding[3];
};

extern struct SceNetAdhocctlAdhocId adhoc_id;

int init_net(void);
int term_net(void);
int init_adhoc(void);
int term_adhoc(void);


int init_net(void)
{
	int ret;

	ret = sceNetInit(0x20000, 42, 0x1000, 42, 0x1000);
	if (ret != 0) {
		return ret;
	}

	ret = sceNetInetInit();
	if (ret != 0) {
		return ret;
	}

	return 0;
}

int term_net(void)
{
	int ret;

	ret = sceNetInetTerm();
	if (ret != 0) {
		return ret;
	}

	ret = sceNetTerm();
	if (ret != 0) {
		return ret;
	}

	return 0;
}

int init_apnet(void) {
    return sceNetApctlInit(0x8000, 0x30);
}

int term_apnet(void) {
    return sceNetApctlTerm();
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
