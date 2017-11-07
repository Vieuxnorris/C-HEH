#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,nb_etoile;

    printf("entrez un nombre");
    scanf("%d", &nb_etoile);

    for(a=0;a<=nb_etoile;a++)
    {
        for(b=0;b<=a;b++)
        {
            printf("*");
        }
        printf("\n");
    }
//*****
    printf("\n Triangle pointe bas gauche\n");
    for(a=0;a<nb_etoile;a++)
    {
        for(b=0;b<nb_etoile-a;b++)
        {
            printf("*");
        }
        printf("\n");
    }
//********
    printf("\n Triangle horizontale\n");
    for(a=0;a<nb_etoile;a++)
    {
        for(b=0;b<a;b++)
        {
            if(b<nb_etoile-a-1)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
//******
    printf("\n Triangle pointe bas droite");
    for(a=0;a<nb_etoile;a++)
    {
        for(b=0;b<nb_etoile;b++)
        {
            if(b<a)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }

        printf("\n");
    }
}
