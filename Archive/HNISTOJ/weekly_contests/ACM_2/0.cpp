#include <iostream>
#include <algorithm>
using namespace std;
long long data[10000];

int main()
{
    int min = -32768;
    int n, k;
    cin >> n >> k;
    if (n <= 0 || k <= 0)
    {
        cout << "NO RESULT";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    sort(data, data + n);
    for (int i = 0; k > 0; i++)
    {
        if (i >= n)
        {
            cout << "NO RESULT";
            return 0;
        }
        if (min < data[i])
        {
            min = data[i];
            k--;
        }
    }
    cout << min;
    return 0;
}