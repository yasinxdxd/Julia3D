module j3dloader   

    using Libdl
    libJulia3D = dlopen("../build/libJulia3D.so")
    
    # window
    window_create = dlsym(libJulia3D, "j3d_window_create")
    window_initialize = dlsym(libJulia3D, "j3d_window_initialize")
    window_destroy = dlsym(libJulia3D, "j3d_window_destroy")
    window_is_close = dlsym(libJulia3D, "j3d_window_is_close")
    window_set_title = dlsym(libJulia3D, "j3d_window_set_title")
    window_poll_event = dlsym(libJulia3D, "j3d_window_poll_event")
    window_clear = dlsym(libJulia3D, "j3d_window_clear")
    window_display = dlsym(libJulia3D, "j3d_window_display")

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
end
