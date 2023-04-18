#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;

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
constexpr Mint inv2=Mint(2).inv();

int root[N],w[N];
vector<int> adj[N];
vector<int> num;

struct MergeSplitSegmentTree {

    #define lch (tr[u].lc)
    #define rch (tr[u].rc)
    constexpr static int MAX_SIZE=1e7+10;
    
    struct Node {
        int lc,rc;
        Mint sump,sumv,lazp;
    } tr[MAX_SIZE];
    int idx;

    int new_node() {
        assert(idx<MAX_SIZE);
        int u=++idx;
        tr[u].lazp=1;
        return u;
    }

    void pushup(int u) {
        tr[u].sumv=tr[u].sump=0;
        if(lch) tr[u].sumv+=tr[lch].sumv,tr[u].sump+=tr[lch].sump;
        if(rch) tr[u].sumv+=tr[rch].sumv,tr[u].sump+=tr[rch].sump;
    }

    void push_laz(int u,Mint laz) {
        if(!u) return;
        tr[u].sump*=laz;
        tr[u].sumv*=laz;
        tr[u].lazp*=laz;
    }

    void pushdn(int u) {
        push_laz(lch, tr[u].lazp);
        push_laz(rch, tr[u].lazp);
        tr[u].lazp=1;
    }

    int merge(int x,int y,int l,int r,Mint &px,Mint &py) {
        if(!x&&!y) return 0;
        if(!x) {
            py-=tr[y].sump;
            push_laz(y, px*inv2);
            return y;
        }
        if(!y) {
            px-=tr[x].sump;
            push_laz(x, (py+1)*inv2);
            return x;
        }
        if(l==r) {
            Mint xp=tr[x].sump;
            Mint yp=tr[y].sump;
            Mint p=xp*(py+1)*inv2+yp*(px-xp)*inv2;
            tr[x].sump=p;
            tr[x].sumv=num[l]*p;
            px-=xp;
            py-=yp;
            return x;
        }
        int mid=l+r>>1;
        pushdn(x),pushdn(y);
        tr[x].lc=merge(tr[x].lc,tr[y].lc,l,mid,px,py);
        tr[x].rc=merge(tr[x].rc,tr[y].rc,mid+1,r,px,py);
        pushup(x);
        return x;
    }

    void build(int &u,int l,int r,int p) {
        u=new_node();
        if(l==r) tr[u].sump=1,tr[u].sumv=num[l];
        else {
            int mid=l+r>>1;
            if(p<=mid) build(lch,l,mid,p);
            else build(rch,mid+1,r,p);
            pushup(u);
        }
    }

    #undef lch
    #undef rch

} sgt;

Mint ans;
void dfs(int u,int fa) {
    sgt.build(root[u], 0, num.size()-1, w[u]);
    for(int v:adj[u]) {
        if(v!=fa) {
            dfs(v,u);
            Mint res=sgt.tr[root[v]].sumv*inv2;
            ans+=res;
            Mint px=1,py=1;
            sgt.merge(root[u], root[v], 0, num.size()-1, px, py);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++) {
        cin>>w[i];
        num.push_back(w[i]);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        w[i]=lower_bound(num.begin(),num.end(),w[i])-num.begin();
    
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);
    ans+=sgt.tr[root[1]].sumv;
    ans*=Mint(2).pow(n-1);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}