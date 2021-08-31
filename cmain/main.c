#include <glad/glad.h>
#include <core.h>
#include <shader.h>
#include <classes/classes.h>
#include <components/components.h>
#include <stdlib.h>
#include <vertex_array_buffer_object.h>
#include <keyboard.h>


int main()
{
    struct _J3DWindow window;
    j3d_window_create(&window, 1200, 200, "Beberuhi");
    j3d_window_initialize(&window);

    struct _SpriteRenderer sprite_renderer;
    j3d_sprite_renderer_init(&sprite_renderer);
    
    struct _Texture texture;
    j3d_texture_create(&texture, J3D_TEXTURE_2D, GL_REPEAT, GL_LINEAR);
    j3d_texture_load(&texture, "../../../Downloads/Fruit.png");
    /*
    */
    
    j3d_sprite_renderer_set_texture(&sprite_renderer, &texture);


    while(!j3d_window_is_close(&window))
    {
        j3d_window_poll_event();
        


        //CODE CODE

        if(j3d_keyboard_is_key_pressed(&window, KEY_LEFT))
            printf("LEFT key is pressed!\n");
        if(j3d_keyboard_is_key_pressed(&window, KEY_RIGHT))
            printf("RIGHT key is pressed!\n");
        if(j3d_keyboard_is_key_pressed(&window, KEY_UP))
            printf("UP key is pressed!\n");
        if(j3d_keyboard_is_key_pressed(&window, KEY_DOWN))
            printf("DOWN key is pressed!\n");

        //CODE CODE


        j3d_window_clear(&window);

        j3d_sprite_renderer_draw(&sprite_renderer);

        j3d_window_display(&window);
        
    }
    printf("dasd");
    j3d_sprite_renderer_destroy(&sprite_renderer);
    j3d_window_destroy(&window);


    return 0;
}