#include<iostream>
using namespace std;

const int N=50010;
int fa[N];
int eat[N];
int asfood[N];
int ans;

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

void assimilate(int a,int b){
    a=findfa(a),b=findfa(b);
    if(a==b) return;
    int deep=1;
    int food=findfa(eat[a]);
    while(fa[food]!=b&&eat[food]!=0){
        food=findfa(eat[food]);
        deep++;
    }
}

void eatit(int a,int b){ // a eat b
    a=findfa(a),b=findfa(b);

}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,k;
    int op,a,b;
    cin>>n>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    while(k--){
        cin>>op>>a>>b;
        if(a>n||b>n){
            ans++;
            continue;
        }
        if(op==1) assimilate(a,b);
        else eatit(a,b);
    }
    cout<<ans;
    return 0;
}