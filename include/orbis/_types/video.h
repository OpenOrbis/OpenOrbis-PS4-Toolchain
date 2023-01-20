#pragma once

#include <stdint.h>

#define ORBIS_VIDEO_USER_MAIN		0xFF

#define ORBIS_VIDEO_OUT_BUS_MAIN	0
#define ORBIS_VIDEO_OUT_BUS_SOCIAL	5
#define ORBIS_VIDEO_OUT_BUS_LIVE	6

typedef enum OrbisFlipType : int32_t
{
	ORBIS_VIDEO_OUT_FLIP_VSYNC = 1,
	ORBIS_VIDEO_OUT_FLIP_HSYNC = 2,
} OrbisFlipType;

typedef enum OrbisFlipRate : int32_t
{
	ORBIS_VIDEO_OUT_FLIP_60HZ = 0,
	ORBIS_VIDEO_OUT_FLIP_30HZ = 1,
	ORBIS_VIDEO_OUT_FLIP_20HZ = 2,
} OrbisFlipRate;

typedef enum OrbisVideoOutTilingMode {
	ORBIS_VIDEO_OUT_TILING_MODE_TILE = 0x0,
	ORBIS_VIDEO_OUT_TILING_MODE_LINEAR = 0x1,
} OrbisVideoOutTilingMode;

typedef enum OrbisVideoOutAspectRatio {
	ORBIS_VIDEO_OUT_ASPECT_RATIO_16_9 = 0x0,
} OrbisVideoOutAspectRatio;

#define ORBIS_VIDEO_OUT_PIXEL_FORMAT_A8B8G8R8_SRGB 0x80002200

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

// Struct Credits - Inori
typedef struct OrbisVideoOutResolutionStatus {
	uint32_t width;
	uint32_t height;
	uint32_t paneWidth;
	uint32_t paneHeight;
	uint64_t refreshRate;
	float screenSize;
	uint16_t flags;
	uint16_t reserved0;
	uint32_t reserved1[3];
} OrbisVideoOutResolutionStatus;
