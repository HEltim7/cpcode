#include <iostream>
using namespace std;
int n, ip, maxsum = -32767, sum;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ip;
        sum += ip;
        if (sum > maxsum)
        {
            maxsum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxsum;
    return 0;
}