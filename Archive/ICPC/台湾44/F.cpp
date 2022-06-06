#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10,mod=1e9+7;
struct NODE
{
    int l,r;
    LL mul,add;
} tr[N*4];
LL ans=0;

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

inline void update(int x,LL mul,LL add){
    if(tr[x].add==-1){
        tr[x].mul=tr[x].mul*mul%mod;
        tr[x].add=add;
    }
    else{
        tr[x].add=tr[x].add*mul%mod;
        if(add!=-1){
            ans=(ans+tr[x].add*(tr[x].r-tr[x].l+1)%mod)%mod;
            tr[x].add=add;
        }
    }
}

inline void pushdn(int x){
    update(x<<1,tr[x].mul,tr[x].add);
    update(x<<1|1,tr[x].mul,tr[x].add);
    tr[x].mul=1;
    tr[x].add=-1;
}

void modify(int x,int l,int r,LL mul,LL add){
    if(tr[x].l>=l&&tr[x].r<=r) update(x,mul,add);
    else{
        pushdn(x);
        int mid=tr[x].l+tr[x].r>>1;
        if(mid>=l) modify(x<<1,l,r,mul,add);
        if(mid<r) modify(x<<1|1,l,r,mul,add);
    }
}

void build(int x,int l,int r){
    tr[x]={l,r};
    if(l==r) tr[x].mul=1,tr[x].add=0;
    else{
        int mid=l+r>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        tr[x].mul=1;
        tr[x].add=-1;
    }
}

void get_ans(int x){
    if(tr[x].l==tr[x].r){
        if(tr[x].add!=-1) ans=(ans+tr[x].add)%mod;
        return;
    }
    pushdn(x);
    get_ans(x<<1);
    get_ans(x<<1|1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    build(1,1,n);
    while(q--){
        int l,r,v;
        char op;
        cin>>l>>r>>op>>v;
        if(op=='+') modify(1,l,r,1,v);
        else if(op=='-') modify(1,l,r,1,mod-v);
        else if(op=='*') modify(1,l,r,v,-1);
        else modify(1,l,r,qpow(v,mod-2),-1);
    }

    get_ans(1);
    cout<<ans;
    return 0;
}