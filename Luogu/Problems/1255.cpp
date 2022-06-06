/*参照4023优化，需要高精度算法*/
#include <iostream>
using namespace std;

unsigned long long iteration(int left,unsigned long long add)
{
    if (left<2)
    {
        return add*1; 
    }
    else
    {
        return add*iteration(left-1,add)+add*iteration(left-2,add);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << iteration(n,1);
    return 0;
}