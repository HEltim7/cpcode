//fuck this 9052

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
    int search, clock = 2;
    cin >> search;
    int begin = 0, end = size - 1, mini = end;
    if (data[end] < search)
    {
        cout << "NO";
        return 0;
    }

    for (;;)
    {
        if (data[(begin + end) / 2] >= search)
        {
            end = (begin + end) / 2;
            mini = end;
        }
        else if (data[(begin + end) / 2] <= search)
        {
            begin = (begin + end) / 2;
        }
        if (begin == (begin + end) / 2 || end == (begin + end) / 2)
        {
            clock--;
            if (clock == 0)
            {
                break;
            }
        }
    }
    cout << mini + 1;
    return 0;
}

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
    int search, clock = 2;
    cin >> search;
    int begin = 0, end = size - 1, mini = -1, min = 10000;

    for (int i = size - 1; i >= 0; i--)
    {
        if (data[i] >= search)
        {
            if (data[i] <= min)
            {
                min = data[i];
                mini = i;
            }
        }
    }

    if (mini == -1)
    {
        cout << "NO";
        return 0;
    }
    cout << mini + 1;
    return 0;
}