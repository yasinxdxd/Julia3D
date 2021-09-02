#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv_coord;
layout (location = 2) in vec3 normal;
layout (location = 3) in vec4 color;

out vec2 uv_coord_location_to_frag;
out vec4 color_location_to_frag;

//mvp matrices
uniform mat4 u_model_matrix;
uniform mat4 u_view_matrix;
uniform mat4 u_projection_matrix;

void main()
{
    uv_coord_location_to_frag = uv_coord;
    color_location_to_frag = color;

    mat4 mvp = u_projection_matrix * u_view_matrix * u_model_matrix;

    gl_Position = mvp * vec4(position, 1.0);
}
