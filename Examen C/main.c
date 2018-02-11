#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grille(char tableaux[100][100], int ligne, int colonne);
void afficher_grille(char tableaux[100][100], int ligne, int colonne);
int nombre_voyelles(char tableaux[100][100], int ligne, int colonne);
void trie_diagonale(char tableaux[100][100],int ligne,int colonne);

int main()
{
    char tableaux[100][100],lettre;
    int ligne,colonne, voyelles=0;

    srand(time(NULL));

    printf("Wins Julien, 1TTI Groupe 2 \n");

    do
    {
        printf("combien de ligne voulez-vous (entre 5 et 25) : ");
        scanf("%d", &ligne);
    }while(ligne<5 || ligne>25);
    do
    {
        printf("combien de colonne voulez-vous (entre 5 et 25) : ");
        scanf("%d", &colonne);
    }while(colonne<5 || colonne>25);

    system("cls");

    grille(tableaux, ligne, colonne);
    voyelles = nombre_voyelles(tableaux, ligne, colonne);
    printf("nombre de voyelle : %d \n", voyelles);
    trie_diagonale(tableaux, ligne, colonne);
    afficher_grille(tableaux, ligne, colonne);

    system("pause");
}

void grille(char tableaux[100][100], int ligne, int colonne)
{
    int i,j, lettre;

    for(i=0;i<ligne;i++)
    {
        for(j=0;j<colonne;j++)
        {
            lettre = rand() % 26;
            tableaux[i][j] = 'A' + lettre;
            printf("%c \t", tableaux[i][j]);
        }
        printf("\n");
    }
}

int nombre_voyelles(char tableaux[100][100], int ligne, int colonne)
{
    int i,j,nombre_voy=0;
    char lettre = 'A',lettre2 = 'E', lettre3 = 'I', lettre4= 'O', lettre5= 'U', lettre6= 'Y';
    for(i=0;i<ligne;i++)
    {
        for(j=0;j<colonne;j++)
        {
            if(tableaux[i][j] == lettre)
            {
                nombre_voy++;
            }
            else if(tableaux[i][j] == lettre2)
            {
                nombre_voy++;
            }
            else if(tableaux[i][j] == lettre3)
            {
                nombre_voy++;
            }
            else if(tableaux[i][j] == lettre4)
            {
                nombre_voy++;
            }
            else if(tableaux[i][j] == lettre5)
            {
                nombre_voy++;
            }
            else if(tableaux[i][j] == lettre6)
            {
                nombre_voy++;
            }
            else
            {
                tableaux[i][j] = tolower(tableaux[i][j]);
            }
        }
    }
    return nombre_voy;
}

void trie_diagonale(char tableaux[100][100], int ligne, int colonne)
{
    int i,j,temp;

    for(i=0;i<ligne;i++)
    {
        for(j=0;j<i;j++)
        {
            temp = tableaux[i][j];
            tableaux[i][j] = tableaux[j][i];
            tableaux[j][i] = temp;
        }
    }
}

void afficher_grille(char tableaux[100][100], int ligne, int colonne)
{
    int i,j;

    for(i=0;i<ligne;i++)
    {
        for(j=0;j<colonne;j++)
        {
            printf("%c \t", tableaux[i][j]);
        }
        printf("\n");
    }
}
