#pragma once
#include <stdint.h>

#define ORBIS_VIDEODEC_ERROR_API_FAIL				        -2134835200	// = 0x80C10000
#define ORBIS_VIDEODEC_ERROR_CODEC_TYPE			        -2134835199	// = 0x80C10001
#define ORBIS_VIDEODEC_ERROR_STRUCT_SIZE			      -2134835198	// = 0x80C10002
#define ORBIS_VIDEODEC_ERROR_HANDLE				          -2134835197	// = 0x80C10003
#define ORBIS_VIDEODEC_ERROR_CPU_MEMORY_SIZE		    -2134835196	// = 0x80C10004
#define ORBIS_VIDEODEC_ERROR_CPU_MEMORY_POINTER	    -2134835195	// = 0x80C10005
#define ORBIS_VIDEODEC_ERROR_CPU_GPU_MEMORY_SIZE	  -2134835194	// = 0x80C10006
#define ORBIS_VIDEODEC_ERROR_CPU_GPU_MEMORY_POINTER -2134835193	// = 0x80C10007
#define ORBIS_VIDEODEC_ERROR_SHADER_CONTEXT_POINTER -2134835192	// = 0x80C10008
#define ORBIS_VIDEODEC_ERROR_AU_SIZE				        -2134835191	// = 0x80C10009
#define ORBIS_VIDEODEC_ERROR_AU_POINTER			        -2134835190	// = 0x80C1000A
#define ORBIS_VIDEODEC_ERROR_FRAME_BUFFER_SIZE	    -2134835189	// = 0x80C1000B
#define ORBIS_VIDEODEC_ERROR_FRAME_BUFFER_POINTER	  -2134835188	// = 0x80C1000C
#define ORBIS_VIDEODEC_ERROR_FRAME_BUFFER_ALIGNMENT -2134835187	// = 0x80C1000D
#define ORBIS_VIDEODEC_ERROR_CONFIG_INFO			      -2134835186	// = 0x80C1000E
#define ORBIS_VIDEODEC_ERROR_ARGUMENT_POINTER		    -2134835185	// = 0x80C1000F
#define ORBIS_VIDEODEC_ERROR_NEW_SEQUENCE		        -2134835184	// = 0x80C10010
#define ORBIS_VIDEODEC_ERROR_DECODE_AU		          -2134835183	// = 0x80C10011
#define ORBIS_VIDEODEC_ERROR_MISMATCH_SPEC		      -2134835182 // = 0x80C10012
#define ORBIS_VIDEODEC_ERROR_INVALID_SEQUENCE		    -2134835181	// = 0x80C10013
#define ORBIS_VIDEODEC_ERROR_FATAL_STREAM		        -2134835180	// = 0x80C10014
#define ORBIS_VIDEODEC_ERROR_FATAL_STATE		        -2134835179	// = 0x80C10015

#define ORBIS_VIDEODEC_CODEC_TYPE_AVC                 (0)
#define ORBIS_VIDEODEC_TIMESTAMP_INVALID              (0xffffffffffffffffULL)
#define ORBIS_VIDEODEC_FLAG_DEFAULT                   (0ULL)
#define ORBIS_VIDEODEC_FLAG_DISABLE_ONE_FRAME_DELAY   (0x5A0000ULL)
#define ORBIS_VIDEODEC_AVC_PROFILE_BASELINE           (66)
#define ORBIS_VIDEODEC_AVC_PROFILE_MAIN               (77)
#define ORBIS_VIDEODEC_AVC_PROFILE_HIGH               (100)
#define ORBIS_VIDEODEC_AVC_LEVEL_1                    (10)
#define ORBIS_VIDEODEC_AVC_LEVEL_1_b                  (111)
#define ORBIS_VIDEODEC_AVC_LEVEL_1_1                  (11)
#define ORBIS_VIDEODEC_AVC_LEVEL_1_2                  (12)
#define ORBIS_VIDEODEC_AVC_LEVEL_1_3                  (13)
#define ORBIS_VIDEODEC_AVC_LEVEL_2                    (20)
#define ORBIS_VIDEODEC_AVC_LEVEL_2_1                  (21)
#define ORBIS_VIDEODEC_AVC_LEVEL_2_2                  (22)
#define ORBIS_VIDEODEC_AVC_LEVEL_3                    (30)
#define ORBIS_VIDEODEC_AVC_LEVEL_3_1                  (31)
#define ORBIS_VIDEODEC_AVC_LEVEL_3_2                  (32)
#define ORBIS_VIDEODEC_AVC_LEVEL_4                    (40)
#define ORBIS_VIDEODEC_AVC_LEVEL_4_1                  (41)
#define ORBIS_VIDEODEC_AVC_LEVEL_4_2                  (42)
#define ORBIS_VIDEODEC_AVC_LEVEL_5                    (50)
#define ORBIS_VIDEODEC_AVC_LEVEL_5_1                  (51)

typedef struct OrbisVideodecCtrl 
{
  size_t    thisSize; // = sizeof(OrbisVideodecCtrl)
  uintptr_t handle;
  uint64_t  version;
} OrbisVideodecCtrl;

typedef struct OrbisVideodecConfigInfo 
{
  size_t    thisSize;   // = sizeof(OrbisVideodecConfigInfo)
  uint32_t  codecType;
  uint32_t  profile;
  uint32_t  maxLevel;
  int32_t   maxFrameWidth;
  int32_t   maxFrameHeight;
  int32_t   maxDpbFrameCount;
  uint64_t  videodecFlags;
} OrbisVideodecConfigInfo;

typedef struct OrbisVideodecResourceInfo 
{
  size_t    thisSize; // = sizeof(OrbisVideodecResourceInfo)
  size_t    cpuMemorySize;
  void*     pCpuMemory;
  size_t    cpuGpuMemorySize;
  void*     pCpuGpuMemory;
  size_t    maxFrameBufferSize;
  uint32_t  frameBufferAlignment;
} OrbisVideodecResourceInfo;

typedef struct OrbisVideodecInputData 
{
  size_t   thisSize; // sizeof(OrbisVideodecInputData)
  void*    pAuData;
  size_t   auSize;
  uint64_t ptsData;
  uint64_t dtsData;
  uint64_t attachedData;
} OrbisVideodecInputData;

typedef struct OrbisVideodecAvcInfo 
{
  uint32_t  numUnitsInTick;
  uint32_t  timeScale;
  uint8_t   fixedFrameRateFlag;
  uint8_t   aspectRatioIdc;
  uint16_t  sarWidth;
  uint16_t  sarHeight;
  uint8_t   colourPrimaries;
  uint8_t   transferCharacteristics;
  uint8_t   matrixCoefficients;
  uint8_t   videoFullRangeFlag;
  uint32_t  frameCropLeftOffset;
  uint32_t  frameCropRightOffset;
  uint32_t  frameCropTopOffset;
  uint32_t  frameCropBottomOffset;
} OrbisVideodecAvcInfo;

typedef union OrbisVideodecCodecInfo 
{
  uint8_t reserved[64];
  OrbisVideodecAvcInfo avc;
} OrbisVideodecCodecInfo;

typedef struct OrbisVideodecPictureInfo 
{
  size_t   thisSize; // = sizeof(OrbisVideodecPictureInfo)
  uint32_t isValid;
  uint32_t codecType;
  uint32_t frameWidth;
  uint32_t framePitch;
  uint32_t frameHeight;
  uint32_t isErrorPic;
  uint64_t ptsData;
  uint64_t attachedData;
  OrbisVideodecCodecInfo codec;
} OrbisVideodecPictureInfo;

typedef struct OrbisVideodecFrameBuffer 
{
  size_t thisSize; // = sizeof(OrbisVideodecFrameBuffer)
  void*  pFrameBuffer;
  size_t frameBufferSize;
} OrbisVideodecFrameBuffer;