#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/* <-------------Personnes du Projet------------->
Programme fait par :
    - Jordan Desaive
    - Carmelo Mirabile
    - Alessio Baio
    - Wins Julien
*/


void carte_alea(int joueur[10][10],int color[10][10],int nombre_joueur,int player_fake,int temp);
void Affichage_de_main(int joueur[10][10],int color[10][10],int joueur_nombre,int player_fake,int fake_temp,int nombre_de_joueur);
void pioche(int joueur[10][10],int color[10][10], int nombre_de_joueur,int votre_carte,int nombre_de_carte,int joueur_de_droite,int player_fake,int fake_temp);
int menu();

int main()
{
    int nombre_joueur,min=0,max=52,nombre_de_manches,choix_joueur,joueur_nombre;
    int validation = 0;
    int i,j;
    int joueur[10][10];
    int color[10][10];
    int player_fake=0;
    int temp_fake = 0;
    int deck_carte[52][52];
    int deck_color[52][5];
    int nombre_de_carte = 52;

    srand(time(NULL));


    printf("Bienvenue sur le jeu de cartes 'Le Tas de Merde' \n\n");
    do
    {
        printf("A combien voulez-vous jouer (Trois minimum, dix maximum) ? ");
        scanf("%d", &nombre_joueur);
        fflush(stdin);
        if(nombre_joueur >= 3 && nombre_joueur <= 10)
        {
            do
            {
                printf("\nEn combien de manches voulez-vous jouer ? ");
                scanf("%d", &nombre_de_manches);
                fflush(stdin);
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
        printf("Joueur %d, voici votre nombre de cartes : %d\n", i, j);
    }
    printf("\nLe nombre de cartes restant est de : %d \n \n", nombre_de_carte);

    Sleep(6500);
    carte_alea(joueur,color,nombre_joueur,player_fake,joueur_nombre);
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
                printf("Quel joueur es-tu ? ");
                scanf("%d", &joueur_nombre);
                fflush(stdin);
            }while(joueur_nombre <= nombre_joueur-nombre_joueur || joueur_nombre > nombre_joueur);
            Affichage_de_main(joueur,color,joueur_nombre,player_fake,temp_fake,nombre_joueur);
            Sleep(5000);
            system("cls");
            break;
        case 2:
            system("cls");
            printf("<----------------Nouvelle Pioche---------------->\n\n\n");
            carte_alea(joueur,color,nombre_joueur,player_fake,joueur_nombre);
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
            system("pause");
            system("cls");
            break;
        case 5:
            return 0;
            break;
        }
    }while(choix_joueur != 5);
}

void carte_alea(int joueur[10][10],int color[10][10],int nombre_joueur,int player_fake,int temp)
{
    int i=0,j=0,k=0,c=0,valeur_carte=0,valeur_couleur=0,valeur_max=0,valeur_min=0,p=2;
    char* tableaux_graphique_carte[] = {"Null","Null","Sept","Neuf","Huit","Six","Cinq","Quatre","Trois","Deux","Valet","Dame","Roi","As"};
    char* tableaux_graphique_couleur[] = {"Null","Pique","Coeur","Carreau","Trefle"};
    int validation = 1;
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
            if(joueur[i][j] > 1 && joueur[i][j] < 15)
            {
                printf("carte : %s \t\t", tableaux_graphique_carte[joueur[i][j]]);
            }
        }
        printf("\n");
        for(j=1;j<=4;j++)
        {
            valeur_couleur = rand() % (5-1) + 1;
            color[i][j] = valeur_couleur;
            if(color[i][j] > 0 && color[i][j] < 5)
            {
                printf("couleur : %s \t", tableaux_graphique_couleur[color[i][j]]);
            }
        }
        printf("\n\n");
    }
    if(player_fake == 2)
    {
        for(i=temp;i<=temp;i++)
        {
            for(j=5;j<=5;j++)
            {
                valeur_carte = rand() %(14-1) + 1;
                joueur[i][j] = valeur_carte;
                printf("carte : %d \t", joueur[i][j]);
            }
            printf("\n");
            for(j=5;j<=5;j++)
            {
                valeur_couleur = rand() % (5-1) + 1;
                color[i][j] = valeur_couleur;
                printf("couleur : %d \t", color[i][j]);
            }
            printf("\n\n");
        }
    }
}

void Affichage_de_main(int joueur[10][10],int color[10][10],int joueur_nombre,int player_fake,int fake_temp,int nombre_de_joueur)
{
    int i=0,j=0,valeur_couleur=0,valeur_carte=0,compteur=0,compteur2=0;
    char* tableaux_graphique_carte[] = {"NULL","NULL","Sept","Neuf","Huit","Six","Cinq","Quatre","Trois","Deux","Valet","Dame","Roi","As"};
    char* tableaux_graphique_couleur[] = {"Null","Pique","Coeur","Carreau","Trefle"};
    for(i=joueur_nombre;i<=joueur_nombre;i++)
    {
        for(j=1;j<=4;j++)
        {
            if(joueur[i][j] > 1 && joueur[i][j] < 15)
            {
                printf("carte : %s \t\t", tableaux_graphique_carte[joueur[i][j]]);
            }
            valeur_carte = joueur[i][1];
            if(joueur[i][j] == valeur_carte)
            {
                compteur++;
                if(compteur == 4)
                {
                    printf("Bravo %d tu as win !", joueur_nombre);
                }
            }
        }
        printf("\n");
        for(j=1;j<=4;j++)
        {
            if(color[i][j] > 0 && color[i][j] < 5)
            {
                printf("couleur : %s \t", tableaux_graphique_couleur[color[i][j]]);
            }
            valeur_couleur = color[i][1];
            if(joueur[i][j] == valeur_couleur)
            {
                compteur2++;
                if(compteur2 == 4)
                {
                    printf("Bravo %d tu as win !", joueur_nombre);
                }
            }
        }
        printf("\n\n");
    }
    if(player_fake == 2 && i == fake_temp)
    {
        system("cls");
        printf("joueur %d \n",fake_temp);
       for(i=fake_temp;i<=fake_temp;i++)
    {
        for(j=1;j<=5;j++)
        {
            printf("carte : %d \t", joueur[i][j]);
            valeur_carte = joueur[i][1];
            if(joueur[i][j] == valeur_carte)
            {
                printf("Bravo %d tu as win !", joueur_nombre);
            }
        }
        printf("\n");
        for(j=1;j<=5;j++)
        {
            printf("couleur : %d \t", color[i][j]);
            valeur_couleur = color[i][1];
            if(joueur[i][j] == valeur_couleur)
            {
                compteur2++;
                if(compteur2 == 4)
                {
                    printf("Bravo %d tu as win !", joueur_nombre);
                }
            }
        }
        printf("\n\n");
    }
    }
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

void Game(int joueur[10][10],int color[10][10],int nombre_de_joueur, int nombre_de_manche,int nombre_de_carte, int deck_color[52][5],int deck_carte[52][52],int joueur_nombre)
{
    int i=0,j=0,k,temp=1,score=0,joueur_victoire[10],fin_joueur[10],valeur_de_la_carte=0;;
    int manche=0, votre_carte=0,compteur=0;
    int Winner=1,GameFull=1,End=1;
    int player_fake=0,temp_fake=0;
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
                            printf("joueur %d dit : 'Dame de coeur ! A vous l'honneur ! Dame de pique, a vous la suite !' \n\n\n",temp);
                            manche++;
                            break;
                    }
                case 2:
                    system("cls");
                    printf("joueur %d \n",temp);
                    Affichage_de_main(joueur,color,temp,player_fake,temp_fake,nombre_de_joueur);
                    break;
                case 3:
                    system("cls");
                    regle();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    printf("joueur %d \n",temp);
                    Affichage_de_main(joueur,color,temp,player_fake,temp_fake,nombre_de_joueur);
                    system("cls");
                    pioche(joueur,color,nombre_de_joueur,votre_carte,nombre_de_carte,temp,player_fake,temp_fake);
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
                    score = compteur_de_score(joueur,color,nombre_de_joueur,temp,player_fake);
                    printf("voici votre score : %d \n\n", score);
                    if(temp > nombre_de_joueur)
                    {
                        temp = 1;
                        manche++;
                        if(manche == nombre_de_manche)
                        {
                            for(i=1;i<=nombre_de_joueur;i++)
                            {
                                score = compteur_de_score(joueur,color,nombre_de_joueur,temp,player_fake);
                                printf("voici votre score : %d \n\n", score);
                                temp++;
                            }
                            Sleep(5000);
                            Winner=0;
                        }
                    }
                    break;
                case 6:
                    system("cls");
                    temp++;
                    if(temp > nombre_de_joueur)
                    {
                        temp = 1;
                        manche++;
                        if(manche == nombre_de_manche)
                        {
                            for(i=1;i<=nombre_de_joueur;i++)
                            {
                                score = compteur_de_score(joueur,color,nombre_de_joueur,temp,player_fake);
                                printf("voici votre score : %d \n\n", score);
                                temp++;
                            }
                            Sleep(5000);
                            Winner=0;
                        }
                    }
                    printf("joueur %d \n",temp);
                    break;
                case 7:
                    system("cls");
                    Winner = 0;
                    break;
                case 8:
                    system("cls");
                    player_fake++;
                    if(player_fake >= 2)
                    {
                        printf("tu es dans la merde mon ami ^^ donne ton numéro (1.2.3.4) : ");
                        scanf("%d", &temp_fake);
                        temp_fake++;
                        temp++;
                        if(temp_fake > nombre_de_joueur || temp > nombre_de_joueur)
                        {
                            temp_fake = 1;
                            temp = 1;
                            nombre_de_carte--;
                            manche++;
                            if(manche == nombre_de_manche)
                            {
                            for(i=1;i<=nombre_de_joueur;i++)
                            {
                                score = compteur_de_score(joueur,color,nombre_de_joueur,temp,player_fake);
                                printf("voici votre score : %d \n\n", score);
                                temp++;
                            }
                            Sleep(5000);
                            Winner=0;
                            }
                        }
                        carte_alea(joueur,color,nombre_de_joueur,player_fake,temp_fake);
                        system("cls");
                    }
                    break;
                }
            }while(Winner == 1);
            system("cls");
            printf("tu veux refaire une partie (1 ou 0) ?");
            scanf("%d", &GameFull);
            fflush(stdin);
            manche = 1;
        }while(GameFull == 1);
        printf("tu es vraiment sûr (1 ou 0) ?");
        scanf("%d", &End);
        fflush(stdin);
        manche = 1;
    }while(End == 1);
    printf("Merci beaucoup d'avoir test notre programme :-) \n");
}

int menu() //Changement ecriture printf
{
    int choix;
    printf("<--------------------Menu-------------------->\n");
    printf("Appuyez sur [1] pour afficher votre main\n");
    printf("Appuyez sur [2] pour melanger le deck\n");
    printf("Appuyez sur [3] pour debuter la partie \n");
    printf("Appuyez sur [4] pour afficher les regles \n");
    printf("Appuyez sur [5] pour quitter le jeu\n\n");
    printf("Que souhaitez-vous faire ? : ");
    scanf("%d", &choix);
    fflush(stdin);
    return choix;

}

int menu_2(int manche, int joueur[10][10], int color[10][10], int nombre_de_joueur, int votre_joueur) //Changements printf
{
    int i,j,choix;
    printf("<----------------Choix----------------> \n");
    if(manche == 0)
    {
        printf("Appuyez sur [1] pour crier 'Dame de coeur ! A vous l'honneur !\nDame de pique, a vous la suite !' \n\n");
        printf("Appuyez sur [7] pour quitter la partie.\n");
    }
    else
    {
        printf("Appuyez sur [2] pour verifier vos carte ainsi que les conditions de victoire\n");
        printf("Appuyez sur [3] pour relire les regles\n");
        printf("Appuyez sur [4] pour jouer\n");
        printf("Appuyez sur [5] pour connaitre ton nombre de kilos de merde\n");
        printf("Appuyez sur [6] pour passer votre tour\n");
        printf("Appuyez sur [7] pour quitter la partie\n");
    }
    printf("votre choix : ");
    scanf("%d", &choix);
    fflush(stdin);
    return choix;
}

void pioche(int joueur[10][10],int color[10][10], int nombre_de_joueur,int votre_carte,int nombre_de_carte,int joueur_de_droite,int player_fake,int fake_temp)
{
    int i,j,valeur_test,swap,valeur_joueur=0;
    Affichage_de_main(joueur,color,joueur_de_droite,player_fake,fake_temp,nombre_de_joueur);
    printf("Quelle est la carte que vous souhaitez changer ? (1,2,3,4) : ");
    scanf("%d", &votre_carte);
    valeur_joueur = joueur_de_droite+1;
    if(valeur_joueur > nombre_de_joueur)
    {
        valeur_joueur = 1;
    }
    printf("Quelle carte du joueur %d voulez-vous echanger ? (1,2,3,4) : ",valeur_joueur);
    scanf("%d", &valeur_test);
    for(i=1;i<=nombre_de_joueur;i++)
    {
        for(j=1;j<=1;j++)
        {
            swap = joueur[joueur_de_droite][votre_carte];
            joueur[joueur_de_droite][votre_carte] = joueur[valeur_joueur][valeur_test];
            joueur[valeur_joueur][valeur_test] = swap;
        }
        for(j=1;j<=1;j++)
        {
            swap = color[joueur_de_droite][votre_carte];
            color[joueur_de_droite][votre_carte] = color[valeur_joueur][valeur_test];
            color[valeur_joueur][valeur_test] = swap;
        }
    }
}

int compteur_de_score(int joueur[10][10], int color[10][10], int nombre_joueur,int ton_joueur)
{
    int i,j,valeur_fake=5,score=0;
    for(i=ton_joueur;i<=ton_joueur;i++)
    {
        for(j=1;j<=valeur_fake;j++)
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
