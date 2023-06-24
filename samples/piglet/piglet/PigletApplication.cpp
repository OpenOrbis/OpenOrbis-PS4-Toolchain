#include "PigletApplication.hpp"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

// mostly taken from https://github.com/flatz/ps4_gl_test/blob/master/main.c
// thx flat_z!

#define STBI_ASSERT(x) do { if (!(x)) { std::cerr << "STBI_ASSERT FAILED, __LINE__ = " << __LINE__ << ", __FUNCTION__ = " << __FUNCTION__ << std::endl; for (;;); } } while(0)
#define STBI_ONLY_PNG 1
#define STB_IMAGE_STATIC 1

#define STB_IMAGE_IMPLEMENTATION 1
#include <stb/stb_image.h>

namespace nik {
    constexpr int MD5_SIZEOF = 16; // an MD5 hash is 16 bytes...
    typedef struct ShaderBlob {
        char* ident;                    // a C string name
        unsigned char hash[MD5_SIZEOF]; // checksum of data at address
        uint64_t len;                   // size of the binary blob
        unsigned char* code;            // a pointer to raw bytes...
    } OrbisShaderBlob;

    extern "C" OrbisShaderBlob scePrecompiledShaderEntries[];

    static PigletApplication g_Application{};
    PigletApplication& GetPigletApplication() {
        return g_Application;
    }

    std::pair<unsigned char*, uint64_t> PigletApplication::fetchShaderByName(const char* shaderName) {
        for (OrbisShaderBlob* entry{scePrecompiledShaderEntries}; entry->ident != nullptr; ++entry) {
            if (strcmp(shaderName, entry->ident) == 0) {
                std::cout << "Found shader " << shaderName << " at 0x" << reinterpret_cast<void*>(entry->code) << " of size " << entry->len << std::endl;
                return std::make_pair(static_cast<unsigned char*>(entry->code), static_cast<uint64_t>(entry->len));
            }
        }

        std::cerr << "Unable to find shader " << shaderName << std::endl;
        return std::make_pair(static_cast<unsigned char*>(nullptr), static_cast<uint64_t>(0));
    }

    bool PigletApplication::loadModules() {
        int ret{-1};
        int mstart_ret{0};

        // komu ne pohui stav'te laik...
        std::string prefix{sceKernelGetFsSandboxRandomWord()};
        prefix = "/" + prefix + "/common/lib/";

        // TODO: we don't need the prefix?
        std::cout << "Loading modules..." << std::endl;
        //prefix = "";

        std::cout << "Module prefix = " << prefix << std::endl;

        std::string pigletname{prefix + "libScePigletv2VSH.sprx"};
        std::string precompiledname{prefix + "libScePrecompiledShaders.sprx"};

        piglet = static_cast<int32_t>(sceKernelLoadStartModule(pigletname.c_str(), 0, nullptr, 0, nullptr, &mstart_ret));
        if (piglet < ORBIS_OK) {
            std::cerr << "Failed to load the Piglet module, err=0x" << std::hex << piglet << std::endl;
            goto err;
        }

        std::cout << "Piglet module_start() = " << mstart_ret << std::endl;

        precompiledprx = static_cast<int32_t>(sceKernelLoadStartModule(precompiledname.c_str(), 0, nullptr, 0, nullptr, &mstart_ret));
        if (precompiledprx < ORBIS_OK) {
            std::cerr << "Failed to load the Precompiled Shaders module, err=0x" << std::hex << precompiledprx << std::endl;
            goto err;
        }

        std::cout << "PrecompiledShaders module_start() = " << mstart_ret << std::endl;

        std::cout << "Modules loaded OK." << std::endl;

        return true;

    err:
        return false;
    }

    void PigletApplication::unloadModules() {
        int ret{-1};
        int mstop_ret{0};

        ret = sceKernelStopUnloadModule(precompiledprx, 0, nullptr, 0, nullptr, &mstop_ret);
        if (ret < ORBIS_OK) {
            std::cerr << "Failed to unload precompiled shaders table, err=0x" << std::hex << ret << std::endl;
        }

        precompiledprx = -1;

        ret = sceKernelStopUnloadModule(piglet, 0, nullptr, 0, nullptr, &mstop_ret);
        if (ret < ORBIS_OK) {
            std::cerr << "Failed to unload Piglet, err=0x" << std::hex << ret << std::endl;
        }

        piglet = -1;

        std::cout << "Modules unloaded." << std::endl;
    }

    bool PigletApplication::createContext(int width, int height) {
        // thanks flat_z!
        OrbisPglConfig pgl_config{};
        OrbisPglWindow render_window{ 0, static_cast<khronos_uint32_t>(width), static_cast<khronos_uint32_t>(height) };
        EGLConfig config{};
        EGLint num_configs{0};
        int ret{-1};
        int major{-1};
        int minor{-1};

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
		pgl_config.dbgPosCmd_0x40 = s_mywidth;
		pgl_config.dbgPosCmd_0x44 = s_myheight;
		pgl_config.dbgPosCmd_0x48 = 0;
		pgl_config.dbgPosCmd_0x4C = 0;
		pgl_config.unk_0x5C = 2;

        if (!scePigletSetConfigurationVSH(&pgl_config)) {
            std::cerr << "scePigletSetConfigurationVSH failed." << std::endl;
            goto err;
        }

        s_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (s_display == EGL_NO_DISPLAY) {
            std::cerr << "eglGetDisplay failed." << std::endl;;
            goto err;
        }

        if (!eglInitialize(s_display, &major, &minor)) {
            ret = eglGetError();
            std::cerr << "eglInitialize failed: 0x" << std::hex << ret << std::endl;
            goto err;
        }

        if (!eglBindAPI(EGL_OPENGL_ES_API)) {
            ret = eglGetError();
            std::cerr << "eglBindAPI failed: 0x" << std::hex << ret << std::endl;
            goto err;
        }

        if (!eglSwapInterval(s_display, 0)) {
            ret = eglGetError();
            std::cerr << "eglSwapInterval failed: 0x" << std::hex << ret << std::endl;
            goto err;
        }

        if (!eglChooseConfig(s_display, attribs, &config, 1, &num_configs)) {
            ret = eglGetError();
            std::cerr << "eglChooseConfig failed: 0x" << std::hex << ret << std::endl;
            goto err;
        }

        if (num_configs < 1) {
            std::cerr << "No available configuration found. num_configs=" << num_configs << std::endl;
            goto err;
        }

        std::cout << "Piglet num_configs = " << num_configs << std::endl;
        std::cout << "EGL version major=" << major << ",minor=" << minor << std::endl;

        s_surface = eglCreateWindowSurface(s_display, config, &render_window, window_attribs);
        if (s_surface == EGL_NO_SURFACE) {
            ret = eglGetError();
            std::cerr << "eglCreateWindowSurface failed: 0x" << std::hex << ret << std::endl;
            goto err;
        }

        s_context = eglCreateContext(s_display, config, EGL_NO_CONTEXT, ctx_attribs);
        if (s_context == EGL_NO_CONTEXT) {
            ret = eglGetError();
            std::cerr << "eglCreateContext failed: 0x" << std::hex << ret << std::endl;
            goto err;
        }

        if (!eglMakeCurrent(s_display, s_surface, s_surface, s_context)) {
            ret = eglGetError();
            std::cerr << "eglMakeCurrent failed: 0x" << std::hex << ret << std::endl;
            goto err;
        }

        std::cout << "GL_VERSION:  "  << reinterpret_cast<const char*>(glGetString(GL_VERSION )) << std::endl;
        std::cout << "GL_VENDOR:   "  << reinterpret_cast<const char*>(glGetString(GL_VENDOR  )) << std::endl;
        std::cout << "GL_RENDERER: "  << reinterpret_cast<const char*>(glGetString(GL_RENDERER)) << std::endl;
        std::cout << "Piglet context created OK." << std::endl;

        return true;
    err:
        return false;
    }

    void PigletApplication::destroyContext() {
        int ret{-1};

        /* need to unset the surface and the context before destroying */
        if (!eglMakeCurrent(s_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT)) {
            ret = eglGetError();
            std::cerr << "eglMakeCurrent failed: " << std::hex << ret << std::endl;
        }

        if (!eglDestroySurface(s_display, s_surface)) {
            ret = eglGetError();
            std::cerr << "eglDestroySurface failed: " << std::hex << ret << std::endl;
        }
        s_surface = EGL_NO_SURFACE;

        if (!eglDestroyContext(s_display, s_context)) {
            ret = eglGetError();
            std::cerr << "eglDestroyContext failed: " << std::hex << ret << std::endl;
        }
        s_context = EGL_NO_CONTEXT;

        if (!eglTerminate(s_display)) {
            ret = eglGetError();
            std::cerr << "eglTerminate failed: " << std::hex << ret << std::endl;
        }
        s_display = EGL_NO_DISPLAY;
    }

    bool PigletApplication::createTexture() {
        int ret{-1};

        std::string texturePath{"/app0/assets/images/rgba_texture.png"};
        int png_width{-1}, png_height{-1}, png_channels{-1};
        auto png_data{stbi_load(texturePath.c_str(), &png_width, &png_height, &png_channels, STBI_rgb_alpha)};

        // a PNG must be at least 1x1 px in size, and contain at least one channel.
        if (!png_data || png_width < 1 || png_height < 1 || png_channels < 1) {
            std::cerr << "stbi_load failed to load the PNG at " << texturePath << std::endl;
            goto err;
        }

        s_cat_width = png_width;
        s_cat_height = png_height;

        std::cout
            << "PNG info:"   << std::endl
            << "Path     = " << texturePath  << std::endl
            << "Width    = " << png_width    << std::endl
            << "Height   = " << png_height   << std::endl
            << "Channels = " << png_channels << std::endl;

	    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        ret = glGetError();
        if (ret) {
            std::cerr << "glPixelStorei failed: " << std::hex << ret << std::endl;
            goto err;
        }

        glGenTextures(1, &s_texture_id);
        ret = glGetError();
        if (ret) {
            std::cerr << "glGenTextures failed: " << std::hex << ret << std::endl;
            goto err;
        }

        glBindTexture(GL_TEXTURE_2D, s_texture_id);
        ret = glGetError();
        if (ret) {
            std::cerr << "glBindTexture failed: " << std::hex << ret << std::endl;
            goto err;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, png_width, png_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, png_data);
        ret = glGetError();
        if (ret) {
            std::cerr << "glTexImage2D failed: " << std::hex << ret << std::endl;
            goto err;
        }

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        ret = glGetError();
        if (ret) {
            std::cerr << "glTexParameteri 1 failed: " << std::hex << ret << std::endl;
            goto err;
        }

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        ret = glGetError();
        if (ret) {
            std::cerr << "glTexParameteri 2 failed: " << std::hex << ret << std::endl;
            goto err;
        }

        stbi_image_free(png_data);
        png_data = nullptr;

        std::cout << "Texture created OK." << std::endl;
        return true;

    err:
        return false;
    }

    void PigletApplication::destroyTexture() {
        int ret{-1};

        glDeleteTextures(1, &s_texture_id);
        ret = glGetError();
        if (ret) {
            std::cerr << "glDeleteTextures failed: " << std::hex << ret << std::endl;
        }
        s_texture_id = GL_NONE;
    }

    bool PigletApplication::createShaders() {
        // the fun stuff...
        int ret{-1};
        GLint i{0};
        GLuint vertex_id{GL_NONE};
        GLuint fragment_id{GL_NONE};
        GLint count{-1};

        // returns an address|length std::pair

        // for TW: these shaders come from precompiled lib, the webkit ones ;-;
        auto vert{fetchShaderByName("texmap/v_2.vert")};
        auto frag{fetchShaderByName("texmap/f_2.frag")};

        if (vert.second == 0 || frag.second == 0) {
            std::cerr << "Failed to fetch precompiled shaders." << std::endl;
            goto err;
        }
        

        fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
        if (!fragment_id) {
            std::cerr << "glCreateShader frag failed: " << std::endl;
            goto err;
        }

        vertex_id = glCreateShader(GL_VERTEX_SHADER);
        if (!vertex_id) {
            std::cerr << "glCreateShader vert failed: " << std::endl;
            goto err;
        }

        s_program_id = glCreateProgram();
        if (!s_program_id) {
            std::cerr << "glCreateProgram failed: " << std::endl;
            goto err;
        }

        // PS4's glShaderBinary only has format 0 which is PSSL

        glShaderBinary(1, &vertex_id, 0, vert.first, vert.second);
        ret = glGetError();
        if (ret) {
            std::cerr << "glShaderBinary vert failed: " << std::hex << ret << std::endl;
            goto err;
        }
        
        glShaderBinary(1, &fragment_id, 0, frag.first, frag.second);
        ret = glGetError();
        if (ret) {
            std::cerr << "glShaderBinary frag failed: " << std::hex << ret << std::endl;
            goto err;
        }

        glAttachShader(s_program_id, vertex_id);
        ret = glGetError();
        if (ret) {
            std::cerr << "glAttachShader vert failed: " << std::hex << ret << std::endl;
            goto err;
        }

        glAttachShader(s_program_id, fragment_id);
        ret = glGetError();
        if (ret) {
            std::cerr << "glAttachShader frag failed: " << std::hex << ret << std::endl;
            goto err;
        }

        glLinkProgram(s_program_id);
        ret = glGetError();
        if (ret) {
            std::cerr << "glLinkProgram failed: " << std::hex << ret << std::endl;
            goto err;
        }

        // fetch shader stuff:
        s_u_modelViewMatrix = glGetUniformLocation(s_program_id, "u_modelViewMatrix");
        ret = glGetError();
        if (ret || s_u_modelViewMatrix < 0) {
            std::cerr << "glGetUniformLocation u_modelViewMatrix failed: " << std::hex << ret << std::endl;
            goto err;
        }

        s_u_projectionMatrix = glGetUniformLocation(s_program_id, "u_projectionMatrix");
        ret = glGetError();
        if (ret || s_u_projectionMatrix < 0) {
            std::cerr << "glGetUniformLocation u_projectionMatrix failed: " << std::hex << ret << std::endl;
            goto err;
        }

        s_u_textureSpaceMatrix = glGetUniformLocation(s_program_id, "u_textureSpaceMatrix");
        ret = glGetError();
        if (ret || s_u_textureSpaceMatrix < 0) {
            std::cerr << "glGetUniformLocation u_projectionMatrix failed: " << std::hex << ret << std::endl;
            goto err;
        }

        s_s_sampler = glGetUniformLocation(s_program_id, "s_sampler");
        ret = glGetError();
        if (ret || s_s_sampler < 0) {
            std::cerr << "glGetUniformLocation s_sampler failed: " << std::hex << ret << std::endl;
            goto err;
        }

        s_u_opacity = glGetUniformLocation(s_program_id, "u_opacity");
        ret = glGetError();
        if (ret || s_u_opacity < 0) {
            std::cerr << "glGetUniformLocation u_opacity failed: " << std::hex << ret << std::endl;
            goto err;
        }

        s_a_vertex = glGetAttribLocation(s_program_id, "a_vertex");
        ret = glGetError();
        if (ret || s_a_vertex < 0) {
            std::cerr << "glGetAttribLocation a_vertex failed: " << std::hex << ret << std::endl;
            goto err;
        }

        std::cout << "Shader fetch OK." << std::endl;
        
        /* dump the uniforms and attributes */
        
        glGetProgramiv(s_program_id, GL_ACTIVE_UNIFORMS, &count);
        for (i = 0; i < count; ++i) {
            GLsizei unilen{-1};
            GLint unisize{-1};
            GLenum unitype{0};
            char unibuff[64]{'\0'};

            glGetActiveUniform(s_program_id, i, (sizeof(unibuff) - 1), &unilen, &unisize, &unitype, unibuff);

            if (unilen > 0) {
                std::cout << "-- Uniform begin --" << std::endl;
                std::cout << "Name = " << unibuff << std::endl;
                std::cout << "Type = 0x" << std::hex << unitype << std::dec << std::endl;
                std::cout << "Size = " << unisize << std::endl;
                std::cout << "-- Uniform end --" << std::endl;
            }
        }

        glGetProgramiv(s_program_id, GL_ACTIVE_ATTRIBUTES, &count);
        for (i = 0; i < count; ++i) {
            GLsizei unilen{-1};
            GLint unisize{-1};
            GLenum unitype{0};
            char unibuff[64]{'\0'};

            glGetActiveAttrib(s_program_id, i, (sizeof(unibuff) - 1), &unilen, &unisize, &unitype, unibuff);

            if (unilen > 0) {
                std::cout << "-- Attribute begin --" << std::endl;
                std::cout << "Name = " << unibuff << std::endl;
                std::cout << "Type = 0x" << std::hex << unitype << std::dec << std::endl;
                std::cout << "Size = " << unisize << std::endl;
                std::cout << "-- Attribute end --" << std::endl;
            }
        }
        

        /* shaders will be auto freed when the program gets freed */

        glDeleteShader(vertex_id);
        ret = glGetError();
        if (ret) {
            std::cerr << "glDeleteShader vert failed: " << std::hex << ret << std::endl;
            goto err;
        }

        vertex_id = GL_NONE;

        glDeleteShader(fragment_id);
        ret = glGetError();
        if (ret) {
            std::cerr << "glDeleteShader frag failed: " << std::hex << ret << std::endl;
            goto err;
        }

        fragment_id = GL_NONE;

        std::cout << "Shaders created OK." << std::endl;
        return true;

    err:
        glDeleteShader(fragment_id);
        glDeleteShader(vertex_id);
        glDeleteProgram(s_program_id);
        return false;
    }

    void PigletApplication::destroyShaders() {
        int ret{-1};

        glDeleteProgram(s_program_id);
        ret = glGetError();
        if (ret) {
            std::cerr << "glDeleteProgram failed: " << std::hex << ret << std::endl;
        }
        s_program_id = GL_NONE;
    }

    bool PigletApplication::setup() {
        int ret{-1};

        // internal SystemService...
        // need to load it once, no need to unload.
        sceSysmoduleLoadModuleInternal(ORBIS_SYSMODULE_INTERNAL_SYSTEM_SERVICE);

        ret = sceSystemServiceHideSplashScreen();
        if (ret < ORBIS_OK) {
            std::cerr << "sceSystemServiceHideSplashScreen failed: " << std::hex << ret << std::endl;
            goto err;
        }

        std::cout << "setup OK" << std::endl;

        return true;

    err:
        return false;
    }

    void PigletApplication::drawTexture(GLuint _tex, float _x, float _y, float _w, float _h, float _rotate, float _opacity) {
        GLfloat vertices[] = { 
            // pos      // tex
            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 
        
            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f
        };

        glm::mat4 texturespace{glm::mat4(1.0f)};
        glm::mat4 projection{glm::ortho(0.0f, static_cast<float>(s_mywidth), static_cast<float>(s_myheight), 0.0f, -1.0f, 1.0f)};
        glm::mat4 model{glm::mat4(1.0f)};
        glm::vec2 position{_x, _y};
        glm::vec2 size{_w, _h};

        model = glm::translate(model, glm::vec3(position, 0.0f));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)
        model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f)); // move origin of rotation to center of quad
        model = glm::rotate(model, glm::radians(_rotate), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate
        model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f)); // move origin back
        model = glm::scale(model, glm::vec3(size, 1.0f)); // last scale

        //texturespace = glm::scale(texturespace, glm::vec3(2.0f, 2.0f, 0.0f));

        // enable the shader:
        glUseProgram(s_program_id);

        // do it:
        glUniform1f(s_u_opacity, _opacity);
        glUniformMatrix4fv(s_u_modelViewMatrix, 1, GL_FALSE, &model[0][0]);
        glUniformMatrix4fv(s_u_projectionMatrix, 1, GL_FALSE, &projection[0][0]);
        glUniformMatrix4fv(s_u_textureSpaceMatrix, 1, GL_FALSE, &texturespace[0][0]);
        glVertexAttribPointer(s_a_vertex, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), vertices);
        glEnableVertexAttribArray(s_a_vertex);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, s_texture_id);
        glUniform1i(s_s_sampler, 0);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    void PigletApplication::doFrame() {
        // center the KITTY
        float _catX{((float)s_mywidth)/2.f - ((float)s_cat_width) / 2.f};
        float _catY{((float)s_myheight)/2.f - ((float)s_cat_height) / 2.f};

        // angle lmao
        static int counter{0};
        float _rotate{(float)(++counter % 360)};

        drawTexture(s_texture_id, _catX, _catY, s_cat_width, s_cat_height, _rotate, 1.f);
    }

    bool PigletApplication::Init() {
        if (!loadModules()) {
            std::cerr << "Module load failed." << std::endl;
            return false;
        }

        if (!createContext(s_mywidth, s_myheight)) {
            std::cerr << "Failed to create the EGL application context." << std::endl;
            return false;
        }

        if (!createTexture()) {
            std::cerr << "Failed to create the GL texture." << std::endl;
            return false;
        }

        if (!createShaders()) {
            std::cerr << "Failed to load the shaders." << std::endl;
            return false;
        }

        if (!setup()) {
            std::cerr << "Failed to setup the state." << std::endl;
            return false;
        }

        std::cout << "PigletApplication Init OK. NEW" << std::endl;
        return true;
    }

    bool PigletApplication::Logic() {
        // not much is happening here...
        // see Render() for more interesting stuff...

        if (s_shouldquit) {
            std::cout << "Exit is requested, quitting..." << std::endl;
            return false;
        }

        // * o i n k * //

        return true;
    }

    void PigletApplication::Render() {
        int ret{-1};

        // frame start:
		glViewport(0, 0, s_mywidth, s_myheight);
        ret = glGetError();
        if (ret) {
            std::cerr << "glViewport failed: " << std::hex << ret << std::endl;
            s_shouldquit = true;
            return;
        }

        glClearColor(s_screencolor[0], s_screencolor[1], s_screencolor[2], s_screencolor[3]);
        ret = glGetError();
        if (ret) {
            std::cerr << "glClearColor failed: " << std::hex << ret << std::endl;
            s_shouldquit = true;
            return;
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        ret = glGetError();
        if (ret) {
            std::cerr << "glClear failed: " << std::hex << ret << std::endl;
            s_shouldquit = true;
            return;
        }

        // enable alpha blending:
        glEnable(GL_BLEND);
        ret = glGetError();
        if (ret) {
            std::cerr << "glEnable failed: " << std::hex << ret << std::endl;
            s_shouldquit = true;
            return;
        }

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        ret = glGetError();
        if (ret) {
            std::cerr << "glBlendFunc failed: " << std::hex << ret << std::endl;
            s_shouldquit = true;
            return;
        }

        // the fun stuff:
        doFrame();

        // commit:
		if (!eglSwapBuffers(s_display, s_surface)) {
            ret = eglGetError();
            std::cerr << "eglSwapBuffers failed: " << std::hex << ret << std::endl;
            s_shouldquit = true;
            return;
        }
    }

    PigletApplication::~PigletApplication() {
        std::cout << "Shutting down PigletApplication..." << std::endl;

        if (piglet >= 0) {
            destroyShaders();
            destroyTexture();
            destroyContext();
            unloadModules();
        }

        std::cout << "Shutdown complete." << std::endl;
    }


} // namespace nik
