#include <orbis/Pad.h>
#include <orbis/UserService.h>

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
	int pad;
	int userID;
	int prevButtonState;
	int buttonState;
	OrbisPadData padData;
	
	void setButtonState(int state);
public:
	Controller();
	~Controller();
	
	bool Init(int controllerUserID);
	
	bool CheckButtonsPressed(int stateToCheck);
	
	bool TrianglePressed();
	bool CirclePressed();
	bool XPressed();
	bool SquarePressed();
	bool L1Pressed();
	bool L2Pressed();
	bool R1Pressed();
	bool R2Pressed();
	bool L3Pressed();
	bool R3Pressed();
	bool StartPressed();
	bool DpadUpPressed();
	bool DpadRightPressed();
	bool DpadDownPressed();
	bool DpadLeftPressed();
	bool TouchpadPressed();
};

#endif

