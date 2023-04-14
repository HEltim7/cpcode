#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=510;
const int INF=0x3f3f3f3f;
vector<int> adj[N];
int dist[N];
int m,n,ans=INF;
bool inque[N];

int spfa(){
    queue<int> q;
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    q.push(1);
    inque[1]=1;
    while(q.size()){
        int h=q.front();
        q.pop();
        inque[h]=0;

        for(auto x:adj[h]){
            if(dist[x]>dist[h]+1){
                dist[x]=dist[h]+1;
                if(!inque[x]) q.push(x);
                inque[x]=1;
            }
        }
    }
    return dist[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>m>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    string in;
    getline(cin,in);
    while(m--){
        int bus[N],idx=0,num=0;
        getline(cin,in);
        in+=' ';
        for(auto x:in){
            if(x>='0'&&x<='9') num=num*10+x-'0';
            else if(num) bus[++idx]=num,num=0;
        }
        for(int i=1;i<=idx;i++) for(int j=i+1;j<=idx;j++) adj[bus[i]].push_back(bus[j]);
    }
    for(int i=1;i<=n;i++) unique(adj[i].begin(),adj[i].end());
    int ans=spfa();
    if(ans==INF) cout<<"NO";
    else cout<<ans-1;
    return 0;
}