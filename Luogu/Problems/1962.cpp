#include <array>
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

template<typename T,int N> struct Matrix {
    array<array<T,N>,N> v;

    Matrix &operator*=(const Matrix &r) {
        array<array<T,N>,N> ans;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                T res{};
                for(int k=0;k<N;k++)
                    res+=v[i][k]*r[k][j];
                ans[i][j]=res;
            }
        }
        v=ans;
        return *this;
    }

    Matrix &operator+=(const Matrix &r) {
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) v[i][j]+=r[i][j];
        return *this;
    }

    Matrix &operator-=(const Matrix &r) {
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) v[i][j]-=r[i][j];
        return *this;
    }

    Matrix pow(long long k) {
        Matrix res(1),x=*this;
        while(k) { if(k&1) res*=x; k>>=1; x*=x; }
        return res;
    }

    friend Matrix operator*(Matrix l,const Matrix &r) { return l*=r; }
    friend Matrix operator+(Matrix l,const Matrix &r) { return l+=r; }
    friend Matrix operator-(Matrix l,const Matrix &r) { return l-=r; }

    auto &operator[](int idx) { return v[idx]; }
    auto &operator[](int idx) const { return v[idx]; }

    void clear() { v={}; }
    void unit(T x=1) { clear(); for(int i=0;i<N;i++) v[i][i]=x; }

    Matrix() {}
    Matrix(T x) { for(int i=0;i<N;i++) v[i][i]=x; }
    Matrix(const array<array<T,N>,N> &x) { v=x; }
};

void solve() {
    LL n;
    cin>>n;
    Matrix<Mint, 2> res={{{{1,0},{0,0}}}};
    Matrix<Mint, 2> val={{{{1,1},{1,0}}}};
    res*=val.pow(n-1);
    cout<<res[0][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}