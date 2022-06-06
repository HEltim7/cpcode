#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < -10)
    {
        cout << 10;
    }
    else if (n < 10)
    {
        cout << 0;
    }
    else
    {
        cout << -10;
    }
    return 0;
}