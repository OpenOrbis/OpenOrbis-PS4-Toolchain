#ifndef _SCE_NET_H_
#define _SCE_NET_H_

#include <stdint.h>

#include <orbis/_types/net.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
OrbisNetId sceNetAccept(OrbisNetId, OrbisNetSockaddr*, OrbisNetSocklen_t*);
// Empty Comment
void sceNetAllocateAllRouteInfo();
// Empty Comment
void sceNetBandwidthControlGetDefaultParam();
// Empty Comment
void sceNetBandwidthControlGetIfParam();
// Empty Comment
void sceNetBandwidthControlGetPolicy();
// Empty Comment
void sceNetBandwidthControlSetDefaultParam();
// Empty Comment
void sceNetBandwidthControlSetIfParam();
// Empty Comment
void sceNetBandwidthControlSetPolicy();
// Empty Comment
int sceNetBind(OrbisNetId, const OrbisNetSockaddr*, OrbisNetSocklen_t);
// Empty Comment
void sceNetClearDnsCache();
// Empty Comment
void sceNetConfigAddArp();
// Empty Comment
void sceNetConfigAddIfaddr();
// Empty Comment
void sceNetConfigAddMRoute();
// Empty Comment
void sceNetConfigAddRoute();
// Empty Comment
void sceNetConfigAddRoute6();
// Empty Comment
void sceNetConfigCleanUpAllInterfaces();
// Empty Comment
void sceNetConfigDelArp();
// Empty Comment
void sceNetConfigDelDefaultRoute();
// Empty Comment
void sceNetConfigDelDefaultRoute6();
// Empty Comment
void sceNetConfigDelIfaddr();
// Empty Comment
void sceNetConfigDelIfaddr6();
// Empty Comment
void sceNetConfigDelMRoute();
// Empty Comment
void sceNetConfigDelRoute();
// Empty Comment
void sceNetConfigDelRoute6();
// Empty Comment
void sceNetConfigDownInterface();
// Empty Comment
void sceNetConfigEtherGetLinkMode();
// Empty Comment
void sceNetConfigEtherPostPlugInOutEvent();
// Empty Comment
void sceNetConfigEtherSetLinkMode();
// Empty Comment
void sceNetConfigFlushRoute();
// Empty Comment
void sceNetConfigGetDefaultRoute();
// Empty Comment
void sceNetConfigGetDefaultRoute6();
// Empty Comment
void sceNetConfigGetIfaddr();
// Empty Comment
void sceNetConfigGetIfaddr6();
// Empty Comment
void sceNetConfigRoutingShowRoutingConfig();
// Empty Comment
void sceNetConfigRoutingShowtCtlVar();
// Empty Comment
void sceNetConfigRoutingStart();
// Empty Comment
void sceNetConfigRoutingStop();
// Empty Comment
void sceNetConfigSetDefaultRoute();
// Empty Comment
void sceNetConfigSetDefaultRoute6();
// Empty Comment
void sceNetConfigSetDefaultScope();
// Empty Comment
void sceNetConfigSetIfaddr();
// Empty Comment
void sceNetConfigSetIfaddr6();
// Empty Comment
void sceNetConfigSetIfmtu();
// Empty Comment
void sceNetConfigUpInterface();
// Empty Comment
void sceNetConfigWlanAdhocClearWakeOnWlan();
// Empty Comment
void sceNetConfigWlanAdhocCreate();
// Empty Comment
void sceNetConfigWlanAdhocGetWakeOnWlanInfo();
// Empty Comment
void sceNetConfigWlanAdhocJoin();
// Empty Comment
void sceNetConfigWlanAdhocLeave();
// Empty Comment
void sceNetConfigWlanAdhocPspEmuClearWakeOnWlan();
// Empty Comment
void sceNetConfigWlanAdhocPspEmuGetWakeOnWlanInfo();
// Empty Comment
void sceNetConfigWlanAdhocPspEmuSetWakeOnWlan();
// Empty Comment
void sceNetConfigWlanAdhocScanJoin();
// Empty Comment
void sceNetConfigWlanAdhocSetExtInfoElement();
// Empty Comment
void sceNetConfigWlanAdhocSetWakeOnWlan();
// Empty Comment
void sceNetConfigWlanApStart();
// Empty Comment
void sceNetConfigWlanApStop();
// Empty Comment
void sceNetConfigWlanBackgroundScanQuery();
// Empty Comment
void sceNetConfigWlanBackgroundScanStart();
// Empty Comment
void sceNetConfigWlanBackgroundScanStop();
// Empty Comment
void sceNetConfigWlanDiagGetDeviceInfo();
// Empty Comment
void sceNetConfigWlanDiagSetAntenna();
// Empty Comment
void sceNetConfigWlanGetDeviceConfig();
// Empty Comment
void sceNetConfigWlanInfraGetRssiInfo();
// Empty Comment
void sceNetConfigWlanInfraLeave();
// Empty Comment
void sceNetConfigWlanInfraScanJoin();
// Empty Comment
void sceNetConfigWlanScan();
// Empty Comment
void sceNetConfigWlanSetDeviceConfig();
// Empty Comment
int sceNetConnect(OrbisNetId, const OrbisNetSockaddr*, OrbisNetSocklen_t);
// Empty Comment
void sceNetControl();
// Empty Comment
void sceNetDhcpdStart();
// Empty Comment
void sceNetDhcpdStop();
// Empty Comment
void sceNetDhcpGetAutoipInfo();
// Empty Comment
void sceNetDhcpGetInfo();
// Empty Comment
void sceNetDhcpGetInfoEx();
// Empty Comment
void sceNetDhcpStart();
// Empty Comment
void sceNetDhcpStop();
// Empty Comment
void sceNetDumpAbort();
// Empty Comment
void sceNetDumpCreate();
// Empty Comment
void sceNetDumpDestroy();
// Empty Comment
void sceNetDumpRead();
// Empty Comment
void sceNetDuplicateIpStart();
// Empty Comment
void sceNetEpollAbort();
// Empty Comment
void sceNetEpollControl();
// Empty Comment
void sceNetEpollCreate();
// Empty Comment
void sceNetEpollDestroy();
// Empty Comment
void sceNetEpollWait();
// Empty Comment
void sceNetErrnoLoc();
// Empty Comment
void sceNetEtherNtostr();
// Empty Comment
void sceNetEtherStrton();
// Empty Comment
void sceNetEventCallbackCreate();
// Empty Comment
void sceNetEventCallbackDestroy();
// Empty Comment
void sceNetEventCallbackGetError();
// Empty Comment
void sceNetEventCallbackWaitCB();
// Empty Comment
void sceNetFreeAllRouteInfo();
// Empty Comment
void sceNetGetArpInfo();
// Empty Comment
void sceNetGetDnsInfo();
// Empty Comment
void sceNetGetIfList();
// Empty Comment
void sceNetGetIfListOnce();
// Empty Comment
void sceNetGetIfName();
// Empty Comment
void sceNetGetIfnameNumList();
// Empty Comment
void sceNetGetMacAddress();
// Empty Comment
void sceNetGetMemoryPoolStats();
// Empty Comment
void sceNetGetNameToIndex();
// Empty Comment
int sceNetGetpeername(OrbisNetId, OrbisNetSockaddr*, OrbisNetSocklen_t*);
// Empty Comment
void sceNetGetRandom();
// Empty Comment
void sceNetGetRouteInfo();
// Empty Comment
void sceNetGetSockInfo();
// Empty Comment
void sceNetGetSockInfo6();
// Empty Comment
int sceNetGetsockname(OrbisNetId, OrbisNetSockaddr*, OrbisNetSocklen_t*);
// Empty Comment
int sceNetGetsockopt(OrbisNetId, int, int, void*, OrbisNetSocklen_t*);
// Empty Comment
void sceNetGetStatisticsInfo();
// Empty Comment
void sceNetGetSystemTime();
// Empty Comment
uint32_t sceNetHtonl(uint32_t);
// Empty Comment
uint64_t sceNetHtonll(uint64_t);
// Empty Comment
uint16_t sceNetHtons(uint16_t);
// Empty Comment
void sceNetInetNtop();
// Empty Comment
int sceNetInetPton(int, const char*, void*);
// Empty Comment
void sceNetInetPtonEx();
// Empty Comment
void sceNetInit();
// Empty Comment
void sceNetIoctl();
// Empty Comment
int sceNetListen(OrbisNetId, int);
// Empty Comment
void sceNetMemoryAllocate();
// Empty Comment
void sceNetMemoryFree();
// Empty Comment
uint32_t sceNetNtohl(uint32_t);
// Empty Comment
uint64_t sceNetNtohll(uint64_t);
// Empty Comment
uint16_t sceNetNtohs(uint16_t);
// Empty Comment
void sceNetPoolCreate();
// Empty Comment
void sceNetPoolDestroy();
// Empty Comment
void sceNetPppoeStart();
// Empty Comment
void sceNetPppoeStop();
// Empty Comment
int sceNetRecv(OrbisNetId, void*, size_t, int);
// Empty Comment
int sceNetRecvfrom(OrbisNetId, void*, size_t, int, OrbisNetSockaddr*, OrbisNetSocklen_t*);
// Empty Comment
int sceNetRecvmsg(OrbisNetId, OrbisNetMsghdr*, int);
// Empty Comment
void sceNetResolverAbort();
// Empty Comment
void sceNetResolverCreate();
// Empty Comment
void sceNetResolverDestroy();
// Empty Comment
void sceNetResolverGetError();
// Empty Comment
void sceNetResolverStartAton();
// Empty Comment
void sceNetResolverStartAton6();
// Empty Comment
void sceNetResolverStartNtoa();
// Empty Comment
void sceNetResolverStartNtoa6();
// Empty Comment
void sceNetResolverStartNtoaMultipleRecords();
// Empty Comment
void sceNetResolverStartNtoaMultipleRecordsEx();
// Empty Comment
int sceNetSend(OrbisNetId, const void*, size_t, int);
// Empty Comment
int sceNetSendmsg(OrbisNetId, const OrbisNetMsghdr*, int);
// Empty Comment
int sceNetSendto(OrbisNetId, const void*, size_t, int, const OrbisNetSockaddr*, OrbisNetSocklen_t);
// Empty Comment
void sceNetSetDnsInfo();
// Empty Comment
void sceNetSetDnsInfoToKernel();
// Empty Comment
int sceNetSetsockopt(OrbisNetId, int, int, const void*, OrbisNetSocklen_t);
// Empty Comment
void sceNetShowIfconfig();
// Empty Comment
void sceNetShowIfconfigWithMemory();
// Empty Comment
void sceNetShowNetstat();
// Empty Comment
void sceNetShowNetstatWithMemory();
// Empty Comment
void sceNetShowPolicy();
// Empty Comment
void sceNetShowPolicyWithMemory();
// Empty Comment
void sceNetShowRoute();
// Empty Comment
void sceNetShowRoute6();
// Empty Comment
void sceNetShowRouteWithMemory();
// Empty Comment
int sceNetShutdown(OrbisNetId, int);
// Empty Comment
OrbisNetId sceNetSocket(const char *, int, int, int);
// Empty Comment
int sceNetSocketAbort(OrbisNetId, int);
// Empty Comment
int sceNetSocketClose(OrbisNetId);
// Empty Comment
void sceNetSyncCreate();
// Empty Comment
void sceNetSyncDestroy();
// Empty Comment
void sceNetSyncGet();
// Empty Comment
void sceNetSyncSignal();
// Empty Comment
void sceNetSyncWait();
// Empty Comment
void sceNetSysctl();
// Empty Comment
void sceNetTerm();
// Empty Comment
void sceNetThreadCreate();
// Empty Comment
void sceNetThreadExit();
// Empty Comment
void sceNetThreadJoin();
// Empty Comment
void sceNetUsleep();


#endif

#ifdef __cplusplus
}
#endif
