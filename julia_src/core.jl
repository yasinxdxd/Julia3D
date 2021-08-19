module j3dloader   

    using Libdl
    libJulia3D = dlopen("../build/libJulia3D.so")
    
    window_create = dlsym(libJulia3D, "j3d_window_create")
    window_initialize = dlsym(libJulia3D, "j3d_window_initialize")
    window_destroy = dlsym(libJulia3D, "j3d_window_destroy")
    window_is_close = dlsym(libJulia3D, "j3d_window_is_close")
    window_poll_event = dlsym(libJulia3D, "j3d_window_poll_event")
    window_clear = dlsym(libJulia3D, "j3d_window_clear")
    window_display = dlsym(libJulia3D, "j3d_window_display")


end
