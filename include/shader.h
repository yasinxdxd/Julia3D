#ifndef _JULIA3D_SHADER_H_
#define _JULIA3D_SHADER_H_

#include <defs.h>

JULIA3D_CORE struct _J3DShaderProgram
{
    char* vertex_shader_source;
    char* fragment_shader_source;
    ui32_t shader_program;
};
typedef struct _J3DShaderProgram* J3DShaderProgram;

JULIA3D_CORE void j3d_load_shader_sources(J3DShaderProgram program, const char* frag_path, const char* vert_path);
JULIA3D_CORE void j3d_free_shader_sources(J3DShaderProgram program);
JULIA3D_CORE void j3d_compile_and_link_shader(J3DShaderProgram program);

//uniforms:
JULIA3D_CORE void uniform1d(J3DShaderProgram program, const char* name, double value );
JULIA3D_CORE void uniform1f(J3DShaderProgram program, const char* name, float value);
JULIA3D_CORE void uniform1i(J3DShaderProgram program, const char* name, int value);
JULIA3D_CORE void uniform1ui(J3DShaderProgram program, const char* name, unsigned int value);
JULIA3D_CORE void uniform2d(J3DShaderProgram program, const char* name, double v0, double v1);
JULIA3D_CORE void uniform2f(J3DShaderProgram program, const char* name, float v0, float v1);
JULIA3D_CORE void uniform2i(J3DShaderProgram program, const char* name, int v0, int v1);
JULIA3D_CORE void uniform2ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1);
JULIA3D_CORE void uniform3d(J3DShaderProgram program, const char* name, double v0, double v1, double v2);
JULIA3D_CORE void uniform3f(J3DShaderProgram program, const char* name, float v0, float v1, float v2);
JULIA3D_CORE void uniform3i(J3DShaderProgram program, const char* name, int v0, int v1, int v2);
JULIA3D_CORE void uniform3ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1, unsigned int v2);
JULIA3D_CORE void uniform4d(J3DShaderProgram program, const char* name, double v0, double v1, double v2, double v3);
JULIA3D_CORE void uniform4f(J3DShaderProgram program, const char* name, float v0, float v1, float v2, float v3);
JULIA3D_CORE void uniform4i(J3DShaderProgram program, const char* name, int v0, int v1, int v2, int v3);
JULIA3D_CORE void uniform4ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3);

JULIA3D_CORE //uniform vectors:
JULIA3D_CORE void uniform1dv(J3DShaderProgram program, const char* name, int count, const double* value);
JULIA3D_CORE void uniform1fv(J3DShaderProgram program, const char* name, int count, const float* value);
JULIA3D_CORE void uniform1iv(J3DShaderProgram program, const char* name, int count, const int* value);
JULIA3D_CORE void uniform1uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value);
JULIA3D_CORE void uniform2dv(J3DShaderProgram program, const char* name, int count, const double* value);
JULIA3D_CORE void uniform2fv(J3DShaderProgram program, const char* name, int count, const float* value);
JULIA3D_CORE void uniform2iv(J3DShaderProgram program, const char* name, int count, const int* value);
JULIA3D_CORE void uniform2uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value);
JULIA3D_CORE void uniform3dv(J3DShaderProgram program, const char* name, int count, const double* value);
JULIA3D_CORE void uniform3fv(J3DShaderProgram program, const char* name, int count, const float* value);
JULIA3D_CORE void uniform3iv(J3DShaderProgram program, const char* name, int count, const int* value);
JULIA3D_CORE void uniform3uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value);
JULIA3D_CORE void uniform4dv(J3DShaderProgram program, const char* name, int count, const double* value);
JULIA3D_CORE void uniform4fv(J3DShaderProgram program, const char* name, int count, const float* value);
JULIA3D_CORE void uniform4iv(J3DShaderProgram program, const char* name, int count, const int* value);
JULIA3D_CORE void uniform4uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value);
 
JULIA3D_CORE //uniform matrices:
JULIA3D_CORE void uniformMatrix2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
JULIA3D_CORE void uniformMatrix3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
JULIA3D_CORE void uniformMatrix4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
JULIA3D_CORE void uniformMatrix2x3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
JULIA3D_CORE void uniformMatrix3x2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
JULIA3D_CORE void uniformMatrix2x4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
JULIA3D_CORE void uniformMatrix4x2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
JULIA3D_CORE void uniformMatrix3x4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
JULIA3D_CORE void uniformMatrix4x3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
JULIA3D_CORE void uniformMatrix2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
JULIA3D_CORE void uniformMatrix3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
JULIA3D_CORE void uniformMatrix4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
JULIA3D_CORE void uniformMatrix2x3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
JULIA3D_CORE void uniformMatrix3x2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
JULIA3D_CORE void uniformMatrix2x4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
JULIA3D_CORE void uniformMatrix4x2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
JULIA3D_CORE void uniformMatrix3x4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
JULIA3D_CORE void uniformMatrix4x3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);


#endif//_JULIA3D_SHADER_H_