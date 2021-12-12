#ifndef _PIGLETAPPLICATION_HPP_
#define _PIGLETAPPLICATION_HPP_ 1

// global headers:
#include <iostream>
#include <string>
#include <utility>

// only include piglet through the piglet header
// don't include any gl stuff manually, everything must be done through the pig h
#include <orbis/Pigletv2VSH.h>
#include <orbis/libkernel.h>
#include <orbis/SystemService.h>
#include <orbis/Sysmodule.h>




// rtc sony
#include <orbis/Rtc.h>



#include "ApplicationBase.hpp"

namespace nik {
    class PigletApplication : public ooexamples::ApplicationBase {
    private:

    // fields:
        int32_t piglet{-1};
        int32_t precompiledprx{-1};
        EGLDisplay s_display{EGL_NO_DISPLAY};
        EGLSurface s_surface{EGL_NO_SURFACE};
        EGLContext s_context{EGL_NO_CONTEXT};

        GLuint s_texture_id{GL_NONE};
        GLuint s_program_id{GL_NONE};

        // RGB=64, A=255
		// a nice gray shape :3
        GLfloat s_screencolor[4]{
            64.f / 255.f, 64.f / 255.f, 64.f / 255.f, 255.f / 255.f
        };

        int s_mywidth{1920};
        int s_myheight{1080};
        float s_opacity{1.f};

        /*
Found shader texmap/v_2.vert at 0x0x81cd546e0 of size 1076
Found shader texmap/f_2.frag at 0x0x81cd57d80 of size 552
Name = u_modelViewMatrix
Type = 0x8b5c MAT4x4
Size = 1
Name = u_projectionMatrix
Type = 0x8b5c MAT4x4
Size = 1
Name = u_textureSpaceMatrix
Type = 0x8b5c MAT4x4
Size = 1
Name = s_sampler
Type = 0x8b5e SAMPLER_2D
Size = 1
Name = u_opacity
Type = 0x1406 FLOAT
Size = 1
Name = a_vertex [ATTRIBUTE]
Type = 0x8b52 FLOAT_VEC4
Size = 1
            
        */

        // shaders:
        GLint s_u_modelViewMatrix{-1};
        GLint s_u_projectionMatrix{-1};
        GLint s_u_textureSpaceMatrix{-1};
        GLint s_s_sampler{-1};
        GLint s_u_opacity{-1};
        GLint s_a_vertex{-1};

        bool s_shouldquit{false};


        int s_cat_width{0};
        int s_cat_height{0};


    // methods:

        void drawTexture(GLuint _tex, float _x, float _y, float _w, float _h, float _rotate, float _opacity);

        bool loadModules();
        void unloadModules();

        bool createContext(int width, int height);
        void destroyContext();

        bool createTexture();
        void destroyTexture();

        bool createShaders();
        void destroyShaders();

        bool setup();

        void doFrame();

		// ......
        std::pair<unsigned char*, uint64_t> fetchShaderByName(const char* shaderName);
    
    public:
    
        // Initializes the application
        // Returns false on unsuccessful initialization
        bool Init() override;
        // Updates the logic of the app
        // Returns false if should break out of the application loop
        bool Logic() override;
        // Renders the app
        // Must be called in the application loop
        void Render() override;
        // Finishes the app
        ~PigletApplication() override;

    };

    PigletApplication& GetPigletApplication();
}

#endif /* _PIGLETAPPLICATION_HPP_ */
