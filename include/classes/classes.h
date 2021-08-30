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


struct _Rect
{
    vec2 position;
    vec2 size;
};

typedef enum TEXTURE_SHAPE
{
    J3D_TEXTURE_3D = 0x806F,
    J3D_TEXTURE_2D = 0x0DE1,
    J3D_TEXTURE_1D = 0x0DE0,

} TEXTURE_SHAPE;

struct _Texture
{
    ui32_t* m_texture;
    i32_t m_width, m_height, m_nr_channels;
	ui8_t* m_data;
    TEXTURE_SHAPE m_shape;
};
typedef struct _Texture* Texture;

JULIA3D_CLASS_COMPS bool j3d_texture_load(Texture texture, const char* file_path);
JULIA3D_CLASS_COMPS bool j3d_texture_create(Texture texture, TEXTURE_SHAPE texture_shape, ui32_t wrap_mode, ui32_t filter);
JULIA3D_CLASS_COMPS bool j3d_texture_destroy(Texture texture);

struct _Material
{

};
typedef struct _Material* Material;

struct _Mesh
{
    struct _Vertex* m_vertices;
    ui32_t* m_indices;
};
typedef struct _Mesh* Mesh;

#endif//_JULIA3D_CLASSES_H_
