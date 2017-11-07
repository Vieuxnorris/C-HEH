#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    do
    {
        printf("1,2 ou 3 : \n");
        scanf("%d", &a);
        if (a <1 || a>3)
        {
            printf("erreur 1 2 3 \n");
        }
    }
    while(a<1 || a>3);
    printf("bravo, vous avez appuye sur la touche : 1 2 3 \n");
}
