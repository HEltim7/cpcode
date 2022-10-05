#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int b[N],a[N];
vector<int> pos[N];

void solve() {
    int n;
    int zero=1;
    cin>>n;
    for(int i=0;i<=n+1;i++) pos[i].clear();
    vector<pair<int,int>> bp;
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        bp.push_back({b[i],i});
        pos[b[i]].push_back(i);
        if(b[i]!=0) zero=0;
    }
    if(zero) {
        cout<<0<<endl;
        for(int i=1;i<=n;i++) cout<<i<<" \n"[i==n];
        return;
    }
    sort(bp.begin(),bp.end());
    vector<int> dif;
    for(int i=0;i<n;i++) 
        if(i==0||bp[i].first!=bp[i-1].first) 
            dif.push_back(bp[i].first);

    int cur,k=1;
    if(pos[0].size()) cur=0;
    else cur=n+1;
    for(int i=0,idx=1,state=cur!=0;i<dif.size();i++,state^=1) {
        int end=idx+pos[cur].size()-1;
        for(auto x:pos[cur]) {
            if(state) k=max(k,x);
            if(pos[x].size()) a[end]=x;
            else a[idx++]=x;
        }
        cur=a[end];
        idx=end+1;
    }
    cout<<k<<endl;
    for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}