//找到了0A，发现是文件输入的问题，0A为A
#include <iostream>
using namespace std;

int main()
{
    int a[100] = {0}, b[100] = {0}, c[100] = {0};
    long long x, y;
    int j, i, k;
    cin >> x >> y;
    cout << x + y << ' ';
    //a
    for (i = 1; x > 0; i++)
    {
        a[i] = x % 10;
        x /= 10;
    }
    //b
    for (j = 1; y > 0; j++)
    {
        b[j] = y % 10;
        y /= 10;
    }
    //a+b
    for (k = 1; k < i || k < j; k++)
    {
        c[k] = (a[k] + b[k]) % 10;
    }
    for (k--; k > 0; k--)
    {
        if (c[k] != 0)
        {
            break;
        }
    }
    if (k == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = k; i >= 1; i--)
    {
        cout << c[i];
    }
    
    return 0;
}