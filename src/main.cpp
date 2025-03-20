#include <glfw3.h>
#include <cstdio>
#include "graphism/graphism_functions.h"
#include "constant.h"

/**
 * @brief Configure les paramètres initiaux du jeu
 * 
 * Cette fonction initialise l'environnement du jeu :
 * - Définit la couleur de fond en bleu clair (RGB: 100, 100, 255)
 * - Peut être étendue pour ajouter d'autres initialisations
 */
void gameSetUp(){
    backgroundColor(100, 100, 255, 1);
}

/**
 * @brief Boucle principale du jeu
 * 
 * Cette fonction est appelée à chaque frame pour :
 * - Mettre à jour la logique du jeu
 * - Gérer les événements
 * - Effectuer le rendu
 * 
 * Note: Actuellement vide, à implémenter selon les besoins du jeu
 */
void gameLoop(){
    // À implémenter : logique de jeu, mise à jour, etc.
}

/**
 * @brief Point d'entrée principal du programme
 * 
 * Cette fonction :
 * 1. Crée la fenêtre principale en mode plein écran
 * 2. Configure l'environnement OpenGL
 * 3. Initialise les ressources nécessaires
 * 
 * @return int Code de retour (0 pour succès)
 */
int main(void){
    createWindow(window, 1);
    return 0;
}
