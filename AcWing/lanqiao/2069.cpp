#include<iostream>
using namespace std;
const int N=1e4+10;
const int M=1e5+10;
int n,m;
int fa[N],d[N];

int findfa(int u){
    if(fa[u]==u||fa[fa[u]]==fa[u]) return fa[u];
    int f=findfa(fa[u]);
    d[u]+=d[fa[u]];
    return fa[u]=f;
}

int main(){
    int op,a,b;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&op,&a,&b);
        if(op==1){
            a=findfa(a),b=findfa(b);
            if(a!=b){
                d[a]-=d[b];
                fa[a]=b;
            }
        }
        else{
            a=findfa(a);
            d[a]+=b;
        }
    }
    for (int i = 1; i <= n; i ++ )
        if (i == findfa(i)) printf("%d ", d[i]);
        else printf("%d ", d[i] + d[findfa(i)]);
    return 0;
}