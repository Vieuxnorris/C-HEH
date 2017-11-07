#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    int b;
    float c;

    printf("entrer une valeur pour a : ");
    scanf("\n %f", &a);

    b = a;
    printf("\n %d", b);

    c = a - b;
    printf("\n %f", c);
}
