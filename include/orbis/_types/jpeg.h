#pragma once 

#include <stdint.h>

typedef void *OrbisJpegEncHandle;
typedef void *OrbisJpegDecHandle;

typedef struct OrbisJpegEncCreateParam {
	uint32_t size;
	uint32_t attr;
} OrbisJpegEncCreateParam;

typedef struct OrbisJpegDecCreateParam {
	uint32_t size;
	uint32_t attr;
	uint32_t maxWidth;
} OrbisJpegDecCreateParam;

typedef struct OrbisJpegEncEncodeParam {
	const void *imgAddr;
	void *jpegAddr;
	uint32_t imgSize;
	uint32_t jpegSize;
	uint32_t imgWidth;
	uint32_t imgHeight;
	uint32_t imgPitch;
	uint16_t unk8;
	uint16_t unk9;
	uint16_t unk10;
	uint8_t unk11;
	uint8_t unk12;
	int32_t unk13;
} OrbisJpegEncEncodeParam;

typedef struct OrbisJpegDecDecodeParam {
	const void *jpegAddr;
	void *imgAddr;
	void *unk3;
	uint32_t unk4;
	uint32_t unk5;
	uint32_t unk6;
	uint16_t unk7;
	uint16_t unk8;
	uint16_t unk9;
	uint16_t alpha;
	uint32_t unk11;
} OrbisJpegDecDecodeParam;

typedef struct OrbisJpegEncOutputInfo {
	uint32_t imageSize;
	uint32_t imageHeight;
} OrbisJpegEncOutputInfo;

typedef struct OrbisJpegDecImageInfo {
	uint32_t imgWidth;
	uint32_t imgHeight;
	uint16_t unk3;
	uint16_t unk4;
	uint8_t unk5[4];
	uint8_t unk6[4];
	uint32_t unk7;
	uint32_t unk8;
	uint32_t outImgWidth;
	uint32_t outImgHeight;
} OrbisJpegDecImageInfo;

typedef struct OrbisJpegDecParseParam {
	const void *unk1;
	uint32_t unk2;
	uint16_t unk3;
	uint16_t unk4;
} OrbisJpegDecParseParam;