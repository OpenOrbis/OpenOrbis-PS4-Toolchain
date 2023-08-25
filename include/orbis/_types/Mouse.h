#pragma once

#include <stdint.h>

#define ORBIS_MOUSE_PORT_TYPE_STANDARD		0
#define ORBIS_MOUSE_MAX_STANDARD_PORT_INDEX	2 

#define ORBIS_MOUSE_OPEN_PARAM_NORMAL	0x00
#define ORBIS_MOUSE_OPEN_PARAM_MERGED	0x01

typedef enum OrbisMouseButtonDataOffset : uint32_t
{
	ORBIS_MOUSE_BUTTON_PRIMARY = 0x00000001,		// Left button.
	ORBIS_MOUSE_BUTTON_SECONDARY = 0x00000002,		// Right button.
	ORBIS_MOUSE_BUTTON_OPTIONAL = 0x00000004,		// Wheel press.
	ORBIS_MOUSE_BUTTON_OPTIONAL2 = 0x00000008,		// Back button.
	ORBIS_MOUSE_BUTTON_OPTIONAL3 = 0x00000010,		// Forward button.
	ORBIS_MOUSE_BUTTON_INTERCEPTED = 0x80000000,	// Intercepted flag.
};

typedef struct OrbisMouseOpenParam
{
	uint8_t behaviorFlag;
	uint8_t reserve[7];
} OrbisMouseOpenParam;

typedef struct OrbisMouseData
{
	uint64_t		timestamp;				// System timestamp (in micro seconds).
	bool			connected;				// Connection status.
	uint32_t		buttons;				// Mouse buttons.
	int32_t			xAxis;					// Amount of movement in the x Axis.
	int32_t			yAxis;					// Amount of movement in the y Axis.
	int32_t			wheel;					// Amount of wheel movement.
	int32_t			tilt;					// Amount of tilt movement.
	uint8_t			reserve[8];
} OrbisMouseData;
