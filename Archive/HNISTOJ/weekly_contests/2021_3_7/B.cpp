#include <iostream>
using namespace std;
int sum;

int main()
{
    double n;
    cin >> n;
    for (int i = 1; i * i < n; i++)
    {
        if (n / i == (int)(n / i))
        {
            sum += i + n / i;
        }
    }
    if (sum - n == n)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}