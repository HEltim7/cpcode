#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII = pair<LL,LL>;

void solve() {
    vector<PII> seg;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        LL x,r;
        cin>>x>>r;
        seg.emplace_back(x-r,x+r);
    }
    sort(seg.begin(),seg.end());
    LL ans=0;
    LL last=seg.front().second;
    for(int i=1;i<n;i++) {
        auto [l,r]=seg[i];
        ans+=max(0LL,l-last);
        last=max(last,r);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}