#pragma once 

#include <glfw3.h>

#define WINDOW_NAME "test"

extern GLFWwindow* window;
extern GLFWmonitor* monitor;

extern int window_width;
extern int window_height;

extern GLuint vertexbuffer; 
extern GLuint VertexArrayID; 

extern const char* vertexShaderSource;
extern const char* fragmentShaderSource;