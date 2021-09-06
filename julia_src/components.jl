include("classes.jl")
include("private/private.jl")

# COMPONENTS
struct Transform
    m_position::AbstractArray{Float32}
    m_rotation::AbstractArray{Float32}
    m_scale::AbstractArray{Float32}
    model_matrix::AbstractArray{AbstractArray{Float32}}
    m_right_axis::AbstractArray{Float32}
	m_front_axis::AbstractArray{Float32}
	m_up_axis::AbstractArray{Float32}

    Transform() = new([0, 0, 0], [0, 0, 0], [0, 0, 0], 
    [[1, 0, 0, 0], 
     [0, 1, 0, 0],
     [0, 0, 1, 0],
     [0, 0, 0, 1]], [1, 0, 0], [0, 0, -1], [0, 1, 0])
end

# FIX THE type of ptr members
struct SpriteRenderer
    m_texture::Texture #ptr
    m_vertices::Vertex #ptr
    m_color::AbstractArray{Float32}
    m_material::Material #ptr
    m_shader_program::_private.J3DShaderProgram
    m_viabo::_private.VertexIndexArrayBufferObject

    # FIX THE type of ptr members
    SpriteRenderer() = new(Texture(), Vertex(), [0, 0, 0, 1],
    Material(), _private.J3DShaderProgram(), _private.VertexIndexArrayBufferObject())
end

struct Camera
    

end
