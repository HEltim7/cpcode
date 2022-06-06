//求最小公倍数
#include <stdio.h>
int main()
{
    int a, b, max, ax, bx;
    scanf("%d%d", &a, &b);
    max = a * b;
    if (b > a) //make a>b
    {
        a += b;
        b = a - b;
        a = a - b;
    }
    ax = a;
    bx = b;
    for (;;)
    {
        if (ax == bx)
        {
            printf("%d", ax);
            break;
        }
        bx += b;
        if (bx > ax)
        {
            ax += a;
        }
    }
    return 0;
}