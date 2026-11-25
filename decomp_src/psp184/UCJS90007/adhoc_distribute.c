#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", _sce_pspnet_adhoc_distribute_get_server_ctx);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", _sce_pspnet_adhoc_distribute_get_worker_ctx);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", sceNetAdhocDistributeInitServer);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", sceNetAdhocDistributeCreateServer);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", sceNetAdhocDistributeStartServer);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", sceNetAdhocDistributeStopServer);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", sceNetAdhocDistributeDeleteServer);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", sceNetAdhocDistributeTermServer);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_distribute_server_matching_cb_func);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_distribute_malloc_init);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_distribute_malloc_term);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_distribute_malloc);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", sceNetAdhocDistributeGetPoolStat);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_distribute_free);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_download_maketag);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_download_gettag);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", sceNetAdhocDistributeUpdateServerHelloOpt);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_distribute_get_reqmsg);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_distribute_worker_thread);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_distribute_send);
