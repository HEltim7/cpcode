#include <iostream>
using namespace std;
int data[1000], avg;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
        avg += data[i];
    }
    cout << avg / n;
    return 0;
}