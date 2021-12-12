#include "ootk_GraphicsManager.hpp"

#include <cstring>

void ootk::GraphicsManager::Init(int width, int height) {
    // thanks flat_z!
    OrbisPglConfig pgl_config{};
    OrbisPglWindow render_window{ 0, static_cast<khronos_uint32_t>(width), static_cast<khronos_uint32_t>(height) };
    EGLConfig config{};
    EGLint num_configs{0};
    int ret{-1};
    int major{-1};
    int minor{-1};

    ctx_width = width;
    ctx_height = height;

    const EGLint attribs[]{
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 0,
        EGL_STENCIL_SIZE, 0,
        EGL_SAMPLE_BUFFERS, 0,
        EGL_SAMPLES, 0,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_NONE,
    };

    const EGLint ctx_attribs[]{
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE,
    };

    const EGLint window_attribs[]{
        EGL_RENDER_BUFFER, EGL_BACK_BUFFER,
        EGL_NONE,
    };

    std::memset(&pgl_config, 0, sizeof(pgl_config));
    pgl_config.size = sizeof(pgl_config);
    pgl_config.flags = ORBIS_PGL_FLAGS_USE_COMPOSITE_EXT | ORBIS_PGL_FLAGS_USE_FLEXIBLE_MEMORY | 0x60;
    pgl_config.processOrder = 1;
    pgl_config.systemSharedMemorySize=250*1024*1024;
    pgl_config.videoSharedMemorySize=512*1024*1024; 
    pgl_config.maxMappedFlexibleMemory=170*1024*1024;
    pgl_config.drawCommandBufferSize=1*1024*1024;
    pgl_config.lcueResourceBufferSize=1*1024*1024;
    pgl_config.dbgPosCmd_0x40 = ctx_width;
    pgl_config.dbgPosCmd_0x44 = ctx_height;
    pgl_config.dbgPosCmd_0x48 = 0;
    pgl_config.dbgPosCmd_0x4C = 0;
    pgl_config.unk_0x5C = 2;

    if (!scePigletSetConfigurationVSH(&pgl_config)) {
        throw Exception("Failed to set piglet configuration.");
    }

    ctx_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (ctx_display == EGL_NO_DISPLAY) {
        throw Exception("Failed to get EGL display, err = %X.", eglGetError());
    }

    if (eglInitialize(ctx_display, &major, &minor) == EGL_FALSE) {
        throw Exception("Failed to initialize EGL, err = %X.", eglGetError());
    }

    if (eglBindAPI(EGL_OPENGL_ES_API) == EGL_FALSE) {
        throw Exception("Failed to bind EGL API, err = %X.", eglGetError());
    }

    if (eglSwapInterval(ctx_display, 0) == EGL_FALSE) {
        throw Exception("Failed to set display swap interval, err = %X.", eglGetError());
    }

    if (eglChooseConfig(ctx_display, attribs, &config, 1, &num_configs) == EGL_FALSE) {
        throw Exception("Failed to choose EGL config, err = %X.", eglGetError());
    }

    if (num_configs < 1) {
        throw Exception("Failed to obtain EGL configs. num = %d", eglGetError());
    }

    ctx_surface = eglCreateWindowSurface(ctx_display, config, &render_window, window_attribs);
    if (ctx_surface == EGL_NO_SURFACE) {
        throw Exception("Failed to create an EGL surface. err = %X", eglGetError());
    }

    ctx_context = eglCreateContext(ctx_display, config, EGL_NO_CONTEXT, ctx_attribs);
    if (ctx_context == EGL_NO_CONTEXT) {
        throw Exception("Failed to create an EGL context. err = %X", eglGetError());
    }

    if (eglMakeCurrent(ctx_display, ctx_surface, ctx_surface, ctx_context) == EGL_FALSE) {
        throw Exception("Failed to set up EGL ctx/surf/display. err = %X", eglGetError());
    }
}

void ootk::GraphicsManager::Logic() {
    // nothing for now, might want to update collisions here etcetc
}

void ootk::GraphicsManager::BeginRender() {

}

void ootk::GraphicsManager::EndRender() {

}

