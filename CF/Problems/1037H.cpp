#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int root[N];

struct MergeSplitSegmentTree {

    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    constexpr static int MAX_SIZE=N*40;
    
    struct Node {
        int ch[2];
    } tr[MAX_SIZE];
    int idx;

    int new_node() { return ++idx; }
    
    int merge(int u,int v) {
        if(!u||!v) return u|v;
        else {
            int w=new_node();
            tr[w].ch[0]=merge(lch,tr[v].ch[0]);
            tr[w].ch[1]=merge(rch,tr[v].ch[1]);
            return w;
        }
    }

    bool __query(int u,int l,int r,int L,int R) {
        if(l>=L&&r<=R) return 1;
        int mid=l+r>>1;
        bool res=0;
        if(lch&&mid>=L) res|=__query(lch, l, mid, L, R);
        if(rch&&mid<R) res|=__query(rch, mid+1, r, L, R);
        return res;
    }

    bool query(int u,int l,int r,int L,int R) {
        return L<=R&&__query(u, l, r, L, R);
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

int n;
vector<int> adj[N];
struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len;
        int ch[A];
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
        for(int v:adj[u]) merge(v),root[u]=sgt.merge(root[u], root[v]);
    }

    void build(string &s) {
        for(char x:s) extend(x);
        n=s.size();
        int u=0,len=0;
        for(char x:s) {
            int c=x-B;
            u=edp[u].ch[c];
            len++;
            sgt.build(root[u], 1, n, len);
        }
        for(int i=1;i<size();i++) adj[edp[i].link].push_back(i);
        for(int v:adj[0]) merge(v);
    }

    string match(string &s,int L,int R) {
        s.push_back('a'-1);
        vector<int> stk(1);
        string res;
        int len,u;
        for(len=u=0;len<s.size();len++) {
            int c=s[len]-B;
            bool fail=0;
            if(s[len]=='a'-1||!edp[u].ch[c]) fail=1;
            else fail=!sgt.query(root[edp[u].ch[c]], 1, n, L+len, R);
            if(fail) break;
            u=edp[u].ch[c];
            stk.push_back(u);
            res.push_back(s[len]);
        }
        
        while(stk.size()) {
            u=stk.back();
            for(int c=s[len]+1-B;c<26;c++) {
                int v=edp[u].ch[c];
                if(v&&sgt.query(root[v], 1, n, L+len, R)) {
                    res.push_back(c+B);
                    return res;
                }
            }
            stk.pop_back();
            if(res.size()) res.pop_back();
            len--;
        }
        return "-1";
    }

    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N);

void solve() {
    int q;
    string s;
    cin>>s>>q;
    sam.build(s);
    while(q--) {
        int l,r;
        cin>>l>>r>>s;
        cout<<sam.match(s, l, r)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}