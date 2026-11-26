#include "common.h"

/* declarations recovered from DWARF */


extern int evf;
extern int error_code;
extern char event_str[4][16];

void adhocctl_handler(int event, int error, void *arg);
int wait_connect(void);
int wait_disconnect(void);
int wait_scan(void);


extern int evf_322D0;

/* SDK prototypes (tools/sdk_protos.h) */
int printf(const char *fmt, ...);
int sceKernelDelayThread(unsigned int delay);

void clear_evf(void) {
    evf_322D0 = 0;
    error_code = 0;
}

#define evf evf_322D0
void adhocctl_handler(int event, int error, void *arg)
{
	printf("event: [%s] error_code = 0x%x\n", event_str[event], error);
	if (event == 0) {
		error_code = error;
		evf |= 0x01;
	} else if (event == 1) {
		error_code = 0;
		evf |= 0x02;
	} else if (event == 2) {
		error_code = 0;
		evf |= 0x04;
	} else if (event == 3) {
		error_code = 0;
		evf |= 0x08;
	}
}
#undef evf

extern int evf_322D0;

int polling_error(void) {
    int var_a0;

    var_a0 = 0;
    if (evf_322D0 & 1) {
        evf_322D0 &= ~1;
        var_a0 = error_code;
    }
    return var_a0;
}

#define evf evf_322D0
int wait_connect(void)
{
	int ret;

	ret = 0;
	while (1) {
		if (evf & 0x02)
			break;
		if (evf & 0x01) {
			ret = error_code;
			evf &= ~0x01;
			break;
		}
		sceKernelDelayThread(1000000);
	}
	evf &= ~0x02;
	return ret;
}
#undef evf

#define evf evf_322D0
int wait_disconnect(void)
{
	while (1) {
		if (evf & 0x04)
			break;
		sceKernelDelayThread(1000000);
	}
	evf &= ~0x04;
	return 0;
}
#undef evf

#define evf evf_322D0
int wait_scan(void)
{
	int ret;

	ret = 0;
	while (1) {
		if (evf & 0x08)
			break;
		if (evf & 0x01) {
			ret = error_code;
			evf &= ~0x01;
			break;
		}
		sceKernelDelayThread(1000000);
	}
	evf &= ~0x08;
	return ret;
}
#undef evf
