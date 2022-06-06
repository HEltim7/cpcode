//被9整除的数
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = n; i < 100; i++)
    {
        if (i % 9 == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}