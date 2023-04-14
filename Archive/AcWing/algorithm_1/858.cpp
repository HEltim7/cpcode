#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=510;
const int INF=0x3f3f3f3f;
int n,m;
int dist[N];
int matrix[N][N];
bitset<N> st;

int prim(){
    int res=0;
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=n;i++){
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!st[j]&&(t==-1||dist[j]<dist[t]))
                t=j;
        if(i>1&&dist[t]==INF) return INF;
        st[t]=1;
        if(i!=1) res+=dist[t];
        for(int j=1;j<=n;j++) dist[j]=min(dist[j],matrix[t][j]);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    memset(matrix,0x3f,sizeof matrix);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        matrix[a][b]=min(matrix[a][b],c);
        matrix[b][a]=min(matrix[a][b],c);
    }
    int ans=prim();
    if(ans==INF) cout<<"impossible";
    else cout<<ans;
    return 0;
}