#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

template<typename I,typename L,I mod> struct Modint {
    I v;
    I pow(L b) const {
        L res=1,a=v;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }
    I inv() const { return pow(mod-2); }

    Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=L(1)*v*x.inv()%mod; return *this; }

    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }

    Modint operator++(int) { auto res=*this; *this+=1; return res; }
    Modint operator--(int) { auto res=*this; *this-=1; return res; }
    Modint operator-  () { return *this*-1; }
    Modint &operator++() { return *this+=1; }
    Modint &operator--() { return *this-=1; }

    bool operator< (const Modint &x) const { return v< x.v; }
    bool operator> (const Modint &x) const { return v> x.v; }
    bool operator<=(const Modint &x) const { return v<=x.v; }
    bool operator>=(const Modint &x) const { return v>=x.v; }
    bool operator==(const Modint &x) const { return v==x.v; }
    bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
    static_assert(0ULL+mod+mod-2<1ULL<<(sizeof(I)*8-1), "Modint overflow");
    static_assert(1ULL*(mod-1)*(mod-1)<1ULL<<(sizeof(L)*8-1), "Modint overflow");
}; using Mint=Modint<int,long long,int(1e9)+7>;

constexpr int N=4e5+10;
Mint faet[N],infaet[N];

void init() {
    faet[1]=1,faet[0]=1;
    infaet[1]=1,infaet[0]=1;
    for(int i=2;i<N;i++){
        faet[i]=faet[i-1]*i;
        infaet[i]=infaet[i-1]/i;
    }
}

Mint cmb(int a,int b) {
    if(a<0||b<0||a<b) return 0;
    return faet[a]*infaet[a-b]*infaet[b];
}

void solve() {
    init();
    int n,m;
    cin>>n>>m;
    Mint ans=0;
    for(int i=1;i<=n;i++) ans+=cmb(n-1,i-1);
    vector<pair<int,int>> arr(m),cur;
    for(auto &[x,y]:arr) cin>>x>>y;
    sort(arr.begin(),arr.end());

    for(int i=1;i<1<<m;i++) {
        int sign=__builtin_popcount(i)&1?-1:1;
        cur.clear();
        cur.emplace_back(1,1);
        for(int j=0;j<m;j++)
            if(i>>j&1) cur.push_back(arr[j]);
        bool valid=1;
        for(int pos=0,j=0;j<cur.size();j++)
            if(cur[j].second<pos) valid=0;
            else pos=cur[j].second;
        if(!valid) continue;

        Mint res=1;
        for(int j=1;j<cur.size();j++) {
            auto [x,y]=cur[j-1];
            auto [r,c]=cur[j];
            res*=cmb(r-x+c-y,r-x);
        }

        Mint sum=0;
        auto [x,y]=cur.back();
        for(int r=x,c=n-r+1;c>=y;r++,c--) sum+=cmb(r-x+c-y,r-x);
        ans+=sign*res*sum;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}