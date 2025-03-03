#include <glfw3.h>
#include <iostream>
#include <cmath>
#include "../constant.h"
#include "graphism_functions.h"


using namespace std;


int createWindow(GLFWwindow*& window, int fullscreen){

/* Fonction pour créer une fenêtre, elle prends comme paramètres le pointeur sur window, et la variable fullscreen qui prends comme valeur 1 si true */

    if (!glfwInit()){
        return -1;
    }

    if(fullscreen == 1){
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        // cout << "Screen width: " << mode->width << ", Screen height: " << mode->height << endl;

        window = glfwCreateWindow(mode -> width, mode -> height, WINDOW_NAME, glfwGetPrimaryMonitor(), NULL);
    }

    else{
        window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);
    }

    if (!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        
        glfwPollEvents();

        glfwSetMouseButtonCallback(window, checkMousePos);
    }

    glfwTerminate();

    return fullscreen;
}

void checkMousePos(GLFWwindow* window, int button, int action, int mods){

/* Donne la position du curseur lorsque le clic gauche est pressé */

    double DposX, DposY;

    glfwGetCursorPos(window, &DposX, &DposY);

    int posX = static_cast<int>(floor(DposX));
    int posY = static_cast<int>(floor(DposY));

    if(posX > 10000){
        posX -= 32000;
        posY -= 32000;
    }
    
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        cout << "Mouse pos is: " << posX << "X " << posY << "Y" << endl;
    }
}