#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_COLONNES 7
#define NB_LIGNE 6

void grille(char tableaux[NB_COLONNES][NB_LIGNE]);
void affichage_grille(char tableaux[NB_COLONNES][NB_LIGNE]);
int joueur(int player,char tableaux[NB_COLONNES][NB_LIGNE]);
int validation(int choix, char tableaux[NB_COLONNES][NB_LIGNE]);
void jeu(int choix,char tableaux[NB_COLONNES][NB_LIGNE]);

int main()
{
    int tableaux[NB_COLONNES][NB_LIGNE];
    int player;
    int gameover;
    int choix;
    int FALSE=0;
    int TRUE=1;

    printf("Bienvenue dans mon puissance 4 :-) \n");

    grille(tableaux);
    affichage_grille(tableaux);

    do
    {
        printf("choisi le numero du joueur 1 ou 2 : ");
        scanf("%d", &player);
    }while(player<1 || player>2);

    do
    {
        choix = joueur(player,tableaux);
    }while(validation(choix,tableaux)==FALSE);

    jeu(choix,tableaux);
    affichage_grille(tableaux);
}

void grille(char tableaux[NB_COLONNES][NB_LIGNE])
{
    int i,j;
    for(i=0;i<NB_COLONNES;i++)
    {
        for(j=0;j<NB_LIGNE;j++)
        {
            tableaux[i][j] =' ';
        }
    }
}

void affichage_grille(char tableaux[NB_COLONNES][NB_LIGNE])
{
    int i, j;

    printf("|");
    for(i = 0; i < NB_COLONNES; i++)
    {
        printf(" %d ", i+1);
    }
    printf("|\n");

    printf("|");
    for(i = 0; i < NB_COLONNES; i++)
    {
        printf("___");
    }
    printf("|\n");

    for(j = 0 ; j < NB_LIGNE; j++)
    {
        printf("|");
        for(i = 0; i < NB_COLONNES; i++)
        {
            printf(" %c ", tableaux[i][j]);
        }
        printf("|\n");
    }
    printf("|");
    for(i = 0; i < NB_COLONNES; i++)
    {
        printf("___");
    }
    printf("|\n");
}

int joueur(int player, char tableaux[NB_COLONNES][NB_LIGNE])
{
    int i,j,choix_joueur;

    if(player==1 || player==2)
    {
        printf("Bienvenue joueur %d :-) ", player);
        printf("voici une case : ");
        scanf("%d", &choix_joueur);
    }
    return choix_joueur;
}

int validation(int choix, char tableaux[NB_COLONNES][NB_LIGNE])
{
    int lignefree = -1;
    int i;
    choix -=1;
    int FALSE=0;
    int TRUE=1;

    if(choix < 0 || choix >= NB_COLONNES)
    {
        return FALSE;
    }

    for(i=NB_LIGNE-1;i>=0;i--)
    {
        if(tableaux[choix][i]==' ');
        lignefree = i;
    }

    if(lignefree == -1)
    {
        return FALSE;
    }
    return TRUE;
}

void jeu(int choix, char tableaux[NB_COLONNES][NB_LIGNE])
{
    int lignefree= -1;
    choix -= 1;
    int i;

    for (i=NB_LIGNE-1;i>=0;i--)
    {
        if(tableaux[choix][i] == ' ')
        {
            lignefree = i;
        }
    }

    tableaux[choix][lignefree] = 'x';
}
