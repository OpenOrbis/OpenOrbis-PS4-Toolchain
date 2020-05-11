#ifndef _SCE_NP_MANAGER_H_
#define _SCE_NP_MANAGER_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void _sceNpIpcCreateMemoryFromKernel();
// Empty Comment
void _sceNpIpcCreateMemoryFromPool();
// Empty Comment
void _sceNpIpcDestroyMemory();
// Empty Comment
void _sceNpIpcFreeImpl();
// Empty Comment
void _sceNpIpcGetNpMemAllocator();
// Empty Comment
void _sceNpIpcMallocImpl();
// Empty Comment
void _sceNpIpcReallocImpl();
// Empty Comment
void _sceNpManagerCreateMemoryFromKernel();
// Empty Comment
void _sceNpManagerCreateMemoryFromPool();
// Empty Comment
void _sceNpManagerDestroyMemory();
// Empty Comment
void _sceNpManagerFreeImpl();
// Empty Comment
void _sceNpManagerGetNpMemAllocator();
// Empty Comment
void _sceNpManagerMallocImpl();
// Empty Comment
void _sceNpManagerReallocImpl();
// Empty Comment
void sceNpAbortRequest();
// Empty Comment
void sceNpAsmClientGetNpComInfo2();
// Empty Comment
void sceNpAsmClientGetNpTitleToken();
// Empty Comment
void sceNpAsmClientGetServiceIdInfo();
// Empty Comment
void sceNpAsmClientInitialize();
// Empty Comment
void sceNpCheckCallback();
// Empty Comment
void sceNpCheckCallbackForLib();
// Empty Comment
void sceNpCheckNpAvailability();
// Empty Comment
void sceNpCheckNpAvailabilityA();
// Empty Comment
void sceNpCheckNpReachability();
// Empty Comment
void sceNpCheckPlus();
// Empty Comment
void sceNpCreateAsyncRequest();
// Empty Comment
void sceNpCreateRequest();
// Empty Comment
void sceNpDeleteRequest();
// Empty Comment
void sceNpGetAccountCountry();
// Empty Comment
void sceNpGetAccountCountryA();
// Empty Comment
void sceNpGetAccountDateOfBirth();
// Empty Comment
void sceNpGetAccountDateOfBirthA();
// Empty Comment
void sceNpGetAccountId();
// Empty Comment
void sceNpGetAccountIdA();
// Empty Comment
void sceNpGetAccountLanguage();
// Empty Comment
void sceNpGetAccountLanguageA();
// Empty Comment
void sceNpGetGamePresenceStatus();
// Empty Comment
void sceNpGetGamePresenceStatusA();
// Empty Comment
void sceNpGetNpId();
// Empty Comment
void sceNpGetNpReachabilityState();
// Empty Comment
void sceNpGetOnlineId();
// Empty Comment
void sceNpGetParentalControlInfo();
// Empty Comment
void sceNpGetParentalControlInfoA();
// Empty Comment
void sceNpGetState();
// Empty Comment
void sceNpGetUserIdByAccountId();
// Empty Comment
void sceNpGetUserIdByOnlineId();
// Empty Comment
void sceNpHasSignedUp();
// Empty Comment
void sceNpIdMapperAbortRequest();
// Empty Comment
void sceNpIdMapperAccountIdToNpId();
// Empty Comment
void sceNpIdMapperAccountIdToOnlineId();
// Empty Comment
void sceNpIdMapperCreateRequest();
// Empty Comment
void sceNpIdMapperDeleteRequest();
// Empty Comment
void sceNpIdMapperNpIdToAccountId();
// Empty Comment
void sceNpIdMapperOnlineIdToAccountId();
// Empty Comment
void sceNpInGameMessageAbortHandle();
// Empty Comment
void sceNpInGameMessageCreateHandle();
// Empty Comment
void sceNpInGameMessageDeleteHandle();
// Empty Comment
void sceNpInGameMessageInitialize();
// Empty Comment
void sceNpInGameMessagePrepare();
// Empty Comment
void sceNpInGameMessagePrepareA();
// Empty Comment
void sceNpInGameMessageSendData();
// Empty Comment
void sceNpInGameMessageSendDataA();
// Empty Comment
void sceNpInGameMessageTerminate();
// Empty Comment
void sceNpIntCheckPlus();
// Empty Comment
void sceNpManagerIntAbortRequest();
// Empty Comment
void sceNpManagerIntAddPlusMemberTypeCallback();
// Empty Comment
void sceNpManagerIntCheckGameNpAvailability();
// Empty Comment
void sceNpManagerIntClearParentalControlInfoSubAccount();
// Empty Comment
void sceNpManagerIntClearUsedFlag();
// Empty Comment
void sceNpManagerIntCreateLoginRequest();
// Empty Comment
void sceNpManagerIntCreateRequest();
// Empty Comment
void sceNpManagerIntDeleteRequest();
// Empty Comment
void sceNpManagerIntGetAccountCountry();
// Empty Comment
void sceNpManagerIntGetAccountCountryA();
// Empty Comment
void sceNpManagerIntGetAccountDateOfBirth();
// Empty Comment
void sceNpManagerIntGetAccountDateOfBirthA();
// Empty Comment
void sceNpManagerIntGetAccountId();
// Empty Comment
void sceNpManagerIntGetAccountLanguage();
// Empty Comment
void sceNpManagerIntGetAccountLanguageA();
// Empty Comment
void sceNpManagerIntGetAccountNpEnv();
// Empty Comment
void sceNpManagerIntGetActiveSigninState();
// Empty Comment
void sceNpManagerIntGetAuthorizationCode();
// Empty Comment
void sceNpManagerIntGetAuthorizationCodeA();
// Empty Comment
void sceNpManagerIntGetAuthorizationCodeWithRedirectUri();
// Empty Comment
void sceNpManagerIntGetAuthServerErrorFlag();
// Empty Comment
void sceNpManagerIntGetGameTitleBanInfo();
// Empty Comment
void sceNpManagerIntGetGameTitleToken();
// Empty Comment
void sceNpManagerIntGetGameVshToken();
// Empty Comment
void sceNpManagerIntGetLastAccountLanguage();
// Empty Comment
void sceNpManagerIntGetMAccountId();
// Empty Comment
void sceNpManagerIntGetNpEnv();
// Empty Comment
void sceNpManagerIntGetNpId();
// Empty Comment
void sceNpManagerIntGetNpIdSdk();
// Empty Comment
void sceNpManagerIntGetOnlineIdInternal();
// Empty Comment
void sceNpManagerIntGetOnlineIdSdk();
// Empty Comment
void sceNpManagerIntGetParentalControlFlag();
// Empty Comment
void sceNpManagerIntGetParentalControlInfo();
// Empty Comment
void sceNpManagerIntGetParentalControlInfoA();
// Empty Comment
void sceNpManagerIntGetParentalControlInfoNB();
// Empty Comment
void sceNpManagerIntGetPlusMemberType();
// Empty Comment
void sceNpManagerIntGetPlusMemberTypeNB();
// Empty Comment
void sceNpManagerIntGetServerError();
// Empty Comment
void sceNpManagerIntGetSigninState();
// Empty Comment
void sceNpManagerIntGetTicket();
// Empty Comment
void sceNpManagerIntGetTicketNB();
// Empty Comment
void sceNpManagerIntGetUserIdByAccountId();
// Empty Comment
void sceNpManagerIntGetUserIdByOnlineId();
// Empty Comment
void sceNpManagerIntGetUserList();
// Empty Comment
void sceNpManagerIntGetUserNum();
// Empty Comment
void sceNpManagerIntGetUserState();
// Empty Comment
void sceNpManagerIntGetVshToken();
// Empty Comment
void sceNpManagerIntGetVshTokenNB();
// Empty Comment
void sceNpManagerIntIsServerMaintenanceError();
// Empty Comment
void sceNpManagerIntIsSubAccount();
// Empty Comment
void sceNpManagerIntIsTemporarySignout();
// Empty Comment
void sceNpManagerIntIsUnregisteredClientError();
// Empty Comment
void sceNpManagerIntLoginAddJsonInfo();
// Empty Comment
void sceNpManagerIntLoginBind();
// Empty Comment
void sceNpManagerIntLoginCheckSignin();
// Empty Comment
void sceNpManagerIntLoginGet2svInfo();
// Empty Comment
void sceNpManagerIntLoginGetAccessToken();
// Empty Comment
void sceNpManagerIntLoginGetAccountId();
// Empty Comment
void sceNpManagerIntLoginGetAuthorizationCode();
// Empty Comment
void sceNpManagerIntLoginGetDeviceCodeInfo();
// Empty Comment
void sceNpManagerIntLoginGetEmail();
// Empty Comment
void sceNpManagerIntLoginGetOnlineId();
// Empty Comment
void sceNpManagerIntLoginGetUserId();
// Empty Comment
void sceNpManagerIntLoginParseJsonUserInfo();
// Empty Comment
void sceNpManagerIntLoginResetSsoToken();
// Empty Comment
void sceNpManagerIntLoginSetAccountInfo();
// Empty Comment
void sceNpManagerIntLoginSetSsoToken();
// Empty Comment
void sceNpManagerIntLoginValidateCredential();
// Empty Comment
void sceNpManagerIntLoginValidateKratosAuthCode();
// Empty Comment
void sceNpManagerIntLoginVerifyDeviceCode();
// Empty Comment
void sceNpManagerIntPfAuth();
// Empty Comment
void sceNpManagerIntRemovePlusMemberTypeCallback();
// Empty Comment
void sceNpManagerIntRevalidatePassword();
// Empty Comment
void sceNpManagerIntSetTimeout();
// Empty Comment
void sceNpManagerIntSignout();
// Empty Comment
void sceNpManagerIntTemporarySignout();
// Empty Comment
void sceNpManagerIntUpdateVshToken();
// Empty Comment
void sceNpManagerIntWebLoginRequired();
// Empty Comment
void sceNpManagerPrxStartVsh();
// Empty Comment
void sceNpManagerUtilConvertJidToNpId();
// Empty Comment
void sceNpManagerUtilConvertNpIdToJid();
// Empty Comment
void sceNpNotifyPlusFeature();
// Empty Comment
void sceNpPollAsync();
// Empty Comment
void sceNpPushInit();
// Empty Comment
void sceNpPushIntBeginInactive();
// Empty Comment
void sceNpPushIntEndInactive();
// Empty Comment
void sceNpPushIntGetConnectionState();
// Empty Comment
void sceNpRegisterGamePresenceCallback();
// Empty Comment
void sceNpRegisterGamePresenceCallbackA();
// Empty Comment
void sceNpRegisterNpReachabilityStateCallback();
// Empty Comment
void sceNpRegisterPlusEventCallback();
// Empty Comment
void sceNpRegisterStateCallback();
// Empty Comment
void sceNpRegisterStateCallbackA();
// Empty Comment
void sceNpServiceClientInit();
// Empty Comment
void sceNpServiceClientTerm();
// Empty Comment
void sceNpSetContentRestriction();
// Empty Comment
void sceNpSetGamePresenceOnlineA();
// Empty Comment
void sceNpSetNpTitleId();
// Empty Comment
void sceNpSetTimeout();
// Empty Comment
void sceNpUnregisterNpReachabilityStateCallback();
// Empty Comment
void sceNpUnregisterPlusEventCallback();
// Empty Comment
void sceNpUnregisterStateCallback();
// Empty Comment
void sceNpUnregisterStateCallbackA();
// Empty Comment
void sceNpWaitAsync();


#endif

#ifdef __cplusplus
}
#endif