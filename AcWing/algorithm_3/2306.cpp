/*
外层权值线段树，每个节点存储值在[l-r]区间的数的下标
内层下标线段树，每个节点存储下标在[l-r]区间的数的个数
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=5e4+10,M=N*4*16*4;
typedef vector<int> VI;

struct INPUT {
    int op,a,b,c;
} inp[N];
struct NODE {
    int l,r,sum,add;
} tr[M];
VI num;
int L[N*4],R[N*4],T[N*4];
int n,m,idx;

//求两个区间的交集
inline int inter(int a,int b,int c,int d){
    return min(b,d)-max(a,c)+1;
}

//[l,r]表示当前下标区间，[a,b]表示要修改的下标区间
void update(int x,int l,int r,int a,int b){
    tr[x].sum+=inter(l,r,a,b);
    if(l>=a&&r<=b) {
        tr[x].add++;
        return;
    }
    int mid=l+r>>1;
    if(mid>=a){
        if(!tr[x].l) tr[x].l=++idx;
        update(tr[x].l,l,mid,a,b);
    }
    if(mid+1<=b){
        if(!tr[x].r) tr[x].r=++idx;
        update(tr[x].r,mid+1,r,a,b);
    }
}

//[a,b]表示要修改的下标区间
void modify(int x,int a,int b,int c){
    update(T[x],1,n,a,b);
    if(L[x]==R[x]) return;
    int mid=L[x]+R[x]>>1;
    if(mid>=c) modify(x<<1,a,b,c);
    else modify(x<<1|1,a,b,c);
}

//内层查询
int __query(int x,int l,int r,int a,int b,int add){
    if(l>=a&&r<=b) return tr[x].sum+(r-l+1)*add;
    int mid=l+r>>1;
    int res=0;
    add+=tr[x].add;
    if(mid>=a){
        if(tr[x].l) res+=__query(tr[x].l,l,mid,a,b,add);
        else res+=inter(l,mid,a,b)*add;
    }
    if(mid+1<=b){
        if(tr[x].r) res+=__query(tr[x].r,mid+1,r,a,b,add);
        else res+=inter(mid+1,r,a,b)*add;
    }
    return res;
}

int query(int x,int a,int b,int c){
    if(L[x]==R[x]) return L[x];
    int mid=L[x]+R[x]>>1;
    int k=__query(T[x<<1|1],1,n,a,b,0);
    if(k>=c) return query(x<<1|1,a,b,c);
    return query(x<<1,a,b,c-k);
}

void build(int x,int l,int r){
    L[x]=l,R[x]=r,T[x]=++idx;
    if(l==r) return;
    int mid=l+r>>1;
    build(x<<1,l,mid),build(x<<1|1,mid+1,r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>inp[i].op>>inp[i].a>>inp[i].b>>inp[i].c;
        if(inp[i].op==1) num.push_back(inp[i].c);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    build(1,0,num.size()-1);

    for(int i=1;i<=m;i++){
        auto [op,a,b,c]=inp[i];
        if(op==1) modify(1,a,b,lower_bound(num.begin(),num.end(),c)-num.begin());
        else cout<<num[query(1,a,b,c)]<<endl;
    }
    return 0;
}