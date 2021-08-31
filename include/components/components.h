#ifndef _JULIA3D_COMPONENTS_H_
#define _JULIA3D_COMPONENTS_H_

#include <defs.h>
#include <classes/classes.h>
#include <vertex_array_buffer_object.h>
#include <cglm/vec3.h>
#include <cglm/vec4.h>
#include <cglm/mat4.h>

struct _Transform
{
    vec3 m_position;
    vec3 m_rotation;
    vec3 m_scale;
    mat4 model_matrix;

};
typedef struct _Transform* Transform;

JULIA3D_COMPONENTS void j3d_transform_init(Transform transform);
JULIA3D_COMPONENTS void j3d_transform_set_position(Transform transform, vec3 pos);
JULIA3D_COMPONENTS void j3d_transform_set_rotation(Transform transform, float angle, vec3 rot);
JULIA3D_COMPONENTS void j3d_transform_set_scale(Transform transform, vec3 scl);
JULIA3D_COMPONENTS void j3d_transform_set_rotation_x(Transform transform, float angle);
JULIA3D_COMPONENTS void j3d_transform_set_rotation_y(Transform transform, float angle);
JULIA3D_COMPONENTS void j3d_transform_set_rotation_z(Transform transform, float angle);


struct _MeshFilter
{
    Mesh m_mesh;
};
typedef struct _MeshFilter* MeshFilter;

JULIA3D_COMPONENTS j3d_mesh_filter_load_mesh(MeshFilter mesh_filter, const char* file_path);

struct _MeshRenderer
{
    struct _Vertex* m_vertices;//should I remove?
    Material m_material;
    struct _J3DShaderProgram m_shader_program;
    struct _VertexIndexArrayBufferObject m_viabo;

};
typedef struct _MeshRenderer* MeshRenderer;

struct _SpriteRenderer
{
    Texture m_texture;
    struct _Vertex* m_vertices;//should I remove?
    vec4 m_color;
    Material m_material;
    struct _J3DShaderProgram m_shader_program;
    struct _VertexIndexArrayBufferObject m_viabo;
    
};
typedef struct _SpriteRenderer* SpriteRenderer;

JULIA3D_COMPONENTS void j3d_sprite_renderer_init(SpriteRenderer sprite_renderer);
JULIA3D_COMPONENTS void j3d_sprite_renderer_draw(SpriteRenderer sprite_renderer);
JULIA3D_COMPONENTS void j3d_sprite_renderer_destroy(SpriteRenderer sprite_renderer);
JULIA3D_COMPONENTS void j3d_sprite_renderer_set_texture(SpriteRenderer sprite_renderer, Texture texture);

struct _Camera
{
    mat4 projection_matrix; //ortho or perspective
    mat4 view_matrix;
    float field_of_view; //fov (perspective)
    float size; //size (ortho)
    struct _Rect view_port_rect;
    float near_z, far_z;
    
};
typedef struct _Camera* Camera;

JULIA3D_COMPONENTS void j3d_camera_init_as_perspective(Camera camera, float fov, 
                                                        float near_z, float far_z,
                                                        struct _Rect viev_port);
JULIA3D_COMPONENTS void j3d_camera_init_as_orthographic(Camera camera, float size,
                                                        float near_z, float far_z,
                                                        struct _Rect viev_port);

#endif//_JULIA3D_COMPONENTS_H_