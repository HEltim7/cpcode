#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VII;
const int N=1e3+10;
const int INF=0x3f3f3f3f;
int n,p,k;
VII adj[N];

bool dijkstra(int x){
    int dist[N];
    bool passed[N];
    memset(dist,0x3f,sizeof dist);
    memset(passed,0,sizeof passed);
    dist[1]=0;
    priority_queue<PII,VII,greater<PII>> heap;
    heap.emplace(dist[1],1);

    while(heap.size()){
        int h=heap.top().second;
        heap.pop();
        if(passed[h]) continue;
        passed[h]=1;

        for(auto [l,id]:adj[h]){
            if(l>x) l=1;
            else l=0;
            if(dist[id]>dist[h]+l){
                dist[id]=dist[h]+l;
                heap.emplace(dist[id],id);
            }
        }
    }
    if(dist[n]<=k) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>p>>k;
    for(int i=1;i<=p;i++){
        int a,b,l;
        cin>>a>>b>>l;
        adj[a].emplace_back(l,b);
        adj[b].emplace_back(l,a);
    }

    int l=0,r=1e6+1;
    while(l<r){
        int mid=l+r>>1;
        if(dijkstra(mid)) r=mid;
        else l=mid+1;
    }
    if(l>1e6) cout<<-1;
    else cout<<l;
    return 0;
}