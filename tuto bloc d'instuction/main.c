#include <stdio.h>

void afficher(int nbr);
void faireplusdeux(int *nbr);

main()
{
    int valeur;
    printf("entrez une valeur entier positif : ");
    scanf("%d", &valeur);
    afficher(valeur);
    faireplusdeux(&valeur);
}

void afficher(int nbr)
{
    printf("\ndans la procedure afficher : %d", nbr);
}

void faireplusdeux(int *nbr)
{
    *nbr = *nbr+2;
    printf("\ndans la procedure afficher : %d", *nbr);
}

