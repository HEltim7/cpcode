#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10,mod=998244353;
const int A=N*4-1,B=N*4-2,C=N*4-3,Z=N*4-4;

struct NODE
{
    int l,r;
    LL res[3][3];
    inline void init(){
        memset(res,0,sizeof res);
        for(int i=0;i<3;i++) res[i][i]=1;
    }
} tr[N*4];
char s[N];
LL ans[3][3];
vector<int> nodes;

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

//a前矩阵，b后矩阵
inline void cal(int a,int b){
    memset(ans,0,sizeof ans);
    for(int i=0;i<3;i++) //后矩阵行 左
        for(int j=0;j<3;j++) //后矩阵列 左
            for(int k=0;k<3;k++) //前矩阵列 右
                ans[i][j]=(ans[i][j]+tr[b].res[i][k]*tr[a].res[k][j]%mod)%mod;
}

inline void pushup(int x){
    cal(x<<1,x<<1|1);
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) tr[x].res[i][j]=ans[i][j];
}

void query(int x,int l,int r){
    if(tr[x].l>=l&&tr[x].r<=r) nodes.push_back(x);
    else{
        int mid=tr[x].l+tr[x].r>>1;
        if(mid>=l) query(x<<1,l,r);
        if(mid+1<=r) query(x<<1|1,l,r);
    }
}

void modify(int x,int pos,int aim){
    if(tr[x].l==tr[x].r){
        if(aim==1) for(int i=0;i<3;i++) for(int j=0;j<3;j++) tr[x].res[i][j]=tr[A].res[i][j];
        if(aim==2) for(int i=0;i<3;i++) for(int j=0;j<3;j++) tr[x].res[i][j]=tr[B].res[i][j];
        if(aim==3) for(int i=0;i<3;i++) for(int j=0;j<3;j++) tr[x].res[i][j]=tr[C].res[i][j];
    }
    else{
        int mid=tr[x].l+tr[x].r>>1;
        if(mid>=pos) modify(x<<1,pos,aim);
        else modify(x<<1|1,pos,aim);
        pushup(x);
    }
}

void build(int x,int l,int r){
    tr[x]={l,r};
    if(l==r){
        if(s[l]=='1') for(int i=0;i<3;i++) for(int j=0;j<3;j++) tr[x].res[i][j]=tr[A].res[i][j];
        if(s[l]=='2') for(int i=0;i<3;i++) for(int j=0;j<3;j++) tr[x].res[i][j]=tr[B].res[i][j];
        if(s[l]=='3') for(int i=0;i<3;i++) for(int j=0;j<3;j++) tr[x].res[i][j]=tr[C].res[i][j];
    }
    else{
        int mid=l+r>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        pushup(x);
    }
}

void init(){
    tr[0].init();
    tr[A].res[0][0]=1;
    tr[A].res[0][1]=
    tr[A].res[0][2]=
    tr[A].res[1][1]=
    tr[A].res[2][2]=qpow(2,mod-2);

    tr[B].res[1][1]=1;
    tr[B].res[0][0]=
    tr[B].res[1][0]=
    tr[B].res[1][2]=
    tr[B].res[2][2]=qpow(2,mod-2);
    
    tr[C].res[2][2]=1;
    tr[C].res[0][0]=
    tr[C].res[1][1]=
    tr[C].res[2][0]=
    tr[C].res[2][1]=qpow(2,mod-2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    build(1,1,n);
    while(m--){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==2) {
            nodes.clear();
            query(1,a,b);
            tr[Z].init();
            for(auto x:nodes){
                cal(Z,x);
                for(int i=0;i<3;i++) for(int j=0;j<3;j++) tr[Z].res[i][j]=ans[i][j];
            }
            for(int i=0;i<3;i++){
                LL res=0;
                for(int j=0;j<3;j++) res=(res+ans[i][j])%mod;
                cout<<res<<' ';
            }
            cout<<endl;
        }
        else modify(1,a,b);
    }
    return 0;
}