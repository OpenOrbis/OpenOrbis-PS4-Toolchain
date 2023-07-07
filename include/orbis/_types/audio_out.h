#pragma once 

#include <stdint.h>

enum OrbisAudioOutPort
{
    ORBIS_AUDIO_OUT_PORT_TYPE_MAIN = 0,
};

enum OrbisAudioOutParam
{
    ORBIS_AUDIO_OUT_PARAM_FORMAT_S16_MONO = 0,
    ORBIS_AUDIO_OUT_PARAM_FORMAT_S16_STEREO = 1,
    ORBIS_AUDIO_OUT_PARAM_FORMAT_FLOAT_MONO = 3,
    ORBIS_AUDIO_OUT_PARAM_FORMAT_FLOAT_STEREO = 4,
};

typedef struct OrbisAudioOutPostState {
	uint16_t output;
	uint8_t channel;
	uint8_t unk3[1];
	int16_t volume;
	uint16_t unk5;
	uint64_t flag;
	uint64_t unk7[2];
} OrbisAudioOutPostState;

typedef struct OrbisAudioOutSystemState {
	float loudness;
	uint8_t unk2[4];
	uint64_t unk3[3];
} OrbisAudioOutSystemState;

typedef struct OrbisAudioOutMasteringStatesHeader {
	uint32_t id;
} OrbisAudioOutMasteringStatesHeader;

typedef struct OrbisAudioOutOutputParam {
	int32_t handle;
	const void *pointer;
} OrbisAudioOutOutputParam;
