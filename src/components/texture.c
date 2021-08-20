#include <components/components.h>
#include <stb_image.h>
#include <stdio.h>
#include <glad/glad.h>

struct _Texture
{
    ui32_t m_texture;
    i32_t m_width, m_height, m_nr_channels;
	ui8_t* m_data;
};

JULIA3D_COMPONENTS bool j3d_texture_load(Texture texture, const char* file_path)
{
    texture->m_data = stbi_load(file_path, &texture->m_width, &texture->m_height, &texture->m_nr_channels, 0);
    
    if(!texture->m_data)
    {
        perror("Failed to load texture!");
        stbi_image_free(texture->m_data);
        return false;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->m_width, texture->m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->m_data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(texture->m_data);
    return true;
}

JULIA3D_COMPONENTS bool j3d_texture_create(Texture texture)
{
    glGenTextures(1, &texture->m_texture);
    glBindTexture(GL_TEXTURE_2D, texture->m_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

JULIA3D_COMPONENTS bool j3d_texture_destroy(Texture texture)
{
    if(texture->m_data)
        stbi_image_free(texture->m_data);
    glDeleteTextures(sizeof(ui32_t), &texture->m_texture);
}