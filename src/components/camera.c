#include <components/components.h>

JULIA3D_COMPONENTS void j3d_camera_init_as_perspective(Camera camera, float fov, 
                                                        float near_z, float far_z, 
                                                        struct _Rect viev_port)
{
    camera->view_port_rect = viev_port;
    camera->near_z = near_z;
    camera->far_z = far_z;
    camera->field_of_view = fov;
    glm_perspective(camera->field_of_view, 800/600, camera->near_z, camera->far_z, camera->projection_matrix);
}

JULIA3D_COMPONENTS void j3d_camera_init_as_orthographic(Camera camera, float size, 
                                                        float near_z, float far_z, 
                                                        struct _Rect viev_port)
{
    camera->view_port_rect = viev_port;
    camera->near_z = near_z;
    camera->far_z = far_z;
    camera->size = size;
    glm_ortho(0.0, 10.0, 10.0, 0.0, camera->near_z, camera->far_z, camera->projection_matrix);
}