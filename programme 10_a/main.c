#include <stdio.h>
#include <stdlib.h>

#define nbr_cellules 10

void remplir(int *adresse_debut, int nb_cases);
void afficher(int *adresse_debut, int nb_cases);
void inversion(int tableaux[nbr_cellules], int nb_cases);

int main()
{
    int liste[nbr_cellules];

    remplir(liste,nbr_cellules);
    afficher(liste,nbr_cellules);

    inversion(liste,nbr_cellules);
    afficher(liste,nbr_cellules);
}

void remplir(int *adresse_debut, int nb_cases)
{
    int i;
    int *ptr;
    ptr = adresse_debut;
    for(i=0;i<nb_cases;i++)
    {
        *ptr = rand()%10;
        ptr++;
    }
}

void afficher(int *adresse_debut, int nb_cases)
{
    int i;
    int *ptr;
    ptr = adresse_debut;
    printf("\n");
    for(i=0;i<nb_cases;i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }
}

void inversion(int tableaux[nbr_cellules], int nb_cases)
{
    int i,tmp;
    for(i=0;i<nb_cases/2;i++)
    {
        tmp = tableaux[i];
        tableaux[i] = tableaux[nb_cases-i-1];
        tableaux[nb_cases-i-1] = tmp;
    }
}
