#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10,mod=1e9+7;

struct NODE{
    int l,r,len,minn;//记录最小进制
    LL res[12];//记录各个进制下的值
} tr[N*4];
int num[N];

LL qpow(LL a,LL b){
    a%=mod,b%=mod;
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

inline void pushup(int x){
    auto &p=tr[x],&l=tr[x<<1],&r=tr[x<<1|1];
    if(p.l==p.r) return;
    p.minn=max(l.minn,r.minn);
    for(int i=p.minn;i<=10;i++)
        p.res[i]=((l.res[i]%mod*qpow(i,r.len))%mod+r.res[i])%mod;
}

void modify(int x,int pos,int aim){
    auto &p=tr[x];
    int mid=p.l+p.r>>1;
    if(p.l==p.r){
        tr[x].minn=aim+1;
        for(int i=tr[x].minn;i<=10;i++) tr[x].res[i]=aim;
        return;
    }
    else if(pos<=mid) modify(x<<1,pos,aim);
    else modify(x<<1|1,pos,aim);
    pushup(x);
}

int findm(int x,int l,int r){
    auto &p=tr[x];
    if(p.l>=l&&p.r<=r) return p.minn;
    int mid=p.l+p.r>>1;
    int res=0;
    if(mid>=l) res=max(res,findm(x<<1,l,r));
    if(mid+1<=r) res=max(res,findm(x<<1|1,l,r));
    return res;
}

int query(int x,int l,int r,int aim){
    auto &p=tr[x];
    if(p.l>=l&&p.r<=r) return p.res[aim];
    int mid=p.l+p.r>>1;
    LL res=0;
    if(mid>=l) res=query(x<<1,l,min(mid,r),aim)%mod;
    if(mid+1<=r) res=((res*qpow(aim,r-mid)%mod)+query(x<<1|1,max(mid+1,l),r,aim))%mod;
    return res%mod;
}

void build(int x,int l,int r){
    tr[x]={l,r,r-l+1};
    if(l==r) {
        tr[x].minn=num[l]+1;
        for(int i=tr[x].minn;i<=10;i++) tr[x].res[i]=num[l];
    }
    else{
        int mid=l+r>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        pushup(x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        char in;
        cin>>in;
        num[i]=in-'0';
    }
    build(1,1,n);
    while(q--){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1) modify(1,a,b);
        else cout<<query(1,a,b,findm(1,a,b))<<endl;
    }
    return 0;
}