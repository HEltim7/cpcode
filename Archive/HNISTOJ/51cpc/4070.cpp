#include <iostream>
using namespace std;
int redirect[1000], direct, sum; //北=0西=3南=2东=1

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> redirect[i];
        switch (redirect[i])
        {
        case 0:
            direct = (direct - 1 + 4) % 4;
            break;
        case 1:
            direct = (direct + 1 + 4) % 4;
            break;
        case 2:
            direct = (direct + 2 + 4) % 4;
            break;
        default:
            break;
        }

        if (direct == 2)
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}