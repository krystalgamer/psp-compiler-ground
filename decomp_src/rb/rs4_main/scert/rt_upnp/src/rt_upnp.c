#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_memory_free(void **);
int rt_upnp_add_port_mapping(void);
int rt_upnp_delete_port_mapping(void);
int rt_upnp_describe(void);
int rt_upnp_describe_service(void);
int rt_upnp_destroy(void *);
int rt_upnp_disable_natservice_heartbeat(void *);
int rt_upnp_discover(void);
int rt_upnp_get_connect_status(void);
int rt_upnp_get_external_address(int *, int *, int *);
int rt_upnp_get_external_ip(void);
int rt_upnp_get_version_string(void);
int rt_upnp_search_for_port_mapping(void);
int rt_upnp_set_memory_ceiling(void);
int rt_upnp_uber_resolve();
int rt_upnp_update(int *);
int rt_upnp_verify_port_mapping(void);
typedef struct { int ip; int port; } RtUpnpAddr;

extern int gpszVersionString;

int rt_upnp_get_version_string(void) {
    return gpszVersionString;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_upnp/src/rt_upnp", rt_upnp_create);

int rt_upnp_destroy(void *u)
{
    void *p = NULL;
    if (u == NULL) return 2;
    p = u;
    rt_memory_free(&p);
    return 0;
}

int rt_upnp_discover(void) {
    return 4;
}

int rt_upnp_describe(void) {
    return 4;
}

int rt_upnp_describe_service(void) {
    return 4;
}

int rt_upnp_get_connect_status(void) {
    return 4;
}

int rt_upnp_get_external_ip(void) {
    return 4;
}

int rt_upnp_search_for_port_mapping(void) {
    return 4;
}

int rt_upnp_add_port_mapping(void) {
    return 4;
}

int rt_upnp_verify_port_mapping(void) {
    return 4;
}

int rt_upnp_delete_port_mapping(void) {
    return 4;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_upnp/src/rt_upnp", rt_upnp_resolve_external_address);

int rt_upnp_get_external_address(int *u, int *addr, int *port)
{
    if (u == NULL) return 2;
    if (u[0x3C / 4] != 0) return 0xD6DA;
    if (addr == NULL) return 2;
    if (port == NULL) return 2;
    addr[0] = u[3];
    addr[1] = u[4];
    *port = u[6];
    return 0;
}

int rt_upnp_disable_natservice_heartbeat(void *arg0) {
    int var_v1;

    var_v1 = 2;
    if (arg0 != NULL) {
        var_v1 = 0xD6DA;
        if (M2C_FIELD(arg0, int *, 0x3C) == 0) {
            M2C_FIELD(arg0, int *, 0x38) = 1;
            var_v1 = 0;
        }
    }
    return var_v1;
}

void upnp_iresolve_cb();
int rt_upnp_resolve_external_address();
int rt_upnp_uber_resolve(char *u, RtUpnpAddr addr, int t, void *cb, int user)
{
    if (u == NULL) return 2;
    if (*(int *)(u + 0x3C) != 0) return 0xD6DA;
    *(void **)(u + 0x44) = cb;
    *(int *)(u + 0x48) = user;
    return rt_upnp_resolve_external_address(u, addr, t, upnp_iresolve_cb);
}

int process_nat_resolution_timeslice();
int process_heartbeat_timeslice();
int rt_upnp_update(int *u)
{
    int r = 0;
    if (u == NULL) return 2;
    switch (u[0x3C / 4]) {
    case 0:
        r = process_heartbeat_timeslice(u);
        break;
    case 1:
        r = process_nat_resolution_timeslice(u);
        break;
    }
    return r;
}

int rt_upnp_set_memory_ceiling(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_upnp/src/rt_upnp", upnp_iresolve_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_upnp/src/rt_upnp", process_heartbeat_timeslice);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_upnp/src/rt_upnp", process_nat_resolution_timeslice);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_upnp/src/rt_upnp", D_0010CC74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_upnp/src/rt_upnp", rcsid_10CC90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_upnp/src/rt_upnp", headerfile_rcsid_10CCEC);
