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
    long ip;
    cin >> ip;
    prime(ip);
    for (int i = ip; i > 0; i--)
    {
        double cmpf = ip * 1. / i;
        int cmpi = ip / i;
        if (!isnp[i] && !isnp[cmpi] && cmpi == cmpf)
        {
            cout << i;
            break;
        }
    }
    return 0;
}