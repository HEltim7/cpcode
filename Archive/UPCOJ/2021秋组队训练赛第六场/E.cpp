#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 1005;
int a[N];
int up, low;
int main()
{
    int t, s, n;
    scanf("%d%d%d", &t, &s, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    low = s;
    for (int i = 2; i <= n; i++)
    {
        int g = a[i] - a[i - 1];
        int change = g;
        if (i % 2 == 0)
        {
            if (g > low)
            {
                change = low;
            }
            low -= change;
            up += change;
        }
        else
        {
            if (g > up)
            {
                change = up;
            }
            up -= change;
            low += change;
        }
    }
    if (n % 2 == 1)
    {
        swap(up, low);
    }
    int g = t - a[n];
    if (g >= up)
    {
        puts("0");
    }
    else
        printf("%d\n", up - g);
}