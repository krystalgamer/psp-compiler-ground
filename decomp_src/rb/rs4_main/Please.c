#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *rt_comm_adhoc_resolve_interface(void);
M2C_UNK *rt_comm_platform_resolve_interface(void);
M2C_UNK *rt_udp_get_version_string(void);
int InitObjectUpdateList(void);
int IsEven(int *arg0);
int KM_SetUpdateCallback(int arg0);
int NetClientIndexToClientIndexPacket(int arg0);
int NetDisableLanMessaging(void);
int NetGetBuildTimeStamp(signed char *arg0);
int NetGetLocalTime(int *arg0);
int NetGetMaxDataStreamTypes(int *arg0);
int NetGetMaxDataStreams(int *arg0);
int NetGetMaxFieldsPerStructure(int *arg0);
int NetGetMaxObjects(int *arg0);
int NetGetMaxStructures(int *arg0);
int NetGetMsgClientIndex(void *arg0);
int NetGetMyWorldID(void);
int NetGetNatService(M2C_UNK **arg0);
int NetGetP2PHandle(void *arg0);
int NetIGetClientIpAddress(void *arg0, int arg1, int arg2);
int NetIGetCurrentUDPSourceBinaryIP(void *arg0);
int NetIGetMyClientIndex(int *arg0, void *arg1);
int NetIGetSessionMasterClientIndex(int *arg0, void *arg1);
int NetIGetTime(void *arg0);
int NetIRegParseMessage(void);
int NetIRegisterMessage(void);
int NetISetDefaultResolveAddrParams(void *arg0);
int NetIUpdateParseMessage(void);
int NetLANSetDefaultEnableMessagingInParams(void *arg0);
int NetSetConnInfo(int arg0, int arg1);
int NetSetDefaultBitMask(void *arg0);
int NetSetDefaultIncomingClientParams(int *arg0);
int NetSetDefaultJoinParams(void *arg0);
int NetSetDefaultLatencyMetricsParams(void *arg0);
int NetSetDefaultLookupParams(void *arg0);
int NetSetDefaultNetUsePeerToPeerInParams(void *arg0);
int NetSetPeerToPeerHostChangeCallback(int arg0, int arg1);
int NetSetSessionMasterClientIndex(void *arg0, int arg1);
int NetTokenSystemQuery(void *arg0, int *arg1);
int NetUseCommAdhoc(void);
int NetUseCommInet(void);
int NetUseCommSockets(void);
int NetUseCrypt(void);
int NetUseDme(void);
int NetUseUDP(void);
int RemoveFromObjectUpdateList(void);
int RtMsgToDmeConnectionIndex(unsigned int arg0);
int ServerResponsePacketHandler(void);
int rt_comm_adhoc_display_state(void);
int rt_comm_adhoc_get_avail_bytes_to_read(void);
int rt_comm_adhoc_get_host_by_name(void);
int rt_comm_adhoc_get_remote_ip(void);
int rt_comm_adhoc_is_connected(void);
int rt_comm_adhoc_receive(void);
int rt_comm_adhoc_receive_echo(void);
int rt_comm_adhoc_send(void);
int rt_comm_adhoc_update(void);
int rt_comm_adhoc_vsend(void);
int rt_comm_echo_is_enabled(void);
int rt_comm_get_version_string_ptr(void);
int rt_comm_is_valid_channel();
int rt_comm_platform_display_state(void);
int rt_comm_platform_linkaddress_toint(int *arg0, int arg1);
int rt_comm_platform_update(void);
int rt_constraint_check_RT_4BYTE_FP(float *arg0, void *arg1);
int rt_isdigit(int arg0);
int rt_memory_allocate_init_zero(void **arg0, unsigned int arg1);
int rt_memory_get_aligned_address(unsigned int *arg0, unsigned int arg1, int arg2);
int rt_memory_register_another_callback(int arg0);
int rt_memory_register_callbacks(int arg0, int arg1);
int rt_msg_set_byte(signed char *arg0, signed char arg1);
int rt_mutex_platform_destroy(void *arg0);
int rt_mutex_platform_get_thread_id(int *arg0);
int rt_mutex_platform_lock(void *arg0);
int rt_mutex_platform_unlock(void *arg0);
int rt_p2p_get_max_peers(void *arg0, int *arg1);
int rt_p2p_get_overlay_peer_count(void *arg0, int arg1, int *arg2);
int rt_p2p_get_virtual_port(void *arg0, unsigned short *arg1);
int rt_p2p_pack_type(int arg0, int arg1);
int rt_p2p_process_local_broadcast_test(void *arg0, int arg1);
int rt_p2p_set_send_aggregation(int *arg0);
int rt_p2p_tick(int arg0);
int rt_socket_cleanup_stack_platform(void);
int rt_socket_close_platform(void);
int rt_socket_get_version_string(void);
int rt_socket_listen_tcp(void);
int rt_socket_recvmsg_platform(void);
int rt_strlen(signed char *arg0);
int rt_time_platform_init(void);
int rt_time_sleep_usecs_platform();
int rt_timebase_restart(void);
int rt_udp_destroy_shared_channel_data(void *arg0);
int rt_udp_disable_nat_service_heartbeat(void *arg0);
int rt_udp_get_aggregation_interval(void *arg0, int *arg1);
int rt_udp_get_inactivity_timeout(int *arg0);
int rt_udp_get_local_address(void *arg0, void *arg1, int *arg2);
int rt_udp_get_virtual_port(void *arg0, unsigned short *arg1);
int rt_udp_listen(void *arg0, int arg1);
int rt_udp_mgr_destroy(void);
int rt_udp_set_aggregation_interval();
int rt_udp_set_connection_inactivity_timeout(void *arg0, int arg1);
int rt_udp_set_inactivity_timeout(int arg0);
int rt_upnp_add_port_mapping(void);
int rt_upnp_delete_port_mapping(void);
int rt_upnp_describe(void);
int rt_upnp_describe_service(void);
int rt_upnp_disable_natservice_heartbeat(void *arg0);
int rt_upnp_discover(void);
int rt_upnp_get_connect_status(void);
int rt_upnp_get_external_ip(void);
int rt_upnp_get_version_string(void);
int rt_upnp_search_for_port_mapping(void);
int rt_upnp_set_memory_ceiling(void);
int rt_upnp_verify_port_mapping(void);
int rt_upnp_xml_create_parser(void);
int rt_upnp_xml_destroy_parser(void);
int rt_upnp_xml_get_parse_data(void);
int rt_upnp_xml_get_parser_type(void);
int rt_upnp_xml_is_document_complete(void);
int rt_upnp_xml_parse(void);
int rt_xmlparse_create(void);
int rt_xmlparse_destroy(void);
int rt_xmlparse_is_document_complete(void);
int rt_xmlparse_parse_buf(void);
int rt_xmlparse_set_character_data_cb(void);
int rt_xmlparse_set_element_end_cb(void);
int rt_xmlparse_set_element_start_cb(void);
int rt_xmlparse_set_user_data(void);
void ClearInterfacePointers(void);
void InitializePRNG(void);
void KM_GenerateRSAKeyPair(int arg0, int arg1);
void LANFindSetLocalServer(int arg0, int arg1);
void NetCreateConnInfoBare(void);
void NetFreeClientPointers(void);
void NetGetMyAddressInfoInternal(void *arg0);
void NetIGetDataStream(void);
void NetISendFieldUpdates(void);
void NetMutexUnlock(void);
void NetRegisterMemoryCallbacks(void);
void NetResetTime(int arg0);
void NetSetHeartbeatInterval(int arg0);
void NetSetLatencyMetricsCallback(int arg0, int arg1);
void lintAddIP(int arg0, int arg1);
void lintClearBit(int arg0, unsigned int arg1);
void lintSetBit(int arg0, unsigned int arg1);
void lintSetSmallValue(int *arg0, int arg1);
void p2p_system_change_cb(int arg0, int arg1, void *arg2);
void randReSync(void);
void rt_comm_adhoc_shutdown(void);
void rt_comm_destroy(void *arg0);
void rt_comm_display_state(void);
void rt_comm_echo_set_default_options(int *arg0);
void rt_comm_get_broadcast_ip(void);
void rt_comm_get_dns_servers(void);
void rt_comm_get_host_by_name(void);
void rt_comm_get_local_ip(void);
void rt_comm_linkaddress_toint(void);
void rt_comm_platform_get_dns_servers(void);
void rt_p2p_reset_peer_info(void *arg0, void *arg1);
void rt_parse_update(void);
void rt_socket_cleanup_stack(void);
void rt_socket_close(void);
void rt_socket_find_closed_sockets(void);
void rt_socket_find_sockets_with_data(void);
void rt_socket_get_available_bytes_to_read(void);
void rt_socket_get_dns_servers(void);
void rt_socket_get_local_ip(void);
void rt_socket_initialize_stack(void);
void rt_socket_is_connected(void);
void rt_socket_recvmsg(void);
void rt_socket_sendmsg(void);
void rt_socket_set_no_delay_tcp(void);
void rt_socket_set_non_blocking(void);
void rt_time_elapsed(void);
void rt_time_get_date_time(void);
void rt_time_get_gmtime(void);
void rt_time_get_local(void);
void rt_time_get_time_stamp(void);
void rt_time_get_time_string(void);
void rt_time_platform_fast_elapsed_msecs(void);
void rt_time_platform_fast_elapsed_secs(void);
void rt_time_platform_get_gmtime(void);
void rt_time_sleep_usecs(void);
void rt_time_start(void);
void rt_timebase_get_localtime(void);
void rt_timebase_reset_globaltime(int arg0);
void rt_token_shutdown(int *arg0);
void rt_udp_add_conn_to_list(void *arg0, void *arg1);
void rt_udp_del_conn_from_list(void *arg0, void *arg1);
void rt_udp_enable_unexpected_port(int arg0);
void rt_udp_set_peer_id(void *arg0, int arg1);
void udp_data_cb(void);
M2C_UNK DmeFree(M2C_UNK *);                         /* extern */
M2C_UNK rt_time_elapsed_msecs();                    /* extern */
M2C_UNK rt_udp_resolve_interface();                 /* extern */
M2C_UNK setNewSeed(M2C_UNK);                        /* extern */
int rt_parse_register();                            /* extern */
M2C_UNK RSAGenerateKeyPair(int, int);               /* extern */
M2C_UNK rt_comm_linkaddress_setnull(int);           /* extern */
int rt_memory_allocate();                           /* extern */
M2C_UNK rt_comm_release_channel_id(void *);         /* extern */
int NetIGetObject();                                /* extern */
M2C_UNK SendGroupedFieldUpdate(int, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK rt_crypt_resolve_interface();               /* extern */
void *NetGetClientInfo(int, int);                   /* extern */
M2C_UNK rt_comm_linkaddress_toext(void *, void *);  /* extern */
M2C_UNK rt_comm_shutdown();                         /* extern */
M2C_UNK rt_memory_free(void *);                     /* extern */
M2C_UNK rt_upnp_destroy(int);                       /* extern */
M2C_UNK rt_timebase_get_globaltime(void *);         /* extern */
M2C_UNK rt_socket_sendmsg_platform();               /* extern */
int rt_socket_get_err_platform();                   /* extern */
int sceNetInetListen();                             /* extern */
M2C_UNK rt_token_destroy_table(int);                /* extern */
int NetIGetLocalTime();                             /* extern */
M2C_UNK rt_mutex_unlock(int, M2C_UNK);              /* extern */
M2C_UNK rt_socket_get_dns_servers_platform();       /* extern */
M2C_UNK rt_time_platform_get_time_stamp();          /* extern */
M2C_UNK rt_parse_timeout_frag_msg();                /* extern */
M2C_UNK rt_socket_find_closed_sockets_platform();   /* extern */
M2C_UNK rt_socket_initialize_stack_platform();      /* extern */
int rt_parse_update_parser();                       /* extern */
M2C_UNK rt_socket_get_available_bytes_to_read_platform(); /* extern */
M2C_UNK rt_time_get_msecs();                        /* extern */
M2C_UNK NetGetStreamChannel();                      /* extern */
M2C_UNK rt_udp_destroy(int);                        /* extern */
M2C_UNK rt_socket_get_local_ip_platform();          /* extern */
M2C_UNK rt_time_platform_get_time_string();         /* extern */
M2C_UNK NetIRegisterMemoryCallbacks();              /* extern */
M2C_UNK rt_time_elapsed_secs();                     /* extern */
int rt_ip_string2ip(int);                           /* extern */
M2C_UNK rt_time_platform_get_date_time();           /* extern */
M2C_UNK rt_socket_set_non_blocking_platform();      /* extern */
M2C_UNK rt_socket_is_connected_platform();          /* extern */
M2C_UNK rt_socket_find_sockets_with_data_platform(); /* extern */
int sceNetInetClose();                              /* extern */
M2C_UNK DMEmalloc(M2C_UNK);                         /* extern */
int rt_parse_reg_parser();                          /* extern */
M2C_UNK rt_socket_set_no_delay_tcp_platform();      /* extern */
extern void *gCommPlatformInterfacePtr;
extern unsigned char NetClientPointerList;
extern int x1;
extern int x2;
extern int y;
extern void *gObjectInterfacePtr;
extern int gpszVersion_11536C;
extern int gpfFreeCallback;
extern int gpfMallocCallback;
extern unsigned char D_00132074;
extern int gAppUpdateCallback;
extern unsigned char gLANMessage;
extern int HEARTBEAT_INTERVAL;
extern int gpHostChangeCallbackData;
extern int gpfHostChangeCallback;
extern unsigned char gszRtUdpVersionString;
extern int gGlobalTimeBase;
extern unsigned char gppConnInfo;
extern void *gDmeGlobals;
extern int gbTimebaseEnabled;
extern int gLastNetTime;
extern unsigned char gLastQueryTimeStamp;
extern unsigned char gQueryRecord;
extern int gpszVersion_114A2C;
extern int gbEnableUnexpectedPort;
extern unsigned char gCommAdhocInterface;
extern unsigned char rt_comm_adhoc_create;
extern unsigned char rt_comm_adhoc_destroy;
extern unsigned char rt_comm_adhoc_get_broadcast_ip;
extern unsigned char rt_comm_adhoc_get_dns_servers;
extern unsigned char rt_comm_adhoc_get_local_ip;
extern unsigned char rt_comm_adhoc_linkaddress_isequal;
extern unsigned char rt_comm_adhoc_linkaddress_isnull;
extern unsigned char rt_comm_adhoc_linkaddress_setnull;
extern unsigned char rt_comm_adhoc_linkaddress_toext;
extern unsigned char rt_comm_adhoc_linkaddress_toint;
extern unsigned char rt_comm_adhoc_linkaddress_tostr;
extern unsigned char rt_comm_adhoc_receive_from;
extern unsigned char rt_comm_adhoc_send_echo;
extern unsigned char rt_comm_adhoc_send_to;
extern unsigned char rt_comm_adhoc_startup;
extern unsigned char rt_comm_adhoc_vsend_to;
extern int RT_UDP_INACTIVITY_TIMEOUT;
extern unsigned char gLatencyMetrics;
extern int gACodecGSMInterfacePtr;
extern int gACodecLPC10InterfacePtr;
extern int gACodecLPCInterfacePtr;
extern int gCryptInterfacePtr;
extern int gMsgClientInterfacePtr;
extern int gP2PInterfacePtr;
extern int gStreamMediaInterfacePtr;
extern int gUDPInterfacePtr;
extern int gVCodecJPEGInterfacePtr;
extern signed char gBuildTimeStamp_10DEB4;
extern int gbInitialized_130B2C;
extern int gMgr;
extern int gpszVersionString;
extern int gpfReallocCallback;
extern int gEchoInfo;
extern unsigned char gNatService;
extern unsigned char gMyAddressInfo;
extern unsigned char gCommPlatformInterface;
extern unsigned char rt_comm_platform_create;
extern unsigned char rt_comm_platform_destroy;
extern unsigned char rt_comm_platform_get_avail_bytes_to_read;
extern unsigned char rt_comm_platform_get_broadcast_ip;
extern unsigned char rt_comm_platform_get_host_by_name;
extern unsigned char rt_comm_platform_get_local_ip;
extern unsigned char rt_comm_platform_get_remote_ip;
extern unsigned char rt_comm_platform_is_connected;
extern unsigned char rt_comm_platform_linkaddress_isequal;
extern unsigned char rt_comm_platform_linkaddress_isnull;
extern unsigned char rt_comm_platform_linkaddress_setnull;
extern unsigned char rt_comm_platform_linkaddress_toext;
extern unsigned char rt_comm_platform_linkaddress_tostr;
extern unsigned char rt_comm_platform_receive;
extern unsigned char rt_comm_platform_receive_echo;
extern unsigned char rt_comm_platform_receive_from;
extern unsigned char rt_comm_platform_send;
extern unsigned char rt_comm_platform_send_echo;
extern unsigned char rt_comm_platform_send_to;
extern unsigned char rt_comm_platform_shutdown;
extern unsigned char rt_comm_platform_startup;
extern unsigned char rt_comm_platform_vsend;
extern unsigned char rt_comm_platform_vsend_to;
extern int gnLocalServerPort;
extern int gpNetLocalServerConnection;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", pool_alloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", pool_free);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetUsePeerToPeer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_resolve_interface);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_current_address_type);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_peer_address);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_my_address);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_my_peer_index);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_host_index);

int rt_p2p_get_virtual_port(void *arg0, unsigned short *arg1) {
    int var_v1;

    var_v1 = 2;
    if (arg1 != NULL) {
        *arg1 = 0;
        if (arg0 != NULL) {
            var_v1 = 0;
            *arg1 = M2C_FIELD(arg0, unsigned short *, 0x1CC);
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_buffer_stats);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_peer_buffer_stats);

int rt_p2p_set_send_aggregation(int *arg0) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        var_v0 = rt_udp_set_aggregation_interval(*arg0);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_host);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_incoming_peer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_connect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_disconnect);

int rt_p2p_tick(int arg0) {
    return (arg0 != 0) ? 0 : 2;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_list);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_receive_broadcasts);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_to);

int rt_p2p_get_max_peers(void *arg0, int *arg1) {
    int var_v1;

    var_v1 = 2;
    if (arg1 != NULL) {
        *arg1 = 0;
        if (arg0 != NULL) {
            var_v1 = 0;
            *arg1 = (int) M2C_FIELD(arg0, unsigned short *, 0x19C);
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_set_max_peers);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_set_overlay_type);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_join_overlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_quit_overlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_quit_all_overlays);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_ignore_peer_in_overlay);

int rt_p2p_get_overlay_peer_count(void *arg0, int arg1, int *arg2) {
    int temp_v1;
    int var_a3;
    unsigned int temp_a1;

    temp_a1 = arg1 & 0xFF;
    var_a3 = 2;
    if (arg2 != NULL) {
        *arg2 = 0;
        if ((arg0 != NULL) && (temp_a1 < (unsigned int) M2C_FIELD(arg0, unsigned int *, 0x1D8))) {
            temp_v1 = M2C_FIELD(arg0, int *, 0x188);
            var_a3 = 3;
            if (temp_v1 != 0) {
                var_a3 = 0;
                *arg2 = M2C_FIELD(((temp_a1 * 0x18) + temp_v1), int *, 0x10);
            }
        }
    }
    return var_a3;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_is_peer_in_overlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_overlay);

int rt_p2p_pack_type(int arg0, int arg1) {
    return (arg1 & 0x7FF) | ((arg0 & 0x1F) << 0xB);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_unpack_type);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid1);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid2);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid3);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid5);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid6);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid7);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid9);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid11);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid12);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid13);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid15);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid16);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid17);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid19);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid21);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid22);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid23);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid25);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid26);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid27);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid28);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid29);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid31);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", grid32);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10C87C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10C8DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10C93C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_event_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_data_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_peer_info);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_handle_connect_event);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_handle_connected_event);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_handle_timeout_event);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_handle_closed_event);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_handle_reset_event);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_handle_error_event);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_peer_by_address);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_peer_by_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_my_peer_status);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_find_free_peer_index);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_fill_new_peer_struct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_internal_message);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_new_peer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_coordinate_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_connect_complete);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_broadcast_update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_connection_detached);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_broadcast_disconnect);

int rt_p2p_process_local_broadcast_test(void *arg0, int arg1) {
    void *temp_a0;

    temp_a0 = ((arg1 & 0xFFFF) * 0x50) + M2C_FIELD(arg0, int *, 0x184);
    if (M2C_FIELD(temp_a0, int *, 0x18) != 1) {
        M2C_FIELD(temp_a0, int *, 0x18) = 1;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_overlay_type);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_join_overlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_join_response);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_quit_overlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_ignore_update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_grid_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_complete_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_local_broadcast_tests);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_isend);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_isend_list);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_my_broadcast_flag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_generic_disconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_determine_new_host);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_connection_detached_to_host);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_broadcast_disconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_notify_peers_disconnect_forwarding);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_notify_peers_disconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_save_backlog_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_find_backlog_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_timeout_backlog_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_generate_grid_fill_empties);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_generate_grid_add_peer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_generate_grid);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_peer_grid_edges);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_update_grid);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_token_msg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_token_list_msg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_token_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_token_event_notify);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_timebase_query);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_timebase_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_game_session_key);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_get_latency_info);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_set_host_invactivity_timeout_session);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_set_host_inactivity_timeout_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_set_peer_update_bit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_new_peer_info);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_send_peer_updates);

void *memset(void *s, int c, unsigned int n);

void rt_p2p_reset_peer_info(void *arg0, void *arg1) {
    if (arg1 != NULL) {
        M2C_FIELD(arg1, int *, 0) = 0;
        M2C_FIELD(arg1, int *, 4) = 0;
        M2C_FIELD(arg1, int *, 8) = 0;
        M2C_FIELD(arg1, int *, 0xC) = 0;
        M2C_FIELD(arg1, int *, 0x10) = 0;
        M2C_FIELD(arg1, int *, 0x14) = 0;
        M2C_FIELD(arg1, int *, 0x18) = 0;
        M2C_FIELD(arg1, int *, 0x1C) = 0;
        M2C_FIELD(arg1, int *, 0x20) = 0;
        M2C_FIELD(arg1, short *, 0x24) = 0;
        rt_comm_linkaddress_setnull(arg1 + 0x28);
        M2C_FIELD(arg1, short *, 0x34) = 0;
        M2C_FIELD(arg1, short *, 0x36) = 0;
        M2C_FIELD(arg1, short *, 0x38) = 0;
        M2C_FIELD(arg1, short *, 0x3A) = 0;
        M2C_FIELD(arg1, short *, 0x3C) = 0;
        M2C_FIELD(arg1, short *, 0x3E) = 0;
        M2C_FIELD(arg1, short *, 0x40) = 0;
        M2C_FIELD(arg1, short *, 0x42) = 0;
        M2C_FIELD(arg1, short *, 0x44) = 0;
        M2C_FIELD(arg1, int *, 0x30) = 0;
        M2C_FIELD(arg1, int *, 0x48) = 0;
        memset(M2C_FIELD(arg1, void **, 0x4C), 0, (((unsigned int) (M2C_FIELD(arg0, unsigned short *, 0x19C) + 0x1F) >> 5) * 4) + 4);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_p2p_process_peer_host_query);

void rt_udp_enable_unexpected_port(int arg0) {
    gbEnableUnexpectedPort = arg0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_get_sequence_id);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_ack_list_flush);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_buffer_ack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_get_first_sub_header);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", GetUDPSecurityMode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", randomNonZero);

int NetUseUDP(void) {
    rt_udp_resolve_interface();
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_resolve_interface);

M2C_UNK *rt_udp_get_version_string(void) {
    return &gszRtUdpVersionString;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_set_buffer_size);

int rt_udp_set_aggregation_interval(arg0, arg1)
    void *arg0;
    int arg1;
{
    int var_v0;

    var_v0 = 0xD2F2;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x70) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_get_buffer_size);

int rt_udp_get_aggregation_interval(void *arg0, int *arg1) {
    int var_v1;

    *arg1 = 0;
    var_v1 = 0xD2F2;
    if (arg0 != NULL) {
        var_v1 = 0;
        *arg1 = M2C_FIELD(arg0, int *, 0x70);
    }
    return var_v1;
}

int rt_udp_get_virtual_port(void *arg0, unsigned short *arg1) {
    int var_v1;

    *arg1 = 0;
    var_v1 = 0xD2F3;
    if (arg0 != NULL) {
        var_v1 = 0;
        *arg1 = M2C_FIELD(arg0, unsigned short *, 0x5C);
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_get_buffer_stats);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_resolve_address);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_get_resolved_address);

int rt_udp_get_local_address(void *arg0, void *arg1, int *arg2) {
    int var_a3;

    var_a3 = 0xD2F2;
    if (arg0 != NULL) {
        var_a3 = 0;
        M2C_FIELD(arg1, int *, 0) = (int) M2C_FIELD(arg0, int *, 0x94);
        M2C_FIELD(arg1, int *, 4) = (int) M2C_FIELD(arg0, int *, 0x98);
        *arg2 = M2C_FIELD(arg0, int *, 0x9C);
    }
    return var_a3;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_get_address);

int rt_udp_disable_nat_service_heartbeat(void *arg0) {
    int var_v0;

    var_v0 = 0xD2F2;
    if (arg0 != NULL) {
        rt_upnp_disable_natservice_heartbeat(M2C_FIELD(arg0, int *, 0x10));
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_connect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_disconnect);

void rt_udp_set_peer_id(void *arg0, int arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x70) = arg1;
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_send_list);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_send_unconnected);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_broadcast);

int rt_udp_listen(void *arg0, int arg1) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x80) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_accept);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_deny);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_pre_accept);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_event_process);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10CAE0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10CB40);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_event_check);

void rt_udp_add_conn_to_list(void *arg0, void *arg1) {
    M2C_FIELD(arg1, void **, 0x8C) = (void *) M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, void **, 0xC) = arg1;
}

void rt_udp_del_conn_from_list(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v0_2;
    void *var_v1;

    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    if (temp_v0 == arg1) {
        M2C_FIELD(arg0, void **, 0xC) = (void *) M2C_FIELD(arg1, void **, 0x8C);
        return;
    }
    var_v1 = temp_v0;
    if (temp_v0 != NULL) {
loop_4:
        temp_v0_2 = M2C_FIELD(var_v1, void **, 0x8C);
        if (arg1 == temp_v0_2) {
            M2C_FIELD(var_v1, void **, 0x8C) = (void *) M2C_FIELD(temp_v0_2, void **, 0x8C);
            return;
        }
        var_v1 = temp_v0_2;
        if (temp_v0_2 == NULL) {

        } else {
            goto loop_4;
        }
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_find_free_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_setup_packet_sub_header);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_buffer_data_for_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_append_data_to_packet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_get_packet_seed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_set_packet_seed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_send_messages);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_remove_non_delivery_critical_packets);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_send_broadcasts);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_receive_messages);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_process_message);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_process_version_exchange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_send_version_exchange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_process_new_connect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_process_disconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_process_reset);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_process_heartbeat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_process_acknowlege);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_process_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_process_unconnected_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_find_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_send_reset);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_send_ack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_is_duplicate_packet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_calculate_rto);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_create_shared_channel_data);

int rt_udp_destroy_shared_channel_data(void *arg0) {
    int temp_v1;

    rt_comm_destroy(M2C_FIELD(arg0, int *, 0));
    rt_memory_free(arg0 + 0x58);
    rt_memory_free(arg0 + 0x5C);
    temp_v1 = M2C_FIELD(arg0, int *, 0x10);
    if (temp_v1 != 0) {
        rt_upnp_destroy(temp_v1);
        M2C_FIELD(arg0, int *, 0x10) = 0;
    }
    rt_comm_shutdown();
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_uber_resolve_cb);

int rt_udp_set_inactivity_timeout(int arg0) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != 0) {
        RT_UDP_INACTIVITY_TIMEOUT = arg0;
        var_v0 = 0;
    }
    return var_v0;
}

int rt_udp_get_inactivity_timeout(int *arg0) {
    *arg0 = RT_UDP_INACTIVITY_TIMEOUT;
    return 0;
}

int rt_udp_set_connection_inactivity_timeout(void *arg0, int arg1) {
    int var_v0;

    var_v0 = 2;
    if (arg1 != 0) {
        M2C_FIELD(arg0, int *, 0x44) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_get_latency_info);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_get_pool_used);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_mgr_create);

void *memset(void *s, int c, unsigned int n);

int rt_udp_mgr_destroy(void) {
    rt_udp_destroy(gMgr);
    memset(&gMgr, 0, 0x108U);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_mgr_get_channel_ref);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_mgr_release_channel_ref);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_udp_mgr_find_channel_ref);

int rt_upnp_get_version_string(void) {
    return gpszVersionString;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_upnp_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_upnp_destroy);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_upnp_resolve_external_address);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_upnp_get_external_address);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_upnp_uber_resolve);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_upnp_update);

int rt_upnp_set_memory_ceiling(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", upnp_iresolve_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", process_heartbeat_timeslice);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", process_nat_resolution_timeslice);

int rt_upnp_xml_create_parser(void) {
    return 4;
}

int rt_upnp_xml_destroy_parser(void) {
    return 4;
}

int rt_upnp_xml_parse(void) {
    return 4;
}

int rt_upnp_xml_is_document_complete(void) {
    return 4;
}

int rt_upnp_xml_get_parser_type(void) {
    return 4;
}

int rt_upnp_xml_get_parse_data(void) {
    return 4;
}

int rt_xmlparse_create(void) {
    return 4;
}

int rt_xmlparse_destroy(void) {
    return 4;
}

int rt_xmlparse_parse_buf(void) {
    return 4;
}

int rt_xmlparse_set_user_data(void) {
    return 4;
}

int rt_xmlparse_set_element_start_cb(void) {
    return 4;
}

int rt_xmlparse_set_element_end_cb(void) {
    return 4;
}

int rt_xmlparse_set_character_data_cb(void) {
    return 4;
}

int rt_xmlparse_is_document_complete(void) {
    return 4;
}

int NetUseCommAdhoc(void) {
    rt_comm_adhoc_resolve_interface();
    return 0;
}

M2C_UNK *rt_comm_adhoc_resolve_interface(void) {
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0) = &rt_comm_adhoc_startup;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 4) = &rt_comm_adhoc_shutdown;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 8) = &rt_comm_adhoc_create;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0xC) = &rt_comm_adhoc_destroy;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x10) = &rt_comm_adhoc_send;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x14) = &rt_comm_adhoc_send_to;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x18) = &rt_comm_adhoc_vsend;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x1C) = &rt_comm_adhoc_vsend_to;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x20) = &rt_comm_adhoc_send_echo;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x24) = &rt_comm_adhoc_receive;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x28) = &rt_comm_adhoc_receive_from;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x2C) = &rt_comm_adhoc_receive_echo;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x34) = &rt_comm_adhoc_get_local_ip;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x38) = &rt_comm_adhoc_get_broadcast_ip;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x3C) = &rt_comm_adhoc_get_host_by_name;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x30) = &rt_comm_adhoc_get_avail_bytes_to_read;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x40) = &rt_comm_adhoc_get_remote_ip;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x44) = &rt_comm_adhoc_display_state;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x48) = &rt_comm_adhoc_is_connected;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x4C) = &rt_comm_adhoc_update;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x50) = &rt_comm_adhoc_linkaddress_setnull;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x54) = &rt_comm_adhoc_linkaddress_isnull;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x58) = &rt_comm_adhoc_linkaddress_isequal;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x5C) = &rt_comm_adhoc_linkaddress_tostr;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x60) = &rt_comm_adhoc_linkaddress_toext;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x64) = &rt_comm_adhoc_linkaddress_toint;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x68) = &rt_comm_adhoc_get_dns_servers;
    gCommPlatformInterfacePtr = &gCommAdhocInterface;
    return &gCommAdhocInterface;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_linkaddress_setnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_linkaddress_isnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_linkaddress_isequal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_linkaddress_tostr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_linkaddress_toext);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_linkaddress_toint);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_startup);

void rt_comm_adhoc_shutdown(void) {
    gbInitialized_130B2C = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_send_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_vsend_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_receive_from);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_get_local_ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_get_broadcast_ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_get_stat);

int rt_comm_adhoc_send(void) {
    return 0xC350;
}

int rt_comm_adhoc_vsend(void) {
    return 4;
}

int rt_comm_adhoc_receive(void) {
    return 4;
}

int rt_comm_adhoc_get_avail_bytes_to_read(void) {
    return 4;
}

int rt_comm_adhoc_get_host_by_name(void) {
    return 4;
}

int rt_comm_adhoc_get_remote_ip(void) {
    return 4;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_send_echo);

int rt_comm_adhoc_receive_echo(void) {
    return 4;
}

int rt_comm_adhoc_is_connected(void) {
    return 4;
}

int rt_comm_adhoc_display_state(void) {
    return 0;
}

int rt_comm_adhoc_update(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_adhoc_get_dns_servers);

int NetUseCommInet(void) {
    rt_comm_platform_resolve_interface();
    return 0;
}

int NetUseCommSockets(void) {
    rt_comm_platform_resolve_interface();
    return 0;
}

M2C_UNK *rt_comm_platform_resolve_interface(void) {
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0) = &rt_comm_platform_startup;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 4) = &rt_comm_platform_shutdown;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 8) = &rt_comm_platform_create;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0xC) = &rt_comm_platform_destroy;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x10) = &rt_comm_platform_send;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x14) = &rt_comm_platform_send_to;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x18) = &rt_comm_platform_vsend;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x1C) = &rt_comm_platform_vsend_to;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x20) = &rt_comm_platform_send_echo;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x24) = &rt_comm_platform_receive;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x28) = &rt_comm_platform_receive_from;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x2C) = &rt_comm_platform_receive_echo;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x34) = &rt_comm_platform_get_local_ip;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x38) = &rt_comm_platform_get_broadcast_ip;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x3C) = &rt_comm_platform_get_host_by_name;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x30) = &rt_comm_platform_get_avail_bytes_to_read;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x40) = &rt_comm_platform_get_remote_ip;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x44) = &rt_comm_platform_display_state;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x48) = &rt_comm_platform_is_connected;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x4C) = &rt_comm_platform_update;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x50) = &rt_comm_platform_linkaddress_setnull;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x54) = &rt_comm_platform_linkaddress_isnull;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x58) = &rt_comm_platform_linkaddress_isequal;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x5C) = &rt_comm_platform_linkaddress_tostr;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x60) = &rt_comm_platform_linkaddress_toext;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x64) = &rt_comm_platform_linkaddress_toint;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x68) = &rt_comm_platform_get_dns_servers;
    gCommPlatformInterfacePtr = &gCommPlatformInterface;
    return &gCommPlatformInterface;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_get_listen_socket);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_linkaddress_setnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_linkaddress_isnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_linkaddress_isequal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_linkaddress_tostr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_linkaddress_toext);

int rt_comm_platform_linkaddress_toint(int *arg0, int arg1) {
    *arg0 = rt_ip_string2ip(arg1);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_startup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_shutdown);

int rt_comm_platform_update(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_send_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_vsend);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_vsend_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_send_echo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_receive);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_receive_from);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_receive_echo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_get_avail_bytes_to_read);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_get_local_ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_get_broadcast_ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_get_host_by_name);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_get_remote_ip);

int rt_comm_platform_display_state(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_platform_is_connected);

void rt_comm_platform_get_dns_servers(void) {
    rt_socket_get_dns_servers();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_get_version);

int rt_socket_get_version_string(void) {
    return gpszVersion_114A2C;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10CC14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010CC74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10CC90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10CCEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10CD4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10CDB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10CE18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10CE7C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10CEE4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10CF5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10CFCC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10D030);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", RT_SOCKET_MINOR_VERSION);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D098);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D0B8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_get_build_timestamp);

void rt_socket_initialize_stack(void) {
    rt_socket_initialize_stack_platform();
}

void rt_socket_cleanup_stack(void) {
    rt_socket_cleanup_stack_platform();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_shutdown);

void rt_socket_close(void) {
    rt_socket_close_platform();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_get_type);

void rt_socket_set_non_blocking(void) {
    rt_socket_set_non_blocking_platform();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_set_broadcast);

void rt_socket_get_available_bytes_to_read(void) {
    rt_socket_get_available_bytes_to_read_platform();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_set_reuse_address);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_set_send_buffer_size);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_set_receive_buffer_size);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_get_receive_buffer_size);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_get_send_buffer_size);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_bind);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_bind_with_ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_bind_dynamic);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_connect_to_service);

void rt_socket_find_sockets_with_data(void) {
    rt_socket_find_sockets_with_data_platform();
}

void rt_socket_find_closed_sockets(void) {
    rt_socket_find_closed_sockets_platform();
}

void rt_socket_get_local_ip(void) {
    rt_socket_get_local_ip_platform();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_create_tcp);

void rt_socket_set_no_delay_tcp(void) {
    rt_socket_set_no_delay_tcp_platform();
}

int rt_socket_listen_tcp(void) {
    int var_v1;

    var_v1 = 0;
    if (sceNetInetListen() != 0) {
        var_v1 = rt_socket_get_err_platform();
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_accept_connection_tcp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_read_data_tcp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_send_data_tcp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_peek_data_tcp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_create_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_accept_connection_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_read_data_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_send_data_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_read_data_connected_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_send_data_connected_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", in_cksum);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_create_icmp_echo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_send_icmp_echo_request);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_recv_icmp_echo_response);

void rt_socket_is_connected(void) {
    rt_socket_is_connected_platform();
}

void rt_socket_get_dns_servers(void) {
    rt_socket_get_dns_servers_platform();
}

void rt_socket_sendmsg(void) {
    rt_socket_sendmsg_platform();
}

void rt_socket_recvmsg(void) {
    rt_socket_recvmsg_platform();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10D120);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_get_err_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_initialize_stack_platform);

int rt_socket_cleanup_stack_platform(void) {
    return 0;
}

int rt_socket_close_platform(void) {
    int var_v1;

    var_v1 = 0;
    if (sceNetInetClose() != 0) {
        var_v1 = rt_socket_get_err_platform();
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_set_no_delay_tcp_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_set_non_blocking_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_get_available_bytes_to_read_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_check_readability_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_find_sockets_with_data_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_find_closed_sockets_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_get_host_by_name);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_get_local_ip_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_is_interface_up);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_is_connected_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_get_dns_servers_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_socket_sendmsg_platform);

int rt_socket_recvmsg_platform(void) {
    return 4;
}

int KM_SetUpdateCallback(int arg0) {
    int temp_v0;

    temp_v0 = gAppUpdateCallback;
    gAppUpdateCallback = arg0;
    return temp_v0;
}

void *memset(void *s, int c, unsigned int n);
void lintSetSmallValue(int *arg0, int arg1) {
    memset(arg0, 0, 0x200U);
    *arg0 = arg1;
}

int IsEven(int *arg0) {
    return (*arg0 ^ 1) & 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", IsZero);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", IsOne);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", IsEqual);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintGetBit);

void lintSetBit(int arg0, unsigned int arg1) {
    int *temp_a2;
    unsigned int temp_v1;

    temp_v1 = arg1 >> 5;
    temp_a2 = (temp_v1 * 4) + arg0;
    *temp_a2 |= 1 << (arg1 - (temp_v1 << 5));
}

void lintClearBit(int arg0, unsigned int arg1) {
    int *temp_a2;
    unsigned int temp_v0;

    temp_v0 = arg1 >> 5;
    temp_a2 = (temp_v0 * 4) + arg0;
    *temp_a2 &= ~(1 << (arg1 - (temp_v0 << 5)));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintIncrement);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintDecrement);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintAdd);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintSub);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MOD);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", QUO);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", QRMOD);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", GCD);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", EMOD);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintIsbSPRP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintRandomize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintTryDiv);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", PRIME_START);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D37C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintPrime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", EMODM);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintGenerateKeyPair);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintGetBits);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ShiftRight);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ShiftLeft);

void lintAddIP(int arg0, int arg1) {
    int temp_v0;
    int var_a4;
    unsigned int *temp_a2;
    unsigned int *temp_v0_2;
    unsigned int temp_v1;
    unsigned int var_a3;

    var_a4 = 0;
    var_a3 = 0;
    do {
        temp_v0 = var_a3 * 4;
        temp_a2 = temp_v0 + arg1;
        temp_v0_2 = temp_v0 + arg0;
        temp_v1 = *temp_v0_2 + (*temp_a2 + var_a4);
        *temp_v0_2 = temp_v1;
        if (var_a4 != 0) {
            var_a4 = (unsigned int) *temp_a2 >= temp_v1;
        } else {
            var_a4 = temp_v1 < (unsigned int) *temp_a2;
        }
        var_a3 += 1;
    } while (var_a3 < 0x80U);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", lintSubIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MODIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", IsGreater);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", IsSmaller);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", IsNotGreater);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", IsNotSmaller);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MULT);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", XMOD);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MODW);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MontPro);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RC4Init);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RC4Code);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RCInitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RCSaltyInitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RCEncrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RCDecrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RSAEncryptBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RSADecryptBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RSAEncrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RSADecrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RSA2048Encrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RSA2048Decrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RSA2048GenerateKeyPair);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SHAInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SHAUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SHAFinal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", endianTest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SHSTransform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", longReverse);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SHAtoByte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_MD2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md2Init);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md2Update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md2Final);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md2Transform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_MD4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md4Init);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md4Update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md4Final);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md4Transform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", Encode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", Decode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_MD5);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_Salted_MD5);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md5Init);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md5Update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md5Final);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md5Transform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", md5Encode);

int NetUseCrypt(void) {
    rt_crypt_resolve_interface();
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_crypt_resolve_interface);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", IsNullRCKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NewKeyChain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", DeleteKeyChain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", AppendKeyChain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", GetKeyChain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RemoveKeyChain);

void KM_GenerateRSAKeyPair(int arg0, int arg1) {
    InitializePRNG();
    RSAGenerateKeyPair(arg0, arg1);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RSAGenerateKeyPair);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D428);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10D42C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rc4_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10D4E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10D538);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10D590);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rsa2048_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10D64C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", sha1_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D700);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10D704);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", md2_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", gS);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D8B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D8BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D8C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D8C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D8C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D8D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D8D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D8E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D8E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D8F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D900);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D90C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D918);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D928);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D938);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D948);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010D958);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10D96C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", md4_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10DA20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_crypt_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10DAE8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_GetVersionStringPtr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_SHA1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_Salted_SHA1);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_Create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_SetLocalClientID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_SetPublicKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_GetPublicKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_SetLocalKeyPair);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_SetGameSessionKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_GetGameSessionKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_AddSymmetricKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_GetSymmetricKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_CompareSymmetricKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_DeleteSymmetricKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_CopyKeys);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_DigiSign);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_DigiVerify);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_DeleteKeys);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_Destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_Cleanup);

void InitializePRNG(void) {
    if (D_00132074 != 0) {

    } else {
        D_00132074 = 1;
        setNewSeed(0x035D2325);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_CreateRandomRCKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_Encrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_Encrypt2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_Decrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_Decrypt2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_RSAAdjust);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", GetSoftwareKeyPair);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetInitializeClients);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetClientStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetCreateClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetFreeClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetFreeClients);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetFreeAllClients);

void NetFreeClientPointers(void) {
    DmeFree(&NetClientPointerList);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetISendMyClientUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetRegisterObjectStart);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultNetUseObjectsInParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetUseObjects);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetObjectField);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultRegisterObjectFilterParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetRegisterObjectFilter);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetCreateObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetRequestCreateRemoteNamedObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetMyClientObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetFreeObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetFreeAllObjects);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetRequestObjectPrivateOwnership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetReleaseObjectPrivateOwnership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetRegisterStructure);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetRegisterRemoteObjectCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSendObjectFullUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetSessionMasterClientIndex);

int NetGetMaxStructures(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gObjectInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gObjectInterfacePtr, int *, 0xF8);
        }
    }
    return var_v1;
}

int NetGetMaxFieldsPerStructure(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gObjectInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gObjectInterfacePtr, int *, 0xFC);
        }
    }
    return var_v1;
}

int NetGetMaxObjects(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gObjectInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gObjectInterfacePtr, int *, 0x100);
        }
    }
    return var_v1;
}

int NetGetMaxDataStreamTypes(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gObjectInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gObjectInterfacePtr, int *, 0x108);
        }
    }
    return var_v1;
}

int NetGetMaxDataStreams(int *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v1 = 0x10;
        if (gObjectInterfacePtr != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(gObjectInterfacePtr, int *, 0x10C);
        }
    }
    return var_v1;
}

int InitObjectUpdateList(void) {
    M2C_FIELD(gObjectInterfacePtr, int *, 0x12C) = 0;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", AddToObjectUpdateList);

int RemoveFromObjectUpdateList(void) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_v1;

    temp_v0 = NetIGetObject();
    if (temp_v0 != NULL) {
        temp_v0_2 = M2C_FIELD(gObjectInterfacePtr, void **, 0x12C);
        if (temp_v0 == temp_v0_2) {
            M2C_FIELD(gObjectInterfacePtr, void **, 0x12C) = (void *) M2C_FIELD(temp_v0, void **, 0x4C);
        } else {
            var_v1 = temp_v0_2;
            if (temp_v0_2 != NULL) {
loop_5:
                temp_v0_3 = M2C_FIELD(var_v1, void **, 0x4C);
                if (temp_v0 == temp_v0_3) {
                    M2C_FIELD(var_v1, void **, 0x4C) = (void *) M2C_FIELD(temp_v0, void **, 0x4C);
                } else {
                    var_v1 = temp_v0_3;
                    if (temp_v0_3 != NULL) {
                        goto loop_5;
                    }
                }
            }
        }
        M2C_FIELD(temp_v0, void **, 0x4C) = NULL;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetMyPersistantObjectCount);

void NetIGetDataStream(void) {
    NetGetStreamChannel();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetStreamChannel);

int NetIGetSessionMasterClientIndex(int *arg0, void *arg1) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0x100;
        if (arg1 != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(arg1, int *, 0x408);
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RemoteObjectCreation);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RemoteObjectUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RemoteObjectDelete);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetFreeRemoteObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetFreeLocalObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIFreeObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", LocalObjectName2Index);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", FindFreeLocalObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIFreeAllObjects);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIJoin);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetJoin2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIRequestCreateRemoteNamedObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetICreateObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIOpenDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIEndDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIRequestObjectPrivateOwnership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIReleaseObjectPrivateOwnership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", CheckFieldsForUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SendGroupedFieldUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetISendObjectFullUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIAddToDataStream);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10DB6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10DBCC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10DC2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", gszrtObjectVersionString);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ElementErrorExceedsThreshold);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", GlobalFieldErrorExceedsThreshold);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetDataStreamPacket);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SendCloseDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIDataStreamBytesFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SendClientDataStreams);

void NetISendFieldUpdates(void) {
    SendGroupedFieldUpdate(NetIGetObject(), 0, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SendClientNetObjectUpdates);

int NetSetSessionMasterClientIndex(void *arg0, int arg1) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x408) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetCompleteJoin);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetFreeAllDataStreams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetILeave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MyClientJoins);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetClientJoins);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ReserveNetObjectsAndDataStreamsForClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", DmeObjectResolveInterface);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetISetMyClientObject);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetClientLeaves);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetFindNextSessionMaster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", CreateGlobalObjectInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", DestroyGlobalObjectInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", DeleteNetObjectPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ElectSessionMaster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetObjectFullUpdatePacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", FieldUpdatePacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", FindFreeDataStreamBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RequestOwnershipPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", GrantOwnershipPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ReleaseOwnershipPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", DataStreamUpdatePacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", DataStreamEndPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ArbitrateJoinPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SMMigrateOrderPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", GetFreeNetObjectBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", AcceptClientIntoGame);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", AcceptClientPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ClientLeavesPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ClientUpdatePacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIRegisterObjectStart);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIObjectField);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RegisterChildStructure);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIRegisterStructure);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIRegisterObjectFilter);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIRegisterRemoteObjectCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIRegisterDataStream);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010DCF0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010DCF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010DCF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010DCFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10DD00);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10DD6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10DDD4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10DE3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", gszDmeVersionString);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", gBuildTimeStamp_10DEB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", gszrtBaseVersionString);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetClientVersion);

char *strcpy(char *d, const char *s);

int NetGetBuildTimeStamp(signed char *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        strcpy(arg0, &gBuildTimeStamp_10DEB4);
        var_v1 = 0;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultInitializeParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetInitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetAverageDelayToClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetBufferStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetSendAggregationInterval);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetBandwidthInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetRegisterMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetRegisterApplicationMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSendMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSendApplicationMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetRegisterDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultMemoryCallbackParams);

void NetRegisterMemoryCallbacks(void) {
    NetIRegisterMemoryCallbacks();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetAssignLocalServer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetConnect);

void *memset(void *s, int c, unsigned int n);
int NetSetDefaultJoinParams(void *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        memset(arg0, 0, 0x48U);
        M2C_FIELD(arg0, int *, 0x1C) = 2;
        M2C_FIELD(arg0, int *, 0) = 1;
        var_v1 = 0;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetHostPeerToPeer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetNATServiceAddr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultResolveAddrParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetResolveAddr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIncomingClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetMyClientReceiveBroadcast);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetPing);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetPingIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetPingNetAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetOpenDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetAddToDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetEndDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSendMyClientUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetDataStream);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetClientStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetMyIpAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetMyNetAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetClientIpAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetMyClientIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetPeerToPeerHostClientIndex);

int NetGetLocalTime(int *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        *arg0 = NetIGetLocalTime();
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetTime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetConnectStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetValidClientCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultStreamMediaParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetConnectionStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetDataStreamBytesFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetServerVersion);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetNetUpdateErrors);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetTick);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetLeave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultDisconnectParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetDisconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetStreamMediaJoinChannel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetStreamMediaQuitChannel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetStreamMediaGetChannelInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetStreamMediaGetClientInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetStreamMediaEndRecording);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetStreamMediaGetCurrentChannelState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetStreamMediaSetDefaultIgnoreParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetStreamMediaSetIgnoreState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetJoin);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetFieldChanged);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSendFieldUpdates);

void *memset(void *s, int c, unsigned int n);
int NetSetDefaultLookupParams(void *arg0) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        memset(arg0, 0, 0x114U);
        var_v1 = 0;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetHostByName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetClientBufferStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultAppMessageParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSendAppMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetLANSetUserName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetAddressToStringAddress);

int NetSetDefaultNetUsePeerToPeerInParams(void *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0) = 0;
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0x10000;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetUdpBindPort);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetUPnPMemoryCeiling);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetLANBroadcastCommSetting);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetGlobalBufferPoolStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetConnectivityType);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetLocalizationSettings);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", BinaryAddressToNetAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", StringAddressToNetAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetAddressToBinaryAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIAddressToStringAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetLANFindEnableExchange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetLANFind);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultLANFindParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetLANFindCancel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetILANFind);

void LANFindSetLocalServer(int arg0, int arg1) {
    gpNetLocalServerConnection = arg0;
    gnLocalServerPort = arg1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", LANFindGetMyPeerDesc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", LANFindPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", LANFindResultsPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SendLANFindResultsOnExchange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SendLANFindReply);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", InitLANFindRequest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", InitLANFindReply);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", OnReceivedLANFindRequest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", OnReceivedLANFindReply);

void ClearInterfacePointers(void) {
    gMsgClientInterfacePtr = 0;
    gStreamMediaInterfacePtr = 0;
    gCommPlatformInterfacePtr = 0;
    gObjectInterfacePtr = 0;
    gP2PInterfacePtr = 0;
    gUDPInterfacePtr = 0;
    gCryptInterfacePtr = 0;
    gACodecGSMInterfacePtr = 0;
    gACodecLPCInterfacePtr = 0;
    gACodecLPC10InterfacePtr = 0;
    gVCodecJPEGInterfacePtr = 0;
}

int NetSetDefaultBitMask(void *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0) = 0;
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        M2C_FIELD(arg0, int *, 0x14) = 0;
        M2C_FIELD(arg0, int *, 0x18) = 0;
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        M2C_FIELD(arg0, int *, 0x20) = 0;
        M2C_FIELD(arg0, int *, 0x24) = 0x100;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetBitMaskIsSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetBitMaskSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetBitMaskUnSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGenerateClientList);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGenerateJoinedClientList);

void NetSetHeartbeatInterval(int arg0) {
    HEARTBEAT_INTERVAL = arg0;
}

void NetGetMyAddressInfoInternal(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0);
    M2C_FIELD(arg0, int *, 4) = (int) M2C_FIELD(&gMyAddressInfo, int *, 4);
    M2C_FIELD(arg0, int *, 8) = (int) M2C_FIELD(&gMyAddressInfo, int *, 8);
    M2C_FIELD(arg0, int *, 0xC) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0xC);
    M2C_FIELD(arg0, int *, 0x10) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0x10);
    M2C_FIELD(arg0, int *, 0x14) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0x14);
    M2C_FIELD(arg0, int *, 0x18) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0x18);
    M2C_FIELD(arg0, int *, 0x1C) = (int) M2C_FIELD(&gMyAddressInfo, int *, 0x1C);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetMyAddressInfo);

int NetGetP2PHandle(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x474);
}

int NetUseDme(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", GetSoftwareID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetMyIntIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetMyExtIP);

int NetGetMsgClientIndex(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x470);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SendMyClientStatus);

int RtMsgToDmeConnectionIndex(unsigned int arg0) {
    return arg0 + (arg0 < 5U);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetAverageDelayToClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetBufferStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetISetSendAggregationInterval);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetBandwidthInfo);

int NetIGetMyClientIndex(int *arg0, void *arg1) {
    int var_v1;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        *arg0 = 0x100;
        if (arg1 != NULL) {
            var_v1 = 0;
            *arg0 = M2C_FIELD(arg1, int *, 0x404);
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetPeerToPeerHostClientIndex);

int NetSetPeerToPeerHostChangeCallback(int arg0, int arg1) {
    gpfHostChangeCallback = arg0;
    gpHostChangeCallbackData = arg1;
    return 0;
}

void NetResetTime(int arg0) {
    M2C_FIELD(gDmeGlobals, int *, 0x10) = arg0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10DF90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10DFF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010E058);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E068);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10E0D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E144);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E1A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10E208);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", DMEmalloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", DmeFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIRegisterMemoryCallbacks);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetMyIpAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetMyNetAddress);

void *memset(void *s, int c, unsigned int n);

int NetIGetClientIpAddress(void *arg0, int arg1, int arg2) {
    int var_v1;
    void *temp_v0;

    var_v1 = 0x17;
    if (arg0 != NULL) {
        memset(arg0, 0, 0x10U);
        temp_v0 = NetGetClientInfo(arg1, arg2);
        var_v1 = 8;
        if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, int *, 0x20) != 0)) {
            rt_comm_linkaddress_toext(arg0, temp_v0);
            var_v1 = 0;
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RemoteClientConnects);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RemoteClientDisconnects);

int NetIGetCurrentUDPSourceBinaryIP(void *arg0) {
    int var_a2;

    var_a2 = 0x17;
    if (arg0 != NULL) {
        var_a2 = 0;
        M2C_FIELD(arg0, int *, 0) = (int) M2C_FIELD(gDmeGlobals, int *, 0x18);
        M2C_FIELD(arg0, int *, 4) = (int) M2C_FIELD(gDmeGlobals, int *, 0x1C);
    }
    return var_a2;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetLocalTime);

int NetIGetTime(void *arg0) {
    int var_v1;

    var_v1 = 0x2F;
    if (M2C_FIELD(arg0, int *, 0x4A4) != 0) {
        if (gbTimebaseEnabled == 0) {

        } else {
            rt_timebase_get_globaltime(gDmeGlobals + 0x10);
        }
        var_v1 = M2C_FIELD(gDmeGlobals, int *, 0x10);
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetConnectStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetValidClientCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetConnectionStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetServerVersion);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetISendTo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetBitMaskToSendMask);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSendMessageByUDP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSendMessageByTCP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetFragSendCB);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetISendMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ParseMessageList);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RemoteClientDisconnectEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RemoteClientEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIInitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIAssignLocalServer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIEnableUDP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetCreateP2PInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", IncomingMessageFunc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MapMsgClientFailureReason);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MyClientConnectsPeerToPeer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MsgClientConnectCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MsgClientDisconnectCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultConnectParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIConnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetConnect_ClientServerTCP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetConnect_PeerToPeerUDP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetDefaultHostPeerToPeerParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIHostPeerToPeer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetISetNATServiceAddr);

int NetISetDefaultResolveAddrParams(void *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        M2C_FIELD(arg0, int *, 0x14) = 0;
        M2C_FIELD(arg0, int *, 0x18) = 0;
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        M2C_FIELD(arg0, int *, 0) = 1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIResolveAddr);

void *memset(void *s, int c, unsigned int n);
int NetSetDefaultIncomingClientParams(int *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        memset(arg0, 0, 0x74U);
        *arg0 = 1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIIncomingClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetIncomingClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetISetMyClientReceiveBroadcast);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", FindFreePingSlot);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIPing);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIPingIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetUpdateAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetITick);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetNetUpdateErrors);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIDisconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetMapRtError);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetClientPingInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetCleanupClientPingInfoArray);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetConnInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetCleanupConnInfo);

void NetCreateConnInfoBare(void) {
    DMEmalloc(0x4AC);
}

int NetSetConnInfo(int arg0, int arg1) {
    int *temp_a0;
    int var_v0;

    temp_a0 = (arg0 * 4) + &gppConnInfo;
    var_v0 = 0x17;
    if (*temp_a0 == 0) {
        *temp_a0 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetCreateConnInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetDestroyConnInfoBare);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetDestroyConnInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetClientInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetCreateClientInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetDestroyClientInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetServerIpAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetSetServerIpAddress);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetCheckForPingTimeouts);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIsPeerToPeerHost);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", EchoRequestCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetProcessEchoRequests);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetDisablePingIPs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetClientConnectStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetProcessP2PDisconnect);

int NetClientIndexToClientIndexPacket(int arg0) {
    return arg0 & 0xFF;
}

int NetGetNatService(M2C_UNK **arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        *arg0 = &gNatService;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetConvertTransportFlags);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", p2p_connect_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", p2p_disconnect_cb);

void p2p_system_change_cb(int arg0, int arg1, void *arg2) {
    if ((arg2 == NULL) || (M2C_FIELD(arg2, int *, 0x468) != 2)) {
        return;
    }
    if (arg1 != 0) {
        M2C_FIELD(arg2, int *, 0x450) = (int) (M2C_FIELD(arg2, int *, 0x450) | arg0);
        return;
    }
    M2C_FIELD(arg2, int *, 0x450) = (int) (M2C_FIELD(arg2, int *, 0x450) & ~arg0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", p2p_host_change_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", udp_resolve_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", p2p_peer_update_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", p2p_incoming_data_cb);

int NetGetMyWorldID(void) {
    int var_v0;
    void *temp_v1;

    var_v0 = -1;
    if (gObjectInterfacePtr != NULL) {
        temp_v1 = M2C_FIELD(gObjectInterfacePtr, void **, 0x138);
        if (temp_v1 != NULL) {
            var_v0 = M2C_FIELD(temp_v1, int *, 0x458);
        }
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", udp_unconnected_data_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", udp_event_cb);

void udp_data_cb(void) {
    if (gUDPInterfacePtr != NULL) {
        M2C_FIELD(gUDPInterfacePtr, M2C_UNK (**)(), 0x3C)();
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", p2p_broadcast_update_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MsgClientSystemMessageCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetMutexLock);

void NetMutexUnlock(void) {
    rt_mutex_unlock(gDmeGlobals + 0x28, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetISetFieldChanged);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetHostByName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIGetClientBufferStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetDNSLookupCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ClientConnectsPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ServerVersionPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RequestServersPacketHandler);

int ServerResponsePacketHandler(void) {
    return 0xC;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", PingPacketHandler);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E338);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10E3A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", UpdateClientStatusPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", RegisterDMEmessages);

int NetSetDefaultLatencyMetricsParams(void *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0) = 0;
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        M2C_FIELD(arg0, int *, 0x14) = 0;
        M2C_FIELD(arg0, int *, 0x18) = 0;
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        M2C_FIELD(arg0, int *, 0x20) = 0;
        M2C_FIELD(arg0, int *, 0x24) = 0;
        M2C_FIELD(arg0, int *, 0x28) = 0;
        M2C_FIELD(arg0, int *, 0x2C) = 0;
        M2C_FIELD(arg0, int *, 0x30) = 0;
        M2C_FIELD(arg0, int *, 0x34) = 0;
        NetSetDefaultBitMask(arg0 + 8);
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetGetLatencyMetrics);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", MetricsEvent);

void NetSetLatencyMetricsCallback(int arg0, int arg1) {
    M2C_FIELD(&gLatencyMetrics, int *, 0) = arg0;
    M2C_FIELD(&gLatencyMetrics, int *, 4) = arg1;
}

int NetIRegisterMessage(void) {
    return (rt_parse_register() == 0) ? 0 : 0x1E;
}

int NetIRegParseMessage(void) {
    return (rt_parse_reg_parser() == 0) ? 0 : 0x1E;
}

int NetIUpdateParseMessage(void) {
    return (rt_parse_update_parser() == 0) ? 0 : 0x1E;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetIRegisterApplicationMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SendTokenMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", SendTokenListMessage);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E420);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10E480);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E4E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E544);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10E5A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", HostProcessTokenMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", TokenEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", TokenHostEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", TokenNotifyEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetTokenQuery);

int NetTokenSystemQuery(void *arg0, int *arg1) {
    int var_v1;

    var_v1 = 0x17;
    if (((arg0 == NULL) | (arg1 == NULL)) == 0) {
        var_v1 = 0x31;
        if (M2C_FIELD(arg0, int *, 0x4A0) != 0) {
            var_v1 = 0;
            *arg1 = M2C_FIELD(arg0, int *, 0x450) & 1;
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetTokenRequest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetTokenRelease);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetTokenListRequest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetTokenListRelease);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetTokenCountGet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetTokenTableSizeGet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetTokenTableGet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetTokenTablePrint);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_clear);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_free);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_use);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_store);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_copy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_normalize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_normalize_with_buf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_get_used);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_get_used_nowrap);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_get_avail);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_get_avail_nowrap);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_get_start_used_ptr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_get_start_avail_ptr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_circ_buf_is_wrapped);

int rt_comm_get_version_string_ptr(void) {
    return gpszVersion_11536C;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E674);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10E6D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E72C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10E788);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header2_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010E854);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_get_build_timestamp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_startup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_shutdown);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_set_default_options);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_create);

void rt_comm_destroy(void *arg0) {
    if (rt_comm_is_valid_channel() == 0) {

    } else {
        M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(int), 0xC)(M2C_FIELD(arg0, int *, 8));
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 0) = 0;
        rt_comm_release_channel_id(arg0);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_send_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_vsend);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_vsend_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_send_echo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_receive);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_receive_from);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_receive_echo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_get_avail_bytes_to_read);

void rt_comm_get_local_ip(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x34)();
}

void rt_comm_get_broadcast_ip(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x38)();
}

void rt_comm_get_host_by_name(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x3C)();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_get_remote_ip);

void rt_comm_display_state(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x44)();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_get_metrics);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_get_interface_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_get_local_port);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_is_connected);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_get_host_by_name_nb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_generate_lookup_query);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_resend_lookup_query);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_check_for_query_response);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_process_response_header);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_skip_query_section);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_process_rr);

int rt_isdigit(int arg0) {
    return (unsigned int) (arg0 - 0x30) < 0xAU;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_get_new_channel_id);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_release_channel_id);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_metric_init);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_metric_add_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_metric_update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_metric_update_single);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_linkaddress_setnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_linkaddress_isnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_linkaddress_isequal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_linkaddress_tostr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_linkaddress_toext);

void rt_comm_linkaddress_toint(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x64)();
}

int rt_comm_echo_is_enabled(void) {
    return gEchoInfo;
}

void rt_comm_echo_set_default_options(int *arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_echo_enable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_echo_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_echo_update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_comm_echo_shutdown);

void rt_comm_get_dns_servers(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x68)();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_constraint_check_RT_1BYTE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_constraint_check_RT_U1BYTE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_constraint_check_RT_2BYTE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_constraint_check_RT_U2BYTE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_constraint_check_RT_4BYTE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_constraint_check_RT_U4BYTE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_constraint_check_RT_8BYTE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_constraint_check_RT_U8BYTE);

int rt_constraint_check_RT_4BYTE_FP(float *arg0, void *arg1) {
    float temp_f1;
    int var_v0;

    temp_f1 = *arg0;
    var_v0 = 0;
    if (!(temp_f1 < M2C_FIELD(arg1, float *, 0)) && !(M2C_FIELD(arg1, float *, 4) < temp_f1)) {
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_constraint_check_RT_8BYTE_FP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_constraint_check_RT_CSTRING);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_Initialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", IsNullRSAKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", KM_GetLocalPublicKey);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", GetKeyMaster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_ip_string2ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_ip_ip2string);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetLANSetDefaultSendTextMessageInParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetLANSendTextMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetLANSetDefaultSendRawMessageInParams);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetLANSendRawMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", NetEnableLANMessaging);

int NetDisableLanMessaging(void) {
    M2C_FIELD(&gLANMessage, int *, 0) = 0;
    M2C_FIELD(&gLANMessage, int *, 8) = 0;
    return 0;
}

void *memset(void *s, int c, unsigned int n);
int NetLANSetDefaultEnableMessagingInParams(void *arg0) {
    int var_v1;

    var_v1 = 0xA;
    if (arg0 != NULL) {
        memset(arg0, 1, 0x10U);
        var_v1 = 0;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", LANTextMessageHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", LANRawMessageHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_memory_allocate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_memory_reallocate);

void *memset(void *s, int c, unsigned int n);

int rt_memory_allocate_init_zero(void **arg0, unsigned int arg1) {
    int temp_v0;
    int var_v1;
    void *temp_v0_2;

    var_v1 = 0x64;
    if (arg0 != NULL) {
        *arg0 = NULL;
        temp_v0 = rt_memory_allocate();
        var_v1 = temp_v0;
        if (temp_v0 == 0) {
            temp_v0_2 = *arg0;
            var_v1 = 0x64;
            if (temp_v0_2 != NULL) {
                memset(temp_v0_2, 0, arg1);
                var_v1 = 0;
            }
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_memory_free);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_memory_align_alloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_memory_align_alloc_init_zero);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_memory_align_free);

int rt_memory_register_callbacks(int arg0, int arg1) {
    gpfMallocCallback = arg0;
    gpfFreeCallback = arg1;
    return 0;
}

int rt_memory_register_another_callback(int arg0) {
    gpfReallocCallback = arg0;
    return 0;
}

int rt_memory_get_aligned_address(unsigned int *arg0, unsigned int arg1, int arg2) {
    int var_a3;
    unsigned int temp_hi;
    unsigned int temp_v1;

    temp_v1 = arg2 & 0xFFFF;
    var_a3 = 0x64;
    if (((arg0 == NULL) | (arg1 == 0)) == 0) {
        *arg0 = arg1;
        var_a3 = 0;
        if (temp_v1 >= 2U) {
            temp_hi = arg1 % temp_v1;
            if (temp_hi != 0) {
                *arg0 = arg1 + (temp_v1 - temp_hi);
            }
        }
    }
    return var_a3;
}

int rt_msg_set_byte(signed char *arg0, signed char arg1) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        *arg0 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_get_byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_set_ubyte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_get_ubyte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_set_2byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_get_2byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_set_u2byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_get_u2byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_set_4byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_get_4byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_set_u4byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_get_u4byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_set_2byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_get_2byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_set_u2byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_get_u2byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_set_4byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_get_4byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_set_u4byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_msg_get_u4byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", seedMT);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", seedMTUsingArray);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", reloadMT);

void randReSync(void) {
    x1 = 0x98765431;
    x2 = 0x12345679;
    y = 0x13579BDF;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", randomMT);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", randomMTSetCharArray);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", setNewSeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", ScrambleSeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", setNewSeed_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_lock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_lock_no_block);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_unlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_begin_critical_section);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_end_critical_section);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E888);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E8EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_ip_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10E994);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10E9F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10EA4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10EAA8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10EB04);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10EB60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", D_0010EBBC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10EBFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10EC54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10ECAC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10ED10);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_platform_create);

int sceKernelDeleteSema(int semid);
int rt_mutex_platform_destroy(void *arg0) {
    int var_v1;

    var_v1 = 2;
    if (arg0 != NULL) {
        var_v1 = (sceKernelDeleteSema(M2C_FIELD(arg0, int *, 0xC)) == 0) ? 0 : 0x384;
    }
    return var_v1;
}

int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int rt_mutex_platform_lock(void *arg0) {
    int var_v1;

    var_v1 = 2;
    if (arg0 != NULL) {
        var_v1 = (sceKernelWaitSema(M2C_FIELD(arg0, int *, 0xC), 1, NULL) == 0) ? 0 : 0x384;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_platform_lock_no_block);

int sceKernelSignalSema(int semid, int signal);
int rt_mutex_platform_unlock(void *arg0) {
    int var_v1;

    var_v1 = 2;
    if (arg0 != NULL) {
        var_v1 = (sceKernelSignalSema(M2C_FIELD(arg0, int *, 0xC), 1) == 0) ? 0 : 0x384;
    }
    return var_v1;
}

int sceKernelGetThreadId(void);
int rt_mutex_platform_get_thread_id(int *arg0) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        *arg0 = sceKernelGetThreadId();
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_platform_begin_critical_section);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_mutex_platform_end_critical_section);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_init_pack_buffer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_pack_anything);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_pack_1byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_pack_cu2byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_pack_cstring);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_initialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_shutdown);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_register);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_reg_parser);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_reg_app_parser);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_update_parser);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_execute);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_execute_ext);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_get_callback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_zero_execution_counts);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_get_execution_counts);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_fragment_message);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_timeout_frag_msg);

void rt_parse_update(void) {
    rt_parse_timeout_frag_msg();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_find_frag_msg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_parse_fragment_handler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_string_strncpy);

int rt_strlen(signed char *arg0) {
    int var_v0;
    signed char *var_v1;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v1 = arg0;
        if (*arg0 != 0) {
            do {
                var_v1 += 1;
            } while (*var_v1 != 0);
        }
        var_v0 = var_v1 - arg0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_strnlen);

void rt_time_get_local(void) {
    rt_time_get_msecs();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_get_msecs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_get_secs);

void rt_time_start(void) {
    rt_time_get_time_stamp();
}

void rt_time_get_time_stamp(void) {
    rt_time_platform_get_time_stamp();
}

void rt_time_elapsed(void) {
    rt_time_elapsed_msecs();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_elapsed_secs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_elapsed_msecs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_elapsed_usecs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_delay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_initialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_reinitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_calc_diff);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_timestamp_to_secs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_timestamp_to_msecs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_timestamp_to_usecs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_get_base_diff);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_elapsed_timestamp);

void rt_time_sleep_usecs(void) {
    rt_time_sleep_usecs_platform();
}

void rt_time_get_time_string(void) {
    rt_time_platform_get_time_string();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10ED94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10EDEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10EE44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", headerfile_rcsid_10EEA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10EEF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_string_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10EFB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10F010);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_get_time_string_ptr);

void rt_time_get_date_time(void) {
    rt_time_platform_get_date_time();
}

void rt_time_get_gmtime(void) {
    rt_time_platform_get_gmtime();
}

int rt_time_platform_init(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_platform_get_time_stamp);

int sceKernelDelayThread(unsigned int delay);
int rt_time_sleep_usecs_platform(arg0)
    unsigned int arg0;
{
    sceKernelDelayThread(arg0);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_platform_update_date_time);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10F07C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10F0E8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_platform_get_time_string);

void rt_time_platform_get_gmtime(void) {
    rt_time_platform_get_date_time();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_time_platform_get_date_time);

void rt_time_platform_fast_elapsed_secs(void) {
    rt_time_elapsed_secs();
}

void rt_time_platform_fast_elapsed_msecs(void) {
    rt_time_elapsed_msecs();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_timebase_get_globaltime);

void rt_timebase_get_localtime(void) {
    rt_time_get_local();
}

void *memset(void *s, int c, unsigned int n);

int rt_timebase_restart(void) {
    memset(&gQueryRecord, 0, 0x198U);
    M2C_FIELD(&gLastQueryTimeStamp, int *, 0) = 0;
    M2C_FIELD(&gLastQueryTimeStamp, int *, 4) = 0;
    gLastNetTime = 0;
    gGlobalTimeBase = 0;
    return 0;
}

void rt_timebase_reset_globaltime(int arg0) {
    gGlobalTimeBase = arg0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_timebase_update_globaltime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_timebase_get_percentiledelay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_timebase_is_query_ready);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_timebase_start);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_start);

void rt_token_shutdown(int *arg0) {
    int temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        rt_token_destroy_table(temp_v0);
        rt_memory_free(arg0);
        *arg0 = 0;
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_is_valid);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_is_mine);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_is_free);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_is_pending);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_set_pending_state);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_free_owner);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_get_table_size);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_get_table);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_get_token_count);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_check_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_grant_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_release_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_update_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_list_check_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_list_grant_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_list_release_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_list_update_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_create_table);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_expand_table);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_destroy_table);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_add_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_remove_ownership);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_build_token_msg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/Please", rt_token_build_token_list_msg);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10F164);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10F1C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", rcsid_10F21C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/Please", header_rcsid_10F274);
