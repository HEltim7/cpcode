#include <iostream>
using namespace std;
int moto, car;

int main()
{
    int n;
    cin >> n;
    string str[n];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        if (str[i][1] == 'Y' || str[i][1] == 'E' || str[i][1] == 'X')
        {
            if (str[i][0] == '1')
            {
                moto++;
            }
            else if (str[i][0] == '2')
            {
                car++;
            }
        }
    }
    cout << moto << ' ' << car;
    return 0;
}