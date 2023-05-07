#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr LL INF=2e9;

template<typename T> T exgcd(T a,T b,T &x,T &y) {
    if(!b) { x=1,y=0; return a; }
    T res=exgcd(b, a%b, x, y),t=x;
    x=y,y=t-(a/b)*y;
    return res;
}

void solve() {
    LL a,b,n,L,R;
    cin>>a>>b>>n>>L>>R;
    
    LL x,y;
    LL g=exgcd(a, b, x, y);
    if(n%g) {
        cout<<"NO"<<endl;
        return;
    }
    x*=n/g;
    y*=n/g;
    LL mvx=b/g;
    debug(x,y,g,mvx);

    LL l=-INF,r=INF;
    while(l<r) {
        LL mid=l+r>>1;
        LL res=x+mid*mvx;
        if(res>=L&&res<=R) {
            l=r=mid;
            break;
        }
        else if(res<L) l=mid+1;
        else r=mid-1;
    }
    LL res=x+l*mvx;
    if(res>=L&&res<=R) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}