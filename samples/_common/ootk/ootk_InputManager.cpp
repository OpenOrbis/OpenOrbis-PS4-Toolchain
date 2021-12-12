#include "ootk_InputManager.hpp"

#include <algorithm>

ootk::InputManager::InputManager() {
    int err{scePadInit()};

    if (err < 0) {
        throw Exception("Failed to initialize scePad, %d.", err);
    }
}

ootk::InputManager::~InputManager() {
    int err{scePadClose(handle)};

    handle = -1;
    if (err != ORBIS_OK) {
        throw Exception("Failed to finalize scePad, %d.", err);
    }
}

void ootk::InputManager::Init(int userId) {
    int err{-1};

    if (handle >= 0) return;

    if (userId < 0) {
        OrbisUserServiceInitializeParams param;
    	param.priority = ORBIS_KERNEL_PRIO_FIFO_LOWEST;
    	sceUserServiceInitialize(&param);
    	err = sceUserServiceGetInitialUser(&userId);

        if (err < ORBIS_OK) {
            throw Exception("Failed to get initial user, %d.", userId);
        }
    }

    handle = scePadOpen(userId, ORBIS_PAD_PORT_TYPE_STANDARD, 0, nullptr);
    user = userId;

    if (handle < 0) {
        throw Exception("Failed to open the pad handle, %d.", handle);
    }
}

bool ootk::InputManager::Logic() {
    int ok{-1};

    buttonsPrev = buttons;
    std::memset(&state, 0, sizeof(state));
    ok = scePadReadState(handle, &state);
    buttons = state.buttons;

    return (ok == ORBIS_OK);
}

bool ootk::InputManager::IsConnected() {
    return state.connected;
}

int ootk::InputManager::GetUserId() {
    return user;
}

bool ootk::InputManager::Check(uint32_t bitMask) {
    return buttons & bitMask;
}

bool ootk::InputManager::CheckPressed(uint32_t bitMask) {
    return (buttons & bitMask) && !(buttonsPrev & bitMask);
}

bool ootk::InputManager::CheckReleased(uint32_t bitMask) {
    return (buttonsPrev & bitMask) && !(buttons & bitMask);
}

float ootk::InputManager::GetAxis(InputAxis axis) {
    float v{0.f};
    float dz{stickDeadzone};

    switch (axis) {
        case InputAxis::LEFTX: {
            v = static_cast<float>(state.leftStick.x) / 255.f;
            break;
        }

        case InputAxis::LEFTY: {
            v = static_cast<float>(state.leftStick.y) / 255.f;
            break;
        }

        case InputAxis::RIGHTX: {
            v = static_cast<float>(state.rightStick.x) / 255.f;
            break;
        }

        case InputAxis::RIGHTY: {
            v = static_cast<float>(state.rightStick.y) / 255.f;
            break;
        }

        case InputAxis::L2: {
            v = static_cast<float>(state.analogButtons.l2) / 255.f;
            dz = buttonDeadzone;
            break;
        }

        case InputAxis::R2: {
            v = static_cast<float>(state.analogButtons.r2) / 255.f;
            dz = buttonDeadzone;
            break;
        }
    }

    return v > dz ? v : 0.f;
}

void ootk::InputManager::SetStickDeadzone(float dz) {
    stickDeadzone = dz;
}

float ootk::InputManager::GetStickDeadzone() {
    return stickDeadzone;
}

void ootk::InputManager::SetButtonDeadzone(float dz) {
    buttonDeadzone = dz;
}

float ootk::InputManager::GetButtonDeadzone() {
    return buttonDeadzone;
}

int ootk::InputManager::GetTouchpad(InputFinger finger) {
    switch (finger) {
        case InputFinger::AMOUNT: return state.touch.fingers;
        case InputFinger::FIRSTX: return state.touch.touch[0].x;
        case InputFinger::FIRSTY: return state.touch.touch[0].y;
        case InputFinger::FIRSTID: return state.touch.touch[0].finger;
        case InputFinger::SECONDX: return state.touch.touch[1].x;
        case InputFinger::SECONDY: return state.touch.touch[1].y;
        case InputFinger::SECONDID: return state.touch.touch[1].finger;
    }

    // default value...
    return 0;
}
