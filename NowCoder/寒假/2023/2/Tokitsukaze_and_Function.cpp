#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL n,l,r;
    cin>>n>>l>>r;
    auto f=[&](LL x) { return n/x+x-1; };

    LL mid=ceil(sqrt(n));
    mid=max(mid,l);
    mid=min(mid,r);
    auto v=vector<pair<LL,LL>> {
        make_pair(f(l), l),
        make_pair(f(r), r),
        make_pair(f(mid), mid)
    };
    sort(v.begin(),v.end());

    LL ans=v.begin()->second;
    LL L=l,R=mid;
    while(L<R) {
        LL M=(L+R)/2;
        if(f(M)<=f(ans)) R=M,ans=M;
        else L=M+1;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}