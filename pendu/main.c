#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();
void jeu(char mot_visible[100],char mot_invisible[100], char lettre_choix);
void afficher(char mot_invisible[100]);
void score(char mot_visible[100],char mot_invisible[100],char lettre_choix);

int main()
{
    char lettre,mot[100],mot_secret[100];
    int i=0,choix,k2000;

    printf("<--bienvenue dans le jeu du pendu-->\n\n");

    printf("rentrez votre mot : ");
    scanf("%s", &mot);
    system("CLS");

    strcpy(mot_secret,mot);

    for(i=0;i<strlen(mot);i++)
    {
        mot_secret[i] = '*';
    }

    do
    {
        printf("\n entrez une lettre : ");
        scanf("%s", &lettre);

        choix=menu();

        switch(choix)
        {
        case 1:
            jeu(mot,mot_secret,lettre);
            afficher(mot_secret);
            score(mot,mot_secret,lettre);
            break;
        case 2:
            return 0;
            break;
        }
    }while(strcmp(mot,mot_secret)==1);
    printf("felicitation");
}

int menu()
{
    int choix_utilisateur;

    printf("1) jouer/continuer ? \n");
    printf("2) quitter ? \n");
    printf("votre choix : ");
    scanf("%d", &choix_utilisateur);

    return choix_utilisateur;
}

void jeu(char mot_visible[100],char mot_invisible[100], char lettre_choix)
{
    int i=0,j=0;

    printf("<--voici votre mot camoufle-->\n");

    for(j=0;j<strlen(mot_visible);j++)
    {
        if(mot_visible[j]==lettre_choix)
        {
            mot_invisible[j] = lettre_choix;
        }
    }
}

void afficher(char mot_invisible[100])
{
        printf("%s", mot_invisible);
}

void score(char mot_visible[100],char mot_invisible[100], char lettre_choix)
{
    int point=10;

    if(strchr(mot_visible,lettre_choix)== NULL)
    {
        point--;
        printf("\n il te reste %d de chance", point);
        if(point==0)
        {
            printf("dommage :-(");
            return 0;
        }
    }
}
