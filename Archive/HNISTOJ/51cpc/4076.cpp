#include <iostream>
using namespace std;

int isnp[10000] = {1, 1};
void prime(int ip)
{
    for (int i = 2; i * i < ip; i++)
        if (!isnp[i])
            for (int j = i * i; j < ip; j += i)
                isnp[j] = 1;
}

int main()
{
    int last, end;
    cin >> last >> end;
    prime(end + 1);
    for (int i = last; i <= end; i++)
    {
        if (!isnp[i])
        {
            cout << i << ' ';
        }
    }
    return 0;
}