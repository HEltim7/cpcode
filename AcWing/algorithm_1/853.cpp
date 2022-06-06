#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout<<"[debug] "<<#x<<" = "<<x<<endl
const int N=510,M=10010;
const int INF=0x3f3f3f3f;
int n,m,k;
int dist[N],backup[N];

struct Edge{
    int a,b,w;
} edge[M];

int bellman_ford(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=1;i<=k;i++){
        memcpy(backup,dist,sizeof dist);
        for(int j=1;j<=m;j++) dist[edge[j].b]=min(dist[edge[j].b],edge[j].w+backup[edge[j].a]);
    }
    if(dist[n]>=INF-500*10000) return -1;
    return dist[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edge[i]={a,b,w};
    }
    int ans=bellman_ford();
    if(ans==-1) cout<<"impossible";
    else cout<<ans;
    return 0;
}