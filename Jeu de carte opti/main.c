#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

/*
*************************************************
Credit dev: Alessio Baio
            Carmelo Mirabile
            Jordan Desaive
            Julien Wins
*************************************************
*/

int main()
{
    int joueur=0;
    int choix;
    int nombre_de_manche=0;
    int joueur_actuelle=0;
    int deck[13][4];
    int deck_couleur[13][4];
    int fake_win[13] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4};
    int nombre_de_carte = 52;

    srand(time(NULL));

    printf("Bienvenue sur le jeu de cartes 'Le Tas de Merde' \n\n");

    do
    {
        printf("A combien voulez-vous jouer (Trois minimum, dix maximum) ? \n");
        scanf("%d", &joueur);
        fflush(stdin);
        system("cls");
    }while(joueur < 3 || joueur > 10);

    do
    {
        printf("En combien de manches voulez-vous jouer ? ");
        scanf("%d", &nombre_de_manche);
        fflush(stdin);
    }while(nombre_de_manche < 0 || nombre_de_manche > 999);

    melange(deck,deck_couleur,joueur);

    do
    {
        choix = menu();

        switch(choix)
        {
        case 1:
            system("cls");
            affichage(deck,deck_couleur,joueur,joueur_actuelle,fake_win,nombre_de_carte);
            break;
        case 2:
            system("cls");
            melange(deck,deck_couleur,joueur);
            break;
        case 3:
            system("cls");
            game(deck,deck_couleur,joueur,joueur_actuelle,nombre_de_manche,fake_win,nombre_de_carte);
            break;
        case 4:
            system("cls");
            regle();
            break;
        case 5:
            return 0;
            break;
        }
    }while(choix != 5);
}

void melange(int deck[13][4],int deck_couleur[13][4],int joueur)
{
    int i,j;
    int Sans_Double[13][4] = {0};
    int valeur_aleatoire_a = 0;
    int valeur_aleatoire_b = 0;
    int carte = 9;
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
            deck_couleur[i][j] = valeur_aleatoire_b;
        }
    }
    for(i=12;i>carte;i--)
    {
        for(j=0;j<4;j++)
        {
            do
            {
                valeur_aleatoire_a = rand() % random_carte;
                valeur_aleatoire_b = rand() % 4;
            }while(Sans_Double[valeur_aleatoire_a][valeur_aleatoire_b] != 0);
            Sans_Double[valeur_aleatoire_a][valeur_aleatoire_b] = 1;
            deck[i][j] = valeur_aleatoire_a;
            deck_couleur[i][j] = valeur_aleatoire_b;
        }
    }
}

void affichage(int deck[13][4],int deck_couleur[13][4], int joueur,int joueur_actu,int fake_win[13],int nombre_de_carte)
{
    int i,j;
    char* tableaux_graphique_carte[] = {"Roi","Dame","Valet","Deux","Trois","Quatre","Cinq","Six","Huit","Neuf","Sept","Dix","As"};
    char* tableaux_graphique_couleur[] = {"Pique","Coeur","Carreau","Trefle"};
    int carte=9;
    int joueur_actuelle=0;
    int compteur=0;
    int temp=0;

    joueur_actuelle = 12-joueur_actu;

    for(i=3;i<joueur;i++)
    {
        carte--;
        nombre_de_carte -= 4;
    }

    for(i=joueur_actuelle;i>=joueur_actuelle;i--)
    {
        for(j=0;j<fake_win[i];j++)
        {
            if(j > 3)
            {
                deck[i][j] = deck[i-joueur][-1+temp];
                temp++;
            }
            if(deck[i][j] == 7)
            {
                fake_win[i] = 4;
            }
            printf("carte : %s \t couleur : %s \n", tableaux_graphique_carte[deck[i][j]],tableaux_graphique_couleur[deck_couleur[i][j]]);
            if(deck[i][j] == deck[i][0] || deck_couleur[i][j] == deck_couleur[i][0])
            {
                compteur++;
                if(compteur == 4+temp)
                {
                    printf("félicitation tu as gagné joueur %d", i);
                    return 0;
                }
            }
        }
    }
}

int menu() //Changement ecriture printf
{
    int choix;
    printf("<--------------------Menu-------------------->\n");
    printf("Appuyez sur [1] pour afficher votre main\n");
    printf("Appuyez sur [2] pour refaire un melange\n");
    printf("Appuyez sur [3] pour lance le jeu\n");
    printf("Appuyez sur [4] pour afficher les regles \n");
    printf("Appuyez sur [5] pour quitter le jeu\n\n");
    printf("Que souhaitez-vous faire ? : ");
    scanf("%d", &choix);
    fflush(stdin);
    return choix;
}

void regle() //Correction lecture regles + "titre"
{
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("***********************************REGLES*************************************\n\n");
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
    system("pause");
    system("cls");
}

void echange(int deck[13][4],int deck_couleur[13][4],int joueur,int joueur_actu,int fake_win[13],int nombre_de_carte)
{
    int i,j,valeur_joueur=0,carte=9,swap,votre_carte,votre_test,valeur_joueur_max=0;

    affichage(deck,deck_couleur,joueur,joueur_actu,fake_win,nombre_de_carte);

    valeur_joueur = 12-joueur_actu;
    valeur_joueur_max = valeur_joueur-1;

    if(valeur_joueur_max == 12-joueur)
    {
        valeur_joueur_max = 12;
    }

    printf("entrer la carte : ");
    scanf("%d", &votre_carte);

    printf("entrer la carte : ");
    scanf("%d", &votre_test);

    for(i=1;i<=1;i++)
    {
        swap = deck[valeur_joueur][votre_carte];
        deck[valeur_joueur][votre_carte] = deck[valeur_joueur_max][votre_test];
        deck[valeur_joueur_max][votre_test] = swap;
    }
    for(i=1;i<=1;i++)
    {
        swap = deck_couleur[valeur_joueur][votre_carte];
        deck_couleur[valeur_joueur][votre_carte] = deck_couleur[valeur_joueur_max][votre_test];
        deck_couleur[valeur_joueur_max][votre_carte] = swap;
    }
}

int verification(int deck[13][4],int joueur_actu,int joueur)
{
    int i,j,valeur_joueur;

    valeur_joueur = 12-joueur;

    for(i=12;i>valeur_joueur;i--)
    {
        for(j=0;j<4;j++)
        {
            if(deck[i][j] == 1)
            {
                return i;
            }
        }
    }
}

void game(int deck[13][4],int deck_couleur[13][4],int joueur,int joueur_actu,int nombre_de_manche,int fake_win[13],int nombre_de_carte)
{
    int i,j,choix,manche=0,temp,fin=0,compteur=0,joueur_actuelle=0;
    do
    {
        choix = menu_game(manche,nombre_de_carte);

        if(manche == nombre_de_manche)
        {
            system("cls");
            for(i=0;i<joueur;i++)
            {
                kilo(deck,deck_couleur,joueur,i);
            }
        }
        switch(choix)
        {
            if(manche == 0)
                {
                case 1:
                    system("cls");
                    printf("joueur %d dit : 'Dame de coeur ! A vous l'honneur ! Dame de pique, a vous la suite !' \n\n\n",verification(deck,joueur_actu,joueur));
                    manche++;
                    break;
                }
        case 2:
            system("cls");
            affichage(deck,deck_couleur,joueur,joueur_actu,fake_win,nombre_de_carte);
            break;
        case 3:
            system("cls");
            regle();
            break;
        case 4:
            system("cls");
            echange(deck,deck_couleur,joueur,joueur_actu,fake_win,nombre_de_carte);
            joueur_actu++;
            if(joueur_actu > joueur-1)
            {
                joueur_actu=0;
                manche++;
            }
            break;
        case 5:
            system("cls");
            temp = kilo(deck,deck_couleur,joueur,joueur_actu,fake_win);
            printf("voici votre score : %d \n\n", temp);
            break;
        case 6:
            system("cls");
            joueur_actu++;
            if(joueur_actu > joueur-1)
            {
                joueur_actu=0;
                manche++;
            }
            break;
        case 7:
            system("cls");
            compteur++;
            joueur_actuelle = 12-joueur_actu;
            if(compteur==2)
            {
                nombre_de_carte--;
                compteur=0;
                for(i=joueur_actuelle;i<=joueur_actuelle;i++)
                {
                    fake_win[i] += 1;
                }

            }
            joueur_actu++;
            if(joueur_actu > joueur-1)
            {
                joueur_actu=0;
                manche++;
            }
            break;
        case 8:
            system("cls");
            break;
        }
    }while(choix != 8);
}

int menu_game(int manche,int nombre_de_carte)
{
    int choix;
    printf("<----------------Choix----------------> \n");
    if(manche == 0)
    {
        printf("Appuyez sur [1] pour crier 'Dame de coeur ! A vous l'honneur !\nDame de pique, a vous la suite !' \n\n");
        printf("Appuyez sur [8] pour quitter la partie.\n");
    }
    else
    {
        printf("Appuyez sur [2] pour verifier vos carte ainsi que les conditions de victoire\n");
        printf("Appuyez sur [3] pour relire les regles\n");
        printf("Appuyez sur [4] pour jouer\n");
        printf("Appuyez sur [5] pour connaitre ton nombre de kilos de merde\n");
        printf("Appuyez sur [6] pour passer votre tour\n");
        if(nombre_de_carte == 0)
        {
            printf("Appuyez sur [7] pour Fake Win\n");
        }
        printf("Appuyez sur [8] pour quitter la partie\n");
        printf("votre choix : ");
    }
    scanf("%d",&choix);
    return choix;
}

int kilo(int deck[13][4], int deck_couleur[13][4], int joueur, int joueur_actu,int fake_win[13])
{
    int i,j,joueur_actuelle,score=0;

    joueur_actuelle = 12-joueur_actu;

    for(i=joueur_actuelle;i<=joueur_actuelle;i++)
    {
        for(j=0;j<fake_win[i];j++)
        {
            if(deck[joueur_actuelle][j] == 1)
            {
                score += 12;
            }
            if(deck[joueur_actuelle][j] == 2)
            {
                score += 13;
            }
            if(deck[joueur_actuelle][j] == 0)
            {
                score += 11;
            }
            if(deck[joueur_actuelle][j] == 6)
            {
                score += 5;
            }
            if(deck[joueur_actuelle][j] == 12)
            {
                score += 100;
            }
        }
        return score;
    }
}
