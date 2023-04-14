#include <vector>
#include <numeric>
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
}; using Mint=Modint<int,long long,int(1e9)+7>;

constexpr int N=1e5+10,M=N;
int prime[M],minp[M],euler[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=euler[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++idx]=i,euler[i]=i-1,minp[i]=i;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) {
                euler[i*prime[j]]=euler[i]*prime[j];
                break;
            }
            else euler[i*prime[j]]=euler[i]*(prime[j]-1);
        }
    }
}

vector<pair<int,int>> fac;
void get_factor(int val) {
    while(val>1) {
        int t=minp[val];
        fac.emplace_back(t,0);
        while(minp[val]==t) val/=t,fac.back().second++;
    }
}

vector<int> num;
void dfs(int idx,int val) {
    if(idx==fac.size()) {
        num.push_back(val);
        return;
    }
    auto [x,y]=fac[idx];
    for(int i=0,t=1;i<=y;i++,t*=x) dfs(idx+1,val*t);
}

void solve() {
    int n;
    cin>>n;
    Mint ans;
    for(int c=1;c<=n-2;c++) {
        int d=n-c;
        get_factor(d);
        dfs(0, 1);
        for(int g:num) if(g>1&&g<d) ans+=1LL*lcm(c,g)*euler[d/g];
        ans+=1LL*c*euler[d];
        fac.clear(),num.clear();
    }
    cout<<ans;
}

int main() {
    get_prime();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}