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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int w[N],dn[N],up[N];
vector<int> adj[N];

template<typename I,int H=sizeof(I)*8-1-is_signed<I>()>
struct BinaryTrie {
    struct Node {
        int ch[2];
        int cnt;
    };
    vector<Node> tr;

    int new_node() {
        tr.push_back({});
        return tr.size()-1;
    }

    void insert(int v) {
        for(int i=H,u=0;i>=0;i--) {
            bool x=v>>i&1;
            if(!tr[u].ch[x]) tr[u].ch[x]=new_node();
            u=tr[u].ch[x];
            tr[u].cnt++;
        }
    }

    void erase(int v) {
        for(int i=H,u=0;i>=0;i--) {
            bool x=v>>i&1;
            u=tr[u].ch[x];
            tr[u].cnt--;
        }
    }

    I xor_max(int v) {
        I res{};
        for(int i=H,u=0;i>=0;i--) {
            bool x=v>>i&1^1;
            if(tr[tr[u].ch[x]].cnt) {
                res|=1<<i;
                u=tr[u].ch[x];
            }
            else u=tr[u].ch[x^1];
        }
        return res;
    }

    I xor_min(int v) {
        I res{};
        for(int i=H,u=0;i>=0;i--) {
            bool x=v>>i&1;
            if(tr[tr[u].ch[x]].cnt) u=tr[u].ch[x];
            else {
                res|=1<<i;
                u=tr[u].ch[x^1];
            }
        }
        return res;
    }

    void clear() {
        tr.clear();
        new_node();
    }

    explicit BinaryTrie(int size=0) {
        tr.reserve(size*(H+1));
        clear();
    }
};
BinaryTrie<int> tr;

namespace dsu {
    int id[N],ed[N],ori[N],sz[N],hch[N],idx;

    void init(int u,int fa) {
        sz[u]=1;
        id[u]=++idx;
        ori[id[u]]=u;
        for(int v:adj[u]) {
            if(v!=fa) {
                init(v,u);
                if(sz[v]>sz[hch[u]]) hch[u]=v;
                sz[u]+=sz[v];
            }
        }
        ed[u]=idx;
    }

    void solve_dn(int u,int fa,bool keep) {
        auto add=[&](int id) {
            int x=ori[id];
            dn[u]=max(dn[u],tr.xor_max(w[x]));
            tr.insert(w[x]);
        };

        auto del=[](int id) {
            int x=ori[id];
            tr.erase(w[x]);
        };
        
        for(int v:adj[u]) if(v!=fa&&v!=hch[u]) solve_dn(v,u,0);
        if(hch[u]) solve_dn(hch[u],u,1),dn[u]=dn[hch[u]];
        for(int v:adj[u]) 
            if(v!=fa&&v!=hch[u]) 
                for(int i=id[v];i<=ed[v];i++) add(i);
        add(id[u]);

        if(!keep) for(int i=id[u];i<=ed[u];i++) del(i);
    }

    void solve_up(int u,int fa,int x) {
        if(u==x) return;
        int res=up[u];
        auto add=[&](int id) {
            int x=ori[id];
            res=max(res,tr.xor_max(w[x]));
            tr.insert(w[x]);
        };

        auto del=[](int id) {
            int x=ori[id];
            tr.erase(w[x]);
        };

        int ne=-1;
        for(int v:adj[u]) {
            if(v!=fa) {
                int l=id[v],r=ed[v];
                if(id[x]>=l&&id[x]<=r) ne=v;
                else for(int i=l;i<=r;i++) add(i);
            }
        }
        add(id[u]);
        up[ne]=max(up[ne],res);
        
        solve_up(ne, u, x);
    }

    void clear(int n=N-1) {
        idx=0;
        fill(hch,hch+n+1,0);
        for(int i=0;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=1;i<=n;i++) cin>>w[i],mp[w[i]]=i;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dsu::init(1, 0);
    dsu::solve_dn(1, 0, 1);

    int x,y;
    for(int i=1;i<=n;i++) {
        int val=w[i]^dn[1];
        if(mp.find(val)!=mp.end()) {
            x=i;
            y=mp[val];
            break;
        }
    }

    for(int i=1;i<=n;i++) {
        int idx=dsu::id[x];
        int idy=dsu::id[y];
        int l=dsu::id[i],r=dsu::ed[i];
        if((idx<l||idx>r)&&(idy<l||idy>r)) up[i]=dn[1];
    }

    tr.clear();
    dsu::solve_up(1, 0, x);
    tr.clear();
    dsu::solve_up(1, 0, y);
    
    int ans=2e9;
    for(int i=1;i<=n;i++) ans=min(ans,abs(up[i]-dn[i]));
    cout<<ans<<endl;

    tr.clear();
    dsu::clear(n);
    for(int i=1;i<=n;i++) up[i]=dn[i]=0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}