#ifndef IF_SPPPVAR_H
#define IF_SPPPVAR_H

/* NetBSD 1.6 net/if_spppvar.h as cut down by Sony (pspnet_inet) */

#define IDX_LCP 0
#define IDX_IPCP 1
#define IDX_PAP 2
#define IDX_CHAP 3
#define IDX_COUNT 4

struct slcp {
	u_long opts;
	u_long magic;
	u_long mru;
	u_long their_mru;
	u_long protos;
	u_char echoid;
	int timeout;
	int max_terminate;
	int max_configure;
	int max_failure;
};

struct sipcp {
	u_long opts;
	u_int flags;
	u_int32_t myaddr;
	u_int32_t hisaddr;
};

#define AUTHNAMELEN 128
#define AUTHKEYLEN 128

struct sauth {
	u_short proto;
	u_short flags;
	char name[AUTHNAMELEN];
	char secret[AUTHKEYLEN];
	u_char name_len;
	u_char secret_len;
	char challenge[16];
	int timeout;
	int max_configure;
};

struct sppp {
	struct ifnet pp_if;
	char pp_unkE8[0x128 - sizeof(struct ifnet)];
	struct ifqueue pp_cpq;
	u_int pp_flags;
	u_int pp_framebytes;
	u_short pp_alivecnt;
	u_short pp_loopcnt;
	u_long pp_seq[IDX_COUNT];
	u_long pp_rseq[IDX_COUNT];
	u_quad_t pp_saved_mtu;
	int pp_phase;
	int pp_status;
	u_int32_t dns_addrs[2];
	int state[IDX_COUNT];
	u_char confid[IDX_COUNT];
	int rst_counter[IDX_COUNT];
	int fail_counter[IDX_COUNT];
	struct callout ch[IDX_COUNT];
	struct slcp lcp;
	struct sipcp ipcp;
	struct sauth myauth;
	u_char chap_ident;
	u_char chap_value[255];
	int chap_value_len;
	void (*pp_up)(struct sppp *sp);
	void (*pp_down)(struct sppp *sp);
	void (*pp_tls)(struct sppp *sp);
	void (*pp_tlf)(struct sppp *sp);
	void (*pp_con)(struct sppp *sp);
	void (*pp_chg)(struct sppp *sp, int new_state);
};

#define PP_KEEPALIVE 0x01
#define PP_NEEDAUTH 0x10
#define PP_NOFRAMING 0x20

#define sppp_input func_00026A4C
#define sppp_flush func_00026D5C
#define sppp_dequeue func_00026DEC
#define sppp_ioctl func_00026E9C
#define sppp_attach func_000291A4
#define sppp_detach func_000292E0
#define sppp_isempty func_00029330

void sppp_attach(struct ifnet *ifp);
void sppp_detach(struct ifnet *ifp);
void sppp_input(struct ifnet *ifp, struct mbuf *m);
int sppp_ioctl(struct ifnet *ifp, u_long cmd, void *data);
struct mbuf *sppp_dequeue(struct ifnet *ifp);
int sppp_isempty(struct ifnet *ifp);
void sppp_flush(struct ifnet *ifp);

#endif
