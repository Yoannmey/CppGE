#pragma once

#include <glfw3.h>
#include "../../constant.h"

GLuint createShaderVAO(GLuint VAO, GLuint VBO, GLfloat* vertexs, int size);

GLuint createVBO(GLuint VBO);

void shader(GLuint shaderProgram, GLuint VAO);