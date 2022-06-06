#include <iostream>
using namespace std;
long bin[20][10000000];
int r;
int main()
{
    long n, flag = 0, mark = 0;
    while (cin >> n)
    {  
        if (n == 0)
        {
            break;
        }
        long data[n] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> data[i];
            bin[r][data[i]]++;
        }
        for (int i = 0;; i++)
        {
            if (bin[r][i] == 1)
            {
                cout << i << endl;
                break;
            }
        }
        r++;
    }
    return 0;
}