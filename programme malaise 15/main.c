#include <stdio.h>
#include <stdlib.h>

#define ligne 3
#define colonne 3

int main()
{
    int tab[ligne][colonne];
    int i=0,j=0,reponse=0,compteur=0;

    for(i=0;i<ligne;i++)
    {
        for(j=0;j<colonne;j++)
        {
            do
            {
                printf("entrez un nombre positif : ");
                scanf("%d", &tab[i][j]);
            }while(tab[i][j]<=0);
            if (tab[i][j]%2==0)
            {
                compteur++;
            }
            reponse = reponse + tab[i][j];
        }
        printf("nombre de paire : %d \nsomme de la colonne : %d \n", compteur, reponse);
        reponse = 0;
    }
}
