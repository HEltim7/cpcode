#include <iostream>
using namespace std;
string str;
int alpha[128], flag;

int main()
{
    while(cin>>str)
    {
        int count = str.length();
        //统计字符
        for (int i = 0; i < count; i++)
        {
            alpha[str[i]]++;
        }
        //判断
        count = 128;
        for (int i = 0; i < count; i++)
        {
            if (alpha[i] % 2 == 1)
            {
                flag++;
            }
            alpha[i] = 0;
        }
        if (flag > 1)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
        flag = 0;
    }
    return 0;
}