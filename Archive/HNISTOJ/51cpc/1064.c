//哥德巴赫猜想
#include <stdio.h>
int isnp[32768] = {0};
int main()
{
    int n, prime(int);
    scanf("%d", &n);
    prime(n);
    for (int i = 1; i <= n / 2; i += 2)
    {
        if (!isnp[i] && !isnp[n - i])
        {
            printf("%d = %d + %d\n", n, i, n - i);
        }
    }
    return 0;
}
int prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (!isnp[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                isnp[j] = 1;
            }
        }
    }
    return 0;
}