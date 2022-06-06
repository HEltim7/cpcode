#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<LL,int> PII;
typedef vector<PII> VII;
const int N=5e5+10;

VII adj[N];
LL dist[N];
bool passed[N];
int n;

//类似筛建图
void build(){
    for(int i=1;i<=n;i++){
        for(int j=2;i*j<=n;j++){
            adj[i].emplace_back((LL)(i*j-i)*(i*j-i),i*j);
            // adj[i*j].emplace_back((LL)(i*j-i)*(i*j-i),i);
        }
    }
}

void dijkstra(){
    priority_queue<PII,VII,greater<PII>> heap;
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    heap.push({0,1});

    while(heap.size()){
        auto [dis,node]=heap.top();
        heap.pop();
        if(passed[node]) continue;
        passed[node]=1;

        for(auto [d,x]:adj[node]){
            if(dist[x]>d+dist[node]){
                dist[x]=d+dist[node];
                heap.push({dist[x],x});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    build();
    dijkstra();
    for(int i=1;i<=n;i++) cout<<dist[i]<<' ';
    return 0;
}