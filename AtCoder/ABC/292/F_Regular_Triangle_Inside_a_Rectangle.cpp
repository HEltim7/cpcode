#include <cmath>
#include <vector>
#include <iomanip>
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
constexpr LD eps=1e-15;
const LD pi=acos(LD(-1));

void solve() {
    LD x=pi/12;
    LD y=pi/6-x;
    LD z=pi/3-x;
    LD a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    if(b>=2*a/sqrt(3)) {
        LD h=a;
        LD ans=h*2/sqrt(3);
        cout<<ans;
    }
    else {
        LD l=0,r=pi/12;
        LD aim=a/b;
        while(abs(r-l)>eps) {
            LD mid=(l+r)/2;
            LD res=tan(mid)+tan(pi/3-mid);
            res/=(1+tan(pi/6-mid)*tan(pi/3-mid));
            if(res>aim) r=mid;
            else l=mid;
        }
        LD ans=b/cos(l);
        cout<<ans;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(20);
    solve();
    return 0;
}