#include <stddef.h>
#include <stdint.h>

#include "string_data.h"
#include "logo_data.h"

uint32_t sceGameRightGetVersion()
{
	return 1;
}

void* sceGameRightGetString()
{
	return string_data;
}

int32_t sceGameRightGetStringSizeInBytes()
{
	return (int32_t)size_string_data;
}

void* sceGameRightGetLogoPngImage()
{
	return logo_data;
}

int32_t sceGameRightGetLogoPngImageSizeInBytes()
{
	return (int32_t)size_logo_data;
}