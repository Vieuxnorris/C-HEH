#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[20],nombre;
    convertisseur(tab,nombre);
}

int convertisseur(int tableau[20],int decimal)
{
    int i=0,j;
    printf("Entrez un nombre a convertir : ");
    scanf("%d",&decimal);
    do
    {
        tableau[i]=decimal%2;
        decimal=decimal/2;
        i++;
    }while(decimal!=0);

    for(j=i-1;j>=0;j--)
    {
        printf("%d",tableau[j]);
    }
}
