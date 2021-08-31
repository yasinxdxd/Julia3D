#include <classes/classes.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <stdio.h>
#include <glad/glad.h>

JULIA3D_CLASS_COMPS bool j3d_texture_load(Texture texture, const char* file_path)
{
    stbi_set_flip_vertically_on_load(true);

    texture->m_data = stbi_load(file_path, &texture->m_width, &texture->m_height, &texture->m_nr_channels, 0);
    const char* err = stbi_failure_reason();
    if(err)
			printf("stbi failure reason: %s\n", err);

    if(!texture->m_data)
    {
        perror("Failed to load texture!\n");
        stbi_image_free(texture->m_data);
        return false;
    }

    if(texture->m_shape == J3D_TEXTURE_2D)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->m_width, texture->m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->m_data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("other texture shapes are not supported yet...");
    }
    
    glBindTexture(GL_TEXTURE, 0);
    stbi_image_free(texture->m_data);
    return true;
}

JULIA3D_CLASS_COMPS bool j3d_texture_create(Texture texture, TEXTURE_SHAPE texture_shape, ui32_t wrap_mode, ui32_t filter)
{
    //glEnable(GL_BLEND);

    texture->m_shape = texture_shape;

    glGenTextures(1, &texture->m_texture);//&
    glBindTexture(texture_shape, texture->m_texture);//

    glTexParameteri(texture->m_shape, GL_TEXTURE_WRAP_S, wrap_mode);//GL_REPEAT
    glTexParameteri(texture->m_shape, GL_TEXTURE_WRAP_T, wrap_mode);//GL_REPEAT
    glTexParameteri(texture->m_shape, GL_TEXTURE_MIN_FILTER, filter);//GL_LINEAR
    glTexParameteri(texture->m_shape, GL_TEXTURE_MAG_FILTER, filter);//GL_LINEAR
}

JULIA3D_CLASS_COMPS bool j3d_texture_destroy(Texture texture)
{
    glDeleteTextures(0, &texture->m_texture);//&
}
