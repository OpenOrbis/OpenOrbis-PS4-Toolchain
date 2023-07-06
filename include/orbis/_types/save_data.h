#include <inttypes.h>
#include <stdint.h>
#include <time.h> // time_t
#pragma once

#define ORBIS_SAVE_DATA_MOUNT_MODE_RDONLY			1		//Read-only
#define ORBIS_SAVE_DATA_MOUNT_MODE_RDWR				2		//Read/write-enabled
#define ORBIS_SAVE_DATA_MOUNT_MODE_CREATE			4		//Create new (error if save data directory already exists)
#define ORBIS_SAVE_DATA_MOUNT_MODE_DESTRUCT_OFF		8		//Turn off corrupt flag (not recommended)
#define ORBIS_SAVE_DATA_MOUNT_MODE_COPY_ICON		16		//Copy save_data.png in package as icon when newly creating save data
#define ORBIS_SAVE_DATA_MOUNT_MODE_CREATE2			32		//Create new (mount save data directory if it already exists)

#define ORBIS_SAVE_DATA_PARAM_TYPE_ALL				0		//Update all parameters
#define ORBIS_SAVE_DATA_PARAM_TYPE_TITLE			1		//Update save data title only
#define ORBIS_SAVE_DATA_PARAM_TYPE_SUB_TITLE		2		//Update save data subtitle only
#define ORBIS_SAVE_DATA_PARAM_TYPE_DETAIL			3		//Update save data detailed information only
#define ORBIS_SAVE_DATA_PARAM_TYPE_USER_PARAM		4		//Update user parameter only

#define ORBIS_SAVE_DATA_MOUNT_MAX_COUNT				16			//Maximum number of instances of save data that can be mounted simultaneously
#define ORBIS_SAVE_DATA_DIRNAME_MAX_COUNT			1024		//Maximum number of save data directories
#define ORBIS_SAVE_DATA_ICON_WIDTH					228			//Icon width
#define ORBIS_SAVE_DATA_ICON_HEIGHT					128			//Icon height
#define ORBIS_SAVE_DATA_ICON_FILE_MAXSIZE			116736		//Maximum size for an icon file
#define ORBIS_SAVE_DATA_BLOCK_SIZE					32768		//Block size (bytes)
#define ORBIS_SAVE_DATA_BLOCKS_MIN2					96			//Minimum number of blocks
#define ORBIS_SAVE_DATA_BLOCKS_MAX 					32768		//Maximum number of blocks
#define ORBIS_SAVE_DATA_MEMORY_MAXSIZE3				33554432	//Maximum size for the data sections of the save data memory (maximum value for the total save data memory size of all users)
#define ORBIS_SAVE_DATA_MEMORY_SETUP_MAX_COUNT		4			//Maximum number of instances of save data memory that can be set up simultaneously
#define ORBIS_SAVE_DATA_MEMORY_DATANUM_MAX_COUNT	5			//Maximum number of data that can be specified at the same time to the data sections of the save data memory

#define ORBIS_SAVE_DATA_TITLE_ID_DATA_SIZE			10			//Save data title ID size
#define ORBIS_SAVE_DATA_DIRNAME_DATA_MAXSIZE		32			//Maximum size for a save data directory name
#define ORBIS_SAVE_DATA_MOUNT_POINT_DATA_MAXSIZE	16			//Maximum size for a mount point name
#define ORBIS_SAVE_DATA_FINGERPRINT_DATA_SIZE		65			//Fingerprint size
#define ORBIS_SAVE_DATA_TITLE_MAXSIZE				128			//Maximum size for a save data title name (NULL-terminated, UTF-8)
#define ORBIS_SAVE_DATA_SUBTITLE_MAXSIZE			128			//Maximum size for a save data subtitle name (NULL-terminated, UTF-8)
#define ORBIS_SAVE_DATA_DETAIL_MAXSIZE				1024		//Maximum size for save data detailed information (NULL-terminated, UTF-8)


typedef uint32_t OrbisSaveDataSortKey;
typedef uint32_t OrbisSaveDataSortOrder;
typedef uint64_t OrbisSaveDataBlocks;

typedef struct OrbisSaveDataFingerprint {
	char data[ORBIS_SAVE_DATA_FINGERPRINT_DATA_SIZE];
	char padding[15];
} OrbisSaveDataFingerprint;

typedef struct OrbisSaveDataDirName {
	char data[ORBIS_SAVE_DATA_DIRNAME_DATA_MAXSIZE];
} OrbisSaveDataDirName;

typedef struct OrbisSaveDataTitleId {
	char data[ORBIS_SAVE_DATA_TITLE_ID_DATA_SIZE];
	char padding[6];
} OrbisSaveDataTitleId;

typedef struct OrbisSaveDataMountPoint {
    char data[ORBIS_SAVE_DATA_MOUNT_POINT_DATA_MAXSIZE];
} OrbisSaveDataMountPoint;

typedef struct OrbisSaveDataMountInfo {
	uint64_t blocks;
	uint64_t freeBlocks;
	uint8_t reserved[32];
} OrbisSaveDataMountInfo;

typedef struct __attribute__((packed)) OrbisSaveDataMount
{
	int32_t userId;
	int32_t unknown1;
	const char *titleId;
	const char *dirName;
	const char *fingerprint;
	uint64_t blocks;
	uint32_t mountMode;
	uint8_t reserved[36];
} OrbisSaveDataMount;

typedef struct __attribute__((packed)) OrbisSaveDataMountResult
{
	char mountPathName[ORBIS_SAVE_DATA_MOUNT_POINT_DATA_MAXSIZE];
	uint64_t requiredBlocks;
	uint32_t progress;
	uint8_t reserved[32];
} OrbisSaveDataMountResult;

typedef struct OrbisSaveDataDelete
{
	int32_t userId;
	int32_t unknown1; 
	const OrbisSaveDataTitleId *titleId;
	const OrbisSaveDataDirName *dirName;
	uint32_t unused;
	uint8_t reserved[32];
	int32_t unknown2;
} OrbisSaveDataDelete;

typedef struct __attribute__((packed)) OrbisSaveDataParam
{
    char title[ORBIS_SAVE_DATA_TITLE_MAXSIZE];
    char subtitle[ORBIS_SAVE_DATA_SUBTITLE_MAXSIZE];
    char details[ORBIS_SAVE_DATA_DETAIL_MAXSIZE];
    uint32_t userParam;
    uint32_t unknown1;
    time_t mtime;
    char unknown2[0x20];
} OrbisSaveDataParam;

typedef struct OrbisSaveDataMount2 {
	int32_t userId;
	uint32_t unk1;
	const OrbisSaveDataDirName *dirName;
	uint64_t blocks;
	uint32_t mountMode;
	uint8_t reserved[32];
	uint32_t unk2;
} OrbisSaveDataMount2;

typedef struct OrbisSaveDataIcon {
	void *buf;
	size_t bufSize;
	size_t dataSize;
	uint8_t reserved[32];
} OrbisSaveDataIcon;

typedef struct OrbisSaveDataDirNameSearchCond {
	int32_t userId;
	int :32;
	const OrbisSaveDataTitleId *titleId;
	const OrbisSaveDataDirName *dirName;
	OrbisSaveDataSortKey key;
	OrbisSaveDataSortOrder order;
	uint8_t reserved[32];
} OrbisSaveDataDirNameSearchCond;

typedef struct OrbisSaveDataSearchInfo {
	OrbisSaveDataBlocks blocks;
	OrbisSaveDataBlocks freeBlocks;
	uint8_t reserved[32];
} OrbisSaveDataSearchInfo;

typedef struct OrbisSaveDataDirNameSearchResult {
	uint32_t hitNum;
	int :32;
	OrbisSaveDataDirName *dirNames;
	uint32_t dirNamesNum;
	uint32_t setNum;
	OrbisSaveDataParam *params;
	OrbisSaveDataSearchInfo *infos;
	uint8_t reserved[12];
	int :32;
} OrbisSaveDataDirNameSearchResult;

