#include <iostream>
using namespace std;
long a1, b1, c1, a2, b2, c2;

int main()
{
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    long x = (b1 * c2 - b2 * c1) * 1. / (b1 * a2 - b2 * a1);
    long y = (c1 * a2 - c2 * a1) * 1. / (b1 * a2 - b2 * a1);
    cout << x << ' ' << y;
    return 0;
}