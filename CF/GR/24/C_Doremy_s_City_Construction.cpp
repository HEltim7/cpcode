#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        mp[in]++;
    }
    int t=mp.size();
    vector<int> arr(1),pre(t+2),suf(t+2);
    for(auto [x,y]:mp) arr.push_back(y);
    for(int i=1;i<=t;i++) pre[i]=pre[i-1]+arr[i];
    for(int i=t;i>=1;i--) suf[i]=suf[i+1]+arr[i];
    if(t==1) cout<<n/2<<endl;
    else {
        LL ans=0;
        for(int i=1;i<t;i++) ans=max(ans,1LL*pre[i]*suf[i+1]);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}