#include<iostream>
using namespace std;
const int N=1e5+10;
int fa[N];

int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

//find也可写成：
int findalt(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
//结构体也可以使用并查集

void merge(int a,int b){
    fa[find(a)]=fa[find(b)];
}

void query(int a,int b){
    if(fa[find(a)]==fa[find(b)]) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,a,b;
    char mth;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>mth>>a>>b;
        if(mth=='M') merge(a,b);
        else query(a,b);
    }
    return 0;
}