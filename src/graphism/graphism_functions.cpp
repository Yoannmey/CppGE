#include <../../include/GLAD/glad.h>
#include <../../include/GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "../constant.h"
#include "graphism_functions.h"
#include "shaders/shaders.h"
#include "shaders/shaderCompilation.h"

using namespace std;

/**
 * @brief Crée et initialise une fenêtre GLFW avec OpenGL
 * 
 * Cette fonction configure et crée une fenêtre qui peut être en mode plein écran ou fenêtré.
 * Elle initialise également le contexte OpenGL et configure les shaders de base.
 * 
 * Étapes principales :
 * 1. Initialisation de GLFW et configuration des options OpenGL
 * 2. Création de la fenêtre (plein écran ou fenêtrée selon le paramètre)
 * 3. Initialisation de GLAD pour la gestion des fonctions OpenGL
 * 4. Configuration du viewport
 * 5. Création d'un shader de base et configuration d'un rectangle
 * 6. Boucle principale de rendu
 * 
 * @param window Référence vers le pointeur de la fenêtre GLFW à créer
 * @param fullscreen 1 pour mode plein écran, 0 pour mode fenêtré
 * @return int -1 en cas d'erreur, sinon retourne la valeur de fullscreen
 */
int createWindow(GLFWwindow*& window, int fullscreen){
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if(fullscreen == 1){
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        window = glfwCreateWindow(mode->width, mode->height, WINDOW_NAME, glfwGetPrimaryMonitor(), NULL);
        window_width = mode->width;
        window_height = mode->height;
    }
    else{
        window = glfwCreateWindow(window_width, window_height, WINDOW_NAME, NULL, NULL);
    }
    
    if (window == NULL){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, window_width, window_height);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    GLfloat positions[18]; 
    rectPosition18(0, 0, 200, 300, positions);
    vertexArray VABO1 = createShader(VABO1.VAO, VABO1.VBO, positions, sizeof(positions), VABO1.shaderProgram, vertexShaderSource, fragmentShaderSource);

    while (!glfwWindowShouldClose(window)){
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        input(window);
        shaderLoopSquare(VABO1.shaderProgram, VABO1.VAO);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    shaderDelete(VABO1.VAO, VABO1.VBO, VABO1.shaderProgram);
    glfwDestroyWindow(window);
    glfwTerminate();

    return fullscreen;
}

/**
 * @brief Gère les entrées utilisateur (souris et clavier)
 * 
 * Cette fonction vérifie :
 * - Le clic gauche de la souris pour afficher sa position
 * - La touche Échap pour fermer la fenêtre
 * 
 * @param window Pointeur vers la fenêtre GLFW active
 */
void input(GLFWwindow* window){
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
        glfwSetMouseButtonCallback(window, checkMousePos);
    }

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

/**
 * @brief Change la couleur de fond de la fenêtre
 * 
 * Convertit les valeurs RGB de 0-255 en valeurs OpenGL (0-1)
 * et applique la nouvelle couleur de fond.
 * 
 * @param r Rouge (0-255)
 * @param g Vert (0-255)
 * @param b Bleu (0-255)
 * @param a Alpha (0-1, transparence)
 */
void backgroundColor(float r, float g, float b, float a){
    r = r/255;
    g = g/255;
    b = b/255;
    cout << "colors: " << r << " " << g << " " << b << endl;
    glClearColor(r, g, b, a);
}

/**
 * @brief Callback pour obtenir et afficher la position du curseur
 * 
 * Cette fonction :
 * 1. Récupère la position du curseur
 * 2. Convertit les coordonnées en entiers
 * 3. Ajuste les coordonnées pour le mode plein écran
 * 4. Inverse l'axe Y pour correspondre au système de coordonnées OpenGL
 * 
 * @param window Pointeur vers la fenêtre GLFW
 * @param button Bouton de la souris concerné
 * @param action Action effectuée (appui ou relâchement)
 * @param mods Modificateurs de touches (Ctrl, Alt, etc.)
 */
void checkMousePos(GLFWwindow* window, int button, int action, int mods){
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

/**
 * @brief Convertit les coordonnées écran en coordonnées OpenGL
 * 
 * OpenGL utilise un système de coordonnées normalisé de -1 à 1.
 * Cette fonction convertit une coordonnée écran en sa valeur OpenGL correspondante.
 * 
 * @param point Coordonnée à convertir (en pixels)
 * @param taille Taille totale (largeur ou hauteur de la fenêtre)
 * @return float Coordonnée convertie en système OpenGL (-1 à 1)
 */
float convertToOpengl(float point, float taille){
    float openPoint = (point/taille)*2-1;
    return openPoint;
}

/**
 * @brief Calcule les positions des vertices d'un triangle
 * 
 * Configure un tableau de 9 flottants (3 vertices x 3 coordonnées)
 * représentant les positions des sommets d'un triangle.
 * Les coordonnées sont converties du système écran vers OpenGL.
 * 
 * @param x Position X du coin inférieur gauche
 * @param y Position Y du coin inférieur gauche
 * @param longueur Longueur des côtés du triangle
 * @param positions Tableau de sortie pour les coordonnées des vertices
 */
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

/**
 * @brief Calcule les positions des vertices d'un carré
 * 
 * Configure un tableau de 18 flottants (6 vertices x 3 coordonnées)
 * représentant les positions des sommets d'un carré.
 * Le carré est composé de deux triangles.
 * Les coordonnées sont converties du système écran vers OpenGL.
 * 
 * @param x Position X du coin inférieur gauche
 * @param y Position Y du coin inférieur gauche
 * @param longueur Longueur des côtés du carré
 * @param positions Tableau de sortie pour les coordonnées des vertices
 */
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

    // En haut à gauche (répété pour le second triangle)
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

/**
 * @brief Calcule les positions des vertices d'un rectangle
 * 
 * Configure un tableau de 18 flottants (6 vertices x 3 coordonnées)
 * représentant les positions des sommets d'un rectangle.
 * Le rectangle est composé de deux triangles.
 * Les coordonnées sont converties du système écran vers OpenGL.
 * 
 * @param x Position X du coin inférieur gauche
 * @param y Position Y du coin inférieur gauche
 * @param largeur Largeur du rectangle
 * @param longueur Hauteur du rectangle
 * @param positions Tableau de sortie pour les coordonnées des vertices
 */
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

    // En haut à gauche (répété pour le second triangle)
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