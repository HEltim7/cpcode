#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
using TIII=tuple<int,int,int>;
const int N=1e5+10;

int label[N],label_end[N];
int trie_id[N];
int ans[N];
int label_idx;
vector<PII> querys[N];

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
Fenwick<int> fen(N);

struct ACAM {
    const static int A=26;
    const static char start='a';
    struct NODE {
        int next,p;
        int ch[A];
    };

    vector<NODE> trie;
    vector<int> fail_adj[N];
    int idx=0;

    int new_node() {
        trie.push_back({});
        return ++idx;
    }

    void insert(string &s) {
        int id=0,root=0;
        for(auto x:s) {
            if(x=='P') trie_id[++id]=root;
            else if(x=='B') root=trie[root].p;
            else {
                int c=x-start;
                if(!trie[root].ch[c]) {
                    trie[root].ch[c]=new_node();
                    trie[trie[root].ch[c]].p=root;
                }
                root=trie[root].ch[c];
            }
        }
    }

    void build() {
        queue<int> q;
        for(int i=0;i<A;i++) 
            if(trie[0].ch[i]) {
                q.push(trie[0].ch[i]);
                fail_adj[0].push_back(trie[0].ch[i]);
            }
        while(q.size()) {
            auto root=q.front();
            q.pop();
            for(int i=0;i<A;i++) {
                int &cur=trie[root].ch[i];
                if(!cur) continue;
                int j=trie[root].next;
                while(j&&!trie[j].ch[i]) j=trie[j].next;
                if(trie[j].ch[i]) j=trie[j].ch[i];
                trie[cur].next=j;
                fail_adj[j].push_back(cur);
                q.push(cur);
            }
        }
    }

    void relable(int u) {
        label[u]=label_end[u]=++label_idx;
        for(int v:fail_adj[u]) 
            relable(v),
            label_end[u]=max(label_end[u],label_end[v]);
    }

    void match(int u) {
        fen.add(label[u],1);
        for(auto [v,id]:querys[u]) {
            int tot=fen.query(label_end[v]);
            int pre=fen.query(label[v]-1);
            ans[id]=tot-pre;
        }
        for(int i=0;i<A;i++) 
            if(trie[u].ch[i]) match(trie[u].ch[i]);
        fen.add(label[u],-1);
    }
    
    int size() { return idx; }

    ACAM() { trie.resize(1); }
    ACAM(int sz) { trie.reserve(sz); }
};

void solve() {
    ACAM acam;
    string txt;
    cin>>txt;
    acam.insert(txt);
    acam.build();
    acam.relable(0);
    int m;
    cin>>m;
    for(int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        querys[trie_id[b]].emplace_back(trie_id[a],i);
    }
    acam.match(0);
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}