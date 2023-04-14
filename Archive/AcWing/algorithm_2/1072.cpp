#include<iostream>
using namespace std;

const int N=2e4+10;
const int __INF=0xcfcfcfcf;
int h[N],e[N],ne[N],w[N],idx;
int ans;

void add(int a,int b,int v){
    e[++idx]=b,ne[idx]=h[a],h[a]=idx,w[idx]=v;
}

int dfs(int id,int root){
    int max1=0,max2=0;
    int dist=0;
    for(int i=h[id];i;i=ne[i]){
        if(e[i]==root) continue;
        int tmp=dfs(e[i],id)+w[i];
        dist=max(dist,tmp);
        if(tmp>=max1){
            max2=max1;
            max1=tmp;
        }
        else if(tmp>max2) max2=tmp;
    }
    ans=max(ans,max1+max2);
    return dist;
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
    dfs(1,-1);
    cout<<ans;
    return 0;
}