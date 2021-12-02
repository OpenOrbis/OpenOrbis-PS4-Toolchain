#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#include <orbis/libkernel.h>
#include <orbis/AudioOut.h>
#include <orbis/UserService.h>

// Header library for decoding wav files
#define DR_WAV_IMPLEMENTATION
#include "dr_wav.h"

#define PARAMS16 ORBIS_AUDIO_OUT_PARAM_FORMAT_S16_STEREO

int32_t audio = 0;

/*********************************************************************
* No.of channels : 2
* Bits / Sample : 16
**********************************************************************/

int main()
{
    int rc;
    OrbisUserServiceUserId userId = ORBIS_USER_SERVICE_USER_ID_SYSTEM;

    sceUserServiceInitialize(NULL);

    // Initialize audio output library
    rc = sceAudioOutInit();

    if (rc != 0)
    {
        printf("[ERROR] Failed to initialize audio output\n");
        return rc;
    }

    // Open a handle to audio output device
    audio = sceAudioOutOpen(userId, ORBIS_AUDIO_OUT_PORT_TYPE_MAIN, 0, 256, 48000, PARAMS16);

    if (audio <= 0)
    {
        printf("[ERROR] Failed to open audio on main port\n");
        return audio;
    }

    // Decode a wav file to play
    drwav wav;

    if (!drwav_init_file(&wav, "/app0/assets/audio/lets_go_go_go_tigerblood_jewel.wav", NULL))
    {
        printf("[ERROR] Failed to decode wav file\n");
        return -1;
    }

    // Calculate the sample count and allocate a buffer for the sample data accordingly
    size_t sampleCount = wav.totalPCMFrameCount * wav.channels;
    drwav_int16 *pSampleData = (drwav_int16 *)malloc(sampleCount * sizeof(uint16_t));

    // Decode the wav into pSampleData
    drwav_read_pcm_frames_s16(&wav, wav.totalPCMFrameCount, pSampleData);

    // Play the sample
    int32_t sOffs = 0;
    drwav_int16 *pSample = nullptr;

    bool finished = false;

    // Play the song in a loop
    while (!finished)
    {
        pSample = &pSampleData[sOffs];

        /* Output audio */
        sceAudioOutOutput(audio, NULL);	// NULL: wait for completion

        if (sceAudioOutOutput(audio, pSample) < 0) {

            printf("Failed to output audio\n");
            return -1;
        }

        sOffs += 256 * 2;

        if (sOffs >= sampleCount)
            sOffs = 0;
    }

    drwav_uninit(&wav);

    for (;;);
    return 0;
}