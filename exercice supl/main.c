#include <stdio.h>
#include <string.h>

int main()
{
   char a[100], b[100];

   printf("Entrez un mot : ");
   gets(a);

   strcpy(b,a);
   strrev(b);

   if (strcmp(a,b) == 0)
   {
       printf("c'est un palindrome.\n");
   }
   else
   {
       printf("c'est pas un palindrome.\n");
   }
}
