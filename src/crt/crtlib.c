#include <stdint.h>

void(*__init_array_start[])(void);
void(*__init_array_end[])(void);

// sce_module_param
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".section \".data.sce_module_param\" \n"
"_sceProcessParam: \n"
	// size
"	.quad 	0x18 \n"
	// magic
"	.quad   0x13C13F4BF \n"
	// SDK version
"	.quad 	0x1000051 \n"
".att_syntax prefix \n"
);

// data globals
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".data \n"
"__dso_handle: \n"
"	.quad 	0 \n"
"_sceLibc: \n"
"	.quad 	0 \n"
".att_syntax prefix \n"
);

int32_t __attribute__((visibility("hidden"))) module_start(int64_t args, const void* argp)
{
	// Iterate init array and initialize all objects
	for(void(**i)(void) = __init_array_start; i != __init_array_end; i++)
	{
		i[0]();
	}
	return 0;
}

int32_t __attribute__((visibility("hidden"))) module_stop(int64_t args, const void* argp)
{
	return 0;
}

int32_t _init()
{
	return 0;
}

int32_t _fini()
{
	return 0;
}
