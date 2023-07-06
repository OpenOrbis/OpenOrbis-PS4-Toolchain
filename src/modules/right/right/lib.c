#include <stddef.h>
#include <stdint.h>

#include "string_data.h"
#include "logo_data.h"

uint32_t sceGameRightGetVersion()
{
	return 1;
}

const char* sceGameRightGetString()
{
	return string_data;
}

int32_t sceGameRightGetStringSizeInBytes()
{
	return (int32_t)sizeof(string_data);
}

void* sceGameRightGetLogoPngImage()
{
	return (void*)logo_data;
}

int32_t sceGameRightGetLogoPngImageSizeInBytes()
{
	return (int32_t)sizeof(logo_data);
}
