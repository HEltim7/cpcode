#include <set>
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
using LLL=__int128;
using LD=long double;
constexpr int N=1e3;
constexpr LL INF=2e18;

void solve() {
    LL n;
    cin>>n;
    set<LL> st;
    for(int i=2;i<=min(n,1LL*N);i++) {
        bool flag=1;
        LL t=n;
        while(t) {
            if(t%i>=2) flag=0;
            t/=i;
        }
        if(flag) st.insert(i);
    }

    for(int i=1;i<1<<6;i++) {
        LL l=N,r=LL(1e18);

        auto cal=[&](LL mid) {
            LL sum=0;
            LL base=1;
            LD sumd=0;
            LD based=1;
            for(int j=0;j<6;j++) {
                if(i>>j&1) sum+=base,sumd+=based;
                base*=mid;
                based*=mid;
            }
            if(sumd>INF) return INF;
            return sum;
        };

        while(l<r) {
            LL mid=l+r>>1;
            LL sum=cal(mid);
            if(sum==n) {
                l=r=mid;
                break;
            }
            if(sum>n) r=mid-1;
            else l=mid+1;
        }

        if(cal(l)==n) st.insert(l);
    }

    debug(st);
    cout<<st.size()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}