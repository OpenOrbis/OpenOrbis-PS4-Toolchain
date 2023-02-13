#pragma once 

#include <stdint.h>

#define ORBIS_PAD_PORT_TYPE_STANDARD 0
#define ORBIS_PAD_MAX_TOUCH_NUM 2
#define ORBIS_PAD_MAX_DATA_NUM 0x40

typedef enum OrbisPadButtonDataOffset : uint32_t
{
	ORBIS_PAD_BUTTON_L3          = 0x00000002,
	ORBIS_PAD_BUTTON_R3          = 0x00000004,
	ORBIS_PAD_BUTTON_OPTIONS     = 0x00000008,
	ORBIS_PAD_BUTTON_UP          = 0x00000010,
	ORBIS_PAD_BUTTON_RIGHT       = 0x00000020,
	ORBIS_PAD_BUTTON_DOWN        = 0x00000040,
	ORBIS_PAD_BUTTON_LEFT        = 0x00000080,
	ORBIS_PAD_BUTTON_L2          = 0x00000100,
	ORBIS_PAD_BUTTON_R2          = 0x00000200,
	ORBIS_PAD_BUTTON_L1          = 0x00000400,
	ORBIS_PAD_BUTTON_R1          = 0x00000800,
	ORBIS_PAD_BUTTON_TRIANGLE    = 0x00001000,
	ORBIS_PAD_BUTTON_CIRCLE      = 0x00002000,
	ORBIS_PAD_BUTTON_CROSS       = 0x00004000,
	ORBIS_PAD_BUTTON_SQUARE      = 0x00008000,
	ORBIS_PAD_BUTTON_TOUCH_PAD   = 0x00100000,
	ORBIS_PAD_BUTTON_INTERCEPTED = 0x80000000,
} OrbisPadButtonDataOffset;

typedef struct vec_float3
{
    float x;
    float y;
    float z;
} vec_float3;

typedef struct vec_float4
{
    float x;
    float y;
    float z;
    float w;
} vec_float4;

typedef struct stick
{
	uint8_t x;
	uint8_t y;
} stick;

typedef struct analog
{
	uint8_t l2;
	uint8_t r2;
} analog;

typedef struct OrbisPadTouch 
{
	uint16_t x, y;
	uint8_t finger;
	uint8_t pad[3];
} OrbisPadTouch;

typedef struct OrbisPadTouchData 
{
	uint8_t fingers;
	uint8_t pad1[3];
	uint32_t pad2;
	OrbisPadTouch touch[ORBIS_PAD_MAX_TOUCH_NUM];
} OrbisPadTouchData;

// The ScePadData Structure contains data polled from the DS4 controller. This includes button states, analogue
// positional data, and touchpad related data.
typedef struct OrbisPadData 
{
	unsigned int buttons;
	stick leftStick;
	stick rightStick;
	analog analogButtons;
	uint16_t padding;
	vec_float4 quat;
	vec_float3 vel;
	vec_float3 acell;
	OrbisPadTouchData touch;
	uint8_t connected;
	uint64_t timestamp;
	uint8_t ext[16];
	uint8_t count;
	uint8_t unknown[15];
} OrbisPadData;

// The PadColor structure contains RGBA for the DS4 controller lightbar.
typedef struct OrbisPadColor 
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
} OrbisPadColor;

typedef struct OrbisPadVibeParam 
{
	uint8_t lgMotor;
	uint8_t smMotor;
} OrbisPadVibeParam;
