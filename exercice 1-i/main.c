#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,f,g,h;

    printf("a*b     a and b     a nand b    a or b      a nor b     a exor b    a nexor b\n");
    a = 0;
    b = 0;
    c = a && b;
    d = !(a && b);
    e = a || b;
    f = !(a || b);
    g = ((!a) &&b) || (a&&(!b));
    h = !(((!a) &&b) || (a&&(!b)));
    printf("%d*%d       %d          %d         %d          %d           %d           %d\n", a,b,c,d,e,f,g,h);
    a = 0;
    b = 1;
    c = a && b;
    d = !(a && b);
    e = a || b;
    f = !(a || b);
    g = ((!a) &&b) || (a&&(!b));
    h = !(((!a) &&b) || (a&&(!b)));
    printf("%d*%d       %d          %d         %d          %d           %d           %d\n", a, b,c,d,e,f,g,h);
    a = 1;
    b = 0;
    c = a && b;
    d = !(a && b);
    e = a || b;
    f = !(a || b);
    g = ((!a) &&b) || (a&&(!b));
    h = !(((!a)&&b) || (a&&(!b)));
    printf("%d*%d       %d          %d         %d          %d           %d           %d\n", a, b,c,d,e,f,g,h);
    a = 1;
    b = 1;
    c = a && b;
    d = !(a && b);
    e = a || b;
    f = !(a || b);
    g = ((!a) &&b) || (a&&(!b));
    h = !(((!a) &&b) || (a&&(!b)));
    printf("%d*%d       %d          %d         %d          %d           %d           %d\n", a, b,c,d,e,f,g,h);
}
