#include <vertex_array_buffer_object.h>
#include <glad/glad.h>

void j3d_viabo_generate(VertexIndexArrayBufferObject viabo)
{
    //generate VAO:
    glGenVertexArrays(1, &viabo->VAO);
    //generate VBO:
    glGenBuffers(1, &viabo->VBO);
    //generate EBO:
    glGenBuffers(1, &viabo->EBO);
}

void j3d_viabo_destroy(VertexIndexArrayBufferObject viabo)
{
    j3d_vibao_unbind(viabo);
    //delete VAO:
    glDeleteVertexArrays(1, &viabo->VAO);
    //delete VBO:
    glDeleteBuffers(1, &viabo->VBO);
    //delete EBO:
    glDeleteBuffers(1, &viabo->EBO);
}

void j3d_vibao_bind(VertexIndexArrayBufferObject viabo)
{
    //bind VAO:
    glBindVertexArray(viabo->VAO);
    //bind VBO:
    glBindBuffer(GL_ARRAY_BUFFER, viabo->VBO);
    //bind EBO:
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, viabo->EBO);
}

void j3d_vibao_unbind(VertexIndexArrayBufferObject viabo)
{
    //unbind EBO:
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    //unbind VBO:
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //unbind VAO:
    glBindVertexArray(0);
}