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
int32_t sceNetBind(OrbisNetId, const OrbisNetSockaddr*, OrbisNetSocklen_t);
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
int32_t sceNetConnect(OrbisNetId, const OrbisNetSockaddr*, OrbisNetSocklen_t);
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
int32_t sceNetEtherNtostr(unsigned char* macAddr, char* out, int32_t length);
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
int32_t sceNetGetDnsInfo(OrbisNetDnsInfo* info, int32_t flags);
// Empty Comment
int32_t sceNetGetIfList(enum OrbisNetIfName ifName_num, struct OrbisNetIfEntry* out, int32_t unk);
// Empty Comment
void sceNetGetIfListOnce();
// Empty Comment
void sceNetGetIfName();
// Empty Comment
void sceNetGetIfnameNumList();
// Empty Comment
int32_t sceNetGetMacAddress(OrbisNetEtherAddr* mac_address, int32_t len);
// Empty Comment
void sceNetGetMemoryPoolStats();
// Empty Comment
void sceNetGetNameToIndex();
// Empty Comment
int32_t sceNetGetpeername(OrbisNetId, OrbisNetSockaddr*, OrbisNetSocklen_t*);
// Empty Comment
void sceNetGetRandom();
// Empty Comment
void sceNetGetRouteInfo();
// Empty Comment
void sceNetGetSockInfo();
// Empty Comment
void sceNetGetSockInfo6();
// Empty Comment
int32_t sceNetGetsockname(OrbisNetId, OrbisNetSockaddr*, OrbisNetSocklen_t*);
// Empty Comment
int32_t sceNetGetsockopt(OrbisNetId, int32_t, int32_t, void*, OrbisNetSocklen_t*);
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
int32_t sceNetInetPton(int32_t, const char*, void*);
// Empty Comment
void sceNetInetPtonEx();
// Empty Comment
int32_t sceNetInit();
// Empty Comment
void sceNetIoctl();
// Empty Comment
int32_t sceNetListen(OrbisNetId, int);
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
int32_t sceNetPoolCreate(const char *name, int32_t size, int32_t flags);
// Empty Comment
void sceNetPoolDestroy(int32_t);
// Empty Comment
void sceNetPppoeStart();
// Empty Comment
void sceNetPppoeStop();
// Empty Comment
int32_t sceNetRecv(OrbisNetId, void*, size_t, int);
// Empty Comment
int32_t sceNetRecvfrom(OrbisNetId, void*, size_t, int32_t, OrbisNetSockaddr*, OrbisNetSocklen_t*);
// Empty Comment
int32_t sceNetRecvmsg(OrbisNetId, OrbisNetMsghdr*, int);
// Empty Comment
int32_t sceNetResolverAbort(OrbisNetId, int32_t flags);
// Empty Comment
OrbisNetId sceNetResolverCreate(const char *name, int32_t memid, int32_t flags);
// Empty Comment
int32_t sceNetResolverDestroy(OrbisNetId);
// Empty Comment
void sceNetResolverGetError();
// Empty Comment
void sceNetResolverStartAton();
// Empty Comment
void sceNetResolverStartAton6();
// Empty Comment
int32_t sceNetResolverStartNtoa(OrbisNetId rid, const char *hostname, OrbisNetInAddr *addr, int32_t timeout, int32_t retry, int32_t flags);
// Empty Comment
void sceNetResolverStartNtoa6();
// Empty Comment
void sceNetResolverStartNtoaMultipleRecords();
// Empty Comment
void sceNetResolverStartNtoaMultipleRecordsEx();
// Empty Comment
int32_t sceNetSend(OrbisNetId, const void*, size_t, int);
// Empty Comment
int32_t sceNetSendmsg(OrbisNetId, const OrbisNetMsghdr*, int);
// Empty Comment
int32_t sceNetSendto(OrbisNetId, const void*, size_t, int32_t, const OrbisNetSockaddr*, OrbisNetSocklen_t);
// Empty Comment
void sceNetSetDnsInfo();
// Empty Comment
void sceNetSetDnsInfoToKernel();
// Empty Comment
int32_t sceNetSetsockopt(OrbisNetId, int32_t, int32_t, const void*, OrbisNetSocklen_t);
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
int32_t sceNetShutdown(OrbisNetId, int);
// Empty Comment
OrbisNetId sceNetSocket(const char *, int32_t, int32_t, int);
// Empty Comment
int32_t sceNetSocketAbort(OrbisNetId, int);
// Empty Comment
int32_t sceNetSocketClose(OrbisNetId);
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

#ifdef __cplusplus
}
#endif

#endif
