#include <iostream>
using namespace std;

int main()
{
    long n;
    while (cin >> n)
    {
        if (n == 0)
        {
            return 0;
        }
        int i;
        long long data[n];
        for (i = 0; i < n; i++)
        {
            cin >> data[i];
        }

        for (i = 0; i < n; i++)
        {
            int flag = 1;
            for (int j = 0; j < n; j++)
            {
                if (data[i] == data[j] && i != j)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                cout << data[i] << endl;
                break;
            }
        }
    }
    return 0;
}