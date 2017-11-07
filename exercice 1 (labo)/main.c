#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b;
    int c;

    printf("exercice portent sur les opérations arithmétiques\n");
    printf("donner une valeur pour a :\n");
    scanf("%d", &a);
    printf("donner une valeur pour b :\n");
    scanf("%d", &b);

    c = a + b;
    printf("somme %d \n", c);
    c = a - b;
    printf("soustraction %d \n", c);
    c = a * b;
    printf("multiplication %d \n", c);
    c = a / b;
    printf("division %d \n", c);
    c = a % b;
    printf("modulo %d \n", c);
    a++;
    printf("a plus %d \n", a);
    b--;
    printf("b moins %d \n", b);

    a = -20;
    b = 123;
    printf("valeur absolue de a et b : %d %d", abs(a), abs(b));
}
