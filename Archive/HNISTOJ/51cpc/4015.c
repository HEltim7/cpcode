//素数之和
#include <stdio.h>
int isnp[100000] = {0};
int prime(int n)
{
    isnp[1] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (!isnp[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isnp[j] = 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    prime(n);
    for (int i = 1; i <= n; i++)
    {
        if (!isnp[i])
        {
            sum += i;
        }
    }
    printf("%d", sum);
}