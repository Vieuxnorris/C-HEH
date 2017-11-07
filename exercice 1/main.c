#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int age, age_global;
    const int retrait = 65;

    printf("entre votre age: ");
    scanf("%d", &age);
    age_global = age - retrait;

    if (age < retrait)
    {
        printf("tu n'est pas dans la retrait, il te reste %d ans avant la retrait", -age_global);
    }
    else
    {
        printf("tu es dans la retrait depuis %d ans", age_global);
    }
}
