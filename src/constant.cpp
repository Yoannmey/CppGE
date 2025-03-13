#include <glfw3.h>
#include "constant.h"

GLFWwindow* window = NULL;

GLFWmonitor* monitor = NULL;

int window_width = 920;
int window_height = 880;

GLuint vertexbuffer; 
GLuint VertexArrayID; 

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
