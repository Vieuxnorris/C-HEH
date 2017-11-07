#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[4][3], ligne=0,colonne=0;
    int *pointeur;

    printf("remplissage du tableau \n");
    pointeur = tab;
    for(ligne=0;ligne<4;ligne++)
    {
        for(colonne=0;colonne<3;colonne++)
        {
            printf("entrez une valeur entiere pour la cellule [%d,%d] :",ligne,colonne);
            scanf("%d",pointeur);
            pointeur++;
        }
    }
printf("affichage du tableau \n \n");
pointeur = tab;
        for(ligne=0;ligne<4;ligne++)
    {
        for(colonne=0;colonne<3;colonne++)
        {
            printf("\n%p - %d \t",pointeur,*pointeur);
            pointeur++;
        }
        printf("\n");
    }
}
