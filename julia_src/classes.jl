struct Vertex
    m_position::AbstractArray{Float32}
    m_uv_coord::AbstractArray{Float32}
    m_normal::AbstractArray{Float32}
    m_color::AbstractArray{Float32}

    Vertex() = new([0, 0, 0], [0, 0], [0, 0, 0], [0, 0, 0, 1])
end

struct Texture
    m_texture::UInt32
    m_width::Int32
    m_height::Int32
    m_nr_channels::Int32
	m_data::Ptr{UInt8}
    m_shape::Int32

    Texture() = new(0, 0, 0, 0, C_NULL, 0)
end

struct Material

end
