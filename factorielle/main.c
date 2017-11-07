#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long a;
    long long b;
    long long res=1;
    printf("donner un nombre : \n");
    scanf("%d", &a);
    printf("donner un nombre : \n");
    scanf("%d", &b);

    res = a;

    while(res < b)
    {
        b = b * a;
        a--;
    }
    printf("%d", b);
}
