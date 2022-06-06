#include <iostream>
using namespace std;

int fn(int ip)
{
    if (ip >= 0)
    {
        return 5;
    }
    else
    {
        return fn(ip + 1) + fn(ip + 2) + 1;
    }
}

int main()
{
    int x;
    cin >> x;
    cout << fn(x);
    return 0;
}