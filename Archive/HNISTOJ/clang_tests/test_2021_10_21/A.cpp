#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
const int N=1e5+10;
const int INF=0x3f3f3f3f;

VII adj[N];
int n,m;
int dist[N];
bool passed[N];

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    priority_queue<PII,VII,greater<PII>> heap;
    heap.emplace(dist[1],1);
    while(heap.size()){
        auto h=heap.top().second;
        auto d=heap.top().first;
        heap.pop();
        if(passed[h]) continue;
        passed[h]=1;

        for(auto [dis,node]:adj[h]){
            if(dist[node]>dis+d){
                dist[node]=dis+d;
                heap.emplace(dist[node],node);
            }
        }
    }
    return dist[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].emplace_back(c,b);
    }
    cout<<dijkstra();
    return 0;
}