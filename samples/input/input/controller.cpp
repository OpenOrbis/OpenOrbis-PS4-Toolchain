#include "controller.h"
#include "../../_common/log.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

bool Controller::Init(int controllerUserID)
{
    // Initialize the Pad library
    if (scePadInit() != 0)
    {
        DEBUGLOG << "[DEBUG] [ERROR] Failed to initialize pad library!";
        return false;
    }

    // Get the user ID
    if (controllerUserID < 0)
    {
    	OrbisUserServiceInitializeParams param;
    	param.priority = ORBIS_KERNEL_PRIO_FIFO_LOWEST;
    	sceUserServiceInitialize(&param);
    	sceUserServiceGetInitialUser(&this->userID);
    }
    else
    {
    	this->userID = controllerUserID;
    }

    // Open a handle for the controller
    this->pad = scePadOpen(this->userID, 0, 0, NULL);

    if (this->pad < 0)
    {
        DEBUGLOG << "[DEBUG] [ERROR] Failed to open pad!";
        return false;
    }
    
    return true;
}

void Controller::setButtonState(int state)
{
	this->prevButtonState = this->buttonState;
	this->buttonState = state;
}

bool Controller::CheckButtonsPressed(int stateToCheck)
{
	scePadReadState(this->pad, &this->padData);
	setButtonState(this->padData.buttons);
        
	if (stateToCheck & PAD_BUTTON_TRIANGLE && !(this->buttonState & PAD_BUTTON_TRIANGLE))
		return false;
	if (stateToCheck & PAD_BUTTON_CIRCLE && !(this->buttonState & PAD_BUTTON_CIRCLE))
		return false;
	if (stateToCheck & PAD_BUTTON_X && !(this->buttonState & PAD_BUTTON_X))
		return false;
	if (stateToCheck & PAD_BUTTON_SQUARE && !(this->buttonState & PAD_BUTTON_SQUARE))
		return false;
	if (stateToCheck & PAD_BUTTON_L1 && !(this->buttonState & PAD_BUTTON_L1))
		return false;
	if (stateToCheck & PAD_BUTTON_R1 && !(this->buttonState & PAD_BUTTON_R1))
		return false;
	if (stateToCheck & PAD_BUTTON_L2 && !(this->buttonState & PAD_BUTTON_L2))
		return false;
	if (stateToCheck & PAD_BUTTON_R2 && !(this->buttonState & PAD_BUTTON_R2))
		return false;
	if (stateToCheck & PAD_BUTTON_L3 && !(this->buttonState & PAD_BUTTON_L3))
		return false;
	if (stateToCheck & PAD_BUTTON_R3 && !(this->buttonState & PAD_BUTTON_R3))
		return false;
	if (stateToCheck & PAD_BUTTON_START && !(this->buttonState & PAD_BUTTON_START))
		return false;
	if (stateToCheck & PAD_BUTTON_DPAD_UP && !(this->buttonState & PAD_BUTTON_DPAD_UP))
		return false;
	if (stateToCheck & PAD_BUTTON_DPAD_RIGHT && !(this->buttonState & PAD_BUTTON_DPAD_RIGHT))
		return false;
	if (stateToCheck & PAD_BUTTON_DPAD_DOWN && !(this->buttonState & PAD_BUTTON_DPAD_DOWN))
		return false;
	if (stateToCheck & PAD_BUTTON_DPAD_LEFT && !(this->buttonState & PAD_BUTTON_DPAD_LEFT))
		return false;
	if (stateToCheck & PAD_BUTTON_TOUCHPAD && !(this->buttonState & PAD_BUTTON_TOUCHPAD))
		return false;

	return true;
}

bool Controller::TrianglePressed()
{
	return CheckButtonsPressed(PAD_BUTTON_TRIANGLE);
}

bool Controller::CirclePressed()
{
	return CheckButtonsPressed(PAD_BUTTON_CIRCLE);
}

bool Controller::XPressed()
{
	return CheckButtonsPressed(PAD_BUTTON_X);
}

bool Controller::SquarePressed()
{
	return CheckButtonsPressed(PAD_BUTTON_SQUARE);
}

bool Controller::L1Pressed()
{
	return CheckButtonsPressed(PAD_BUTTON_L1);
}

bool Controller::L2Pressed()
{
	return CheckButtonsPressed(PAD_BUTTON_L2);
}

bool Controller::R1Pressed()
{
	return CheckButtonsPressed(PAD_BUTTON_R1);
}

bool Controller::R2Pressed()
{
	return CheckButtonsPressed(PAD_BUTTON_R2);
}

bool Controller::L3Pressed()
{
	return CheckButtonsPressed(PAD_BUTTON_L3);
}

bool Controller::R3Pressed()
{
	return CheckButtonsPressed(PAD_BUTTON_R3);
}

bool Controller::StartPressed()
{
	return CheckButtonsPressed(PAD_BUTTON_START);
}

bool Controller::DpadUpPressed()
{
	return CheckButtonsPressed(PAD_BUTTON_DPAD_UP);
}

bool Controller::DpadRightPressed()
{
	return CheckButtonsPressed(PAD_BUTTON_DPAD_RIGHT);
}

bool Controller::DpadDownPressed()
{
	return CheckButtonsPressed(PAD_BUTTON_DPAD_DOWN);
}

bool Controller::DpadLeftPressed()
{
	return CheckButtonsPressed(PAD_BUTTON_DPAD_LEFT);
}

bool Controller::TouchpadPressed()
{
	return CheckButtonsPressed(PAD_BUTTON_TOUCHPAD);
}

