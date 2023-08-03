#ifndef _SCE_NP_TROPHY_H_
#define _SCE_NP_TROPHY_H_

#include <stdint.h>
#include <orbis/_types/Np.h>

#ifdef __cplusplus 
extern "C" {
#endif

int32_t sceNpTrophyAbortHandle(int32_t a_handle);
int32_t sceNpTrophyCaptureScreenshot(int32_t a_handle, const OrbisNpTrophyScreenshotTarget* a_target, int32_t a_numTargets);
int32_t sceNpTrophyCreateContext(int32_t* a_context, int32_t a_userID, uint32_t a_serviceLabel, uint64_t a_options);
int32_t sceNpTrophyCreateHandle(int32_t* a_handle);
int32_t sceNpTrophyDestroyContext(int32_t a_context);
int32_t sceNpTrophyDestroyHandle(int32_t a_handle);
int32_t sceNpTrophyGetGameIcon(int32_t a_context, int32_t a_handle, void* a_buffer, size_t* a_size);
int32_t sceNpTrophyGetGameInfo(int32_t a_context, int32_t a_handle, OrbisNpTrophyGameDetails* a_details, OrbisNpTrophyGameData*);
int32_t sceNpTrophyGetGroupIcon(int32_t a_context, int32_t a_handle, int32_t a_groupID, void* a_buffer, size_t* a_size);
int32_t sceNpTrophyGetGroupInfo(int32_t a_context, int32_t a_handle, int32_t a_groupID, OrbisNpTrophyGroupDetails* a_details, OrbisNpTrophyGroupData* a_data);
int32_t sceNpTrophyGetTrophyIcon(int32_t a_context, int32_t a_handle, int32_t a_trophyID, void* a_buffer, size_t* a_size);
int32_t sceNpTrophyGetTrophyInfo(int32_t a_context, int32_t a_handle, int32_t a_trophyID, OrbisNpTrophyDetails* a_details, OrbisNpTrophyData* a_data);
int32_t sceNpTrophyGetTrophyUnlockState(int32_t a_context, int32_t a_handle, OrbisNpTrophyFlagArray* a_flags, uint32_t* a_count);
int32_t sceNpTrophyRegisterContext(int32_t a_context, int32_t a_handle, uint64_t a_options);
int32_t sceNpTrophyShowTrophyList(int32_t a_context, int32_t a_handle);
int32_t sceNpTrophyUnlockTrophy(int32_t a_context, int32_t a_handle, int32_t a_trophyID, int32_t *a_platinumId);

void sceNpTrophySystemIsServerAvailable();
void sceNpTrophyIntAbortHandle();
void sceNpTrophyIntCheckNetSyncTitles();
void sceNpTrophyIntCreateHandle();
void sceNpTrophyIntDestroyHandle();
void sceNpTrophyIntGetLocalTrophySummary();
void sceNpTrophyIntGetProgress();
void sceNpTrophyIntGetRunningTitle();
void sceNpTrophyIntGetRunningTitles();
void sceNpTrophyIntGetTrpIconByUri();
void sceNpTrophyIntNetSyncTitles();
#ifdef __cplusplus
}
#endif
#endif