#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void rt_comm_destroy(void *);
void rt_comm_display_state(void);
int rt_comm_echo_enable(int *);
int rt_comm_echo_is_enabled(void);
void rt_comm_echo_set_default_options(int *);
int rt_comm_echo_shutdown(void);
int rt_comm_echo_update(void);
int rt_comm_get_avail_bytes_to_read(char *, int *);
void rt_comm_get_broadcast_ip(void);
void rt_comm_get_dns_servers(void);
void rt_comm_get_host_by_name(void);
int rt_comm_get_interface_data(char *, void **);
void rt_comm_get_local_ip(void);
int rt_comm_get_local_port(char *, int *);
void rt_comm_get_metrics(void *);
int * rt_comm_get_new_channel_id(void);
int rt_comm_get_remote_ip(char *, int *);
int rt_comm_get_version_string_ptr(void);
int rt_comm_is_connected(char *, int *);
int rt_comm_linkaddress_isequal();
int rt_comm_linkaddress_isnull();
int rt_comm_linkaddress_toext();
void rt_comm_linkaddress_toint(void);
int rt_comm_linkaddress_tostr();
void rt_comm_metric_init(void);
void rt_comm_metric_update(void);
int rt_comm_receive(char *, void *, int, int *);
int rt_comm_receive_echo(char *, int *, int, int);
int rt_comm_receive_from(char *, int, int, void *, int, int *);
int rt_comm_release_channel_id(void *);
int rt_comm_send(char *, void *, int, int *);
int rt_comm_send_echo();
int rt_comm_send_to();
void rt_comm_set_default_options(int *);
void rt_comm_shutdown(void);
int rt_comm_skip_query_section(int, char *, unsigned int, unsigned int *);
int rt_comm_startup(void);
int rt_comm_vsend(char *, void *, int *);
int rt_comm_vsend_to();
int rt_isdigit(int);
int rt_memory_allocate_init_zero(void **, unsigned int);
int rt_memory_free(void **);
int rt_msg_get_ubyte(unsigned char *, unsigned char *);
int rt_time_elapsed(void *, unsigned int *);
int rt_time_elapsed_msecs(void *, unsigned int *);
int rt_time_start(void *);
typedef struct { unsigned int ip; unsigned int port; } RtLinkAddr;

int rt_comm_is_valid_channel();

void *memcpy(void *, const void *, unsigned long);
void *memset(void *, int, unsigned int);
extern char gMetricData[];

extern void *gCommPlatformInterfacePtr;
extern int gpszVersion_11536C;
extern int gEchoInfo;

int rt_comm_get_version_string_ptr(void) {
    return gpszVersion_11536C;
}

typedef int (*CommFn)();
#define COMMIF(off) (*(CommFn *)((char *)gCommPlatformInterfacePtr + (off)))
extern int gnInitCount_1353F4;
extern char gLookupData[];

void *memset(void *, int, unsigned int);

void rt_comm_metric_add_data();

void rt_comm_metric_update_single(void *, unsigned int);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rcsid_10E72C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", header_rcsid_10E788);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", header2_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", D_0010E854);

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *rt_comm_get_build_timestamp(void) {
    return "15:12:27 Sep 19 2005";
}

int rt_comm_startup(void)
{
    int r;
    if (gCommPlatformInterfacePtr == NULL) return 5;
    if (gnInitCount_1353F4 == 0) {
        r = COMMIF(0)();
        if (r != 0) return r;
        rt_comm_metric_init();
        memset(gLookupData, 0, 0x224);
        (&gEchoInfo)[0] = 0;
        (&gEchoInfo)[1] = 0;
        (&gEchoInfo)[2] = 0;
    }
    gnInitCount_1353F4++;
    return 0;
}

void rt_comm_shutdown(void)
{
    if (gnInitCount_1353F4 <= 0) return;
    rt_comm_echo_shutdown();
    if (--gnInitCount_1353F4 != 0) return;
    (*(void (**)(void))((char *)gCommPlatformInterfacePtr + 4))();
    rt_comm_metric_init();
    memset(gLookupData, 0, 0x224);
    (&gEchoInfo)[0] = 0;
    (&gEchoInfo)[1] = 0;
    (&gEchoInfo)[2] = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_update);

void rt_comm_set_default_options(int *o)
{
    o[1] = 0;
    o[2] = 0;
    o[3] = 0;
    o[0] = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_create);

void rt_comm_destroy(void *arg0) {
    if (rt_comm_is_valid_channel() == 0) {

    } else {
        M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(int), 0xC)(M2C_FIELD(arg0, int *, 8));
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 0) = 0;
        rt_comm_release_channel_id(arg0);
    }
}

int rt_comm_send(char *ch, void *buf, int len, int *sent)
{
    int conn;
    int r;
    *sent = 0;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0xC) != 0 && *(int *)(ch + 0xC) != 2) return 0xC355;
    if (*(int *)(ch + 0x20) == 0 && *(int *)(ch + 0xC) == 0) {
        conn = 0;
        r = rt_comm_is_connected(ch, &conn);
        if (r != 0) return r;
        if (conn == 0) {
            *sent = 0;
            return 0;
        }
        *(int *)(ch + 0x20) = 1;
    }
    r = COMMIF(0x10)(*(int *)(ch + 8), buf, len, sent);
    if (r != 0) return r;
    rt_comm_metric_add_data(*sent, 0, 0x28);
    return 0;
}

int rt_comm_send_to(char *ch, RtLinkAddr addr, int a, int b, int c, int *sent)
{
    int r;
    if (COMMIF(0x54)(addr) != 0) return 2;
    *sent = 0;
    if (b == 0) return 2;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0xC) != 1) return 0xC355;
    r = COMMIF(0x14)(*(int *)(ch + 8), addr, a, b, c, sent);
    if (r != 0) return r;
    rt_comm_metric_add_data(*sent, 0, 0x1C);
    return 0;
}

int rt_comm_vsend(char *ch, void *iov, int *sent)
{
    int conn;
    int r;
    *sent = 0;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0xC) != 0 && *(int *)(ch + 0xC) != 2) return 0xC355;
    if (*(int *)(ch + 0x20) == 0 && *(int *)(ch + 0xC) == 0) {
        conn = 0;
        r = rt_comm_is_connected(ch, &conn);
        if (r != 0) return r;
        if (conn == 0) {
            *sent = 0;
            return 0;
        }
        *(int *)(ch + 0x20) = 1;
    }
    r = COMMIF(0x18)(*(int *)(ch + 8), iov, sent);
    if (r != 0) return r;
    rt_comm_metric_add_data(*sent, 0, 0x28);
    return 0;
}

int rt_comm_vsend_to(char *ch, RtLinkAddr addr, int a, int b, int *sent)
{
    int r;
    if (COMMIF(0x54)(addr) != 0) return 2;
    *sent = 0;
    if (b == 0) return 2;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0xC) != 1) return 0xC355;
    r = COMMIF(0x1C)(*(int *)(ch + 8), addr, a, b, sent);
    if (r != 0) return r;
    rt_comm_metric_add_data(*sent, 0, 0x1C);
    return 0;
}

int rt_comm_send_echo(char *ch, int *sent, RtLinkAddr addr, int d)
{
    int r;
    if (sent == NULL) return 2;
    *sent = 0;
    if (COMMIF(0x54)(addr) != 0) return 2;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0xC) != 3) return 0xC355;
    r = COMMIF(0x20)(*(int *)(ch + 8), sent, addr, d);
    if (r != 0) return r;
    rt_comm_metric_add_data(0x1C, 0, 0);
    return 0;
}

int rt_comm_receive(char *ch, void *buf, int len, int *got)
{
    int conn;
    int r;
    *got = 0;
    if (buf == NULL) return 2;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0xC) != 0 && *(int *)(ch + 0xC) != 2) return 0xC355;
    if (*(int *)(ch + 0x20) == 0 && *(int *)(ch + 0xC) == 0) {
        conn = 0;
        r = rt_comm_is_connected(ch, &conn);
        if (r != 0) return r;
        if (conn == 0) {
            *got = 0;
            return 0;
        }
        *(int *)(ch + 0x20) = 1;
    }
    r = COMMIF(0x24)(*(int *)(ch + 8), buf, len, got);
    if (r != 0) return r;
    rt_comm_metric_add_data(0, *got, 0x28);
    return 0;
}

int rt_comm_receive_from(char *ch, int a, int b, void *buf, int len, int *got)
{
    int r;
    if (got == NULL) return 2;
    *got = 0;
    if (buf == NULL) return 2;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0xC) != 1) return 0xC355;
    r = COMMIF(0x28)(*(int *)(ch + 8), a, b, buf, len, got);
    if (r != 0) return r;
    rt_comm_metric_add_data(0, *got, 0x1C);
    return 0;
}

int rt_comm_receive_echo(char *ch, int *got, int a, int b)
{
    int r;
    *got = 0;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0xC) != 3) return 0xC355;
    r = COMMIF(0x2C)(*(int *)(ch + 8), got, a, b);
    if (r != 0) return r;
    if (*got != 0) rt_comm_metric_add_data(0, 0x1C, 0);
    return 0;
}

int rt_comm_get_avail_bytes_to_read(char *ch, int *out)
{
    int conn;
    int r;
    *out = 0;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0x20) == 0 && *(int *)(ch + 0xC) == 0) {
        conn = 0;
        r = rt_comm_is_connected(ch, &conn);
        if (r != 0) return r;
        if (conn == 0) {
            *out = 0;
            return 0;
        }
        *(int *)(ch + 0x20) = 1;
    }
    return COMMIF(0x30)(*(int *)(ch + 8), out);
}

void rt_comm_get_local_ip(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x34)();
}

void rt_comm_get_broadcast_ip(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x38)();
}

void rt_comm_get_host_by_name(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x3C)();
}

int rt_comm_get_remote_ip(char *ch, int *ip)
{
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0xC) != 0 && *(int *)(ch + 0xC) != 2) return 0xC355;
    return COMMIF(0x40)(*(int *)(ch + 8), ip);
}

void rt_comm_display_state(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x44)();
}

void rt_comm_get_metrics(void *m)
{
    rt_comm_metric_update();
    memcpy(m, gMetricData, 0x38);

}

int rt_comm_is_valid_channel();
int rt_comm_get_interface_data(char *ch, void **out)
{
    *out = NULL;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    *out = ch + 8;
    return 0;
}

int rt_comm_get_local_port(char *ch, int *out)
{
    *out = 0;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    *out = *(int *)(ch + 0x1C);
    return 0;
}

int rt_comm_is_connected(char *ch, int *out)
{
    int r;
    if (rt_comm_is_valid_channel(ch) == 0) return 2;
    if (*(int *)(ch + 0xC) != 0) return 0xC355;
    if (*(int *)(ch + 0x20) == 0) {
        r = COMMIF(0x48)(*(int *)(ch + 8), ch + 0x20);
        if (r != 0) return r;
    }
    *out = *(int *)(ch + 0x20);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_get_host_by_name_nb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_generate_lookup_query);

typedef struct { int comm; int timer[2]; RtLinkAddr addr; char buf[0x200]; int len; int pad; unsigned int tries; void (*cb)(void *); } RtLookup;
extern char D_001353FC[];

int rt_comm_resend_lookup_query(RtLookup *ld)
{
    unsigned int elapsed;
    int sent = 0;

    if (ld->cb == NULL) return 0;
    rt_time_elapsed(&ld->timer, &elapsed);
    if (elapsed > 500) {
        rt_comm_send_to(ld->comm, ld->addr, 0x35, ld->buf, ld->len, &sent);
        rt_time_start(&ld->timer);
        ld->tries++;
    }
    if (ld->tries == 0x3C) {
        memset(D_001353FC, 0, 0x88);
        *(int *)(D_001353FC + 0x84) = 0xC358;
        ld->cb(D_001353FC);
        rt_comm_destroy(ld->comm);
        memset(ld, 0, 0x224);
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_check_for_query_response);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_process_response_header);

int rt_comm_skip_query_section(int a, char *buf, unsigned int len, unsigned int *off)
{
    unsigned char n = 0;

    for (;;) {
        rt_msg_get_ubyte(buf + *off, &n);
        if (n == 0) break;
        *off = *off + n + 1;
        if (*off > len) return 0xC35A;
    }
    *off += 5;
    if (*off > len) return 0xC35A;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_process_rr);

int rt_isdigit(int arg0) {
    return (unsigned int) (arg0 - 0x30) < 0xAU;
}

int *rt_comm_get_new_channel_id(void)
{
    int *ch = NULL;
    rt_memory_allocate_init_zero(&ch, 0x24);
    if (ch == NULL) return NULL;
    ch[0] = 1;
    return ch;
}

int rt_comm_release_channel_id(void *p)
{
    void *q = p;

    return rt_memory_free(&q);
}

int rt_comm_is_valid_channel(arg0)
    void *arg0;
{
    int var_v1;
    var_v1 = 0;
    if ((arg0 != NULL) && (M2C_FIELD(arg0, int *, 0) != 0) && ((var_v1 = 1, (M2C_FIELD(arg0, int *, 4) == 0)) || ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0xC) >= 4U))) {
        var_v1 = 0;
    }
    return var_v1;
}
typedef struct { int a, b; } RtTimeS;
extern RtTimeS gLastMetricPrintTime;

void rt_comm_metric_init(void)
{
    int *m = (int *)gMetricData;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 0;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
    m[9] = 0;
    m[10] = 0;
    m[11] = 0;
    m[12] = 0;
    m[13] = 0;
    rt_time_start(m);
    gLastMetricPrintTime = *(RtTimeS *)m;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_metric_add_data);

void rt_comm_metric_update(void)
{
    unsigned int el;
    rt_time_elapsed_msecs(gMetricData, &el);
    if (el < 1001) return;
    rt_comm_metric_update_single(gMetricData + 8, el);
    rt_comm_metric_update_single(gMetricData + 0x14, el);
    rt_comm_metric_update_single(gMetricData + 0x20, el);
    rt_comm_metric_update_single(gMetricData + 0x2C, el);
    rt_time_start(gMetricData);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_metric_update_single);

void rt_comm_linkaddress_setnull(RtLinkAddr *a)
{
    M2C_FIELD(gCommPlatformInterfacePtr, void (**)(RtLinkAddr *), 0x50)(a);
}

int rt_comm_linkaddress_isnull(RtLinkAddr a)
{
    return M2C_FIELD(gCommPlatformInterfacePtr, int (**)(RtLinkAddr), 0x54)(a);
}

int rt_comm_linkaddress_isequal(RtLinkAddr a, RtLinkAddr b)
{
    return M2C_FIELD(gCommPlatformInterfacePtr, int (**)(RtLinkAddr, RtLinkAddr), 0x58)(a, b);
}

int rt_comm_linkaddress_tostr(char *out, RtLinkAddr a)
{
    return M2C_FIELD(gCommPlatformInterfacePtr, int (**)(char *, RtLinkAddr), 0x5C)(out, a);
}

int rt_comm_linkaddress_toext(char *out, RtLinkAddr a)
{
    return M2C_FIELD(gCommPlatformInterfacePtr, int (**)(char *, RtLinkAddr), 0x60)(out, a);
}

void rt_comm_linkaddress_toint(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x64)();
}

int rt_comm_echo_is_enabled(void) {
    return gEchoInfo;
}

void rt_comm_echo_set_default_options(int *arg0) {
    *arg0 = 0;
}

int rt_comm_create();
int rt_comm_echo_enable(int *cfg)
{
    RtLinkAddr addr;
    int params[4];
    int ret = 5;

    if ((&gEchoInfo)[0] == 0) {
        params[0] = 3;
        params[1] = 0;
        params[2] = 0;
        params[3] = 0;
        rt_comm_linkaddress_setnull(&addr);
        ret = rt_comm_create(&(&gEchoInfo)[1], &addr, 0, params);
        if (ret == 0) {
            (&gEchoInfo)[2] = *cfg;
            (&gEchoInfo)[0] = 1;
        }
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_echo_send);

typedef struct { int on; int comm; void (*cb)(RtLinkAddr, int); } RtEchoInfo;
#define EI ((RtEchoInfo *)&gEchoInfo)
int rt_comm_echo_update(void)
{
    RtLinkAddr addr;
    int got;
    int d;
    int r;

    d = 0;
    got = 0;
    if (EI->on == 0) return 5;
    do {
        r = rt_comm_receive_echo(EI->comm, &got, &addr, &d);
        if (r != 0) return r;
        if (got == 0) return 0;
        if (EI->cb != 0)
            EI->cb(addr, d);
    } while (got != 0);
    return 0;
}

int rt_comm_echo_shutdown(void)
{
    if ((&gEchoInfo)[0] == 0) return 5;
    rt_comm_destroy((void *)(&gEchoInfo)[1]);
    (&gEchoInfo)[0] = 0;
    return 0;
}

void rt_comm_get_dns_servers(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x68)();
}
