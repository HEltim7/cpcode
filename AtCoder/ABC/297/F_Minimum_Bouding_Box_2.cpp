#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10;

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

    Modint operator++(int) { auto res=*this; ++*this; return res; }
    Modint operator--(int) { auto res=*this; --*this; return res; }
    Modint &operator++() { v=v==mod-1?0:v+1; return *this; }
    Modint &operator--() { v=v?v-1:mod-1; return *this; }
    Modint operator-() { v=mod-v; return *this; }

    bool operator< (const Modint &x) const { return v< x.v; }
    bool operator> (const Modint &x) const { return v> x.v; }
    bool operator<=(const Modint &x) const { return v<=x.v; }
    bool operator>=(const Modint &x) const { return v>=x.v; }
    bool operator==(const Modint &x) const { return v==x.v; }
    bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    constexpr Modint(L x=0): v((x=abs(x)>=mod?x%mod:x)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,998244353>;

Mint faet[N*N],infaet[N*N],res[N][N],pre[N][N];
bool mark[N][N];

void init() {
    faet[1]=1,faet[0]=1;
    infaet[1]=1,infaet[0]=1;
    for(int i=2;i<N*N;i++){
        faet[i]=faet[i-1]*i;
        infaet[i]=infaet[i-1]/i;
    }
}

Mint cmb(int a,int b) {
    if(a<0||b<0||a<b) return 0;
    return faet[a]*infaet[a-b]*infaet[b];
}

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    Mint ans;
    int tot=n*m;

    // 计算矩形小于等于rxc的概率
    auto cal=[&](int r,int c) {
        int cur=r*c;
        int cnt=(n-r+1)*(m-c+1);
        if(r<=0||c<=0||cur<k) return Mint(0);
        return cmb(cur,k)/cmb(tot,k)*cnt;
    };

    // // 返回矩形严格被rxc包含的概率
    // function<Mint(int,int)> dfs=[&](int r,int c) {
    //     int cur=r*c;
    //     if(r<=0||c<=0||cur<k) return Mint(0);
    //     if(mark[r][c]) return pre[r][c];
    //     mark[r][c]=1;
        
    //     res[r][c]=cal(r,c)-dfs(r-1,c)-dfs(r,c-1)+dfs(r-1,c-1);
    //     pre[r][c]=pre[r-1][c]+pre[r][c-1]-pre[r-1][c-1]+res[r][c];
    //     return res[r][c]=ans;
    // };


    cout<<ans;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}