#include <iostream>
#include <algorithm>
using namespace std;
struct id
{
    long begin;
    long birth;
    long end;
} data[5], tmp;

bool tosort(int ip1, int ip2)
{
    if (ip1 < ip2)
        return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%6ld", &data[i].begin);
        scanf("%8ld", &data[i].birth);
        scanf("%4ld", &data[i].end);
    }

    for (int j = n - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (tosort(data[i].birth, data[i + 1].birth))
            {
                tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << data[i].begin << data[i].birth << data[i].end << endl;
    }

    return 0;
}