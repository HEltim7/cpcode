#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=1e6+10;
vector<PII> querys[N];
int trie_id[N],ans[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

template<typename T> 
struct Fenwick {
    std::vector<T> tr;
    int sz=0;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,T &val) {
        aim+=val;
    }

    void add(int pos,T val) {
        assert(pos>0);
        while(pos<=sz) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=0;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int n) { tr.resize(sz=n+1); }
};
Fenwick<int> fen(N);

struct ACAM {
    const static int A=26;
    const static char start='a';
    struct Node {
        int cnt,next;
        int ch[A];
        vector<int> adj;
    };

    vector<Node> tr;
    vector<int> label,label_end;
    int idx=0,label_idx=0;

    int new_node() {
        tr.push_back({});
        return ++idx;
    }

    int insert(int j,string &s) {
        int root=trie_id[j];
        for(auto x:s) {
            int c=x-start;
            if(!tr[root].ch[c]) 
                tr[root].ch[c]=new_node();
            root=tr[root].ch[c];
        }
        tr[root].cnt++;
        return root;
    }

    void relable(int u) {
        label[u]=label_end[u]=++label_idx;
        for(int v:tr[u].adj)
            relable(v),
            label_end[u]=max(label_end[u],label_end[v]);
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
                if(!cur) continue;
                int j=tr[root].next;
                while(j&&!tr[j].ch[i]) j=tr[j].next;
                if(tr[j].ch[i]) j=tr[j].ch[i];
                tr[cur].next=j;
                tr[j].adj.push_back(cur);
                q.push(cur);
            }
        }
        debug(this->size());
        label.resize(this->size());
        label_end.resize(this->size());
        this->relable(0);
    }

    void match(int u) {
        debug(u);
        fen.add(label[u],1);
        for(auto [v,id]:querys[u]) 
            ans[id]=fen.query(label_end[v])-fen.query(label[v]-1);
        for(int i=0;i<A;i++) if(tr[u].ch[i]) match(tr[u].ch[i]); 
        fen.add(label[u],-1);
    }

    int size() { return tr.size(); }

    ACAM() { tr.resize(1); }
    ACAM(int sz) { tr.reserve(sz+1),tr.push_back({}); }
};

void solve() {
    int n;
    cin>>n;
    ACAM acam;
    for(int i=1;i<=n;i++) {
        int op;
        cin>>op;
        if(op==1) {
            string c;
            cin>>c;
            trie_id[i]=acam.insert(0,c);
        }
        else {
            int j;
            string c;
            cin>>j>>c;
            trie_id[i]=acam.insert(j,c);
        }
    }
    int m;
    cin>>m;
    for(int i=n+1;i<=n+m;i++) {
        int t;
        string s;
        cin>>t>>s;
        querys[trie_id[t]].emplace_back(acam.insert(0,s),i-n);
    }
    acam.build();
    acam.match(0);
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}