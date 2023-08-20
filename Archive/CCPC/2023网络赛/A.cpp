#include<array>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<numeric>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;
#define debug(x) cerr<<"[debug] "<<#x<<" = "<<x<<endl

#define endl '\n'
using LL=long long;
constexpr int N = 1e6 + 10;

template<typename I,typename L,I mod> struct Modint {
    I v;
    using M=Modint;
    constexpr M &operator+=(const M &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    constexpr M &operator-=(const M &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    constexpr M &operator*=(const M &x) { v=L(1)*v*x.v%mod; return *this; }

    constexpr friend M operator+(M l,const M &r) { return l+=r; }
    constexpr friend M operator-(M l,const M &r) { return l-=r; }
    constexpr friend M operator*(M l,const M &r) { return l*=r; }
    constexpr bool operator==(const M &x) const { return v==x.v; }

    friend ostream &operator<<(ostream &os,const M &x) { return os<<x.v; }
    constexpr Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
};
using Mint=Modint<int,LL,998244353>;
using Mint2=Modint<int,LL,int(1e9)+7>;
// using Mll=Modint<LL,__int128,LL(1e18)+9>;

struct Tag {
    Mint lans=0,lsum=0,lcnt=0;
    void clear() {
        lans=lsum=lcnt=0;
    }
    
    void operator+=(const Tag &t) {
        lans+=t.lans;
        lsum+=t.lsum;
        lcnt+=t.lcnt;
    }
};

struct Info {
    Mint ans=0,sum=0,cnt=0;
    
    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.ans=l.ans+r.ans;
        res.sum=l.sum+r.sum;
        res.cnt=l.cnt+r.cnt;
        return res;
    }

    void operator+=(const Tag &t) {
        ans+=t.lans;
        sum+=t.lsum;
        cnt+=t.lcnt;
    }
};

struct SGT {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)
    int rng_l,rng_r;
    constexpr static int sz=4<<__lg(N)|1;

    array<Tag, sz> tag;
    array<Info, sz> info;
    array<bool, sz> clean;

    void pushup(int u) {
        info[u]=info[lch]+info[rch];
    }

    void update(int u,const Tag &t) {
        info[u]+=t;
        tag[u]+=t;
        clean[u]=0;
    }

    void pushdn(int u) {
        if(clean[u]) return;
        update(lch,tag[u]);
        update(rch,tag[u]);
        clean[u]=1;
        tag[u].clear();
    }

    Info query(int u,int l,int r,int x,int y) {
        if(l>y||r<x) return {};
        if(l>=x&&r<=y) return info[u];
        pushdn(u);
        int mid=(l+r)/2;
        return query(lch,l,mid,x,y)+query(rch,mid+1,r,x,y);
    }
    Info query(int l,int r) { return query(1,rng_l,rng_r,l,r); }

    void modify(int u,int l,int r,int x,int y,const Tag &t) {
        if(l>y||r<x) return;
        if(l>=x&&r<=y) update(u,t);
        else {
            pushdn(u);
            int mid=(l+r)/2;
            if(mid>=x) modify(lch,l,mid,x,y,t);
            if(mid<y) modify(rch,mid+1,r,x,y,t);
            pushup(u);
        }
    }
    void modify(int l,int r,const Tag &t) { modify(1,rng_l,rng_r,l,r,t); }

    void build(int u,int l,int r) {
        clean[u]=1;
        // info[u].init(l,r);
        // tag[u].clear();
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
            pushup(u);
        }
    }
    void build(int l,int r) {
        rng_l=l,rng_r=r;
        build(1,l,r);
    }
} sgt;

vector<Mint> pw1;
vector<Mint2> pw2;
constexpr int base=131;
struct Hash {
    vector<Mint> arr1;
    vector<Mint2> arr2;

    void append(const string &s) {
        arr1.reserve(s.size()+1);
        arr2.reserve(s.size()+1);
        for(auto x:s) {
            arr1.emplace_back(arr1.back()*base+x);
            arr2.emplace_back(arr2.back()*base+x);
        }
    }

    pair<Mint,Mint2> query(int l,int r) {
        return {arr1[r]-arr1[l-1]*pw1[r-l+1],arr2[r]-arr2[l-1]*pw2[r-l+1]};
    }

    Hash() {
        arr1.emplace_back(0);
        arr2.emplace_back(0);
    }
} hs,ht;

int z[N];
void solve() {
    string s,t;
    cin>>s>>t;
    hs.append(s);
    ht.append(t);
    int n=s.size();
    int m=t.size();
    for(int i=1;i<=n;i++) {
        auto find_next=[&](int x,int y) {
            int l=0,r=min(n-x+1,m-y+1);
            while(l<r) {
                int mid=(l+r+1)/2;
                if(hs.query(x,x+mid-1)==ht.query(y,y+mid-1)) l=mid;
                else r=mid-1;
            }
            return l;
        };

        int R=i+m-1;
        int t=find_next(i,1);
        if(i+t>=n||t+1>=m) z[i]=min({n,R,i+t});
        else {
            t=t+1+find_next(i+t+1,t+2);
            z[i]=i+t-1;
        }
    }

    sgt.build(1,n);
    sgt.modify(1,z[1],Tag{1,1,1});
    for(int i=2;i<=n;i++) {
        Info x=sgt.query(i-1,i-1);
        Tag t=Tag{x.ans+2*x.sum+x.cnt,x.sum+x.cnt,x.cnt};
        sgt.modify(i,z[i],t);
    }
    Info ans=sgt.query(n,n);
    cout<<ans.ans<<endl;
    // cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
}

int main() {
    pw1.emplace_back(1);
    pw2.emplace_back(1);
    for(int i=1;i<N;i++) pw1.emplace_back(pw1.back()*base);
    for(int i=1;i<N;i++) pw2.emplace_back(pw2.back()*base);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}