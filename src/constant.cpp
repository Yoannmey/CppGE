#include <glfw3.h>
#include "constant.h"

/**
 * @brief Pointeur vers la fenêtre principale GLFW
 * Utilisé pour gérer la fenêtre de l'application
 */
GLFWwindow* window = NULL;

/**
 * @brief Pointeur vers le moniteur principal
 * Utilisé pour la gestion du mode plein écran
 */
GLFWmonitor* monitor = NULL;

/**
 * @brief Largeur par défaut de la fenêtre en pixels
 */
int window_width = 920;

/**
 * @brief Hauteur par défaut de la fenêtre en pixels
 */
int window_height = 880;

/**
 * @brief Buffer de vertices OpenGL
 * Stocke les données des vertices pour le rendu
 */
GLuint vertexbuffer; 

/**
 * @brief Identifiant du Vertex Array Object
 * Stocke la configuration des attributs de vertices
 */
GLuint VertexArrayID; 

/**
 * @brief Code source du Vertex Shader
 * 
 * Shader GLSL version 330 core qui :
 * - Prend en entrée une position 3D (vec3)
 * - Transforme cette position en vec4 pour le pipeline de rendu
 * - Passe directement la position au fragment shader sans modification
 */
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

/**
 * @brief Code source du Fragment Shader
 * 
 * Shader GLSL version 330 core qui :
 * - Définit la couleur de sortie (FragColor)
 * - Colore tous les pixels en jaune clair (RGB: 1.0, 1.0, 0.02)
 * - Utilise une opacité complète (Alpha: 1.0)
 */
const char* fragmentShaderSource ="#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n" 
"{\n"
"   FragColor = vec4(1.0f, 1.0f, 0.02f, 1.0f);\n"
"}\n\0";
