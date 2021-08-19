#ifndef _JULIA3D_SHADER_H_
#define _JULIA3D_SHADER_H_

#include "defs.h"

struct _J3DShaderProgram;
typedef struct _J3DShaderProgram* J3DShaderProgram;

void j3d_compile_shader();

//uniforms:
void uniform1d(J3DShaderProgram program, const char* name, double value );
void uniform1f(J3DShaderProgram program, const char* name, float value);
void uniform1i(J3DShaderProgram program, const char* name, int value);
void uniform1ui(J3DShaderProgram program, const char* name, unsigned int value);
void uniform2d(J3DShaderProgram program, const char* name, double v0, double v1);
void uniform2f(J3DShaderProgram program, const char* name, float v0, float v1);
void uniform2i(J3DShaderProgram program, const char* name, int v0, int v1);
void uniform2ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1);
void uniform3d(J3DShaderProgram program, const char* name, double v0, double v1, double v2);
void uniform3f(J3DShaderProgram program, const char* name, float v0, float v1, float v2);
void uniform3i(J3DShaderProgram program, const char* name, int v0, int v1, int v2);
void uniform3ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1, unsigned int v2);
void uniform4d(J3DShaderProgram program, const char* name, double v0, double v1, double v2, double v3);
void uniform4f(J3DShaderProgram program, const char* name, float v0, float v1, float v2, float v3);
void uniform4i(J3DShaderProgram program, const char* name, int v0, int v1, int v2, int v3);
void uniform4ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3);

//uniform vectors:
void uniform1dv(J3DShaderProgram program, const char* name, int count, const double* value);
void uniform1fv(J3DShaderProgram program, const char* name, int count, const float* value);
void uniform1iv(J3DShaderProgram program, const char* name, int count, const int* value);
void uniform1uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value);
void uniform2dv(J3DShaderProgram program, const char* name, int count, const double* value);
void uniform2fv(J3DShaderProgram program, const char* name, int count, const float* value);
void uniform2iv(J3DShaderProgram program, const char* name, int count, const int* value);
void uniform2uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value);
void uniform3dv(J3DShaderProgram program, const char* name, int count, const double* value);
void uniform3fv(J3DShaderProgram program, const char* name, int count, const float* value);
void uniform3iv(J3DShaderProgram program, const char* name, int count, const int* value);
void uniform3uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value);
void uniform4dv(J3DShaderProgram program, const char* name, int count, const double* value);
void uniform4fv(J3DShaderProgram program, const char* name, int count, const float* value);
void uniform4iv(J3DShaderProgram program, const char* name, int count, const int* value);
void uniform4uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value);

//uniform matrices:
void uniformMatrix2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
void uniformMatrix3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
void uniformMatrix4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
void uniformMatrix2x3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
void uniformMatrix3x2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
void uniformMatrix2x4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
void uniformMatrix4x2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
void uniformMatrix3x4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
void uniformMatrix4x3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value);
void uniformMatrix2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
void uniformMatrix3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
void uniformMatrix4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
void uniformMatrix2x3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
void uniformMatrix3x2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
void uniformMatrix2x4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
void uniformMatrix4x2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
void uniformMatrix3x4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);
void uniformMatrix4x3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value);


#endif//_JULIA3D_SHADER_H_