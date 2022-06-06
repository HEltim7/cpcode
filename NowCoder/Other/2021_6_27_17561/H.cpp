#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long ll;

const int M=1e7+10;
const int N=2e5+10;
int prime[M];
bool isprime[M];
int n,m,k;
int fa[N];

struct EDGE{
    int a,b,w;
    bool operator < (const EDGE &W) const{
        return w<W.w;
    }
}edge[N];

int getprime(int n){
    int cnt=0;
    memset(isprime,1,sizeof isprime);
    isprime[1]=0;
    for(int i=2;i<=n;i++){
        if(isprime[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]<=n/i;j++){
            isprime[prime[j]*i]=0;
            if(i%prime[j]==0) break;
        }
    }
    return cnt;
}

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

bool kruskal(){
    int cnt=0;
    ll ans=0;
    for(int i=1;i<=m;i++){
        int a=findfa(edge[i].a),b=findfa(edge[i].b);
        if(a!=b){
            fa[a]=b;
            ans+=edge[i].w;
            cnt++;
        }
    }
    // debug(ans);
    if(cnt<n-1||ans>=k) return 0;
    else return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    getprime(1e7);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>edge[i].a>>edge[i].b>>edge[i].w;
        if(isprime[edge[i].w]) edge[i].w=0;
    }
    sort(edge+1,edge+m+1);
    if(kruskal()) cout<<"wmmxycwdjdwdlnljbzwtskirakira";
    else cout<<"wmmxycwdjdwdlnljbzwtsfljt";
    return 0;
}