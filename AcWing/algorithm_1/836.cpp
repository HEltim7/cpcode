#include<iostream>
using namespace std;

const int N=1e5+10;
int fa[N];
int idx;

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

void merge(int a,int b){
    a=findfa(a);
    b=findfa(b);
    fa[a]=b;
}

void query(int a,int b){
    a=findfa(a);
    b=findfa(b);
    if(a==b) cout<<"Yes\n";
    else cout<<"No\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,m,a,b;
    char op;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>op>>a>>b;
        if(op=='M') merge(a,b);
        else query(a,b);
    }
    return 0;
}