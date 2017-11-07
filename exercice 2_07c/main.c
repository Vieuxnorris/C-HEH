#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    do
    {
        printf("a,b,c,d,e : \n");
        scanf("%c", &a);
        if ((a!='a')&&(a!='b')&&(a!='c')&&(a!='d')&&(a!='e'))
        {
            printf("erreur : \n");
        }
    }
    while ((a!='a')&&(a!='b')&&(a!='c')&&(a!='d')&&(a!='e'));
    printf("c'est bon");

}
