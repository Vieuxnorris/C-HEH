#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,nombre_etoiles;

    printf("entrez un nombre :");
    scanf("%d", &nombre_etoiles);

    for(a=0;a<nombre_etoiles;a++)
    {
     for(b=0;b<nombre_etoiles;b++)
     {
         printf("*");
     }
     printf("\n");
    }

}
