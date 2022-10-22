#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
const int N=1000006;
typedef long long ll;
ll f2[6];
ll res[11];
ll qmi(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%p;

        a=a*a%p;
        b>>=1;
    }
    return res;
}
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll y=1;y<=4;y++)
    {
        if(y==2)
        {
            f2[2]+=1*((n-y)/4+(n>=y));//z=1
            f2[4]+=(n-1)*((n-y)/4+(n>=y));//z=2~n
            
        }
        else
        for(ll z=1;z<=2;z++)
        {
            ll g=qmi(y,z,4);
            if(g==0) g=4;
            f2[g]+=((n-z)/2+(n>=z))*((n-y)/4+(n>=y));
        }
    }
    for(ll x=1;x<=10;x++)
    {
        for(ll g=1;g<=4;g++)
        {
            ll k=qmi(x,g,10);
            res[k]+=f2[g]*((n-x)/10+(n>=x));
        }
    }
    ll sum=0;
    for(int i=0;i<=9;i++)
    {
        printf("%lld ",res[i]);
        sum+=res[i];
    }
    // debug(sum);
}