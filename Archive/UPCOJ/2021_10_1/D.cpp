#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
const int N=2000005;
ll a[N];
ll g[N];
ll sum;
ll jishu;
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        g[a[i]]++;
    }

    for(int i=0;i<1000000;i++)
    {
        g[i+1]+=g[i]/2;
        g[i]=g[i]%2;

        if(g[i]==1)
        jishu++;
    }
    // for(int i=0;i<=6;i++)
    // printf("%d ",g[i]);
    if(n==1)
    puts("N");
    else if(jishu==2||jishu==1)
    puts("Y");
    else
    puts("N");
    

}