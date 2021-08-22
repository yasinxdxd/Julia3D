#version 330 core
out vec4 frag_color;

in vec2 uv_coord_location_to_frag;
in vec4 color_location_to_frag;

uniform sampler2D u_texture;

void main()
{
    frag_color = texture(u_texture, uv_coord_location_to_frag) * color_location_to_frag;
}
