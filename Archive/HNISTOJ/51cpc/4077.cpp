#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a, b, c, sum = 0;
    cin >> a >> b >> c;
    sum = a + b + c;
    double d = sum * 1. / 3;
    cout << sum << endl;
    printf("%.2f", d);
    return 0;
}