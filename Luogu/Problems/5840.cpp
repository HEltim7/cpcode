#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e6+10;
int trie_id[N];

template<typename T> 
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

struct AhoCorasickAutomaton {
    const static int A=26,M=22;
    const static char start='a';
    struct Node {
        int link;
        int ch[A];
        vector<int> adj;
    };

    vector<Node> tr;
    vector<int> id,ed;
    Fenwick<int> fen=Fenwick<int>(N);
    int fa[N][M+1],dep[N];
    int sz=0,idx=0;

    int insert(string &s) {
        int root=0;
        for(auto x:s) {
            int c=x-start;
            if(!tr[root].ch[c]) 
                tr[root].ch[c]=new_node();
            root=tr[root].ch[c];
        }
        return root;
    }

    void build() {
        queue<int> q;
        for(int i=0;i<A;i++) 
            if(tr[0].ch[i]) {
                q.push(tr[0].ch[i]);
                tr[0].adj.push_back(tr[0].ch[i]);
            }
        while(q.size()) {
            auto root=q.front();
            q.pop();
            for(int i=0;i<A;i++) {
                int &cur=tr[root].ch[i];
                int pre=tr[tr[root].link].ch[i];
                if(!cur) cur=pre;
                else {
                    tr[cur].link=pre;
                    tr[pre].adj.push_back(cur);
                    q.push(cur);
                }
            }
        }

        id.resize(size());
        ed.resize(size());
        relabel(0);
        getlca(0, -1);
    }

    void relabel(int u) {
        id[u]=++idx;
        for(int v:tr[u].adj) relabel(v);
        ed[u]=idx;
    }

    void getlca(int u,int p){
        for(auto s:tr[u].adj){
            if(s==p) continue;
            dep[s]=dep[u]+1;
            fa[s][0]=u;
            for(int i=1;i<=M;i++)
                fa[s][i]=fa[fa[s][i-1]][i-1];
            getlca(s,u);
        }
    }
    
    int lca(int a,int b){
        if(dep[a]<dep[b]) swap(a,b);
        for(int k=M;~k;k--)
            if(dep[fa[a][k]]>=dep[b])
                a=fa[a][k];
        if(a==b) return a;
        for(int k=M;~k;k--)
            if(fa[a][k]!=fa[b][k])
                a=fa[a][k],b=fa[b][k];
        return fa[a][0];
    }

    void update(string &s) {
        int u=0;
        vector<pair<int,int>> pos;
        for(char c:s) {
            int v=c-start;
            u=tr[u].ch[v];
            fen.add(id[u], 1);
            pos.emplace_back(id[u],u);
        }
        sort(pos.begin(),pos.end());
        for(int i=1;i<pos.size();i++) {
            u=lca(pos[i].second,pos[i-1].second);
            fen.add(id[u], -1);
        }
    }
    
    int match(int u) {
        int tot=fen.query(ed[u]);
        int pre=fen.query(id[u]-1);
        return tot-pre;
    }

    int size() { return tr.size(); }
    int new_node() { tr.push_back({});return ++sz; }
    void clear() { tr.clear();tr.resize(1);sz=idx=0; }

    AhoCorasickAutomaton() { tr.resize(1); }
    AhoCorasickAutomaton(int sz) { tr.reserve(sz+1);tr.push_back({}); }
} acam;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string in;
        cin>>in;
        trie_id[i]=acam.insert(in);
    }
    acam.build();

    int m;
    cin>>m;
    while(m--) {
        int op;
        cin>>op;
        if(op==1) {
            string in;
            cin>>in;
            acam.update(in);
        }
        else {
            int in;
            cin>>in;
            cout<<acam.match(trie_id[in])<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}