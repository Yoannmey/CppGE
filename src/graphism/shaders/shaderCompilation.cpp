#include <../../include/GLAD/glad.h>
#include <../../include/GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "../../constant.h"
#include "../graphism_functions.h"

using namespace std;

/**
 * @brief Compile et lie les shaders pour créer un programme shader
 * 
 * Cette fonction effectue toutes les étapes nécessaires pour créer un programme shader OpenGL :
 * 1. Création et compilation du vertex shader (shader de sommets)
 *    - Le vertex shader traite chaque sommet de la géométrie
 *    - Il permet de transformer les positions des sommets
 * 
 * 2. Création et compilation du fragment shader (shader de pixels)
 *    - Le fragment shader détermine la couleur de chaque pixel
 *    - Il s'exécute pour chaque pixel qui sera affiché
 * 
 * 3. Création du programme shader
 *    - Lie les deux shaders ensemble
 *    - Crée un programme exécutable sur la carte graphique
 * 
 * 4. Nettoyage
 *    - Supprime les shaders individuels après la création du programme
 *    - Libère la mémoire car les shaders ne sont plus nécessaires
 * 
 * @param shaderProgram Identifiant du programme shader à créer
 * @param vertexSource Code source du vertex shader en GLSL
 * @param fragmentSource Code source du fragment shader en GLSL
 * @return GLuint Identifiant du programme shader créé
 */
GLuint shaderCompilation(GLuint shaderProgram, const char* vertexSource, const char* fragmentSource){
    // Création et compilation du vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    // Création et compilation du fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Création et configuration du programme shader
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Nettoyage des shaders individuels
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
