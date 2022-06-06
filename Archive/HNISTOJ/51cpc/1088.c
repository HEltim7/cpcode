//求前n小的素数
#include <stdio.h>
int main()
{
    int isnp[10000] = {1, 1}, n;
    scanf("%d", &n);
    for (int i = 2; i * i <= 10000; i++)
        if (!isnp[i])
            for (int j = i * i; j < 10000; j += i)
            {
                isnp[j]++;
            }
    for (int i = 0; n; i++)
    {
        if (!isnp[i])
        {
            printf("%d ", i);
            n--;
        }
    }

    return 0;
}