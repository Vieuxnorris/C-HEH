#include <stdio.h>
#include <stdlib.h>

#define nb_cellules 5

void remplir(int tabl[nb_cellules], int nb_cases);
void tri_par_inversion(int tabl[nb_cellules], int nb_cases);
void tri_croissant(int tab[nb_cellules], int nb_cases);
void afficher(int *adresse, int nb_cases);
void tri_avec_sens(int tabl[nb_cellules], int nb_cases, char sens) ;

int main()
{
    int choix;

    int tableaux[nb_cellules];
    remplir(tableaux, nb_cellules);

    printf("entrez une valeur pour votre choix \n");
    printf("1 croissant \n");
    printf("2 decroissant \n");
    printf("choix : ");
    scanf("%d", &choix);
    switch(choix)
    {
 case 1:
    tri_avec_sens(tableaux,nb_cellules,'c');
    afficher(tableaux,nb_cellules);
    break;
 case 2:
    tri_avec_sens(tableaux,nb_cellules,'d');
    afficher(tableaux,nb_cellules);
    break;
 default :
    printf("pas bon \n");
    }
}

void tri_par_inversion(int tabl[nb_cellules], int nb_cases)
{
    int i;
    int tmp;
    for(i=0;i<nb_cases/2;i++)
    {
        tmp = tabl[i];
        tabl[i] = tabl[nb_cases-i-1];
        tabl[nb_cases-i-1] = tmp;
    }
}

void afficher(int *adresse, int nb_cases)
{
    int i;
    int *ptr;
    ptr = adresse;
    printf("\n");
    for(i=0;i<nb_cases;i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }
}

void remplir(int tabl[nb_cellules], int nb_cases)
{
    int i;
    for(i=0;i<nb_cases;i++)
    {
        printf("rentrez une valeur : ");
        scanf("%d", &tabl[i]);
    }
}

void tri_croissant(int tabl[nb_cellules], int nb_cases)
{
    int i,j,tmp;
    for(i=0;i<nb_cases-1;i++)
    {
        for(j=i+1;j<nb_cases;j++)
        {
            if(tabl[i]>tabl[j])
            {
                tmp=tabl[i];
                tabl[i]=tabl[j];
                tabl[j]=tmp;
            }
        }
    }
}

void tri_avec_sens(int tabl[nb_cellules], int nb_cases, char sens) // c croissant d decroissant
{
    int i,j,tmp;
    for(i=0;i<nb_cases-1;i++)
    {
        for(j=i+1;j<nb_cases;j++)
        {
            if(((tabl[i]>tabl[j])&&(sens=='c'))||((tabl[i]<tabl[j])&&(sens=='d')))
            {
                tmp=tabl[i];
                tabl[i]=tabl[j];
                tabl[j]=tmp;
            }
        }
    }
}


void tri_decroissant(int tabl[nb_cellules], int nb_cases)
{
    int i,j,tmp;
    for(i=0;i<nb_cases-1;i++)
    {
        for(j=i+1;j<nb_cases;j++)
        {
            if(tabl[i]<tabl[j])
            {
                tmp=tabl[i];
                tabl[i]=tabl[j];
                tabl[j]=tmp;
            }
        }
    }
}
