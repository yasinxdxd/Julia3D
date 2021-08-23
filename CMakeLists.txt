#project properties
cmake_minimum_required(VERSION 3.0)
project(Julia3D VERSION 0.1)
enable_language(C)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -pthread")

#external include directories
include_directories(
"extern/glfw/include"
"extern/glad/include"
"extern/cglm/include"
"extern/stb_image")

#external sources
file(GLOB EXTERN_SOURCES
"extern/glad/src/glad.c")

#external library names
set(LIBRARIES
"dl"
"m"#math library
"libglfw3.a"
"libcglm.a")

#external library directories
set(LIBRARY_DIRECTORIES
"extern/glfw/lib"
"extern/cglm/lib")

link_directories(${LIBRARY_DIRECTORIES})

#local include directories
include_directories("include")

#local sources
file(GLOB LOCAL_SOURCES
"src/*.c"
"src/components/*.c"
"src/classes/*.c")

add_library(Julia3D SHARED ${LOCAL_SOURCES} ${EXTERN_SOURCES})
target_link_libraries(Julia3D ${LIBRARIES})

add_executable(main "cmain/main.c" ${LOCAL_SOURCES} ${EXTERN_SOURCES})
target_link_libraries(main ${LIBRARIES})