#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int,int> pii;
const int N=1.5e5+10;
const int INF=0x3f3f3f3f;

int e[N],ne[N],w[N],dist[N],h[N],idx;
bool mark[N];
int n,m;

void add(int a,int b,int c){
    e[++idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx;
}

int dijkstra(){
    dist[1]=0;
    priority_queue<pii,vector<pii>,greater<pii>> heap;
    heap.emplace(dist[1],1);
    while(heap.size()){
        pii t=heap.top();
        heap.pop();
        int id=t.se;
        if(mark[id]) continue;
        mark[id]=1;

        for(int i=h[id];i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[id]+w[i]){
                dist[j]=dist[id]+w[i];
                heap.emplace(dist[j],j);
            }
        }
    }
    return dist[n]==INF?-1:dist[n];
}

int main(){
    memset(dist,0x3f,sizeof dist);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<dijkstra();
    return 0;
}