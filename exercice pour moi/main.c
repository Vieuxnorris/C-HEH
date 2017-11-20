#include <stdio.h>
#include <stdlib.h>
#define lignes 3
#define colonnes 15

void remplir_tableau(int tabl[lignes][colonnes], int ligne, int colonne);
void grille(int tabl[lignes][colonnes], int ligne,int colonne);
void afficher_grille(int tabl[lignes][colonnes], int ligne, int colonne);
void permutation_horizontale(int tableau[lignes][colonnes], int ligne,int colonne);
void permutation_verticale(int tableau[lignes][colonnes], int ligne,int colonne);
void permutation_diagonale(int tableau[lignes][colonnes], int ligne, int colonne);
void scan_nombre(int tableau[lignes][colonnes], int ligne, int colonne);

int main()
{
    int tableau[lignes][colonnes];
    int ligne,colonne,choix,nombre;

    do
    {
        printf("entrez un nombre entre %d/%d pour les lignes : ",lignes,colonnes);
        scanf("%d", &ligne);
    }while(ligne<3 || ligne>15);

    do
    {
        printf("entrez un nombre entre %d/%d pour les colonnes : ",lignes,colonnes);
        scanf("%d", &colonne);
    }while(colonne<3 || colonne>15);

    grille(tableau,ligne,colonne);

    do
    {
    choix=menu();

    switch(choix)
    {
    case 1:
        afficher_grille(tableau,ligne,colonne);
        break;
    case 2:
        permutation_horizontale(tableau,ligne,colonne);
        break;
    case 3:
        permutation_verticale(tableau,ligne,colonne);
        break;
    case 4:
        permutation_diagonale(tableau,ligne,colonne);
        break;
    case 5:
        scan_nombre(tableau,ligne,colonne);
        break;
    case 6:
        return 0;
        break;
    }
    }while(choix!=6);
}

void menu()
{
    int choix_utilisateur;

    printf("---Menu---\n");
    printf("1) voir la grille\n");
    printf("2) permutation horizontale\n");
    printf("3) permutation verticale\n");
    printf("4) permutation diagonale\n");
    printf("5) scan nombre\n");
    printf("6) quitter\n");
    do
    {
    printf("rentrez un nombre entre 1 et 6 : ");
    scanf("%d", &choix_utilisateur);
    }while(choix_utilisateur<1 || choix_utilisateur>6);
}

void grille(int tableau[lignes][colonnes], int ligne,int colonne)
{
    int i=0,j=0;
    srand(time(NULL));
    for(i=0;i<ligne;i++)
    {
        for(j=0;j<colonne;j++)
        {
            tableau[i][j] = rand()%21;
        }
    }
}

void afficher_grille(int tableau[lignes][colonnes], int ligne, int colonne)
{
    int i,j;
    for(i=0;i<ligne;i++)
    {
        for(j=0;j<colonne;j++)
        {
            printf("%d\t", tableau[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void permutation_horizontale(int tableau[lignes][colonnes], int ligne,int colonne)
{
    int i,j,k2000;
    for(i=0;i<ligne;i++)
    {
        for(j=0;j<colonne/2;j++)
        {
            k2000 = tableau[i][j];
            tableau[i][j] = tableau[i][colonne-j-1];
            tableau[i][colonne-j-1] = k2000;
        }
    }
}

void permutation_verticale(int tableau[lignes][colonnes], int ligne,int colonne)
{
    int i,j,k2000;
    for(i=0;i<ligne/2;i++)
    {
        for(j=0;j<colonne;j++)
        {
            k2000 = tableau[i][j];
            tableau[i][j] = tableau[ligne-i-1][j];
            tableau[ligne-i-1][j] = k2000;
        }
    }
}

void permutation_diagonale(int tableau[lignes][colonnes], int ligne, int colonne)
{
    int i,j,k2000;
    for(i=0;i<ligne-1;i++)
    {
        for(j=0;j<colonne-1;j++)
        {
            k2000 = tableau[i][j];
            tableau[i][j] = tableau[ligne-j-1][colonne-i-1];
            tableau[ligne-j-1][colonne-i-1] = k2000;
        }
    }
}

void scan_nombre(int tableau[lignes][colonnes], int ligne, int colonne)
{
    int i,j,compteur=0,nombre;

    printf("entrez un nombre a scan : ");
    scanf("%d", &nombre);

    for(i=0;i<ligne;i++)
    {
        for(j=0;j<colonne;j++)
        {
            if(tableau[i][j]==nombre)
            {
                compteur++;
            }
        }
    }
    printf("voici combien il est de fois dans le tableau %d\n", compteur);
}
