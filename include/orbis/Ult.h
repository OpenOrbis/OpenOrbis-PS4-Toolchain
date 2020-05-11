#ifndef _SCE_UTIL_H_
#define _SCE_UTIL_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void _sceUltConditionVariableCreate();
// Empty Comment
void _sceUltConditionVariableOptParamInitialize();
// Empty Comment
void _sceUltMutexCreate();
// Empty Comment
void _sceUltMutexOptParamInitialize();
// Empty Comment
void _sceUltQueueCreate();
// Empty Comment
void _sceUltQueueDataResourcePoolCreate();
// Empty Comment
void _sceUltQueueDataResourcePoolOptParamInitialize();
// Empty Comment
void _sceUltQueueOptParamInitialize();
// Empty Comment
void _sceUltReaderWriterLockCreate();
// Empty Comment
void _sceUltReaderWriterLockOptParamInitialize();
// Empty Comment
void _sceUltSemaphoreCreate();
// Empty Comment
void _sceUltSemaphoreOptParamInitialize();
// Empty Comment
void _sceUltUlthreadCreate();
// Empty Comment
void _sceUltUlthreadOptParamInitialize();
// Empty Comment
void _sceUltUlthreadRuntimeCreate();
// Empty Comment
void _sceUltUlthreadRuntimeOptParamInitialize();
// Empty Comment
void _sceUltWaitingQueueResourcePoolCreate();
// Empty Comment
void _sceUltWaitingQueueResourcePoolOptParamInitialize();
// Empty Comment
void sceUltConditionVariableDestroy();
// Empty Comment
void sceUltConditionVariableSignal();
// Empty Comment
void sceUltConditionVariableSignalAll();
// Empty Comment
void sceUltConditionVariableWait();
// Empty Comment
void sceUltFinalize();
// Empty Comment
void sceUltGetConditionVariableInfo();
// Empty Comment
void sceUltGetMutexInfo();
// Empty Comment
void sceUltGetQueueDataResourcePoolInfo();
// Empty Comment
void sceUltGetQueueInfo();
// Empty Comment
void sceUltGetReaderWriterLockInfo();
// Empty Comment
void sceUltGetSemaphoreInfo();
// Empty Comment
void sceUltGetUlthreadInfo();
// Empty Comment
void sceUltGetUlthreadRuntimeInfo();
// Empty Comment
void sceUltGetWaitingQueueResourcePoolInfo();
// Empty Comment
void sceUltInitialize();
// Empty Comment
void sceUltMutexDestroy();
// Empty Comment
void sceUltMutexLock();
// Empty Comment
void sceUltMutexTryLock();
// Empty Comment
void sceUltMutexUnlock();
// Empty Comment
void sceUltQueueDataResourcePoolDestroy();
// Empty Comment
void sceUltQueueDataResourcePoolGetWorkAreaSize();
// Empty Comment
void sceUltQueueDestroy();
// Empty Comment
void sceUltQueuePop();
// Empty Comment
void sceUltQueuePush();
// Empty Comment
void sceUltQueueTryPop();
// Empty Comment
void sceUltQueueTryPush();
// Empty Comment
void sceUltReaderWriterLockDestroy();
// Empty Comment
void sceUltReaderWriterLockLockRead();
// Empty Comment
void sceUltReaderWriterLockLockWrite();
// Empty Comment
void sceUltReaderWriterLockTryLockRead();
// Empty Comment
void sceUltReaderWriterLockTryLockWrite();
// Empty Comment
void sceUltReaderWriterLockUnlockRead();
// Empty Comment
void sceUltReaderWriterLockUnlockWrite();
// Empty Comment
void sceUltSemaphoreAcquire();
// Empty Comment
void sceUltSemaphoreDestroy();
// Empty Comment
void sceUltSemaphoreRelease();
// Empty Comment
void sceUltSemaphoreTryAcquire();
// Empty Comment
void sceUltUlthreadExit();
// Empty Comment
void sceUltUlthreadGetSelf();
// Empty Comment
void sceUltUlthreadJoin();
// Empty Comment
void sceUltUlthreadRuntimeDestroy();
// Empty Comment
void sceUltUlthreadRuntimeGetWorkAreaSize();
// Empty Comment
void sceUltUlthreadTryJoin();
// Empty Comment
void sceUltUlthreadYield();
// Empty Comment
void sceUltWaitingQueueResourcePoolDestroy();
// Empty Comment
void sceUltWaitingQueueResourcePoolGetWorkAreaSize();

#endif

#ifdef __cplusplus
}
#endif