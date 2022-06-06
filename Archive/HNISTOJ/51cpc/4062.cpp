#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
char a[10000], b[10000];
bool flag = true;

int main()
{
    cin >> a >> b;
    for (int i = 0; i < strlen(a) || i < strlen(b); i++)
    {
        if (a[i] != b[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}