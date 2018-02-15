#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

int menu();

int main()
{
    int joueur=0;
    char* tableaux_graphique_carte[] = {"As","Deux","Trois","Quatre","Cinq","Six","sept","Huit","Neuf","Dix","Valet","Dame","Roi"};
    char* tableaux_graphique_couleur[] = {"Pique","Coeur","Carreau","Trefle"};
    int joueur_carte=4;
    int choix;
    int nombre_de_manche=0;
    int valeur_couleur=0;
    int deck_carte[52];
    int deck_couleur[52];

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

    system("cls");
    melange_deck(deck_carte,deck_couleur,valeur_couleur);
    system("cls");
    melange_joueur(deck_carte,deck_couleur,valeur_couleur,joueur);

    do
    {
        choix = menu();

        switch(choix)
        {
        case 1:
            system("cls");
            affichage_les_mains(deck_carte,deck_couleur,valeur_couleur,joueur);
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

void affichage_les_mains(int deck_carte[52], int deck_couleur[52], int valeur_couleur,int joueur)
{
    int i,j,k,q;
    char* tableaux_graphique_carte[] = {"As","Deux","Trois","Quatre","Cinq","Six","sept","Huit","Neuf","Dix","Valet","Dame","Roi"};
    char* tableaux_graphique_couleur[] = {"Pique","Coeur","Carreau","Trefle"};
    int nombre_de_carte = 52;
    int nombre_dec = 48;

    for(i=0;i<joueur;i++)
    {
        printf("joueur %d \n", i+1);
        for(j=nombre_de_carte;j>nombre_dec;j--)
        {
            k = deck_carte[j];
            q = deck_couleur[j];
            printf("carte : %s \t couleur : %s \n", tableaux_graphique_carte[k],tableaux_graphique_couleur[q]);
        }
        printf("\n");
        nombre_de_carte = nombre_dec;
        nombre_dec -= 4;
    }
}

void melange_joueur(int deck_carte[52],int deck_couleur[52],int valeur_couleur,int joueur)
{
    int i,j;
    int valeur_carte=0;
    int sans_doublons[52][4] = {0};
    int joueur_nombre = 3;
    int nombre_de_carte = 12;
    int test_affichage_carte[52];
    int test_affichage_couleur[52];

    for(i=3;i<joueur;i++)
    {
        joueur_nombre++;
        nombre_de_carte += 4;
    }

    for(i=52-nombre_de_carte;i<52;i++)
    {
        do
        {
        valeur_carte = rand() % joueur_nombre;
        valeur_couleur = rand() % 4;
        }while(sans_doublons[valeur_carte][valeur_couleur] != 0);
        sans_doublons[valeur_carte][valeur_couleur] = 1;
        deck_carte[i] = valeur_carte;
        deck_couleur[i] = valeur_couleur;
    }
}

void melange_deck(int deck_carte[52],int deck_couleur[52],int valeur_couleur,int joueur)
{
    int i,j;
    int valeur_carte=0;
    int sans_doublons[52][4] = {0};
    int joueur_nombre = 4;
    int valeur_max = 13;
    int nombre_de_carte = 40;

    for(i=3;i<joueur;i++)
    {
        joueur_nombre++;
        nombre_de_carte -= 4;
    }

    for(i=0;i<nombre_de_carte;i++)
    {
        do
        {
            valeur_carte = rand() % (valeur_max-joueur_nombre)+joueur_nombre;
            valeur_couleur = rand() % 4;
        }while(sans_doublons[valeur_carte][valeur_couleur] != 0);
        sans_doublons[valeur_carte][valeur_couleur] = 1;
        deck_carte[i] = valeur_carte;
        deck_couleur[i] = valeur_couleur;
    }
}

int menu() //Changement ecriture printf
{
    int choix;
    printf("<--------------------Menu-------------------->\n");
    printf("Appuyez sur [1] pour afficher les mains\n");
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
