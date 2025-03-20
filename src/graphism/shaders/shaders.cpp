#include <../../include/GLAD/glad.h>
#include <../../include/GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "../../constant.h"
#include "../graphism_functions.h"
#include "shaderCompilation.h"
#include "shaders.h"

using namespace std;

/**
 * @brief Crée et configure un shader avec ses buffers associés
 * 
 * Cette fonction permet de créer un nouveau shader en initialisant tous les éléments nécessaires :
 * - Compile le shader à partir des sources fournies
 * - Crée et configure le Vertex Array Object (VAO)
 * - Crée et configure le Vertex Buffer Object (VBO)
 * - Configure les attributs des vertices
 * 
 * @param VAO Identifiant du Vertex Array Object à créer
 * @param VBO Identifiant du Vertex Buffer Object à créer
 * @param vertexs Tableau contenant les coordonnées des vertices
 * @param size Taille en octets des données de vertices
 * @param shaderProgram Identifiant du programme shader à utiliser
 * @param vertexSource Code source du vertex shader
 * @param fragmentSource Code source du fragment shader
 * @return vertexArray Structure contenant les identifiants VAO, VBO et shaderProgram
 */
vertexArray createShader(GLuint VAO, GLuint VBO, GLfloat* vertexs, int size, GLuint shaderProgram, const char* vertexSource, const char* fragmentSource ){

    shaderProgram = shaderCompilation(shaderProgram,vertexSource,fragmentSource);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, size, vertexs, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    vertexArray VABO = { VAO, VBO, shaderProgram};
    
    return VABO;
}

/**
 * @brief Dessine un triangle en utilisant le shader spécifié
 * 
 * Cette fonction effectue les étapes nécessaires pour afficher un triangle :
 * - Active le programme shader
 * - Lie le VAO contenant les données du triangle
 * - Dessine le triangle avec 3 vertices
 * 
 * @param shaderProgram Identifiant du programme shader à utiliser
 * @param VAO Identifiant du Vertex Array Object contenant les données du triangle
 */
void shaderLoopTriangle(GLuint shaderProgram, GLuint VAO){
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

/**
 * @brief Dessine un carré en utilisant le shader spécifié
 * 
 * Cette fonction effectue les étapes nécessaires pour afficher un carré :
 * - Active le programme shader
 * - Lie le VAO contenant les données du carré
 * - Dessine le carré (composé de 2 triangles, donc 6 vertices)
 * 
 * @param shaderProgram Identifiant du programme shader à utiliser
 * @param VAO Identifiant du Vertex Array Object contenant les données du carré
 */
void shaderLoopSquare(GLuint shaderProgram, GLuint VAO){
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

/**
 * @brief Nettoie les ressources OpenGL utilisées par le shader
 * 
 * Cette fonction libère la mémoire en supprimant :
 * - Le Vertex Array Object (VAO)
 * - Le Vertex Buffer Object (VBO)
 * - Le programme shader
 * 
 * À appeler quand on n'a plus besoin du shader pour éviter les fuites de mémoire.
 * 
 * @param VAO Identifiant du Vertex Array Object à supprimer
 * @param VBO Identifiant du Vertex Buffer Object à supprimer
 * @param shaderProgram Identifiant du programme shader à supprimer
 */
void shaderDelete(GLuint VAO, GLuint VBO, GLuint shaderProgram){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
}