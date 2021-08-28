#include <keyboard.h>
#include <core.h>



JULIA3D_CORE bool j3d_keyboard_is_key_pressed(J3DWindow window, int32_t key)
{
    return glfwGetKey(window->m_window, key) ? true : false;
}

JULIA3D_CORE bool j3d_keyboard_is_key_upped(J3DWindow window, int32_t key)
{

}

JULIA3D_CORE bool j3d_keyboard_is_key_downed(J3DWindow window, int32_t key)
{

}