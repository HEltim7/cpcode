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
constexpr int N=2e3+10,B=114514;

constexpr int HASHCNT=2;
constexpr array<int,HASHCNT> mod{int(1e9+7),998244353};
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

using Mat=array<array<Hint,N>,N>;
array<array<char,N>,N> grid;
array<array<int,N>,N> base;
array<Hint,N*N> pw;
Mat pre,suf;

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>grid[i][j];
    
    auto rev=[&](auto &arr) {
        for(int i=1;i<=n;i++)
            reverse(arr[i].begin()+1,arr[i].begin()+m+1);
        reverse(arr.begin()+1,arr.begin()+n+1);
    };

    pw[0]=1;
    for(int i=1,idx=0;i<=n;i++)
        for(int j=1;j<=m;j++) {
            base[i][j]=++idx;
            pw[idx]=pw[idx-1]*B;
        }

    auto work=[&](Mat &pre) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                Hint cur=pw[base[i][j]]*grid[i][j];
                pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+cur;
            }
        }
    };

    work(pre);
    rev(grid);
    work(suf);

    auto reidx=[&](int &r,int &c) {
        r=n-r+1,c=m-c+1;
    };

    auto check=[&](int r,int c,int x,int y) {
        int p=base[r][c];
        Hint a=pre[x][y]-pre[x][c-1]-pre[r-1][y]+pre[r-1][c-1];

        reidx(r, c),reidx(x, y);
        swap(r, x),swap(c, y);
        int s=base[r][c];
        Hint b=suf[x][y]-suf[x][c-1]-suf[r-1][y]+suf[r-1][c-1];

        if(s>=p) a*=pw[s-p];
        else b*=pw[p-s];
        return a==b;
    };

    LL ans=0;
    // odd
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int l=0,r=min({i,j,n-i+1,m-j+1})-1;
            while(l<r) {
                int mid=(l+r+1)/2;
                if(check(i-mid,j-mid,i+mid,j+mid)) l=mid;
                else r=mid-1;
            }
            ans+=l+1;
        }
    }

    // even
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            int x=i+1,y=j+1;
            int l=0,r=min({i,j,n-x+1,m-y+1})-1;
            if(!check(i,j,x,y)) continue;
            while(l<r) {
                int mid=(l+r+1)/2;
                if(check(i-mid,j-mid,x+mid,y+mid)) l=mid;
                else r=mid-1;
            }
            ans+=l+1;
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