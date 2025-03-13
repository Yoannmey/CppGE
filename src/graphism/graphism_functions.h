#pragma once

#include <glfw3.h>
#include "../constant.h"

int createWindow(GLFWwindow*& window, int fullscreen);

void input(GLFWwindow* window);

void checkMousePos(GLFWwindow* window, int button, int action, int mods);

void backgroundColor( float r, float g, float b, float a);

float convertToOpengl(float point, float taille);

GLfloat trianglePosition12(int x, int y, int longueur, GLfloat* positions);

GLfloat squarePosition18(int x, int y, int longueur, GLfloat* positions);

GLfloat rectPosition18(int x, int y, int longueur, int largeur, GLfloat* positions);