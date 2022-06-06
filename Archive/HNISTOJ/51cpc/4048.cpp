#include <iostream>
#include <string.h>
using namespace std;
char str[100], trash;

int main()
{
    cin >> str;
    cin >> trash;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != trash)
        {
            cout << str[i];
        }
    }
    return 0;
}