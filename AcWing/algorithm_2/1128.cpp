/*
每个点的信都是来源于指挥部
所以每个点收到信的最早时间等价为指挥部到该点的最短路
问题转化为求源点到各个汇点的最短路的最大值
如果存在无穷远的点说明存在不可达的点
*/

#include<iostream>
#include<cstring>
using namespace std;

const int N=110;
const int INF=0x3f3f3f3f;
int dist[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=n;i++) dist[i][i]=0;

    while(m--){
        int a,b,k;
        cin>>a>>b>>k;
        dist[a][b]=dist[b][a]=min(dist[a][b],k);
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

    int ans=-1;
    for(int i=1;i<=n;i++) ans=max(ans,dist[1][i]);
    if(ans==INF) cout<<-1;
    else cout<<ans;
    return 0;
}