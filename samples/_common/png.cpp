#define STBI_ASSERT(x)
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "graphics.h"
#include "png.h"
#include "log.h"

PNG::PNG(const char *imagePath)
{
	this->img = (uint32_t *)stbi_load(imagePath, &this->width, &this->height, &this->channels, STBI_rgb_alpha);

 	if (this->img == NULL)
	{
		DEBUGLOG << "Failed to load image '" << imagePath << "': " << stbi_failure_reason();
		return;
	}
}

PNG::~PNG()
{
	if(this->img != NULL)
		stbi_image_free(this->img);
}

void PNG::Draw(Scene2D *scene, int startX, int startY)
{
	// Don't draw non-existant images
	if(this->img == NULL)
		return;
		
	// Iterate the bitmap and draw the pixels
	for (int yPos = 0; yPos < this->height; yPos++)
	{
		for (int xPos = 0; xPos < this->width; xPos++)
		{
			// Decode the 32-bit color
			uint32_t encodedColor = this->img[(yPos * this->width) + xPos];

			// Get new pixel coordinates to account for start coordinates
			int x = startX + xPos;
 			int y = startY + yPos;

			// Re-encode the color
			uint8_t r = (uint8_t)(encodedColor >> 0);
			uint8_t g = (uint8_t)(encodedColor >> 8);
			uint8_t b = (uint8_t)(encodedColor >> 16);

			Color color = { r, g, b };

			// Do some bounds checking to make sure the pixel is actually inside the frame buffer
			if (xPos < 0 || yPos < 0 || xPos >= this->width || yPos >= this->height)
				continue;

			scene->DrawPixel(x, y, color);
		}
	}
}

