#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceRemoteplayApprove();
void sceRemoteplayClearAllRegistData();
void sceRemoteplayClearConnectHistory();
void sceRemoteplayConfirmDeviceRegist();
void sceRemoteplayDisconnect();
void sceRemoteplayGeneratePinCode();
void sceRemoteplayGetApMode();
void sceRemoteplayGetConnectHistory();
void sceRemoteplayGetConnectionStatus();
void sceRemoteplayGetConnectUserId();
void sceRemoteplayGetMbusDeviceInfo();
void sceRemoteplayGetRemoteplayStatus();
void sceRemoteplayGetRpMode();
void sceRemoteplayImeClose();
void sceRemoteplayImeFilterResult();
void sceRemoteplayImeGetEvent();
void sceRemoteplayImeNotify();
void sceRemoteplayImeNotifyEventResult();
void sceRemoteplayImeOpen();
void sceRemoteplayImeSetCaret();
void sceRemoteplayImeSetText();
void sceRemoteplayInitialize();
void sceRemoteplayIsRemoteOskReady();
void sceRemoteplayIsRemotePlaying();
void sceRemoteplayNotifyMbusDeviceRegistComplete();
void sceRemoteplayNotifyNpPushWakeup();
void sceRemoteplayNotifyPinCodeError();
void sceRemoteplayNotifyUserDelete();
void sceRemoteplayPrintAllRegistData();
void sceRemoteplayProhibit();
void sceRemoteplayProhibitStreaming();
void sceRemoteplaySetApMode();
void sceRemoteplaySetLogLevel();
void sceRemoteplaySetProhibition();
void sceRemoteplaySetProhibitionForVsh();
void sceRemoteplaySetRpMode();
void sceRemoteplayTerminate();
