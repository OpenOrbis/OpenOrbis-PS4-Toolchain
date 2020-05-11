#pragma once

#include <stdint.h>

typedef void *OrbisPngEncHandle;

typedef void *OrbisPngDecHandle;

typedef struct OrbisPngEncCreateParam {
	uint32_t size;
	uint32_t attr;
	uint32_t maxImgWidth;
	uint32_t unk4;
} OrbisPngEncCreateParam;

typedef struct OrbisPngEncEncodeParam {
	const void *unk1;
	void *unk2;
	uint32_t unk3;
	uint32_t unk4;
	uint32_t unk5;
	uint32_t unk6;
	uint32_t unk7;
	uint16_t unk8;
	uint16_t unk9;
	uint16_t unk10;
	uint16_t unk11;
	uint16_t unk12;
	uint16_t unk13;
} OrbisPngEncEncodeParam;

typedef struct OrbisPngEncOutputInfo {
	uint32_t size;
	uint32_t height;
} OrbisPngEncOutputInfo;

typedef struct OrbisPngDecCreateParam {
	uint32_t unk1;
	uint32_t unk2;
	uint32_t unk3;
} OrbisPngDecCreateParam;

typedef struct OrbisPngDecDecodeParam {
	const void *unk1;
	void *unk2;
	uint32_t unk3;
	uint32_t unk4;
	uint16_t unk5;
	uint16_t unk6;
	uint32_t unk7;
} OrbisPngDecDecodeParam;

typedef struct OrbisPngDecImageInfo {
	uint32_t width;
	uint32_t height;
	uint16_t unk3;
	uint16_t unk4;
	uint32_t unk5;
} OrbisPngDecImageInfo;

typedef struct OrbisPngDecParseParam {
	const void *unk1;
	uint32_t unk2;
	uint32_t unk3;
} OrbisPngDecParseParam;