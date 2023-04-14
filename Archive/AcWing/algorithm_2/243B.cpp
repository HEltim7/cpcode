#include<iostream>
#include<cmath>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10,M=320;

//sum表示块和，add为懒标记，num为数组
LL sum[M],add[M],num[N];
int n,m,len;

//计算块id
inline int get(int idx){
    return idx/len;
}

void query(int l,int r){
    LL res=0;
    //块内直接暴
    if(get(l)==get(r)) while(l<=r) res+=num[l]+add[get(l)],l++;
    else{
        //分别处理残段和完整段
        int i=l,j=r;
        while(get(i)==get(l)) res+=num[i]+add[get(i)],i++;
        while(get(j)==get(r)) res+=num[j]+add[get(j)],j--;
        for(int k=get(i);k<=get(j);k++) res+=sum[k];
    }
    cout<<res<<endl;
}

void modify(int l,int r,LL d){
    //块内直接暴
    if(get(l)==get(r)) while(l<=r) num[l]+=d,sum[get(l)]+=d,l++;
    else{
        //同样分段处理
        int i=l,j=r;
        while(get(i)==get(l)) num[i]+=d,sum[get(i)]+=d,i++;
        while(get(j)==get(r)) num[j]+=d,sum[get(j)]+=d,j--;
        for(int k=get(i);k<=get(j);k++) sum[k]+=d*len,add[k]+=d;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    len=sqrt(n);
    for(int i=1;i<=n;i++) cin>>num[i],sum[get(i)]+=num[i];
    while(m--){
        char op;
        LL a,b,c;
        cin>>op;
        if(op=='Q'){
            cin>>a>>b;
            query(a,b);
        }
        else{
            cin>>a>>b>>c;
            modify(a,b,c);
        }
    }
}