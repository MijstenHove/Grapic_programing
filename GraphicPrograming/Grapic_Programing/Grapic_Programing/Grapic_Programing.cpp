// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <glad/glad.h>
#include <string>
#include "GLFW/glfw3.h"

#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int loadTexture(std:: string url)
{
    //gen & bind id
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // instellen texter params
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    // shit inladen
    int width, height, channels;
    unsigned char* data;
    data = stbi_load(url.c_str(), &width, &height, &channels, 0);
    if (data == nullptr)
    {
        std::cout << "error" << " imgae" << std::endl;
    }
    else
    {
        glTexSubImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D,0);

    return textureID;
}


void loadFromFile(const char* url, char** target) {
    std::ifstream stream(url, std::ios::binary);

    stream.seekg(0, stream.end);
    int total = stream.tellg();
    *target = new char[total + 1];

    stream.seekg(0, stream.beg);
    stream.read(*target, total);

    (*target)[total] = '\0';

    stream.close();
}

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
        // positions            //colors            // tex coords   // normals
        0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 0.0f,   1.f, 0.f,       0.f, -1.f, 0.f,
        0.5f, -0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,       0.f, -1.f, 0.f,
        -0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 1.0f,   0.f, 1.f,       0.f, -1.f, 0.f,
        -0.5f, -0.5f, -.5f,     1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, -1.f, 0.f,

        0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   2.f, 0.f,       1.f, 0.f, 0.f,
        0.5f, 0.5f, 0.5f,       1.0f, 1.0f, 1.0f,   2.f, 1.f,       1.f, 0.f, 0.f,

        0.5f, 0.5f, 0.5f,       1.0f, 1.0f, 1.0f,   1.f, 2.f,       0.f, 0.f, 1.f,
        -0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   0.f, 2.f,       0.f, 0.f, 1.f,

        -0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   -1.f, 1.f,      -1.f, 0.f, 0.f,
        -0.5f, 0.5f, -.5f,      1.0f, 1.0f, 1.0f,   -1.f, 0.f,      -1.f, 0.f, 0.f,

        -0.5f, 0.5f, -.5f,      1.0f, 1.0f, 1.0f,   0.f, -1.f,      0.f, 0.f, -1.f,
        0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   1.f, -1.f,      0.f, 0.f, -1.f,

        -0.5f, 0.5f, -.5f,      1.0f, 1.0f, 1.0f,   3.f, 0.f,       0.f, 1.f, 0.f,
        -0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   3.f, 1.f,       0.f, 1.f, 0.f,

        0.5f, -0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,       0.f, 0.f, 1.f,
        -0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 1.0f,   0.f, 1.f,       0.f, 0.f, 1.f,

        -0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 1.0f,   0.f, 1.f,       -1.f, 0.f, 0.f,
        -0.5f, -0.5f, -.5f,     1.0f, 1.0f, 1.0f,   0.f, 0.f,       -1.f, 0.f, 0.f,

        -0.5f, -0.5f, -.5f,     1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, 0.f, -1.f,
        0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, 0.f, -1.f,

        0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.f, 0.f,       1.f, 0.f, 0.f,
        0.5f, -0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,       1.f, 0.f, 0.f,

        0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   2.f, 0.f,       0.f, 1.f, 0.f,
        0.5f, 0.5f, 0.5f,       1.0f, 1.0f, 1.0f,   2.f, 1.f,       0.f, 1.f, 0.f
    };

    int indices[]{
    0, 1, 2,   // first triangle
    0, 2, 3,    // second triangle
    // BACK
    14, 6, 7,   // first triangle
    14, 7, 15,    // second triangle
    // RIGHT
    20, 4, 5,   // first triangle
    20, 5, 21,    // second triangle
    // LEFT
    16, 8, 9,   // first triangle
    16, 9, 17,    // second triangle
    // FRONT
    18, 10, 11,   // first triangle
    18, 11, 19,    // second triangle
    // UP
    22, 12, 13,   // first triangle
    22, 13, 23,    // second triangle
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

    int stride = sizeof(float) * 11;

    //pos
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride , 0);
    glEnableVertexAttribArray(0);
   
    //col
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, stride , (void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);
   
    // UV
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)( sizeof(float) * 6));
    glEnableVertexAttribArray(2);

    // normal
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE,stride, (void*)(sizeof(float) * 8));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    //end Triangle


    //    SETUP SHADER PROGRAM
     char* vertexSource;
    loadFromFile("VerShader.shader", &vertexSource);

    char* fragmentSource;
    loadFromFile("fragShader.shader", &fragmentSource);

    //load

    unsigned int diffureTexID = loadTexture("char.JPG");
    
    unsigned int vertID, fragID;
    vertID = glCreateShader(GL_VERTEX_SHADER);
    fragID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertID, 1, &vertexSource, nullptr);
    glShaderSource(fragID, 1, &fragmentSource, nullptr);

    glCompileShader(vertID);
    glCompileShader(fragID);
//error
    int success;
    char infoLog[512];

    glCompileShader(vertID);
    glGetShaderiv(vertID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    glCompileShader(fragID);
    glGetShaderiv(fragID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

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

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, diffureTexID);

        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

        glfwPollEvents(); //Exit       
    }


    glfwTerminate(); //afsluiten
    return 0;
}

