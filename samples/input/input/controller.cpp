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
        
	if (stateToCheck & ORBIS_PAD_BUTTON_TRIANGLE && !(this->buttonState & ORBIS_PAD_BUTTON_TRIANGLE))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_CIRCLE && !(this->buttonState & ORBIS_PAD_BUTTON_CIRCLE))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_CROSS && !(this->buttonState & ORBIS_PAD_BUTTON_CROSS))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_SQUARE && !(this->buttonState & ORBIS_PAD_BUTTON_SQUARE))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_L1 && !(this->buttonState & ORBIS_PAD_BUTTON_L1))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_R1 && !(this->buttonState & ORBIS_PAD_BUTTON_R1))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_L2 && !(this->buttonState & ORBIS_PAD_BUTTON_L2))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_R2 && !(this->buttonState & ORBIS_PAD_BUTTON_R2))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_L3 && !(this->buttonState & ORBIS_PAD_BUTTON_L3))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_R3 && !(this->buttonState & ORBIS_PAD_BUTTON_R3))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_OPTIONS && !(this->buttonState & ORBIS_PAD_BUTTON_OPTIONS))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_UP && !(this->buttonState & ORBIS_PAD_BUTTON_UP))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_RIGHT && !(this->buttonState & ORBIS_PAD_BUTTON_RIGHT))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_DOWN && !(this->buttonState & ORBIS_PAD_BUTTON_DOWN))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_LEFT && !(this->buttonState & ORBIS_PAD_BUTTON_LEFT))
		return false;
	if (stateToCheck & ORBIS_PAD_BUTTON_TOUCH_PAD && !(this->buttonState & ORBIS_PAD_BUTTON_TOUCH_PAD))
		return false;

	return true;
}

bool Controller::TrianglePressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_TRIANGLE);
}

bool Controller::CirclePressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_CIRCLE);
}

bool Controller::XPressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_CROSS);
}

bool Controller::SquarePressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_SQUARE);
}

bool Controller::L1Pressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_L1);
}

bool Controller::L2Pressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_L2);
}

bool Controller::R1Pressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_R1);
}

bool Controller::R2Pressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_R2);
}

bool Controller::L3Pressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_L3);
}

bool Controller::R3Pressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_R3);
}

bool Controller::StartPressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_OPTIONS);
}

bool Controller::DpadUpPressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_UP);
}

bool Controller::DpadRightPressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_RIGHT);
}

bool Controller::DpadDownPressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_DOWN);
}

bool Controller::DpadLeftPressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_LEFT);
}

bool Controller::TouchpadPressed()
{
	return CheckButtonsPressed(ORBIS_PAD_BUTTON_TOUCH_PAD);
}

