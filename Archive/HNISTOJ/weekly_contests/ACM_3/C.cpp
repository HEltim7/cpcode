//题看错，折腾了好久，A了，可参照kmp算法改进
#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    string str[n];
    cin >> str[0];
    for (int i = 0; i <= n; i++)
    {
        string cmp;
        getline(cin,cmp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < cmp.length(); j++)
            {
                int flag = 1, add = 0;
                if (cmp[j] == str[i][0])
                {
                    for (int k = 0; k < str[i].length(); k++)
                    {
                        if (str[i][k] != cmp[j + add])
                        {
                            flag = 0;
                            break;
                        }
                        add++;
                    }

                    if (flag)
                    {
                        sum++;
                    }
                }
            }
        }
    }
    cout << sum;
    return 0;
}