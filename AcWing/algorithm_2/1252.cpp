#include<iostream>
using namespace std;

const int N=1e4+10;
int fa[N];
int dp[N];
int n,m,v;
int vol[N],val[N];

int findfa(int x){
    if(fa[x]==x) return x;
    else return fa[x]=findfa(fa[x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>v;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) cin>>vol[i]>>val[i];
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        a=findfa(a),b=findfa(b);
        if(a==b) continue;
        fa[a]=b;
        vol[b]+=vol[a];
        val[b]+=val[a];
    }
    for(int i=1;i<=n;i++)
        if(findfa(i)==i)
            for(int j=v;j>=vol[i];j--)
                dp[j]=max(dp[j],dp[j-vol[i]]+val[i]);
    cout<<dp[v];
    return 0;
}