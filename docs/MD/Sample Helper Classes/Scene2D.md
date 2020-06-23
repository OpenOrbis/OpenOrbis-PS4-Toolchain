# Scene2D Helper Class
The `Scene2D` helper class is used by various samples that draw to the screen. It's provided as both an example and a helper class you can copy into your own code and hack on if you wish. Below is some documentation on the class and it's exposed methods. Non-public methods are not documented here, but can be found in the source file in `/samples/_common/graphics.cpp`.

### Constructor

```cpp
Scene2D::Scene2D(int w, int h, int pixelDepth)
```

The `Scene2D` class constructor takes three arguments. A width `w`, height `h`, and pixel depth of `pixelDepth`. These dimensions are important as they're used to calculate the size of the frame buffer for future drawing.

#### Example

```cpp
auto scene = new Scene2D(1920, 1080, 4);
```


### Init method
*Note: This function must be called before any other library functions.*

```cpp
bool Scene2D::Init(size_t memSize, int numFrameBuffers)
```

The Init method takes a total `memSize` for the direct memory allocation for backing frame buffers and the number of frame buffers to use. A large amount of memory should be provided for frame buffers, `0x6000000` per frame buffer is recommended. Along with allocating direct memory, it also handles the setup of the flip queues and frame buffer stuff under the hood.

#### Example

```cpp
if(!scene->Init(0xC000000, 2))
{
        DEBUGLOG << "Failed to initialize 2D scene";
        return -1;
}
```


### SetActiveFrameBuffer method

```cpp
void Scene2D::SetActiveFrameBuffer(int index)
```

This method is used to set the active frame buffer. Samples currently don't invoke this, and you probably don't need to either, but it's provided for those who want this capability.

#### Example

```cpp
scene->SetActiveFrameBuffer(1);
```


### SubmitFlip method

```cpp
void Scene2D::SubmitFlip(int frameID)
```

This method should be called on every draw loop iteration, and passed the frame ID. This submits a flip event to the VideoOut instance attached to the scene.

#### Example

```cpp
int frameID = 0;
// ...
for(;;)
{
	// ...
	scene->SubmitFlip(frameID);
	scene->FrameWait(frameID);
	scene->FrameBufferSwap();
	frameID++;
}
```

### FrameWait method

```cpp
void Scene2D::FrameWait(int frameID)
```

This method should also be called on every draw loop iteration directly after `::SubmitFlip`.

#### Example

```cpp
int frameID = 0;
// ...
for(;;)
{
	// ..
	scene->SubmitFlip(frameID);
	scene->FrameWait(frameID);
	scene->FrameBufferSwap();
	frameID++;
}
```

### FrameBufferSwap method

```cpp
void Scene2D::FrameBufferSwap()
```

This method should be called near the end of the draw loop before the frame ID is incremented. This is used to swap between the back and primary buffers for performance.

#### Example

```cpp
int frameID = 0;
// ...
for(;;)
{
	// ..
	scene->SubmitFlip(frameID);
	scene->FrameWait(frameID);
	scene->FrameBufferSwap();
	frameID++;
}
```


### FrameBufferClear method

```cpp
void Scene2D::FrameBufferClear()
```

Clears the frame buffer. If this method is going to be called, it should be near the beginning of the draw loop, as it'll clear any pixels written to the buffer. Writes white (0xFFFFFF) pixels to the screen.

#### Example

```cpp
scene->FrameBufferClear();
```


### FrameBufferFill method

```cpp
void Scene2D::FrameBufferFill(Color color)
```

Fills the frame buffer with the given color.

#### Example

```cpp
Color blackBg = { 0, 0, 0 };
scene->FrameBufferFill(blackBg);
```


### DrawPixel method

```cpp
void Scene2D::DrawPixel(int x, int y, Color color)
```

Draws a pixel of `color` to the given `x` and `y` coordinates on the screen.

#### Example

```cpp
Color redPixel = { 255, 0, 0 };
scene->DrawPixel(50, 50, redPixel);
```


### DrawRectangle method

```cpp
void Scene2D::DrawRectangle(int x, int y, int w, int h, Color color)
```

Draws a rectangle filled with `color` from origin coordinates `x` and `y` (anchored to top left) for `w` width and `h` height in pixels.

#### Example

```cpp
Color red = { 255, 0, 0 };
scene->DrawRectangle(50, 50, 200, 200, red);
```


### InitFont method
*Note: Only available if compiled with the `GRAPHICS_USES_FONT` macro defined.*

```cpp
bool Scene2D::InitFont(FT_Face *face, const char *fontPath, int fontSize)
```

Initializes a given font `face` with the specified `fontPath` with a size of `fontSize` in pixels. Returns true if the font face was initialized, false if an error occurred.

#### Example

```cpp
FT_Face fontTxt;

if(!scene->InitFont(&fontTxt, "/app0/arial.ttf", 42))
{
	DEBUGLOG << "Failed to initialize font '" << font << "'";
	return -1;
}
```


### DrawText method
*Note: Only available if compiled with the `GRAPHICS_USES_FONT` macro defined.*

```cpp
void Scene2D::DrawText(char *txt, FT_Face face, int startX, int startY, Color bgColor, Color fgColor)
```

Writes `txt` to the screen using the given font `face` at coordinates `startX` and `startY` (anchored to top left). Writes pixels of color `bgColor` for the background and `fgColor` for the foreground. Handles all the dirty details of pen calculations for baseline and character positions under the hood.

#### Example

```cpp
// InitFont example ...

Color bgColor = { 0, 0, 0 };
Color fgColor = { 255, 255, 255 };

scene->DrawText("Hello World!", fontTxt, 150, 150, bgColor, fgColor);
```