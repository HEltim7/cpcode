#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
constexpr int N=2e5+10,H=30;
int arr[N];
LL pos[N][H];
vector<pair<int,LL>> ans;

void init(int n) {
    for(int i=1;i<=n;i++)
        memset(pos[i], 0, sizeof pos[i]);
    for(int b=0;b<H;b++) {
        auto mv=[&](int idx) {
            LL step=idx;
            pos[idx-1][b]=step;
            idx--;
            idx=idx%(n-1)+1;
            while(!pos[idx][b]) {
                step+=n;
                pos[idx][b]=step;
                idx=idx%(n-1)+1;
            }
        };
        for(int i=2;i<=n;i++) if(arr[i]>>b&1) pos[i-1][b]=i;
        for(int i=1;i<=n;i++) if(arr[i]>>b&1) mv(i);
    }

    ans.clear();
    ans.emplace_back(arr[1], 1);

    map<LL,int> mp;
    for(int i=1;i<n;i++) {
        mp.clear();
        for(int b=0;b<H;b++) {
            if(pos[i][b]) {
                mp[pos[i][b]]|=1<<b;
            }
        }
        debug(i,mp);
        for(int pre=0; auto [p,v]:mp) {
            ans.emplace_back(pre|=v,p);
        }
    }
}

void solve() {
    int n,q;
    cin>>n>>q;

    int sum=0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        sum|=arr[i];
    }

    if(n==1) {
        while(q--) {
            int in;
            cin>>in;
            if(in+1<=arr[1]) cout<<1<<endl;
            else cout<<-1<<endl;
        }
        return;
    }

    init(n);
    sort(ans.begin(),ans.end());
    LL sufmin=1e18;
    for(int i=1;i<=ans.size();i++) {
        auto &p=ans.end()[-i].second;
        sufmin=min(sufmin,p);
        p=min(p,sufmin);
    }
    debug(ans);

    while(q--) {
        int in;
        cin>>in;
        if(in+1>sum) cout<<-1<<endl;
        else {
            auto it=lower_bound(ans.begin(),ans.end(),pair{in+1,-1LL});
            assert(it!=ans.end());
            cout<<it->second<<endl;
        }
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