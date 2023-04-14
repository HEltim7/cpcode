#include <queue>
#include <vector>
#include <cstring>
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
}; using Mint=Modint<int,long long,998244353>;
constexpr int N=1e5+10;
int a[N],b[N];
bool mark[N];
vector<int> adj[N];

void solve() {
    int n;
    cin>>n;
    memset(mark, 0, sizeof(bool)*(n+1));
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) adj[a[i]].push_back(b[i]),adj[b[i]].push_back(a[i]);
    
    Mint ans=1;
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(!mark[i]) {
            int edg=0,poi=0;
            bool selfloop=0;
            q.push(i);
            while(q.size()) {
                int u=q.front();
                q.pop();
                if(mark[u]) continue;
                mark[u]=1;
                poi++;

                edg+=adj[u].size();
                for(int v:adj[u]) {
                    if(u==v) selfloop=1;
                    else q.push(v);
                }
            }

            edg/=2;
            if(edg>=poi+1) ans=0;
            else if(edg==poi) {
                if(selfloop) ans*=n;
                else ans*=2;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}