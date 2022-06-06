#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VII;
const int INF=0x3f3f3f3f;
const int N=110;
int limit,n;
VII adj[N];
int level[N];
int ans=INF;

int dijkstra(int up,int down){
    int dist[N];
    bool passed[N];
    priority_queue<PII,vector<PII>,greater<PII>> q;
    memset(dist,0x3f,sizeof dist);
    memset(passed,0,sizeof passed);
    dist[0]=0;
    q.emplace(dist[0],0);
    while(q.size()){
        int h=q.top().second;
        q.pop();
        if(passed[h]) continue;
        passed[h]=1;

        for(auto [l,id]:adj[h]){
            if(dist[id]>dist[h]+l){
                if(level[id]>up||level[id]<down) continue;
                dist[id]=dist[h]+l;
                q.emplace(dist[id],id);
            }
        }
    }
    return dist[1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>limit>>n;
    for(int i=1;i<=n;i++){
        int p,l,x;
        cin>>p>>l>>x;
        adj[0].emplace_back(p,i);
        level[i]=l;
        while(x--){
            int id,p;
            cin>>id>>p;
            adj[id].emplace_back(p,i);
        }
    }
    for(int i=1;i<=max(1,100-limit);i++) ans=min(ans,dijkstra(i+limit,i));
    cout<<ans;
    return 0;
}