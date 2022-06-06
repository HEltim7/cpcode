#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 0)
    {
        cout << "ERROR!";
        return 0;
    }
    for (int i = 0; i <= n; i++)
    {
        cout << i << '+' << n - i << "=" << n << endl;
    }
    return 0;
}