//m进制转十进制
#include <stdio.h>
#include <math.h>
int main()
{
    int m, n, num, flag = 0;
    scanf("%d%d", &n, &m);
    if (n == 0)
    {
        printf("0");
        return 0;
    }
    if (n < 0)
    {
        flag = 1;
        n = fabs(n);
    }
    //数字分离
    if (flag)
    {
        printf("-");
    }
    for (int i = 0; n != 0; i++)
    {
        int tmp = 0;
        tmp = n % 10;
        num += tmp * pow(m, i);
        n /= 10;
    }
    printf("%d", num);
    return 0;
}