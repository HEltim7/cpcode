#include <iostream>
#include <stdio.h>
using namespace std;
int i, j, k;

int main()
{
    int ip;
    cin >> ip;
    //5
    for (i = 1; i <= 9; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            for (k = 0; k <= 9; k++)
            {
                if (i * 2 + j * 2 + k == ip)
                {
                    cout << i << j << k << j << i << endl;
                }
            }
        }
    }
    //6
    for (i = 1; i <= 9; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            for (k = 0; k <= 9; k++)
            {
                if (i * 2 + j * 2 + k * 2 == ip)
                {
                    cout << i << j << k << k << j << i << endl;
                }
            }
        }
    }
    return 0;
}