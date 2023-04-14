#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef  __int128_t ll128;
const ld eps=1e-8;
int ts;
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif
ll exgcd(ll128 a,ll128 b,ll128 &x,ll128 &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    else
    {
        ll128 xl,yl;
        ll gcd=exgcd(b,a%b,xl,yl);
        x=yl;
        y=xl-(a/b)*yl;
        return gcd;
    }
}

ll lwy(ll a,ll b,ll p)//a*x=b (mod p)
{
    //ax-Qp=b;
    ll128 x;
    b=(b%p+p)%p;
    ll128 Q;
    ll d=exgcd(a,p,x,Q);
    x*=b;
    x%=p;
    return x;
}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>ts;
    while (ts--) {
        ll X1,Y1,X2,Y2;
        cin>>X1>>Y1>>X2>>Y2;
        if(X1==X2){
            cout<<X1+1<<" "<<Y1<<endl;
            continue;
        }
        if(Y1==Y2){
            cout<<X1<<" "<<Y1+1<<endl;
            continue;
        }
        ll n=Y2-Y1;
        ll m=X2-X1;
        ll t=__gcd(n,m);
        n/=t;
        m/=t;
        ll bn=Y1*m-n*X1;
        bn--;
        // ll bm=m;
        // ld b=bn*1.0/bm;
        // ld g=b*m;
        // debug(g);
        // ll l=-1e18,r=1e18;
        // while(l<r)
        // {
        //     ll mid=(l+r+1)>>1;
        //     if(mid<g-eps) l=mid;
        //     else r=mid-1;
        // }
        ll x=lwy(n,-bn,m);
        ll y=(n*x+bn)/m;
        cout<<x<<" "<<y<<endl;


    }

}