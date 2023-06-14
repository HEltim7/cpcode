#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
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

constexpr int N=2e5+10;
int arr[N];
vector<int> col[N];
vector<pair<int,int>> dif[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        col[i].clear();
        dif[i].clear();
    }
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        col[arr[i]].push_back(i);
    }


    multiset<int> seg;
    set<int> blk;
    seg.emplace(n);
    blk.insert(0);
    blk.insert(n+1);
    dif[n].emplace_back(1,1);

    for(int r=n;r>=1;r--) {
        int idx=n-r+1;
        for(int x:col[r]) {
            auto it=blk.upper_bound(x);
            int r=*it;
            int l=*--it;
            int len=r-l-1;
            int lenl=x-l-1;
            int lenr=r-x-1;
            blk.insert(x);
        
            dif[len].emplace_back(idx,-1);
            seg.erase(seg.find(len));
            if(lenl) seg.insert(lenl),dif[lenl].emplace_back(idx,1);
            if(lenr) seg.insert(lenr),dif[lenr].emplace_back(idx,1);
        }
    }

    map<int,LL,greater<>> mp;
    for(int i=1;i<=n;i++) debug(i,dif[i]);
    for(int i=1;i<=n;i++) {
        int idx=1,tot=0;
        dif[i].emplace_back(n+1,0);
        for(auto [pos,val]:dif[i]) {
            int len=pos-idx;
            if(tot) mp[i]+=1LL*tot*len;
            tot+=val;
            idx=pos;
        }
    }
    debug(mp);

    LL m;
    cin>>m;
    LL ans=m;
    
    for(auto [len,cnt]:mp) {
        LL t=(m+len-1)/len;
        t=min(t,cnt);
        ans-=t;
        m-=t*len;
        if(m<=0) break;
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