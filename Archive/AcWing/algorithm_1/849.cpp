#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510;
const int MAX=0x3f3f3f3f;
int matrix[N][N];
int dist[N];
bool mark[N];
int n,m;

void dijkstra(){
    dist[1]=0;
    for(int i=1;i<=n;i++){
        int minn=-1;
        for(int j=1;j<=n;j++) if(!mark[j]&&(dist[j]<dist[minn]||minn==-1)) minn=j;
        mark[minn]=1;
        for(int j=1;j<=n;j++) dist[j]=min(dist[j],dist[minn]+matrix[minn][j]);
    }
    if(dist[n]==MAX) cout<<-1;
    else cout<<dist[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(matrix, 0x3f, sizeof matrix);
    memset(dist, 0x3f, sizeof dist);
    cin>>n>>m;
    int a,b,w;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>w;
        matrix[a][b]=min(matrix[a][b],w);
    }
    dijkstra();
    return 0;
}