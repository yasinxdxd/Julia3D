include("private/core.jl")
include("private/private.jl")

mutable struct Window

    m_width::Int64
    m_height::Int64
    m_title::String
    m_window::_private.J3DWindow

    Window(width::Int64, height::Int64, title::String) = new(width, height, title, _private.J3DWindow())

end

function Init(window::Window)
    ccall(j3dloader.window_create, Cvoid, (Ref{_private.J3DWindow}, Csize_t, Csize_t, Cstring), window.m_window, window.m_width, window.m_height, window.m_title)
    ccall(j3dloader.window_initialize, Cchar, (Ref{_private.J3DWindow}, ), window.m_window)
end

function IsClose(window::Window)::Bool
    ccall(j3dloader.window_is_close, Cchar, (Ref{_private.J3DWindow}, ), window.m_window)
end

function SetTitle(window::Window, title::String)
    window.m_title = title
    ccall(j3dloader.window_set_title, Cvoid, (Ref{_private.J3DWindow}, Cstring), window.m_window, window.m_title)
end

function PollEvent()
    ccall(j3dloader.window_poll_event, Cvoid, ())
end

function Clear(window::Window)
    ccall(j3dloader.window_clear, Cvoid, (Ref{_private.J3DWindow}, ), window.m_window)
end

function Display(window::Window)
    ccall(j3dloader.window_display, Cvoid, (Ref{_private.J3DWindow}, ), window.m_window)
end

function Destroy(window::Window)
    ccall(j3dloader.window_destroy, Cvoid, (Ref{_private.J3DWindow}, ), window.m_window)
end

