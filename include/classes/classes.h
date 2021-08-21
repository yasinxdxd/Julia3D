#ifndef _JULIA3D_CLASSES_H_
#define _JULIA3D_CLASSES_H_

#include <defs.h>

struct _Vertex;
typedef struct _Vertex* Vertex;

struct _Texture;
typedef struct _Texture* Texture;

JULIA3D_CLASS_COMPS bool j3d_texture_load(Texture texture, const char* file_path);
JULIA3D_CLASS_COMPS bool j3d_texture_create(Texture texture);
JULIA3D_CLASS_COMPS bool j3d_texture_destroy(Texture texture);

struct _Sprite;
typedef struct _Sprite* Sprite;

#endif//_JULIA3D_CLASSES_H_
