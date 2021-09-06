#include <components/components.h>
#include <glad/glad.h>

JULIA3D_COMPONENTS void j3d_sprite_renderer_init(SpriteRenderer sprite_renderer)
{
    j3d_shader_load_sources(&sprite_renderer->m_shader_program, "../shaders/default_sprite_shader.vert", "../shaders/default_sprite_shader.frag");
    j3d_shader_compile_and_link(&sprite_renderer->m_shader_program);
    j3d_shader_free_sources(&sprite_renderer->m_shader_program);


    struct _Vertex vertices[] = {
        {
            {1.f,  1.f, 0.0f},
            {1.f,  1.f},
            {1.f,  1.f, 0.0f},
            {1.f, 1.f, 1.f, 1.f},
        },
        {
            {1.f, -1.f, 0.0f},
            {1.f,  -1.f},
            {1.f,  1.f, 0.0f},
            {1.f, 1.f, 1.f, 1.f},
        },
        {
            {-1.f, -1.f, 0.0f},
            {-1.f, -1.f},
            {1.f,  1.f, 0.0f},
            {1.f, 1.f, 1.f, 1.f},
        },
        {
            {-1.f,  1.f, 0.0f},
            {-1.f,  1.f},
            {1.f,  1.f, 0.0f},
            {1.f, 1.f, 1.f, 1.f},
        },
    };

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };


    j3d_viabo_generate(&sprite_renderer->m_viabo);
    j3d_vibao_bind(&sprite_renderer->m_viabo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
  
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(struct _Vertex), (void*)offsetof(struct _Vertex, m_position));//pos
    glEnableVertexAttribArray(0);
    //
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(struct _Vertex), (void*)offsetof(struct _Vertex, m_uv_coord));//uv
    glEnableVertexAttribArray(1);
    //
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(struct _Vertex), (void*)offsetof(struct _Vertex, m_normal));//norm
    glEnableVertexAttribArray(2);
    //
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(struct _Vertex), (void*)offsetof(struct _Vertex, m_color));//color
    glEnableVertexAttribArray(3);

    j3d_vibao_unbind(&sprite_renderer->m_viabo);

}

JULIA3D_COMPONENTS void j3d_sprite_renderer_draw(SpriteRenderer sprite_renderer)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, sprite_renderer->m_texture->m_texture);

    j3d_shader_use(&sprite_renderer->m_shader_program);
    j3d_vibao_bind(&sprite_renderer->m_viabo);
    //glDrawArrays(GL_TRIANGLES, 0, 16);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

JULIA3D_COMPONENTS void j3d_sprite_renderer_destroy(SpriteRenderer sprite_renderer)
{
    j3d_vibao_unbind(&sprite_renderer->m_viabo);
    j3d_viabo_destroy(&sprite_renderer->m_viabo);
    j3d_shader_destroy(&sprite_renderer->m_shader_program);
    j3d_texture_destroy(sprite_renderer->m_texture);
    printf("sprite is destroyed");

}

JULIA3D_COMPONENTS void j3d_sprite_renderer_set_texture(SpriteRenderer sprite_renderer, Texture texture)
{
    sprite_renderer->m_texture = texture;
    j3d_shader_use(&sprite_renderer->m_shader_program);
    uniform1i(&sprite_renderer->m_shader_program, "u_texture", 0);
}
    