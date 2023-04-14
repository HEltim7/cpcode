#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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
}; using Mint=Modint<int,long long,998244353>;
constexpr int N=45,M=125,X=105;
Mint dp[N][M][X][X],slash[M][X][X],up[M][X][X],dn[M][X][X];

void solve() {
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x++,y++;
    dp[0][0][1][1]=1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=120;j++) {
            for(int s=1;s<=x;s++) {
                for(int t=1;t<=y;t++) {
                    slash[j][s][t]=slash[j][s-1][t-1]+dp[i-1][j][s][t];
                    up[j][s][t]=up[j][s-1][t]+slash[j][s][t];
                    dn[j][s][t]=dn[j][s][t-1]+slash[j][s][t];
                }
            }
        }

        for(int j=0;j<=120;j++) {
            for(int s=1;s<=x;s++) {
                for(int t=1;t<=y;t++) {
                    if(j) dp[i][j][s][t]+=slash[j-1][s][t];
                    if(j>=3) dp[i][j][s][t]+=up[j-3][s-1][t];
                    dp[i][j][s][t]+=dn[j][s][t-1];
                }
            }
        }
    }
    
    Mint ans;
    for(int i=m;i<=120;i++) ans+=dp[n][i][x][y];
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}