#include "ootk_AudioManager.hpp"

ootk::AudioManager::AudioManager() {
    int ok{sceAudioOutInit()};
    if (ok < ORBIS_OK) {
        throw Exception("Failed to initialize AudioOut, %d.", ok);
    }
}

void ootk::AudioManager::Logic() {
    // update the state of the threads...
}
