#pragma once

// https://github.com/flatz/ps4_stub_lib_maker_v2/blob/master/include/bgft.h

struct _OrbisBgftInitParams {
	void* heap;
	size_t heapSize;
};
typedef struct _OrbisBgftInitParams OrbisBgftInitParams;

enum _OrbisBgftTaskSubType {
	ORBIS_BGFT_TASK_SUB_TYPE_UNKNOWN = 0,
	ORBIS_BGFT_TASK_SUB_TYPE_PHOTO = 1,
	ORBIS_BGFT_TASK_SUB_TYPE_MUSIC = 2,
	ORBIS_BGFT_TASK_SUB_TYPE_VIDEO = 3,
	ORBIS_BGFT_TASK_SUB_TYPE_MARLIN_VIDEO = 4,
	ORBIS_BGFT_TASK_SUB_TYPE_UPDATA_ORBIS = 5,
	ORBIS_BGFT_TASK_SUB_TYPE_GAME = 6,
	ORBIS_BGFT_TASK_SUB_TYPE_GAME_AC = 7,
	ORBIS_BGFT_TASK_SUB_TYPE_GAME_PATCH = 8,
	ORBIS_BGFT_TASK_SUB_TYPE_GAME_LICENSE = 9,
	ORBIS_BGFT_TASK_SUB_TYPE_SAVE_DATA = 10,
	ORBIS_BGFT_TASK_SUB_TYPE_CRASH_REPORT = 11,
	ORBIS_BGFT_TASK_SUB_TYPE_PACKAGE = 12,
	ORBIS_BGFT_TASK_SUB_TYPE_MAX = 13,
};
typedef enum _OrbisBgftTaskSubType OrbisBgftTaskSubType;

enum _OrbisBgftTaskOpt {
	ORBIS_BGFT_TASK_OPT_NONE = 0x0,
	ORBIS_BGFT_TASK_OPT_DELETE_AFTER_UPLOAD = 0x1,
	ORBIS_BGFT_TASK_OPT_INVISIBLE = 0x2,
	ORBIS_BGFT_TASK_OPT_ENABLE_PLAYGO = 0x4,
	ORBIS_BGFT_TASK_OPT_FORCE_UPDATE = 0x8,
	ORBIS_BGFT_TASK_OPT_REMOTE = 0x10,
	ORBIS_BGFT_TASK_OPT_COPY_CRASH_REPORT_FILES = 0x20,
	ORBIS_BGFT_TASK_OPT_DISABLE_INSERT_POPUP = 0x40,
	ORBIS_BGFT_TASK_OPT_INTERNAL = 0x80, /* ignores release date */
	ORBIS_BGFT_TASK_OPT_DISABLE_CDN_QUERY_PARAM = 0x10000,
};
typedef enum _OrbisBgftTaskOpt OrbisBgftTaskOpt;

struct _OrbisBgftDownloadRegisterErrorInfo {
	/* TODO */
	uint8_t buf[0x100];
};
typedef struct _OrbisBgftDownloadRegisterErrorInfo OrbisBgftDownloadRegisterErrorInfo;

struct _OrbisBgftDownloadParam {
	int32_t userId;
	int32_t entitlementType;
	const char* id; /* max size = 0x30 */
	const char* contentUrl; /* max size = 0x800 */
	const char* contentExUrl;
	const char* contentName; /* max size = 0x259 */
	const char* iconPath; /* max size = 0x800 */
	const char* skuId;
	OrbisBgftTaskOpt option;
	const char* playgoScenarioId;
	const char* releaseDate;
	const char* packageType;
	const char* packageSubType;
	uint32_t packageSize;
};
typedef struct _OrbisBgftDownloadParam OrbisBgftDownloadParam;

struct _OrbisBgftDownloadParamEx {
	OrbisBgftDownloadParam params;
	uint32_t slot;
};
typedef struct _OrbisBgftDownloadParamEx OrbisBgftDownloadParamEx;

struct _OrbisBgftDownloadTaskInfo {
	char* contentTitle;
	char* iconPath;
	uint32_t notificationUtcTick;
};
typedef struct _OrbisBgftDownloadTaskInfo OrbisBgftDownloadTaskInfo;

struct _OrbisBgftTaskProgress {
	uint32_t bits;
	int32_t errorResult;
	uint32_t length;
	uint32_t transferred;
	uint32_t lengthTotal;
	uint32_t transferredTotal;
	uint32_t numIndex;
	uint32_t numTotal;
	uint32_t restSec;
	uint32_t restSecTotal;
	int32_t preparingPercent;
	int32_t localCopyPercent;
};
typedef struct _OrbisBgftTaskProgress OrbisBgftTaskProgress;
