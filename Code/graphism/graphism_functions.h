#pragma once

#include <glfw3.h>
#include "../constant.h"

int createWindow(GLFWwindow*& window, int fullscreen);

void checkMousePos(GLFWwindow* window, int button, int action, int mods);