#ifndef _JULIA3D_VERTEX_INDEX_ARRAY_BUFFER_OBJECT_H_
#define _JULIA3D_VERTEX_INDEX_ARRAY_BUFFER_OBJECT_H_

#include <defs.h>

JULIA3D_CORE struct _VertexIndexArrayBufferObject
{
    ui32_t VAO, VBO, EBO;
};
typedef struct _VertexIndexArrayBufferObject* VertexIndexArrayBufferObject;

void j3d_viabo_generate(VertexIndexArrayBufferObject viabo);
void j3d_viabo_destroy(VertexIndexArrayBufferObject viabo);

void j3d_vibao_bind(VertexIndexArrayBufferObject viabo);
void j3d_vibao_unbind(VertexIndexArrayBufferObject viabo);

#endif//__JULIA3D_VERTEX_INDEX_ARRAY_BUFFER_OBJECT_H_