#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

const int N=5e4+10;
const int INF=0x3f3f3f3f;
typedef pair<int,int> PII;
typedef vector<PII> VII;
VII adj[N];
int n,m;
int bus[10];
map<PII,int> ans;
bool mark[10];

void dijkstra(int start,int end){
    int dist[N];
    bool passed[N];
    memset(dist,0x3f,sizeof dist);
    memset(passed,0,sizeof passed);
    dist[start]=0;
    priority_queue<PII,VII,greater<PII>> heap;
    heap.emplace(dist[start],start);

    while(heap.size()){
        int h=heap.top().second;
        heap.pop();
        if(passed[h]) continue;
        passed[h]=1;

        for(auto [l,id]:adj[h]){
            if(dist[id]>dist[h]+l){
                dist[id]=dist[h]+l;
                heap.emplace(dist[id],id);
            }
        }
    }
    ans.insert({{start,end},dist[end]});
    ans.insert({{end,start},dist[end]});
}

int dfs(int deep,int source){
    int res=INF;
    if(deep>=5) return 0;

    for(int i=1;i<=5;i++){
        if(!mark[i]){
            mark[i]=1;
            res=min(res,dfs(deep+1,bus[i])+
            ans.find({source,bus[i]})->second);
            mark[i]=0;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    bus[0]=1;
    for(int i=1;i<=5;i++) cin>>bus[i];
    while(m--){
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].emplace_back(d,b);
        adj[b].emplace_back(d,a);
    }
    for(int i=0;i<=5;i++) for(int j=i+1;j<=5;j++) dijkstra(bus[i],bus[j]);
    cout<<dfs(0,1);
    return 0;
}