#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VII;
const int N=2500+10;

int dist[N];
bool inque[N];
int t,c,ts,te;
VII adj[N];
/*
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[ts]=0;
    for(int i=1;i<=t;i++){
        int path=-1;
        for(int j=1;j<=t;j++)
            if(!passed[j]&&(path==-1||dist[j]<dist[path]))
                path=j;

        if(path==te) break;
        passed[path]=1;
        for(int j=1;j<=t;j++)
            dist[j]=min(dist[j],dist[path]+matrix[path][j]);
    }
    return dist[te];
}

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[ts]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.emplace(dist[ts],ts);
    
    while(heap.size()){
        int node=heap.top().second;
        if(node==te) break;
        heap.pop();
        if(passed[node]) continue;
        passed[node]=1;

        for(auto x:adj[node]){
            int &dis=dist[x.second];
            if(dis>x.first+dist[node]){
                dis=x.first+dist[node];
                heap.emplace(dis,x.second);
            }
        }
    }
    return dist[te];
}
*/
int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[ts]=0;
    queue<int> que;
    que.push(ts);
    inque[ts]=1;
    while(que.size()){
        int node=que.front();
        que.pop();
        inque[node]=0;
        for(auto x:adj[node]){
            int &dis=dist[x.second];
            if(x.first+dist[node]<dis){
                dis=x.first+dist[node];
                if(!inque[x.second]){
                    que.push(x.second);
                    inque[x.second]=1;
                }
            }
        }
    }
    return dist[te];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t>>c>>ts>>te;
    while(c--){
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].emplace_back(d,b);
        adj[b].emplace_back(d,a);
    }
    cout<<spfa();
    return 0;
}