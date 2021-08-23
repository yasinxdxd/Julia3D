#include <components/components.h>
#include <cglm/cglm.h>
#include <cglm/vec3.h>
#include <cglm/mat4.h>


JULIA3D_COMPONENTS void j3d_transform_set_position(Transform transform, vec3 pos)
{
    glm_vec3_eqv(transform->m_position, pos);
}

JULIA3D_COMPONENTS void j3d_transform_set_rotation(Transform transform, vec3 rot)
{
    glm_vec3_eqv(transform->m_rotation, rot);
}

JULIA3D_COMPONENTS void j3d_transform_set_scale(Transform transform, vec3 scl)
{
    glm_vec3_eqv(transform->m_scale, scl);
}

JULIA3D_COMPONENTS void j3d_transform_translate(Transform transform, vec3 pos)
{
    //glm_vec3_eqv(transform->m_sclae, scl);
}

JULIA3D_COMPONENTS void j3d_transform_rotate(Transform transform, float angle, vec3 rot)
{
    glm_vec3_rotate(transform->m_rotation, glm_rad(angle), rot);
}

JULIA3D_COMPONENTS void j3d_transform_rotate_x(Transform transform, float angle)
{
    glm_vec3_rotate(transform->m_rotation, glm_rad(angle), (vec3){1.0, 0.0, 0.0});
}

JULIA3D_COMPONENTS void j3d_transform_rotate_y(Transform transform, float angle)
{
    glm_vec3_rotate(transform->m_rotation, glm_rad(angle), (vec3){0.0, 1.0, 0.0});
}

JULIA3D_COMPONENTS void j3d_transform_rotate_z(Transform transform, float angle)
{
    glm_vec3_rotate(transform->m_rotation, glm_rad(angle), (vec3){0.0, 0.0, 1.0});
}

JULIA3D_COMPONENTS void j3d_transform_scale(Transform transform, vec3 scl)
{
    glm_vec3_scale(transform->m_scale, 1, scl);
}

