#ifndef _SCE_BGFT_H_
#define _SCE_BGFT_H_

#include "_types/bgft.h"

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

typedef int OrbisBgftTaskId;

int sceBgftServiceIntInit(OrbisBgftInitParams* params);
int sceBgftServiceIntTerm();

int sceBgftServiceDownloadFindTaskByContentId(const char* contentId, OrbisBgftTaskSubType subType, OrbisBgftTaskId* taskId);
int sceBgftServiceDownloadFindActivePatchTask(const char* unk, OrbisBgftTaskId* taskId);
int sceBgftServiceDownloadFindActivePupTask(OrbisBgftTaskId* taskId);

int sceBgftServiceDownloadStartTask(OrbisBgftTaskId taskId);
int sceBgftServiceDownloadStartTaskAll(void);
int sceBgftServiceDownloadPauseTask(OrbisBgftTaskId taskId);
int sceBgftServiceDownloadPauseTaskAll(void);
int sceBgftServiceDownloadResumeTask(OrbisBgftTaskId taskId);
int sceBgftServiceDownloadResumeTaskAll(void);
int sceBgftServiceDownloadStopTask(OrbisBgftTaskId taskId);
int sceBgftServiceDownloadStopTaskAll(void);

int sceBgftServiceDownloadGetProgress(OrbisBgftTaskId taskId, OrbisBgftTaskProgress* progress);

int sceBgftServiceIntDownloadRegisterTask(OrbisBgftDownloadParam* params, OrbisBgftTaskId* taskId);
int sceBgftServiceIntDownloadRegisterTaskByStorageEx(OrbisBgftDownloadParamEx* params, OrbisBgftTaskId* taskId);
int sceBgftServiceIntDownloadRegisterTaskStore(OrbisBgftDownloadParam* params, OrbisBgftTaskId* taskId, OrbisBgftDownloadRegisterErrorInfo* errorInfo);
int sceBgftServiceIntDownloadUnregisterTask(OrbisBgftTaskId taskId);
int sceBgftServiceIntDownloadReregisterTaskPatch(OrbisBgftTaskId oldTaskId, OrbisBgftTaskId* newTaskId);

int sceBgftServiceIntDownloadStartTask(OrbisBgftTaskId taskId);
int sceBgftServiceIntDownloadStopTask(OrbisBgftTaskId taskId);
int sceBgftServiceIntDownloadPauseTask(OrbisBgftTaskId taskId);
int sceBgftServiceIntDownloadResumeTask(OrbisBgftTaskId taskId);

int sceBgftServiceIntDownloadGetTaskInfo(OrbisBgftTaskId taskId, OrbisBgftDownloadTaskInfo* taskInfo);

int sceBgftServiceIntDownloadGetProgress(OrbisBgftTaskId taskId, OrbisBgftTaskProgress* progress);
int sceBgftServiceIntDownloadGetPatchProgress(const char* contentId, OrbisBgftTaskProgress* progress);
int sceBgftServiceIntDownloadGetPlayGoProgress(const char* contentId, OrbisBgftTaskProgress* progress);
int sceBgftServiceIntDownloadGetGameAndGameAcProgress(const char* contentId, OrbisBgftTaskProgress* progress);

int sceBgftServiceIntDownloadFindActiveGameAndGameAcTask(const char* contentId, OrbisBgftTaskId* taskId);
int sceBgftServiceIntDownloadFindActiveTask(const char* contentId, OrbisBgftTaskSubType subType, OrbisBgftTaskId* taskId);

int sceBgftServiceIntDebugDownloadRegisterPkg(OrbisBgftDownloadParam* params, OrbisBgftTaskId* taskId);

void sceBgftServiceDownloadQueryTask();

#ifdef __cplusplus
}
#endif

#endif
