#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N = 210;
const int INF=0x3f3f3f3f;
int n, m, k;
int dist[N][N];

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=n;i++) dist[i][i]=0;
    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
    }
    floyd();
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]>=INF-200*10000) cout<<"impossible"<<endl;
        else cout<<dist[a][b]<<endl;
    }
    return 0;
}