#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();
void jeu(char mot_visible[100],char mot_invisible[100], char lettre_choix);
void afficher(char mot_invisible[100]);

int main()
{
    char lettre,mot[100],mot_secret[100];
    int i=0,choix,score=10;

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
            if(strchr(mot, lettre)== NULL)
            {
                score--;
                printf("\n il te reste %d de chance", score);
                if(score==0)
                {
                    return 0;
                }
            }
            break;
        case 2:
            return 0;
            break;
        }
    }while(mot_secret!=mot);
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
