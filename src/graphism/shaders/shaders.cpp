#include <../../include/GLAD/glad.h>
#include <../../include/GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "../../constant.h"
#include "../graphism_functions.h"
#include "shaderCompilation.h"
#include "shaders.h"

using namespace std;

vertexArray createShader(GLuint VAO, GLuint VBO, GLfloat* vertexs, int size, GLuint shaderProgram, const char* vertexSource, const char* fragmentSource ){

    shaderProgram = shaderCompilation(shaderProgram,vertexSource,fragmentSource);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, size, vertexs, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    vertexArray VABO = { VAO, VBO, shaderProgram};
    
    return VABO;
}

void shaderLoopTriangle(GLuint shaderProgram, GLuint VAO){

    /* Fonction finale du shader pour le créer et l'afficher */
    
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    
}

void shaderLoopSquare(GLuint shaderProgram, GLuint VAO){

    /* Fonction finale du shader pour le créer et l'afficher */
    
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    
}

void shaderDelete(GLuint VAO, GLuint VBO, GLuint shaderProgram){

    glDeleteVertexArrays(2, &VAO);
	glDeleteBuffers(2, &VBO);
	glDeleteProgram(shaderProgram);

}