# PNG Helper Class
The `PNG` helper class is used by samples that need PNG decoding and draw images to the screen. It's provided as both an example and a helper class you can copy into your own code and hack on if you wish. Below is some documentation on the class and it's exposed methods. The source file can be found at `/samples/_common/png.cpp`.

*Note: This class leverages the STB header library for PNG decoding*

### Constructor

```cpp
PNG::PNG(const char *imagePath)
```

The `PNG` class constructor takes only one argument, being the path of the image to load, decode, and render.

#### Example

```cpp
auto logo = new PNG("/app0/logo.png");
```


### Destructor

```cpp
PNG::~PNG()
```

The `PNG` class destructor frees the heap memory used to store the bitmap for the decoded PNG.

#### Example

```cpp
delete logo;
```


### Draw method

```cpp
PNG::Draw(Scene2D *scene, int startX, int startY)
```

The draw method takes a `Scene2D` object instance and draws the loaded PNG to it at coordinates `startX` and `startY` (anchored to top left).