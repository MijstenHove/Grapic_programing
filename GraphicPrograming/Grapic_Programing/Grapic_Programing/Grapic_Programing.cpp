// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <glad/glad.h>
#include <string>
#include "GLFW/glfw3.h"

int main()
{
    std::cout << "Hello World!\n";
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int width = 800;
    int height = 600;

    GLFWwindow* window = glfwCreateWindow(width, height, "Hello OpenGL!", NULL, NULL); //maak window

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, width, height); //Geef window

    double t = glfwGetTime() * 2;
    float v = float(sin(t * 1.0f));
    //Triangle
    float vertices[] = {
    //pos                    // col
     -0.5f, -0.5f, 0.5f,     1.0f, 0.0f, 0.0f, 1.0f,    0.0f, 0.0f,         
     0.5f, -0.5f, 0.5f,      0.0f, 1.0f, 0.0f, 1.0f,    1.0f, 0.0f,             
    -0.5f,  0.5f, 0.5f,      0.0f, 0.0f, 1.0f, 1.0f,    0.0f, 1.0f,           
     0.5f,  0.5f, 0.5f,      1.0f, 0.0f, 1.0f, 1.0f,    1.0f, 1.0f,          


 
    };

    int indices[]{
        0, 1, 2,
        1, 3, 2,

    };


    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    //end Triangle


    //    SETUP SHADER PROGRAM

    const char* vertexSource = "#version 330 core\n"
        "layout(location =0) in vec3 vPos;\n"
        "layout(location=1) in vec4 vColor;\n"
        "layout(location =3) in vec3 UVPos;\n"
        "out vec4 color;\n"
        "void main() {\n"
        "\tgl_Position = vec4(vPos, 1.0f);\n"

        "\tcolor = vColor; \n"
        "}\n"
        "\0";

    const char* fragmentSource = 
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "in vec4 color;\n"
        "void main() {\n"
        "\tFragColor = vec4(color.rgb,1.0f);\n"
        "}\n"
        "\0";

    unsigned int vertID, fragID;
    vertID = glCreateShader(GL_VERTEX_SHADER);
    fragID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertID, 1, &vertexSource, nullptr);
    glShaderSource(fragID, 1, &fragmentSource, nullptr);

    glCompileShader(vertID);
    glCompileShader(fragID);

    unsigned int myProgram = glCreateProgram();
    glAttachShader(myProgram, vertID);
    glAttachShader(myProgram, fragID);
    glLinkProgram(myProgram);

    glDeleteShader(vertID);
    glDeleteShader(fragID);




    //END SETUP SHADER PROGRAM

    while (!glfwWindowShouldClose(window))
    {
        double t = glfwGetTime() * 2;
        float a = (float)sin(t * 1.0f) + 0.2f;
        float r = (float)sin(t * 2.0f);
        float g = (float)cos(t * 0.5f);
        float b = (float)tan(t * 1.3f);

        glUseProgram(myProgram);

        glClearColor(r, g, b, a);
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

        glfwPollEvents(); //Exit       
    }


    glfwTerminate(); //afsluiten
    return 0;
}