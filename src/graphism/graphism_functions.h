#pragma once

#include <glfw3.h>
#include "../constant.h"

int createWindow(GLFWwindow*& window, int fullscreen);

void input(GLFWwindow* window);

void checkMousePos(GLFWwindow* window, int button, int action, int mods);

void backgroundColor( float r, float g, float b, float a);

float convertToOpengl(float point, float taille);

void createShader(GLuint &shaderProgram, const char* vertexSource, const char* fragmentSource);

void createShader2(GLuint &VAO, GLuint &VBO, GLfloat* vertexs, int size);