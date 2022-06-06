#include<iostream>
#include<algorithm>
using namespace std;
const int N=110;
int n,m;
struct EDGE{
    int a,b,v;
} edge[N];
int fa[N];
int ans;

bool cmp(EDGE a,EDGE b){
    return a.v<b.v;
}

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>edge[i].a>>edge[i].b>>edge[i].v;
    }
    sort(edge+1,edge+1+m,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){
        int a=findfa(edge[i].a);
        int b=findfa(edge[i].b);
        int v=edge[i].v;
        if(a==b) continue;
        ans+=v;
        fa[b]=a;
        if(++cnt>=n-1) break;
    }
    if(cnt>=n-1) cout<<ans;
    else cout<<"impossible";
    return 0;
}