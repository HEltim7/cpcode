#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int ans[N],st[N],sz[N],idx;

void solve() {
    int n,k;
    cin>>n>>k;
    memset(ans, -1, sizeof ans);
    map<int,int> mp;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        auto it=mp.lower_bound(in);
        if(it==mp.end()) mp.emplace(in,++idx),sz[idx]=1,st[in]=idx;
        else {
            int id=it->second;
            mp.erase(it);
            mp.emplace(in,id);
            st[in]=id,sz[id]++;
        }
        int id=mp[in];
        if(sz[id]==k) ans[id]=i,mp.erase(in);
    }
    for(int i=1;i<=n;i++) cout<<ans[st[i]]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}