#include <bits/stdc++.h>
using namespace std;
int data[30], n;
long long sum[30];

long long next(int left, long long op)
{

    if (left < 2)
    {
        return op * 1;
    }
    else
    {
        return op * next(left - 1, op) + op * 2 * next(left - 2, op);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
        sum[i] = next(data[i], 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << sum[i] << endl;
    }

    return 0;
}