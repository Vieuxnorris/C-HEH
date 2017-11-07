#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;

    printf("entrer un nombre : ");
    scanf("%d",&a);
    printf("entrer un deuxieme nombre : ");
    scanf("%d",&b);

    c = (a * b)>0;
    printf("%d",c);
}
