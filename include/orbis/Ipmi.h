#ifndef _SCE_IPMI_H_
#define _SCE_IPMI_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void _ZN4IPMI4impl10ClientImpl10disconnectEv();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl10initializeEPKNS_6Client6ConfigEPv();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl11getUserDataEv();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl12tryGetResultEjjPiPNS_10BufferInfoEj();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl12tryGetResultEjPiPvPmm();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl13pollEventFlagEjmjPm();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl13waitEventFlagEjmjPmPj();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl16invokeSyncMethodEjPKNS_8DataInfoEjPiPNS_10BufferInfoEj();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl16invokeSyncMethodEjPKvmPiPvPmm();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl17invokeAsyncMethodEjPKNS_8DataInfoEjPjPKNS_6Client12EventNotifeeE();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl17invokeAsyncMethodEjPKvmPjPKNS_6Client12EventNotifeeE();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl19terminateConnectionEv();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl6getMsgEjPvPmmPj();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl7connectEPKvmPi();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl7destroyEv();
// Empty Comment
void _ZN4IPMI4impl10ClientImpl9tryGetMsgEjPvPmm();
// Empty Comment
void _ZN4IPMI4impl10ClientImplC1Ev();
// Empty Comment
void _ZN4IPMI4impl10ClientImplC2Ev();
// Empty Comment
void _ZN4IPMI4impl10ClientImplD0Ev();
// Empty Comment
void _ZN4IPMI4impl10ClientImplD1Ev();
// Empty Comment
void _ZN4IPMI4impl10ClientImplD2Ev();
// Empty Comment
void _ZN4IPMI4impl10ServerImpl11getUserDataEv();
// Empty Comment
void _ZN4IPMI4impl10ServerImpl11tryDispatchEPvm();
// Empty Comment
void _ZN4IPMI4impl10ServerImpl13createSessionEPPNS_7SessionEPvS5_();
// Empty Comment
void _ZN4IPMI4impl10ServerImpl13runDispatcherEPvm();
// Empty Comment
void _ZN4IPMI4impl10ServerImpl14getServiceNameEv();
// Empty Comment
void _ZN4IPMI4impl10ServerImpl15getEventHandlerEv();
// Empty Comment
void _ZN4IPMI4impl10ServerImpl18shutdownDispatcherEv();
// Empty Comment
void _ZN4IPMI4impl10ServerImpl7destroyEv();
// Empty Comment
void _ZN4IPMI4impl10ServerImplC1Ev();
// Empty Comment
void _ZN4IPMI4impl10ServerImplC2Ev();
// Empty Comment
void _ZN4IPMI4impl10ServerImplD0Ev();
// Empty Comment
void _ZN4IPMI4impl10ServerImplD1Ev();
// Empty Comment
void _ZN4IPMI4impl10ServerImplD2Ev();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl10trySendMsgEjPKvm();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl11getUserDataEv();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl11tryDispatchEPvm();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl12estimateSizeEPKNS_7Session6ConfigE();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl12getClientPidEv();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl12setEventFlagEjm();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl13emptyMsgQueueEj();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl26respondToSyncMethodRequestEiPKNS_10BufferInfoEj();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl27respondToAsyncMethodRequestEjjiPKNS_8DataInfoEj();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl7destroyEv();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl7sendMsgEjPKvmPj();
// Empty Comment
void _ZN4IPMI4impl11SessionImpl9getServerEv();
// Empty Comment
void _ZN4IPMI4impl11SessionImplC1Ev();
// Empty Comment
void _ZN4IPMI4impl11SessionImplC2Ev();
// Empty Comment
void _ZN4IPMI4impl11SessionImplD0Ev();
// Empty Comment
void _ZN4IPMI4impl11SessionImplD1Ev();
// Empty Comment
void _ZN4IPMI4impl11SessionImplD2Ev();
// Empty Comment
void _ZN4IPMI6Client6Config14MsgQueueConfig20estimateMsgQueueSizeEmj();
// Empty Comment
void _ZN4IPMI6Client6Config14MsgQueueConfigC1Ev();
// Empty Comment
void _ZN4IPMI6Client6Config14MsgQueueConfigC2Ev();
// Empty Comment
void _ZN4IPMI6Client6Config24estimateClientMemorySizeEv();
// Empty Comment
void _ZN4IPMI6Client6Config26SyncMethodInvocationConfigC1Ev();
// Empty Comment
void _ZN4IPMI6Client6Config26SyncMethodInvocationConfigC2Ev();
// Empty Comment
void _ZN4IPMI6Client6Config27AsyncMethodInvocationConfigC1Ev();
// Empty Comment
void _ZN4IPMI6Client6Config27AsyncMethodInvocationConfigC2Ev();
// Empty Comment
void _ZN4IPMI6Client6ConfigC1Ev();
// Empty Comment
void _ZN4IPMI6Client6ConfigC2Ev();
// Empty Comment
void _ZN4IPMI6Client6createEPPS0_PKNS0_6ConfigEPvS6_();
// Empty Comment
void _ZN4IPMI6ClientC2Ev();
// Empty Comment
void _ZN4IPMI6ClientD0Ev();
// Empty Comment
void _ZN4IPMI6ClientD1Ev();
// Empty Comment
void _ZN4IPMI6ClientD2Ev();
// Empty Comment
void _ZN4IPMI6Server12EventHandler15onSessionKilledEPNS_7SessionE();
// Empty Comment
void _ZN4IPMI6Server12EventHandler20onSyncMethodDispatchEPNS_7SessionEjPKNS_8DataInfoEjPNS_10BufferInfoEj();
// Empty Comment
void _ZN4IPMI6Server12EventHandler21onAsyncMethodDispatchEPNS_7SessionEjjPKNS_8DataInfoEj();
// Empty Comment
void _ZN4IPMI6Server12EventHandlerD0Ev();
// Empty Comment
void _ZN4IPMI6Server12EventHandlerD1Ev();
// Empty Comment
void _ZN4IPMI6Server12EventHandlerD2Ev();
// Empty Comment
void _ZN4IPMI6Server6ConfigC1Ev();
// Empty Comment
void _ZN4IPMI6Server6ConfigC2Ev();
// Empty Comment
void _ZN4IPMI6Server6createEPPS0_PKNS0_6ConfigEPvS6_();
// Empty Comment
void _ZN4IPMI6ServerC2Ev();
// Empty Comment
void _ZN4IPMI6ServerD0Ev();
// Empty Comment
void _ZN4IPMI6ServerD1Ev();
// Empty Comment
void _ZN4IPMI6ServerD2Ev();
// Empty Comment
void _ZN4IPMI7Session6Config25estimateSessionMemorySizeEv();
// Empty Comment
void _ZN4IPMI7SessionC2Ev();
// Empty Comment
void _ZN4IPMI7SessionD0Ev();
// Empty Comment
void _ZN4IPMI7SessionD1Ev();
// Empty Comment
void _ZN4IPMI7SessionD2Ev();
// Empty Comment
void _ZNK4IPMI6Server6Config29estimateTempWorkingMemorySizeEv();
// Empty Comment
void _ZTVN4IPMI6Server12EventHandlerE();

#endif

#ifdef __cplusplus
}
#endif