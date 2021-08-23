#ifndef _JULIA3D_VERTEX_INDEX_ARRAY_BUFFER_OBJECT_H_
#define _JULIA3D_VERTEX_INDEX_ARRAY_BUFFER_OBJECT_H_

#include <defs.h>

JULIA3D_CORE struct _VertexIndexArrayBufferObject
{
    ui32_t VAO, VBO, EBO;
};
typedef struct _VertexIndexArrayBufferObject* VertexIndexArrayBufferObject;

void j3d_generate_viabo(VertexIndexArrayBufferObject viabo);
void j3d_destroy_viabo(VertexIndexArrayBufferObject viabo);

void j3d_bind_vibao(VertexIndexArrayBufferObject viabo);
void j3d_unbind_vibao(VertexIndexArrayBufferObject viabo);

#endif//__JULIA3D_VERTEX_INDEX_ARRAY_BUFFER_OBJECT_H_