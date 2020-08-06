#include "TTF.h"

#include <stdio.h>

FT_Library ftLib;

bool InitFont(FT_Face* face, const char* fontPath, int fontSize)
{
    int rc;

    rc = FT_New_Face(ftLib, fontPath, 0, face);

    if (rc < 0)
        return false;

    rc = FT_Set_Pixel_Sizes(*face, 0, fontSize);

    if (rc < 0)
        return false;

    return true;
}

int SetText(SDL_Surface* surface, char* txt, FT_Face face, Color fgColor, Color bgColor)
{
    int rc;
    int xOffset = 0;
    int yOffset = 0;
    int totalWidth = 0;
    uint32_t* pixels = (uint32_t*)surface->pixels;

    // Get the glyph slot for bitmap and font metrics
    FT_GlyphSlot slot = face->glyph;

    // Iterate each character of the text to write to the screen
    for (int n = 0; n < strlen(txt); n++)
    {
        FT_UInt glyph_index;

        // Get the glyph for the ASCII code
        glyph_index = FT_Get_Char_Index(face, txt[n]);

        // Load and render in 8-bit color
        rc = FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);

        if (rc)
            continue;

        rc = FT_Render_Glyph(slot, ft_render_mode_normal);

        if (rc)
            continue;

        // Parse and write the bitmap to the frame buffer
        for (int yPos = 0; yPos < slot->bitmap.rows; yPos++)
        {
            for (int xPos = 0; xPos < slot->bitmap.width; xPos++)
            {
                // Decode the 8-bit bitmap
                char pixel = slot->bitmap.buffer[(yPos * slot->bitmap.width) + xPos];

                // Get new pixel coordinates to account for the character position and baseline, as well as newlines
                int x = xPos + xOffset + (slot->metrics.horiBearingX / 64);
                int y = face->size->metrics.y_ppem + yPos + yOffset - slot->bitmap_top;

                uint8_t r = (bgColor.r * (255 - 255) + pixel * fgColor.r * 255 / 255) / 255;
                uint8_t g = (bgColor.g * (255 - 255) + pixel * fgColor.g * 255 / 255) / 255;
                uint8_t b = (bgColor.b * (255 - 255) + pixel * fgColor.b * 255 / 255) / 255;

                // Create new color struct with lerp'd values
                Color finalColor = { r, g, b };

                // We need to do bounds checking before commiting the pixel write due to our transformations, or we
                // could write out-of-bounds of the texture's pixel array
                if (x < 0 || y < 0 || x >= surface->w || y >= surface->h)
                    continue;

                if (pixel != 0x00)
                {
                    // Get pixel location based on pitch
                    int pixelIdx = (y * surface->w) + x;

                    // Encode to 24-bit color
                    uint32_t encodedColor = (pixel << 24) + (finalColor.r << 16) + (finalColor.g << 8) + finalColor.b;

                    // Draw to the pixel buffer
                    pixels[pixelIdx] = encodedColor;
                }

                totalWidth += slot->bitmap.width;
            }
        }

        // Increment x offset for the next character
        xOffset += slot->advance.x >> 6;
    }

    return totalWidth;
}

SDL_Texture* CreateText(SDL_Renderer *renderer, char* txt, FT_Face fontFace, Color fgColor, Color bgColor)
{
    SDL_Surface* tempSurface;
    SDL_Texture* finalTexture;

    // Pre-calculate the surface size by counting the number of characters and multiplying by the horizontal pem for width,
    // and by using the vertical pem * 2 for the height.
    int w = strlen(txt) * fontFace->size->metrics.x_ppem;
    int h = fontFace->size->metrics.y_ppem * 2;

    tempSurface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);

    // Write the text pixels to the surface
    SetText(tempSurface, txt, fontFace, fgColor, bgColor);

    // We need to set a transparency key. However, we want to support the ability to use any arbitrary
    // background color *without* it getting keyed out. So we'll check the background color for extremes
    // (white and black), and we'll use the opposite of what is specified.
    Uint32 colorKey;

    if (bgColor.r == 0 && bgColor.g == 0 && bgColor.b == 0)
        colorKey = SDL_MapRGB(tempSurface->format, 255, 255, 255);
    else
        colorKey = SDL_MapRGB(tempSurface->format, 0, 0, 0);

    SDL_SetColorKey(tempSurface, SDL_TRUE, colorKey);

    // Derive the texture and make it blendable
    finalTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_SetTextureBlendMode(finalTexture, SDL_BLENDMODE_BLEND);

    // We no longer need the surface, we only need it for texture creation
    SDL_FreeSurface(tempSurface);

    return finalTexture;
}
