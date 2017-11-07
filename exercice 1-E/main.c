#include <stdio.h>
#include <stdlib.h>

int main()
{
    float far;
    float celsius;

    printf("entrer une valeur pour farhr : \n");
    scanf("%f", &far);

    celsius = 5 * (far - 32) /9;
    printf("voici en celsius: %.2f \n", celsius);

    celsius = 5.0/9.0 * (far - 32);
    printf("voici en celsius: %.2f", celsius);
}
