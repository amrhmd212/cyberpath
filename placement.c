#include "structure_bibli.h"

int** placement_mur(int** grille, int longueur, int largeur) { // Fonction de placement des murs sur les bords du jeu + mur       aléatoire perpendiculaire au bord
    int v = verif_para_L_l(longueur, largeur);// Fonction qui me permet de verifier sur la longueur et la largeur on les          bonnes dimensions
    if (v == -15) {
        printf("pb de parametre longueur ou largeur dans fct placement_mur\n");
        exit(1); // si les paramètres sont pas bon on quitte le programme
    }

    int v1 = verif_para_grille(grille);// Fonction qui me permet de verifier si la grille a bien été allouée
    
    if (v1 == -20) {
        printf("Pb allocation grille dans procedure liberation_grille\n");
        exit(2);// si les paramètres sont pas bon on quitte le programme
    }

    int mur = 1; // Constante qu'on a décidé d'attribuer.
    int mur_invisible = 26; // Constante qu'on a décidé d'attribuer.
    int vide = 0; // Constante qu'on a décidé d'attribuer.
    longueur = longueur * 2 + 1; // On fait x*2+1 afin de pouvoir mettre les traits sous forme de case 
    largeur = largeur * 2 + 1; // On fait x*2+1 afin de pouvoir mettre les traits sous forme de case 
    srand(time(NULL)); // Initialisation de rand avec le temps actuel

    int ale1, ale2, ale3, ale4, ale5, ale6, ale7, ale8; // Déclaration des variables aléatoires

    do {
        ale1 = rand() % (longueur - 2) + 1; // Variable aléatoire qui sert à positionner les murs perpendiculaires au bord
        ale2 = rand() % (longueur - 2) + 1; // Variable aléatoire qui sert à positionner les murs perpendiculaires au bord
    } while (ale1 == ale2); // Condition pour ne pas que les 2 nombres aléatoires soient égaux 

    do {
        ale3 = rand() % (longueur - 2) + 1; // Variable aléatoire qui sert à positionner les murs perpendiculaires au bord
        ale4 = rand() % (longueur - 2) + 1; // Variable aléatoire qui sert à positionner les murs perpendiculaires au bord
    } while (ale3 == ale4); // Condition pour ne pas que les 2 nombres aléatoires soient égaux 

    do {
        ale5 = rand() % (largeur - 2) + 1; // Variable aléatoire qui sert à positionner les murs perpendiculaires au bord
        ale6 = rand() % (largeur - 2) + 1; // Variable aléatoire qui sert à positionner les murs perpendiculaires au bord
    } while (ale5 == ale6); // Condition pour ne pas que les 2 nombres aléatoires soient égaux 

    do {
        ale7 = rand() % (largeur - 2) + 1; // Variable aléatoire qui sert à positionner les murs perpendiculaires au bord
        ale8 = rand() % (largeur - 2) + 1; // Variable aléatoire qui sert à positionner les murs perpendiculaires au bord
    } while (ale7 == ale8); // Condition pour ne pas que les 2 nombres aléatoires soient égaux 

    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) { // Double boucle car tableau 2D.
            if ((i == 
                vide) || (j == vide) || (i == longueur - 1) || (j == largeur - 1) ||
                (i == 1 && j == ale1) || (i == 1 && j == ale2) ||
                (i == longueur - 2 && j == ale3) || (i == longueur - 2 && j == ale4) ||
                (i == ale5 && j == 1) || (i == ale6 && j == 1) ||
                (i == ale7 && j == largeur - 2) || (i == ale8 && j == largeur - 2)) { // Toutes les conditions nécessaires                    pour mettre un mur.
                grille[i][j] = mur; // Utilisation de la variable mur pour dire que cette case correspond à un mur
            }
            else if (j % 2 == 0 || i % 2 == 0) { // Condition avec i et j paire car les lignes et colonnes rajoutées sont                 celles qui sont paires
            grille[i][j] = mur_invisible; // Utilisation de la variable mur_invisible pour dire que cette case correspond à               un mur invisible
            }
            else {
                grille[i][j] = vide; // Utilisation de la variable vide car s'il n'y a pas de mur et de mur invisible, il n'y                 a pour le moment rien donc on met un 0.
            }
        }
    }

    return grille;
}
int** placement_cible(int** grille, int longueur, int largeur, Cible* tab_de_cibles) { // Fonction de placement des cibles
    int v = verif_para_L_l(longueur, largeur);// Fonction qui me permet de verifier sur la longueur et la largeur on les          bonnes dimensions
    if (v == -15) {
        printf("pb de parametre longueur ou largeur dans fct placement_cible\n");
        exit(1);// si les paramètres sont pas bon on quitte le programme
    }
    int v1 = verif_para_grille(grille);// Fonction qui me permet de verifier si la grille a bien été allouée
    if (v1 == -20) {
        printf("Pb allocation grille dans procedure liberation_grille\n");
        exit(2);// si les paramètres sont pas bon on quitte le programme
    }
    int v2 = verif_para_tab_de_cible(tab_de_cibles);// Fonction qui me permet de verifier si le tableau de cible a bien été       allouée
    if (v2 == -25) {
        printf("Pb allocation de tab_de_cibles dans fct placement_cible\n");
        exit(4);// si les paramètres sont pas bon on quitte le programme
    }

    int mur = 1;// Constante qu'on a décidé d'attribuer.
    int cible = 2; // Constante qu'on a décidé d'attribuer.
    int x = 0, y = 0; // Déclaration x et y pour les positions.
    int ale = 0; // Nombre aléatoire afin de mettre des murs autour des cibles 
    int essais = 0; // Compteur pour limiter le nombre d'essais de placement
    int max_essais = 10000; // Limite du nombre d'essais

    while (cible < 20 && essais < max_essais) { // Boucle pour arriver au bon nombre de cibles avec limite d'essais
        x = rand() % (longueur * 2 - 4) + 2; // Création nbr aléatoire
        y = rand() % (largeur * 2 - 4) + 2; // Création nbr aléatoire

        
        if ( // Vérification de la validité de la position (on verifie jusqu'à 2 cases tout autour de la cible et si la               position  (x;y) est libre)
        grille[x-2][y-2]!=cible && grille[x-1][y-2]!=cible && grille[x][y-2]!=cible && grille[x+1][y-2]!=cible && grille[x+2]         [y-2]!=cible && 
        grille[x-2][y-1]!=cible && grille[x-1][y-1]!=cible && grille[x][y-1]!=cible && grille[x+1][y-1]!=cible && grille[x+2]         [y-1]!=cible &&
        grille[x-2][y]!=cible && grille[x-1][y]!=cible && grille[x][y]==0 && grille[x+1][y]!=cible && grille[x+2][y]!=cible &&
        grille[x-2][y+1]!=cible && grille[x-1][y+1]!=cible && grille[x][y+1]!=cible && grille[x+1][y+1]!=cible && grille[x+2]         [y+1]!=cible &&
        grille[x-2][y+2]!=cible && grille[x-1][y+2]!=cible && grille[x][y+2]!=cible && grille[x+1][y+2]!=cible && grille[x+2]         [y+2]!=cible &&

        grille[x-2][y-2]!=mur && grille[x-1][y-2]!=mur && grille[x][y-2]!=mur && grille[x+1][y-2]!=mur && grille[x+2][y-              2]!=mur && 
        grille[x-2][y-1]!=mur && grille[x-1][y-1]!=mur && grille[x][y-1]!=mur && grille[x+1][y-1]!=mur && grille[x+2][y-              1]!=mur &&
        grille[x-2][y]!=mur && grille[x-1][y]!=mur && grille[x][y]==0 && grille[x+1][y]!=mur && grille[x+2][y]!=mur &&
        grille[x-2][y+1]!=mur && grille[x-1][y+1]!=mur && grille[x][y+1]!=mur && grille[x+1][y+1]!=mur && grille[x+2]                 [y+1]!=mur &&
        grille[x-2][y+2]!=mur && grille[x-1][y+2]!=mur && grille[x][y+2]!=mur && grille[x+1][y+2]!=mur && grille[x+2]                 [y+2]!=mur) {
            
                    int placement_possible = 1; // variable qui me permet de vérifier si le placement est possible
        
                    // Vérification des cases autour pour s'assurer qu'il n'y a pas d'autres cibles ou murs
                    for (int dx = -3; dx <= 3; dx++) {
                        for (int dy = -3; dy <= 3; dy++) {
                            if (x + dx >= 0 && x + dx < longueur * 2 + 1 && y + dy >= 0 && y + dy < largeur * 2 + 1) {
                                if (grille[x + dx][y + dy] > 1 && grille[x + dx][y + dy] <= 25) {
                                    placement_possible = 0;
                                    break;
                                }
                            }
                        }
                        
                        if (placement_possible!=0) break; // si le placement n'est pas possible on sort de la fonction
                    }
        
                    if (placement_possible==1) {//si placement possible =1 alors on place la cible
                        grille[x][y] = cible; // cible positionnée
        
                        tab_de_cibles[cible - 2].posi_cible.x = x; // Enregistrement des coordonnées de la cible (-2 car on                           commence robot à 2)
                        tab_de_cibles[cible - 2].posi_cible.y = y; // Enregistrement des coordonnées de la cible
        
                        ale = rand() % 4 + 1; // nombre aleatoire qui nous permet de placer l'orientation des murs
                        
                        if (ale == 1) {
                            grille[x - 1][y] = 1;
                            grille[x - 1][y - 1] = 1;
                            grille[x][y - 1] = 1;
                        } 
                        
                        else if (ale == 2) {
                            grille[x][y - 1] = 1;
                            grille[x + 1][y] = 1;
                            grille[x + 1][y - 1] = 1;
                        }
                        
                        else if (ale == 3) {
                            grille[x - 1][y] = 1;
                            grille[x - 1][y + 1] = 1;
                            grille[x][y + 1] = 1;
                        }
                        
                        else if (ale == 4) {
                            grille[x][y + 1] = 1;
                            grille[x + 1][y] = 1;
                            grille[x + 1][y + 1] = 1;
                        }
        
                        //printf("Cible %d placée en (%d, %d)\n", cible, x, y);
                        cible++; // Augmentation du numéro de la cible
                        essais = 0; // on remet a 0 le compteur d'essais pour la prochaine cible
                    } 
                    
                    else {
                        essais++; // on rajoute 1 au compteur d'essais si le placement a échoué
                    }

           
        } 
        else {
            essais++; // on rajoute 1 au compteur d'essais si la case est déjà prise
        }
    }

    if (cible < 20) {// si certaines cibles ne sont pas placées alors ce message s'affichera
        printf("Impossible de placer toutes les cibles après %d essais.\n", essais);
    }

    return grille;
}




int** placement_robot(int** grille, int longueur, int largeur, Robot* tab_de_robots) {// Fonction qui va me permettre de          placer les robots au sein de la grille 2D
    int v = verif_para_L_l(longueur, largeur);// Fonction qui me permet de verifier sur la longueur et la largeur on les          bonnes dimensions
    if (v == -15) {
        printf("pb de parametre longueur ou largeur dans fct placement_robot\n");
        exit(1);// si les paramètres sont pas bon on quitte le programme
    }
    int v1 = verif_para_grille(grille);// Fonction qui me permet de verifier si la grille a bien été allouée
    
    if (v1 == -20) {
        printf("Pb allocation grille dans procedure liberation_grille\n");
        exit(2);// si les paramètres sont pas bon on quitte le programme
    }
    int v2 = verif_para_tab_de_robot(tab_de_robots);// Fonction qui me permet de verifier si le tableau de robot a bien été       allouée
    if (v2 == -30) {
        printf("Pb allocation de tab_de_robots dans fct placement_robot\n");
        exit(4);// si les paramètres sont pas bon on quitte le programme
    }

    int robot = 21; // Constante qu'on a décidé d'attribuer.
    int x = 0, y = 0; // variable x et y pour les positions.

    while (robot <= 24) { // Boucle pour placer les 4 robots.
        do {
            x = rand() % (longueur * 2 - 4) + 2; // Création nbr aléatoire de base c'est (longueur-2)+1 mais vu qu'on                     multiplie par 2 la matrice, on le fait aussi ici.
            y = rand() % (largeur * 2 - 4) + 2; // Création nbr aléatoire de base c'est (longueur-2)+1 mais vu qu'on                      multiplie par 2 la matrice, on le fait aussi ici.
        } while (grille[x][y] != 0); // On vérifie si la case (x;y) est vide. Si elle n'est pas vide on recommence jusqu'à            trouver une case vide.

        if (grille[x + 1][y] != robot && grille[x + 1][y + 1] != robot && grille[x + 1][y - 1] != robot &&
            grille[x - 1][y] != robot && grille[x - 1][y + 1] != robot && grille[x - 1][y - 1] != robot &&
            grille[x][y + 1] != robot && grille[x][y - 1] != robot) { // Condition pour vérifier qu'il n'y a pas d'autres                 robots à côté.

            grille[x][y] = robot; // robot positionnée

            tab_de_robots[robot - 21].posi_robot.x = x; // enregistrement des coordonnées du robot dans le tableau de robot
            tab_de_robots[robot - 21].posi_robot.y = y; // enregistrement des coordonnées du robot dans le tableau de robot

            robot++; // Augmentation du numéro du robot.
        }
        //printf("Robot %d placé en (%d, %d)\n", robot, x, y);
    }

    return grille;
}
