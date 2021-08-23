#include <shader.h>
#include <glad/glad.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


JULIA3D_CORE void j3d_shader_load_sources(J3DShaderProgram program, const char* vert_path, const char* frag_path)
{

    FILE* vert_file;
    vert_file = fopen(vert_path, "r");

    if(vert_file == NULL)
    {
        printf("Vertex Shader file couldn't open, or find!");
        fclose(vert_file);
        return;
    }
    
    char vert_line[256];

    FILE* stream_v;
    size_t len_v;
    stream_v = open_memstream(&program->vertex_shader_source, &len_v);

    while(fgets(vert_line, sizeof(vert_line), vert_file) != NULL)
    {    
        fprintf(stream_v, vert_line);
    }

    fclose(stream_v);
    fclose(vert_file);


///////////////////////////////////////////////////

    FILE* frag_file;
    frag_file = fopen(frag_path, "r");

    if(frag_file == NULL)
    {
        printf("Fragment Shader file couldn't open, or find!");
        fclose(frag_file);
        return;
    }
    
    char frag_line[256];

    FILE* stream_f;
    size_t len_f;
    stream_f = open_memstream(&program->fragment_shader_source, &len_f);

    while(fgets(frag_line, sizeof(frag_line), frag_file) != NULL)
    {    
        fprintf(stream_f, frag_line);
    }

    fclose(stream_f);
    fclose(frag_file); 
    
}

JULIA3D_CORE void j3d_shader_free_sources(J3DShaderProgram program)
{
    free(program->vertex_shader_source);
    free(program->fragment_shader_source);
}

JULIA3D_CORE void j3d_shader_compile_and_link(J3DShaderProgram program)
{
    // build and compile our shader program
    
    // vertex shader
    ui32_t vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &program->vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    
    // check for shader compile errors
    i32_t success;
    char infoLog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    }

    // fragment shader
    ui32_t fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
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

JULIA3D_CORE void j3d_shader_use(J3DShaderProgram program)
{
    glUseProgram(program->shader_program);
}

JULIA3D_CORE void j3d_shader_destroy(J3DShaderProgram program)
{
    glDeleteProgram(program->shader_program);
}

JULIA3D_CORE void uniform1d(J3DShaderProgram program, const char* name, double value)
{
    glUniform1d(glGetUniformLocation(program->shader_program, name), value);
}

JULIA3D_CORE void uniform1f(J3DShaderProgram program, const char* name, float value)
{
    glUniform1f(glGetUniformLocation(program->shader_program, name), value);
}

JULIA3D_CORE void uniform1i(J3DShaderProgram program, const char* name, int value)
{
    glUniform1i(glGetUniformLocation(program->shader_program, name), value);
}

JULIA3D_CORE void uniform1ui(J3DShaderProgram program, const char* name, unsigned int value)
{
    glUniform1ui(glGetUniformLocation(program->shader_program, name), value);
}

JULIA3D_CORE void uniform2d(J3DShaderProgram program, const char* name, double v0, double v1)
{
    glUniform2d(glGetUniformLocation(program->shader_program, name), v0, v1);
}

JULIA3D_CORE void uniform2f(J3DShaderProgram program, const char* name, float v0, float v1)
{
    glUniform2f(glGetUniformLocation(program->shader_program, name), v0, v1);
}

JULIA3D_CORE void uniform2i(J3DShaderProgram program, const char* name, int v0, int v1)
{
    glUniform2i(glGetUniformLocation(program->shader_program, name), v0, v1);
}

JULIA3D_CORE void uniform2ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1)
{
    glUniform2ui(glGetUniformLocation(program->shader_program, name), v0, v1);
}

JULIA3D_CORE void uniform3d(J3DShaderProgram program, const char* name, double v0, double v1, double v2)
{
    glUniform3d(glGetUniformLocation(program->shader_program, name), v0, v1, v2);
}

JULIA3D_CORE void uniform3f(J3DShaderProgram program, const char* name, float v0, float v1, float v2)
{
    glUniform3f(glGetUniformLocation(program->shader_program, name), v0, v1, v2);
}

JULIA3D_CORE void uniform3i(J3DShaderProgram program, const char* name, int v0, int v1, int v2)
{
    glUniform3i(glGetUniformLocation(program->shader_program, name), v0, v1, v2);
}

JULIA3D_CORE void uniform3ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1, unsigned int v2)
{
    glUniform3ui(glGetUniformLocation(program->shader_program, name), v0, v1, v2);
}

JULIA3D_CORE void uniform4d(J3DShaderProgram program, const char* name, double v0, double v1, double v2, double v3)
{
    glUniform4d(glGetUniformLocation(program->shader_program, name), v0, v1, v2, v3);
}

JULIA3D_CORE void uniform4f(J3DShaderProgram program, const char* name, float v0, float v1, float v2, float v3)
{
    glUniform4f(glGetUniformLocation(program->shader_program, name), v0, v1, v2, v3);
}

JULIA3D_CORE void uniform4i(J3DShaderProgram program, const char* name, int v0, int v1, int v2, int v3)
{
    glUniform4i(glGetUniformLocation(program->shader_program, name), v0, v1, v2, v3);
}

JULIA3D_CORE void uniform4ui(J3DShaderProgram program, const char* name, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3)
{
    glUniform4ui(glGetUniformLocation(program->shader_program, name), v0, v1, v2, v3);
}

//uniform vectors:

JULIA3D_CORE void uniform1dv(J3DShaderProgram program, const char* name, int count, const double* value)
{
    glUniform1dv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform1fv(J3DShaderProgram program, const char* name, int count, const float* value)
{
    glUniform1fv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform1iv(J3DShaderProgram program, const char* name, int count, const int* value)
{
    glUniform1iv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform1uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value)
{
    glUniform1uiv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform2dv(J3DShaderProgram program, const char* name, int count, const double* value)
{
    glUniform2dv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform2fv(J3DShaderProgram program, const char* name, int count, const float* value)
{
    glUniform2fv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform2iv(J3DShaderProgram program, const char* name, int count, const int* value)
{
    glUniform2iv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform2uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value)
{
    glUniform2uiv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform3dv(J3DShaderProgram program, const char* name, int count, const double* value)
{
    glUniform3dv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform3fv(J3DShaderProgram program, const char* name, int count, const float* value)
{
    glUniform3fv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform3iv(J3DShaderProgram program, const char* name, int count, const int* value)
{
    glUniform3iv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform3uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value)
{
    glUniform3uiv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform4dv(J3DShaderProgram program, const char* name, int count, const double* value)
{
    glUniform4dv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform4fv(J3DShaderProgram program, const char* name, int count, const float* value)
{
    glUniform4fv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform4iv(J3DShaderProgram program, const char* name, int count, const int* value)
{
    glUniform4iv(glGetUniformLocation(program->shader_program, name), count, value);
}

JULIA3D_CORE void uniform4uiv(J3DShaderProgram program, const char* name, int count, const unsigned int* value)
{
    glUniform4uiv(glGetUniformLocation(program->shader_program, name), count, value);
}

//uniform matrices:

JULIA3D_CORE void uniformMatrix2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix2fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix3fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix4fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix2x3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix2x3fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix3x2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix3x2fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix2x4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix2x4fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix4x2fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix4x2fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix3x4fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix3x4fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix4x3fv(J3DShaderProgram program, const char* name, int count, bool transpose, const float* value)
{
    glUniformMatrix4x3fv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix2dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix3dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix4dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix2x3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix2x3dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix3x2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix3x2dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix2x4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix2x4dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix4x2dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix4x2dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix3x4dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix3x4dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}

JULIA3D_CORE void uniformMatrix4x3dv(J3DShaderProgram program, const char* name, int count, bool transpose, const double* value)
{
    glUniformMatrix4x3dv(glGetUniformLocation(program->shader_program, name), count, transpose, value);
}


