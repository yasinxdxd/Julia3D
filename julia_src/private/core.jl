module j3dloader   

    using Libdl
    libJulia3D = dlopen("../build/libJulia3D.so")
    
    # CORE
    # window
    window_create = dlsym(libJulia3D, "j3d_window_create")
    window_initialize = dlsym(libJulia3D, "j3d_window_initialize")
    window_destroy = dlsym(libJulia3D, "j3d_window_destroy")
    window_is_close = dlsym(libJulia3D, "j3d_window_is_close")
    window_set_title = dlsym(libJulia3D, "j3d_window_set_title")
    window_poll_event = dlsym(libJulia3D, "j3d_window_poll_event")
    window_clear = dlsym(libJulia3D, "j3d_window_clear")
    window_display = dlsym(libJulia3D, "j3d_window_display")
    # keyboard
    keyboard_is_key_pressed = dlsym(libJulia3D, "j3d_keyboard_is_key_pressed")
    keyboard_is_key_upped = dlsym(libJulia3D, "j3d_keyboard_is_key_upped")
    keyboard_is_key_downed = dlsym(libJulia3D, "j3d_keyboard_is_key_downed")

    # NON-COMPONENT CLASSES
    # texture
    texture_load = dlsym(libJulia3D, "j3d_texture_load")
    texture_create = dlsym(libJulia3D, "j3d_texture_create")
    texture_destroy = dlsym(libJulia3D, "j3d_texture_destroy")

    # COMPONENTS
    # transform
    transform_init = dlsym(libJulia3D, "j3d_transform_init")
    transform_set_position = dlsym(libJulia3D, "j3d_transform_set_position")
    transform_set_rotation = dlsym(libJulia3D, "j3d_transform_set_rotation")
    transform_set_scale = dlsym(libJulia3D, "j3d_transform_set_scale")
    transform_set_rotation_x = dlsym(libJulia3D, "j3d_transform_set_rotation_x")
    transform_set_rotation_y = dlsym(libJulia3D, "j3d_transform_set_rotation_y")
    transform_set_rotation_z = dlsym(libJulia3D, "j3d_transform_set_rotation_z")
    # sprite renderer
    sprite_renderer_init = dlsym(libJulia3D, "j3d_sprite_renderer_init")
    sprite_renderer_draw = dlsym(libJulia3D, "j3d_sprite_renderer_draw")
    sprite_renderer_destroy = dlsym(libJulia3D, "j3d_sprite_renderer_destroy")
    sprite_renderer_set_texture = dlsym(libJulia3D, "j3d_sprite_renderer_set_texture")
    #camera
    camera_init_as_perspective = dlsym(libJulia3D, "j3d_camera_init_as_perspective")
    camera_init_as_orthographic = dlsym(libJulia3D, "j3d_camera_init_as_orthographic")
end
