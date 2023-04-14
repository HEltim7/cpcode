#include <array>
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
constexpr int N=1e5+10;

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
}; using Mint=Modint<int,long long,int(1e9)+7>;

template<typename T,int R,int C=R> struct Matrix {
    array<array<T,C>,R> v;

    template<int Rr,int Cr> Matrix<T,R,Cr> operator*(const Matrix<T,Rr,Cr> &r) const {
        static_assert(C==Rr,"");
        array<array<T,Cr>,R> ans;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                T res{};
                for(int k=0;k<C;k++)
                    res+=v[i][k]*r[k][j];
                ans[i][j]=res;
            }
        }
        return ans;
    }

    Matrix operator+(const Matrix &r) {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) ans[i][j]=v[i][j]+r[i][j];
        return ans;
    }

    Matrix operator-(const Matrix &r) {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) ans[i][j]=v[i][j]-r[i][j];
        return ans;
    }

    Matrix &operator*=(const Matrix<T,C,C> &r) { return *this=*this*r; }
    Matrix &operator+=(const Matrix &r) { return *this=*this+r; }
    Matrix &operator-=(const Matrix &r) { return *this=*this-r; }

    Matrix pow(long long k) {
        Matrix res(1),x=*this;
        while(k) { if(k&1) res*=x; k>>=1; x*=x; }
        return res;
    }

    //[0,n)[0,n)矩阵求逆，无逆元时res[0][0]=-1
    Matrix<T,R,C> inv() const {
        static_assert(R==C,"");
        int n=R;
        auto a=this->v;
		static Matrix<T,R,R> res;
        res.unit();
		for (int i=0,r; i<n; ++i) {
			r=i;
			for (int j=i+1; j<n; ++j)
				if (a[j][i]>a[r][i]) r=j;
			swap(a[i],a[r]), swap(res[i],res[r]);
			if (a[i][i]==0) return res[0][0]=-1,res;

            T invaii=a[i][i].inv();
			for (int k=0; k<n; ++k) a[i][k]=a[i][k]*invaii;
			for (int k=0; k<n; ++k) res[i][k]=res[i][k]*invaii;
			for (int j=0; j<n; ++j)
				if (j!=i) {
					T tmp=a[j][i];
					for (int k=i; k<n; ++k) 
                        a[j][k]=(a[j][k]-tmp*a[i][k]);
					for (int k=0; k<n; ++k) 
                        res[j][k]=(res[j][k]-tmp*res[i][k]);
				}
		}
		return res;
	}

    auto &operator[](int idx) { return v[idx]; }
    auto &operator[](int idx) const { return v[idx]; }

    void clear() { v={}; }
    void unit(T x=1) { static_assert(R==C,""); clear(); for(int i=0;i<R;i++) v[i][i]=x; }

    Matrix() { clear(); }
    Matrix(T x) { unit(x); }
    Matrix(const array<array<T,C>,R> &x) { v=x; }
}; 
using Mat1=Matrix<Mint, 2>;
using Mat2=Matrix<Mint,1,2>;

const Mat1 slash[]={Mat1({{{1,1},{0,1}}}),Mat1({{{1,0},{1,1}}})};
const Mat2 init[]={Mat2({1,0}),Mat2({0,1})};
Mat1 pre[N];

void solve() {
    int n,m;
    cin>>n>>m;
    pre[1]=Mat1(1);
    for(int i=2;i<=n;i++) {
        char in;
        cin>>in;
        bool type=in=='\\';
        pre[i]=pre[i-1]*slash[type];
    }
    while(m--) {
        int hs,ht,ps,pt;
        cin>>hs>>ht>>ps>>pt;
        Mat1 trans=pre[hs].inv()*pre[ht];
        Mat2 res=init[ps]*trans;
        cout<<res[0][pt]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}