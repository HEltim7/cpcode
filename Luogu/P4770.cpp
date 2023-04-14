#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
int root[N],n;
vector<int> adj[N];

struct MergeSplitSegmentTree {

    #define lch tr[u].l
    #define rch tr[u].r
    constexpr static int MAX_SIZE=N*40;
    
    struct Node {
        int l,r;
    } tr[MAX_SIZE];
    int idx;

    int new_node() { return ++idx; }

    int merge(int x,int y) {
        if(!x||!y) return x|y;
        int u=new_node();
        lch=merge(tr[x].l,tr[y].l);
        rch=merge(tr[x].r,tr[y].r);
        return u;
    }

    bool __query(int u,int l,int r,int L,int R) {
        if(l>=L&&r<=R) return 1;
        int mid=l+r>>1;
        bool res=0;
        if(lch&&mid>=L) res|=__query(lch, l, mid, L, R);
        if(rch&&mid<R) res|=__query(rch, mid+1, r, L, R);
        return res;
    }

    bool query(int u,int L,int R) {
        return L<=R&&__query(u, 1, n, L, R);
    }

    void build(int &u,int l,int r,int p) {
        u=new_node();
        if(l!=r) {
            int mid=l+r>>1;
            if(p<=mid) build(lch,l,mid,p);
            else build(rch,mid+1,r,p);
        }
    }

    #undef lch
    #undef rch

} sgt;

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len;
        int ch[A];
        bool mark;
    };
    vector<Endpos> edp;
    int last=0;

    int new_node() {
        edp.push_back({});
        return edp.size()-1;
    }

    void extend(char x) {
        int c=x-B;
        int p=last;
        int cur=last=new_node();
        edp[cur].len=edp[p].len+1;
        while(p!=-1) {
            if(!edp[p].ch[c]) edp[p].ch[c]=cur;
            else {
                int q=edp[p].ch[c];
                if(edp[p].len+1==edp[q].len) edp[cur].link=q;
                else {
                    int clone=new_node();
                    edp[clone]=edp[q];
                    edp[clone].len=edp[p].len+1; 
                    edp[cur].link=edp[q].link=clone;
                    for(;p!=-1&&edp[p].ch[c]==q;p=edp[p].link) 
                        edp[p].ch[c]=clone;
                }
                break;
            }
            p=edp[p].link;
        }
    }

    void merge(int u) {
        for(int v:adj[u]) 
            merge(v),root[u]=sgt.merge(root[u], root[v]);
    }

    void build_with_sgt(string &s) {
        build(s);
        for(int u=0,i=0;i<s.size();i++) {
            int c=s[i]-B;
            u=edp[u].ch[c];
            sgt.build(root[u], 1, n, i+1);
        }
        for(int i=1;i<size();i++) adj[edp[i].link].push_back(i);
        for(int v:adj[0]) merge(v);
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N),cur(N);

LL count(string &str,int L,int R) {
    cur.clear();
    cur.build(str);
    int u=0,v=0,len=0,tot=0;
    LL res=0;
    auto &s=sam.edp,&t=cur.edp;
    for(char x:str) {
        int c=x-SuffixAutomaton::B;
        tot++;
        while(u&&(!s[u].ch[c]||!sgt.query(root[s[u].ch[c]], L+len, R)))
            if(--len==s[s[u].link].len) u=s[u].link,len=s[u].len;
        if(s[u].ch[c]&&sgt.query(root[s[u].ch[c]], L+len, R)) 
            u=s[u].ch[c],len++;

        v=t[v].ch[c];
        int p=v;
        while(p&&!t[p].mark) t[p].mark=1,p=t[p].link;
        res+=tot-max(len,t[p].len);
    }
    return res;
}

void solve() {
    int q;
    string s;
    cin>>s>>q;
    n=s.size();
    sam.build_with_sgt(s);
    while(q--) {
        int l,r;
        cin>>s>>l>>r;
        cout<<count(s,l,r)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}