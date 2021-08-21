#ifndef _JULIA3D_COMPONENTS_H_
#define _JULIA3D_COMPONENTS_H_

#include <defs.h>

struct _Transform;
typedef struct _Transform* Transform;

typedef float vec3[3];
JULIA3D_COMPONENTS void j3d_transform_set_position(Transform transform, vec3 pos);
JULIA3D_COMPONENTS void j3d_transform_set_rotation(Transform transform, vec3 rot);
JULIA3D_COMPONENTS void j3d_transform_set_scale(Transform transform, vec3 scl);
JULIA3D_COMPONENTS void j3d_transform_translate(Transform transform, vec3 pos);
JULIA3D_COMPONENTS void j3d_transform_rotate(Transform transform, float angle, vec3 rot);
JULIA3D_COMPONENTS void j3d_transform_rotate_x(Transform transform, float angle);
JULIA3D_COMPONENTS void j3d_transform_rotate_y(Transform transform, float angle);
JULIA3D_COMPONENTS void j3d_transform_rotate_z(Transform transform, float angle);
JULIA3D_COMPONENTS void j3d_transform_scale(Transform transform, vec3 scl);

struct _MeshFilter;
typedef struct _MeshFilter* MeshFilter;

struct _MeshRenderer;
typedef struct _MeshRenderer* MeshRenderer;

struct _SpriteRenderer;
typedef struct _SpriteRenderer* SpriteRenderer;

#endif//_JULIA3D_COMPONENTS_H_