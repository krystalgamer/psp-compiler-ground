/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

const char D_0002DB14[] = "internet";

extern int tcp_syn_cache_size, tcp_syn_cache_limit, tcp_syn_bucket_limit, tcp_syn_cache_interval, tcp_rst_ppslim, icmperrppslim;
extern char tcp_syn_cache[];

void
func_00014824(void)
{
	tcp_syn_cache_size = 0x125;
	tcp_syn_cache_limit = 0x280F;
	tcp_syn_bucket_limit = 0x69;
	memset(tcp_syn_cache, 0, 0x928);
	tcp_syn_cache_interval = 1;
	icmperrppslim = tcp_rst_ppslim = 100;
}
