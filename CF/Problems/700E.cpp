#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int dp[N*2];

int root[N*2];
struct MergeableSegmentTree {

    #define lch (tr[u].lc)
    #define rch (tr[u].rc)
    constexpr static int MAX_SIZE=N*80;
    constexpr static int pos_l=0,pos_r=N-1;
    
    struct Node {
        int lc,rc;
    } tr[MAX_SIZE];
    int idx;

    int new_node() { return ++idx; }

    int merge(int x,int y) {
        if(!x||!y) return x|y;
        int u=new_node();
        lch=merge(tr[x].lc,tr[y].lc);
        rch=merge(tr[x].rc,tr[y].rc);
        return u;
    }

    bool __query(int u,int l,int r,int ql,int qr) {
        if(l>=ql&&r<=qr) return 1;
        int mid=l+r>>1;
        int res=0;
        if(lch&&mid>=ql) if(__query(lch, l, mid, ql, qr)) return 1;
        if(rch&&mid<qr) if(__query(rch, mid+1, r, ql, qr)) return 1;
        return 0;
    }

    bool query(int u,int ql,int qr) {
        if(ql>qr) return 0;
        return __query(u, pos_l, pos_r, ql, qr);
    }

    void __build(int &u,int l,int r,int p) {
        u=new_node();
        if(l!=r) {
            int mid=l+r>>1;
            if(p<=mid) __build(lch,l,mid,p);
            else __build(rch,mid+1,r,p);
        }
    }

    void build(int &u,int p) { __build(u, pos_l, pos_r, p); }

    #undef lch
    #undef rch

} sgt;

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len,pos;
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
        for(;p!=-1&&!edp[p].ch[c];p=edp[p].link) edp[p].ch[c]=cur;
        if(p!=-1) {
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
        }
    }

    vector<int> toporder;
    void toposort() {
        auto &q=toporder;
        q.clear();
        q.reserve(size());
        vector<int> ind(size());
        for(int i=1;i<size();i++) ind[edp[i].link]++;
        for(int i=1;i<size();i++) if(!ind[i]) q.push_back(i);
        for(int i=0;i<q.size();i++) {
            int u=q[i];
            int p=edp[u].link;
            if(p&&!--ind[p]) q.push_back(p);
        }
    }

    void find_pos(const string &s) {
        int u=0,idx=0;
        for(auto x:s) {
            int c=x-B;
            u=edp[u].ch[c];
            edp[u].pos=idx++;
        }
        for(int u:toporder) {
            int p=edp[u].link;
            edp[p].pos=edp[u].pos;
        }
    }

    void build_sgt(string &s) {
        for(int u=0,i=0;i<s.size();i++) {
            int c=s[i]-B;
            u=edp[u].ch[c];
            sgt.build(root[u], i);
        }
        for(int u:toporder) {
            int p=edp[u].link;
            if(p) root[p]=sgt.merge(root[p], root[u]);
        }
    }

    int size() { return edp.size(); }
    void build(const string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    
    SuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
    SuffixAutomaton(const string &s) { edp.reserve(s.size()*2),clear(),build(s); }
} sam(N*2);
const auto &edp=sam.edp;

// * index start from 0
namespace lca {
    constexpr int M=__lg(N*2);
    int fa[N*2][M+1],dep[N*2],pos[N];

    void get_fa(const vector<int> &q) {
        dep[0]=1;
        for(auto it=q.rbegin();it!=q.rend();it++) {
            int u=*it;
            int p=edp[u].link;
            dep[u]=dep[p]+1;
            fa[u][0]=p;
            for(int i=1;i<=M;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
        }
    }

    void get_pos(const string &s) {
        int u=0;
        for(int i=0;i<s.size();i++) {
            int c=s[i]-sam.B;
            u=edp[u].ch[c];
            pos[i]=u;
        }
    }

    int find(int l,int r) {
        int u=pos[r];
        int len=r-l+1;
        for(int i=M;i>=0;i--) {
            int p=fa[u][i];
            if(edp[p].len>=len) u=p;
        }
        return u;
    }

    int lca(int u,int v) {
        if(dep[u]<dep[v]) swap(u,v);
        for(int k=M;~k;k--)
            if(dep[fa[u][k]]>=dep[v])
                u=fa[u][k];
        if(u==v) return u;
        for(int k=M;~k;k--)
            if(fa[u][k]!=fa[v][k])
                u=fa[u][k],v=fa[v][k];
        return fa[u][0];
    }

    int lcs(int l,int r,int L,int R) {
        int u=find(l,r),v=find(L,R);
        if(u==v) return min(r-l+1,R-L+1);
        int p=lca(u,v);
        return edp[p].len;
    }
}

void solve() {
    int n;
    string s;
    cin>>n>>s;
    sam.build(s);
    sam.toposort();
    sam.find_pos(s);
    sam.build_sgt(s);
    auto &q=sam.toporder;
    lca::get_fa(q);

    auto check=[&](int u,int p) {
        if(!p) return true;
        int l=edp[u].pos-(edp[u].len-edp[p].len);
        int r=edp[u].pos-1;
        return sgt.query(root[p], l, r);
    };

    for(auto it=q.rbegin();it!=q.rend();it++) {
        int u=*it,v=u;
        if(edp[u].link==0) {
            dp[u]=1;
            continue;
        }
        for(int i=lca::M;i>=0;i--) {
            int p=lca::fa[v][i];
            if(check(u,p)) continue;
            v=p;
        }
        v=edp[v].link;
        dp[u]=dp[v]+1;
    }

    int ans=0;
    for(int u:q) ans=max(ans,dp[u]);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}