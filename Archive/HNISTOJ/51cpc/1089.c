//输出小数的4位小数部分
#include <stdio.h>
int main()
{
    double ip;
    scanf("%lf", &ip);
    unsigned long long tmp = ip * 1000000;
    int a, b, c, d;
    d = (tmp % 1000) / 100;
    c = (tmp % 10000) / 1000;
    b = (tmp % 100000) / 10000;
    a = (tmp % 1000000) / 100000;
    printf("%d\n%d\n%d\n%d", a, b, c, d);
    return 0;
}