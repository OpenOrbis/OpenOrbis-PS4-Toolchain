#pragma once 

#include <stdint.h>

typedef union OrbisGnmDrawIndexFlags {
	struct {
		uint32_t predication : 1;
		uint32_t _unused : 28;
		uint32_t rendertargetsliceoffset : 3;
	};
	uint32_t asuint;
} OrbisGnmDrawIndexFlags;
