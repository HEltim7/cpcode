#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII = pair<int,int>;
constexpr int N=1e5+10,M=1e4+10;

template<typename T=int> 
struct Fenwick {
    std::vector<T> tr;
    int sz=0;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,T &val) {
        aim+=val;
    }

    void add(int pos,T val) {
        while(pos<=sz) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=0;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int n) { tr.resize(sz=n+1); }
};

Fenwick<> fen(N);
vector<int> adj[N];
vector<PII> modify[M],query[M];
int ans[N],id[N],ed[N],idx;
bool mark[N];

void get_id(int u) {
    id[u]=++idx;
    for(int v:adj[u]) get_id(v);
    ed[u]=idx;
}

void solve(int x) {
    if(modify[x].empty()||query[x].empty()) return;
    auto &mod=modify[x],&que=query[x];
    int m=0,q=0;
    while(q<que.size()) {
        if(m<mod.size()&&mod[m].first<que[q].first) {
            auto [x,y]=mod[m];
            if(!mark[y]) fen.add(id[y],1);
            mark[y]=1;
            m++;
        }
        else {
            auto [x,y]=que[q];
            ans[x]=fen.query(ed[y])-fen.query(id[y]-1);
            q++;
        }
    }
    for(auto [x,y]:mod) if(mark[y]) mark[y]=0,fen.add(id[y],-1);
}

void solve() {
    int n,m;
    cin>>n;
    for(int i=2;i<=n;i++) {
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    get_id(1);

    cin>>m;
    vector<int> qid;
    for(int i=1;i<=m;i++) {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1) modify[y].emplace_back(i,x);
        else query[y].emplace_back(i,x),qid.push_back(i);
    }
    for(int i=1;i<M;i++) solve(i);
    for(int i:qid) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}