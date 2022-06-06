#include<iostream>
#include <stdio.h>
using namespace std;

int month1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int isly[2048] = {0};
int main()
{
    int y,day=0,i,flag=0,week,a;
    cin>>y;
    if (y<1998)
    {
        i=y;
        y=1998;
        flag=1; 
    }
    
    for (; i < y; i++)
    {
        if (isly[i])
        {
            day+=366;
        }
        else
        {
            day+=365;
        }
    }
    
    a=day%7+4;
    if (a>7)
    {
        a=a%7;
    }
    
    if (isly[y])
    {
        
    }
    
}

void leap(int y)
{
    for (y; y <= 2048; y++)
    {
        if (y % 4 == 0 && y % 100 != 0)
            isly[y] = 1;
        else if (y % 400 == 0 && y % 3200 != 0)
            isly[y] = 1;
    }
}