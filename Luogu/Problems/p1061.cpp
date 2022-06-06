#include <iostream>
using namespace std;
string a, b, op;

int main()
{
    //输入
    getline(cin, a);
    getline(cin, b);
    //补齐0位
    if (a.length() > b.length())
    {
        int add0 = a.length() - b.length() - 1;
        for (int i = 0; i <= add0; i++)
            b = '0' + b;
    }
    else if (b.length() > a.length())
    {
        int add0 = b.length() - a.length() - 1;
        for (int i = 0; i <= add0; i++)
            a = '0' + a;
    }
    //相加，flag为进位指示器
    int flag = 0;
    int tmp, j = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        tmp = a[i] - '0' + b[i] - '0' + flag;
        if (tmp > 9)
        {
            tmp -= 10;
            op += tmp + '0';
            flag = 1;
            continue;
        }
        op += tmp + '0';
        flag = 0;
    }
    if (flag)
    {
        op += '1';
    }
    //输出
    for (int i = op.length() - 1; i >= 0; i--)
    {
        cout << op[i];
    }
    return 0;
}