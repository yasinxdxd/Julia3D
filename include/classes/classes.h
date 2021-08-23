#ifndef _JULIA3D_CLASSES_H_
#define _JULIA3D_CLASSES_H_

#include <defs.h>
#include <shader.h>
#include <cglm/cglm.h>
#include <cglm/vec2.h>
#include <cglm/vec3.h>
#include <cglm/vec4.h>

struct _Vertex
{
    vec3 m_position;
    vec2 m_uv_coord;
    vec3 m_normal;
    vec4 m_color;
    
};
typedef struct _Vertex* Vertex;

struct _Texture
{
    ui32_t m_texture;
    i32_t m_width, m_height, m_nr_channels;
	ui8_t* m_data;
};
typedef struct _Texture* Texture;

JULIA3D_CLASS_COMPS bool j3d_texture_load(Texture texture, const char* file_path);
JULIA3D_CLASS_COMPS bool j3d_texture_create(Texture texture);
JULIA3D_CLASS_COMPS bool j3d_texture_destroy(Texture texture);

struct _Sprite
{
    struct _Vertex* m_vertices;
    Texture m_texture;
    struct _J3DShaderProgram m_shader_program;
};
typedef struct _Sprite* Sprite;

struct _Material
{

};
typedef struct _Material* Material;

#endif//_JULIA3D_CLASSES_H_
