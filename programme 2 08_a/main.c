#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[4][3], ligne,colonne;

    printf("remplissage du tableau \n");

    for(ligne=0;ligne<4;ligne++)
    {
        for(colonne=0;colonne<3;colonne++)
        {
            printf("entrez une valeur entiere pour la cellule [%d,%d] :",ligne,colonne);
            scanf("%d",&tab[ligne][colonne]);
        }
    }

        for(ligne=0;ligne<4;ligne++)
    {
        for(colonne=0;colonne<3;colonne++)
        {
            printf("%d \t",tab[ligne][colonne]);
        }
        printf("\n");
    }
}
