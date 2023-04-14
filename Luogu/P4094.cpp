#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10,M=20;
int root[N],pos[N];
int fa[N][M+1],dep[N]={1};
int n;

struct MergeSplitSegmentTree {

    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    constexpr static int MAX_SIZE=N*20*2;
    
    struct Node {
        int ch[2];
        int max;
    } tr[MAX_SIZE];
    int idx;

    int new_node() {
        assert(idx<MAX_SIZE);
        return ++idx;
    }

    void pushup(int u) {
        if(rch) tr[u].max=tr[rch].max;
        else if(lch) tr[u].max=tr[lch].max;
    }

    int merge(int x,int y) {
        if(!x||!y) return x|y;
        else {
            int u=new_node();
            lch=merge(tr[x].ch[0],tr[y].ch[0]);
            rch=merge(tr[x].ch[1],tr[y].ch[1]);
            pushup(u);
            return u;
        }
    }

    int query(int u,int l,int r,int L,int R) {
        if(l>=L&&r<=R) return tr[u].max;
        int mid=l+r>>1;
        int res=-1;
        if(mid>=L&&lch) res=max(res,query(lch, l, mid, L, R));
        if(mid<R&&rch) res=max(res,query(rch, mid+1, r, L, R));
        return res;
    }

    void build(int &u,int l,int r,int p) {
        u=new_node();
        if(l!=r) {
            int mid=l+r>>1;
            if(p<=mid) build(lch,l,mid,p);
            else build(rch,mid+1,r,p);
            pushup(u);
        }
        else tr[u].max=l;
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
        vector<int> adj;
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

    void get_lca(int u) {
        for(int v:edp[u].adj) {
            dep[v]=dep[u]+1;
            fa[v][0]=u;
            for(int i=1;i<=M;i++)
                fa[v][i]=fa[fa[v][i-1]][i-1];
            get_lca(v);
        }
    }

    void merge(int u) {
        for(int v:edp[u].adj) 
            merge(v),root[u]=sgt.merge(root[u], root[v]);
    }

    void build_with_sgt(string &s) {
        build(s);
        for(int i=1;i<size();i++) edp[edp[i].link].adj.push_back(i);
        for(int i=0,u=0;i<s.size();i++) {
            int c=s[i]-B;
            pos[i]=u=edp[u].ch[c];
            sgt.build(root[u], 0, n-1, i);
        }
        for(int v:edp[0].adj) merge(v);
        get_lca(0);
    }

    int match(int l,int r,int L,int R) {
        int u=pos[R],len=R-L+1;
        for(int i=M;i>=0;i--) 
            if(edp[fa[u][i]].len>=len) 
                u=fa[u][i];
        int t=sgt.query(root[u], 0, n-1, l+edp[edp[u].link].len, r);
        if(t!=-1) return min(t-l+1,len);
        for(int i=M;i>=0;i--) {
            int v=fa[u][i];
            if(v&&sgt.query(root[v], 0, n-1, l+edp[edp[v].link].len, r)==-1) u=v;
        }
        u=fa[u][0];
        t=sgt.query(root[u], 0, n-1, l, r);
        return min(edp[u].len,max(t-l+1,0));
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam;

void solve() {
    int m;
    string s;
    cin>>n>>m>>s;
    reverse(s.begin(), s.end());
    sam.build_with_sgt(s);
    while(m--) {
        vector<int> arr(4);
        for(int i=0;i<4;i++) {
            cin>>arr[i];
            arr[i]=n-arr[i];
        }
        cout<<sam.match(arr[1], arr[0], arr[3], arr[2])<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}