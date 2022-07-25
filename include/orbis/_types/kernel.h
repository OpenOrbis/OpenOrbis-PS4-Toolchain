#pragma once

#include <stdint.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef MAP_TYPE
	#define MAP_TYPE 0x0f
#endif

#define ORBIS_KERNEL_EVFILT_TIMER    EVFILT_TIMER
#define ORBIS_KERNEL_EVFILT_READ     EVFILT_READ
#define ORBIS_KERNEL_EVFILT_WRITE    EVFILT_WRITE
#define ORBIS_KERNEL_EVFILT_USER     EVFILT_USER
#define ORBIS_KERNEL_EVFILT_FILE     EVFILT_VNODE
#define ORBIS_KERNEL_EVFILT_GNM      EVFILT_GRAPHICS_CORE
#define ORBIS_KERNEL_EVFILT_VIDEO_OUT      EVFILT_DISPLAY
#define ORBIS_KERNEL_EVFILT_HRTIMER  EVFILT_HRTIMER

#define ORBIS_KERNEL_EVNOTE_DELETE   NOTE_DELETE
#define ORBIS_KERNEL_EVNOTE_WRITE    NOTE_WRITE
#define ORBIS_KERNEL_EVNOTE_EXTEND   NOTE_EXTEND
#define ORBIS_KERNEL_EVNOTE_ATTRIB   NOTE_ATTRIB
#define ORBIS_KERNEL_EVNOTE_RENAME   NOTE_RENAME
#define ORBIS_KERNEL_EVNOTE_REVOKE   NOTE_REVOKE

#define ORBIS_KERNEL_EVFLAG_EOF       EV_EOF
#define ORBIS_KERNEL_EVFLAG_ERROR     EV_ERROR

#define ORBIS_KERNEL_EVF_ATTR_TH_FIFO   0x01
#define ORBIS_KERNEL_EVF_ATTR_TH_PRIO   0x02
#define ORBIS_KERNEL_EVF_ATTR_SINGLE    0x10
#define ORBIS_KERNEL_EVF_ATTR_MULTI     0x20
#define ORBIS_KERNEL_EVF_WAITMODE_AND        0x01
#define ORBIS_KERNEL_EVF_WAITMODE_OR         0x02
#define ORBIS_KERNEL_EVF_WAITMODE_CLEAR_ALL  0x10
#define ORBIS_KERNEL_EVF_WAITMODE_CLEAR_PAT  0x20

#define ORBIS_KERNEL_SEMA_ATTR_TH_FIFO   0x01
#define ORBIS_KERNEL_SEMA_ATTR_TH_PRIO   0x02

#define ORBIS_KERNEL_MAIN_DMEM_SIZE 0x180000000u

#define ORBIS_KERNEL_WB_ONION  0x0
#define ORBIS_KERNEL_WC_GARLIC 0x3
#define ORBIS_KERNEL_WB_GARLIC 0xA

#define ORBIS_KERNEL_PROT_CPU_READ 0x01
#define ORBIS_KERNEL_PROT_CPU_WRITE 0x02
#define ORBIS_KERNEL_PROT_CPU_RW (ORBIS_KERNEL_PROT_CPU_READ | ORBIS_KERNEL_PROT_CPU_WRITE)
#define ORBIS_KERNEL_PROT_CPU_EXEC 0x04
#define ORBIS_KERNEL_PROT_CPU_ALL (ORBIS_KERNEL_PROT_CPU_RW | ORBIS_KERNEL_PROT_CPU_EXEC)

#define ORBIS_KERNEL_PROT_GPU_READ 0x10
#define ORBIS_KERNEL_PROT_GPU_WRITE 0x20
#define ORBIS_KERNEL_PROT_GPU_RW (ORBIS_KERNEL_PROT_GPU_READ | ORBIS_KERNEL_PROT_GPU_WRITE)
#define ORBIS_KERNEL_PROT_GPU_ALL ORBIS_KERNEL_PROT_GPU_RW

struct kevent {
	uintptr_t	ident;		/* identifier for this event */
	short		filter;	/* filter for event */
	u_short	flags;
	u_int		fflags;
	intptr_t	data;
	void		*udata;	/* opaque user data identifier */
};

typedef struct OrbisKernelModuleSegmentInfo
{
    void *address;
    uint32_t size;
    int32_t prot;
} OrbisKernelModuleSegmentInfo;

typedef struct OrbisKernelModuleInfo
{
	size_t size;
	char name[256];
	OrbisKernelModuleSegmentInfo segmentInfo[4];
	uint32_t segmentCount;
	uint8_t fingerprint[20];
} OrbisKernelModuleInfo;

typedef struct _OrbisKernelEventFlagOptParam {
	size_t sz;
} OrbisKernelEventFlagOptParam;

typedef struct timeval OrbisKernelTimeval;
typedef unsigned int OrbisKernelUseconds;
typedef uint32_t OrbisKernelModule;

typedef uint64_t OrbisKernelEqueue;
typedef struct kevent OrbisKernelEvent;
typedef struct _OrbisKernelEventFlag* OrbisKernelEventFlag;

typedef struct _OrbisKernelSemaOptParam {
	size_t sz;
} OrbisKernelSemaOptParam;

typedef struct _OrbisKernelSema* OrbisKernelSema;

typedef struct {
	uint32_t    unk01;
	uint16_t    unk02;
	uint16_t    unk03;
	uint8_t     unk04;
	uint8_t     unk05;
	uint8_t     unk06[6];
} OrbisKernelUuid;

typedef mode_t OrbisKernelMode;
typedef struct stat OrbisKernelStat;

typedef struct timespec OrbisKernelTimespec;

typedef struct OrbisKernelIovec {
	void* base;
	size_t len;
} OrbisKernelIovec;

typedef struct {
	void* unk01;
	void* unk02;
	off_t offset;
	int unk04;
	int unk05;
	unsigned isFlexibleMemory : 1;
	unsigned isDirectMemory : 1;
	unsigned isStack : 1;
	unsigned isPooledMemory : 1;
	unsigned isCommitted : 1;
	char name[32];
} OrbisKernelVirtualQueryInfo;

typedef struct {
    size_t Size;                // 0x0
    char VersionString[0x1C];   // 0x8 (e.g. " 6.720.001" padded with leading zeros)
    uint32_t Version;           // 0xe.g. 0x06720001
} OrbisKernelSwVersion;
// size = 0x28

// Enum Credits - OSM-Made
enum OrbisNotificationRequestType
{
	NotificationRequest = 0,
	SystemNotification = 1,
	SystemNotificationWithUserId = 2,
	SystemNotificationWithDeviceId = 3,
	SystemNotificationWithDeviceIdRelatedToUser = 4,
	SystemNotificationWithText = 5,
	SystemNotificationWithTextRelatedToUser = 6,
	SystemNotificationWithErrorCode = 7,
	SystemNotificationWithAppId = 8,
	SystemNotificationWithAppName = 9,
	SystemNotificationWithAppInfo = 9,
	SystemNotificationWithAppNameRelatedToUser = 10,
	SystemNotificationWithParams = 11,
	SendSystemNotificationWithUserName = 12,
	SystemNotificationWithUserNameInfo = 13,
	SendAddressingSystemNotification = 14,
	AddressingSystemNotificationWithDeviceId = 15,
	AddressingSystemNotificationWithUserName = 16,
	AddressingSystemNotificationWithUserId = 17,

	UNK_1 = 100,
	TrcCheckNotificationRequest = 101,
	NpDebugNotificationRequest = 102,
	UNK_2 = 102,
};

// Struct Credits - OSM-Made
typedef struct
{
	enum OrbisNotificationRequestType type;
	int reqId;
	int priority;
	int msgId;
	int targetId;
	int userId;
	int unk1;
	int unk2;
	int appId;
	int errorNum;
	int unk3;
	unsigned char useIconImageUri;
	char message[1024];
	char iconUri[1024];
	char unk[1024];
} OrbisNotificationRequest;
