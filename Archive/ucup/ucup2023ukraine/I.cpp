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
constexpr int N=2e5+10;

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
}; using Mint=Modint<int,long long,998244353>;

int leap[N],nleap[N],len[N];
Mint dp[N][2],pw[N];

void solve() {
    int n,m;
    cin>>n>>m;
    bool valid=1;

    for(int i=1;i<=n+m-1;i++) leap[i]=nleap[i]=len[i]=0;
    for(int i=1;i<=n+m-1;i++) dp[i][0]=dp[i][1]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int in,id=i+j-1;
            cin>>in;
            len[id]++;
            if(in==id) nleap[id]++;
            else if(in==id+1) leap[id]++;
            else if(in!=-1) valid=0;
        }
    }

    debug(valid);
    if(valid) {
        dp[0][0]=1;
        for(int i=1;i<=n+m-1;i++) {
            if(leap[i]) dp[i][0]=0;
            else dp[i][0]=dp[i-1][0];

            if(nleap[i]<len[i]) {
                dp[i][1]=dp[i-1][0]*(pw[len[i]-leap[i]-nleap[i]]-(leap[i]==0));
                if(nleap[i]==0) dp[i][1]+=dp[i-1][1];
            }
            else dp[i][1]=0;
            // debug(leap[i],nleap[i],len[i]);
            debug(i,dp[i][0],dp[i][1]);
        }
        cout<<dp[n+m-1][0]+dp[n+m-1][1]<<endl;
    }
    else {
        cout<<0<<endl;
    }
}

int main() {
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*2;

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}