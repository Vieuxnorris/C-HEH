#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int temperature[140];
    int repetition,i,j=0,k2000,somme;
    float moyenne,diff;

    printf("combien de temperature voulez-vous rentrer \n");
    scanf("%d", &repetition);
    if(repetition >= 7 && repetition <= 140)
    {
        for(i=0;i<repetition;i++)
        {
            do
            {
                printf("entrer votre temperature (-20 et 60) : \n");
                scanf("%d", &temperature[i]);
            } while (temperature[i]<-20 || temperature[i]>60);
        }
        system("CLS");
        for(i=0;i<repetition;i++)
        {
            printf("%d\t", temperature[i]);
            j++;
            if(j==4)
            {
                printf("\n");
                j=0;
            }
        }
        printf("\n");
        for(i=0;i<repetition/2;i++)
        {
            k2000 = temperature[i];
            temperature[i] = temperature[repetition-1-i];
            temperature[repetition-1-i] = k2000;
        }
        j=0;
        for(i=0;i<repetition;i++)
        {
            somme += temperature[i];
            printf("%d\t", temperature[i]);
            j++;
            if(j==4)
            {
                printf("\n");
                j=0;
            }
        }
        moyenne = somme/repetition;
        do
            {
                printf("entrer votre temperature (-20 et 60) : \n");
                scanf("%d", &temperature[i]);
            } while (temperature[i]<-20 || temperature[i]>60);

        diff = fabs(temperature[i]-moyenne);
        printf("%f",diff);
    }
}
