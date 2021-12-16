
#pragma once
#include <orbis/Pad.h>
#include <orbis/UserService.h>
#include "ootk_Exception.hpp"

namespace ootk {
    enum class InputAxis {
        // left stick x
        LEFTX,
        // left stick y
        LEFTY,
        // right stick x
        RIGHTX,
        // right stick y
        RIGHTY,
        // L2 above
        L2,
        // R2 above
        R2
    };

    enum class InputFinger {
        // [0] finger X
        FIRSTX,
        // [0] finger Y
        FIRSTY,
        // [0] finger id
        FIRSTID,
        // [1] finger X
        SECONDX,
        // [1] finger Y
        SECONDY,
        // [1] finger id
        SECONDID,
        // amount of fingers on touch
        AMOUNT
    };

    class InputManager {
    private:
        int user{-1};
        int handle{-1};
        float stickDeadzone{0.2f};
        float buttonDeadzone{0.2f};

        uint32_t buttonsPrev{};
        uint32_t buttons{};
        OrbisPadData state{};


    public:
        InputManager();
        ~InputManager();
        void Init(int userId = -1);
        bool Logic();

        bool IsConnected();
        int GetUserId();

        bool Check(uint32_t bitMask);
        bool CheckPressed(uint32_t bitMask);
        bool CheckReleased(uint32_t bitMask);

        float GetAxis(InputAxis axis);

        void SetStickDeadzone(float dz);
        float GetStickDeadzone();

        void SetButtonDeadzone(float dz);
        float GetButtonDeadzone();

        int GetTouchpad(InputFinger finger);
    };
}
