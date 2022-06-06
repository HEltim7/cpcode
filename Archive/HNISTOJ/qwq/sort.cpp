#include<iostream>
#include<algorithm>
using namespace std;
// int data[100];

struct mark
{
    string str;
    int data;
}a[10];

bool cmp(mark a,mark b)
{
    return a.data>b.data;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin>>a[i].data;
    }
    sort(a,a+10,cmp);
    for (int i = 0; i < 10; i++)
    {
        cout<<a[i].data<<' ';
    }
    return 0;
}