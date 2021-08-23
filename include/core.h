#ifndef _JULIA3D_CORE_H_
#define _JULIA3D_CORE_H_

#include <defs.h>

typedef struct GLFWwindow GLFWwindow;

JULIA3D_CORE struct _J3DWindow
{
    GLFWwindow* m_window;
    size_t m_width;
    size_t m_height;
    char* m_title;
};;
typedef struct _J3DWindow* J3DWindow;

JULIA3D_CORE void j3d_window_create(J3DWindow window, size_t width, size_t height, const char* title);
JULIA3D_CORE bool j3d_window_initialize(J3DWindow window);
JULIA3D_CORE bool j3d_window_is_close(J3DWindow window);
JULIA3D_CORE void j3d_window_poll_event(void);
JULIA3D_CORE void j3d_window_set_title(J3DWindow window, const char* title);
JULIA3D_CORE void j3d_window_clear(J3DWindow window);
JULIA3D_CORE void j3d_window_display(J3DWindow window);
JULIA3D_CORE void j3d_window_destroy(J3DWindow window);

#endif//_JULIA3D_CORE_H_