#include <iostream>
using namespace std;
int main()
{
    double n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n / i == (int)(n / i))
        {
            cout << i << " * " << n / i << " = " << n << endl;
        }
    }
    return 0;
}