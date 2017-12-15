#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

void menu();

int main()
{
    menu();

    return 0;
}

void menu()
{
    int i,j,mot,resultat,essaies=0,essaiesCumu=0,tradCumu=0,cpt,nbVerif=1,motRand,bon;
    char fr[10];
    char an[10];
    char trad[10];
    char verif[6][10];
    for(i=0;i<6;i++)
    {
        strcpy(verif[i],"azertyu");
    }

    srand(time(NULL));
    setlocale(LC_ALL,"");
    FILE *output, *input;

    int choix;

    cpt=0;
    if((input=fopen("word_data_base.txt","r"))!=NULL)
    {
        while(!feof(input))
        {
            fscanf(input,"%s %s",fr,an);
            cpt++;
        }
        fclose(input);
    }

    if(cpt<100)
    {
        printf("Jeu de traduction :\n");
        printf("1 : Encoder un mot\n");
        printf("2 : Jouer en traduisant du français vers l'anglais\n");
        printf("3 : Jouer en traduisant de l'anglais vers le français\n");
        printf("4 : Afficher l'ensemble des mots de la liste\n");
        printf("5 : Quitter le jeu\n");
        do
        {
            scanf("%d",&choix);
            fflush(stdin);
        } while(choix<1 || choix>5);
    }
    else
    {
        printf("ERREUR, vous avez plus de 100 mots encodé, veuillez aller en supprimer\n");
    }


    switch(choix)
    {
        case 1:

        system("CLS");

        if((output=fopen("word_data_base.txt","a"))!=NULL)
        {
                printf("Entrez un mot en français: ");
                scanf("%s",fr);
                printf("Entrez sa traduction en anglais: ");
                scanf("%s",an);

                fprintf(output,"\n%s %s",fr,an);
                fclose(output);
                system("CLS");
                printf("Vous avez bien encodé le mot %s et sa traduction %s\n",fr,an);

                main();
        }
        else
        {
            printf("ERREUR, impossible d'ouvrir le fichier");
        }

        break;

        case 2:
            system("CLS");
            if((input=fopen("word_data_base.txt","r"))!=NULL)
            {
                if(cpt>=5)
                {
                    for(i=0;i<5;i++)
                    {
                        mot = rand()%cpt;
                        motRand = mot;
                        for(j=0;j<nbVerif;j++)
                        {
                            mot = motRand;
                            do
                            {
                                fscanf(input,"%s %s",fr,an);
                                mot--;
                            }while(mot>=0);
                            rewind(input);
                            bon = strcmp(fr,verif[j]);
                            if(bon==0)
                            {
                                mot = rand()%cpt;
                                motRand = mot;
                                j=0;
                            }

                        }
                        strcpy(verif[nbVerif],fr);
                        nbVerif++;

                    printf("Traduisez vers l'anglais le mot suivant : %s\n",fr);
                    do
                    {
                        if(essaies>0)
                        {
                            printf("Raté ! Réessayez\n");
                        }
                    scanf("%s",trad);
                    resultat = strcmp(trad, an); //Cette fonction renvoi 0 si les 2 sont egaux, un nombre négatif si trad est inférieur, et positif si fr est supérieur
                    essaies++;
                    essaiesCumu++;
                    } while(resultat!=0 && essaies<5);
                    if(essaies<5)
                    {
                        tradCumu++;
                    }
                    essaies = 0;
                    system("CLS");
                }
                    printf("Vous avez dû traduire 5 mots\n");
                    printf("Vous en avez traduit %d correctement\n",tradCumu);
                    printf("Vous avez fait %d essaies\n\n",essaiesCumu);
            }
            else
            {
                printf("ERREUR, veuillez encoder au moins 5 mots\n");
            }
        fclose(input);
        }
        else
        {
            printf("ERREUR, impossible d'ouvrir le fichier\n");
        }

        main();

        break;

        case 3:
            system("CLS");
            if((input=fopen("word_data_base.txt","r"))!=NULL)
            {
            if(cpt>=5)
            {
            for(i=0;i<5;i++)
            {

                    mot = rand()%cpt;
                    motRand = mot;
                    for(j=0;j<nbVerif;j++)
                    {
                        mot = motRand;
                        do
                        {
                            fscanf(input,"%s %s",fr,an);
                            mot--;
                        }while(mot>=0);
                        rewind(input);
                        bon = strcmp(an,verif[j]);
                        if(bon==0)
                        {
                            mot = rand()%cpt;
                            motRand = mot;
                            j=0;
                        }

                    }
                    strcpy(verif[nbVerif],an);
                    nbVerif++;

                    printf("Traduisez vers le français le mot suivant : %s\n",an);
                    do
                    {
                        if(essaies>0)
                        {
                            printf("Raté ! Réessayez\n");
                        }
                    scanf("%s",trad);
                    resultat = strcmp(trad, fr); //Cette fonction renvoi 0 si les 2 sont egaux, un nombre négatif si trad est inférieur, et positif si fr est supérieur
                    essaies++;
                    essaiesCumu++;
                    } while(resultat!=0 && essaies<5);
                    if(essaies<5)
                    {
                        tradCumu++;
                    }
                    essaies = 0;
                    system("CLS");
        }
            printf("Vous avez dû traduire 5 mots\n");
            printf("Vous en avez traduit %d correctement\n",tradCumu);
            printf("Vous avez fait %d essaies\n\n",essaiesCumu);
        }
        else
        {
            printf("ERREUR, veuillez encoder au moins 5 mots\n");
        }
        fclose(input);
        }
        else
        {
            printf("ERREUR, impossible d'ouvrir le fichier\n");
        }

        main();

        break;

        case 4:

        cpt=0;

        system("CLS");
        if((input=fopen("word_data_base.txt","r"))!=NULL)
        {
            while(!feof(input)&&(cpt<100))
            {
                fscanf(input,"%s %s",fr,an);
                cpt++;
                printf("Mot %d: %s en français et %s en anglais\n",cpt,fr,an);
            }
            printf("\n");
            fclose(input);

            main();
        }
        else
        {
            printf("ERREUR, impossible d'ouvrir le fichier");
        }

        break;

        case 5:
            system("CLS");
            printf("Fin du programme\n");
        break;
    }
}
