#pragma once

#include <orbis/AudioOut.h>
#include <ootk_Exception.hpp>

namespace ootk {
    class AudioManager {
    private:


    public:
        AudioManager();
        ~AudioManager();
        void Init();
        void Logic();
    };
}
