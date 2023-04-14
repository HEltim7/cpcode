#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10,M=100,B=33,E=126-B;

int mod;
template<typename I,typename L,const I &mod> struct Modint {
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
}; using Mint=Modint<int,long long,mod>;

Mint pre[M*M],suf[M*M];
int pre_cnt[M],suf_cnt[M];

int cal(int x,int y) {
    return x*M+y;
}

void solve() {
    string s;
    cin>>s>>mod;

    int n=s.size();
    s=" "+s;
    for(int i=1;i<=n-1;i++) {
        int c=s[i]-B;
        for(int j=0;j<=E;j++) {
            pre[cal(j,c)]+=pre_cnt[j];
        }
        pre_cnt[c]++;
    }

    Mint ans,sum;
    suf_cnt[s[n]-B]++;
    for(int i=n-1;i>=2;i--) {
        int c=s[i]-B;
        pre_cnt[c]--;
        for(int j=0;j<=E;j++) {
            pre[cal(j,c)]-=pre_cnt[j];
            sum-=pre_cnt[j]*suf[cal(c,j)];
        }

        ans+=sum;
        for(int j=0;j<=E;j++) {
            suf[cal(c,j)]+=suf_cnt[j];
            sum+=suf_cnt[j]*pre[cal(j,c)];
        }
        suf_cnt[c]++;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}