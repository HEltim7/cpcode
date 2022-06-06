#include <iostream>
using namespace std;
long long data[10000], maxdata = -2147483647, mindata = 2147483647;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
        if (data[i] > maxdata)
        {
            maxdata = data[i];
        }
        if (data[i] < mindata)
        {
            mindata = data[i];
        }
    }
    cout << mindata << ' ' << maxdata;
    return 0;
}