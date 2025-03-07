#include <../../include/GLAD/glad.h>
#include <../../include/GLFW/glfw3.h>
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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if(fullscreen == 1){
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        // cout << "Screen width: " << mode->width << ", Screen height: " << mode->height << endl;

        window = glfwCreateWindow(mode -> width, mode -> height, WINDOW_NAME, glfwGetPrimaryMonitor(), NULL);

        window_width = mode -> width;
        window_height = mode -> height;
    }

    else{
        window = glfwCreateWindow(window_width, window_height, WINDOW_NAME, NULL, NULL);
    }
    
    if (!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){

        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    if(fullscreen == 1){
        glViewport(0, 0, 1920, 1080);
    }
    else{
        glViewport(0, 0, window_width, window_height);
    }

    while (!glfwWindowShouldClose(window)){
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        input(window);

        drawTriangleTest(10,900,100,900,45,500);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return fullscreen;
}

void input(GLFWwindow* window){

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
        glfwSetMouseButtonCallback(window, checkMousePos);
    }

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }

}

void backgroundColor( int r, int g, int b, int a){
    glClearColor(r, g, b, a);
    
}

void checkMousePos(GLFWwindow* window, int button, int action, int mods){

/* Donne la position du curseur */

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

float convertToOpengl(float point, float taille){

/* Converti les coordonées */

    float openPoint = (point/taille)*2-1;

    return openPoint;
}

void drawTriangleTest(int xGauche, int yGauche, int xDroite, int yDroite, int xHaut, int yHaut){

/* Dessine un triangle */

    glGenVertexArrays(1, &VertexArrayID); 
    glBindVertexArray(VertexArrayID);

    float xG = convertToOpengl(xGauche, window_width);
    float xD = convertToOpengl(xDroite, window_width);
    float xH = convertToOpengl(xHaut, window_width);

    float yG = convertToOpengl(yGauche, window_width);
    float yD = convertToOpengl(yDroite, window_width);
    float yH = convertToOpengl(yHaut, window_width);

    static const GLfloat g_vertex_buffer_data[] = { 
        xG, yG, 0.0f, 
        xD, yD, 0.0f, 
        xH, yH, 0.0f, 
     };
     

    glGenBuffers(1, &vertexbuffer); 
    

    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); 
    

    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0); 
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); 
    glVertexAttribPointer( 
    0,                  
    3,                  
    GL_FLOAT,           
    GL_FALSE,           
    0,                  
    (void*)0            
    ); 
    
    
    glDrawArrays(GL_TRIANGLES, 0, 3); 
    
    glDisableVertexAttribArray(0);

}