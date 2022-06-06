#include <iostream>
#include <stdio.h>
using namespace std;
#define M 10007

int main()
{
    long a = 1, b = 1, n, sum = 2;
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << '1';
        return 0;
    }

    for (int i = 3; i <= n; i++)
    {
        sum = (a + b) % M;
        a = b % M;
        b = sum;
    }
    cout << sum;
    return 0;
}