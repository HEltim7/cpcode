#include<iostream>
using namespace std;

#define endl '\n'
const int N=1e5+10;
typedef long long LL;

struct SEG{
    int l,r;
    LL sum,add,mul=1;
}seg[N*4];
int mod;
int num[N];

inline void pushup(int id){
    seg[id].sum=(seg[id<<1].sum+seg[id<<1|1].sum)%mod;
}

inline void upd(SEG &fa,LL mul,LL add){
    fa.sum=(fa.sum*mul%mod+add*(fa.r-fa.l+1)%mod)%mod;
    fa.mul=fa.mul*mul%mod;
    fa.add=(fa.add*mul%mod+add)%mod;
}

inline void pushdn(int id){
    auto &fa=seg[id],&l=seg[id<<1],&r=seg[id<<1|1];
    upd(l,fa.mul,fa.add);
    upd(r,fa.mul,fa.add);
    fa.mul=1,fa.add=0;
}

void build(int id,int l,int r){
    auto &fa=seg[id];
    fa={l,r};
    if(l==r) fa.sum=num[l];
    else{
        int mid=fa.l+fa.r>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        pushup(id);
    }
}

void modify(int id,int l,int r,LL mul,LL add){
    auto &fa=seg[id];
    if(fa.l>=l&&fa.r<=r) upd(fa,mul,add);
    else{
        pushdn(id);
        int mid=fa.l+fa.r>>1;
        if(mid>=l) modify(id<<1,l,r,mul,add);
        if(mid+1<=r) modify(id<<1|1,l,r,mul,add);
        pushup(id);
    }
}

LL query(int id,int l,int r){
    auto &fa=seg[id];
    if(fa.l>=l&&fa.r<=r) return fa.sum;
    int mid=fa.l+fa.r>>1;
    pushdn(id);
    LL res=0;
    if(mid>=l) res+=query(id<<1,l,r);
    if(mid+1<=r) res+=query(id<<1|1,l,r);
    return res%mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>mod;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,1,n);

    cin>>m;
    while(m--){
        int a,b,c,d;
        cin>>a>>b>>c;
        if(a==1){
            cin>>d;
            modify(1,b,c,d,0);
        }
        else if(a==2){
            cin>>d;
            modify(1,b,c,1,d);
        }
        else cout<<query(1,b,c)<<endl;
    }
    return 0;
}