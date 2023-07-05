#ifndef _SCE_NP_TROPHY_H_
#define _SCE_NP_TROPHY_H_

#include <stdint.h>
#include <orbis/_types/Np.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceNpTrophyAbortHandle();
// Empty Comment
void sceNpTrophyCaptureScreenshot();
// Empty Comment
int32_t sceNpTrophyCreateContext(int32_t *context, int32_t user, uint32_t unk, uint64_t unk2);
// Empty Comment
int32_t sceNpTrophyCreateHandle(int32_t *handle);
// Empty Comment
int32_t sceNpTrophyDestroyContext(int32_t context);
// Empty Comment
int32_t sceNpTrophyDestroyHandle(int32_t handle);
// Empty Comment
void sceNpTrophyGetGameIcon();
// Empty Comment
void sceNpTrophyGetGameInfo();
// Empty Comment
void sceNpTrophyGetGroupIcon();
// Empty Comment
void sceNpTrophyGetGroupInfo();
// Empty Comment
void sceNpTrophyGetTrophyIcon();
// Empty Comment
int32_t sceNpTrophyGetTrophyInfo(int32_t context, int32_t handle, int32_t TRPID, OrbisNpTrophyDetails* details, OrbisNpTrophyData* data);
// Empty Comment
void sceNpTrophyGetTrophyUnlockState();
// Empty Comment
void sceNpTrophyIntAbortHandle();
// Empty Comment
void sceNpTrophyIntCheckNetSyncTitles();
// Empty Comment
void sceNpTrophyIntCreateHandle();
// Empty Comment
void sceNpTrophyIntDestroyHandle();
// Empty Comment
void sceNpTrophyIntGetLocalTrophySummary();
// Empty Comment
void sceNpTrophyIntGetProgress();
// Empty Comment
void sceNpTrophyIntGetRunningTitle();
// Empty Comment
void sceNpTrophyIntGetRunningTitles();
// Empty Comment
void sceNpTrophyIntGetTrpIconByUri();
// Empty Comment
void sceNpTrophyIntNetSyncTitles();
// Empty Comment
int32_t sceNpTrophyRegisterContext(int32_t context, int32_t handle, uint64_t unk);
// Empty Comment
int32_t sceNpTrophyShowTrophyList(int32_t Context, int32_t hadle);
// Empty Comment
void sceNpTrophySystemIsServerAvailable();
// Empty Comment
int32_t sceNpTrophyUnlockTrophy(int32_t context, int32_t handle, int32_t TrophyID, int32_t *PLATID);

#ifdef __cplusplus
}
#endif

#endif
