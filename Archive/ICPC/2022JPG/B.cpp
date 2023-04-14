#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

const int N=102;
int a[N][N];
bool st[N*N];//这个数字是否出现过
int n,m;
int x=1,y=0;
int res;
void read()
{
    res++;
    if(x%2==1)
    {
        if(y==m)
        {
            x++;
            y=m;
        }
        else
        {
            y++;
        }
    }
    else if(x%2==0)
    {
        if(y==1)
        {
            x++;
            y=1;
        }
        else
        {
            y--;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    while(x<=n)
    {
        read();
        if(st[a[x][y]])
        {
            continue;
        }
        else
        {
            st[a[x][y]]=true;
            int num1=a[x][y];
            read();
            int num2=a[x][y];
            if(st[num2]&&num1!=num2) res++;
            else if(st[num2]&&num1==num2) continue;//无所谓
            else
            {
                st[num2]=true;
            }
        }
    }
    res--;
    printf("%d\n",res);
    
}