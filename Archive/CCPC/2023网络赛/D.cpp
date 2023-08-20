#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<numeric>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
#include <cassert>
using namespace std;

constexpr double PI=acos(-1);
struct Comp {
    double a,b;
    Comp(double a=0,double b=0):a(a),b(b) {}
    Comp operator+ (const Comp& o)const {
        return Comp(a+o.a,b+o.b);
    }
    Comp operator-(const Comp& o) const {
        return Comp(a-o.a,b-o.b);
    }
    Comp operator*(const Comp& o) const {
        return Comp(a*o.a-b*o.b,a*o.b+b*o.a);
    }
};

void dft(vector<Comp>& a) {
    static vector<int> rev;
    int n=a.size();
    if(rev.size()!=n) {
        rev.resize(n);
        for(int i=1; i<n; ++i)
            rev[i]=rev[i>>1]|(i&1?n>>1:0);
    }
    for(int i=0; i<n; ++i)
        if(i<rev[i]) swap(a[i],a[rev[i]]);
    static vector<Comp> w{Comp(),Comp(1,0)};
    if(w.size()<n) {
        int k=__builtin_popcount(w.size());
        w.resize(n);
        for(; (1<<k)<n; ++k) {
            Comp e(cos(PI/(1<<k)),sin(PI/(1<<k)));
            for(int i=(1<<(k-1)); i<(1<<k); ++i) {
                w[i<<1]=w[i];
                w[i<<1|1]=w[i]*e;
            }
        }
    }
    for(int m=1; m<n; m<<=1) {
        for(int i=0; i<n; i+=m<<1) {
            for(int j=0; j<m; ++j) {
                Comp B=a[i+j],C=a[i+m+j]*w[m+j];
                a[i+j]=B+C, a[i+m+j]=B-C;
            }
        }
    }
}

// void idft(vector<Comp>& a) {
//     dft(a);
//     reverse(a.begin()+1,a.end());
//     for(auto& x:a)
//         x.a/=a.size(),x.b/=a.size();
// }

using namespace std;
using ll=long long;
constexpr int N = 2e5 + 10;
// #define double long double

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> f(n);
    for(int& x:f) cin>>x;

    vector<Comp> w(n);
    w[0]=Comp(1,0);
    if(n>1)
        w[1]=Comp(cos(PI*2/n),sin(PI*2/n));
    for(int i=2; i<n; ++i) {
        w[i]=w[i-1]*w[1];
    }

    // int len=1;
    // while(len<n)
    //     len<<=1;
    // f.resize(len);

    auto func=[&](ll mid) {
        vector<int> g(f);
        g[k]=mid;
        double ans=0;
        for(int i=0; i<n; ++i) {
            Comp sum(0,0);
            for(int j=0; j<n; ++j) {
                Comp& x=w[(-i*j%n+n)%n];
                sum.a+=g[j]*x.a;
                sum.b+=g[j]*x.b;
            }
            ans=max(ans,sqrt(sum.a*sum.a+sum.b*sum.b));
        }
        return ans;
        // vector<Comp> g(len);
        // for(int i=0; i<n; ++i)
        //     g[i].a=f[i];
        // g[k].a=mid;
        // dft(g);
        // double cur=0;
        // for(int i=0; i<n; ++i) {
        //     cur=max(cur,sqrt(g[i].a*g[i].a+g[i].b*g[i].b));
        // }
        // return cur;
    };

    // double ans=numeric_limits<double>::max();
    // 三分求func(mid)的最小值，mid in [-1e14,1e14]

    auto work=[&](ll l,ll r) {
        ll lastl=l,lastr=r;
        while(r-l+1>5) {
            ll lmid=(l+r)/2;
            ll rmid=lmid+1;
            if(func(rmid)>=func(lmid)) r=rmid;
            else l=lmid;
            assert(l!=lastl||r!=lastr);
            lastl=l,lastr=r;
        }
        ll ans=l;
        auto x=func(l);
        for(ll i=l+1;i<=r;i++) {
            auto v=func(i);
            if(v<x) {
                x=v;
                ans=i;
            }
        }
        return ans;
    };

    cout<<fixed<<setprecision(12)<<func(work(-1e9,1e9))<<'\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tt=1;
    // cin>>tt;
    while(tt--) {
        solve();
    }
    return 0;
}