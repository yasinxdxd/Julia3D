#ifndef _JULIA3D_COMPONENTS_H_
#define _JULIA3D_COMPONENTS_H_

#include <defs.h>
#include <classes/classes.h>
#include <cglm/vec3.h>
#include <cglm/vec4.h>

struct _Transform
{
    vec3 m_position;
    vec3 m_rotation;
    vec3 m_scale;

};
typedef struct _Transform* Transform;

JULIA3D_COMPONENTS void j3d_transform_set_position(Transform transform, vec3 pos);
JULIA3D_COMPONENTS void j3d_transform_set_rotation(Transform transform, vec3 rot);
JULIA3D_COMPONENTS void j3d_transform_set_scale(Transform transform, vec3 scl);
JULIA3D_COMPONENTS void j3d_transform_translate(Transform transform, vec3 pos);
JULIA3D_COMPONENTS void j3d_transform_rotate(Transform transform, float angle, vec3 rot);
JULIA3D_COMPONENTS void j3d_transform_rotate_x(Transform transform, float angle);
JULIA3D_COMPONENTS void j3d_transform_rotate_y(Transform transform, float angle);
JULIA3D_COMPONENTS void j3d_transform_rotate_z(Transform transform, float angle);
JULIA3D_COMPONENTS void j3d_transform_scale(Transform transform, vec3 scl);

struct _MeshFilter
{

};
typedef struct _MeshFilter* MeshFilter;

struct _MeshRenderer
{

};
typedef struct _MeshRenderer* MeshRenderer;

struct _SpriteRenderer
{
    Sprite m_sprite;
    vec4 m_color;
    Material m_material;
    
};
typedef struct _SpriteRenderer* SpriteRenderer;

#endif//_JULIA3D_COMPONENTS_H_