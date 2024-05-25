#include "structure_bibli.h"


int main(){ // Fonction principale
    int r1=0;// variable+initialisation pour les verif
    int r2=0;// variable+initialisation pour les verif
    int r3=0;// variable+initialisation pour les verif
    int niveau=0;// variable+initialisation pour le niveau de difficulté
    Joueur* tab_joueur=NULL;//initialisation du pointeur
    int nombre_manche=0;// variable+initialisation pour le nombre de manche

    int nombre_joueur=0;// variable+initialisation pour le nombre de joueur

    affichage_3d_banniere();
    sleep(7);
    system("clear");
    
    do{
        printf("Combien y'a t-il de joueur:");//demande du nombre de joueurs
        r1=scanf("%d",&nombre_joueur);
        while(getchar()!='\n');
        if(r1!=1|| (nombre_joueur<2 || nombre_joueur>20)){//verif scanf
          printf("erreur de choix nombre de joueur\n");
          
        }
    }while(r1!=1 || (nombre_joueur<2 || nombre_joueur>20));//boucle pour avoir au minimum 2 joueurs et au maximum 20

    tab_joueur=malloc(nombre_joueur*sizeof(Joueur)); //allocation du tableau de joueur
        if(tab_joueur==NULL){// verif malloc
             printf("erreur malloc tab joueur\n");
            exit(212212);
        }

    for(int i=0;i<nombre_joueur;i++){
        tab_joueur[i].num_joueur=i+1;//initilisation du numéro de joueur
        printf("Le joueur %d à %d points\n",tab_joueur[i].num_joueur,tab_joueur[i].nombre_point); //affichage point joueur
        tab_joueur[i].nombre_point=0;// initialisation point des joueurs 
    }


    do{ 
        printf("Combien de manche voulez-vous jouer:");
        r2=scanf("%d",&nombre_manche);
        while(getchar()!='\n');
        if(r2!=1|| (nombre_manche<1 || nombre_manche>20)){//verification scanf
            printf("erreur de choix nombre de manche\n");
        
        }
    }while(r2!=1 || (nombre_manche<1 || nombre_manche>20)); //boucle pour avoir au minimum 1 manche ou maximum 20 manches;

    do{
        printf("Quel est le niveau de difficulte ? 1 = Facile 2 = Intermédiaire 3 = Difficile 4 = Extreme : ");
        r3=scanf("%d",&niveau);
        while(getchar()!='\n');
        if(r3!=1|| (niveau<1 || niveau>4)){// verif scanf
            printf("erreur de choix niveau de difficulté\n");
            
        }
    }while(r3!=1 || (niveau<1 || niveau>4));//boucle pour avoir le niveau de difficulté entre 1 et 4

    printf("La partie va commencer\n");
    
    for(int m=0;m<nombre_manche;m++){//boucle pour effectuer le nombre de manche 
        int longueur = 0, largeur = 0; // Initialisation variable x et y de position.
        longueur = nbr_ale(); // Affection à la variable x
        largeur = nbr_ale(); // Affection à la variable y
        int** grille = allocation_grille(longueur, largeur); // Appel fonction allocation_grille pour allouer le stockage du          tableau 2D

        // printf("\n"); // Retour à la ligne pour espacer tab

        //affiche_grille(grille, longueur, largeur); // Appel procédure affiche_grille pour voir la grille

        grille = placement_mur(grille, longueur, largeur); // Appel fonction placement_mur pour placer les murs. On met               grille = placement_mur car cette fonction retourne l'adresse d'un tableau.

        // printf("\n"); // Retour à la ligne pour espacer tab

        //affiche_grille(grille, longueur, largeur); // Appel procédure affiche_grille pour voir la grille

        Cible tab_de_cibles[18]; // Création d'un tableau de type cible avec 18 cases.

        grille = placement_cible(grille, longueur, largeur, tab_de_cibles); // Appel fonction placement_cible pour placer les         cibles. On met grille = placement_cible car cette fonction retourne l'adresse d'un tableau.
    
        //printf("\n"); // Retour à la ligne pour espacer tab
    
        //affiche_grille(grille, longueur, largeur); // Appel procédure affiche_grille pour voir la grille
    
        Robot tab_de_robots[4]; // Création d'un tableau de type Robot avec 4 cases.
    
        grille = placement_robot(grille, longueur, largeur, tab_de_robots); // Appel fonction placement_robot pour placer les         robots. On met grille = placement_robot car cette fonction retourne l'adresse d'un tableau.
    
        //printf("\n"); // Retour à la ligne pour espacer tab
    
        //affiche_grille(grille, longueur, largeur); // Appel procédure affiche_grille pour voir la grille du codeur
    
        // printf("\n"); // Retour à la ligne pour espacer tab
        //verif_coordonnees(grille, longueur, largeur, tab_de_robots, tab_de_cibles); // Appel procédure de vérification des          coordonnées
    
    
        int nombre_coup=0;// variable+initialisation pour le nombre de coup
    
        int r=0;
        for(int i=0; i<4;i++){//initilisation du numéro de chaque robot
           tab_de_robots[i].num_robot=21+i;
        }
        
        for(int i=0;i<18;i++){//initilisation du numéro de chaque cible
            tab_de_cibles[i].num_cible=i+2;
        }
    
        Robot  autre_robot[3];//initialisation du tableau nombre d'autre robot qui n'ont pas été séléctionnés
        Cible  autre_cible[17];//initialisation du tableau nombre d'autre cible qui n'ont pas été séléctionnéés
    
    
         printf("Manche %d commence \n",m+1);     //affichage pour le joueur du début d'une manche
    
        tab_joueur=Jeux(tab_de_robots,4,grille,longueur,largeur,autre_robot,3,autre_cible,17,tab_de_cibles,18,tab_joueur,
        nombre_joueur,niveau);//appel de la fonction jeux
        
        for(int i=0;i<nombre_joueur;i++){
                printf("Le joueur %d à %d points\n",tab_joueur[i].num_joueur,tab_joueur[i].nombre_point);//affichage du                       nombre de points
        }
    
    
    
        sleep(5);//attente de 5 seconde avant de recommencer une nouvelle manche
        liberation_grille(grille, longueur); // Libération de l'espace alloué.
    
    }
    
    printf("Fin de la partie les scores sont :\n");           //affichage de fin de partie
    
    for(int i=0;i<nombre_joueur;i++){
        printf("\nLe joueur %d à %d points\n",tab_joueur[i].num_joueur,tab_joueur[i].nombre_point); //affichage final des             scores
    }

    return 0;
}
