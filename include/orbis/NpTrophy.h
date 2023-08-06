#ifndef _SCE_NP_TROPHY_H_
#define _SCE_NP_TROPHY_H_

#include <stdint.h>
#include <orbis/_types/Np.h>

#ifdef __cplusplus 
extern "C" {
#endif

int32_t sceNpTrophyAbortHandle(int32_t handle);
int32_t sceNpTrophyCaptureScreenshot(int32_t handle, const OrbisNpTrophyScreenshotTarget* target, int32_t numTargets);
int32_t sceNpTrophyCreateContext(int32_t* context, int32_t userID, uint32_t serviceLabel, uint64_t options);
int32_t sceNpTrophyCreateHandle(int32_t* handle);
int32_t sceNpTrophyDestroyContext(int32_t context);
int32_t sceNpTrophyDestroyHandle(int32_t handle);
int32_t sceNpTrophyGetGameIcon(int32_t context, int32_t handle, void* buffer, size_t* size);
int32_t sceNpTrophyGetGameInfo(int32_t context, int32_t handle, OrbisNpTrophyGameDetails* details, OrbisNpTrophyGameData* data);
int32_t sceNpTrophyGetGroupIcon(int32_t context, int32_t handle, int32_t groupID, void* buffer, size_t* size);
int32_t sceNpTrophyGetGroupInfo(int32_t context, int32_t handle, int32_t groupID, OrbisNpTrophyGroupDetails* details, OrbisNpTrophyGroupData* data);
int32_t sceNpTrophyGetTrophyIcon(int32_t context, int32_t handle, int32_t trophyID, void* buffer, size_t* size);
int32_t sceNpTrophyGetTrophyInfo(int32_t context, int32_t handle, int32_t trophyID, OrbisNpTrophyDetails* details, OrbisNpTrophyData* data);
int32_t sceNpTrophyGetTrophyUnlockState(int32_t context, int32_t handle, OrbisNpTrophyFlagArray* flags, uint32_t* count);
int32_t sceNpTrophyRegisterContext(int32_t context, int32_t handle, uint64_t options);
int32_t sceNpTrophyShowTrophyList(int32_t context, int32_t handle);
int32_t sceNpTrophyUnlockTrophy(int32_t context, int32_t handle, int32_t trophyID, int32_t *platinumId);

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