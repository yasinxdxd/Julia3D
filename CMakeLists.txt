#project properties
cmake_minimum_required(VERSION 3.0)
project(Julia3D VERSION 0.1)

#external include directories
include_directories(
"extern/glfw/include"
"extern/glad/include"
"extern/stb_image")

#external sources
file(GLOB EXTERN_SOURCES
"extern/glad/src/glad.c")

#external library names
set(LIBRARIES
"libglfw3.a")

#external library directories
set(LIBRARY_DIRECTORIES
"extern/glfw/lib")

link_directories(${LIBRARY_DIRECTORIES})

#local include directories
include_directories("include")

#local sources
file(GLOB LOCAL_SOURCES
"src/core.c"
"src/shader.c")

add_library(Julia3D SHARED ${LOCAL_SOURCES} ${EXTERN_SOURCES})
target_link_libraries(Julia3D ${LIBRARIES})