#include <core.h>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

JULIA3D_CORE struct _J3DWindow
{
    GLFWwindow* m_window;
    size_t m_width;
    size_t m_height;
    char* m_title;
};

JULIA3D_CORE void j3d_window_create(J3DWindow window, size_t width, size_t height, const char* title)
{
    window->m_width = width;
    window->m_height = height;
    window->m_title = title;
    printf("[ok] create\n");
}

JULIA3D_CORE bool j3d_window_initialize(J3DWindow window)
{   
    //glfw init:
    if (!glfwInit())
    {
        perror("glfw couldn't initialize!");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    //window init:
    window->m_window = glfwCreateWindow(window->m_width, window->m_height, window->m_title, NULL, NULL);
    
	if (!window->m_window)
    {
        perror("window couldn't initialize.");
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window->m_window);

    //glad init:
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        perror("glad couldn't initialize!");
        return false;
    }


    //viewport
    glViewport(0, 0, window->m_width, window->m_height);
    glEnable(GL_DEPTH_TEST);


    printf("[ok] initialize\n");
    return true;
}

JULIA3D_CORE bool j3d_window_is_close(J3DWindow window)
{
    return (bool)glfwWindowShouldClose(window->m_window);
}

JULIA3D_CORE void j3d_window_poll_event(void)
{
    glfwPollEvents();
}

JULIA3D_CORE void j3d_window_clear(J3DWindow window)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
};

JULIA3D_CORE void j3d_window_display(J3DWindow window)
{
    glfwSwapBuffers(window->m_window);
}

JULIA3D_CORE void j3d_window_destroy(J3DWindow window)
{
    glfwDestroyWindow(window->m_window);
	glfwTerminate();

    printf("[ok] destroy\n");
}