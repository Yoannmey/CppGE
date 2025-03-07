#pragma once

#include <glfw3.h>
#include "../constant.h"

int createWindow(GLFWwindow*& window, int fullscreen);

void input(GLFWwindow* window);

void checkMousePos(GLFWwindow* window, int button, int action, int mods);

void backgroundColor( int r, int g, int b, int a);

float convertToOpengl(float point, float taille);

void drawTriangleTest(int xGauche, int yGauche, int xDroite, int yDroite, int xHaut, int yHaut);
