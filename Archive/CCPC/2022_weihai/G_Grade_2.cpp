#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long ll;
const int N=5000006;

int pian;
int h;
ll f[N];
ll s[N];
bool F(ll k,ll x)
{
    return __gcd((k*x)^x,x)==1;
}
ll S(ll idx)
{
    if(idx<=h-1) return f[idx];
    ll res=f[h-1];
    idx-=h-1;

    res+=idx/h*s[h]+s[idx%h];
    return res;
}
int main()
{
    int x,n;
    scanf("%d%d",&x,&n);

    
    for(int i=0;i<30;i++)
    {
        if((1<<i)>x)
        {
            h=(1<<i);
            break;
        }
    }
    for(int i=1;i<=h-1;i++)
    {
        if(F(i,x)) f[i]=f[i-1]+1;
        else f[i]=f[i-1];
    }
    
    for(int i=h;i<=h+h-1;i++)
    {
        int t=i-(h-1);
        if(F(i,x)) s[t]=s[t-1]+1;
        else s[t]=s[t-1];
    }
    while(n--)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        ll res=S(r)-S(l-1);
        printf("%lld\n",res);
    }
}