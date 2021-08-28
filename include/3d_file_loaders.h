#include <stdio.h>
#include <stdlib.h>

//STL file loader Begin

typedef struct _J3DSTLHeader
{
    unsigned char header[80];       //80 bytes
    unsigned int triangles_number;  //4 bytes
    
} J3DSTLHeader; //84 bytes

typedef struct _J3DSTLTriangle
{
    float normal_vector[3];               //12 bytes  x, y, z
    float vertex1[3];                     //12 bytes  x, y, z
    float vertex2[3];                     //12 bytes  x, y, z
    float vertex3[3];                     //12 bytes  x, y, z
	unsigned short attribute_byte_count:2;//2 bytes

} J3DSTLTriangle; //50 bytes

static J3DSTLTriangle* j3d_3D_file_load_STL(const char* path, J3DSTLHeader* header)
{
    FILE* file = fopen(path, "rb");
    if (!file) {
        perror("file cannot opened!");
        return NULL;
    }
    fread(header, sizeof(J3DSTLHeader), 1, file);
    
    J3DSTLTriangle* triangles = (J3DSTLTriangle*)malloc(header->triangles_number * sizeof(J3DSTLTriangle));
    J3DSTLTriangle one_triangle;
    
    unsigned int i;
    for(i = 0; i < header->triangles_number; i++)
    {
        fread(&one_triangle, sizeof(J3DSTLTriangle), 1, file);
        
        triangles[i] = one_triangle;
    }

    fclose(file);

    return triangles;
}

static void j3d_3F_file_free_STL(J3DSTLTriangle* triangles)
{
    free(triangles);
    triangles = NULL;
}

//STL file loader End
