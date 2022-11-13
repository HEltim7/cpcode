#include<iostream>
#include<algorithm>
#include<string.h>
#include<set>
using namespace std;
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif
typedef long long ll;

const int N=300005,M=600005;
int a[N];
int r[N][2];
int tr[N];
int n,m;
char s[M];
int type[N];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int c)
{
    while(x<=n)
    {
        tr[x]+=c;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int res=0;
    while(x)
    {
        res+=tr[x];
        x-=lowbit(x);
    }
    return res;
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)
    {
        add(i,1);
    }

    ll res=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        r[i][0]=query(a[i]-1);
        r[i][1]=n-i-r[i][0];
        res+=r[i][0];//原本的逆序对
        // res[1]+=r[i][1];//reverse的逆序对
        add(a[i],-1);
    }
    int ty=1;
    scanf("%s",s+1);
    int id=1;
    ll sum=1ll*n*(n-1)/2;
    printf("%lld\n",res);
    for(int i=1;i<=m;i++)
    {
        if(s[i]=='R')
        {
            ty*=-1;
            id=id+ty;
            if(id==n+1) id=1;
            if(id==0) id=n;
            res=sum-res;
            printf("%lld",res%10);
        }
        else
        {
            res=res-(a[id]-1)+(n-a[id]);
            printf("%lld",res%10);
            id+=ty;
            if(id==n+1) id=1;
            if(id==0) id=n;
        }

        // debug(res);
    }

}