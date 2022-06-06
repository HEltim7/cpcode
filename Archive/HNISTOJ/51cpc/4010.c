//求一个整数有几位
#include <stdio.h>
int main()
{
    int ip, i;
    scanf("%d", &ip);
    for (i = 0; ip != 0; i++)
    {
        ip /= 10;
    }
    printf("%d", i);
    return 0;
}