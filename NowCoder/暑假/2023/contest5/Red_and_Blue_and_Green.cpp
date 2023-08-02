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
using SEG=tuple<int,int,bool>;
constexpr int N=2e3+10;
SEG seg[N];
vector<int> adj[N];
map<pair<int,int>,bool> mp;
int ans[N];
bool isroot[N];

vector<int> get(int l,int r) {
    vector<int> arr(r-l+1);
    iota(arr.begin(), arr.end(), l);
    return arr;
};

void solve(int id,const vector<int> num) {
    int l,r;
    bool par;
    tie(l,r,par)=seg[id];
    debug(l,r,num);
    if(l==r) {
        ans[l]=num.front();
        return;
    }
    for(int i:adj[id]) par^=get<2>(seg[i]);

    auto split=[&](int L,int R) {
        vector<int> arr(R-L+1);
        for(int i=0;i<arr.size();i++)
            arr[i]=num[L-l+i];
        return arr;
    };

    if(par) {
        int id1=adj[id][0];
        int id2=adj[id][1];
        auto [L1,R1,P1]=seg[id1];
        auto [L2,R2,P2]=seg[id2];
        auto &&v1=split(L1,R1);
        auto &&v2=split(L2,R2);
        swap(v1.back(),v2.front());
        solve(id1, v1);
        solve(id2, v2);
        for(int i=2;i<adj[id].size();i++) {
            auto [L,R,P]=seg[adj[id][i]];
            solve(adj[id][i], split(L,R));
        }
    }
    else {
        for(int i=0;i<adj[id].size();i++) {
            auto [L,R,P]=seg[adj[id][i]];
            solve(adj[id][i], split(L,R));
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<bool> mark(n+1);
    for(int i=1;i<=m;i++) {
        auto &[l,r,x]=seg[i];
        cin>>l>>r>>x;
        auto it=mp.find({l,r});
        if(it==mp.end()) mp[{l,r}]=x;
        else if(it->second!=x) {
            cout<<-1<<endl;
            return;
        }
        if(l==r&&x) {
            cout<<-1<<endl;
            return;
        }
        for(int i=l;i<=r;i++) mark[i]=1;
    }
    for(int i=1;i<=n;i++) if(mark[i]&&mp.find({i,i})==mp.end()) seg[++m]={i,i,0};
    sort(seg+1,seg+1+m,[](SEG x,SEG y) {
        auto [l,r,_]=x;
        auto [L,R,__]=y;
        return r-l<R-L;
    });

    for(int i=1;i<=m;i++) {
        isroot[i]=1;
        auto [l,r,x]=seg[i];
        for(int j=i+1;j<=m;j++) {
            auto [a,b,y]=seg[j];
            if(a<=l&&b>=r) {
                adj[j].emplace_back(i);
                isroot[i]=0;
                break;
            }
        }
    }
    for(int i=1;i<=m;i++) {
        sort(adj[i].begin(),adj[i].end(),[](int x,int y) {
            return get<0>(seg[x])<get<0>(seg[y]);
        });
    }

    for(int i=1;i<=n;i++) ans[i]=i;
    for(int i=1;i<=m;i++) {
        if(isroot[i]) {
            auto [l,r,p]=seg[i];
            solve(i,get(l,r));
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}