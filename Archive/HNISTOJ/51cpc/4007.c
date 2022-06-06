//数组找最大和最小数
#include <stdio.h>
int main()
{
    int ip, max = -32768;
    for (;;)
    {
        scanf("%d", &ip);
        if (ip == 0)
        {
            break;
        }
        max = ip > max ? ip : max;
    }
    printf("0 %d", max);
    return 0;
}