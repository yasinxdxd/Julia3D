#include <vertex_array_buffer_object.h>
#include <glad/glad.h>

void j3d_generate_viabo(VertexIndexArrayBufferObject viabo)
{
    //generate VAO:
    glGenVertexArrays(1, &viabo->VAO);
    //generate VBO:
    glGenBuffers(1, &viabo->VBO);
    //generate EBO:
    glGenBuffers(1, &viabo->EBO);
}

void j3d_destroy_viabo(VertexIndexArrayBufferObject viabo)
{
    j3d_unbind_vibao(viabo);
    //delete VAO:
    glDeleteVertexArrays(1, &viabo->VAO);
    //delete VBO:
    glDeleteBuffers(1, &viabo->VBO);
    //delete EBO:
    glDeleteBuffers(1, &viabo->EBO);
}

void j3d_bind_vibao(VertexIndexArrayBufferObject viabo)
{
    //bind VAO:
    glBindVertexArray(viabo->VAO);
    //bind VBO:
    glBindBuffer(GL_ARRAY_BUFFER, viabo->VBO);
    //bind EBO:
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, viabo->EBO);
}

void j3d_unbind_vibao(VertexIndexArrayBufferObject viabo)
{
    //unbind EBO:
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    //unbind VBO:
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //unbind VAO:
    glBindVertexArray(0);
}