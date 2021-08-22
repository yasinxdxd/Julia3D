#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv_coord;
layout (location = 2) in vec3 normal;
layout (location = 3) in vec4 color;

out vec2 uv_coord_location_to_frag = uv_coord;
out vec4 color_location_to_frag = color;

void main()
{
    gl_Position = vec4(position, 1.0, 1.0);
}
