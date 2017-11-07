#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int tab[10][2],i,somme, minimal=99999999999999999999;

    printf("entrez 10 valeurs pour les lignes et les colonnes : \n");

    for(i=0;i<10;i++)
    {
        scanf("%d", &tab[i][0]);
    }
    printf("entrez 10 valeurs pour la colonne : \n");
    for(i=0;i<10;i++)
    {
        scanf("%d", &tab[i][1]);
    }
    for(i=0;i<10;i++)
    {
        somme = tab[i][1];
        tab[i][1] = tab[i][0];
        tab[i][0] = somme;
        printf("1           %d = %d              2               %d = %d \n",i,tab[i][0],i,tab[i][1]);
    }
    */
    int i, tab[10], minimal=555;
    for(i=0;i<10;i++)
    {
     scanf("%d", &tab[i])
    if(minimal>tab[i])
    {
        minimal = tab[i];
    }
    }
    printf("%d \n", minimal);
}
