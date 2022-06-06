#include <iostream>
using namespace std;

int main()
{
    string str;
    char insert;
    bool output = false;
    cin >> str >> insert;
    for (int i = 0; i < str.length(); i++)
    {
        if (insert <= str[i] && !output)
        {
            cout << insert;
            output = true;
        }
        cout << str[i];
    }
    return 0;
}