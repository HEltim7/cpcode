#include <iostream>
using namespace std;
bool flag;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        int sum = i;
        for (int j = i + 1; sum < n; j++)
        {
            sum += j;
            if (sum == n)
            {
                cout << n << '=' << i;
                for (int k = i + 1; k <= j; k++)
                {
                    cout << '+' << k;
                }
                return 0;
            }
        }
    }
    cout << "No Answer";
    return 0;
}