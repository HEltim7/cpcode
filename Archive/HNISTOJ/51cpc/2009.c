//循环程序2
#include <stdio.h>
int main()
{
    int m = 1, i;
    double ip, add = 0, op = 0;
    scanf("%lf", &ip);
    for (i = 1;; i++)
    {
        add = 1. / m;
        if (add < ip)
        {
            break;
        }
        op += add;
        m *= i;
    }
    printf("%lf", op);
    return 0;
}