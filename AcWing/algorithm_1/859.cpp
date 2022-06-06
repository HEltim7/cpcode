#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=2e5+10;
int n,m;
int fa[N];
struct EDGE{
    int a,b,w;
    bool operator < (const EDGE &W) const{
        return w<W.w;
    }
}edge[N];

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

int kruskal(){
    int res=0,cnt=0;
    for(int i=1;i<=m;i++){
        int a=findfa(edge[i].a),b=findfa(edge[i].b);
        if(a!=b){
            fa[a]=b;
            res+=edge[i].w;
            cnt++;
        }
    }
    if(cnt<n-1) cout<<"impossible";
    else cout<<res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>edge[i].a>>edge[i].b>>edge[i].w;
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(edge+1,edge+1+m);
    kruskal();
    return 0;
}