//在并查集基础上维护集合数量（父节点的size数组
#include<iostream>
using namespace std;
const int N=1e5+10;
int fa[N],size[N];

int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,a,b;
    string mth;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        fa[i]=i;
        size[i]=1;
    }
    for(int i=1;i<=m;i++){
        cin>>mth>>a;
        if(mth=="C"){
            cin>>b;
            if(fa[find(a)]!=fa[find(b)]){
                size[fa[find(b)]]+=size[fa[find(a)]];
                fa[find(a)]=fa[find(b)];
            }
        }
        else if(mth=="Q1"){
            cin>>b;
            if(fa[find(a)]==fa[find(b)]) cout<<"Yes"<<'\n';
            else cout<<"No"<<'\n';
        }
        else{
            cout<<size[fa[find(a)]]<<'\n';
        }
    }
    return 0;
}