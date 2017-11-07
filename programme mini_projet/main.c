#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mots_FR 2
#define mots_EN 2

int main()
{
    int choix,i,j=0,h=0,compteur=0;
    char motsFR[mots_FR][34],motsEN[mots_EN][34], reponse[100];

    do{
    printf("jeu de traduction\n");
    printf("1 : Encoder la serie de mots \n");
    printf("2 : Jouer en traduisant du français vers l'anglais \n");
    printf("3 : Jouer en traduisant de l'anglais vers le français \n");
    printf("4 : Quitter le jeu \n");
    printf("Entrez le chiffre correspondant à votre choix :");
    scanf("%d", &choix);


    switch(choix)
    {
    case 1:
        printf("entrez 10 mots FR : \n");
        for (i=0;i<mots_FR;i++)
        {
         printf("entrez un mots FR : \n");
         scanf("%s", &motsFR[i]);
        }
        printf("entrez 10 mots EN : \n");
        for(i=0;i<mots_EN;i++)
        {
         printf("entrez un mots EN : \n");
         scanf("%s", &motsEN[i]);
        }
        break;
    case 2:
        do
        {
            for(i=0;i<mots_FR;i++)
            {
                do
                {
                    h=0;
                    printf("entrez le mot englais de %s : \n", motsFR[i]);
                    scanf("%s", reponse);
                    if (strcmp(reponse, motsEN[i]) == 0)
                    {
                        printf("bonne response \n");
                        h=1;
                    }
                    compteur++;
                    printf("compteur %d \n", compteur);
                } while (h==0);
            }
            compteur = 0;
        } while(h==0);
        break;
    case 3:
        do
        {
            for(i=0;i<mots_EN;i++)
            {
                do
                {
                    h=0;
                    printf("entrez le mot englais de %s : \n", motsEN[i]);
                    scanf("%s", reponse);
                    if (strcmp(reponse, motsFR[i]) == 0)
                    {
                        printf("bonne response \n");
                        h=1;
                    }
                    compteur++;
                    printf("compteur %d \n", compteur);
                } while (h==0);
            }
            compteur = 0;
        } while(h==0);
        break;
    case 4:
        return 0;
        break;

        }
    }while(j==0);
}
