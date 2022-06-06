#include<iostream>
#include<numeric>
using namespace std;

#define endl '\n'
const int N=5e5+10;
typedef long long LL;
LL dif[N];

struct NODE{
    int l,r;
    LL sum,gcd;
} sgt[N*4];

void pushup(NODE &fa,NODE &ls,NODE &rs){
    fa.sum=ls.sum+rs.sum;
    fa.gcd=gcd(ls.gcd,rs.gcd);
}

void pushup(int id){
    pushup(sgt[id],sgt[id<<1],sgt[id<<1|1]);
}

void build(int id,int l,int r){
    auto &t=sgt[id];
    t={l,r};
    if(l==r) t.sum=t.gcd=dif[r];
    else{
        int mid=l+r>>1;
        build(id<<1,l,mid),build(id<<1|1,mid+1,r);
        pushup(id);
    }
}

void modify(int id,int p,LL v){
    auto &t=sgt[id];
    if(t.l==p&&t.r==p){
        t.sum+=v;
        t.gcd+=v;
    }
    else{
        int mid=t.l+t.r>>1;
        if(p<=mid) modify(id<<1,p,v);
        else modify(id<<1|1,p,v);
        pushup(id);
    }
}

NODE query(int id,int l,int r){
    auto &t=sgt[id];
    if(t.l>=l&&t.r<=r) return t;
    int mid=t.l+t.r>>1;
    if(r<=mid) return query(id<<1,l,r);
    else if(l>mid) return query(id<<1|1,l,r);
    else{
        auto left=query(id<<1,l,r);
        auto right=query(id<<1|1,l,r);
        NODE res;
        pushup(res,left,right);
        return res;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL n,m,in;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>in,dif[i]+=in,dif[i+1]-=in;
    build(1,1,n);
    while(m--){
        LL l,r,d;
        char op;
        cin>>op;
        if(op=='Q'){
            cin>>l>>r;
            auto difsum=query(1,1,l);
            auto difgcd=query(1,l+1,r);
            cout<<gcd(difsum.sum,difgcd.gcd)<<endl;
        }
        else{
            cin>>l>>r>>d;
            modify(1,l,d);
            if(r+1<=n) modify(1,r+1,d);
        }
    }
    return 0;
}