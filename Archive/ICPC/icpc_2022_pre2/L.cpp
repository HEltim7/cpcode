#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e6+10,mod=998244353;
int u[N],v[N];
char s[N];
int n;

struct Node {
    LL i,c,p;
    LL ic,cp,pc;
    LL icp,cpc;
    LL icpc;

    void merge(const Node &l,const Node &r) {
        icpc=(l.icpc+r.icpc+(l.i*r.cpc)+(l.ic*r.pc)+(l.icp*r.c))%mod;
        icp=(l.icp+r.icp+(l.i*r.cp)+(l.ic*r.p))%mod;
        cpc=(l.cpc+r.cpc+(l.c*r.pc)+(l.cp*r.c))%mod;
        ic=(l.ic+r.ic+(l.i*r.c))%mod;
        cp=(l.cp+r.cp+(l.c*r.p))%mod;
        pc=(l.pc+r.pc+(l.p*r.c))%mod;
        i=(l.i+r.i)%mod;
        c=(l.c+r.c)%mod;
        p=(l.p+r.p)%mod;
    }

    void split(const Node &l,const Node &r) {
        i=(r.i-l.i+mod)%mod;
        c=(r.c-l.c+mod)%mod;
        p=(r.p-l.p+mod)%mod;
        ic=((r.ic-l.ic-(l.i*c))%mod+mod)%mod;
        cp=((r.cp-l.cp-(l.c*p))%mod+mod)%mod;
        pc=((r.pc-l.pc-(l.p*c))%mod+mod)%mod;
        icp=((r.icp-l.icp-(l.i*cp)-(l.ic*p))%mod+mod)%mod;
        cpc=((r.cpc-l.cpc-(l.c*pc)-(l.cp*c))%mod+mod)%mod;
        icpc=((r.icpc-l.icpc-(l.i*cpc)-(l.ic*pc)-(l.icp*c))%mod+mod)%mod;
    }
} st[N];

void build() {
    for(int i=1;i<=n;i++) {
        if(s[i]=='I') st[i].i=1;
        else if(s[i]=='C') st[i].c=1;
        else st[i].p=1;
        st[i].merge(st[i-1],st[i]);
    }
}

LL query(int l,int r) {
    Node res;
    res.split(st[l-1],st[r]);
    return res.icpc;
}

void solve() {
    LL q,x,a,b,p;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i];
    cin>>x>>a>>b>>p;
    
    build();
    LL res=0;
    for(int i=1;i<=q;i++) x=(x*a+b)%p,u[i]=x%n;
    for(int i=1;i<=q;i++) x=(x*a+b)%p,v[i]=x%n;
    for(int i=1;i<=q;i++) {
        int l=min(u[i],v[i])+1;
        int r=max(u[i],v[i])+1;
        res=(res+query(l,r))%mod;
    }
    cout<<res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}