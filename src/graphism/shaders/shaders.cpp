#include <../../include/GLAD/glad.h>
#include <../../include/GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "../../constant.h"
#include "../graphism_functions.h"
#include "../../main.h"
#include "shaderCompilation.h"

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource ="#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n" 
"{\n"
"   FragColor = vec4(1.0f, 1.0f, 0.02f, 1.0f);\n"
"}\n\0";



GLuint createShaderVAO(GLuint VAO, GLuint VBO, GLfloat* vertexs, int size){

    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);


    glBufferData(GL_ARRAY_BUFFER, size, vertexs, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
   
    return VAO;
}

GLuint createVBO(GLuint VBO){

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    return VBO;

}

void shader(GLuint shaderProgram, GLuint VAO){

    /* Fonction finale du shader pour le créer et l'afficher */
    
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 4);
    
}