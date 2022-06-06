#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;

#define endl '\n'
#define check(x,bit) (x&(1<<bit))
const int N=1e6+10;
int e[N],ne[N],pre[N],w[N],h[N],idx;
bool mark[N][30];
int edge[N],cnt,res;

inline void add(int a,int b,int c){
    if(~h[a]) pre[h[a]]=idx;
    pre[idx]=N+a;
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

inline void del(int x){
    if(pre[x]>N) h[pre[x]-N]=ne[x];
    else ne[pre[x]]=ne[x];
    if(~ne[x]) pre[ne[x]]=pre[x];
}

void dfs(int root,int bit){
    mark[root][bit]=1;
    res++;
    for(int i=h[root];~i;i=ne[i]){
        int ver=e[i];
        if(mark[ver][bit]) continue;
        if(check(w[i],bit)){
            edge[++cnt]=i;
            continue;
        }
        dfs(ver,bit);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(h,-1,sizeof (int)*(n+1));
    int ans=0;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    for(int i=29;i>=0;i--){
        res=0;
        dfs(1,i);
        if(res==n) while(cnt) del(edge[cnt--]);
        else ans+=1<<i;
        cnt=0;
    }
    cout<<ans<<endl;
    return 0;
}