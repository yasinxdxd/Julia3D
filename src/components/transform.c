#include <components/components.h>
#include <cglm/cglm.h>
#include <cglm/vec3.h>
#include <cglm/mat4.h>

JULIA3D_COMPONENTS void j3d_transform_init(Transform transform)
{
    j3d_transform_set_position(transform, (vec3){0, 0, 0});
    j3d_transform_set_rotation(transform, 0, (vec3){0, 0, 0});
    j3d_transform_set_scale(transform, (vec3){0, 0, 0});

    glm_mat4_identity(transform->model_matrix);

}

JULIA3D_COMPONENTS void j3d_transform_set_position(Transform transform, vec3 pos)
{
    glm_vec3_eqv(transform->m_position, pos);
    glm_translate(transform->model_matrix, transform->m_position);
}

JULIA3D_COMPONENTS void j3d_transform_set_rotation(Transform transform, float angle, vec3 rot)
{
    glm_vec3_eqv(transform->m_rotation, rot);
    glm_rotate(transform->model_matrix, angle, transform->m_rotation);
}

JULIA3D_COMPONENTS void j3d_transform_set_scale(Transform transform, vec3 scl)
{
    glm_vec3_eqv(transform->m_scale, scl);
    glm_scale(transform->model_matrix, transform->m_scale);
}

JULIA3D_COMPONENTS void j3d_transform_set_rotation_x(Transform transform, float angle)
{
    glm_vec3_eqv(transform->m_rotation, (vec3){1.0, 0.0, 0.0});
    glm_rotate(transform->model_matrix, angle, transform->m_rotation);
}

JULIA3D_COMPONENTS void j3d_transform_set_rotation_y(Transform transform, float angle)
{
    glm_vec3_eqv(transform->m_rotation, (vec3){0.0, 1.0, 0.0});
    glm_rotate(transform->model_matrix, angle, transform->m_rotation);
}

JULIA3D_COMPONENTS void j3d_transform_set_rotation_z(Transform transform, float angle)
{
    glm_vec3_eqv(transform->m_rotation, (vec3){0.0, 0.0, 1.0});
    glm_rotate(transform->model_matrix, angle, transform->m_rotation);
}
