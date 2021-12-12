
#pragma once
#include <orbis/Pigletv2VSH.h>
#include "ootk_Exception.hpp"

namespace ootk {
    class GraphicsManager {
    private:
        int ctx_width{-1};
        int ctx_height{-1};
        EGLContext ctx_context{EGL_NO_CONTEXT};
        EGLDisplay ctx_display{EGL_NO_DISPLAY};
        EGLSurface ctx_surface{EGL_NO_SURFACE};
    
    public:
        void Init(int width, int height);
        void Logic();
        void BeginRender();
        void EndRender();
    };
}

