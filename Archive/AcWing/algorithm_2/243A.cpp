#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;

struct NODE{
    int l,r,laze;
    LL sum;
}seg[N*4];
int num[N];

inline void pushup(int id){
    seg[id].sum=seg[id<<1].sum+seg[id<<1|1].sum;
}

inline void pushdn(int id){
    auto &fa=seg[id],&l=seg[id<<1],&r=seg[id<<1|1];
    LL len=l.r-l.l+1;
    l.sum+=fa.laze*len,l.laze+=fa.laze;
    len=r.r-r.l+1;
    r.sum+=fa.laze*len,r.laze+=fa.laze;
    fa.laze=0;
}

void build(int id,int l,int r){
    auto &fa=seg[id];
    fa={l,r};
    if(fa.r==fa.l) fa.sum=num[fa.l];
    else{
        int mid=l+r>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        pushup(id);
    }
}

LL query(int id,int l,int r){
    auto &fa=seg[id];
    LL sum=0;
    if(fa.l>=l&&fa.r<=r) return fa.sum;
    else{
        int mid=fa.l+fa.r>>1;
        pushdn(id);
        if(mid>=l) sum+=query(id<<1,l,r);
        if(mid+1<=r) sum+=query(id<<1|1,l,r);
        pushup(id);
    }
    return sum;
}

void modify(int id,int l,int r,int x){
    auto &fa=seg[id];
    LL len=fa.r-fa.l+1;
    if(fa.l>=l&&fa.r<=r) fa.sum+=len*x,fa.laze+=x;
    else{
        int mid=fa.l+fa.r>>1;
        pushdn(id);
        if(mid>=l) modify(id<<1,l,r,x);
        if(mid+1<=r) modify(id<<1|1,l,r,x);
        pushup(id);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,1,n);
    while(m--){
        char op;
        int a,b,c;
        cin>>op>>a>>b;
        if(op=='Q') cout<<query(1,a,b)<<endl;
        else{
            cin>>c;
            modify(1,a,b,c);
        }
    }
    return 0;
}