#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int a = -1, b=0,res;
    while(a != 0)
    {
        int b=1;
        a = -10

        ;
        while (a < 0)
        {
        printf("donner un nombre pour a :\n");
        scanf("%d", &a);
        system("CLS");
        }

        while(b<=10)
        {
        res = a * b;
        printf("la table de multiplication %d * %d = %d \n", a, b, res);
        b++;
        }
    }
}
