#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int M=1e6+10;
int trie_id[M];
int label[M],label_end[M],label_idx;
int change[M];

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
Fenwick<int> fen(0);

struct ACAM {
    const static int A=26;
    const static char start='a';
    struct NODE {
        int cnt,next;
        int ch[A];
        vector<int> adj;
    };

    vector<NODE> tr;
    int idx=0;

    int new_node() {
        tr.push_back({});
        return ++idx;
    }

    int insert(string &s) {
        int root=0;
        for(auto x:s) {
            int c=x-start;
            if(!tr[root].ch[c]) 
                tr[root].ch[c]=new_node();
            root=tr[root].ch[c];
        }
        tr[root].cnt++;
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
                int pre=tr[tr[root].next].ch[i];
                if(!cur) cur=pre;
                else {
                    tr[cur].next=pre;
                    tr[pre].adj.push_back(cur);
                    q.push(cur);
                }
            }
        }
    }

    void relable(int u) {
        label[u]=label_end[u]=++label_idx;
        for(int v:tr[u].adj)
            relable(v),
            label_end[u]=max(label_end[u],label_end[v]);
        if(tr[u].cnt) {
            fen.add(label[u],tr[u].cnt);
            fen.add(label_end[u]+1,-tr[u].cnt);
        }
    }

    void modify(int u,int val) {
        u=trie_id[u];
        if(change[u]!=val) {
            fen.add(label[u],val?-1:1);
            fen.add(label_end[u]+1,val?1:-1);
            change[u]=val;
        }
    }
    
    LL match(string &s) {
        int j=0;
        LL ans=0;
        for(auto x:s) {
            int c=x-start;
            j=tr[j].ch[c];
            ans+=fen.query(label[j]);
        }
        return ans;
    }

    int size() { return idx; }

    ACAM() { tr.resize(1); }
    ACAM(int sz) { tr.reserve(sz); }
};

void solve() {
    int n,k;
    cin>>n>>k;
    ACAM acam;
    for(int i=1;i<=k;i++) {
        string in;
        cin>>in;
        trie_id[i]=acam.insert(in);
    }
    acam.build();
    fen=Fenwick<int>(acam.size()+10);
    acam.relable(0);
    while(n--) {
        char op;
        cin>>op;
        if(op=='?') {
            string s;
            cin>>s;
            cout<<acam.match(s)<<endl;
        }
        else {
            int id;
            cin>>id;
            acam.modify(id,op=='+'?0:1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}