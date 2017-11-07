#include <stdio.h>
#include <stdlib.h>

#define nb_caract 35

int main()
{
    char chaine_caract [nb_caract];
    char lettre_rech;
    char *pointeur;

    printf("Entrez un mot de maximum %d caractere minuscule : \n\t",nb_caract-1);
    scanf("%s",chaine_caract);

    fflush(stdin);
    printf("Entrez une lettre minuscule contenue dans le mot precedent :\n\t");
    lettre_rech=getchar();

    pointeur=chaine_caract;
    while(*pointeur!='\0')
    {
        if(*pointeur==lettre_rech)
        {
            *pointeur=toupper(*pointeur);
        }
        pointeur++;
    }
    printf("\n Le mot apres modification est\n\t%s\n",chaine_caract);
}
