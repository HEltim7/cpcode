#include<iostream>
#include<string>
using namespace std;
struct man
{
    string id;
    int num;
}a[10][100];

int mian()
{
    int group;
    cin>>group;
    int n[group];
    for (int i = 0; i < group; i++)
    {
        cin>>n[i];
        for (int j=0;j<n[i];j++)
        {
            cin>>a[i][j].id>>a[i][j].num;
        }
    }
    
    for (;;)
    {
        /* code */
    }
    

    return 0;
}