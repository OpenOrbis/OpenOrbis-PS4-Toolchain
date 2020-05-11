#ifndef __gl2sce_h_
#define __gl2sce_h_ 1

#ifdef __cplusplus
extern "C" {
#endif

#define glGetProgramBinary glPigletGetShaderBinarySCE

#define glTexImageCanvas2D glOrbisTexImageCanvas2DSCE
#define glTexImageResource glOrbisTexImageResourceSCE

#define glMapTextureResource glOrbisMapTextureResourceSCE
#define glUnmapTextureResource glOrbisUnmapTextureResourceSCE

void glOrbisTexImageCanvas2DSCE(GLenum target, GLuint uCanvasHandle);
void glOrbisTexImageResourceSCE(GLenum target, const GLvoid* texture_resource_descriptor, GLsizei descriptor_size);

void glOrbisMapTextureResourceSCE(GLenum target, GLvoid* texture_resource_descriptor, GLsizei* descriptor_size);
void glOrbisUnmapTextureResourceSCE(GLenum target);

void glPigletGetShaderBinarySCE(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary);

#ifdef __cplusplus
}
#endif

#endif
