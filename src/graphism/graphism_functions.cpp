#include <../../include/GLAD/glad.h>
#include <../../include/GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "../constant.h"
#include "graphism_functions.h"
#include "shaders/shaders.h"
#include "shaders/shaderCompilation.h"

using namespace std;

int createWindow(GLFWwindow*& window, int fullscreen){

/* Fonction pour créer une fenêtre, elle prends comme paramètres le pointeur sur window, et la variable fullscreen qui prends comme valeur 1 si true */

    glfwInit();

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
    
    if (window == NULL){
        // cout << "La fenetre n'a pas pu etre crée" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0,0,window_width, window_height);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){

        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    GLfloat positions[18]; 

    rectPosition18(0, 0, 200,300,positions);

    vertexArray VABO1 = createShader(VABO1.VAO, VABO1.VBO, positions, sizeof(positions), VABO1.shaderProgram, vertexShaderSource, fragmentShaderSource);

    // cout << "program: " << shaderProgramOrange << "VAO :" << VAO1 << "VBO :" << VBO << endl;

     while (!glfwWindowShouldClose(window)){
        
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        input(window);

        shaderLoopSquare(VABO1.shaderProgram, VABO1.VAO);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    shaderDelete(VABO1.VAO,VABO1.VBO, VABO1.shaderProgram);
    glfwDestroyWindow(window);
    glfwTerminate();

    return fullscreen;
}

void input(GLFWwindow* window){

/* Gére les events liés à la souris et au clavier */

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
        glfwSetMouseButtonCallback(window, checkMousePos);
    }

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }

}

void backgroundColor( float r, float g, float b, float a){

/* Change la couleur du fond et divisant les valeurs par 255 afin qu'elles soient comprises entre 0 et 1*/

    r = r/255;
    g = g/255;
    b = b/255;
    cout << "colors: " << r << " " << g << " " << b << endl;

    glClearColor(r, g, b, a);
    
}

void checkMousePos(GLFWwindow* window, int button, int action, int mods){

/* Donne la position du curseur, il convertit la position donnée par GLFW en int et l'affiche dans le terminal, si la fenetre est en plein écran
   les coordonées de départ sont 32000 et 32000 au lieu de 0 0*/

    double DposX, DposY;

    glfwGetCursorPos(window, &DposX, &DposY);

    int posX = static_cast<int>(floor(DposX));
    int posY = static_cast<int>(floor(DposY));

    if(posX > 10000){
        posX -= 32000;
        posY -= 32000;
    }
    posY = window_height - posY;
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        cout << "Mouse pos is: " << posX << "X " << posY << "Y" << endl;
    }
}

float convertToOpengl(float point, float taille){

/* Converti les coordonées, grâce à la coordonnée x ou y du point ainsi que la taille de la fenetre, width pour x et height pour y*/

    float openPoint = (point/taille)*2-1;

    return openPoint;
}

GLfloat trianglePosition12(int x, int y, int longueur, GLfloat* positions){

    // En bas à gauche
    positions[0] = convertToOpengl(x, window_width);
    positions[1] = convertToOpengl(y, window_height);
    positions[2] = 0.0f;

    // En bas à droite
    positions[3] = convertToOpengl(x + longueur, window_width);
    positions[4] = convertToOpengl(y, window_height);
    positions[5] = 0.0f;

    // En haut à droite
    positions[6] = convertToOpengl(x + longueur, window_width);
    positions[7] = convertToOpengl(y + longueur, window_height);
    positions[8] = 0.0f;

}

GLfloat squarePosition18(int x, int y, int longueur, GLfloat* positions){

    // En bas à gauche
    positions[0] = convertToOpengl(x, window_width);
    positions[1] = convertToOpengl(y, window_height);
    positions[2] = 0.0f;

    // En bas à droite
    positions[3] = convertToOpengl(x + longueur, window_width);
    positions[4] = convertToOpengl(y, window_height);
    positions[5] = 0.0f;

    // En haut à gauche
    positions[6] = convertToOpengl(x, window_width);
    positions[7] = convertToOpengl(y + longueur, window_height);
    positions[8] = 0.0f;

    // En haut à gauche
    positions[9] = convertToOpengl(x, window_width);
    positions[10] = convertToOpengl(y + longueur, window_height);
    positions[11] = 0.0f;

    // En haut à droite
    positions[12] = convertToOpengl(x + longueur, window_width);
    positions[13] = convertToOpengl(y + longueur, window_height);
    positions[14] = 0.0f;
    // En bas à droite
    positions[15] = convertToOpengl(x + longueur, window_width);
    positions[16] = convertToOpengl(y, window_height);
    positions[17] = 0.0f;

}

GLfloat rectPosition18(int x, int y, int largeur, int longueur, GLfloat* positions){

    // En bas à gauche
    positions[0] = convertToOpengl(x, window_width);
    positions[1] = convertToOpengl(y, window_height);
    positions[2] = 0.0f;

    // En bas à droite
    positions[3] = convertToOpengl(x + largeur, window_width);
    positions[4] = convertToOpengl(y, window_height);
    positions[5] = 0.0f;

    // En haut à gauche
    positions[6] = convertToOpengl(x, window_width);
    positions[7] = convertToOpengl(y + longueur, window_height);
    positions[8] = 0.0f;

    // En haut à gauche
    positions[9] = convertToOpengl(x, window_width);
    positions[10] = convertToOpengl(y + longueur, window_height);
    positions[11] = 0.0f;

    // En haut à droite
    positions[12] = convertToOpengl(x + largeur, window_width);
    positions[13] = convertToOpengl(y + longueur, window_height);
    positions[14] = 0.0f;
    // En bas à droite
    positions[15] = convertToOpengl(x + largeur, window_width);
    positions[16] = convertToOpengl(y, window_height);
    positions[17] = 0.0f;

}