#ifndef _SCE_NP_UTIL_H_
#define _SCE_NP_UTIL_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceNpAppInfoIntAbortRequest();
// Empty Comment
void sceNpAppInfoIntCheckAvailability();
// Empty Comment
void sceNpAppInfoIntCheckAvailabilityAll();
// Empty Comment
void sceNpAppInfoIntCheckServiceAvailability();
// Empty Comment
void sceNpAppInfoIntCheckServiceAvailabilityAll();
// Empty Comment
void sceNpAppInfoIntCreateRequest();
// Empty Comment
void sceNpAppInfoIntDestroyRequest();
// Empty Comment
void sceNpAppLaunchLinkIntAbortRequest();
// Empty Comment
void sceNpAppLaunchLinkIntCreateRequest();
// Empty Comment
void sceNpAppLaunchLinkIntDestroyRequest();
// Empty Comment
void sceNpAppLaunchLinkIntGetCompatibleTitleIdList();
// Empty Comment
void sceNpAppLaunchLinkIntGetCompatibleTitleIdNum();
// Empty Comment
void sceNpBandwidthTestAbort();
// Empty Comment
void sceNpBandwidthTestGetStatus();
// Empty Comment
void sceNpBandwidthTestInitStart();
// Empty Comment
void sceNpBandwidthTestShutdown();
// Empty Comment
void sceNpBandwidthTestShutdownInt();
// Empty Comment
void sceNpLookupAbortRequest();
// Empty Comment
void sceNpLookupCreateAsyncRequest();
// Empty Comment
void sceNpLookupCreateRequest();
// Empty Comment
void sceNpLookupCreateTitleCtx();
// Empty Comment
void sceNpLookupCreateTitleCtxA();
// Empty Comment
void sceNpLookupDeleteRequest();
// Empty Comment
void sceNpLookupDeleteTitleCtx();
// Empty Comment
void sceNpLookupNpId();
// Empty Comment
void sceNpLookupPollAsync();
// Empty Comment
void sceNpLookupSetTimeout();
// Empty Comment
void sceNpLookupWaitAsync();
// Empty Comment
void sceNpServiceChecker2IntAbortRequest();
// Empty Comment
void sceNpServiceChecker2IntCreateRequest();
// Empty Comment
void sceNpServiceChecker2IntDestroyRequest();
// Empty Comment
void sceNpServiceChecker2IntGetServiceAvailability();
// Empty Comment
void sceNpServiceChecker2IntIsSetServiceType();
// Empty Comment
void sceNpServiceCheckerIntAbortRequest();
// Empty Comment
void sceNpServiceCheckerIntCreateRequest();
// Empty Comment
void sceNpServiceCheckerIntDestroyRequest();
// Empty Comment
void sceNpServiceCheckerIntGetAvailability();
// Empty Comment
void sceNpServiceCheckerIntGetAvailabilityList();
// Empty Comment
void sceNpServiceCheckerIntIsCached();
// Empty Comment
void sceNpTitleMetadataIntAbortRequest();
// Empty Comment
void sceNpTitleMetadataIntCreateRequest();
// Empty Comment
void sceNpTitleMetadataIntDeleteRequest();
// Empty Comment
void sceNpTitleMetadataIntGetInfo();
// Empty Comment
void sceNpUtilityInit();
// Empty Comment
void sceNpUtilityTerm();
// Empty Comment
void sceNpWordFilterAbortRequest();
// Empty Comment
void sceNpWordFilterCensorComment();
// Empty Comment
void sceNpWordFilterCreateAsyncRequest();
// Empty Comment
void sceNpWordFilterCreateRequest();
// Empty Comment
void sceNpWordFilterCreateTitleCtx();
// Empty Comment
void sceNpWordFilterCreateTitleCtxA();
// Empty Comment
void sceNpWordFilterDeleteRequest();
// Empty Comment
void sceNpWordFilterDeleteTitleCtx();
// Empty Comment
void sceNpWordFilterPollAsync();
// Empty Comment
void sceNpWordFilterSanitizeComment();
// Empty Comment
void sceNpWordFilterSetTimeout();
// Empty Comment
void sceNpWordFilterWaitAsync();

#endif

#ifdef __cplusplus
}
#endif