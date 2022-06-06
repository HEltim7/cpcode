#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout<<"[debug] "#x<<" = "<<x<<endl;

const int N=1e5+10;
const int INF=0x3f3f3f3f;
int dist[N],cnt[N];
int n,m;
int e[N],ne[N],w[N],h[N],idx;
bitset<N> b;

void add(int a,int b,int c){
    e[++idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx;
}

int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    b[1]=1;
    while(q.size()){
        int t=q.front();
        q.pop();
        b[t]=0;
        for(int i=h[t];i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>n-1) return -1;
                if(!b[j]){
                    q.push(j);
                    b[j]=1;
                }
            }
        }
    }
    return dist[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int ans=spfa();
    if(ans==-1) cout<<"Yes";
    else cout<<"No";
    return 0;
}