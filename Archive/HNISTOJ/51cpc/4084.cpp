#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int term;
    double highth;
    cin>>highth>>term;
    int sum=highth;
    for (int i = 0; i < term; i++)
    {
        highth/=4;
        sum+=highth*2;
    }
    cout<<sum<<endl<<highth;
    return 0;
}