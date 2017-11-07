#include <stdio.h>
#include <stdlib.h>

int main()
{
    int notes=-2, compteur=0, max=0, min=20, accu=0;

    while(notes != -1)
    {
        notes = -2;
        while(notes <-1 || notes>20)
        {
            printf("entrez une note : \n");
            scanf("%d", &notes);
        }
        if(notes != -1)
        {
            accu += notes;
            compteur++;
            if(notes>max)
            {
                max=notes;
            }
            if(notes<min)
            {
                min=notes;
            }
            else
            {

            }
        }
    }
    printf("%d %d %d %d", accu/compteur,max,min,notes);
}
