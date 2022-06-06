#include <iostream>
#include <stdio.h>
using namespace std;
int y, m, d, sum;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    scanf("%4d%2d%2d", &y, &m, &d);
    for (int i = m - 1; i > 0; i--)
    {
        sum += month[i];
    }
    sum += d;

    int whatday = (sum + 5) % 7;
    cout << whatday + 1;
    return 0;
}