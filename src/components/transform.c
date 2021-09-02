#include <components/components.h>
#include <cglm/cglm.h>
#include <cglm/vec3.h>
#include <cglm/mat4.h>

JULIA3D_COMPONENTS void j3d_transform_init(Transform transform)
{
    glm_mat4_identity(transform->model_matrix);

    j3d_transform_set_position(transform, (vec3){0, 0, 0});
    j3d_transform_set_rotation(transform, 0.0, (vec3){0, 0, 0});
    j3d_transform_set_scale(transform, (vec3){1, 1, 1});

    transform->m_right_axis[0] = 1.0f;
    transform->m_right_axis[1] = 0.0f;
    transform->m_right_axis[2] = 0.0f;
    transform->m_front_axis[0] = 0.0f;
    transform->m_front_axis[1] = 0.0f;
    transform->m_front_axis[2] = -1.0f;
    transform->m_up_axis[0] = 0.0f;
    transform->m_up_axis[1] = 1.0f;
    transform->m_up_axis[2] = 0.0f;

}

JULIA3D_COMPONENTS void j3d_transform_set_position(Transform transform, vec3 pos)
{
    transform->m_position[0] = pos[0];
    transform->m_position[1] = pos[1];
    transform->m_position[2] = pos[2];
    glm_translate(transform->model_matrix, transform->m_position);
}

JULIA3D_COMPONENTS void j3d_transform_set_rotation(Transform transform, float angle, vec3 rot)
{
    transform->m_rotation[0] = rot[0];
    transform->m_rotation[1] = rot[1];
    transform->m_rotation[2] = rot[2];
    glm_rotate(transform->model_matrix, angle, transform->m_rotation);
}

JULIA3D_COMPONENTS void j3d_transform_set_scale(Transform transform, vec3 scl)
{
    glm_vec3_eqv(transform->m_scale, scl);
    glm_scale(transform->model_matrix, transform->m_scale);
}

JULIA3D_COMPONENTS void j3d_transform_set_rotation_x(Transform transform, float angle)
{
    j3d_transform_set_rotation(transform, angle, (vec3){1.0, 0.0, 0.0});
    glm_rotate(transform->model_matrix, angle, transform->m_rotation);
}

JULIA3D_COMPONENTS void j3d_transform_set_rotation_y(Transform transform, float angle)
{
    j3d_transform_set_rotation(transform, angle, (vec3){0.0, 1.0, 0.0});
    glm_rotate(transform->model_matrix, angle, transform->m_rotation);
}

JULIA3D_COMPONENTS void j3d_transform_set_rotation_z(Transform transform, float angle)
{
    j3d_transform_set_rotation(transform, angle, (vec3){0.0, 0.0, 1.0});
    glm_rotate(transform->model_matrix, angle, transform->m_rotation);
}
