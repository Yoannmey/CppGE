#include <../../include/GLAD/glad.h>
#include <../../include/GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "../../constant.h"
#include "../graphism_functions.h"
#include "../../main.h"

using namespace std;



GLuint shaderCompilation(GLuint shaderProgram, const char* vertexSource, const char* fragmentSource){

    cout << "test" << endl;

    /* Cette fonction créer le shaderProgram grâce au vertex et au fragment sélectionné */
    
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);
    
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);
    
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
    
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    
        cout << "test2" << endl;

        return shaderProgram;
}
