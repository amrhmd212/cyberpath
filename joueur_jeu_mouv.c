#include "structure_bibli.h"


Joueur* Mouvement(Robot robot,int** grille,int x, int y,Joueur petit,Robot autre_robot[],int taille,Cible autre_cible[],int     taille2, int num_robot,Cible cible_attaque,Joueur tab_joueur[],int nombre_joueur){ // Fonction mouvement qui va nous          permettre de faire bouger les robots
  int key;// variable defini pour l avancé du robot
  int res=11;// variable defini
  int r=0;// variable defini
  int i=1;// variable defini
  int ancienne_cible;// variable defini
  
    for(int p=1; p<=petit.nombre_coup;p++){
        affiche_grille_J(grille,x,y);
        //printf("\ntest2");
        do{
             printf("Veuillez jouer avec les touches suivantes : 8 = Haut  4 = Gauche  2 = Bas 6 = Droite \n"); //permet de                 choisir la direction du robot
             r=scanf(" %d",&key);
            while(getchar()!='\n');
             if(r!=1|| (key!=8 && key!=4 && key!=2 && key!=6)){// verification du scanf != de 1 car on y met que 1 argument
                 printf("Erreur de saisie\n");

        }

        
        }while(key!=8 && key!=4 && key!=2 && key!=6);// condition qui permet de redemander a l utilisateur de taperun des 4           chiffres si il s est trompé


      if(key==8){ //on monte vers le haut
          while(grille[robot.posi_robot.x-1][robot.posi_robot.y]!=1 && grille[robot.posi_robot.x-1]                                     [robot.posi_robot.y]!=autre_robot[0].num_robot && grille[robot.posi_robot.x-1]                                                [robot.posi_robot.y]!=autre_robot[1].num_robot && grille[robot.posi_robot.x-1]                                                [robot.posi_robot.y]!=autre_robot[2].num_robot){// Condition pour savoir si le joeur peut monter ou pas 

          //tant que on atteint pas une bordure ou un autre robot on avance

          grille[robot.posi_robot.x][robot.posi_robot.y]=90;// on met la case (x;y)= 90 (case ou se trouve le joueur) pour              pouvoir faire le tracer apres
          robot.posi_robot.x-=1;// x-1 car le robot monte
          
          grille[robot.posi_robot.x][robot.posi_robot.y]=21+num_robot;// affectation des nouvelles coordonnes du robot
          

              affiche_grille_J(grille,x,y);// Affiche la grille pour le joeur avec la nouvelle position du robot
          }
      }

     
      if(key==2){ //on descend vers le bas
          //tant que on atteint pas une bordure ou un autre robot on avance
          while(grille[robot.posi_robot.x + 1][robot.posi_robot.y] != 1 && grille[robot.posi_robot.x+1]                                 [robot.posi_robot.y]!=autre_robot[0].num_robot && grille[robot.posi_robot.x+1]                                                [robot.posi_robot.y]!=autre_robot[1].num_robot && grille[robot.posi_robot.x+1]                                                [robot.posi_robot.y]!=autre_robot[2].num_robot ){// Condition pour savoir si le joeur peut descendre ou pas 
          grille[robot.posi_robot.x][robot.posi_robot.y] = 90;// on met la case (x;y)= 90 (case ou se trouve le joueur) pour            pouvoir faire le tracer apres
          robot.posi_robot.x += 1;// x+1 car le robot descend
          // printf("Les nouvelles coordonnées sont %d-%d\n", robot.posi_robot.x, robot.posi_robot.y);

              grille[robot.posi_robot.x][robot.posi_robot.y] = 21+num_robot ;// affectation des nouvelles coordonnes du robot
              affiche_grille_J(grille, x, y);// Affiche la grille pour le joeur avec la nouvelle position du robot
          }
      }
     if(key==4){ //on va vers la gauche
        //tant que on atteint pas une bordure ou un autre robot on avance
        while(grille[robot.posi_robot.x][robot.posi_robot.y-1]!=1 && grille[robot.posi_robot.x][robot.posi_robot.y-                   1]!=autre_robot[0].num_robot && grille[robot.posi_robot.x][robot.posi_robot.y-1]!=autre_robot[1].num_robot &&                 grille[robot.posi_robot.x][robot.posi_robot.y-1]!=autre_robot[2].num_robot){// Condition pour savoir si le joeur peut         aller a gauche ou pas 
            grille[robot.posi_robot.x][robot.posi_robot.y] = 90;// on met la case (x;y)= 90 (case ou se trouve le joueur)                 pour pouvoir faire le tracer apres
            robot.posi_robot.y-=1;// y-1 car le robot va a gauche
            grille[robot.posi_robot.x][robot.posi_robot.y]=21+num_robot; // affectation des nouvelles coordonnes du robot
            affiche_grille_J(grille,x,y);// Affiche la grille pour le joeur avec la nouvelle position du robot
        }          
      }
     
     if(key==6){ //on va vers la droite
           //tant que on atteint pas une bordure ou un autre robot on avance

        while(grille[robot.posi_robot.x][robot.posi_robot.y+1]!=1 && grille[robot.posi_robot.x]                                       [robot.posi_robot.y+1]!=autre_robot[0].num_robot && grille[robot.posi_robot.x]                                                [robot.posi_robot.y+1]!=autre_robot[1].num_robot && grille[robot.posi_robot.x]                                                [robot.posi_robot.y+1]!=autre_robot[2].num_robot){// Condition pour savoir si le joeur peut aller a droite ou pas 
        grille[robot.posi_robot.x][robot.posi_robot.y] = 90;// on met la case (x;y)= 90 (case ou se trouve le joueur) pour            pouvoir faire le tracer apres
        robot.posi_robot.y+=1;// y-1 car le robot va a droite
        grille[robot.posi_robot.x][robot.posi_robot.y]=21+num_robot;// affectation des nouvelles coordonnes du robot
        affiche_grille_J(grille,x,y);// Affiche la grille pour le joeur avec la nouvelle position du robot
        }
     }
    if(verif_robot(robot,cible_attaque,grille,x,y)==1){
        printf("Vous avez atteint la cible\n");
        if(p==petit.nombre_coup){
            printf("Vous venez de gagné cette manche et donc un point !\n");
            int z=petit.num_joueur;
            petit.nombre_point+=2;
            tab_joueur[z-1]=petit;
             return tab_joueur;
        }
    }
     
    if(verif_robot(robot,cible_attaque,grille,x,y)==1 && p<petit.nombre_coup){
        printf("Vous avez atteint la cible trop rapidemant : -1 point\n");
        int z=petit.num_joueur;
        petit.nombre_point-=1;
        tab_joueur[z-1]=petit;
        return tab_joueur;
    }
     
    if(verif_robot(robot,cible_attaque,grille,x,y)==0 && p==petit.nombre_coup){
        printf("Vous venez de perdre cette manche :( car vous avez pas atteint la cible\n");
        for(int z=0;z<nombre_joueur;z++){
            if(tab_joueur[z].num_joueur!=petit.num_joueur){
            tab_joueur[z].nombre_point+=1;
            }
        }
        return tab_joueur;
    }
}
return tab_joueur;
}

Joueur* Tour(Joueur tab_joueur[],int nombre_joueur,Robot tab_de_robots[],int nombre_robot,Robot robot,int** grille,int x, int     y,Robot autre_robot[],int taille,Cible autre_cible[],int taille2,int choix_robot,Cible cible_attaque){
  int r=0;
  int k=0;
  Joueur plus_petit;//initialisation de la variable permettant de placer le joueur le plus petit

    for(int i=0;i<nombre_joueur;i++){
        do{
            printf("Joueur n°%d : en combien de coups pensez-vous atteindre la cible : ",i+1); //demande du nombre de coup
            r=scanf("%d",&tab_joueur[i].nombre_coup);  //verif scanf
            while(getchar()!='\n');
            if(r!=1 ||tab_joueur[i].nombre_coup<1){
                printf("erreur saisie nbr de mouvements\n");
              
            }
        } while(r!=1 || tab_joueur[i].nombre_coup<1);//boucle pour avoir au minimum un coup
    }
    
    for(int w=1;w<nombre_joueur;w++){//boucle pour trouver le plus petit nombre de coup 
        if(tab_joueur[k].nombre_coup > tab_joueur[w].nombre_coup){
            k=w;
        }
    }
    
    printf("C'est au joueur %d de jouer avec %d nombre de coups\n",tab_joueur[k].num_joueur,tab_joueur[k].nombre_coup);
    //affichage du joueur qui doit jouer avec le nombre de coups
    tab_joueur = Mouvement(robot,grille,x,y,tab_joueur[k],autre_robot,taille,autre_cible,taille2,choix_robot,cible_attaque,
                 tab_joueur,nombre_joueur);//appel de la fonction mouvement et mise a jour du tableau de joueur                                                                                                                                  
    return tab_joueur;//retour du tableau de joueur pour être mis à jour
}
    
    
    Joueur* Jeux(Robot tab_de_robots[],int nombre_robot,int** grille,int x,int y,Robot autre_robot[],int taile,Cible              autre_cible[],int taille2,Cible tab_de_cibles[],int nombre_cible, Joueur tab_joueur[],int nombre_joueur,int niveau){// Fonction jeu qui permet de jouer le jeu
    
    int choix_robot=rand()%4;//choix aléatoire du robot
    int choix_cible=rand()%18;//choix aléatoire de la cible
    
    int loop=0;
    int loop2=0;
        
    for(int i=0; i<18;i++){
        tab_de_cibles[i].num_cible=2+i;
    }
    
    for(int i=0; i<4;i++){
        tab_de_robots[i].num_robot=21+i;
    }
        
    for(int i=0;i<4;i++){
        if(i!=choix_robot){
        autre_robot[loop]=tab_de_robots[i];
        loop++;
        }
    }
        
    for(int i=0;i<18;i++){
        if(i!=choix_cible){
            autre_cible[loop]=tab_de_cibles[i];
            loop2++;
        }
    }
    
    //affichage pour l'utilisateur du robot et de la cible tiré pour cette partie 
    if(choix_robot==0){        
        printf("Le robot choisi est le robot 🙉 et la cible à atteindre est la cible n°%d\n\n",choix_cible+1);
    }
    if(choix_robot==1){
        printf("Le robot choisi est le robot 🐼 et la cible à atteindre est la cible n°%d\n\n",choix_cible+1);
    }
    if(choix_robot==2){
        printf("Le robot choisi est le robot 🐷 et la cible à atteindre est la cible n°%d\n\n",choix_cible+1);
    }
    if(choix_robot==3){
        printf("Le robot choisi est le robot 🐊 et la cible à atteindre est la cible n°%d\n\n",choix_cible+1);
    }
    sleep(5);//pause de 5 secondes pour que l'utilisateur puisse voir les choix
    niveau_de_difficulte(grille,x,y,niveau);//appel de la fonction pour choisir le niveau de difficulté et donc du temps de       pause 
    
     // Joueur tab_joueur[nombre_joueur];
    
                                                                                                                                  tab_joueur=Tour(tab_joueur,nombre_joueur,tab_de_robots,nombre_robot,tab_de_robots[choix_robot],grille,x,y,autre_robot,        taile,autre_cible,taille2,choix_robot,tab_de_cibles[choix_cible]);    //appel de la fonction Tour qui actualise le            tableau de joueur
    
    return tab_joueur;//renvoie du tableau de joueur pour être actualisé
}
