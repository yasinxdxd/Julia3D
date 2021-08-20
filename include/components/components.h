#ifndef _JULIA3D_COMPONENTS_H_
#define _JULIA3D_COMPONENTS_H_

#include <defs.h>

struct _MeshFilter;
typedef struct _MeshFilter* MeshFilter;

struct _MeshRenderer;
typedef struct _MeshRenderer* MeshRenderer;

struct _Texture;
typedef struct _Texture* Texture;

JULIA3D_COMPONENTS bool j3d_texture_load(Texture window, const char* file_path);
JULIA3D_COMPONENTS bool j3d_texture_create(Texture window);
JULIA3D_COMPONENTS bool j3d_texture_destroy(Texture window);

struct _SpriteRenderer;
typedef struct _SpriteRenderer* SpriteRenderer;

#endif//_JULIA3D_COMPONENTS_H_