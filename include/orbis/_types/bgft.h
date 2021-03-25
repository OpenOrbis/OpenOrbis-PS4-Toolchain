#pragma once

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
	int userId;
	int entitlementType;
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
	unsigned long packageSize;
};
typedef struct _OrbisBgftDownloadParam OrbisBgftDownloadParam;

struct _OrbisBgftDownloadParamEx {
	OrbisBgftDownloadParam params;
	unsigned int slot;
};
typedef struct _OrbisBgftDownloadParamEx OrbisBgftDownloadParamEx;

struct _OrbisBgftDownloadTaskInfo {
	char* contentTitle;
	char* iconPath;
	unsigned long notificationUtcTick;
};
typedef struct _OrbisBgftDownloadTaskInfo OrbisBgftDownloadTaskInfo;

struct _OrbisBgftTaskProgress {
	unsigned int bits;
	int errorResult;
	unsigned long length;
	unsigned long transferred;
	unsigned long lengthTotal;
	unsigned long transferredTotal;
	unsigned int numIndex;
	unsigned int numTotal;
	unsigned int restSec;
	unsigned int restSecTotal;
	int preparingPercent;
	int localCopyPercent;
};
typedef struct _OrbisBgftTaskProgress OrbisBgftTaskProgress;