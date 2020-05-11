#ifndef _SCE_AUDIO_DEC_H
#define _SCE_AUDIO_DEC_H

#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct OrbisAudiodecPcmItem {
	uint32_t unk1;
	void *unk2;
	uint32_t unk3;
} OrbisAudiodecPcmItem;

typedef struct OrbisAudiodecAuInfo {
	uint32_t unk1;
	void *unk2;
	uint32_t unk3;
} OrbisAudiodecAuInfo;

typedef struct OrbisAudiodecCtrl {
	void *unk1;
	void *unk2;
	OrbisAudiodecAuInfo *pAudioInfo;
	OrbisAudiodecPcmItem *pPcmStruct;
} OrbisAudiodecCtrl;

// Decoder Types
#define ORBIS_AUDIO_DEC_CODEC_AT9 	0x0001U
#define ORBIS_AUDIO_DEC_CODEC_MP3		0x0002U
#define ORBIS_AUDIO_DEC_CODEC_M4AAC 	0x0003U

// Empty Comment
int32_t sceAudiodecClearContext(int32_t);
// Empty Comment
int32_t sceAudiodecCreateDecoder(OrbisAudiodecCtrl *, uint32_t);
// Empty Comment
int32_t sceAudiodecDecode(int32_t, OrbisAudiodecCtrl *);
// Empty Comment
void sceAudiodecDecode2();
// Empty Comment
int32_t sceAudiodecDeleteDecoder(int32_t);
// setup a decoder
int32_t sceAudiodecInitLibrary(uint32_t decoderType);
// Empty Comment
int32_t sceAudiodecTermLibrary(uint32_t decoderType);

#ifdef __cplusplus
}
#endif

#endif
