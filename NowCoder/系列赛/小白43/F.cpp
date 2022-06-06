#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=2e5+10,M=2e6+10;
bool man[M],pass[M],odd,even,ans;
int e[M],ne[M],h[M],color[M],idx;
int n,m,k;

inline void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,ne[idx]=h[b],h[b]=idx++;
}

void dfs(int root,int dis){
    pass[root]=1;
    color[root]=dis&1;
    if(man[root]) if(dis) odd=1;else even=1;
    for(int i=h[root];~i;i=ne[i]){
        int ver=e[i];
        if(!pass[ver]) dfs(ver,dis^1);
        else if(color[ver]==color[root]) ans=1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    memset(h,-1,sizeof h);
    int in;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=k;i++) cin>>in,man[in]=1;
    dfs(1,0);
    if(even^odd||ans) cout<<"YES";
    else cout<<"NO";
    return 0;
}