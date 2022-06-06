#include <iostream>
using namespace std;
int n, num, mem[1000] = {0, 1};

int leftadd(int in)
{
    if (mem[in])
    {
        return mem[in];
    }
    else
    {
        int tmp = 0;
        for (int i = 1; i <= in / 2; i++)
        {
            tmp += leftadd(i);
        }
        tmp += 1;
        mem[in] = tmp;
        return tmp;
    }
}

int main()
{
    cin >> n;
    num = leftadd(n);
    cout << num;
    return 0;
}