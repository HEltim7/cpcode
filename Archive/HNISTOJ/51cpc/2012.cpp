#include <algorithm>
#include <iostream>
using namespace std;
int data[10];
int main()
{
    reverse(data, data + 10);
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += data[i];
    cout << sum << endl;
    for (int i = 0; i < 10; i++)
        cout << data[i];
    return 0;
}