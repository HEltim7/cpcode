/*Qlist109，递归&递推，外星密码
思路不清，细节没处理到位，代码冗杂，结构差*/
#include <iostream>
using namespace std;
string in;
int i, flag;
string decmp(int mark) //递归主体,decompression,mark下标
{
    string tmp = "";
    for (i = mark; in[i - 1] != ']' && i < in.length(); i++)
    {
        if (in[i] == '[') //遇到压缩头, 后跟重复数repeat
        {
            int repeat = in[++i] - '0';
            string tmptmp;
            //录入要重复的字符串到tmp
            for (i++; in[i] != ']';)
            {
                if (in[i] == '[') //此处又遇到下一层[]就调用递归
                {
                    tmptmp += decmp(i);
                }
                else
                {
                    tmptmp += in[i];
                    i++;
                }
            }
            for (; repeat > 0; repeat--)
            {
                tmp += tmptmp;
            }
        }
        else //一般内容
        {
            tmp += in[i];
        }
    }
    flag = 1;
    return tmp;
}

int main()
{
    cin >> in;
    cout << decmp(0);
    if (flag && i < in.length()) //垃圾代码的补漏手段
        for (; i < in.length(); i++)
            cout << in[i];
    return 0;
}