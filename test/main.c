#include <stdio.h>
#include <stdlib.h>
#define cellule 5

void remplir(int *adresse,int cas);
void afficher(int *tabl,int cas);
void tri_croissant(int tab[cellule],int cas);

int main()
{
    int tab[cellule];
    printf("Remplissage du tableau : \n");
    remplir(tab,cellule);
    afficher(tab,cellule);
    tri_croissant(tab,cellule);
     afficher(tab,cellule);


    return 0;
}
void remplir(int *adresse,int cas)
{
   int i=0;
    int *ptr;
    ptr=adresse;
    for(i=0;i<cas;i++)
    {
        *ptr=rand()%10;
        ptr++;

    }


}
void afficher(int *tabl,int cas)
{
    int i=0;
    int *ptr;
    ptr=tabl;
    printf("\n");
    for(i=0;i<cas;i++)
    {
        printf("%d\t \a",*ptr);
        ptr++;

    }

    }
    void tri_croissant( int tab[cellule],int cas)
    {
        int i;
        int j;
         int tmp=0;
        for(i=0;i<cas-1;i++)
        {
            for(j=i+1;j<cas;j++)
            {
                if(tab[i]>tab[j])
                {
                    tmp=tab[i];
                    tab[i]=tab[j];
                    tab[j]=tmp;
                }
            }

        }

    }
