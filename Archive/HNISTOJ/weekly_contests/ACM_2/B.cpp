#include <bits/stdc++.h>
using namespace std;
string data[3];

int main()
{
    getline(cin, data[0]);
    getline(cin, data[1]);
    getline(cin, data[2]);
    double sum = 0;
    int j;
    for (int i = 0; i < 3; i++)
    {
        bool flag = 0;
        for (j = 0; j < data[i].length() && !flag; j += 2)
        {
            switch (data[i][j])
            {
            case 'A':
                sum += 4;
                break;
            case 'B':
                sum += 3;
                break;
            case 'C':
                sum += 2;
                break;
            case 'D':
                sum += 1;
                break;
            case 'F':
                sum += 0;
                break;
            default:
                cout << "Unknown" << endl;
                flag = 1;
            }
        }
        if (!flag)
        {
            printf("%.2f\n", sum / (j / 2));
        }
        sum = 0;
    }
    return 0;
}