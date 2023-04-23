#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=5e5+10,M=N<<1;

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
}; using Mint=Modint<int,long long,int(1e9)+9>;

int arr[N];
Mint faet[M],infaet[M],pw[N];

void init() {
    faet[1]=1,faet[0]=1;
    infaet[1]=1,infaet[0]=1;
    for(int i=2;i<M;i++){
        faet[i]=faet[i-1]*i;
        infaet[i]=infaet[i-1]/i;
    }
}

Mint cmb(int a,int b) {
    if(a<0||b<0||a<b) return 0;
    return faet[a]*infaet[a-b]*infaet[b];
}

void solve() {
    int n;
    cin>>n;
    LL sum=0;
    vector<int> tmp;
    vector<pair<int,int>> cnt;
    for(int i=1;i<=n;i++) cin>>arr[i],tmp.push_back(arr[i]),sum+=arr[i];

    sort(tmp.begin(),tmp.end());
    for(int x:tmp) {
        if(cnt.empty()||cnt.back().first!=x) cnt.emplace_back(x,1);
        else cnt.back().second++;
    }

    auto cal=[](int pre,int cur) {
        auto _cal=[](int box,int ball) {
            return cmb(box+ball-1,box-1);
        };
        return _cal(pre+1,cur);
    };

    Mint ans=1;
    int X=2*sum/n;
    int l=0,r=cnt.size()-1,pre=0;
    for(;l<r;l++,r--) {
        if(cnt[l].first+cnt[r].first!=X||cnt[l].second!=cnt[r].second) {
            cout<<0<<endl;
            return;
        }
        ans*=cal(pre,cnt[l].second)*pw[cnt[l].second];
        pre+=cnt[l].second;
    }
    if(l==r) ans*=cal(pre,cnt[l].second/2);
    cout<<ans<<endl;
}

int main() {
    init();
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*2;
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}