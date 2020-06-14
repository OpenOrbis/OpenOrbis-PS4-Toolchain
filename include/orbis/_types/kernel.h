#pragma once

#include <stdint.h>
#include <sys/time.h>
#include <sys/stat.h>

#ifndef MAP_TYPE
	#define MAP_TYPE 0x0f
#endif

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
