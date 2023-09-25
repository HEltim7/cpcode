#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    map<int,vector<int>> cnt;
    auto st=vector(n,vector<int>());
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) {
            int in;
            cin>>in;
            st[i].emplace_back(in);
            cnt[in].emplace_back(i);
        }
    }

    int ans=0;
    for(auto [_,v]:cnt) {
        set<int> s;
        for(int i=0;i<n;i++) {
            if(!binary_search(v.begin(),v.end(),i)) {
                for(int x:st[i]) s.insert(x);
            }
        }
        ans=max(ans,int(s.size()));
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}