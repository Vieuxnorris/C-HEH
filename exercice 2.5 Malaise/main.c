#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char nom[3][100];
    char prenom[3][100];
    char nomprenom;
    int i,j,longueurnom,longueurprenom;

    for(i=0;i<3;i++)
    {
        printf("saisir un nom : ");
        scanf("%s", nom[i]);
        printf("saisir un prenom : ");
        scanf("%s", prenom[i]);

        longueurnom = strlen(nom[i]);
        longueurprenom = strlen(prenom[i]);

        nom[i][0]=toupper(nom[i][0]);
        prenom[i][0]=toupper(prenom[i][0]);
        printf("%c.%c %i %i \n",nom[i][0],prenom[i][0],longueurnom,longueurprenom);

        printf("%s \n", nom[i]);
        printf("%s \n", prenom[i]);

        strcat(nom[i]," ");
        strcat(nom[i],prenom[i]);
        printf("%s \n", nom[i]);
    }

}
