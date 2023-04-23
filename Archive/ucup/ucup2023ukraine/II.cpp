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

vector<Mint> dp[N];
vector<bool> leap[N],nleap[N];
vector<int> num[N];

void solve() {
    int n,m;
    cin>>n>>m;
    bool valid=1;

    for(int i=0;i<=n+2;i++) 
        dp[i].resize(m+1),leap[i].resize(m+2),nleap[i].resize(m+2),num[i].resize(m+2);
    for(int i=0;i<=n+2;i++) for(int j=0;j<m+2;j++) dp[i][j]=0,leap[i][j]=nleap[i][j]=0;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int id=i+j-1;
            cin>>num[i][j];
            leap[i][j]=leap[i][j]|leap[i-1][j]|leap[i][j-1];
            if(num[i][j]==id+1) leap[i][j]=1;
            else if(num[i][j]==id) {
                if(leap[i][j]) valid=0;
                nleap[i][j]=1;
            }
            else if(num[i][j]!=-1) valid=0;
        }
    }

    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
            nleap[i][j]=nleap[i][j]|nleap[i+1][j]|nleap[i][j+1];

    if(valid) {
        for(int i=n;i>=1;i--)
            for(int j=m;j>=1;j--)
                if(!leap[i][j]) {
                    if(!nleap[i][j]) dp[i][j]=dp[i+1][j]+dp[i][j+1]+1;
                    else dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
        for(int i=1;i<=n;i++) debug(dp[i],1,m);
        cout<<dp[1][1]+1<<endl;
    }
    else cout<<0<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}