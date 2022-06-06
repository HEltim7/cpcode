#include <iostream>
#include <algorithm>
using namespace std;

struct numbers
{
    int label;
    int num;
} tmpa;

int main()
{
    int n, tmp, sum = 1, j;
    cin >> n;
    struct numbers a[n] = {0};
    cin >> a[0].label;
    a[0].num++;
    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        for (j = 0; j < sum; j++)
        {
            if (a[j].label == tmp)
            {
                a[j].num++;
                break;
            }
        }
        if (j == sum)
        {
            a[sum].label = tmp;
            a[sum].num++;
            sum++;
        }
    }
    for (int j = 0; j < sum; j++)
    {
        for (int i = 0; i < sum - 1; i++)
        {
            if (a[i].label > a[i + 1].label)
            {
                tmpa = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmpa;
            }
        }
    }
    for (int i = 0; i < sum; i++)
    {
        cout << a[i].label << ' ' << a[i].num << endl;
    }

    return 0;
}