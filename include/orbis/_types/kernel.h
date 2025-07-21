#pragma once

#include <stdint.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef MAP_TYPE
	#define MAP_TYPE 0x0f
#endif

// https://github.com/red-prig/fpPS4/blob/441da1d04080615326e5f55ef6fa3110e642bff6/kernel/ps4_queue.pas#L14
#define EVFILT_READ -1
#define EVFILT_WRITE -2
#define EVFILT_AIO -3	 // attached to aio requests
#define EVFILT_VNODE -4	 // attached to vnodes
#define EVFILT_PROC -5	 // attached to struct proc
#define EVFILT_SIGNAL -6 // attached to struct proc
#define EVFILT_TIMER -7	 // timers
#define EVFILT_FS -9	 // filesystem events
#define EVFILT_LIO -10	 // attached to lio requests
#define EVFILT_USER -11	 // User events
#define EVFILT_POLLING -12
#define EVFILT_DISPLAY -13
#define EVFILT_GRAPHICS_CORE -14
#define EVFILT_HRTIMER -15
#define EVFILT_UVD_TRAP -16
#define EVFILT_VCE_TRAP -17
#define EVFILT_SDMA_TRAP -18
#define EVFILT_REG_EV -19
#define EVFILT_GPU_EXCEPTION -20
#define EVFILT_GPU_SYSTEM_EXCEPTION -21
#define EVFILT_GPU_DBGGC_EV -22
#define EVFILT_SYSCOUNT 22
// actions
#define EV_ADD 0x0001	  // add event to kq (implies enable)
#define EV_DELETE 0x0002  // delete event from kq
#define EV_ENABLE 0x0004  // enable event
#define EV_DISABLE 0x0008 // disable event (not reported)

// flags
#define EV_ONESHOT 0x0010  // only report one occurrence
#define EV_CLEAR 0x0020	   // clear event state after reporting
#define EV_RECEIPT 0x0040  // force EV_ERROR on success, data=0
#define EV_DISPATCH 0x0080 // disable event after reporting

#define EV_SYSFLAGS 0xF000 // reserved by system
#define EV_FLAG1 0x2000	   // filter-specific flag

// returned values
#define EV_EOF 0x8000	// EOF detected
#define EV_ERROR 0x4000 // error, data contains errno

#define NOTE_DELETE 0x0001 // vnode was removed
#define NOTE_WRITE 0x0002  // data contents changed
#define NOTE_EXTEND 0x0004 // size increased
#define NOTE_ATTRIB 0x0008 // attributes changed
#define NOTE_LINK 0x0010   // link count changed
#define NOTE_RENAME 0x0020 // vnode was renamed
#define NOTE_REVOKE 0x0040 // vnode access was revoked

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

// https://github.com/freebsd/freebsd-src/blob/eec2228f5545242471ebda48e26e79eb85156ee5/sys/vm/vm.h#L73
typedef unsigned char vm_prot_t; // freebsd protection codes

#define VM_PROT_NONE ((vm_prot_t)0x00)
#define VM_PROT_READ ((vm_prot_t)0x01)
#define VM_PROT_WRITE ((vm_prot_t)0x02)
#define VM_PROT_EXECUTE ((vm_prot_t)0x04)
#define VM_PROT_COPY ((vm_prot_t)0x08) // copy-on-read

#define VM_PROT_ALL (VM_PROT_READ | VM_PROT_WRITE | VM_PROT_EXECUTE)
#define VM_PROT_RW (VM_PROT_READ | VM_PROT_WRITE)
#define VM_PROT_DEFAULT VM_PROT_ALL

#define ORBIS_KERNEL_PROT_CPU_NONE VM_PROT_NONE
#define ORBIS_KERNEL_PROT_CPU_READ VM_PROT_READ
#define ORBIS_KERNEL_PROT_CPU_WRITE VM_PROT_WRITE
#define ORBIS_KERNEL_PROT_CPU_RW VM_PROT_RW
#define ORBIS_KERNEL_PROT_CPU_EXEC VM_PROT_EXECUTE
#define ORBIS_KERNEL_PROT_CPU_ALL VM_PROT_ALL

#define ORBIS_KERNEL_PROT_GPU_READ 0x10
#define ORBIS_KERNEL_PROT_GPU_WRITE 0x20
#define ORBIS_KERNEL_PROT_GPU_RW (ORBIS_KERNEL_PROT_GPU_READ | ORBIS_KERNEL_PROT_GPU_WRITE)
#define ORBIS_KERNEL_PROT_GPU_ALL ORBIS_KERNEL_PROT_GPU_RW

struct kevent {
	uintptr_t	ident;		/* identifier for this event */
	short		filter;	/* filter for event */
	uint16_t	flags;
	uint32_t	fflags;
	intptr_t	data;
	void		*udata;	/* opaque user data identifier */
};

typedef struct OrbisKernelModuleSegmentInfo
{
    void *address;
    uint32_t size;
    int32_t prot;
} OrbisKernelModuleSegmentInfo;

typedef struct OrbisKernelModuleInfo //352
{
	size_t size;
	char name[256];
	OrbisKernelModuleSegmentInfo segmentInfo[4];
	uint32_t segmentCount;
	uint8_t fingerprint[20];
} OrbisKernelModuleInfo;

typedef struct OrbisKernelModuleInfoEx { //424
	size_t size;
	char name[256];
	int id;
	uint32_t tls_index;
	void* tls_init_addr;
	uint32_t tls_init_size;
	uint32_t tls_size;
	uint32_t tls_offset;
	uint32_t tls_align;
	void* init_proc_addr;
	void* fini_proc_addr;
	uint64_t reserved1;
	uint64_t reserved2;
	void* eh_frame_hdr_addr;
	void* eh_frame_addr;
	uint32_t eh_frame_hdr_size;
	uint32_t eh_frame_size;
	OrbisKernelModuleSegmentInfo segmentInfo[4];
	uint32_t segmentCount;
	uint32_t ref_count;
} OrbisKernelModuleInfoEx;

typedef struct OrbisKernelModuleInfoForUnwind //304
{
	size_t size;
	char name[256];
	void* eh_frame_hdr_addr;
	void* eh_frame_addr;
	uint32_t eh_frame_size;
	uint32_t;
	void* seg0_addr;
	uint64_t seg0_size;
} OrbisKernelModuleInfoForUnwind;

typedef struct _OrbisKernelEventFlagOptParam {
	size_t sz;
} OrbisKernelEventFlagOptParam;

typedef struct timeval OrbisKernelTimeval;
typedef uint32_t OrbisKernelUseconds;
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

typedef uint16_t OrbisKernelMode;

typedef struct OrbisKernelStat {   /* 120 */
    dev_t           st_dev;        /* inode's device */
    ino_t           st_ino;        /* inode's number */
    OrbisKernelMode st_mode;       /* inode protection mode */
    nlink_t         st_nlink;      /* number of hard links */
    uid_t           st_uid;        /* user ID of the file's owner */
    gid_t           st_gid;        /* group ID of the file's group */
    dev_t           st_rdev;       /* device type */
    struct timespec st_atim;       /* time of last access */
    struct timespec st_mtim;       /* time of last data modification */
    struct timespec st_ctim;       /* time of last file status change */
    off_t           st_size;       /* file size, in bytes */
    blkcnt_t        st_blocks;     /* blocks allocated for file */
    blksize_t       st_blksize;    /* optimal blocksize for I/O */
    uint32_t        st_flags;      /* user defined flags for file */
    uint32_t        st_gen;        /* file generation number */
    int32_t         st_lspare;
    struct timespec st_birthtim;   /* time of file creation */
    unsigned int :(8 / 2) * (16 - (int)sizeof(struct timespec));
    unsigned int :(8 / 2) * (16 - (int)sizeof(struct timespec));
} OrbisKernelStat;

typedef struct timespec OrbisKernelTimespec;

typedef struct OrbisKernelIovec {
	void* base;
	size_t len;
} OrbisKernelIovec;

typedef struct {
	void* start_addr;
	void* end_addr;
	off_t offset;
	int32_t prot;
	int32_t mtype;
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
	int32_t reqId;
	int32_t priority;
	int32_t msgId;
	int32_t targetId;
	int32_t userId;
	int32_t unk1;
	int32_t unk2;
	int32_t appId;
	int32_t errorNum;
	int32_t unk3;
	unsigned char useIconImageUri;
	char message[1024];
	char iconUri[1024];
	char unk[1024];
} OrbisNotificationRequest;

typedef struct
{
	int32_t version;
	int32_t;
	uint64_t ids_bits[2];
} OrbisTitleWorkaround;

typedef struct
{
	int32_t  AppId;
	int32_t  mmap_flags;
	int32_t  attributeExe;
	int32_t  AppType;
	char     TitleId[10];
	uint8_t  debug_level;
	uint8_t  slv_flags;
	uint8_t  miniAppDmemFlags;
	uint8_t  render_mode;
	uint8_t  mdbg_out;
	uint8_t  requiredHdcpType;
	uint64_t preloadPrxFlags;
	int32_t  attribute;
	int32_t  hasParamSfo;
	OrbisTitleWorkaround TitleWorkaround;
} OrbisAppInfo;
