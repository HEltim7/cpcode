//n个数的最小公倍数
#include <stdio.h>
#include <math.h>
int main()
{
    int n, lcm = 0, i, gcd(int, int);
    scanf("%d", &n);
    int data[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        data[i + 1] = abs(data[i] * data[i + 1]) / gcd(data[i], data[i + 1]);
    }

    printf("%d", data[i]);
    return 0;
}
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}