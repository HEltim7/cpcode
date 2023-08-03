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

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
vector<pair<int,int>> adj[N];
int k[N],w[N];



int root[N];
struct MergeableSegmentTree {
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    constexpr static int MAX_SIZE=N*20;
    
    struct Node {
        int ch[2];
        int cnt;
    } tr[MAX_SIZE];
    int idx;

    int new_node() {
        tr[++idx]={};
        return idx;
    }

    void pushup(int u) {
        if(lch&&rch) tr[u].cnt=tr[lch].cnt+tr[rch].cnt;
        else if(lch) tr[u].cnt=tr[lch].cnt;
        else if(rch) tr[u].cnt=tr[rch].cnt;
    }
    
    void merge(int &u,int v) {
        if(!u&&!v) return;
        if(!u||!v) u=u|v;
        else {
            merge(lch,tr[v].ch[0]);
            merge(rch,tr[v].ch[1]);
            if(!lch&&!rch) tr[u].cnt+=tr[v].cnt;
            else pushup(u);
        }
    }

    void build(int &u,int l,int r,int p) {
        u=new_node();
        if(l==r) ;
        else {
            int mid=l+r>>1;
            if(p<=mid) build(lch,l,mid,p);
            else build(rch,mid+1,r,p);
            pushup(u);
        }
    }

    #undef lch
    #undef rch
} sgt;

void solve() {
    int n;
    cin>>n;
    vector<int> num;
    for(int i=1;i<=n;i++) cin>>w[i],num.emplace_back(w[i]);
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v>>k[i];
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
        num.emplace_back(k[i]);
    }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        w[i]=lower_bound(num.begin(),num.end(),w[i])-num.begin();
    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}