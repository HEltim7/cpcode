#include<iostream>
using namespace std;

const int N=2e4+10;
int h[N],e[N],ne[N],w[N],idx;
int maxd1[N],maxd2[N],maxu[N],id1[N],id2[N];

void add(int a,int b,int v){
    e[++idx]=b,ne[b]=h[a],h[a]=idx,w[idx]=v;
}

int dfs_down(int id,int root){//向下暴搜距离最远的距离
    for(int i=h[id];i;i=ne[i]){
        if(e[i]==root) continue;
        int dist=dfs_down(e[i],id)+w[i];
        if(dist>=maxd1[id]){
            maxd2[id]=maxd1[id],id2[id]=id1[id];
            maxd1[id]=dist,id1[id]=e[i];
        }
        else if(dist>maxd2[id]) maxd2[id]=dist,id2[id]=e[i];
    }
    return maxd1[id];
}

int dfs_up(int id,int son){//向上暴搜最远的距离
    int dist=0;
    for(int i=h[id];i;i=ne[i]){
        if(e[i]==son) continue;
        if(id1[id]==e[i]) maxu[e[i]] =max(maxu[id],maxd2[id])+w[i];
        else maxu[e[i]]=max(maxu[id],maxd1[id]) +w[i];
        dfs_up(e[i],id);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b,v;
        cin>>a>>b>>v;
        add(a,b,v);
        add(b,a,v);
    }
    dfs_down(1,-1);
    dfs_up(1,-1);
    int res=0x3f3f3f3f;
    for(int i=1;i<=n;i++) res=min(res,max(maxd1[i],maxu[i]));
    cout<<res;
    return 0;
}