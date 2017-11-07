#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,tab[5],x;

    for(i=0;i<4;i++)
    {
        printf("entrez une valeur pour x : ");
        scanf("%d", x);
        tab[i] = x;
    }
    printf("%d", tab[2]);
}
