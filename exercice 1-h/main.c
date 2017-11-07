#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b;
    int c;

    printf("entrer un nombre pour a : \n");
    scanf("%d", &a);
    printf("entrer un nombre pour b : \n");
    scanf("%d", &b);

    c = a;
    a = b;
    b = c;
    printf("A: %d \n", a);
    printf("B: %d \n", b);

    printf("---- Apres l'echange des contenus ----\n \n");

    c = b;
    b = a;
    a = c;
    printf("A: %d \n", a);
    printf("B: %d \n", b);


}
