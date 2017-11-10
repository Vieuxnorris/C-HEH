#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nombre,nombre_uti,facto=1,i=0;

    printf("Entrez un nombre : ");
    scanf("%d", &nombre);
    nombre_uti = nombre;
    facto = nombre_uti;

    for(i=1;i<nombre;i++)
    {
        nombre_uti = nombre_uti-1;
        facto = facto * nombre_uti;
    }
    printf("la factorielle de %d est : %d \n", nombre, facto);
}
