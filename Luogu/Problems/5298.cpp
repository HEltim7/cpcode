#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10,M=N*20;
vector<int> adj[N],num;
int root[N],arr[N],chcnt[N],cnt;

template<typename T=long long,T mod=998244353> struct Modint {
    T v;
    T inv() const {
        T res=1,a=v,b=mod-2;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }

    Modint &operator+=(const Modint &x) { v+=x.v; if(v>=mod) v-=mod; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; if(v<0) v+=mod; return *this; }
    Modint &operator*=(const Modint &x) { v=v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=v*x.inv()%mod; return *this; }

    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }

    Modint operator++(int) { auto res=*this; *this+=1; return res; }
    Modint operator--(int) { auto res=*this; *this-=1; return res; }
    Modint operator-  () { return *this*-1; }
    Modint &operator++() { return *this+=1; }
    Modint &operator--() { return *this-=1; }

    bool operator< (const Modint&x) { return v< x.v; }
    bool operator> (const Modint&x) { return v> x.v; }
    bool operator<=(const Modint&x) { return v<=x.v; }
    bool operator>=(const Modint&x) { return v>=x.v; }
    bool operator==(const Modint&x) { return v==x.v; }
    bool operator!=(const Modint&x) { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(T x=0): v((x%=mod)<0?x+mod:x) {}
}; using Mint=Modint<>;

struct MergeableSegmentTree {
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    
    struct Node {
        int ch[2];
        Mint p,laze=1;
    } tr[M];
    int idx;
    Mint pmax,pmin,ans;

    int new_node() { return ++idx; }

    void pushup(int u) {
        if(lch&&rch) tr[u].p=tr[lch].p+tr[rch].p;
        else if(lch) tr[u].p=tr[lch].p;
        else if(rch) tr[u].p=tr[rch].p;
    }

    void pushdn(int u) {
        if(lch) tr[lch].p*=tr[u].laze,tr[lch].laze*=tr[u].laze;
        if(rch) tr[rch].p*=tr[u].laze,tr[rch].laze*=tr[u].laze;
        tr[u].laze=1;
    }
    
    void merge(int &u,int v,Mint preu,Mint prev) {
        if(!u&&!v) return;
        if(!u) {
            u=v;
            tr[u].p*=preu*pmax+(1-preu)*pmin;
            tr[u].laze*=preu*pmax+(1-preu)*pmin;
        }
        else if(!v) {
            tr[u].p*=prev*pmax+(1-prev)*pmin;
            tr[u].laze*=prev*pmax+(1-prev)*pmin;
        }
        else {
            pushdn(u);pushdn(v);
            merge(rch,tr[v].ch[1],preu+tr[lch].p,prev+tr[tr[v].ch[0]].p);
            merge(lch,tr[v].ch[0],preu,prev);
            pushup(u);
        }
    }

    void build(int &u,int l,int r,int p) {
        u=new_node();
        if(l==r) tr[u].p=1;
        else {
            int mid=l+r>>1;
            if(p<=mid) build(lch,l,mid,p);
            else build(rch,mid+1,r,p);
            pushup(u);
        }
    }

    void init(int u) {
        for(int v:adj[u]) init(v);
        if(!chcnt[u]) build(root[u], 1, cnt, arr[u]);
        else {
            pmax=Mint(arr[u])/10000;
            pmin=1-pmax;
            if(chcnt[u]==2) merge(root[adj[u][0]],root[adj[u][1]],0,0);
            root[u]=root[adj[u][0]];
        }
    }

    void getans(int u,int l,int r) {
        if(l==r) ans+=l*tr[u].p*tr[u].p*num[l];
        else {
            pushdn(u);
            int mid=l+r>>1;
            if(lch) getans(lch,l,mid);
            if(rch) getans(rch,mid+1,r);
        }
    }

    #undef lch
    #undef rch
} sgt;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int p;
        cin>>p;
        if(p) adj[p].push_back(i);
        chcnt[p]++;
    }
    for(int i=1;i<=n;i++) cin>>arr[i];

    num.push_back(0);
    for(int i=1;i<=n;i++) if(!chcnt[i]) num.push_back(arr[i]);
    sort(num.begin(),num.end());
    for(int i=0;i<=n;i++) if(!chcnt[i])
        arr[i]=lower_bound(num.begin(),num.end(),arr[i])-num.begin();
    cnt=num.size()-1;

    sgt.init(1);
    sgt.getans(root[1], 1, cnt);
    cout<<sgt.ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}