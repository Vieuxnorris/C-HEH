#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

int main()
{
    int joueur=0;
    int choix;
    int nombre_de_manche=0;
    int joueur_actuelle;
    int deck[13][4];

    srand(time(NULL));

    printf("Bienvenue sur le jeu de cartes 'Le Tas de Merde' \n\n");

    do
    {
        printf("A combien voulez-vous jouer (Trois minimum, dix maximum) ? \n");
        scanf("%d", &joueur);
        fflush(stdin);
        system("cls");
    }while(joueur < 3 || joueur > 10);

    printf("En combien de manches voulez-vous jouer ? ");
    scanf("%d", &nombre_de_manche);

    melange(deck,joueur);

    do
    {
        choix = menu();

        switch(choix)
        {
        case 1:
            system("cls");
            printf("Quel joueur es-tu ? ");
            scanf("%d", &joueur_actuelle);
            fflush(stdin);
            affichage(deck,joueur,joueur_actuelle);
            break;
        case 2:
            system("cls");
            break;
        case 3:
            system("cls");
            regle();
            break;
        case 4:
            return 0;
            break;
        }
    }while(choix != 4);
}

void melange(int deck[13][4],int joueur)
{
    int i,j;
    int Sans_Double[13][4] = {0};
    int clone_couleur[13][4];
    int valeur_aleatoire_a = 0;
    int valeur_aleatoire_b = 0;
    int carte = 10;
    int random_carte = 3;

    for(i=3;i<joueur;i++)
    {
        carte--;
        random_carte++;
    }

    for(i=0;i<carte;i++)
    {
        for(j=0;j<4;j++)
        {
            do
            {
                valeur_aleatoire_a = rand() %(13-random_carte)+random_carte;
                valeur_aleatoire_b = rand() % 4;
            }while(Sans_Double[valeur_aleatoire_a][valeur_aleatoire_b] != 0);
            Sans_Double[valeur_aleatoire_a][valeur_aleatoire_b] = 1;
            deck[i][j] = valeur_aleatoire_a;
            clone_couleur[i][j] = valeur_aleatoire_b;
        }
    }
}

void affichage(int deck[13][4], int joueur,int joueur_actuelle)
{
    int i,j,k,q;
    int carte = 3;
    int clone_couleur[13][4];
    int random_carte = 3;
    int Sans_Double[13][4] = {0};
    int clone_deck[13][4];
    int valeur_aleatoire_a=0;
    int valeur_aleatoire_b=0;

    for(k=3;k<joueur;k++)
    {
        carte++;
        random_carte++;
    }

    for(i=0;i<carte;i++)
    {
        for(j=0;j<4;j++)
        {
            do
            {
                valeur_aleatoire_a = rand() % random_carte;
                valeur_aleatoire_b = rand() % 4;
            }while(Sans_Double[valeur_aleatoire_a][valeur_aleatoire_b] != 0);
            Sans_Double[valeur_aleatoire_a][valeur_aleatoire_b] = 1;
            clone_deck[i][j] = valeur_aleatoire_a;
            clone_couleur[i][j] = valeur_aleatoire_b;
        }
    }
    for(i=joueur_actuelle;i<=joueur_actuelle;i++)
    {
        printf("joueur %d \n", joueur_actuelle);
        for(j=0;j<4;j++)
        {
            printf("carte : %d \t couleur : %d \n", clone_deck[i][j],clone_couleur[i][j]);
        }
    }
}

int menu() //Changement ecriture printf
{
    int choix;
    printf("<--------------------Menu-------------------->\n");
    printf("Appuyez sur [1] pour afficher les mains\n");
    printf("Appuyez sur [2] pour refaire un melange\n");
    printf("Appuyez sur [2] pour debuter la partie \n");
    printf("Appuyez sur [3] pour afficher les regles \n");
    printf("Appuyez sur [4] pour quitter le jeu\n\n");
    printf("Que souhaitez-vous faire ? : ");
    scanf("%d", &choix);
    fflush(stdin);
    return choix;
}

void regle() //Correction lecture regles + "titre"
{
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("***********************************REGLES*************************************");
    SetConsoleTextAttribute(console, 6);
    printf("Chaque joueur a en sa possession quatre cartes en debut de manche. \nLe joueur qui debute la partie est celui qui a la dame de coeur. \n\n");
    printf("Ce joueur commence en donnant l'une de ses quatre cartes au joueur qui \nse trouve sur sa droite. N'oubliez pas, le but du jeu est d'avoir \nentre vos mains quatre cartes identiques,\ncest-a-dire avec le meme nombre ou tete ou quatre cartes \navec la meme couleur (coeur, pique, carreau, trefle). \n\n");
    printf("Le second joueur effectue la meme action \navec le joueur qui se trouve a sa droite et ainsi de suite. \n\n");
    printf("Lorsqu'un joueur reussit a recuperer quatre cartes identiques, il peut alors \ntaper le tas de cartes qui se trouve au milieu de la table. \nLes autres joueurs doivent faire la meme chose le plus rapidement possible. \nle dernier a taper le tas a perdu la partie. Il doit alors piocher une carte du tas, le nombre indique sur la carte correspond au kilo de merde qu'il recupere. \n\n");
    SetConsoleTextAttribute(console, 12);
    printf("ATTENTION : Le joueur qui a quatre cartes identiques doit attendre que tous les joueurs aient quatre cartes en main pour taper le tas. \n\n");
    printf("Un joueur peut tromper ses adversaires en faisant semblant de taper le tas \nalors qu'il ne possede pas quatre cartes identiques. \nSi un joueur se fait avoir, et tape le tas, il doit alors piocher une carte. \n\n");
    SetConsoleTextAttribute(console, 9);
    printf("LA CHASSE D'EAU : Si un des joueurs pioche une carte avec le nombre 7, \nil pioche la chasse d'eau. Il a alors la chance de \npouvoir remettre toutes les cartes piochees, ses kilos de merde, sous le tas.\n");
    printf("La partie continue jusqu'a ce que les joueurs aient atteint le nombre de manche defini au depart.\n\n");
    SetConsoleTextAttribute(console, 7);
}
