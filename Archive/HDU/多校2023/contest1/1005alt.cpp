#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

template<typename I,typename L,I mod> struct Modint {
    I v;
    constexpr I pow(L b) const {
        L res=1,a=v;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }
    constexpr I inv() const { return pow(mod-2); }

    constexpr Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    constexpr Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    constexpr Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    constexpr Modint &operator/=(const Modint &x) { v=L(1)*v*x.inv()%mod; return *this; }

    friend constexpr Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend constexpr Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend constexpr Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend constexpr Modint operator/(Modint l,const Modint &r) { return l/=r; }
    friend constexpr Modint operator-(Modint r) { r.v=mod-r.v; return r; }

    Modint operator++(int) { auto res=*this; ++*this; return res; }
    Modint operator--(int) { auto res=*this; --*this; return res; }
    Modint &operator++() { v=v==mod-1?0:v+1; return *this; }
    Modint &operator--() { v=v?v-1:mod-1; return *this; }

    constexpr bool operator< (const Modint &x) const { return v< x.v; }
    constexpr bool operator> (const Modint &x) const { return v> x.v; }
    constexpr bool operator<=(const Modint &x) const { return v<=x.v; }
    constexpr bool operator>=(const Modint &x) const { return v>=x.v; }
    constexpr bool operator==(const Modint &x) const { return v==x.v; }
    constexpr bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    constexpr Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,998244353>;

string minimize(const string &s) {
    int i=0,j=1,k=0,n=s.size();
    while(i<n&&j<n&&k<n) {
        if(s[(i+k)%n]==s[(j+k)%n]) k++;
        else {
            if(s[(i+k)%n]>s[(j+k)%n]) i=i+k+1;
            else j=j+k+1;
            if(i==j) i++;
            k=0;
        }
    }
    i=min(i,j);
    string res;
    for(int j=0;j<n;j++) res.push_back(s[(i+j)%n]);
    return res;
}

struct HashArray {
    constexpr static int base=114514;
    vector<Mint> arr,pw;

    void push_back(int x) {
        arr.push_back(arr.back()*base+x);
        pw.push_back(pw.back()*base);
    }

    void append(string &s) { for(auto x:s) push_back(x); }
    void append(vector<int> &s) { for(auto x:s) push_back(x); }

    Mint query(int l,int r) {
        return arr[r]-arr[l-1]*pw[r-l+1];
    }

    void clear() { arr.clear(),pw.clear();arr.push_back(0),pw.push_back(1); }
    
    HashArray() { clear(); };
    HashArray(int sz) {
        clear();
        arr.reserve(sz),pw.reserve(sz);
    };
} hasher;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<Mint> hsh(n+1);
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        s=minimize(s);
        hasher.append(s);
        hsh[i]=hasher.query(1, m);
        hasher.clear();
    }

    int q;
    cin>>q;
    while(q--) {
        int x,y;
        cin>>x>>y;
        cout<<(hsh[x]==hsh[y]?"Yes":"No")<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}