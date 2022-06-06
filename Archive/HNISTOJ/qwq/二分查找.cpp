#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int data[size];
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }
    int search;
    cin >> search;
    int begin = 0, end = size - 1;
    while (data[(begin + end) / 2] != search)
    {
        if (begin == (begin + end) / 2 || end == (begin + end) / 2)
        {
            cout << "NO";
            return 0;
        }
        if (data[(begin + end) / 2] > search)
        {
            end = (begin + end) / 2;
        }
        else if (data[(begin + end) / 2] < search)
        {
            begin = (begin + end) / 2;
        }
    }
    cout << (begin + end) / 2 + 1;
    return 0;
}