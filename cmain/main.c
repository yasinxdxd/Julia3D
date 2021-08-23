#include <glad/glad.h>
#include <core.h>
#include <shader.h>
#include <classes/classes.h>
#include <components/components.h>
#include <stdlib.h>
#include <vertex_array_buffer_object.h>

int main()
{
    struct _J3DWindow window;
    j3d_window_create(&window, 600, 800, "Beberuhi");
    j3d_window_initialize(&window);


    struct _J3DShaderProgram shader;
    j3d_shader_load_sources(&shader, "../shaders/default_2Dshape_renderer.vert", "../shaders/default_2Dshape_renderer.frag");
    j3d_shader_compile_and_link(&shader);
    j3d_shader_free_sources(&shader);



    float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    struct _VertexIndexArrayBufferObject viabo;
    j3d_generate_viabo(&viabo);
    j3d_bind_vibao(&viabo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    j3d_unbind_vibao(&viabo);
   


    while(!j3d_window_is_close(&window))
    {
        j3d_window_poll_event();


        /*CODE CODE*/


        j3d_window_clear(&window);

        j3d_shader_use(&shader);
        j3d_bind_vibao(&viabo);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        j3d_window_display(&window);
    }

    j3d_unbind_vibao(&viabo);
    j3d_destroy_viabo(&viabo);
    j3d_shader_destroy(&shader);
    j3d_window_destroy(&window);


    return 0;
}