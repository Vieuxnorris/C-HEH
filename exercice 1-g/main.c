#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float R;
    float V;

    printf("entrer une valeur pour R : ");
    scanf("%f", &R);

    V = 4.0/3.0 * (M_PI * pow(R,3));
    printf("%.2f", V);
}
