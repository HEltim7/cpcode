#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

#define endl '\n'
#define fi first
#define se second
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int N=25000+10;
const int INF=0x3f3f3f3f-5e8;

VII adj[N];
VI block[N];
int bid[N],in[N],dist[N];
int t,r,p,s;
int bididx;
bool passed[N];
queue<int> q;

void dijkstra(int blockid){
    priority_queue<PII,VII,greater<PII>> heap;
    for(int x:block[blockid]) heap.emplace(dist[x],x);

    while(heap.size()){
        auto h=heap.top();
        heap.pop();
        if(passed[h.second]) continue;
        passed[h.second]=1;

        for(auto x:adj[h.second]){
            if(h.first+x.second<dist[x.first]){
                dist[x.first]=h.first+x.second;
                if(bid[x.first]==blockid)
                    heap.emplace(dist[x.first],x.first);
            }
            if(bid[x.first]!=blockid&&--in[bid[x.first]]==0)
                q.push(bid[x.first]);
        }
    }
}

void topsort(){
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    for(int i=1;i<=bididx;i++) if(in[i]==0) q.push(i);
    while(q.size()){
        int h=q.front();
        q.pop();
        dijkstra(h);
    }
}

void dfs(int id){
    bid[id]=bididx;
    block[bididx].push_back(id);
    for(auto [i,j]:adj[id]) if(!bid[i]) dfs(i);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t>>r>>p>>s;
    for(int i=1;i<=r;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int cnt=0;
    for(int i=1;i<=t;i++){
        if(!bid[i]){
            bididx++;
            dfs(i);
        }
    }
    for(int i=1;i<=p;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        in[bid[b]]++;
    }
    topsort();
    for(int i=1;i<=t;i++){
        if(dist[i]>=INF) cout<<"NO PATH"<<endl;
        else cout<<dist[i]<<endl;
    }
}