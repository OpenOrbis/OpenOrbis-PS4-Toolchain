#ifndef _SCE_BGFT_H_
#define _SCE_BGFT_H_

#include "_types/bgft.h"

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

typedef int32_t OrbisBgftTaskId;

int32_t sceBgftServiceIntInit(OrbisBgftInitParams* params);
int32_t sceBgftServiceIntTerm();

int32_t sceBgftServiceDownloadFindTaskByContentId(const char* contentId, OrbisBgftTaskSubType subType, OrbisBgftTaskId* taskId);
int32_t sceBgftServiceDownloadFindActivePatchTask(const char* unk, OrbisBgftTaskId* taskId);
int32_t sceBgftServiceDownloadFindActivePupTask(OrbisBgftTaskId* taskId);

int32_t sceBgftServiceDownloadStartTask(OrbisBgftTaskId taskId);
int32_t sceBgftServiceDownloadStartTaskAll(void);
int32_t sceBgftServiceDownloadPauseTask(OrbisBgftTaskId taskId);
int32_t sceBgftServiceDownloadPauseTaskAll(void);
int32_t sceBgftServiceDownloadResumeTask(OrbisBgftTaskId taskId);
int32_t sceBgftServiceDownloadResumeTaskAll(void);
int32_t sceBgftServiceDownloadStopTask(OrbisBgftTaskId taskId);
int32_t sceBgftServiceDownloadStopTaskAll(void);

int32_t sceBgftServiceDownloadGetProgress(OrbisBgftTaskId taskId, OrbisBgftTaskProgress* progress);

int32_t sceBgftServiceIntDownloadRegisterTask(OrbisBgftDownloadParam* params, OrbisBgftTaskId* taskId);
int32_t sceBgftServiceIntDownloadRegisterTaskByStorageEx(OrbisBgftDownloadParamEx* params, OrbisBgftTaskId* taskId);
int32_t sceBgftServiceIntDownloadRegisterTaskStore(OrbisBgftDownloadParam* params, OrbisBgftTaskId* taskId, OrbisBgftDownloadRegisterErrorInfo* errorInfo);
int32_t sceBgftServiceIntDownloadUnregisterTask(OrbisBgftTaskId taskId);
int32_t sceBgftServiceIntDownloadReregisterTaskPatch(OrbisBgftTaskId oldTaskId, OrbisBgftTaskId* newTaskId);

int32_t sceBgftServiceIntDownloadStartTask(OrbisBgftTaskId taskId);
int32_t sceBgftServiceIntDownloadStopTask(OrbisBgftTaskId taskId);
int32_t sceBgftServiceIntDownloadPauseTask(OrbisBgftTaskId taskId);
int32_t sceBgftServiceIntDownloadResumeTask(OrbisBgftTaskId taskId);

int32_t sceBgftServiceIntDownloadGetTaskInfo(OrbisBgftTaskId taskId, OrbisBgftDownloadTaskInfo* taskInfo);

int32_t sceBgftServiceIntDownloadGetProgress(OrbisBgftTaskId taskId, OrbisBgftTaskProgress* progress);
int32_t sceBgftServiceIntDownloadGetPatchProgress(const char* contentId, OrbisBgftTaskProgress* progress);
int32_t sceBgftServiceIntDownloadGetPlayGoProgress(const char* contentId, OrbisBgftTaskProgress* progress);
int32_t sceBgftServiceIntDownloadGetGameAndGameAcProgress(const char* contentId, OrbisBgftTaskProgress* progress);

int32_t sceBgftServiceIntDownloadFindActiveGameAndGameAcTask(const char* contentId, OrbisBgftTaskId* taskId);
int32_t sceBgftServiceIntDownloadFindActiveTask(const char* contentId, OrbisBgftTaskSubType subType, OrbisBgftTaskId* taskId);

int32_t sceBgftServiceIntDebugDownloadRegisterPkg(OrbisBgftDownloadParam* params, OrbisBgftTaskId* taskId);

void sceBgftServiceDownloadQueryTask();

#ifdef __cplusplus
}
#endif

#endif
