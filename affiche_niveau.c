#include "structure_bibli.h"

void affiche_grille(int** grille, int longueur, int largeur) {// Fonction pour afficher la grille pour le codeur
    int v = verif_para_L_l(longueur, largeur);// Fonction pour vérifier les paramètres de longueur et de largeur
    if (v == -15) {
        printf("pb de parametre longueur ou largeur dans procedure affiche_grille\n");
        exit(1);
    }
    int v1 = verif_para_grille(grille);// Fonction pour vérifier si la grille est allouée
    if (v1 == -20) {
        printf("Pb allocation grille dans procedure liberation_grille\n");
        exit(2);
    }

    char* Rouge = "\033[31m"; // Constante qui permet d'écrire en rouge 
    char* Vert = "\033[32m"; // Constante qui permet d'écrire en vert 
    char* Jaune = "\033[33m"; // Constante qui permet d'écrire en jaune
    char* Reset = "\033[0m"; // Constante qui permet d'écrire avec la couleur d'origine du terminal 
    int count = 0, count1 = 0; // Constante de vérif si toutes les cibles et tous les robots sont positionnés
    longueur = longueur * 2 + 1; // On fait x*2+1 afin de pouvoir mettre les traits sous forme de case 
    largeur = largeur * 2 + 1; // On fait x*2+1 afin de pouvoir mettre les traits sous forme de case 
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) { // Double boucle car tableau 2D.
            if (grille[i][j] == 1) { // Condition pour afficher le numéro en rouge
                printf("%s%3d%s", Rouge, grille[i][j], Reset);// Affichage numero en rouge
            } else if (grille[i][j] > 1 && grille[i][j] < 21) { // Condition pour afficher le numéro de la cible en vert
                printf("%s%3d%s", Vert, grille[i][j], Reset);// Affichage numero en vert
                count++; // Augmentation du compteur.
            } 
            else if (grille[i][j]==90){// Condition pour afficher le tracer en rouge
                printf("%s  *%s",Rouge,Reset);// Affichage numero en rouge
            }
            else if (grille[i][j] >= 21 && grille[i][j] < 25) { // Condition pour afficher le numéro du robot en jaune
                printf("%s%3d%s", Jaune, grille[i][j], Reset);// Affichage numero en jaune
                count1++; // Augmentation du compteur.
            } else {
                printf("%3d", grille[i][j]); // Si cette case n'a pas le bon numéro pour être en couleur, elle reste de la                     couleur du terminal.
            }
        }
        
        printf("\n"); // Saut de ligne après chaque fin de ligne
    }
    //printf("%d et %d", count, count1); // Affiche des compteurs.
}

void affiche_grille_J(int** grille, int longueur, int largeur) {// Fonction pour afficher la grille pour le joueur

    int v = verif_para_L_l(longueur, largeur);// Fonction pour vérifier les paramètres de longueur et de largeur
    if (v == -15) {
        printf("pb de parametre longueur ou largeur dans procedure affiche_grille\n");
        exit(1);
    }
    int v1 = verif_para_grille(grille);// Fonction pour vérifier si la grille est allouée
    if (v1 == -20) {
        printf("Pb allocation grille dans procedure liberation_grille\n");
        exit(2);
    }

    char* Rouge = "\033[31m"; // Constante qui permet d'écrire en rouge 
    char* Vert = "\033[32m"; // Constante qui permet d'écrire en vert 
    char* Jaune = "\033[33m"; // Constante qui permet d'écrire en jaune
    char* Reset = "\033[0m"; // Constante qui permet d'écrire avec la couleur d'origine du terminal 


    longueur = longueur * 2 + 1;// On fait x*2+1 afin de pouvoir mettre les traits sous forme de case 
    largeur = largeur * 2 + 1;// On fait x*2+1 afin de pouvoir mettre les traits sous forme de case 
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) {// Double boucle car tableau 2D
            if (grille[i][j] == 1) {// Condition pour savoir si c est un mur ou pas pour l affciher
                printf("  #");
            }
            else if (grille[i][j] > 1 && grille[i][j] < 21) {// Condition pour savoir si c est une cible ou pas pour l                   affciher
                printf("%s%3d%s", Vert, grille[i][j] - 1, Reset);//affichage en vert du numéro de la cible (on fait moins 1                  car on part de 2 comme ca le joueur voit les cibles de 1 à 18)

            }
            else if (grille[i][j]==90){// condition pour afficher le tracer
                printf("%s  *%s",Rouge,Reset);// affichage du tracer en rouge 
            }
            else if (grille[i][j] >= 21 && grille[i][j] < 25) {// Condition pour savoir si c est un robot ou pas pour                    l'affciher
                if (grille[i][j] == 21) {// Si robot =21 on affcihe l emoji singe
                    printf(" 🙉");// affichage de l emoji singe
                } else if (grille[i][j] == 22) {// Si robot =22 on affcihe l emoji panda
                    printf(" 🐼");// affichage de l emoji panda
                } else if (grille[i][j] == 23) {// Si robot =23 on affcihe l emoji cochon
                    printf(" 🐷");// affichage de l emoji cochoon
                } else if (grille[i][j] == 24) {// Si robot =24 on affcihe l emoji crocodile
                    printf(" 🐊");// affichage de l emoji crocodile
                }
            } else {
                printf("   ");//sinon on affcihe 3 espaces
            }
        }
        printf("\n");// on saute un ligne
    }
}

void affiche_grille_durant_10_secondes(int **grille, int longueur,int largeur) {// Fonction d affichage de la grille pendant     10 secondes

  int v = verif_para_L_l(longueur, largeur);// Fonction pour vérifier les paramètres de longueur et de largeur
  if (v == -15) {
    printf("pb de parametre longueur ou largeur dans la procedure verif_coordonnees\n");
    exit(1);
  }
  int v1 = verif_para_grille(grille);// Fonction pour vérifier si la grille est allouée
  if (v1 == -20) {
    printf("Pb allocation grille dans procedure liberation_grille\n");
    exit(2);
  }

  time_t start_time = time(NULL);        // on recupere l'heure actuelle
  while (time(NULL) - start_time < 10) { // Boucle pendant 10 secondes
      system("clear"); // Efface l'écran
      affiche_grille_J(grille, longueur, largeur);// affichage de la grille pour le joueur
      sleep(1); // Pause de une seconde entre chaque affichage
  }
  system("clear");// Efface l'écran
}

void affiche_grille_durant_20_secondes(int **grille, int longueur,int largeur) {// Fonction d affichage de la grille pendant    20 secondes
  int v = verif_para_L_l(longueur, largeur);// Fonction pour vérifier les paramètres de longueur et de largeur
  if (v == -15) {
    printf("pb de parametre longueur ou largeur dans la procedure verif_coordonnees\n");
    exit(1);
  }
  int v1 = verif_para_grille(grille);// Fonction pour vérifier si la grille est allouée
  if (v1 == -20) {
    printf("Pb allocation grille dans procedure liberation_grille\n");
    exit(2);
  }

  time_t start_time = time(NULL);        // on reupere l'heure actuelle
  while (time(NULL) - start_time < 20) { // Boucle pendant 20 secondes
      system("clear"); // Efface l'écran
      affiche_grille_J(grille, longueur, largeur);// affichage de la grille pour le joueur
      sleep(1); // Pause de une seconde entre chaque affichage
  }
    
  system("clear");// Efface l'écran
}

void affiche_grille_durant_40_secondes(int **grille, int longueur,int largeur) {// Fonction d affichage de la grille pendant    40 secondes

  int v = verif_para_L_l(longueur, largeur);// Fonction pour vérifier les paramètres de longueur et de largeur
  if (v == -15) {
    printf("pb de parametre longueur ou largeur dans la procedure verif_coordonnees\n");
    exit(1);
  }
  int v1 = verif_para_grille(grille);// Fonction pour vérifier si la grille est allouée
  if (v1 == -20) {
    printf("Pb allocation grille dans procedure liberation_grille\n");
    exit(2);
  }

  time_t start_time = time(NULL);        // on recupere l'heure actuelle
  while (time(NULL) - start_time < 40) { // Boucle pendant 40 secondes
      system("clear"); // Efface l'écran
      affiche_grille_J(grille, longueur, largeur);// affichage de la grille pour le joueur
      sleep(1); // Pause de une seconde entre chaque affichage
  }
  system("clear");// Efface l'écran
}


void affiche_grille_durant_60_secondes(int **grille, int longueur,int largeur) {// Fonction d affichage de la grille pendant    60 secondes

  int v = verif_para_L_l(longueur, largeur);// Fonction pour vérifier les paramètres de longueur et de largeur
  if (v == -15) {
    printf("pb de parametre longueur ou largeur dans la procedure verif_coordonnees\n");
    exit(1);
  }
  int v1 = verif_para_grille(grille);// Fonction pour vérifier si la grille est allouée
  if (v1 == -20) {
    printf("Pb allocation grille dans procedure liberation_grille\n");
    exit(2);
  }

  time_t start_time = time(NULL);        // on recupere l'heure actuelle
  while (time(NULL) - start_time < 60) { // Boucle pendant 60 secondes
      system("clear"); // Efface l'écran
      affiche_grille_J(grille, longueur, largeur);// affichage de la grille pour le joueur
      sleep(1); // Pause de une seconde entre chaque affichage
  }
  system("clear");// Efface l'écran
}

void niveau_de_difficulte(int **grille, int longueur,int largeur, int nv){// Procédure qui demande le niveau de difficulté et     affcihe la grille en fonction
    int v = verif_para_L_l(longueur, largeur);// Fonction pour vérifier les paramètres de longueur et de largeur
    if (v == -15) {
        printf("pb de parametre longueur ou largeur dans la procedure verif_coordonnees\n");
        exit(1);
    }
    int v1 = verif_para_grille(grille);// Fonction pour vérifier si la grille est allouée
    if (v1 == -20) {
        printf("Pb allocation grille dans procedure liberation_grille\n");
        exit(2);
    }
  
    if(nv<1 && nv>4){// verification si le niveau n est pas superieur à 4 et inferieur à 1
        printf("Pb d argument lvl dans la fct niveau_de_difficulté\n");
        exit(3);// Si superieur le programme s'arrete 
    }

    if(nv==1){// niveau facile
        affiche_grille_durant_60_secondes(grille,longueur,largeur);// affcihage durant 60 secondes
        //printf("\n");
    }
        
    else if(nv==2){// niveau intermediaire
        affiche_grille_durant_40_secondes(grille,longueur,largeur);// affcihage durant 40 secondes
        //printf("\n");
    }
        
    else if(nv==3){// niveau difficle
        affiche_grille_durant_20_secondes(grille,longueur,largeur);// affcihage durant 20 secondes
        //printf("\n");
    }
        
    else if(nv==4){// niveau hard
        affiche_grille_durant_10_secondes(grille,longueur,largeur);// affcihage durant 10 secondes
        //printf("\n");
    }
}