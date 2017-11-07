#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nombre=1,table=1;

    while(nombre<11)
    {
        table = 1;
        while(table<11)
        {
            printf("%d ",nombre*table);
            table++;
        }
        printf("\n");
        nombre++;
    }
}
