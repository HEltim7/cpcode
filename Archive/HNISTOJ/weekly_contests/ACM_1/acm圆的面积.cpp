#include <iostream>
#include <stdio.h>
using namespace std;
#define PI 3.14159265358979323846

int main()
{
    double r;
    cin >> r;
    printf("%.7lf", r * r * PI);
    return 0;
}