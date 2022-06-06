#include <iostream>
#include <algorithm>
using namespace std;
int data[10000];

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> data[i];
    }
    sort(data, data + num);
    for (int i = 0; i < num; i++)
    {
        cout << data[i] << ' ';
    }
    return 0;
}