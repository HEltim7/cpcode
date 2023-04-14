#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LLL=__int128;

LL next_floor(LL k,LL i) {
    return k/(k/i);
}

LL next_ceil(LL k,LL i) {
    if(k-1<i) return i;
    return (k-1)/((k-1)/i);
}

void solve() {
    LL n,m;
    cin>>n>>m;
    if(LLL(n)*n<m) {
        cout<<-1<<endl;
        return;
    }
    if(m<=n) {
        cout<<m<<endl;
        return;
    }

    auto div=[&](LL x,LL y) {
        return (x+y-1)/y;
    };

    LL ans=9e18;
    for(LL l=div(m,n),r=div(m,l);l<=r;) {
        ans=min(ans,l*r);
        l=next_ceil(m, l)+1;
        r=div(m,l);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}