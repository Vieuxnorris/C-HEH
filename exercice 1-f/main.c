#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    printf("entrer un nombre a 4 chiffres : ");
    scanf("%d",&a);

    printf("%d   %d   %d   %d",a/1000,(a%1000)/100,(a%100)/10,(a%10));
}
