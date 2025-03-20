# Définitions des Termes Techniques

Ce document explique les termes techniques anglais utilisés dans le projet CppGE (C++ Game Engine).

## Termes Généraux

- **GLFW** (OpenGL Framework) : Une bibliothèque qui facilite la création de fenêtres, de contextes et de surfaces OpenGL, ainsi que la gestion des entrées utilisateur.

- **GLAD** (GL/GL Loader-Generator) : Un générateur/chargeur de fonctions OpenGL qui charge dynamiquement les fonctions OpenGL appropriées pour votre système.

## Termes liés aux Shaders

- **Shader** : Programme qui s'exécute sur la carte graphique (GPU) pour traiter les graphismes.
  - **Vertex Shader** : Programme qui traite chaque sommet (point) d'un objet 3D.
  - **Fragment Shader** : Programme qui détermine la couleur de chaque pixel à l'écran.

- **GLSL** (OpenGL Shading Language) : Le langage de programmation utilisé pour écrire les shaders OpenGL.

## Termes liés aux Buffers et Arrays

- **VAO** (Vertex Array Object) : Objet qui stocke la configuration des attributs de vertices (comme la position, la couleur, etc.).

- **VBO** (Vertex Buffer Object) : Buffer qui stocke les données des vertices (points) dans la mémoire de la carte graphique.

- **Buffer** : Zone de mémoire utilisée pour stocker des données.

## Termes liés au Rendu

- **Vertex** (pl. Vertices) : Point dans l'espace 3D qui définit la géométrie d'un objet.

- **Fragment** : Zone correspondant à un pixel potentiel à l'écran.

- **Pipeline** : Séquence d'étapes de traitement pour transformer les données 3D en image 2D.

## Termes liés à la Fenêtre

- **Window** : Fenêtre de l'application où le rendu est affiché.

- **Monitor** : Écran physique sur lequel l'application est affichée.

- **Fullscreen** : Mode plein écran.

## Termes liés aux Coordonnées

- **Position** : Emplacement d'un point dans l'espace.
  - **vec3** : Vecteur à 3 composantes (x, y, z)
  - **vec4** : Vecteur à 4 composantes (x, y, z, w)

## Termes liés aux Couleurs

- **RGB** (Red, Green, Blue) : Système de couleurs additives.
  - **R** : Rouge (0-255 ou 0.0-1.0)
  - **G** : Vert (0-255 ou 0.0-1.0)
  - **B** : Bleu (0-255 ou 0.0-1.0)

- **Alpha** : Valeur de transparence (0.0 = transparent, 1.0 = opaque)
