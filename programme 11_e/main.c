#include <stdio.h>
#include <stdlib.h>

int factorielle(int nombre);
int arrangement(int nombre_n, int nombre_p);
int choix_option(int choix);

int main()
{
    int choix;
    printf("       truc de fou  \n");
    printf("1 --> factorielle \n");
    printf("2 --> arrangement \n");
    printf("3 --> combinaison \n");
    printf("4 --> quitter \n");
    printf("choix : ");
    scanf("%d", &choix);
    choix_option(choix);
}

int choix_option(int choix)
{
    int valeur_n,valeur_p,choix_entier;
    switch(choix)
    {
    case 1:
        printf("entrez un nombre : ");
        scanf("%d", &valeur_n);
        printf("%d",factorielle(valeur_n));
        break;
    case 2:
        printf("entrez un nombre pour n : ");
        scanf("%d", &valeur_n);
        printf("entrez un nombre pour p : ");
        scanf("%d", &valeur_p);
        printf("%d",arrangement(valeur_n,valeur_p));
        break;
    case 3:
        printf("entrez un nombre pour n : ");
        scanf("%d", &valeur_n);
        printf("entrez un nombre pour p : ");
        scanf("%d", &valeur_p);
        printf("%d",combinaison(valeur_n,valeur_p));
        break;
    case 4:
        return 0;
    }
}

int arrangement(int nombre_n, int nombre_p)
{
    return factorielle(nombre_n)/factorielle(nombre_n-nombre_p);
}

int combinaison(int nombre_n, int nombre_p)
{
    return factorielle(nombre_n)/(factorielle(nombre_n-nombre_p)*factorielle(2));
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
