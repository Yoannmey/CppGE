#include <glfw3.h>
#include "../constant.h"
#include <cstdio>

int createWindow(GLFWwindow* window, int fullscreen){

    if (!glfwInit()){
        return -1;
    }


    if(fullscreen == 1){
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
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
    }

    glfwTerminate();

    return 0;
}