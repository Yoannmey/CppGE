#pragma once

#include <glfw3.h>
#include "../../constant.h"

typedef struct {
    GLuint VAO;
    GLuint VBO;
    GLuint shaderProgram;
} vertexArray;

vertexArray createShader(GLuint VAO, GLuint VBO, GLfloat* vertexs, int size, GLuint shaderProgram, const char* vertexSource, const char* fragmentSource );

void shaderLoopTriangle(GLuint shaderProgram, GLuint VAO);

void shaderLoopSquare(GLuint shaderProgram, GLuint VAO);

void shaderDelete(GLuint VAO, GLuint VBO, GLuint shaderProgram);