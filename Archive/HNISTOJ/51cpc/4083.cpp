#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double salary;
    cin >> salary;
    if (salary < 1000)
    {
        printf("%.2f", salary);
        return 0;
    }
    else if (salary < 2000)
    {
        printf("%.2f", salary * 0.9);
        return 0;
    }
    else if (salary < 3000)
    {
        printf("%.2f", salary * 0.85);
        return 0;
    }
    else if (salary < 4000)
    {
        printf("%.2f", salary * 0.8);
        return 0;
    }
    else
    {
        printf("%.2f", salary * 0.75);
        return 0;
    }
}