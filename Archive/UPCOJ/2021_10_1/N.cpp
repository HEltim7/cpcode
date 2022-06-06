#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ts;
int x, y;
char ps[256];
int nw = 0;
int main()
{
    scanf("%d", &ts);
    getchar();
    scanf("$%d.%d", &x, &y);
    getchar();
    int sum = 0;
    nw = y;
    nw %= 100;
    while (ts--)
    {
        scanf("$%d.%d", &x, &y);
        getchar();
        nw += y;
        if (nw % 100 != 0)
        {
            sum++;
        }
        nw %= 100;
    }

    cout << sum << endl;
    return 0;
}
/*
4
$1.00
$0.01
$0.99
$0.10
$0.90

*/