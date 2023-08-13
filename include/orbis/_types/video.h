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

typedef enum 
{
    ORBIS_VIDEO_OUT_DEVICE_CAPABILITY_YUV   					 = 1 << 0,
    ORBIS_VIDEO_OUT_DEVICE_CAPABILITY_XVYCC 					 = 1 << 1,
    ORBIS_VIDEO_OUT_DEVICE_CAPABILITY_S3D_FRAME_PACKING_59_94HZ  = 1 << 2,
    ORBIS_VIDEO_OUT_DEVICE_CAPABILITY_VR_VIEW_59_94HZ            = 1 << 4,
    ORBIS_VIDEO_OUT_DEVICE_CAPABILITY_VR_VIEW_119_88HZ           = 1 << 5,
    ORBIS_VIDEO_OUT_DEVICE_CAPABILITY_VR_VIEW_89_91HZ            = 1 << 6,
    ORBIS_VIDEO_OUT_DEVICE_CAPABILITY_BT2020_PQ                  = 1 << 7,
} OrbisVideoOutDeviceCapability;

typedef enum 
{
    ORBIS_VIDEO_OUT_SIGNAL_ENCODING_UNKNOWN = 0,
    ORBIS_VIDEO_OUT_SIGNAL_ENCODING_RGB444  = 1,
    ORBIS_VIDEO_OUT_SIGNAL_ENCODING_YUV444  = 2,
    ORBIS_VIDEO_OUT_SIGNAL_ENCODING_YUV422  = 3,
    ORBIS_VIDEO_OUT_SIGNAL_ENCODING_ANY     = 0xFF,
} OrbisVideoOutSignalEncoding;

typedef enum 
{
    ORBIS_VIDEO_OUT_SIGNAL_RANGE_UNKNOWN = 0,
    ORBIS_VIDEO_OUT_SIGNAL_RANGE_LIMITED = 1,
    ORBIS_VIDEO_OUT_SIGNAL_RANGE_FULL    = 2,
    ORBIS_VIDEO_OUT_SIGNAL_RANGE_ANY     = 0xFF,
} OrbisVideoOutSignalRange;

typedef enum 
{
    ORBIS_VIDEO_OUT_COLORIMETRY_UNKNOWN   	 = 0,
    ORBIS_VIDEO_OUT_COLORIMETRY_SRGB      	 = 1,
    ORBIS_VIDEO_OUT_COLORIMETRY_CERGB     	 = 2,
    ORBIS_VIDEO_OUT_COLORIMETRY_YCBCR     	 = 3,
    ORBIS_VIDEO_OUT_COLORIMETRY_YCBCR601  	 = 4,
    ORBIS_VIDEO_OUT_COLORIMETRY_YCBCR709  	 = 5,
    ORBIS_VIDEO_OUT_COLORIMETRY_XVYCC     	 = 6,
    ORBIS_VIDEO_OUT_COLORIMETRY_XVYCC601  	 = 7,
    ORBIS_VIDEO_OUT_COLORIMETRY_XVYCC709  	 = 8,
    ORBIS_VIDEO_OUT_COLORIMETRY_BT2020       = 9,
    ORBIS_VIDEO_OUT_COLORIMETRY_RGB2020      = 10,
    ORBIS_VIDEO_OUT_COLORIMETRY_YCBCR2020    = 11,
    ORBIS_VIDEO_OUT_COLORIMETRY_BT2020_PQ    = 12,
    ORBIS_VIDEO_OUT_COLORIMETRY_RGB2020_PQ   = 13,
    ORBIS_VIDEO_OUT_COLORIMETRY_YCBCR2020_PQ = 14,
    ORBIS_VIDEO_OUT_COLORIMETRY_ANY       	 = 0xFF,
} OrbisVideoOutColorimetry;

typedef enum 
{
    ORBIS_VIDEO_OUT_COLOR_DEPTH_UNKNOWN = 0,
    ORBIS_VIDEO_OUT_COLOR_DEPTH_24BPP   = 24,
    ORBIS_VIDEO_OUT_COLOR_DEPTH_30BPP   = 30,
    ORBIS_VIDEO_OUT_COLOR_DEPTH_36BPP   = 36,
    ORBIS_VIDEO_OUT_COLOR_DEPTH_ANY     = 0xFF,
} OrbisVideoOutColorDepth;

typedef enum
{
    ORBIS_VIDEO_OUT_RESOLUTION_UNKNOWN         		   = 0,
    ORBIS_VIDEO_OUT_RESOLUTION_480I            		   = 1,
    ORBIS_VIDEO_OUT_RESOLUTION_480I_WIDESCREEN 		   = 2,
    ORBIS_VIDEO_OUT_RESOLUTION_576I            		   = 3,
    ORBIS_VIDEO_OUT_RESOLUTION_576I_WIDESCREEN 		   = 4,
    ORBIS_VIDEO_OUT_RESOLUTION_480P            		   = 5,
    ORBIS_VIDEO_OUT_RESOLUTION_480P_WIDESCREEN 		   = 6,
    ORBIS_VIDEO_OUT_RESOLUTION_576P            		   = 7,
    ORBIS_VIDEO_OUT_RESOLUTION_576P_WIDESCREEN 		   = 8,
    ORBIS_VIDEO_OUT_RESOLUTION_720P            		   = 9,
    ORBIS_VIDEO_OUT_RESOLUTION_1080I           		   = 10,
    ORBIS_VIDEO_OUT_RESOLUTION_1080P           		   = 11,
    ORBIS_VIDEO_OUT_RESOLUTION_720P_S3D_FRAME_PACKING  = 0xA0,
    ORBIS_VIDEO_OUT_RESOLUTION_1080P_VR_VIEW  		   = 0xE1,
    ORBIS_VIDEO_OUT_RESOLUTION_ANY_S3D       		   = 0xFFFFFFFF81FFFFFFull,
    ORBIS_VIDEO_OUT_RESOLUTION_ANY_VR_VIEW   		   = 0xFFFFFFFFC1FFFFFFull,
    ORBIS_VIDEO_OUT_RESOLUTION_ANY           		   = 0xFFFFFFFFFFFFFFFFull,
} OrbisVideoOutResolution;

typedef enum 
{
    ORBIS_VIDEO_OUT_REFRESH_RATE_UNKNOWN = 0,
    ORBIS_VIDEO_OUT_REFRESH_RATE_23_98HZ = 1,
    ORBIS_VIDEO_OUT_REFRESH_RATE_50HZ    = 2,
    ORBIS_VIDEO_OUT_REFRESH_RATE_59_94HZ = 3,
    ORBIS_VIDEO_OUT_REFRESH_RATE_29_97HZ = 6,

    // VR
    ORBIS_VIDEO_OUT_REFRESH_RATE_89_91HZ  = 35,
    ORBIS_VIDEO_OUT_REFRESH_RATE_119_88HZ = 13,
    ORBIS_VIDEO_OUT_REFRESH_RATE_ANY      = 0xFFFFFFFFFFFFFFFFull,
} OrbisVideoOutRefreshRate;

typedef enum 
{
	ORBIS_VIDEO_OUT_CONTENT_TYPE_UNKNOWN  = 0,
	ORBIS_VIDEO_OUT_CONTENT_TYPE_GRAPHICS = 1,
	ORBIS_VIDEO_OUT_CONTENT_TYPE_PHOTO    = 2,
	ORBIS_VIDEO_OUT_CONTENT_TYPE_CINEMA   = 3,
	ORBIS_VIDEO_OUT_CONTENT_TYPE_GAME     = 4,
	ORBIS_VIDEO_OUT_CONTENT_TYPE_ANY      = 0xFF,
} OrbisVideoOutContentType;

typedef enum
{
    SCE_VIDEO_OUT_VR_VIEW_CROP_VERTICAL_OFFSET_MIN     =  0,
    SCE_VIDEO_OUT_VR_VIEW_CROP_VERTICAL_OFFSET_NEUTRAL =  0,
    SCE_VIDEO_OUT_VR_VIEW_CROP_VERTICAL_OFFSET_MAX     = 28,
} OrbisVideoOutVRVerticalOffset;

// Struct Credits - psxdev
typedef struct OrbisVideoOutBufferAttribute 
{
	int32_t format;
	int32_t tmode;
	int32_t aspect;
	uint32_t width;
	uint32_t height;
	uint32_t pixelPitch;
	uint64_t reserved[2];
} OrbisVideoOutBufferAttribute;

// Struct Credits - psxdev
typedef struct OrbisVideoOutFlipStatus 
{
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
typedef struct OrbisVideoOutResolutionStatus 
{
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

typedef struct OrbisVideoOutMode
{
    uint32_t   size;				      // = sizeof(OrbisVideoOutMode);
    uint8_t    signalEncoding;		// = OrbisVideoOutSignalEncoding
    uint8_t    signalRange;			  // = OrbisVideoOutSignalRange
    uint8_t    colorimetry;			  // = OrbisVideoOutColorimetry
    uint8_t    depth;				      // = OrbisVideoOutColorDepth
    uint64_t   refreshRate;			  // = OrbisVideoOutRefreshRate
    uint64_t   resolution;			  // = OrbisVideoOutResolution
    uint8_t    contentType;			  // = OrbisVideoOutContentType
    uint8_t    reserved[3];
    uint32_t   reserved2[1];
} OrbisVideoOutMode;

typedef struct OrbisVideoOutDeviceCapabilityInfo 
{
    uint64_t capability;			// = OrbisVideoOutDeviceCapability
} OrbisVideoOutDeviceCapabilityInfo;

typedef struct OrbisVideoOutVrViewCropAdjustment 
{
    int16_t verticalOffset;
    int16_t reserved;
    int32_t reserved2[3];
} OrbisVideoOutVrViewCropAdjustment;

typedef struct OrbisVideoOutConfigureOptions 
{
    OrbisVideoOutVrViewCropAdjustment vrViewCropAdjustment;
} OrbisVideoOutConfigureOptions;
