#include <stdio.h>
#include <stdlib.h>

int factorielle(int valeur2);

int main()
{
    int valeur;
    printf("entrez une valeur : ");
    scanf("%d", &valeur);
    factorielle(valeur);
}

int factorielle(int nombre)
{
    int k2000,facto,i;
    k2000 = nombre;
    facto = k2000;


    for(i=1;i<nombre;i++)
    {
        k2000 = k2000-1;
        facto = facto*k2000;
    }

    printf("voici le factorielle de %d est %d", nombre, facto);
}
