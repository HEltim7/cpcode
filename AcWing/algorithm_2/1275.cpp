#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10;
const int _INF=0xcfcfcfcf;

struct NODE
{
    int l,r;
    int v;//最大值
} sgt[N*4];

void pushup(int id){//子更新父
    sgt[id].v=max(sgt[id<<1].v,sgt[id<<1|1].v);
}

void build(int id,int l,int r){
    sgt[id]={l,r};
    if(l==r) return;
    int mid=l+r>>1;
    build(id<<1,l,mid),build(id<<1|1,mid+1,r);
}

int query(int id,int l,int r){
    if(sgt[id].l>=l&&sgt[id].r<=r) return sgt[id].v;//完全包含

    int mid=sgt[id].l+sgt[id].r>>1;
    int v=_INF;
    if(l<=mid) v=max(v,query(id<<1,l,r));
    if(r>mid) v=max(v,query(id<<1|1,l,r));//build()时划分为[l,mid],[mid+1,r]
    return v;
}

void modify(int id,int p,int v){//当前点为id,将p点值修改为v
    if(sgt[id].l==p&&sgt[id].r==p) sgt[id].v=v;
    else{
        int mid=sgt[id].l+sgt[id].r>>1;
        if(p<=mid) modify(id<<1,p,v);
        else modify(id<<1|1,p,v);
        pushup(id);//回溯时更新父节点
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL m,p,idx=0,a=0;
    cin>>m>>p;
    build(1,1,m);
    while(m--){
        char op;
        LL num;
        cin>>op>>num;
        if(op=='A') modify(1,++idx,(num+a)%p);
        else{
            a=query(1,idx-num+1,idx);
            cout<<a<<endl;
        }
    }
    return 0;
}