#include <iostream>
using namespace std;
int *p[1000], n;

void swap()
{
    for (int i = 0; i < n; i++)
    {
        int min = 325768, mark = 0, change = 0;
        for (int j = i; j < n; j++)
        {
            if (*p[j] < min)
            {
                min = *p[j];
                mark = j;
                change = 1;
            }
        }
        if (change)
        {
            *p[mark] = *p[i];
            *p[i] = min;
        }

        cout << "swap(a[" << i << "],a[" << mark << "]):";
        for (int k = 0; k < n; k++)
        {
            cout << *p[k] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i] = &a[i];
    }
    swap();

    return 0;
}