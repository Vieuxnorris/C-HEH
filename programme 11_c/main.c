#include <stdio.h>
#include <stdlib.h>

int factorielle(int nombre);
int arrangement(int nombre_n, int nombre_p);

int main()
{
    int valeur_n,valeur_p;
    printf("entrez une valeur pour n : ");
    scanf("%d", &valeur_n);
    printf("entrez une valeur pour p : ");
    scanf("%d", &valeur_p);
    printf("%d",arrangement(valeur_n,valeur_p));
}

int arrangement(int nombre_n, int nombre_p)
{
    return factorielle(nombre_n)/factorielle(nombre_n-nombre_p);
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

    return facto;
}
