//十进制转m进制
#include <stdio.h>
int main()
{
    int m, n, op[64] = {0}, round, neg = 0;
    scanf("%d%d", &n, &m);
    if (n == 0 || m ==0)
    {
        printf("0");
        return 0;
    }
    else if (n < 0)
    {
        neg++;
        n = -n;
    }
    for (int i = 0; n != 0; i++)
    {
        op[i] = n % m;
        n /= m;
        round++;
    }
    if (neg)
    {
        printf("-");
    }
    for (int i = round - 1; i >= 0; i--)
    {
        printf("%d", op[i]);
    }
}