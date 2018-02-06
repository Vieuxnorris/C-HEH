#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void carte_alea(int joueur[10][4][4],int nombre_joueur);
void Affichage_de_main(int joueur[10][4][4],int joueur_nombre);
int menu();

int main()
{
    int nombre_joueur,min=0,max=54,nombre_de_manches,choix_joueur,joueur_nombre;
    int validation = 0;
    int i,j,k;
    int joueur[10][4][4];
    int nombre_de_carte = 54;
    int time_machine = clock();

    srand(time(NULL));


    printf("Bienvenue dans notre programme \n\n");
    do
    {
        printf("combien de joueur avec vous (3 à 10) ? ");
        scanf("%d", &nombre_joueur);
        if(nombre_joueur >= 3 && nombre_joueur <= 10)
        {
            do
            {
                printf("combien de manches voulais vous jouez ? ");
                scanf("%d", &nombre_de_manches);
                validation = 1;
            }while(validation == 0);
        }
        system("cls");
    }while(validation == 0);

    for(i=1;i<=nombre_joueur;i++)
    {
        for(j=0;j<4;j++)
        {
            nombre_de_carte--;
            for(k=1;k<=4;k++)
            {

            }
        }
        printf("voici joueur %d votre nombre de carte %d \n", i, j);
    }
    printf("voici le nombre de cartes disponible : %d \n \n", nombre_de_carte);

    Sleep(5000);
    carte_alea(joueur,nombre_joueur);
    system("cls");
    do
    {
        choix_joueur = menu();

        switch(choix_joueur)
        {
        case 1:
            system("cls");
            printf("tu es quel joueur ? ");
            scanf("%d", &joueur_nombre);
            Affichage_de_main(joueur,joueur_nombre);
            Sleep(10000);
            system("cls");
            break;
        case 2:
            system("cls");
            printf("<----------------Nouvelle Pioche---------------->\n\n\n");
            carte_alea(joueur,nombre_joueur);
            Sleep(10000);
            break;
        case 3:
            system("cls");
            break;
        case 4:
            system("cls");
            regle();
            system("pause");
            system("cls");
            break;
        case 5:
            return 0;
            break;
        }
    }while(choix_joueur != 4);
}



void carte_alea(int joueur[10][4][4],int nombre_joueur)
{
    int i=0,j=0,k=0,valeur_carte,valeur_couleur;
    for(i=1;i<=nombre_joueur;i++)
    {
        for(j=1;j<=4;j++)
        {
            for(k=1;k<=1;k++)
            {
                valeur_carte = rand() % 15+1;
                joueur[i][k][j] = valeur_carte;
                valeur_couleur = rand() % 4+1;
                joueur[i][j][k] = valeur_couleur;
                printf("joueur : %d \t carte : %d \t couleur : %d \n", i, joueur[i][k][j], joueur[i][j][k]);
            }
        }
        printf("\n");
    }
}



void Affichage_de_main(int joueur[10][4][4],int joueur_nombre)
{
    int i,j,k,valeur_couleur;

    for(i=joueur_nombre;i<=joueur_nombre;i++)
    {
        for(j=1;j<=4;j++)
        {
            for(k=1;k<=1;k++)
            {
                printf("voici les cartes : %d \t couleur : %d \n",joueur[i][k][j] ,joueur[i][j][k]);
            }
        }
    }
}

void regle()
{
    printf("Ce jeu se joue avec un jeu de 54 cartes que l'on séparera en deux tas, au début de la première manche. \n");
    printf("Le jeu se déroule en plusieurs manches. Avant de jouer, les joueurs décident du nombre de manches à jouer. On peut en jouer autant que l'on veut, cela n'a pas d'importance. Les joueurs doivent former un cercle. On peut, aussi, décider de jouer autant de manches qu'il y a de cartes dans le « tas de merde ».");
    printf("Le but de chaque joueur étant d'avoir quatre cartes de valeurs identiques en main, le premier à jouer choisit une carte qu'il ne veut pas garder et la fait passer à son voisin de gauche ou de droite ou à celui qui à la dame de pique sans la montrer aux autres. À ce moment, le premier joueur a trois cartes et le deuxième en a cinq. À son tour, le deuxième joueur fait passer une carte à son voisin. Ainsi, on tourne en faisant passer les cartes.");
    printf("Lorsque l'un des joueurs a quatre cartes de même valeur (un roi, une dame, etc.) ou sauf à trois joueurs, 4 cartes du même signe (cœur, pique, trèfle ou carreau), il doit attendre que tout le monde ait quatre cartes en main. Une fois que c'est le cas, il doit poser sa main sur le « tas de merde » et tous les joueurs doivent l'imiter au plus vite. Le dernier à avoir posé sa main sur le « tas de merde » doit piocher une carte dans ce dernier et la poser devant lui, face visible. Il gagne autant de kilos de merde que la valeur indiquée par la carte.");
}

void Game(int joueur[10][4][4],int nombre_de_joueur, int nombre_de_manche)
{
    int i,j;
    int choix;
    do
    {
        do
        {
            do
            {
                i = rand() %nombre_de_joueur+1;
                printf("joueur %d à toi de commencer ! \n\n", i);
                switch(choix)
                {
                    if(nombre_de_manche == 1)
                    {
                        case 1:
                            printf("joueur %d dit : Dame de cœur ! À vous l'honneur ! Dame de pique, à vous la suite !");
                            break;
                    }
                case 2:
                    system("cls");
                    Affichage_de_main(joueur,nombre_de_joueur);
                    printf("tu as 4 cartes de même valeurs (oui ou non)? ");

                    break;
                case 3:
                    system("cls");
                    regle();
                    break;
                }
            }while(Winner);
        }while(GameFull);
    }while(End);
}

int menu()
{
    int choix;
    printf("<--------------------Menu-------------------->\n");
    printf("Press [1] pour afficher votre main\n");
    printf("Press [2] pour melanger le jeu\n");
    printf("Press [3] pour lancer (enfin) la partie ^^\n");
    printf("Press [4] pour les regles \n");
    printf("Press [5] pour quitter le jeu\n\n");
    printf("taper votre choix : ");
    scanf("%d", &choix);
    return choix;
}

int menu_2(int nombre_de_manche)
{
    int choix;
    printf("<----------------Choix----------------> \n");
    if(nombre_de_manche == 1)
    {
        printf("Press [1] pour crier 'Dame de cœur ! À vous l'honneur ! Dame de pique, à vous la suite !' \n");
    }
    printf("Press [2] pour verifier vos carte ;-) \n");
    printf("Press [3] pour relire les régles ! \n");
    printf("Press [4] pour jouer");
    printf("Press [5] pour savoir ton nombre de 'kilo de merde' ");
    printf("votre choix : ");
    scanf("%d", &choix);
}
