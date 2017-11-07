#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,C,I,result;

    for (A=0; A<9; A++)
    {
        pow(A,3);
        for (B=0; B<9; B++)
        {
            pow(B,3);
            for (C=0; C<9; C++)
            {
                pow(C,3);
                result = A*100+B*10+C*1;
                I=pow(A,3)+pow(B,3)+pow(C,3);
                if (result== I)
                {
                    printf("%d \n",result);
                }
            }
        }
    }
}
