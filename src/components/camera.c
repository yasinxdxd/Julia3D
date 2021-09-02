#include <components/components.h>

JULIA3D_COMPONENTS void j3d_camera_init_as_perspective(Camera camera, float fov, 
                                                        float near_z, float far_z, 
                                                        struct _Rect view_port)
{
    camera->view_port_rect = view_port;
    camera->near_z = near_z;
    camera->far_z = far_z;
    camera->field_of_view = fov;
    glm_perspective(camera->field_of_view, (camera->view_port_rect.size[0] / camera->view_port_rect.size[1]), 
                    camera->near_z, camera->far_z, camera->projection_matrix);
    glm_mat4_identity(camera->view_matrix);
    //glm_lookat((vec3){0.0, 0.0, 10.0}, (vec3){0.0, 0.0, -1.f}, (vec3){0.0, 1.0, 0.0}, camera->view_matrix);
}

JULIA3D_COMPONENTS void j3d_camera_init_as_orthographic(Camera camera, float size, 
                                                        float near_z, float far_z, 
                                                        struct _Rect view_port)
{
    camera->view_port_rect = view_port;
    camera->near_z = near_z;
    camera->far_z = far_z;
    camera->size = size;
    glm_ortho(0.0, 10.0, 10.0, 0.0, camera->near_z, camera->far_z, camera->projection_matrix);
    glm_mat4_identity(camera->view_matrix);
}
