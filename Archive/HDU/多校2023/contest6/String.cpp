#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

template<typename I,typename L,I mod> struct Modint {
    I v;
    constexpr I pow(L b) const {
        L res=1,a=v;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }
    constexpr I inv() const { return pow(mod-2); }

    constexpr Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    constexpr Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    constexpr Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    constexpr Modint &operator/=(const Modint &x) { v=L(1)*v*x.inv()%mod; return *this; }

    friend constexpr Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend constexpr Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend constexpr Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend constexpr Modint operator/(Modint l,const Modint &r) { return l/=r; }
    friend constexpr Modint operator-(Modint r) { r.v=mod-r.v; return r; }

    Modint operator++(int) { auto res=*this; ++*this; return res; }
    Modint operator--(int) { auto res=*this; --*this; return res; }
    Modint &operator++() { v=v==mod-1?0:v+1; return *this; }
    Modint &operator--() { v=v?v-1:mod-1; return *this; }

    constexpr bool operator< (const Modint &x) const { return v< x.v; }
    constexpr bool operator> (const Modint &x) const { return v> x.v; }
    constexpr bool operator<=(const Modint &x) const { return v<=x.v; }
    constexpr bool operator>=(const Modint &x) const { return v>=x.v; }
    constexpr bool operator==(const Modint &x) const { return v==x.v; }
    constexpr bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    constexpr Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,998244353>;

Mint cal(int l,int r) {
    l=max(l,0);
    assert(r>=0&&r>=l);
    return Mint(l+r)*(r-l+1)/2;
}

Mint cal(int len) {
    assert(len>=0);
    return Mint(1LL*len*(len+1)/2);
}
vector<Mint> cal_pre(N*2);

int root[N*2];
struct MergeableSegmentTree {
    #define lch (tr[u].lc)
    #define rch (tr[u].rc)
    constexpr static int MAX_SIZE=N*80;
    constexpr static int pos_l=0,pos_r=N-1;
    
    struct Node {
        int lc,rc;
        int cnt;
        int fst,lst;
        int sum;
        Mint tot;
    } tr[MAX_SIZE];
    int idx;

    int new_node() {
        tr[++idx]={};
        return idx;
    }

    void pushup(int u) {
        if(lch&&rch) {
            tr[u].cnt=tr[lch].cnt+tr[rch].cnt;
            tr[u].fst=tr[lch].fst;
            tr[u].lst=tr[rch].lst;
            int len=tr[rch].fst-tr[lch].lst-1;
            tr[u].sum=tr[lch].sum+tr[rch].sum+len;
            tr[u].tot=tr[lch].tot+tr[rch].tot+cal(len);
        }
        else if(lch) {
            int lc=tr[u].lc,rc=tr[u].rc;
            tr[u]=tr[lch];
            tr[u].lc=lc,tr[u].rc=rc;
        }
        else if(rch) {
            int lc=tr[u].lc,rc=tr[u].rc;
            tr[u]=tr[rch];
            tr[u].lc=lc,tr[u].rc=rc;
        }
    }

    int merge(int x,int y) {
        if(!x||!y) return x|y;
        int u=new_node();
        lch=merge(tr[x].lc,tr[y].lc);
        rch=merge(tr[x].rc,tr[y].rc);
        pushup(u);
        return u;
    }

    int __query(int u,int l,int r,int ql,int qr) {
        if(l>=ql&&r<=qr) return tr[u].cnt;
        int mid=l+r>>1;
        int res=0;
        if(lch&&mid>=ql) res+=__query(lch, l, mid, ql, qr);
        if(rch&&mid<qr) res+=__query(rch, mid+1, r, ql, qr);
        return res;
    }

    int query(int u,int ql,int qr) {
        if(ql>qr) return 0;
        return __query(u, pos_l, pos_r, ql, qr);
    }

    void __build(int &u,int l,int r,int p) {
        u=new_node();
        tr[u].cnt=1;
        tr[u].fst=tr[u].lst=p;
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
        int link,len,cnt;
        int ch[A];
        Mint pre;
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
        toporder.clear();
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

    Mint work(int u,int l,int r,int n) {
        const Mint tot=cal(n);
        auto &rt=sgt.tr[root[u]];
        int cnt=r-l+1;
        auto get=[&](int l,int r) {
            assert(l<=r);
            if(r<0) return Mint{};
            return cal_pre[r]-(l-1>=0?cal_pre[l-1]:0);
        };
        Mint res=tot*cnt;
        res-=rt.tot*cnt;
        res-=get(l-1,r-1)*(rt.cnt-1);
        res-=cal(l-1,r-1)*rt.sum;
        res-=cal(rt.fst-1)*cnt;
        res-=get(n-rt.lst+l-1,n-rt.lst+r-1);
        res+=get(l-2,r-2)*rt.cnt;
        return res;
    }

    void build_sgt(string &s,int n) {
        for(int i=0;i<size();i++) root[i]=0;
        for(int u=0,i=0;i<s.size();i++) {
            int c=s[i]-B;
            u=edp[u].ch[c];
            sgt.build(root[u], i+1);
        }
        for(int u:toporder) {
            int p=edp[u].link;
            if(p) root[p]=sgt.merge(root[p], root[u]);
        }

        for(int i=1;i<=toporder.size();i++) {
            int u=toporder.end()[-i];
            int p=edp[u].link;
            int l=edp[p].len+1;
            int r=edp[u].len;
            edp[u].pre=edp[p].pre+work(u, l, r, n);
        }
    }

    Mint match(string &s,int n) {
        Mint ans=0;
        int u=0,len=0;
        for(auto x:s) {
            int c=x-B;
            while(u&&!edp[u].ch[c]) u=edp[u].link,len=edp[u].len;
            if(edp[u].ch[c]) u=edp[u].ch[c],len++;
            if(len) {
                auto &rt=sgt.tr[root[u]];
                int p=edp[u].link;
                int l=edp[p].len+1;
                int r=len;
                Mint res=edp[p].pre+work(u, l, r, n);
                ans+=res;
            }
        }
        return ans;
    }

    int size() { return edp.size(); }
    void build(const string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    
    SuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
    SuffixAutomaton(const string &s) { edp.reserve(s.size()*2),clear(),build(s); }
} sam;

void solve() {
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    sam.build(s);
    sam.toposort();
    sam.build_sgt(s,n);

    while(q--) {
        string s;
        cin>>s;
        cout<<sam.match(s, n)/cal(s.size())<<endl;
    }
    sam.clear();
    sgt.idx=0;
}

int main() {
    for(int i=1;i<cal_pre.size();i++)
        cal_pre[i]=cal_pre[i-1]+cal(i);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}