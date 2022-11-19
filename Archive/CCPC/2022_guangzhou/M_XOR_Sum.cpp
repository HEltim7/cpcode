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

    bool operator< (const Modint&x) { return v< x.v; }
    bool operator> (const Modint&x) { return v> x.v; }
    bool operator<=(const Modint&x) { return v<=x.v; }
    bool operator>=(const Modint&x) { return v>=x.v; }
    bool operator==(const Modint&x) { return v==x.v; }
    bool operator!=(const Modint&x) { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
    static_assert(0ULL+mod+mod-2<1ULL<<(sizeof(I)*8-1), "Modint overflow");
    static_assert(1ULL*(mod-1)*(mod-1)<1ULL<<(sizeof(L)*8-1), "Modint overflow");
}; using Mint=Modint<int,long long,int(1e9+7)>;

constexpr int N=55,M=170,K=20;
Mint dp[N][K][M+10],cmb[K][K];

void solve() {
    int k;
    LL n,m;
    cin>>n>>m>>k;

    cmb[0][0]=1;
    for(int i=1;i<K;i++)
        for(int j=0;j<=i;j++)
            cmb[i][j]=cmb[i-1][j-1]+cmb[i-1][j];

    dp[0][0][0]=1;
    auto cal=[&](int x) {
        return k>1?x*(k-x):x;
    };

    for(int i=0;i<=__lg(max(n,m));i++) {
        int x=n>>i&1,y=m>>i&1;
        for(int j=0;j<=k;j++) {
            for(int v=0;v<=M;v++) {
                for(int p=0;p<=j;p++) {
                    for(int q=0;q<=k-j;q++) {
                        int sum=v+cal(p+q);
                        if((sum&1)==x) {
                            sum>>=1;
                            Mint val=dp[i][j][v]*cmb[j][p]*cmb[k-j][q];
                            if(y) dp[i+1][p][sum]+=val;
                            else dp[i+1][j+q][sum]+=val;
                        }
                    }
                }
            }
        }
    }
    cout<<dp[__lg(max(n,m))+1][0][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}