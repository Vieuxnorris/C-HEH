#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;

    printf("entrez un nombre");
    scanf("%d", &a);
    printf("entrez un multiplacateur");
    scanf("%d", &b);
    c=1;
    do
    {
        printf("\n %d * %d = %d",c,a,c*b);
        c++;
    } while(c<=b);
}
