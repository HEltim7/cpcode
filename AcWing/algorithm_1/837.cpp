#include<iostream>
using namespace std;

const int N=1e5+10;
int fa[N];
int num[N];

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

void connect(int a,int b){
    a=findfa(a);
    b=findfa(b);
    if(a==b) return;
    fa[a]=b;
    num[b]+=num[a];
}

void query(int a,int b){
    if(findfa(a)==findfa(b)) cout<<"Yes\n";
    else cout<<"No\n";
}

void query_num(int a){
    cout<<num[findfa(a)]<<'\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,m,a,b;
    string op;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        num[i]=1;
    }
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op=="C"){
            cin>>a>>b;
            connect(a,b);
        }
        else if(op=="Q1"){
            cin>>a>>b;
            query(a,b);
        }
        else{
            cin>>a;
            query_num(a);
        }
    }
    return 0;
}