#ifndef _SCE_PIGLET_V2_VSH_H_
#define _SCE_PIGLET_V2_VSH_H_

#define SIZEOF_ORBIS_PGL_CONFIG 0x88
#define JOIN_HELPER(x, y) x##y
#define JOIN(x, y) JOIN_HELPER(x, y)
#define TYPE_PAD(size) char JOIN(_pad_, __COUNTER__)[size]
#define TYPE_BEGIN(name, size) name { union { TYPE_PAD(size)
#define TYPE_END(...) }; } __VA_ARGS__
#define TYPE_FIELD(field, offset) struct { TYPE_PAD(offset); field; }

TYPE_BEGIN(typedef struct _OrbisPglConfig, SIZEOF_ORBIS_PGL_CONFIG);
	TYPE_FIELD(uint32_t size, 0x00);
	TYPE_FIELD(uint32_t flags, 0x04);
	TYPE_FIELD(uint8_t processOrder, 0x08);
	TYPE_FIELD(uint32_t unk_0x0C, 0x0C);
	TYPE_FIELD(uint32_t unk_0x10, 0x10);
	TYPE_FIELD(uint32_t unk_0x14, 0x14);
	TYPE_FIELD(uint64_t systemSharedMemorySize, 0x18);

	TYPE_FIELD(uint32_t unk_0x20, 0x20);
	TYPE_FIELD(uint32_t unk_0x24, 0x24);
	TYPE_FIELD(uint64_t videoSharedMemorySize, 0x28);
	TYPE_FIELD(uint64_t maxMappedFlexibleMemory, 0x30);
	TYPE_FIELD(uint64_t minFlexibleMemoryChunkSize, 0x38);

	/* TODO: see sceCompositorSetDebugPositionCommand((uint8_t)unk_0x50, (uint16_t)unk_0x48, (uint16_t)unk_0x4C, (uint16_t)unk_0x40, (uint16_t)unk_0x44) */
	TYPE_FIELD(uint32_t dbgPosCmd_0x40, 0x40);
	TYPE_FIELD(uint32_t dbgPosCmd_0x44, 0x44);
	TYPE_FIELD(uint32_t dbgPosCmd_0x48, 0x48);
	TYPE_FIELD(uint32_t dbgPosCmd_0x4C, 0x4C);
	TYPE_FIELD(uint8_t dbgPosCmd_0x50, 0x50);

	TYPE_FIELD(uint32_t drawCommandBufferSize, 0x54);
	TYPE_FIELD(uint32_t lcueResourceBufferSize, 0x58);

	TYPE_FIELD(uint32_t unk_0x5C, 0x5C);

	TYPE_FIELD(uint64_t unk_0x60, 0x60);
	TYPE_FIELD(uint64_t unk_0x68, 0x68);
	TYPE_FIELD(uint64_t unk_0x70, 0x70);
	TYPE_FIELD(uint64_t unk_0x78, 0x78);
TYPE_END(OrbisPglConfig);

#undef TYPE_BEGIN
#undef TYPE_END
#undef TYPE_FIELD
#undef TYPE_PAD
#undef JOIN
#undef JOIN_HELPER
#undef SIZEOF_ORBIS_PGL_CONFIG

/* enables the piglet platform in KHR headers */
#define __PIGLET__            1
/* gl stuff */
#define EGL_EGLEXT_PROTOTYPES 1
#define GL_GLES_PROTOTYPES    1
#define GL_GLEXT_PROTOTYPES   1

#define ORBIS_PGL_MAX_PROCESS_ORDER             (2         )
#define ORBIS_PGL_FLAGS_USE_COMPOSITE_EXT       (0x8       )
#define ORBIS_PGL_FLAGS_SKIP_APP_INITIALIZATION (0x10      )
#define ORBIS_PGL_FLAGS_USE_TILED_TEXTURE       (0x40      )
#define ORBIS_PGL_FLAGS_USE_FLEXIBLE_MEMORY     (0x80      ) /* should be used with ORBIS_PGL_FLAGS_USE_COMPOSITE_EXT */
#define ORBIS_PGL_MAX_SYS_SHARED_MEM            (0x20000000)
#define ORBIS_PGL_MAX_VIDEO_SHARED_MEM          (0x20000000)
#define ORBIS_PGL_MAX_VIDEO_PRIV_MEM            (0x20000000)

/* and only now include all the GL stuff: */
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Sets the Piglet configuration, must be called before doing anything.
bool scePigletSetConfigurationVSH(const OrbisPglConfig *in_config);

// Will fetch the current Piglet configuration, may be different from the one you set.
bool scePigletGetConfigurationVSH(OrbisPglConfig *out_config);

// A valid display must exist, and pname can only be 1 it seems.
bool scePigletGetInteger(int32_t pname, int32_t *out_data);

// Prints heap statistics to a FILE* stream. The stream must be created by libSceLibcInternal.
uint32_t scePigletHeapDump(void *FILE_fprintf_stream, int32_t unk_1, int32_t unk_2);

// Mostly the same as scePigletHeapDump?? The stream must be created by libSceLibcInternal.
uint32_t scePigletHeapGetInfo(void *FILE_fprintf_stream, int32_t unk_1);

#ifdef __cplusplus
}
#endif

#endif
 /*_SCE_PIGLET_V2_VSH_H_*/

