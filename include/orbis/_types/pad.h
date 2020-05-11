#pragma once 

#include <stdint.h>

#define PAD_BUTTON_L3           0x0002
#define PAD_BUTTON_R3           0x0004
#define PAD_BUTTON_START        0x0008
#define PAD_BUTTON_DPAD_UP      0x0010
#define PAD_BUTTON_DPAD_RIGHT   0x0020
#define PAD_BUTTON_DPAD_DOWN    0x0040
#define PAD_BUTTON_DPAD_LEFT    0x0080

#define PAD_BUTTON_L2           0x0100
#define PAD_BUTTON_R2           0x0200
#define PAD_BUTTON_L1           0x0400
#define PAD_BUTTON_R1           0x0800

#define PAD_BUTTON_TRIANGLE     0x1000
#define PAD_BUTTON_CIRCLE       0x2000
#define PAD_BUTTON_X            0x4000
#define PAD_BUTTON_SQUARE       0x8000

#define PAD_BUTTON_TOUCHPAD     0x100000

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

// The ScePadData Structure contains data polled from the DS4 controller. This includes button states, analogue
// positional data, and touchpad related data.
typedef struct OrbisPadData {
	unsigned int buttons;	
	uint8_t lx;
	uint8_t ly;
	uint8_t rx;
	uint8_t ry;
	uint8_t l2;
	uint8_t r2;
	uint16_t padding;
	vec_float4 quat;
	vec_float3 vel;
	vec_float3 acell;
	uint8_t touch[24];
	uint8_t connected;
	uint64_t timestamp;
	uint8_t ext[16];
	uint8_t count;
	uint8_t unknown[15];
} OrbisPadData;

// The PadColor structure contains RGBA for the DS4 controller lightbar.
typedef struct OrbisPadColor {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
} OrbisPadColor;

typedef struct OrbisPadVibeParam {
	uint8_t lgMotor;
	uint8_t smMotor;
} OrbisPadVibeParam;