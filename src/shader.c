#include <shader.h>
#include <glad/glad.h>
#include <stdio.h>

struct _J3DShaderProgram
{
    const char* vertex_shader_source, fragment_shader_source;
    unsigned int shader_program;
};

void j3d_compile_shader(J3DShaderProgram program)
{
    // build and compile our shader program
    // ------------------------------------
    
    // vertex shader
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &program->vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    }

    // fragment shader
    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &program->fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    
    // check for shader compile errors
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
    }
    
    // link shaders
    program->shader_program = glCreateProgram();
    glAttachShader(program->shader_program, vertex_shader);
    glAttachShader(program->shader_program, fragment_shader);
    glLinkProgram(program->shader_program);
    
    // check for linking errors
    glGetProgramiv(program->shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program->shader_program, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
    }
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void uniform1d(J3DShaderProgram program, const char* name, double value)
{
    glUniform1d(glGetUniformLocation(program->shader_program, name), value);
}

void uniform1f(J3DShaderProgram program, const char* name, float value)
{
    glUniform1f(glGetUniformLocation(program->shader_program, name), value);
}

void uniform1i(J3DShaderProgram program, const char* name, int value)
{
    glUniform1i(glGetUniformLocation(program->shader_program, name), value);
}

void uniform1ui(J3DShaderProgram program, const char* name, unsigned int value)
{
    glUniform1ui(glGetUniformLocation(program->shader_program, name), value);
}

void uniform2d(J3DShaderProgram program, const char* name, double v0, double v1)
{
    glUniform2d(glGetUniformLocation(program->shader_program, name), v0, v1);
}

void uniform2f(J3DShaderProgram program, const char* name, float v0, float v1)
{
    glUniform2f(glGetUniformLocation(program->shader_program, name), v0, v1);
}

void uniform2i(J3DShaderProgram program, const char* name, int v0, int v1)
{
    glUniform2i(glGetUniformLocation(program->shader_program, name), v0, v1);
}

void uniform2ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1)
{
    glUniform2ui(glGetUniformLocation(program->shader_program, name), v0, v1);
}

void uniform3d(J3DShaderProgram program, const char* name, double v0, double v1, double v2)
{
    glUniform3d(glGetUniformLocation(program->shader_program, name), v0, v1, v2);
}

void uniform3f(J3DShaderProgram program, const char* name, float v0, float v1, float v2)
{
    glUniform3f(glGetUniformLocation(program->shader_program, name), v0, v1, v2);
}

void uniform3i(J3DShaderProgram program, const char* name, int v0, int v1, int v2)
{
    glUniform3i(glGetUniformLocation(program->shader_program, name), v0, v1, v2);
}

void uniform3ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1, unsigned int v2)
{
    glUniform3ui(glGetUniformLocation(program->shader_program, name), v0, v1, v2);
}

void uniform4d(J3DShaderProgram program, const char* name, double v0, double v1, double v2, double v3)
{
    glUniform4d(glGetUniformLocation(program->shader_program, name), v0, v1, v2, v3);
}

void uniform4f(J3DShaderProgram program, const char* name, float v0, float v1, float v2, float v3)
{
    glUniform4f(glGetUniformLocation(program->shader_program, name), v0, v1, v2, v3);
}

void uniform4i(J3DShaderProgram program, const char* name, int v0, int v1, int v2, int v3)
{
    glUniform4i(glGetUniformLocation(program->shader_program, name), v0, v1, v2, v3);
}

void uniform4ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3)
{
    glUniform4ui(glGetUniformLocation(program->shader_program, name), v0, v1, v2, v3);
}

//uniform vectors:

void uniform1dv(J3DShaderProgram program, const char* name, int count, const double* value)
{
    glUniform1dv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform1fv(J3DShaderProgram program, const char* name, int count, const float* value)
{
    glUniform1fv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform1iv(J3DShaderProgram program, const char* name, int count, const int* value)
{
    glUniform1iv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform1uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value)
{
    glUniform1uiv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform2dv(J3DShaderProgram program, const char* name, int count, const double* value)
{
    glUniform2dv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform2fv(J3DShaderProgram program, const char* name, int count, const float* value)
{
    glUniform2fv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform2iv(J3DShaderProgram program, const char* name, int count, const int* value)
{
    glUniform2iv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform2uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value)
{
    glUniform2uiv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform3dv(J3DShaderProgram program, const char* name, int count, const double* value)
{
    glUniform3dv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform3fv(J3DShaderProgram program, const char* name, int count, const float* value)
{
    glUniform3fv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform3iv(J3DShaderProgram program, const char* name, int count, const int* value)
{
    glUniform3iv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform3uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value)
{
    glUniform3uiv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform4dv(J3DShaderProgram program, const char* name, int count, const double* value)
{
    glUniform4dv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform4fv(J3DShaderProgram program, const char* name, int count, const float* value)
{
    glUniform4fv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform4iv(J3DShaderProgram program, const char* name, int count, const int* value)
{
    glUniform4iv(glGetUniformLocation(program->shader_program, name), count, value);
}

void uniform4uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value)
{
    glUniform4uiv(glGetUniformLocation(program->shader_program, name), count, value);
}

//uniform matrices:

void uniformMatrix2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix2fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix3fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix4fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix2x3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix2x3fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix3x2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix3x2fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix2x4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix2x4fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix4x2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix4x2fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix3x4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix3x4fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix4x3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix4x3fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix2dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix3dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix4dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix2x3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix2x3dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix3x2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix3x2dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix2x4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix2x4dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix4x2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix4x2dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix3x4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix3x4dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

void uniformMatrix4x3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix4x3dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}


