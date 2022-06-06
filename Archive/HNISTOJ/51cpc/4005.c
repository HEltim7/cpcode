//第几天？
#include <stdio.h>
int main()
{
    long ip;
    int d, m, y, judge(int);
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d", &ip);
    d = ip % 100;
    m = (ip % 10000) / 100;
    y = ip / 10000;
    for (int i = 0; i < m - 1; i++)
    {
        d += month[i];
    }
    if (judge(y) && m >= 3)
    {
        d++;
    }
    printf("%d", d);
    return 0;
}
int judge(int year)
{
    int flag = 0;
    if (year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }
    else if (year % 400 == 0 && year % 3200 != 0)
    {
        return 1;
    }
    else if (year % 80000 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}