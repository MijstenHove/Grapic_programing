// OpenGL_Lessen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <glad/glad.h>
#include "GLFW/glfw3.h"

int main()
{
    std::cout << "Hello World!\n";

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow * window = glfwCreateWindow(800, 600, "Hello OpenGL!", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);
    
    float vertices[] =
    {
        -0,5f, -0.5f, 0.5f,
        0.5f, -0,5f, 0,5f,
        0,0f, 0.5f, 0,5f

    };
    unsigned int VAO;
    glVertexArrays(1, &VAO);
    unsigned int VBO;
    glGenBuffer(1, &VBO);

    glBindVertexArry(VAO);

    // setup

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPoinet(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
    glBindVertexArray(0);


    glEnableVertexAttribArray(0);
    glViewport(0, 0, 800, 600);

    while (!glfwWindowShouldClose(window))
    {
        double t = glfwGetTime();
        float r = (float)sin(t*1.1f);
        float g = (float)sin(t*1.3f);
        float b = (float)sin(t*1.7f);

        // iets tekenen
        glBindVertexArry(VAO);

        glClearColor(r,g,b,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
