#include <iostream>
#include <algorithm>
using namespace std;
int data[10000];

int main()
{
    int n, time[10000] = {0}, j = 0;
    cin >> n;
    while (n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> data[i];
            if (data[i] > data[i - 1])
            {
                time[j] += (data[i] - data[i - 1]) * 6 + 5;
            }
            else if (data[i] < data[i - 1])
            {
                time[j] += (data[i - 1] - data[i]) * 4 + 5;
            }
            else
            {
                time[j] += 5;
            }
        }
        j++;
        cin >> n;
    }
    for (int i = 0; i < j; i++)
    {
        cout << time[i] << endl;
    }

    return 0;
}