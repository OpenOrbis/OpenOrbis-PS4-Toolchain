This directory contains code that is shared by multiple samples. Currently this includes the following files:

- graphics.cpp / header: Contains the `Scene2D` class used for CPU rendering and drawing pixels, rectangles, and text if the `GRAPHICS_USES_FONT` macro is defined.
- png.cpp / header: Contains the `PNG` class used for decoding and drawing PNG files.
- log.h: Contains the DEBUGLOG macro and it's backing class. Used for writing to stdout as a stringstream.
- glm / GLMath library, https://github.com/g-truc/glm
