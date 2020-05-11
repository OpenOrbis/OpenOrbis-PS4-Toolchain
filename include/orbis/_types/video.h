#pragma once

#include <stdint.h>

// Struct Credits - psxdev
typedef struct OrbisVideoOutBufferAttribute {
	int32_t format;
	int32_t tmode;
	int32_t aspect;
	uint32_t width;
	uint32_t height;
	uint32_t pixelPitch;
	uint64_t reserved[2];
} OrbisVideoOutBufferAttribute;

// Struct Credits - psxdev
typedef struct OrbisVideoOutFlipStatus {
	uint64_t num;
	uint64_t ptime;
	uint64_t stime;
	int64_t flipArg;
	uint64_t reserved[2];
	int32_t numGpuFlipPending;
	int32_t numFlipPending;
	int32_t currentBuffer;
	uint32_t reserved1;
} OrbisVideoOutFlipStatus;