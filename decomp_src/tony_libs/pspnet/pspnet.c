#include "common.h"

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211ScanJoinRequest);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211ScanCreateRequest);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211LeaveRequest);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211SetAuth);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211SetPowerSave);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211GetIfInfo);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211GetBssDesc);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211ScanRequest);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211CreateRequest);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211JoinRequest);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211SetConf);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211GetConf);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211GetAuth);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211GetPowerSave);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfig80211EnterGameMode);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfigUpInterface);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfigDownInterface);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfigGetEtherAddr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetGetLocalEtherAddr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfigGetIfEvent);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfigSetIfEventFlag);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetConfigGetIfEventFlag);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetInit);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetTerm);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000016BC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00001A00);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_schednetintr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_schednetintr_with_evf);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00001B7C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_start_of_inet_module_in_netintr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_stop_of_inet_module_in_netintr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_start_of_ipv6_module_in_netintr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_stop_of_ipv6_module_in_netintr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_start_of_pppoe_module_in_netintr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_stop_of_pppoe_module_in_netintr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_start_of_adhoc_module_in_netintr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_stop_of_adhoc_module_in_netintr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_thread_enter);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetFreeThreadinfo);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00001F0C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_get_threadinfo);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_lock_threadinfo);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_unlock_threadinfo);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_thread_leave);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_get_thread_errno);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_set_thread_errno);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_thread_busycount);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00002300);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetThreadAbort);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetBpfPoll);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetBpfOpen);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetBpfClose);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetBpfRead);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetBpfWrite);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetBpfIoctl);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000028D0);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_callout_reset_usec);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_callout_stop);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00002B34);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_callout_init);

void _sce_pspnet_callout_cleanup(void) {
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_callout_reset);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00002C74);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00002D48);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_tsleep_usec);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00002FC4);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00003028);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_tsleep);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000030A8);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_wakeup);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_tiwakeup);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_tabort);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_adhoc_sabort);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_inet_sabort);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_start_of_adhoc_module_in_sched);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_stop_of_adhoc_module_in_sched);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_start_of_inet_module_in_sched);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_stop_of_inet_module_in_sched);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00003438);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_0000348C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_spllock);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_splunlock);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNet_lib_6DC71518);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_microtime);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_uiomove);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_hashinit);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_hashdone);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_selrecord);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_selwakeup);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_get_selwait_addr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000037D4);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00003940);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00003B20);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00003E80);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00003FA4);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000040D8);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000040FC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00004160);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_0000426C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000042AC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00004318);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00004410);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000044C0);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00004594);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00004618);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000046A0);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000047EC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00004CC8);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00004DD8);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00004EEC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_if_attach);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_if_detach);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_if_down);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00005404);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_ifioctl);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000057D8);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_if_nulloutput);

void func_0000593C(void) {
}

void func_00005944(void) {
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_0000594C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00005954);

void func_0000595C(void) {
}

void func_00005964(void) {
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_0000596C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_ifafree);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_link_rtrequest);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_if_up);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00005A78);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_ifunit);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_if_exist);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_ifioctl_sync);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_get_ifindex);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_ifplookup_index);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_get_if_core_variables);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_start_of_inet_module_in_if_core);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_stop_of_inet_module_in_if_core);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_0000610C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00006A40);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00006B10);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00006BBC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00006C28);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00006C90);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_ifplookup_lladdr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_start_of_inet_module_in_if_ethersubr_core);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_stop_of_inet_module_in_if_ethersubr_core);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_start_of_adhoc_module_in_if_ethersubr_core);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_stop_of_adhoc_module_in_if_ethersubr_core);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00006E34);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000071C8);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000071FC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007680);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_start_of_inet_module_in_ifhandle_ether);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", _sce_pspnet_stop_of_inet_module_in_ifhandle_ether);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007738);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007778);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007798);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetRand);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000079DC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000079E4);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetGetSystemClockSec);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007A1C);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", D_00009D18);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetEtherNtostr);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetEtherStrton);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", sceNetGetMallocStat);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", module_start);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", module_stop);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007B88);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007BC0);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007C34);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007C74);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007CA8);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007CD4);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007D14);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007D38);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007D60);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007E10);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007E58);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007EF0);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007F6C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007F9C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00007FD4);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00008008);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00008054);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_0000877C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000087A4);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000087D0);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_000087FC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00008810);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_0000881C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", func_00008D6C);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", D_00009DA0);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", D_00009DA8);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet/nonmatchings/pspnet", D_00009F8C);
