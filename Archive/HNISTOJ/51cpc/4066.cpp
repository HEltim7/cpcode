#include <iostream>
#include <string>
using namespace std;
string a, b;
bool flag;

int main()
{
    cin >> a >> b;
    for (int i = 0;; i++)
    {
        flag = true;
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i + j] != b[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << i + 1;
            break;
        }
    }
    return 0;
}