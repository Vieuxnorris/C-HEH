#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a,b,c;

    printf("donner une valeur pour a : \n");
    scanf("%f", &a);
    printf("donner une valeur pour b : \n");
    scanf("%f", &b);

    c = a + b;
    printf("addiction : %+.2f \n", c);
    c = a - b;
    printf("soustraction : %.2f \n", c);
    c = a * b;
    printf("multiplication : %.2f \n", c);
    c = a / b;
    printf("division : %.2f \n", c);
    a++;
    printf("plus a : %.2f \n", a);
    b--;
    printf("moins b : %.2f \n", b);

    a = -12.34567;
    b = 98.76543;
    printf("valeur absolue de a et b : %.2f %.2f \n", fabs(a), fabs(b));

    a = 2;
    b = pow(a,3);
    printf("puissance de b : %.2f \n", b);

    a = 16;
    b = sqrt(a);
    printf("racine carrée de b : %.0f \n", b);
    }

