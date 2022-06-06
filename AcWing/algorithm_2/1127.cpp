#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

#define id first
#define len second
typedef pair<int,int> PII;
const int N=810;
const int INF=0x3f3f3f3f;

vector<PII> adj[N];
int n,p,c;
int farm[N]; 
int dist[N];
bool inque[N];

int spfa(int start){
    memset(inque,0,sizeof inque);
    memset(dist,0x3f,sizeof dist);
    dist[start]=0;
    inque[start]=1;
    queue<int> q;
    q.push(start);

    while(q.size()){
        int a=q.front();
        q.pop();
        inque[a]=0;
        for(auto x:adj[a]){
            int b=x.id;
            int d=x.len;
            if(dist[b]>dist[a]+d){
                dist[b]=dist[a]+d;
                q.push(b);
                inque[b]=1;
            }
        }
    }

    int res=0;
    for(int i=1;i<=p;i++){
        if(farm[i]&&dist[i]==INF) return INF;
        res+=farm[i]*dist[i];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>p>>c;
    int in;
    for(int i=1;i<=n;i++) cin>>in,farm[in]++;

    while(c--){
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].emplace_back(b,d);
        adj[b].emplace_back(a,d);
    }

    int ans=INF;
    for(int i=1;i<=p;i++) ans=min(ans,spfa(i));
    cout<<ans;
}