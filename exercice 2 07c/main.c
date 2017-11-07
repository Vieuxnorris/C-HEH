#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int nombresecret, nombre, compteur=0, end;
    do
    {
        srand(time(NULL));
        nombresecret = rand()% 1001;
    do
    {
        printf("entrez un valeur : ");
        scanf("%d", &nombre);

        if(nombre<nombresecret)
        {
            printf("il est plus grand\n\n");
        }
        if(nombre>nombresecret)
        {
            printf("il est plus petit\n\n");
        }
        if(nombre==66666)
        {
            printf("%d \n", nombresecret);
            compteur=-1;
        }
        compteur++;
    }
    while (nombre != nombresecret);
    printf("félicitation vous avez trouvé en %d tentative(s) \n", compteur);
    printf("recommencer ? \n");
    scanf("%d", &end);
    }
    while(end==1);
        if (end==0)
        {
            return 0;
        }
}
