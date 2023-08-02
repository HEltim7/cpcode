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
using T=tuple<LL,LL,bool>;
using PLL=pair<LL,LL>;
constexpr int N=5e4+10;
vector<pair<LL,int>> val[N];
vector<int> pre[N];
map<LL,int> same_cnt;
map<T,int> vid;
int ans[N];

void solve() {
    int n,q;
    cin>>n>>q;

    vector<PLL> arr(n),qry;
    for(auto &[x,y]:arr) cin>>x>>y;

    auto get=[&](LL a,LL b) {
        if(a>=b) return pair{T{b,a%b,true},a/b};
        return pair{T{a,b%a,false},b/a};
    };

    for(int i=1;i<=q;i++) {
        LL a,b;
        cin>>a>>b;
        qry.emplace_back(a,b);
        if(a==b) continue;
        auto [t,v]=get(a,b);
        auto it=vid.find(t);
        if(it==vid.end()) it=vid.emplace(t,i).first;
        int id=it->second;
        val[id].emplace_back(v,i);
    }

    for(int i=1;i<=q;i++) {
        sort(val[i].begin(),val[i].end());
        pre[i].resize(val[i].size()+1);
    }
    for(auto [a,b]:arr) {
        while(a&&b) {
            if(max(a,b)%min(a,b)==0) same_cnt[min(a,b)]++;
            auto [t,r]=get(a,b);
            auto it=vid.find(t);
            if(it!=vid.end()) {
                int id=it->second;
                LL l=1;
                auto lit=lower_bound(val[id].begin(),val[id].end(),pair{l,-1});
                auto rit=lower_bound(val[id].begin(),val[id].end(),pair{r+1,-1});
                pre[id][lit-val[id].begin()]++;
                pre[id][rit-val[id].begin()]--;
            }
            
            if(a>=b) a%=b;
            else b%=a;
        }
    }

    for(int i=1;i<=q;i++) {
        partial_sum(pre[i].begin(),pre[i].end(),pre[i].begin());
        for(int j=0;j<val[i].size();j++) {
            ans[val[i][j].second]=pre[i][j];
        }
    }

    for(int i=1;i<=qry.size();i++) {
        auto [a,b]=qry[i-1];
        if(a!=b) continue;
        auto it=same_cnt.find(a);
        if(it!=same_cnt.end()) ans[i]+=it->second;
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;

    for(int i=1;i<=q;i++) ans[i]=0;
    same_cnt.clear();
    vid.clear();
    for(int i=1;i<=q;i++) pre[i].clear(),val[i].clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}