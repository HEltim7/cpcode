#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char str[1000];
    cin >> str;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}