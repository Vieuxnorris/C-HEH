#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void carte_alea(int joueur[10][5],int color[10][5],int nombre_joueur);
void Affichage_de_main(int joueur[10][5],int color[10][5],int joueur_nombre);
void pioche(int joueur[10][5],int color[10][5], int nombre_de_joueur,int votre_carte,int nombre_de_carte,int joueur_de_droite);
int menu();

int main()
{
    int nombre_joueur,min=0,max=52,nombre_de_manches,choix_joueur,joueur_nombre;
    int validation = 0;
    int i,j;
    int joueur[10][5];
    int color[10][5];
    int deck_carte[52][52];
    int deck_color[52][5];
    int nombre_de_carte = 52;
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
            deck_carte[nombre_de_carte][nombre_de_carte];
        }
        printf("voici joueur %d votre nombre de carte %d \n", i, j);
    }
    printf("voici le nombre de cartes disponible : %d \n \n", nombre_de_carte);

    Sleep(5000);
    carte_alea(joueur,color,nombre_joueur);
    system("cls");
    do
    {
        choix_joueur = menu();

        switch(choix_joueur)
        {
        case 1:
            system("cls");
            do
            {
                printf("tu es quel joueur ? ");
                scanf("%d", &joueur_nombre);
            }while(joueur_nombre <= nombre_joueur-nombre_joueur || joueur_nombre > nombre_joueur);
            Affichage_de_main(joueur,color,joueur_nombre);
            Sleep(5000);
            system("cls");
            break;
        case 2:
            system("cls");
            printf("<----------------Nouvelle Pioche---------------->\n\n\n");
            carte_alea(joueur,color,nombre_joueur);
            Sleep(10000);
            break;
        case 3:
            system("cls");
            Game(joueur,color,nombre_joueur,nombre_de_manches,nombre_de_carte,joueur_nombre);
            choix_joueur = 5;
            break;
        case 4:
            system("cls");
            regle();
            break;
        case 5:
            return 0;
            break;
        }
    }while(choix_joueur != 5);
}

void Affichage_du_deck(int deck_carte[52][52], int deck_color[52][5])
{
    int i,j;
    for(i=0;i<=52;i++)
    {
        for(j=0;j<=52;j++)
        {
            printf("voici les cartes : %d \t", deck_carte[i][j]);
        }
        printf("\n");
        for(j=0;j<=5;j++)
        {
            printf("couleur : %d", deck_color[i][j]);
        }
        printf("\n\n");
    }
}

void deck(int deck_carte[52][52], int deck_color[52][5])
{
    int i,j,valeur_carte,valeur_color;
    srand(time(NULL));
    for(i=1;i<=52;i++)
    {
        for(j=1;j<=52;j++)
        {
            valeur_carte = rand() %15+1;
            deck_carte[i][j] = valeur_carte;
            printf("carte deck : %d \t", deck_carte[i][j]);
        }
        printf("\n");
        for(j=1;j<=5;j++)
        {
            valeur_color = rand() %4+1;
            deck_color[i][j] = valeur_color;
            printf("couleur deck : %d \t",deck_color[i][j]);
        }
        printf("\n\n");
    }
}

void carte_alea(int joueur[10][5],int color[10][5],int nombre_joueur)
{
    int i=0,j=0,valeur_carte=0,valeur_couleur=0,valeur_max=0,valeur_min=0,p=2;
    if(nombre_joueur == 3)
    {
        valeur_max = 14;
        valeur_min = 13-p;
    }
    else
    {
        for(i=3;i<=10;i++)
        {
            p++;
        }
        valeur_max = 14;
        valeur_min = 13-p;
    }

    for(i=1;i<=nombre_joueur;i++)
    {
        for(j=1;j<=4;j++)
        {
            valeur_carte = rand() %(valeur_max-valeur_min) + valeur_min;
            joueur[i][j] = valeur_carte;
            printf("carte : %d \t", joueur[i][j]);
        }
        printf("\n");
        for(j=1;j<=4;j++)
        {
            valeur_couleur = rand() % (4-1) + 1;
            color[i][j] = valeur_couleur;
            printf("couleur : %d \t", color[i][j]);
        }
        printf("\n\n");
    }
}



void Affichage_de_main(int joueur[10][5],int color[10][5],int joueur_nombre)
{
    int i=0,j=0,valeur_couleur;

    for(i=joueur_nombre;i<=joueur_nombre;i++)
    {
        for(j=1;j<=4;j++)
        {
            printf("carte : %d \t", joueur[i][j]);
        }
        printf("\n");
        for(j=1;j<=4;j++)
        {
            printf("couleur : %d \t", color[i][j]);
        }
        printf("\n\n");
    }
}

void regle()
{
    printf("Ce jeu se joue avec un jeu de 54 cartes que l'on séparera en deux tas, au début de la première manche. \n");
    printf("Le jeu se déroule en plusieurs manches. Avant de jouer, les joueurs décident du nombre de manches à jouer. On peut en jouer autant que l'on veut, cela n'a pas d'importance. Les joueurs doivent former un cercle. On peut, aussi, décider de jouer autant de manches qu'il y a de cartes dans le « tas de merde ».");
    printf("Le but de chaque joueur étant d'avoir quatre cartes de valeurs identiques en main, le premier à jouer choisit une carte qu'il ne veut pas garder et la fait passer à son voisin de gauche ou de droite ou à celui qui à la dame de pique sans la montrer aux autres. À ce moment, le premier joueur a trois cartes et le deuxième en a cinq. À son tour, le deuxième joueur fait passer une carte à son voisin. Ainsi, on tourne en faisant passer les cartes.");
    printf("Lorsque l'un des joueurs a quatre cartes de même valeur (un roi, une dame, etc.) ou sauf à trois joueurs, 4 cartes du même signe (cœur, pique, trèfle ou carreau), il doit attendre que tout le monde ait quatre cartes en main. Une fois que c'est le cas, il doit poser sa main sur le « tas de merde » et tous les joueurs doivent l'imiter au plus vite. Le dernier à avoir posé sa main sur le « tas de merde » doit piocher une carte dans ce dernier et la poser devant lui, face visible. Il gagne autant de kilos de merde que la valeur indiquée par la carte. \n\n");
}

int verification_first_time(int joueur[10][5], int nombre_de_joueur)
{
    int i,j;
    for(i=1;i<=nombre_de_joueur;i++)
    {
        for(j=1;j<=4;j++)
        {
            if(joueur[i][j] == 12)
            {
                return i;
            }
        }
    }
}

void Game(int joueur[10][5],int color[10][5],int nombre_de_joueur, int nombre_de_manche,int nombre_de_carte, int deck_color[52][5],int deck_carte[52][52],int joueur_nombre)
{
    int i,j,k,temp=1,score=0;
    int manche=0, votre_carte=0;
    int Winner=1,GameFull=1,End=1;
    do
    {
        End = 1;
        do
        {
            GameFull = 1;
            do
            {
                Winner = 1;
                if(manche == 0)
                {
                    i = verification_first_time(joueur,nombre_de_joueur);
                    printf("joueur %d à toi de commencer ! \n\n", i);
                }
                int choix=0;
                choix = menu_2(manche,joueur,color,nombre_de_joueur,temp);
                switch(choix)
                {
                    if(manche == 0)
                    {
                        case 1:
                            system("cls");
                            printf("joueur %d dit : Dame de cœur ! À vous l'honneur ! Dame de pique, à vous la suite ! \n\n\n",temp);
                            manche++;
                            break;
                    }
                case 2:
                    system("cls");
                    printf("joueur %d \n",temp);
                    Affichage_de_main(joueur,color,temp);
                    manche++;
                    break;
                case 3:
                    system("cls");
                    printf("joueur %d \n",temp);
                    regle();
                    manche++;
                    break;
                case 4:
                    system("cls");
                    printf("joueur %d \n",temp);
                    Affichage_de_main(joueur,color,temp);
                    system("cls");
                    pioche(joueur,color,nombre_de_joueur,votre_carte,nombre_de_carte,temp);
                    if(nombre_de_carte == 0 || manche >= nombre_de_manche)
                    {
                        printf("arret de la partie.");
                        Winner = 0;
                    }
                    temp++;
                    if(temp > nombre_de_joueur)
                    {
                        temp = 1;
                        manche++;
                    }
                    break;
                case 5:
                    system("cls");
                    printf("joueur %d \n",temp);
                    score = compteur_de_score(joueur,color,nombre_de_joueur,temp);
                    printf("voici votre score : %d \n\n", score);
                    if(temp > nombre_de_joueur)
                    {
                        temp = 1;
                        manche++;
                    }
                    break;
                case 6:
                    system("cls");
                    printf("joueur %d \n",temp);
                    temp++;
                    if(temp > nombre_de_joueur)
                    {
                        temp = 1;
                        manche++;
                    }
                    break;
                case 7:
                    system("cls");
                    Winner = 0;
                    break;
                }
            }while(Winner == 1);
            system("cls");
            printf("tu veux refaire une partie (1 ou 0) ?");
            scanf("%d", &GameFull);
            manche = 1;
        }while(GameFull == 1);
        printf("tu es vraiment sûr (1 ou 0) ?");
        scanf("%d", &End);
        manche = 1;
    }while(End == 1);
    printf("Merci beaucoup d'avoir test notre programme :-) \n");
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

int menu_2(int manche, int joueur[10][5], int color[10][5], int nombre_de_joueur, int votre_joueur)
{
    int choix,winner;
    printf("<----------------Choix----------------> \n");
    if(manche == 0)
    {
        printf("Press [1] pour crier 'Dame de cœur ! À vous l'honneur ! Dame de pique, à vous la suite !' \n");
        printf("Press [7] pour quitter la partie\n");
    }
    else
    {
        printf("Press [2] pour verifier vos carte ;-) \n");
        printf("Press [3] pour relire les régles ! \n");
        printf("Press [4] pour jouer\n");
        printf("Press [5] pour savoir ton nombre de 'kilo de merde'\n");
        printf("Press [6] pour passer votre tour\n");
        printf("Press [7] pour quitter la partie\n");
    }
    printf("%d \n", win(joueur,color,nombre_de_joueur,votre_joueur));
    if(win(joueur,color,nombre_de_joueur,votre_joueur) == 4)
    {
        printf("Press [8] pour Time to win !!!!\n");
    }
    printf("votre choix : ");
    scanf("%d", &choix);
    return choix;
}

void pioche(int joueur[10][5],int color[10][5], int nombre_de_joueur,int votre_carte,int nombre_de_carte,int joueur_de_droite)
{
    int i,j,valeur_test,swap;
    Affichage_de_main(joueur,color,joueur_de_droite);
    printf("qu'elle est la carte que vous voulez changer (1,2,3,4) : ");
    scanf("%d", &votre_carte);
    if(joueur_de_droite+1 > nombre_de_joueur)
    {
        joueur_de_droite = 1;
    }
    printf("qu'elle carte du joueur %d voulez-vous echanger (1,2,3,4) ?",joueur_de_droite+1);
    scanf("%d", &valeur_test);
    for(i=1;i<=nombre_de_joueur;i++)
    {
        for(j=1;j<=1;j++)
        {
            swap = joueur[joueur_de_droite][votre_carte];
            joueur[joueur_de_droite][votre_carte] = joueur[joueur_de_droite+1][valeur_test];
            joueur[joueur_de_droite+1][valeur_test] = swap;
        }
        for(j=1;j<=1;j++)
        {
            swap = color[joueur_de_droite][votre_carte];
            color[joueur_de_droite][votre_carte] = color[joueur_de_droite+1][valeur_test];
            color[joueur_de_droite+1][valeur_test] = swap;
        }
    }
}

int compteur_de_score(int joueur[10][5], int color[10][5], int nombre_joueur,int ton_joueur)
{
    int i,j,score=0;
    for(i=ton_joueur;i<=ton_joueur;i++)
    {
        for(j=1;j<=4;j++)
        {
            if(joueur[i][j] == 7)
            {
                score += 5;
            }
            else if(joueur[i][j] == 11)
            {
                score += 11;
            }
            else if(joueur[i][j] == 12)
            {
                score += 12;
            }
            else if(joueur[i][j] == 13)
            {
                score += 13;
            }
            else if(joueur[i][j] == 14)
            {
                score += 100;
            }
        }
        return score;
    }
}


int win(int joueur[10][5], int color[10][5],int nombre_de_joueur, int votre_joueur)
{
    int i,j,compteur=0,valeur_enregistrer;

    for(i=votre_joueur;i<=votre_joueur;i++)
    {
        for(j=1;j<=4;j++)
        {
            if(joueur[i][1] == joueur[i][j])
            {
                compteur++;
            }
        }
        return compteur;
    }
}
