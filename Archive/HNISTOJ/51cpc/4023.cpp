#include <iostream>
using namespace std;
unsigned long long step[100] = {0, 0, 1, 2};

int main()
{
    int level = 0;
    cin >> level;
    for (int i = 4; i <= level; i++)
    {
        step[i] = step[i - 1] + step[i - 2];
    }
    cout << step[level];
    return 0;
}