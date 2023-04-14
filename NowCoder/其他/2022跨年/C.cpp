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

    bool operator< (const Modint&x) const { return v< x.v; }
    bool operator> (const Modint&x) const { return v> x.v; }
    bool operator<=(const Modint&x) const { return v<=x.v; }
    bool operator>=(const Modint&x) const { return v>=x.v; }
    bool operator==(const Modint&x) const { return v==x.v; }
    bool operator!=(const Modint&x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
    static_assert(0ULL+mod+mod-2<1ULL<<(sizeof(I)*8-1), "Modint overflow");
    static_assert(1ULL*(mod-1)*(mod-1)<1ULL<<(sizeof(L)*8-1), "Modint overflow");
}; using Mint=Modint<int,long long,int(1e9+7)>;

Mint ans;
string s;
int tot;
bool mark[1<<7];

void dfs(int cur,int idx) {
    if(idx==9) {
        LL res=cur;
        res=res*int(1e9)+cur;
        // debug(cur,res);
        ans+=res%7;
        tot++;
    }
    else {
        if(s[idx]!='?') dfs(cur*10+s[idx]-'0',idx+1);
        else {
            for(int i=1;i<=9;i++) {
                if(!mark[i]) {
                    mark[i]=1;
                    dfs(cur*10+i,idx+1);
                    mark[i]=0;
                }
            }
        }
    }
}

void solve() {
    cin>>s;
    for(auto x:s) mark[x-'0']=1;
    dfs(0,0);
    debug(tot,ans);
    cout<<ans/tot;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}