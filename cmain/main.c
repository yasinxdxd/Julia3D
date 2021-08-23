#include <core.h>
#include <shader.h>
#include <classes/classes.h>
#include <components/components.h>
#include <stdlib.h>

struct _J3DShaderProgram
{
    char* vertex_shader_source;
    char*fragment_shader_source;
    ui32_t shader_program;
};

int main()
{
    struct _J3DShaderProgram shader;
    j3d_load_shader_source(&shader, "../shaders/default_sprite_shader.vert", "../shaders/default_sprite_shader.frag");


    return 0;
}