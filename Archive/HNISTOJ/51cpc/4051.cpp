#include <iostream>
using namespace std;
long data[1000];

int main()
{
    int a, b, c, d;
    cin >> a >> b;
    c = a;
    d = b;
    while (d)
    {
        int t = c % d;
        c = d;
        d = t;
    }
    for (int i = 0; i <= (a * b / c) / a + 1; i++)
    {
        int max = i * a;
        while (max < a * b / c)
        {
            data[max] = 1;
            max += b;
        }
    }
    for (int i = (a * b / c) - 1; i >= 0; i--)
    {
        if (!data[i])
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}