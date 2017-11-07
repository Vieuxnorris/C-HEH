#include <stdio.h>
#include <stdlib.h>

int main()
{
    float pt1,pt2,pt3;
    float c1,c2,c3;
    float result;

    printf("rentrer une valeur pour pt1,pt2,pt3 : ");
    scanf("%f %f %f", &pt1,&pt2,&pt3);
    printf("rentrer une valeur pour c1,c2,c3 : ");
    scanf("%f %f %f", &c1,&c2,&c3);

    printf("\n %.2f\t %.2f", pt1,c1);
    printf("\n %.2f\t %.2f", pt2,c2);
    printf("\n %.2f\t %.2f", pt3,c3);

    result = ((pt1 * c1) + (pt2 * c2) + (pt3 * c3)) / (c1 + c2 + c3);
    printf("\n %.2f", result);
}
