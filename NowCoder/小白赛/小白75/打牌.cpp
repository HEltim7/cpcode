#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=55;

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
}; using Mint=Modint<int,long long,int(1e9)+7>;

template<typename T,int R,int C=R> struct Matrix {
    array<array<T,C>,R> v;
    
    template<int Rr,int Cr> constexpr Matrix<T,R,Cr> 
    operator*(const Matrix<T,Rr,Cr> &r) const {
        static_assert(C==Rr,"");
        array<array<T,Cr>,R> ans;
        for(int i=0;i<R;i++) {
            for(int k=0;k<C;k++) {
                if(v[i][k]==0) continue;
                for(int j=0;j<Cr;j++) {
                    ans[i][j]+=v[i][k]*r[k][j];
                }
            }
        }
        return ans;
    }

    constexpr Matrix operator+(const Matrix &r) const {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                ans[i][j]=v[i][j]+r[i][j];
        return ans;
    }

    constexpr Matrix operator-(const Matrix &r) const {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                ans[i][j]=v[i][j]-r[i][j];
        return ans;
    }

    constexpr Matrix &operator*=(const Matrix<T,C,C> &r) { return *this=*this*r; }
    constexpr Matrix &operator+=(const Matrix &r) { return *this=*this+r; }
    constexpr Matrix &operator-=(const Matrix &r) { return *this=*this-r; }

    constexpr Matrix pow(long long k) const {
        Matrix res(1),x=*this;
        while(k) { if(k&1) res*=x; k>>=1; x*=x; }
        return res;
    }

    constexpr auto &operator[](int idx) { return v[idx]; }
    constexpr auto &operator[](int idx) const { return v[idx]; }

    constexpr void clear() { v={}; }
    constexpr void unit(T x=1) {
        static_assert(R==C,"");
        clear(); for(int i=0;i<R;i++) v[i][i]=x;
    }

    constexpr Matrix() { clear(); }
    constexpr Matrix(T x) { unit(x); }
    constexpr Matrix(const array<array<T,C>,R> &x): v(x) {}
}; using Mat=Matrix<Mint, N>;

Mat mat;
constexpr Mint P=Mint(1)/9;

void solve() {
    array<int,9> deck({1,1,1,10,10,10,100,100,100});
    map<tuple<int,int,int>,int> mp;
    int idx=0;

    do {
        int x=deck[0]+deck[1]+deck[2];
        int y=deck[3]+deck[4]+deck[5];
        int z=deck[6]+deck[7]+deck[8];
        if(mp.find({x,y,z})==mp.end()) mp[{x,y,z}]=idx++;
    }while (next_permutation(deck.begin(),deck.end()));

    auto decom=[&](int x) {
        int w=x/100;x%=100;
        int i=x/10;x%=10;
        return tuple{w,i,x};
    };

    auto get_ning=[&](int x) {
        auto [w,i,n]=decom(x);
        if(w>=2) return 100;
        else if(i>=2) return 10;
        else return 1;
    };

    auto get=[&](int x) {
        vector<int> res;
        res.reserve(3);
        while(x>=100) res.emplace_back(100),x-=100;
        while(x>=10) res.emplace_back(10),x-=10;
        while(x) res.emplace_back(1),x-=1;
        return res;
    };

    for(auto [tpl,id]:mp) {
        auto [x,y,z]=tpl;
        if(x==111||y==111||z==111) {
            mat[id][id]+=1;
            continue;
        }
        int ning=get_ning(x);
        for(int p:get(y)) {
            for(int q:get(z)) {
                int a=x-ning+q;
                int b=y-p+ning;
                int c=z-q+p;
                int ne=mp[{a,b,c}];
                mat[id][ne]+=P;
            }
        }
    }

    int pw;
    cin>>pw;
    mat=mat.pow(pw);

    auto read=[&]() {
        string s;
        cin>>s;
        int res=0;
        for(char x:s) {
            if(x=='w') res+=100;
            else if(x=='i') res+=10;
            else if(x=='n') res++;
        }
        return res;
    };

    int a=read();
    int b=read();
    int c=read();
    if(a==111) {
        cout<<1<<endl;
        return;
    }

    int init=mp[{a,b,c}];
    Matrix<Mint, 1, N> dp;
    dp[0][init]=1;
    dp*=mat;

    Mint ans=0;
    for(auto [tpl,id]:mp) {
        auto [x,y,z]=tpl;
        if(x==111) {
            ans+=dp[0][id];
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}