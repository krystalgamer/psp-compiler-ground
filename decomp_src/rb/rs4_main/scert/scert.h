/* shared declarations of the SCERT units (m2c-derived, from the former merged Please.c) */
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *rt_comm_adhoc_resolve_interface(void);
M2C_UNK *rt_comm_platform_resolve_interface(void);
M2C_UNK *rt_udp_get_version_string(void);
int InitObjectUpdateList(void);
int IsEven(int *arg0);
int IsNullRSAKey(int *arg0);
int IsZero(int *arg0);
int KM_SetUpdateCallback(int arg0);
int NetClientIndexToClientIndexPacket(int arg0);
int NetDisableLanMessaging(void);
int NetGetBuildTimeStamp(signed char *arg0);
int NetGetLANBroadcastCommSetting(int *arg0);
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
int NetGetTime(void *arg0, int *arg1);
int NetGetUPnPMemoryCeiling(int *arg0);
int NetGetUdpBindPort(int *arg0);
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
int NetUsePeerToPeer(void *arg0);
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
int rt_constraint_check_RT_1BYTE(signed char *arg0, void *arg1);
int rt_constraint_check_RT_2BYTE(short *arg0, void *arg1);
int rt_constraint_check_RT_4BYTE(int *arg0, void *arg1);
int rt_constraint_check_RT_4BYTE_FP(float *arg0, void *arg1);
int rt_constraint_check_RT_U1BYTE(unsigned char *arg0, void *arg1);
int rt_constraint_check_RT_U2BYTE(unsigned short *arg0, void *arg1);
int rt_constraint_check_RT_U4BYTE(unsigned int *arg0, void *arg1);
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
int rt_token_is_valid(unsigned int arg0);
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
void Decode(int *arg0, int arg1, unsigned int arg2);
void InitializePRNG(void);
void KM_GenerateRSAKeyPair(int arg0, int arg1);
void LANFindSetLocalServer(int arg0, int arg1);
void NetCreateConnInfoBare(void);
void NetFreeClientPointers(void);
void NetGetMyAddressInfoInternal(void *arg0);
void NetIGetDataStream(void);
void NetISendFieldUpdates(void);
void NetInitializeClients(void);
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
M2C_UNK rt_socket_get_local_ip_platform();          /* extern */
int rt_socket_get_err_platform();                   /* extern */
int sceNetInetClose();                              /* extern */
int rt_ip_string2ip(int);                           /* extern */
void *DMEmalloc(M2C_UNK);                           /* extern */
M2C_UNK rt_crypt_resolve_interface();               /* extern */
M2C_UNK rt_time_platform_get_time_string();         /* extern */
M2C_UNK rt_time_elapsed_secs();                     /* extern */
M2C_UNK rt_socket_get_dns_servers_platform();       /* extern */
M2C_UNK rt_time_platform_get_time_stamp();          /* extern */
M2C_UNK rt_socket_get_available_bytes_to_read_platform(); /* extern */
M2C_UNK setNewSeed(M2C_UNK);                        /* extern */
int sceNetInetListen();                             /* extern */
M2C_UNK rt_comm_shutdown();                         /* extern */
M2C_UNK rt_memory_free(void *);                     /* extern */
M2C_UNK rt_upnp_destroy(int);                       /* extern */
int NetIGetLocalTime();                             /* extern */
M2C_UNK rt_time_platform_get_date_time();           /* extern */
void *NetIGetObject();                              /* extern */
M2C_UNK rt_udp_destroy(int);                        /* extern */
M2C_UNK rt_socket_sendmsg_platform();               /* extern */
M2C_UNK rt_time_elapsed_msecs();                    /* extern */
M2C_UNK rt_socket_is_connected_platform();          /* extern */
int rt_parse_register();                            /* extern */
M2C_UNK SendGroupedFieldUpdate(int, M2C_UNK, M2C_UNK); /* extern */
int rt_parse_reg_parser();                          /* extern */
void *NetGetClientInfo(int, int);                   /* extern */
M2C_UNK rt_comm_linkaddress_toext(void *, void *);  /* extern */
M2C_UNK RSAGenerateKeyPair(int, int);               /* extern */
M2C_UNK rt_mutex_unlock(int, M2C_UNK);              /* extern */
M2C_UNK NetGetStreamChannel();                      /* extern */
M2C_UNK rt_socket_find_sockets_with_data_platform(); /* extern */
M2C_UNK rt_socket_find_closed_sockets_platform();   /* extern */
M2C_UNK DmeFree(M2C_UNK *);                         /* extern */
M2C_UNK rt_socket_set_non_blocking_platform();      /* extern */
M2C_UNK rt_time_get_msecs();                        /* extern */
M2C_UNK rt_token_destroy_table(int);                /* extern */
int rt_parse_update_parser();                       /* extern */
M2C_UNK rt_p2p_resolve_interface();                 /* extern */
M2C_UNK rt_parse_timeout_frag_msg();                /* extern */
M2C_UNK NetIRegisterMemoryCallbacks();              /* extern */
M2C_UNK rt_timebase_get_globaltime(void *);         /* extern */
int rt_memory_allocate();                           /* extern */
M2C_UNK rt_udp_resolve_interface();                 /* extern */
M2C_UNK rt_comm_release_channel_id(void *);         /* extern */
M2C_UNK rt_socket_initialize_stack_platform();      /* extern */
M2C_UNK rt_socket_set_no_delay_tcp_platform();      /* extern */
M2C_UNK rt_comm_linkaddress_setnull(int);           /* extern */
extern void *NetClientPointerList;
extern void *gObjectInterfacePtr;
extern int gAppUpdateCallback;
extern int gbEnableUnexpectedPort;
extern int gpszVersionString;
extern signed char gBuildTimeStamp_10DEB4;
extern void *gDmeGlobals;
extern void *gCommPlatformInterfacePtr;
extern unsigned char gLANMessage;
extern unsigned char D_00132074;
extern unsigned char gszRtUdpVersionString;
extern int gGlobalTimeBase;
extern int gLastNetTime;
extern unsigned char gLastQueryTimeStamp;
extern unsigned char gQueryRecord;
extern void *gUDPInterfacePtr;
extern int gMgr;
extern unsigned char gppConnInfo;
extern int gpszVersion_11536C;
extern int gnLocalServerPort;
extern int gpNetLocalServerConnection;
extern int gEchoInfo;
extern unsigned char gMyAddressInfo;
extern unsigned char gNatService;
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
extern int x1;
extern int x2;
extern int y;
extern int RT_UDP_INACTIVITY_TIMEOUT;
extern unsigned char gLatencyMetrics;
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
extern int gpfFreeCallback;
extern int gpfMallocCallback;
extern int gpszVersion_114A2C;
extern int gbTimebaseEnabled;
extern int gACodecGSMInterfacePtr;
extern int gACodecLPC10InterfacePtr;
extern int gACodecLPCInterfacePtr;
extern int gCryptInterfacePtr;
extern int gMsgClientInterfacePtr;
extern int gP2PInterfacePtr;
extern int gStreamMediaInterfacePtr;
extern int gVCodecJPEGInterfacePtr;
extern int gpfReallocCallback;
extern int gbInitialized_130B2C;
extern int HEARTBEAT_INTERVAL;
extern int gpHostChangeCallbackData;
extern int gpfHostChangeCallback;
