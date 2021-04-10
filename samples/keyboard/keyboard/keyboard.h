#pragma once
#include <orbis/Keyboard.h>
#include <orbis/UserService.h>

class Keyboard
{
	int handle;
	int userID;
	OrbisKeyboardData data;

	void Poll();
public:
	enum LockKey
	{
		NUM_LOCK = ORBIS_KEYBOARD_NUM_LOCK,
		CAPS_LOCK = ORBIS_KEYBOARD_CAPS_LOCK,
		SCROLL_LOCK = ORBIS_KEYBOARD_SCROLL_LOCK,
	};

	enum ModifierKey
	{
		LEFT_SHIFT = ORBIS_KEYBOARD_MOD_LEFT_SHIFT,
		LEFT_CTRL = ORBIS_KEYBOARD_MOD_LEFT_CTRL,
		LEFT_ALT = ORBIS_KEYBOARD_MOD_LEFT_ALT,
		LEFT_META = ORBIS_KEYBOARD_MOD_LEFT_META,
		RIGHT_SHIFT = ORBIS_KEYBOARD_MOD_RIGHT_SHIFT,
		RIGHT_CTRL = ORBIS_KEYBOARD_MOD_RIGHT_CTRL,
		RIGHT_ALT = ORBIS_KEYBOARD_MOD_RIGHT_ALT,
		RIGHT_META = ORBIS_KEYBOARD_MOD_RIGHT_META,
		SHIFT = LEFT_SHIFT | RIGHT_SHIFT,
		CTRL = LEFT_CTRL | RIGHT_CTRL,
		ALT = LEFT_ALT | RIGHT_ALT,
		META = LEFT_META | RIGHT_META,
	};

	class KeycodeArray
	{
		OrbisKeyboardData data;
		KeycodeArray(OrbisKeyboardData p) : data(p){}
		friend class Keyboard;
	public:
		uint16_t* begin();
		uint16_t* end();
	};

	Keyboard();
	~Keyboard();

	bool Init(int keyboadUserID);

	bool CheckLock(LockKey keyToCheck);
	bool CheckModifierKey(ModifierKey keyToCheck);
	bool CheckKey(int keyCode);

	KeycodeArray Keys();

	int Key2Char(int keyCode);
};
