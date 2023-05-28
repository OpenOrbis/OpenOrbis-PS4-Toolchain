#pragma once 

#include <stdint.h>

typedef union {
	struct {
		uint32_t predication : 1;
		uint32_t _unused : 28;
		uint32_t rendertargetsliceoffset : 3;
	};
	uint32_t asuint;
} OrbisGnmDrawFlags;
_Static_assert(sizeof(OrbisGnmDrawFlags) == 0x4, "");
