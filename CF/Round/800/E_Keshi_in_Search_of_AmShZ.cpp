#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;
int ind[N],dis[N];
vector<int> adj[N];
bool mark[N];

int dijkstra(int n) {
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    memset(dis,0x3f,sizeof (int)*(n+1));
    dis[n]=0;
    heap.emplace(dis[n],n);
    while(heap.size()) {
        auto [d,u]=heap.top();
        heap.pop();
        if(u==1) return dis[u];
        if(mark[u]) continue;
        mark[u]=1;
        for(int v:adj[u]) {
            int cur=dis[u]+ind[v];
            if(cur<dis[v]) {
                dis[v]=cur;
                heap.emplace(cur,v);
            }
            ind[v]--;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        adj[b].emplace_back(a);
        ind[a]++;
    }
    cout<<dijkstra(n)<<endl;
    return 0;
}