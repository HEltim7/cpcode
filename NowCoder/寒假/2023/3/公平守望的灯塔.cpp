#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr LD eps1=1e-9,eps2=1e-8;

void solve() {

    auto dis=[](LD x1,LD y1,LD x2,LD y2) {
        return sqrt((y1-y2)*(y1-y2)+(x1-x2)*(x1-x2));
    };

    LL x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    LD len=dis(x1,y1,x2,y2)/2;
    LD mx=LD(x1+x2)/2,my=LD(y1+y2)/2;

    auto equ=[](LD x) {
        debug(abs(x-round(x)));
        return abs(x-round(x))<eps2;
    };

    LD ansx=0,ansy=0;
    if(x1==x2) ansx=mx+len,ansy=my;
    else if(y1==y2) ansx=mx,ansy=my+len;
    else {
        LD k=LD(y2-y1)/LD(x2-x1);
        k=-1/k;
        LD b=my-k*mx;
        LD l=mx,r=mx+2e9;
        while(r-l>eps1) {
            LD mid=(l+r)/2;
            LD X=mid,Y=k*X+b;
            if(dis(mx,my,X,Y)>len) r=mid;
            else l=mid;
        }
        ansx=l,ansy=k*ansx+b;
    }

    debug(ansx,ansy);
    if(equ(ansx)&&equ(ansy)) cout<<LL(round(ansx))<<' '<<LL(round(ansy));
    else cout<<"No Answer!";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}