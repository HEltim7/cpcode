#include<iostream>
using namespace std;

const int N=5e5+10;

struct NODE{
    int l,r;
    int sum;
    int lmax,rmax,tmax;
} sgt[N*4];
int num[N];

NODE pushup(NODE &x,NODE &y,NODE &z){
    x.lmax=max(y.lmax,y.sum+z.lmax);
    x.rmax=max(z.rmax,z.sum+y.rmax);
    x.tmax=max(y.rmax+z.lmax,max(y.tmax,z.tmax));
    x.sum=y.sum+z.sum;
    x.l=y.l,x.r=z.r;
    return x;
}

void pushup(int id){
    auto &x=sgt[id],&y=sgt[id<<1],&z=sgt[id<<1|1];
    pushup(x,y,z);
}

void build(int id,int l,int r){
    auto &t=sgt[id];
    if(l==r) t={l,r,num[l],num[l],num[l],num[l]};
    else{
        int mid=l+r>>1;
        build(id<<1,l,mid),build(id<<1|1,mid+1,r);
        pushup(id);
    }
}

void modify(int id,int p,int v){
    auto &t=sgt[id];
    if(t.l==p&&t.r==p) t.sum=t.lmax=t.rmax=t.tmax=v;
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
    NODE res={0},q1={0},q2={0};
    if(l<=mid&&r>mid){
        q1=query(id<<1,l,r);
        q2=query(id<<1|1,l,r);
        res=pushup(res,q1,q2);
    }
    else{
        if(r<=mid) res=query(id<<1,l,r);
        else res=query(id<<1|1,l,r);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,k,x,y;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,1,n);
    while(m--){
        cin>>k>>x>>y;
        if(x>y&&k==1) swap(x,y);
        if(k==1) cout<<query(1,x,y).tmax<<endl;
        else modify(1,x,y);
    }
    return 0;
}