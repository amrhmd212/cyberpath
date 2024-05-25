#include "structure_bibli.h"


int** allocation_grille(int longueur, int largeur) { // Fonction qui nous sert à l'allocation dynamique de notre matrice.
    int v = verif_para_L_l(longueur, largeur);// fonction qui verifie si les paramètres longueur et largeur sont bon
    if (v == -15) {
        printf("pb de parametre longueur ou largeur dans fct allocation_grille\n");
        exit(1);
    }

    longueur = longueur * 2 + 1; // On fait x*2+1 afin de pouvoir mettre les traits sous forme de case 
    largeur = largeur * 2 + 1; // On fait x*2+1 afin de pouvoir mettre les traits sous forme de case 

    int** grille = malloc(longueur * sizeof(int*)); // Utilisation de malloc pour initialiser un tableau d'une colonne de          taille longueur dans lequel il se trouve dans chaque case une adresse qui renvoie sur une ligne d'un autre tableau
    
    for (int i = 0; i < longueur; i++) { // Boucle for pour faire chaque ligne du premier tableau 
        grille[i] = malloc(largeur * sizeof(int)); // Utilisation d'un deuxième malloc pour cette fois-ci allouer la placer            pour chaque colonne et il y a largeur colonne  
    }
    return grille; // On retourne la grille allouée
}

void liberation_grille(int** grille, int longueur) {// Fonction pour libérer l'espace alloué quand on en a plus besoin
    int v1 = verif_para_grille(grille);// fonction qui verifie si les paramètres longueur et largeur sont bon
    if (v1 == -20) {
        printf("Pb allocation grille dans procedure liberation_grille\n");
        exit(2);// on quitte le progarmme 
    }
    if (longueur < 15 || longueur > 20) {
        printf("pb de longueur dans procedure liberation_grille\n");
        exit(3);// on quitte le progarmme 
    }
    for (int i = 0; i < longueur; i++) { // Boucle pour parcourir chaque case du premier tableau qui contient toutes les           adresses des autres tableaux
        free(grille[i]); // On libere la ligne i du tableau qui contenait l adresse d un autre tableau 
    }
    free(grille);
}
