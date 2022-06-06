#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int price, op;
    double off;
    cin >> price >> off;
    op = (price * off / 10) + 5 - ((int)(price * off / 10 + 5) % 10);
    printf("%d", op - op % 10);
    return 0;
}