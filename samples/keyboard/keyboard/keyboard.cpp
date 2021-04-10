#include <orbis/Sysmodule.h>
#include "keyboard.h"
#include "../../_common/log.h"

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

bool Keyboard::Init(int keyboardUserID)
{
    // Load libSceKeyboard.sprx if not yet done
    static bool isSysmoduleLoaded = false;
    if(!isSysmoduleLoaded)
    {
        if(sceSysmoduleLoadModule(SCE_SYSMODULE_KEYBOARD))
        {
            DEBUGLOG << "[DEBUG] [ERROR] Failed to load SCE_SYSMODULE_KEYBOARD!";
            return false;
        }
        isSysmoduleLoaded = true;
    }

    // Initialize the Keyboard library
    if(sceKeyboardInit() != 0)
    {
        DEBUGLOG << "[DEBUG] [ERROR] Failed to initialize keyboard library!";
        return false;
    }

    // Get the user ID
    if(keyboardUserID < 0)
    {
        OrbisUserServiceInitializeParams param;
        param.priority = ORBIS_KERNEL_PRIO_FIFO_LOWEST;
        sceUserServiceInitialize(&param);
        sceUserServiceGetInitialUser(&this->userID);
    }
    else
    {
        this->userID = keyboardUserID;
    }

    // Open a handle for the keyboard
    this->handle = sceKeyboardOpen(this->userID, 0, 0, NULL);

    if(this->handle < 0)
    {
        DEBUGLOG << "[DEBUG] [ERROR] Failed to open keyboard!";
        return false;
    }

    return true;
}

bool Keyboard::CheckLock(LockKey keyToCheck)
{
    Poll();
    return (bool)(this->data.locks & keyToCheck);
}

bool Keyboard::CheckModifierKey(ModifierKey keyToCheck)
{
    Poll();
    return (bool)(this->data.mods & keyToCheck);
}

bool Keyboard::CheckKey(int keyCode)
{
    for(int ev : this->Keys())
        if(ev == keyCode)
            return true;
    return false;
}

Keyboard::KeycodeArray Keyboard::Keys()
{
    Poll();
    return KeycodeArray(this->data);
}

int Keyboard::Key2Char(int keyCode)
{
    OrbisKeyboardKey2Char k2c;
    Poll();
    if(sceKeyboardGetKey2Char(handle, false, this->data.locks, this->data.mods, keyCode, &k2c) < 0)
        return -1;
    if(!k2c.ok)
        return -1;
    return k2c.keycode;
}

uint16_t* Keyboard::KeycodeArray::begin()
{
    return this->data.keycodes;
}

uint16_t* Keyboard::KeycodeArray::end()
{
    uint16_t* ans = this->data.keycodes + this->data.nkeys;
    if(this->data.nkeys && ans[-1] == 0)
        ans--;
    return ans;
}

void Keyboard::Poll()
{
    sceKeyboardReadState(this->handle, &this->data);
}
