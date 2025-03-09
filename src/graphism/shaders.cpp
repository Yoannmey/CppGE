#include <../../include/GLAD/glad.h>
#include <../../include/GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "../constant.h"
#include "graphism_functions.h"
#include "../main.h"

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

char fragmentSwitch(int cas){

    /* Cette fonction retourne le chemin vers le fragment shader demandé */
    
        switch (cas)
        {
        case 1:
              
            break;
        
        default:
            break;
        }
    
}

int shaderCompilation(const char* vertexSource, const char* fragmentSource){

    /* Cette fonction créer le shaderProgram grâce au vertex et au fragment sélectionné */
    
        GLuint shaderProgram;
    
    
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);
    
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);
    
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
    
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    
        return shaderProgram;
        
}

int initShader(int numeroFragment){

    char fragmentPick = fragmentSwitch(numeroFragment);

    GLuint shaderProgram = shaderCompilation(vertexShaderSource, fragmentShaderSource);

    return shaderProgram;

}

void createShader(GLuint VAO, GLuint VBO, GLfloat vertexs, int size){

     glGenVertexArrays(1, &VAO);
     glGenBuffers(1, &VBO);

     glBindVertexArray(VAO);
 
     glBindBuffer(GL_ARRAY_BUFFER, VBO);

     glBufferData(GL_ARRAY_BUFFER, size, vertexs, GL_STATIC_DRAW);
 
     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
     glEnableVertexAttribArray(0);
 
     glBindBuffer(GL_ARRAY_BUFFER, 0);
     glBindVertexArray(0);
    
}

void shader(int numeroFragment){

/* Fonction finale du shader pour le créer et l'afficher */

    static GLuint shaderProgram = 0, VAO, VBO;

    if(shaderProgram == 0){
    
        GLfloat positions[] =
        {
            -0.0f, -0.5f, 0.0f,  // Bas gauche
            0.5f,   -0.5f, 0.0f  // Haut gauche
            -0.5f,  0.5f, 0.0f, // Bas droite
            -0.5f,   0.5f, 0.0f, // Haut droite
        };

        createShader(VAO, VBO, positions, sizeof(positions));

        shaderProgram = initShader(numeroFragment);

    }
    
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 4);

}