/* OpenOrbis Toolkit
 * Application Base class
 */

#pragma once
#include "ootk_Exception.hpp"
#include "ootk_InputManager.hpp"
#include "ootk_GraphicsManager.hpp"
#include "ootk_AudioManager.hpp"

namespace ootk {
    class ApplicationBase {
    protected:
        InputManager Input{};
        GraphicsManager Graphics{};
        AudioManager Audio{};

    public:
        virtual bool Init();
        virtual bool Logic();
        virtual void Render();
        virtual ~ApplicationBase();
    };
}
