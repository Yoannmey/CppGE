#pragma once

#include <glfw3.h>
#include "../constant.h"

void shader(int numeroFragment);

void createShader(GLuint VAO, GLuint VBO, GLfloat vertexs, int size);

int initShader(int numeroFragment);

int shaderCompilation(const char* vertexSource, const char* fragmentSource);

char fragmentSwitch(int cas);