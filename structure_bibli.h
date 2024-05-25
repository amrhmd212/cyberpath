#ifndef STRUCTURE_BIBLI_H
#define STRUCTURE_BIBLI_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int x;
    int y;
} Position; // Structure de position qu'on va utiliser dans les autres structures

typedef struct {
    Position posi_cible;
    int num;
    int num_cible;
} Cible; // Structure cible qui contient la position

typedef struct {
    Position posi_robot;
    int num_robot;
} Robot; // Structure robot qui contient la position

typedef struct{
  int num_joueur;
  int nombre_coup;
  int nombre_point;
} Joueur;
// Prototypes de fonctions pour structure&bibli.c
int verif_para_L_l(int longueur, int largeur);
int verif_para_grille(int** grille);
int verif_para_tab_de_cible(Cible* T);
int verif_para_tab_de_robot(Robot* T);
void verif_coordonnees(int** grille, int longueur, int largeur, Robot* tab_de_robots, Cible* tab_de_cibles);
int verif_robot(Robot robot,Cible cible, int** grille, int x, int y);
int** placement_mur(int** grille, int longueur, int largeur);
int** placement_cible(int** grille, int longueur, int largeur, Cible* tab_de_cibles);
int** placement_robot(int** grille, int longueur, int largeur, Robot* tab_de_robots);
int nbr_ale();
Joueur* Mouvement(Robot robot,int** grille,int x, int y,Joueur petit,Robot autre_robot[],int taille,Cible autre_cible[],int taille2, int num_robot,Cible cible_attaque,Joueur tab_joueur[],int nombre_joueur);
Joueur* Tour(Joueur tab_joueur[],int nombre_joueur,Robot tab_de_robots[],int nombre_robot,Robot robot,int** grille,int x, int y,Robot autre_robot[],int taille,Cible autre_cible[],int taille2,int choix_robot,Cible cible_attaque);
Joueur* Jeux(Robot tab_de_robots[],int nombre_robot,int** grille,int x,int y,Robot autre_robot[],int taile,Cible autre_cible[],int taille2,Cible tab_de_cibles[],int nombre_cible, Joueur tab_joueur[],int nombre_joueur,int niveau);
int** allocation_grille(int longueur, int largeur);
void liberation_grille(int** grille, int longueur);
void affiche_grille(int** grille, int longueur, int largeur);
void affiche_grille_J(int** grille, int longueur, int largeur);
void affiche_grille_durant_10_secondes(int **grille, int longueur,int largeur);
void affiche_grille_durant_20_secondes(int **grille, int longueur,int largeur);
void affiche_grille_durant_40_secondes(int **grille, int longueur,int largeur);
void affiche_grille_durant_60_secondes(int **grille, int longueur,int largeur);
void niveau_de_difficulte(int **grille, int longueur,int largeur, int lvl);
void affichage_3d_banniere();
// Ajoutez d'autres prototypes de fonctions si nécessaire


#endif