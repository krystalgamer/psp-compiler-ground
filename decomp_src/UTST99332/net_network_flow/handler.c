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

void clear_evf(void) {
    evf_322D0 = 0;
    error_code = 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/handler", adhocctl_handler);

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

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/handler", wait_connect);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/handler", wait_disconnect);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/handler", wait_scan);
