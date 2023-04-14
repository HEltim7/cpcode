#include <tuple>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
tuple<int,int,int> q[N];
LL ans[N],m;

struct SegmentTree {

    constexpr static int MAX_SIZE=1e5+10;
    struct Node {
        int l,r;
        LL sum,laze;
    } tr[MAX_SIZE*4];

    void pushup(int u) {
        tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    }

    void pushdn(int u) {
        int len=tr[u<<1].r-tr[u<<1].l+1;
        tr[u<<1].sum+=len*tr[u].laze;
        tr[u<<1].laze+=tr[u].laze;
        len=tr[u<<1|1].r-tr[u<<1|1].l+1;
        tr[u<<1|1].sum+=len*tr[u].laze;
        tr[u<<1|1].laze+=tr[u].laze;
        tr[u].laze=0;
    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) 
            tr[u].sum+=(tr[u].r-tr[u].l+1)*val,tr[u].laze+=val;
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(u<<1,l,r,val);
            if(mid<r) modify(u<<1|1,l,r,val);
            pushup(u);
        }
    }

    LL query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) return tr[u].sum;
        int mid=tr[u].l+tr[u].r>>1;
        LL res=0;
        pushdn(u);
        if(mid>=l) res+=query(u<<1,l,r);
        if(mid<r) res+=query(u<<1|1,l,r);
        return res;
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) return;
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
    }

} sgt;

struct LinkCutTree {
    
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    #define wch(u) (tr[tr[u].p].ch[1]==u)
    constexpr static int MAX_SIZE=2e5+10;

    struct Node {
        int ch[2],p;
        int len,last;
    } tr[MAX_SIZE];
    int stk[MAX_SIZE];

    void pushdn(int u) {
        tr[lch].last=tr[rch].last=tr[u].last;
    }

    bool is_root(int u) {
        return tr[tr[u].p].ch[0]!=u&&tr[tr[u].p].ch[1]!=u;
    }

    void rotate(int x) {
        int y=tr[x].p,z=tr[y].p,k=wch(x);
        if(!is_root(y)) tr[z].ch[wch(y)]=x;
        tr[y].ch[k]=tr[x].ch[!k],tr[tr[y].ch[k]].p=y;
        tr[x].ch[!k]=y,tr[y].p=x,tr[x].p=z;
    }

    void splay(int u) {
        int top=0,fa=u;
        stk[++top]=fa;
        while(!is_root(fa)) stk[++top]=fa=tr[fa].p;
        while(top) pushdn(stk[top--]);
        for(;!is_root(u);rotate(u))
            if(!is_root(fa=tr[u].p)) rotate(wch(u)==wch(fa)?fa:u);
    }

    void access(int u,int pos) {
        int t=u,r=0;
        for(int v=0;u;v=u,u=tr[u].p) {
            splay(u);
            rch=0;
            int x=find_root(u);
            int l=tr[x].len;
            if(tr[x].last&&r) sgt.modify(1,tr[x].last-r+1,tr[x].last-l+1,-1);
            r=l-1;
            rch=v;
        }
        splay(t);
        tr[t].last=pos;
        sgt.modify(1, 1, pos, 1);
    }

    int find_root(int u) {
        while(lch) pushdn(u),u=lch;
        splay(u);
        return u;
    }

    #undef lch
    #undef rch
    #undef wch

} lct;

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

    void solve(string &s) {
        int u=0;
        build(s);
        lct.tr[1].len=1;
        for(int i=1;i<size();i++) {
            lct.tr[i+1].p=edp[i].link+1;
            lct.tr[i+1].len=edp[edp[i].link].len+1;
        }
        s=" "+s;
        for(int i=1,R=0;i<=m;i++) {
            auto [r,l,id]=q[i];
            while(R<r) {
                R++;
                u=edp[u].ch[s[R]-B];
                lct.access(u+1,R);
            }
            ans[id]=sgt.query(1, l, r);
        }
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N*2);

void solve() {
    string s;
    cin>>s>>m;
    sgt.build(1,1,s.size());
    for(int i=1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        q[i]={r,l,i};
    }
    sort(q+1,q+1+m);
    sam.solve(s);
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}