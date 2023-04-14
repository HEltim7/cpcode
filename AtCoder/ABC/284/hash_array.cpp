#include <array>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int HASHCNT=2;
array<int,HASHCNT> mod;
template<int size,typename I=int,typename L=long long,const array<I,size> &p=mod> struct Hashint {
    array<I,size> v;
    I _pow(int i,L b) const {
        L res=1,a=v[i];
        while(b) { if(b&1) res=res*a%p[i]; b>>=1; a=a*a%p[i]; }
        return res;
    }
    I _inv(int i) const { return _pow(i,p[i]-2); }
    Hashint pow(L b) {
        Hashint res;
        for(int i=0;i<size;i++) res[i]=_pow(i,b);
        return res;
    }

    Hashint &operator+=(const Hashint &x) { for(int i=0;i<size;i++) v[i]+=x[i],v[i]-=v[i]>=p[i]?p[i]:0; return *this; }
    Hashint &operator-=(const Hashint &x) { for(int i=0;i<size;i++) v[i]-=x[i],v[i]+=v[i]<0?p[i]:0; return *this; }
    Hashint &operator*=(const Hashint &x) { for(int i=0;i<size;i++) v[i]=L(1)*v[i]*x[i]%p[i]; return *this; }
    Hashint &operator/=(const Hashint &x) { for(int i=0;i<size;i++) v[i]=L(1)*v[i]*x._inv(i)%p[i]; return *this; }

    friend Hashint operator+(Hashint l,const Hashint &r) { return l+=r; }
    friend Hashint operator-(Hashint l,const Hashint &r) { return l-=r; }
    friend Hashint operator*(Hashint l,const Hashint &r) { return l*=r; }
    friend Hashint operator/(Hashint l,const Hashint &r) { return l/=r; }
    
    Hashint operator++(int) { auto res=*this; *this+=1; return res; }
    Hashint operator--(int) { auto res=*this; *this-=1; return res; }
    Hashint operator-  () { return *this*-1; }
    Hashint &operator++() { return *this+=1; }
    Hashint &operator--() { return *this-=1; }

    bool operator< (const Hashint &x) const { return v< x.v; }
    bool operator> (const Hashint &x) const { return v> x.v; }
    bool operator<=(const Hashint &x) const { return v<=x.v; }
    bool operator>=(const Hashint &x) const { return v>=x.v; }
    bool operator==(const Hashint &x) const { return v==x.v; }
    bool operator!=(const Hashint &x) const { return v!=x.v; }

    auto &operator[](int i) { return v[i]; }
    auto &operator[](int i) const { return v[i]; }

    Hashint(L x=0) { for(int i=0;i<size;i++) v[i]=(x%p[i]+p[i])%p[i]; }
}; using Hint=Hashint<HASHCNT>;

struct HashArray {
    constexpr static int base=131;
    vector<Hint> arr,pw;

    void push_back(int x) {
        arr.push_back(arr.back()*base+x);
        pw.push_back(pw.back()*base);
    }

    void append(string &s) { for(auto x:s) push_back(x); }
    void append(vector<int> &s) { for(auto x:s) push_back(x); }

    Hint query(int l,int r) {
        return arr[r]-arr[l-1]*pw[r-l+1];
    }

    void clear() { arr.clear(),pw.clear();arr.push_back(0),pw.push_back(1); }
    
    HashArray() { clear(); };
    HashArray(int sz) {
        clear();
        arr.reserve(sz),pw.reserve(sz);
    };
};

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}