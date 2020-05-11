#ifndef _SCE_FIOS2_H_
#define _SCE_FIOS2_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceFiosArchiveGetDecompressorThreadCount();
// Empty Comment
void sceFiosArchiveGetMountBufferSize();
// Empty Comment
void sceFiosArchiveGetMountBufferSizeSync();
// Empty Comment
void sceFiosArchiveMount();
// Empty Comment
void sceFiosArchiveMountSync();
// Empty Comment
void sceFiosArchiveMountWithOrder();
// Empty Comment
void sceFiosArchiveSetDecompressorThreadCount();
// Empty Comment
void sceFiosArchiveUnmount();
// Empty Comment
void sceFiosArchiveUnmountSync();
// Empty Comment
void sceFiosCacheContainsFileRangeSync();
// Empty Comment
void sceFiosCacheContainsFileSync();
// Empty Comment
void sceFiosCacheFlushFileRangeSync();
// Empty Comment
void sceFiosCacheFlushFileSync();
// Empty Comment
void sceFiosCacheFlushSync();
// Empty Comment
void sceFiosCachePrefetchFH();
// Empty Comment
void sceFiosCachePrefetchFHRange();
// Empty Comment
void sceFiosCachePrefetchFHRangeSync();
// Empty Comment
void sceFiosCachePrefetchFHSync();
// Empty Comment
void sceFiosCachePrefetchFile();
// Empty Comment
void sceFiosCachePrefetchFileRange();
// Empty Comment
void sceFiosCachePrefetchFileRangeSync();
// Empty Comment
void sceFiosCachePrefetchFileSync();
// Empty Comment
void sceFiosCancelAllOps();
// Empty Comment
void sceFiosClearTimeStamps();
// Empty Comment
void sceFiosCloseAllFiles();
// Empty Comment
void sceFiosDateFromComponents();
// Empty Comment
void sceFiosDateGetCurrent();
// Empty Comment
void sceFiosDateToComponents();
// Empty Comment
void sceFiosDeallocatePassthruFH();
// Empty Comment
void sceFiosDebugDumpDate();
// Empty Comment
void sceFiosDebugDumpDH();
// Empty Comment
void sceFiosDebugDumpError();
// Empty Comment
void sceFiosDebugDumpFH();
// Empty Comment
void sceFiosDebugDumpOp();
// Empty Comment
void sceFiosDelete();
// Empty Comment
void sceFiosDeleteSync();
// Empty Comment
void sceFiosDHClose();
// Empty Comment
void sceFiosDHCloseSync();
// Empty Comment
void sceFiosDHGetPath();
// Empty Comment
void sceFiosDHOpen();
// Empty Comment
void sceFiosDHOpenSync();
// Empty Comment
void sceFiosDHRead();
// Empty Comment
void sceFiosDHReadSync();
// Empty Comment
void sceFiosDirectoryCreate();
// Empty Comment
void sceFiosDirectoryCreateSync();
// Empty Comment
void sceFiosDirectoryCreateWithMode();
// Empty Comment
void sceFiosDirectoryCreateWithModeSync();
// Empty Comment
void sceFiosDirectoryDelete();
// Empty Comment
void sceFiosDirectoryDeleteSync();
// Empty Comment
void sceFiosDirectoryExists();
// Empty Comment
void sceFiosDirectoryExistsSync();
// Empty Comment
void sceFiosDLLInitialize();
// Empty Comment
void sceFiosDLLTerminate();
// Empty Comment
void sceFiosExists();
// Empty Comment
void sceFiosExistsSync();
// Empty Comment
void sceFiosFHClose();
// Empty Comment
void sceFiosFHCloseSync();
// Empty Comment
void sceFiosFHGetOpenParams();
// Empty Comment
void sceFiosFHGetPath();
// Empty Comment
void sceFiosFHGetSize();
// Empty Comment
void sceFiosFHOpen();
// Empty Comment
void sceFiosFHOpenSync();
// Empty Comment
void sceFiosFHOpenWithMode();
// Empty Comment
void sceFiosFHOpenWithModeSync();
// Empty Comment
void sceFiosFHPread();
// Empty Comment
void sceFiosFHPreadSync();
// Empty Comment
void sceFiosFHPreadv();
// Empty Comment
void sceFiosFHPreadvSync();
// Empty Comment
void sceFiosFHPwrite();
// Empty Comment
void sceFiosFHPwriteSync();
// Empty Comment
void sceFiosFHPwritev();
// Empty Comment
void sceFiosFHPwritevSync();
// Empty Comment
void sceFiosFHRead();
// Empty Comment
void sceFiosFHReadSync();
// Empty Comment
void sceFiosFHReadv();
// Empty Comment
void sceFiosFHReadvSync();
// Empty Comment
void sceFiosFHSeek();
// Empty Comment
void sceFiosFHStat();
// Empty Comment
void sceFiosFHStatSync();
// Empty Comment
void sceFiosFHSync();
// Empty Comment
void sceFiosFHSyncSync();
// Empty Comment
void sceFiosFHTell();
// Empty Comment
void sceFiosFHToFileno();
// Empty Comment
void sceFiosFHTruncate();
// Empty Comment
void sceFiosFHTruncateSync();
// Empty Comment
void sceFiosFHWrite();
// Empty Comment
void sceFiosFHWriteSync();
// Empty Comment
void sceFiosFHWritev();
// Empty Comment
void sceFiosFHWritevSync();
// Empty Comment
void sceFiosFileDelete();
// Empty Comment
void sceFiosFileDeleteSync();
// Empty Comment
void sceFiosFileExists();
// Empty Comment
void sceFiosFileExistsSync();
// Empty Comment
void sceFiosFileGetSize();
// Empty Comment
void sceFiosFileGetSizeSync();
// Empty Comment
void sceFiosFilenoToFH();
// Empty Comment
void sceFiosFileRead();
// Empty Comment
void sceFiosFileReadSync();
// Empty Comment
void sceFiosFileTruncate();
// Empty Comment
void sceFiosFileTruncateSync();
// Empty Comment
void sceFiosFileWrite();
// Empty Comment
void sceFiosFileWriteSync();
// Empty Comment
void sceFiosGetAllDHs();
// Empty Comment
void sceFiosGetAllFHs();
// Empty Comment
void sceFiosGetAllOps();
// Empty Comment
void sceFiosGetDefaultOpAttr();
// Empty Comment
void sceFiosGetGlobalDefaultOpAttr();
// Empty Comment
void sceFiosGetSuspendCount();
// Empty Comment
void sceFiosGetThreadDefaultOpAttr();
// Empty Comment
void sceFiosInitialize();
// Empty Comment
void sceFiosIOFilterAdd();
// Empty Comment
void sceFiosIOFilterCache();
// Empty Comment
void sceFiosIOFilterGetInfo();
// Empty Comment
void sceFiosIOFilterPsarcDearchiver();
// Empty Comment
void sceFiosIOFilterRemove();
// Empty Comment
void sceFiosIsIdle();
// Empty Comment
void sceFiosIsInitialized();
// Empty Comment
void sceFiosIsSuspended();
// Empty Comment
void sceFiosIsValidHandle();
// Empty Comment
void sceFiosOpCancel();
// Empty Comment
void sceFiosOpDelete();
// Empty Comment
void sceFiosOpGetActualCount();
// Empty Comment
void sceFiosOpGetAttr();
// Empty Comment
void sceFiosOpGetBuffer();
// Empty Comment
void sceFiosOpGetError();
// Empty Comment
void sceFiosOpGetOffset();
// Empty Comment
void sceFiosOpGetPath();
// Empty Comment
void sceFiosOpGetRequestCount();
// Empty Comment
void sceFiosOpIsCancelled();
// Empty Comment
void sceFiosOpIsDone();
// Empty Comment
void sceFiosOpReschedule();
// Empty Comment
void sceFiosOpRescheduleWithPriority();
// Empty Comment
void sceFiosOpSetBuffer();
// Empty Comment
void sceFiosOpSyncWait();
// Empty Comment
void sceFiosOpSyncWaitForIO();
// Empty Comment
void sceFiosOpWait();
// Empty Comment
void sceFiosOpWaitUntil();
// Empty Comment
void sceFiosOverlayAdd();
// Empty Comment
void sceFiosOverlayGetInfo();
// Empty Comment
void sceFiosOverlayGetList();
// Empty Comment
void sceFiosOverlayModify();
// Empty Comment
void sceFiosOverlayRemove();
// Empty Comment
void sceFiosOverlayResolveSync();
// Empty Comment
void sceFiosPathcmp();
// Empty Comment
void sceFiosPathncmp();
// Empty Comment
void sceFiosPathNormalize();
// Empty Comment
void sceFiosPrintf();
// Empty Comment
void sceFiosPrintTimeStamps();
// Empty Comment
void sceFiosRename();
// Empty Comment
void sceFiosRenameSync();
// Empty Comment
void sceFiosResolve();
// Empty Comment
void sceFiosResolveSync();
// Empty Comment
void sceFiosResume();
// Empty Comment
void sceFiosSaveTimeStamp();
// Empty Comment
void sceFiosSetGlobalDefaultOpAttr();
// Empty Comment
void sceFiosSetThreadDefaultOpAttr();
// Empty Comment
void sceFiosShutdownAndCancelOps();
// Empty Comment
void sceFiosStat();
// Empty Comment
void sceFiosStatSync();
// Empty Comment
void sceFiosSuspend();
// Empty Comment
void sceFiosTerminate();
// Empty Comment
void sceFiosTimeGetCurrent();
// Empty Comment
void sceFiosTimeIntervalFromNanoseconds();
// Empty Comment
void sceFiosTimeIntervalToNanoseconds();
// Empty Comment
void sceFiosTraceTimestamp();
// Empty Comment
void sceFiosUpdateParameters();
// Empty Comment
void sceFiosVprintf();

#endif

#ifdef __cplusplus
}
#endif